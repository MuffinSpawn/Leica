// ESCppClientDlg.cpp : implementation file
//

#ifndef WINVER
#if _MSC_VER <= 1200 // up to VC6.0
    #define WINVER 0x0400
#else
    #define WINVER 0x0501
#endif
#endif

#include "ESCppClient.h"
#include "ESCppClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RECV_BUFFER_SIZE 1028 * 64

// macro to save typing work
#define pMainWnd ((CESCppClientDlg*)AfxGetMainWnd())

///////////////////////////////////////////////////////////////////////////////
// CESAPISocket class implementation - there is one virtual function to override:

void CESAPISocket::OnReceive(int nErrorCode)
{
    static char cBuffer[RECV_BUFFER_SIZE]; // 64K buffer - static for efficiency only
    int nSizeOfPacketSize = sizeof(long); // PacketHeaderT::lPacketSize (4 Bytes)
    PacketHeaderT *pHeader = NULL;
    int nCounter = 0;
    int nBytesRead = 0;
    int nBytesReadTotal = 0;
    int nPacketSize = 0;
    int nMissing;
    int nReady;

    // The data parser 'm_EsReceive.ReceiveData()' can only handle 'complete' packets.
    // We must ensure that only single and complete packets are passed. However, the
    // network may have a 'traffic-jam' so that several packets could be read with
    // one receive cylce. On the other hand - although unlikely, only a packet fragment 
    // once could be read. The following mechanism makes sure that these things work properly.

    // just peek the header (read, but not remove from queue).
    nReady = pMainWnd->m_socket.Receive(cBuffer, nSizeOfPacketSize, MSG_PEEK);

    if (nReady == SOCKET_ERROR)
    {
        // WSAEWOULDBLOCK is not a 'real' error and will happen quite 
        // frequently. just sleep a little bit and continue.

        if (pMainWnd->m_socket.GetLastError() != WSAEWOULDBLOCK)
            Beep(1000, 200); // A real application should not just beep but handle the error

        Sleep(1); // may need to be increased in certain situations?
    } // if

    if (nReady < nSizeOfPacketSize)
        return; // non-fatal since only a peek, lets try next time!

    // mask the data with emscon packet header structure
    pHeader = (PacketHeaderT*)cBuffer;  // only lPacketSize is valid so far...
    nPacketSize = pHeader->lPacketSize; // ...do not reference pHeader->type!

    // read in a loop just in case we only get a fragment of the packet (unlikely, so
    // the lopp will usually be passed only once).
    do 
    {
        nCounter++;

        if (nBytesRead > 0)
            nBytesReadTotal += nBytesRead;

        nMissing = nPacketSize - nBytesReadTotal;

        // Only read the 'nMissing' amount of bytes. Make sure to apply the correct  
        // address offset to buffer (relevant if a packet needs more than one Receive cycle)
        nBytesRead = pMainWnd->m_socket.Receive(cBuffer+nBytesReadTotal, nMissing);

        if (nBytesRead == SOCKET_ERROR)
        {
            if (pMainWnd->m_socket.GetLastError() != WSAEWOULDBLOCK)
                Beep(1000, 200); // A real application should not just beep but handle the error

            Sleep(1); // may need to be increased in certain situations?
        } // if
        else if (nBytesRead == 0)
        {
            // Important: According to Microsoft documentation, a value of 0 only  
            // applies if connection closed. This is not true! On high frequency  
            // continuous measurements, it happens quite often that nBytesRead equals
            // to zero and we have to interpret this as a 'successful' reading. That
            // is, sleep a little bit, then retry reading. This effect almost never 
            // happens while running in debugger, it seldom happens when running a
            // debug version and mostly happens for sure for release builds!

            Sleep(1);
            continue;
        } // else if

        TRACE(_T("Bytes read %d\n"), nBytesRead);

        if (nCounter > 64) // loop emergency exit - just in case..
            return;

    } while (nBytesRead < nMissing);

    // contribution from last loop
    if (nBytesRead > 0)
        nBytesReadTotal += nBytesRead;

    // plausibility check
    if (nBytesRead == nMissing && nBytesReadTotal <= RECV_BUFFER_SIZE)
    {
        if (nBytesReadTotal == nPacketSize) // exactly one packet ready - process it
        {
            if (!pMainWnd->m_EsReceive.ReceiveData(cBuffer, nBytesReadTotal)) // exit procedure causes bytesRead = -1
                Beep(3000, 50); // error (status not OK or corrupt data)
        }
    } // if
    else
    {
        Beep(3000, 50); // something went wrong
        TRACE(_T("Read failure\n"));
    } // else

    //CSocket::OnReceive(nErrorCode); // Our class CESSocket has no base class
} // OnReceive()


