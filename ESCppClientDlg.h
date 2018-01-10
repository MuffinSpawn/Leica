// ESCppClientDlg.h : header file
//
#ifndef ESCPPCLIENTDLG_H
#define ESCPPCLIENTDLG_H

#pragma once

//#include <Afxsock.h> // used for CSocket

// Afxsock.h/CSocket (MFC) seems to be unreliable and often caused 
// deadlocks after about 10 minutes tracking reflector positions.
// We therefore designed our own CESSocket class (stripped down to 
// real essentials) based directly on the 'Winsock2' library instead.
#include "ESSocket.h" 

// add Emscon 'intelligence' (using namespace is optional)
#define ES_USE_EMSCON_NAMESPACE
#include "ES_CPP_API_Def.h"


/////////////////////////////////////////////////////////////////////////////
// CESAPISocket class. We must derive our own class in order to override the
// virtual function OnReceive()

class CESAPISocket : public CESSocket /*CSocket*/
{
protected:
   /*virtual*/ void OnReceive(int nErrorCode); // will be invoked if something to read from socket
};


/////////////////////////////////////////////////////////////////////////////
// CMyESAPICommand class. We must derive our own class in order to override 
// the virtual function SendPacket()

class CMyESAPICommand : public EmScon::CESAPICommand // prefix 'EmScon::' due namespace
{
protected:
   /*virtual*/ bool SendPacket(void* PacketStart, long PacketSize); 
};


/////////////////////////////////////////////////////////////////////////////
// derive class from CESAPIReceive in order to use C++ interface
// (easier to use than C- interface)

class CMyESAPIReceive: public EmScon::CESAPIReceive // prefix 'EmScon::' due namespace
{
   ////////////////////////////////////////////////////////////////////
   // override virtual functions of those answers you are interested in:

protected:
   // general answer handlers:
   void OnCommandAnswer(const BasicCommandRT&); // called for every command
   void OnErrorAnswer(const ErrorResponseT&); // called on unsolicited error, e.g. beam break
   void OnSystemStatusChange(const SystemStatusChangeT&);

   // Particular command/data handlers (as far as affected by this sample):
   void OnSingleMeasurementAnswer(const SingleMeasResultT&);
   void OnInitializeAnswer();
   void OnFindReflectorAnswer();
   void OnGetReflectorAnswer(const int iInternalReflectorId);
   void OnSetReflectorAnswer();
   void OnSetUnitsAnswer();
   void OnSetLongSystemParamAnswer();

   void OnReflectorPosAnswer(const ReflectorPosResultT&) ;

   void OnGetReflectorsAnswer(const int iTotalReflectors,
                              const int iInternalReflectorId,
                              const ES_TargetType targetType,
                              const double dSurfaceOffset,
                              const unsigned short cReflectorName[32]);
};


/////////////////////////////////////////////////////////////////////////////
// CESCppClientDlg dialog

class CESCppClientDlg : public CDialog
{
// Construction
public:
   CESCppClientDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
   //{{AFX_DATA(CESCppClientDlg)
   enum { IDD = IDD_ESCPPCLIENT_DIALOG };
   CComboBox m_comboReflector;
   CButton    m_buttonConnect;
   CEdit     m_editAddress;
   CStatic m_staticResult;
   //}}AFX_DATA

   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CESCppClientDlg)
   protected:
   virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV support
   //}}AFX_VIRTUAL

// Implementation
protected:
   // Generated message map functions
   //{{AFX_MSG(CESCppClientDlg)
   virtual BOOL OnInitDialog();
   afx_msg void OnButtonConnect();
   afx_msg void OnButtonInitialize();
   afx_msg void OnButtonFindReflector();
   afx_msg void OnButtonMeasure();
   virtual void OnCancel();
   virtual void OnOK();
   afx_msg void OnSelchangeComboReflector();
   afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()

   bool m_bConnected; // a status variable indicating whether connection is established

   CBrush *m_pcb;
   long m_lStatusColor;
   long m_lPrevColor;

public: // we need to access this from CMySocket, so make it public 
        //(which is not good C++ style! - a real application should provide an accessor
   CMySocket m_socket; // For TCP/IP communication

   CMyESAPIReceive m_EsReceive; // public object - not so nice - should be avoided in real application
   CMyESAPICommand m_EsCommand; // public object - not so nice - should be avoided in real application

   int m_nReflectorCount;     // public parameters are not really good design - should be better designed in real application
   int m_reflIDMap[24];       // index to ID mapping, max 24 reflectors supported
   CString m_reflNameMap[24]; // index to Name mapping, max 24 reflectors supported

   void InitReflectorBox();

   void SetStatusColor(long lColor) 
      {m_lStatusColor = lColor; 
       CWnd* pWnd = GetDlgItem(IDC_STATIC_INDICATOR); 
       if (pWnd) pWnd->Invalidate();}
};

#endif // ESCPPCLIENTDLG_H
