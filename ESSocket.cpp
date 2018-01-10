// ESSocket.cpp
//
#ifndef WINVER
#if _MSC_VER <= 1200 // up to VC6.0
    #define WINVER 0x0400
#else
    #define WINVER 0x0501
#endif
#endif

#include <afxwin.h>
#include "ESSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CESSocket class
//

int CESSocket::m_nInstanceCount = 0;

CESSocket::CESSocket()
{
   m_pWndMessageTarget = new CMessageTargetWnd(this);
   m_sock = 0;
   m_nLastError = 0;

   // keep track of #of instances; CESSocket is not designed to support multiple instances!
   m_nInstanceCount++;
   ASSERT(m_nInstanceCount == 1);
}


CESSocket::~CESSocket() 
{
   Close(); // just in case the application did not call Close()

   if (WSACleanup())
      TRACE(_T("WSACleanup() failed\n"));
      
   if (m_pWndMessageTarget)
   {
      if (::IsWindow(m_pWndMessageTarget->m_hWnd)) 
         VERIFY(m_pWndMessageTarget->DestroyWindow());

      delete m_pWndMessageTarget;
   }

   m_nInstanceCount--;
}


void CESSocket::OnReceive(int nErrorCode)
{
   ASSERT(false); // derived class does not provide an implementation for OnReceive()
   TRACE(_T("virtual OnReceive() called"));
}


bool CESSocket::Create()
{
   WSADATA WSAData;

   ASSERT(m_sock == 0); // call Create only once!
   m_nLastError = 0;

   if (m_nInstanceCount != 1)
   {
      ASSERT(false);
      return false; // this class does not support more than one instance
   }

   if (!::IsWindow(m_pWndMessageTarget->m_hWnd))
   {
      CWnd *pWndParent = CWnd::GetDesktopWindow();

      // This call may fail on Win98 / Unicode builds! use non- Unicode version in these cases
      m_pWndMessageTarget->CWnd::Create(NULL, _T("cessocket_message_sink"), WS_CHILD, 
                                        CRect(0, 0, 20, 20), pWndParent, 0);

      if (!::IsWindow(m_pWndMessageTarget->m_hWnd))
      {
         ASSERT(false);
         TRACE(_T("Creation or message- target window failed\n"));
         return false;
      }

      if (WSAStartup(MAKEWORD(1,1), &WSAData) == 0) 
      {
          m_sock = socket(PF_INET, SOCK_STREAM, 0);

          if (m_sock == INVALID_SOCKET)
          {
             m_nLastError = WSAGetLastError();
             m_sock = 0;
             WSACleanup();
             VERIFY(m_pWndMessageTarget->DestroyWindow());
             TRACE(_T("Socket creation failed\n"));
             return false;
          }
      }
      else
      {
         TRACE(_T("WSAStartup failed\n"));
         return false;
      }
   }
   else
   {
      ASSERT(m_sock != 0);
      ASSERT(false); // target window and socket already exists - Create should be called only once!
   }

   return true;
}


bool CESSocket::Connect(LPCTSTR lpszHostAddress, UINT nHostPort)
{
   #ifdef _UNICODE
   USES_CONVERSION; // for W2A macro
   #endif

   PHOSTENT phe;
   SOCKADDR_IN dest_sin;
   struct in_addr address;

   if (!m_pWndMessageTarget)
   {
      ASSERT(false);
      return false;
   }

   if (m_sock == 0)
   {
      // Did you miss to call Create()? Did you already close the socket?
      ASSERT(false);
      return false;
   }

   // Note: Once Close() is called, you cannot re-use the socket!
   // CESSocket class is neither designed to support multiple 
   // instances not to re-use once closed connections. You must
   // delete the current instance and create a new one for a 
   // re-connection or a connection to a different server.

   memset(&dest_sin, 0, sizeof dest_sin);
   dest_sin.sin_family = AF_INET;
   dest_sin.sin_port = htons(nHostPort); 

   if (_tcschr(lpszHostAddress, '.') == 0)
   {
      #ifdef _UNICODE
      phe = gethostbyname(W2A(lpszHostAddress));
      #else
      phe = gethostbyname(lpszHostAddress);
      #endif

      if (phe == NULL)
      {
         m_nLastError = WSAGetLastError();
         TRACE(_T("gethostbyname failed\n"));
         return false;
      } // if

      memcpy((char FAR *)&(dest_sin.sin_addr), phe->h_addr, phe->h_length);
   } // if
   else
   {
      #ifdef _UNICODE
      address.s_addr = inet_addr(W2A(lpszHostAddress));
      #else
      address.s_addr = inet_addr(lpszHostAddress);
      #endif

      dest_sin.sin_addr = address;
   }

   if (connect(m_sock, (LPSOCKADDR)&dest_sin, sizeof dest_sin))
   {
      m_nLastError = WSAGetLastError();
      TRACE(_T("Connection to server failed.\nCheck host-id and port# !\n"));
      return false;
   }
      
   if (WSAAsyncSelect(m_sock, *m_pWndMessageTarget, WM_LTC_WINSOCK_MSG_RECEIVED, FD_READ) > 0) 
   {
      m_nLastError = WSAGetLastError();
      TRACE(_T("WSAAsyncSelect failed\n"));
      return false;
   } // if

   TRACE(_T("Connection to server OK\n"));
   m_nLastError = 0;
   ASSERT(m_sock != 0);
   return true; // success
}


int CESSocket::Send(const void* lpBuf, int nBufLen, int nFlags)
{
   if (send(m_sock, (const char*)lpBuf, nBufLen, nFlags) == SOCKET_ERROR)
   {
      m_nLastError = WSAGetLastError();
      return false;
   }

   m_nLastError = 0;
   return true;
}


int CESSocket::Receive(void* lpBuf, int nBufLen, int nFlags)
{
   int nBytes = 0;

   if ((nBytes = recv(m_sock, (char*)lpBuf, nBufLen, nFlags)) == SOCKET_ERROR)
   {
      m_nLastError = WSAGetLastError();
      return false;
   }

   m_nLastError = 0;
   return nBytes;
}


void CESSocket::Close()
{
   if (m_sock)
   {
      m_nLastError = 0;
      ASSERT(m_pWndMessageTarget);

      // stop receiving messages
      WSAAsyncSelect(m_sock, *m_pWndMessageTarget, 0, 0);

      if (closesocket(m_sock) == SOCKET_ERROR)
         m_nLastError = WSAGetLastError();

      m_sock = 0;
      TRACE(_T("Socket closed\n"));
   }
}


int CESSocket::GetLastError() 
{
   return m_nLastError;
}


/////////////////////////////////////////////////////////////////////////////
// CMessageTargetWnd class
//

CMessageTargetWnd::CMessageTargetWnd(CESSocket *pESSocket)
{
   m_pESSocket = pESSocket; 
}


LRESULT CMessageTargetWnd::OnDataReceive(WPARAM wParam, LPARAM lParam)
{
   m_pESSocket->OnReceive(HIWORD(lParam));
   return 0;
}

BEGIN_MESSAGE_MAP(CMessageTargetWnd, CWnd)
   ON_MESSAGE(WM_LTC_WINSOCK_MSG_RECEIVED, OnDataReceive)
END_MESSAGE_MAP()





