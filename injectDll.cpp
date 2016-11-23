// dll_2.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

void showProcessInformation(char *list) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if(hSnapshot) {
        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);
        if(Process32First(hSnapshot, &pe32)) {
            do {
				char tmp[100];
				sprintf(tmp,"pid %d %s\n", pe32.th32ProcessID, pe32.szExeFile);
				
				strcat(list,tmp);
            } while(Process32Next(hSnapshot, &pe32));
			//::MessageBox(NULL,list,"ti",MB_OK);
		}
		CloseHandle(hSnapshot);
    }
}

BOOL APIENTRY DllMain( HANDLE hModule, 
					  DWORD  ul_reason_for_call, 
					  LPVOID lpReserved
					  )
{
	switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		//MessageBox((HWND)hModule,"injector success","��ʾ",MB_OK);
		//break;
	case DLL_THREAD_ATTACH:
		{
			//MessageBox((HWND)hModule,"injector success","��ʾ",MB_OK);
			////////////11-18,12:10,CreateWindows////////////////	
			HINSTANCE hInstance;  
			hInstance = GetModuleHandle(NULL);  
			WNDCLASS Draw;  
			Draw.cbClsExtra = 0;  
			Draw.cbWndExtra = 0;  
			Draw.hCursor = LoadCursor(hInstance, IDC_ARROW);;  
			Draw.hIcon = LoadIcon(hInstance, IDI_APPLICATION);;  
			Draw.lpszMenuName = NULL;  
			Draw.style = CS_HREDRAW | CS_VREDRAW;  
			Draw.hbrBackground = (HBRUSH)COLOR_BACKGROUND;  
			Draw.lpfnWndProc = WindowProc;  
			Draw.lpszClassName = _T("DDraw");  
			Draw.hInstance = hInstance;  
			
			RegisterClass(&Draw);  
			
			HWND hwnd = CreateWindow(  
				_T("DDraw"),           //����ע���������Ҫ��ȫһ��      
				_T("Process Name"),  //���ڱ�������      
				WS_OVERLAPPEDWINDOW, //���������ʽ      
				38,             //��������ڸ�����X����      
				20,             //��������ڸ�����Y����      
				640,                //���ڵĿ��      
				480,                //���ڵĸ߶�      
				NULL,               //û�и����ڣ�ΪNULL      
				NULL,               //û�в˵���ΪNULL      
				hInstance,          //��ǰӦ�ó����ʵ�����      
				NULL);              //û�и������ݣ�ΪNULL      
			
			// ��ʾ����      
			ShowWindow(hwnd, SW_SHOW);  
			
			// ���´���      
			UpdateWindow(hwnd);  
			
			// ��Ϣѭ��      
			MSG msg;  
			while (GetMessage(&msg, NULL, 0, 0))  
			{  
				TranslateMessage(&msg);  
				DispatchMessage(&msg);  
			}  
			break;
		}
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
		::MessageBox((HWND)hModule,"uninst","biaoti",MB_OK);
        break;
		}
		return TRUE;
		return TRUE;
}

LRESULT CALLBACK WindowProc(  
							HWND hwnd,  
							UINT uMsg,  
							WPARAM wParam,  
							LPARAM lParam  
							)  
{  
	static HWND hButton,hwndEdit;
	DWORD wmId,wmEvent;
    switch (uMsg)  
    {  
	case WM_CREATE:
		{
			hwndEdit=CreateWindow("Edit",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER| WS_VSCROLL|ES_MULTILINE|ES_READONLY, 10,15,610,350,hwnd,(HMENU)0x0001,NULL,NULL);
			hButton=CreateWindow("button","����",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,520,418,80,25,hwnd,(HMENU)0x0002,NULL,NULL);
			return 0;
		}
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		switch(wmId)
		{
		case 0x0002:
			{
				//MessageBox(hwnd,"1","2",MB_OK);
				char *address, *limit;
				int i=0;
				char content[100000],line[1000];
				for(address = (char *)0x0040A000, limit = address+0x00001FF0; address < limit; address+=0x10)
				{
					memset(line,0,1000);
					
					char tmp_addr[20];
					memset(tmp_addr,0,20);
					sprintf(tmp_addr,"0x%08p  ",address);
					
					char tmp_hex[60];
					for(i=0;i<16;i++)
					{
						sprintf((tmp_hex+i*3),"%02X ",(unsigned char)*(address+i));
					}
					
					char tmp_char[30];
					for(i=0;i<16;i++)
					{
						sprintf((tmp_char+i),"%c ",(unsigned char)*(address+i));
					}
					
					sprintf(line,"%s %s %s\r\n",tmp_addr,tmp_hex,tmp_char);
					
					SendMessage(hwndEdit,WM_GETTEXT,100000,(LPARAM)content);
					strcat(content,line);
					SendMessage(hwndEdit,WM_SETTEXT,NULL,(LPARAM)content);
					::UpdateWindow(hwndEdit);
				}
			}
			return 0;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);  
		}
		case WM_DESTROY:  
			{  
				PostQuitMessage(0);  
				return 0;  
			}  
    }  
    return DefWindowProc(hwnd, uMsg, wParam, lParam);  
}  