///////////////////////////////////////////////////////////////////////////////
// CMyESAPICommand class implementation - there a virtual function to override:

bool CMyESAPICommand::SendPacket(void* PacketStart, long PacketSize) 
{
    pMainWnd->m_staticResult.SetWindowText(_T("")); // always clear result window (cosmetics)

    if (!pMainWnd->m_socket.Send(PacketStart, PacketSize))
        return false;

    return true;
}


///////////////////////////////////////////////////////////////////////////////
// CMyESAPIReceive class implementation - override virtual functions:


void CMyESAPIReceive::OnCommandAnswer(const BasicCommandRT& cmd)
{
    // Called for every command - even when failed.
    // Status can be used to determine failure reason.
    // If status OK, the command was OK. Only in this case, the specific command
    // virtual function will be called in additon (if overridden).
    // For exmaple OnFindReflectorAnswer()

    CString s;
    s.Format(_T("OnCommandAnswer, command %d, status %d\n"), cmd.command, cmd.status);
    TRACE(s);

    if (cmd.status != ES_RS_AllOK)
    {
        Beep(2000, 100);   // command failed
        AfxMessageBox(s);  // show the coammand number and error status in a box
    }
}


void CMyESAPIReceive::OnErrorAnswer(const ErrorResponseT& err)
{
    CString s;
    s.Format(_T("OnErrorAnswer, command %d, error %d\n"), err.command, err.status);
    Beep(2000, 100);

    TRACE(s);
    AfxMessageBox(s);
}


void CMyESAPIReceive::OnSetUnitsAnswer()
{
    TRACE(_T("OnSetUnitsAnswer\n"));

    // Enable continuous reflector positions
    if (!pMainWnd->m_EsCommand.SetLongSystemParameter(ES_SP_DisplayReflectorPosition, 1))
        AfxMessageBox(_T("Invoking OnSetUnitsAnswer command failed"));

    // Flow of control continued in OnSetLongSystemParamAnswer()
}


void CMyESAPIReceive::OnSetLongSystemParamAnswer()
{
    TRACE(_T("OnSetLongSystemParamAnswer\n"));

    // Finally, we query the reflectors to initialize the reflectors combo box
    if (!pMainWnd->m_EsCommand.GetReflectors())
        AfxMessageBox(_T("Invoking GetReflectors command failed"));
}


void CMyESAPIReceive::OnSystemStatusChange(const SystemStatusChangeT& status)
{
    CString s;
    s.Format(_T("OnSystemStatusChange, status %d\n"), status);
    TRACE(s);

    // bad design - enum values should not be compared - better use a switch statement!
    if (status.systemStatusChange >= ES_SSC_MeasStatus_NotReady && 
        status.systemStatusChange <= ES_SSC_MeasStatus_Ready)
    {
        if (status.systemStatusChange == ES_SSC_MeasStatus_NotReady)
            pMainWnd->SetStatusColor(RGB(255, 0, 0));
        else if (status.systemStatusChange == ES_SSC_MeasStatus_Busy)
            pMainWnd->SetStatusColor(RGB(255, 255, 0));
        else if (status.systemStatusChange == ES_SSC_MeasStatus_Ready)
            pMainWnd->SetStatusColor(RGB(0, 255, 100));
        else
            ASSERT(false);
    } // if
}


void CMyESAPIReceive::OnSingleMeasurementAnswer(const SingleMeasResultT& result)
{
    TRACE(_T("OnSingleMeasurementAnswer\n"));

    CString s; // We assume the coordinate system is set to RHR (-->labels X,Y,Z)
    s.Format(_T("X=%lf, Y=%lf, Z=%lf\n"), result.dVal1, result.dVal2, result.dVal3);
    TRACE(s);

    Beep(500, 100);
    AfxMessageBox(s);
    //pMainWnd->m_staticResult.SetWindowText(s);
}


void CMyESAPIReceive::OnInitializeAnswer()
{
    CString s = _T("Initialize OK");
    pMainWnd->m_staticResult.SetWindowText(s);
    TRACE(s);
    Beep(500, 100);
}


void CMyESAPIReceive::OnFindReflectorAnswer()
{
    CString s = _T("FindReflector OK");
    pMainWnd->m_staticResult.SetWindowText(s);
    TRACE(s);
    Beep(500, 100);
}


void CMyESAPIReceive::OnSetReflectorAnswer()
{
    CString s = _T("Set Active Reflector OK");
    pMainWnd->m_staticResult.SetWindowText(s);
    TRACE(s);
    Beep(500, 100);
}


