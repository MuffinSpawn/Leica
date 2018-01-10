// ESSocket.h : header file
//
#ifndef ESSOCKET_H
#define ESSOCKET_H

#pragma once

#include <Winsock2.h>  // win32 socket stuff

#define WM_LTC_WINSOCK_MSG_RECEIVED WM_USER+001

/////////////////////////////////////////////////////////////////////////////
// CESSocket class - a replacement-class for CSocket of MFC
//
// CESSocket should not block on high data rate, as CSocket does. However,
// CESSocket is not a full replacement of CSocket. Therea are only sa few
// methods implemented as required for tracker clients.

class CESSocket
{
friend class CMessageTargetWnd;

public:
   CESSocket();
   virtual ~CESSocket();

protected:
   virtual void OnReceive(int nErrorCode);

public:
   bool Create();
   bool Connect(LPCTSTR lpszHostAddress, UINT nHostPort);
   int Send(const void* lpBuf, int nBufLen, int nFlags = 0);
   int Receive(void* lpBuf, int nBufLen, int nFlags = 0);
   void Close();
   int GetLastError();

private:
   CMessageTargetWnd *m_pWndMessageTarget;
   SOCKET m_sock;
   int m_nLastError;

   static int m_nInstanceCount;
};


//Helper class CMessageTargetWnd

class CMessageTargetWnd : public CWnd
{
public:
   CMessageTargetWnd(CESSocket*);

protected:
   LRESULT OnDataReceive(WPARAM, LPARAM);
   DECLARE_MESSAGE_MAP()

private:
   CESSocket *m_pESSocket;
};

#endif // ESSOCKET_H
