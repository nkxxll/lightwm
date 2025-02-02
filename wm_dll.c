#include <Windows.h>

__declspec(dllexport) LRESULT CALLBACK ShellProc(int code, WPARAM wparam, LPARAM lparam) {

	if (code == HSHELL_WINDOWCREATED || code == HSHELL_WINDOWDESTROYED) {
		HANDLE windowEvent = OpenEventW(EVENT_ALL_ACCESS, FALSE, L"LightWMWindowEvent");
		if (windowEvent) {
			SetEvent(windowEvent);
			CloseHandle(windowEvent);
		}
	}

	return CallNextHookEx(NULL, code, wparam, lparam);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReasonForCall, LPVOID lpReserved) 
{
	switch(ulReasonForCall) { 
		case DLL_PROCESS_ATTACH: 
			break; 
		case DLL_THREAD_ATTACH: 
			break;
		case DLL_THREAD_DETACH: 
			break; 
		case DLL_PROCESS_DETACH: 
			break; 
	}
		
	return TRUE; 
}