void CMyESAPIReceive::OnReflectorPosAnswer(const ReflectorPosResultT& reflPos) 
{
    CString s; // We assume the coordinate system is set to RHR (-->labels X,Y,Z)
    s.Format(_T("Reflector Pos: x= %lf, y= %lf, z= %lf"), reflPos.dVal1, reflPos.dVal2, reflPos.dVal3);
    pMainWnd->m_staticResult.SetWindowText(s);
    TRACE(s + '\n');
} 


void CMyESAPIReceive::OnGetReflectorsAnswer(const int iTotalReflectors,
                                            const int iInternalReflectorId,
                                            const ES_TargetType targetType,
                                            const double dSurfaceOffset,
                                            const unsigned short cReflectorName[32])
{
    TRACE(_T("OnGetReflectorsAnswer\n"));

    static int nIndex = -1;
    nIndex++;

    pMainWnd->m_reflIDMap[nIndex] = iInternalReflectorId;  // index to ID mapping

    // convert from unicode to ansi (simple method since we know that all chars are ascii)
    const int size = 32; 
    char buf[size];

    for (int i = 0; i < size; i++)
        buf[i] = LOBYTE(cReflectorName[i]);

    pMainWnd->m_reflNameMap[nIndex] = buf;

    if (nIndex == (iTotalReflectors - 1)) // the last one has arrived
    {
        pMainWnd->m_nReflectorCount = iTotalReflectors;
        pMainWnd->InitReflectorBox();
    }
}


void CMyESAPIReceive::OnGetReflectorAnswer(const int iInternalReflectorId)
{
    // Part of the initialization of the reflector combo box. Once all names have
    // been added, we must select the one that is currently active.

    // IMPORTANT: combo box must not have sort flag!

    TRACE(_T("OnGetReflectorAnswer\n"));

    // find the index
    for (int i = 0; i < pMainWnd->m_nReflectorCount; i++)
    {
        if (pMainWnd->m_reflIDMap[i] == iInternalReflectorId)
        {
            pMainWnd->m_comboReflector.SetCurSel(i);
            break;
        }
    }
}


/////////////////////////////////////////////////////////////////////////////
// CESCppClientDlg dialog

CESCppClientDlg::CESCppClientDlg(CWnd* pParent /*=NULL*/)
   : CDialog(CESCppClientDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CESCppClientDlg)
    //}}AFX_DATA_INIT

    m_bConnected = false;
    m_nReflectorCount = 0;

    m_lStatusColor = 255;
    m_lPrevColor = 0;
    m_pcb = NULL; // brush for traffic light
}

void CESCppClientDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CESCppClientDlg)
    DDX_Control(pDX, IDC_BUTTON_CONNECT, m_buttonConnect);
    DDX_Control(pDX, IDC_COMBO_REFL, m_comboReflector);
    DDX_Control(pDX, IDC_EDIT_ADDR, m_editAddress);
    DDX_Control(pDX, IDC_STATIC_RESULT, m_staticResult);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CESCppClientDlg, CDialog)
    //{{AFX_MSG_MAP(CESCppClientDlg)
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_BUTTON_CONNECT, OnButtonConnect)
    ON_BN_CLICKED(IDC_BUTTON_INITIALIZE, OnButtonInitialize)
    ON_BN_CLICKED(IDC_BUTTON_FINDREFL, OnButtonFindReflector)
    ON_BN_CLICKED(IDC_BUTTON_MEASURE, OnButtonMeasure)
    ON_CBN_SELCHANGE(IDC_COMBO_REFL, OnSelchangeComboReflector)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CESCppClientDlg message handlers

BOOL CESCppClientDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // This must be done prior to use anything from socket library
    //AfxSocketInit(); // not required for our own CESCoket class

    // according to MFC documentation, we must create the socket after construction.
    // (note that construction is implicit when CSocket member variable is allocated.
    if (!m_socket.Create())
    {
        AfxMessageBox(_T("Failed to create socket - fatal error, exiting"));
        OnCancel();
    }
    else
        TRACE(_T("Socket creation OK\n"));

    m_editAddress.SetWindowText(_T("192.168.0.1")); // default factory setting server address

    return TRUE;  // return TRUE  unless you set the focus to a control
}


