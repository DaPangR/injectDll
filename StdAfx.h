// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__86A42027_5515_41E8_AC24_69C0B22C59AE__INCLUDED_)
#define AFX_STDAFX_H__86A42027_5515_41E8_AC24_69C0B22C59AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Insert your headers here
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>

#include <windows.h>
#include <TlHelp32.h>
#include <stdio.h>
#include <string>
#include "TCHAR.h" 


LRESULT CALLBACK WindowProc(  
							HWND hwnd,  
							UINT uMsg,  
							WPARAM wParam,  
							LPARAM lParam  
							);
// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__86A42027_5515_41E8_AC24_69C0B22C59AE__INCLUDED_)