void CESCppClientDlg::OnButtonConnect() 
{
    CString sServerAddr;

    // Get the server address or hostname from entry field
    m_editAddress.GetWindowText(sServerAddr);

    // Check if entry is avialable
    if (sServerAddr.IsEmpty() || isspace(sServerAddr[0]))
    {
        Beep(2000, 100);
        AfxMessageBox(_T("Please enter address of your server (no leading blanks allowed)"));
        m_editAddress.SetSel((DWORD)MAKELONG(0, -1)); // just cosmetics - highlight the incorrect text if not empty
        m_editAddress.SetFocus(); // catch the cursor into field where input expected
        return;
    }

   // Try to connect to server - emScon always sits on port 700
   // Note: Connect() can fail with a variety of errors. Use GetLastError() to figure out
   //       what went wrong. This is not done in this sample. See MFC documentation of 
   //       CAsyncSocket::Connect() for further details.

    if (!m_socket.Connect(sServerAddr, 700))
    {
        // analyzing last error can be helpful for debugging and should be done
        // in real applications
        //int nErr = GetLastError();

        Beep(2000, 100);
        AfxMessageBox(_T("Connection failed. make sure server is running and IP address is correct"));
    }
    else
    {
        m_bConnected = true;
        m_buttonConnect.EnableWindow(false); // disable button, prevent a second connection
        TRACE(_T("Connection to server OK\n"));

        // Ensure desired units - hardcoded (thus these cannot be changed through the user-interface)
        // This command is the starting point for a 'chain of init commands'. Note that our interface
        // behaves asynchronous. Thus it's not possible to make several consecutive calls. We must 
        // send a command, catch its answer and in the answer handler, we can issue the next command.
        //
        if (!m_EsCommand.SetUnits(ES_LU_Meter, ES_AU_Gon, ES_TU_Celsius, ES_PU_HPascal, ES_HU_RH))
            AfxMessageBox(_T("Invoking SetUnits command failed"));

        // Flow of control continued in OnSetUnitsAnswer()
    }
}


void CESCppClientDlg::OnButtonInitialize() 
{
    if (!m_bConnected)
    {
        AfxMessageBox(_T("Not connected"));
        return;
    }

    if (!m_EsCommand.Initialize()) // Initizlize the tracker
        AfxMessageBox(_T("Invoking Initizlize command failed"));
}


void CESCppClientDlg::OnButtonFindReflector() 
{
    if (!m_bConnected)
    {
        AfxMessageBox(_T("Not connected"));
        return;
    }

    // Assume length units 'Meters'
    m_EsCommand.FindReflector(5.0); // a serious App should test return-status (as done above with Initialize)
}


void CESCppClientDlg::OnButtonMeasure() 
{
    if (!m_bConnected)
    {
        AfxMessageBox(_T("Not connected"));
        return;
    }

    // Here we assume that system is in Single Point Measurement mode !!!

    m_EsCommand.StartMeasurement(); // a serious app should test return-status (as done above with Initialize)
}


void CESCppClientDlg::OnSelchangeComboReflector() 
{
    int nIndex = m_comboReflector.GetCurSel(); 

    // get the current reflector
    m_EsCommand.SetReflector(m_reflIDMap[nIndex]);       
}


void CESCppClientDlg::OnCancel() 
{
    // virtual method override!
    // Disconnect from server

    if (m_bConnected)
    {
        m_socket.Close();
        TRACE(_T("Disconnected from server\n"));
    }

    CDialog::OnCancel();
}


void CESCppClientDlg::OnOK() 
{  
    // virtual method override!
    //
    // we have no OK button, but OnOK() is also called when
    // pressing enter - We do not want to exit the application
    // in this case, so do not call base methiod.
    //
    // CDialog::OnOK();
}


void CESCppClientDlg::InitReflectorBox()
{
    // IMPORTANT: combo box must not have sort flag!

    for (int i = 0; i < m_nReflectorCount; i++)
        m_comboReflector.AddString(m_reflNameMap[i]);

    // get the current reflector
    m_EsCommand.GetReflector(); 
}


HBRUSH CESCppClientDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
   HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

   // deal with the colored edit controls            
   if (nCtlColor == CTLCOLOR_STATIC)
   {
      if (pWnd->GetDlgCtrlID() == IDC_STATIC_INDICATOR)
      {
         if (m_lStatusColor && m_lPrevColor != m_lStatusColor)
         {
            if (m_pcb)
            {
               delete m_pcb;
               m_pcb = NULL;
            } // if

            m_pcb = new CBrush;
            ASSERT(m_pcb);

            if (m_pcb)
            {
               VERIFY(m_pcb->CreateSolidBrush(m_lStatusColor));
               m_lPrevColor = m_lStatusColor; // for next time
            } // if
         } // if

         if (m_pcb)
            hbr = *m_pcb;
      } // if
   } // if

   return hbr;
}

