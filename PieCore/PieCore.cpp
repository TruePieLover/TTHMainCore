/////////////////////////////////////////////////////////////////////////
//				TTHMainCore vTTHMain1.0 (DevBuild)
// Author: Pie
// Project: PieCore
// Creation Date: 10/7/2020
// Copyright2020: TTH and all registered domains
// PieCore.cpp: Main PieCore application source file 
/////////////////////////////////////////////////////////


#include "pch.h"
#include "framework.h"
#include "PieCore.h"



// Step 1) Essential Main Window Entry Functionalityn	
//--------------------------------------------------
#pragma region Essential Main Window Entry Functionality

/* Main win app entry point */
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// Declare parameters not needed to be used 
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	LoadStringW(hInstance, IDS_APP_TITLE, g_szPieWndTitle, MAD_STRING_SIZE);
	LoadStringW(hInstance, IDC_PIECORE, g_szPieWndClass, MAD_STRING_SIZE);
	RegisterPieWindow(hInstance);

	// Perform application initialization:
	if (!InitAppInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// Main app message loop
	MSG msg;
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PIECORE));
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	int result = (int)msg.wParam; // Get success result from wParam 
	return result;
}
#pragma endregion


// Step 2) Setup Window Helper Functions	
//--------------------------------------------------
#pragma region Setup Window Helper Functions

ATOM RegisterPieWindow(HINSTANCE hInstance) 
{
	WNDCLASSEXW pcwcex; // PieCore window class declare
	pcwcex.cbSize = sizeof(WNDCLASSEX);
	pcwcex.style = CS_HREDRAW | CS_VREDRAW;
	pcwcex.lpfnWndProc = PieWndProc;
	pcwcex.cbClsExtra = 0;
	pcwcex.cbWndExtra = 0;
	pcwcex.hInstance = hInstance;
	pcwcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PIEICO1));
	pcwcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	pcwcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	pcwcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PIECORE); 
	pcwcex.lpszClassName = g_szPieWndClass;
	pcwcex.hIconSm = LoadIcon(pcwcex.hInstance, MAKEINTRESOURCE(IDI_PIEICO1));
	return RegisterClassExW(&pcwcex);
}


BOOL InitAppInstance(HINSTANCE hInstance, int nCmdShow) 
{
	g_hInst = hInstance; // Store instance handle in our global variable
	HWND hWnd = CreateWindowW(g_szPieWndClass, g_szPieWndTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

#pragma endregion


//	Step 3) Define our essential app procedures
//--------------------------------------
#pragma region Essential App Proc Definitions

PAINTSTRUCT _psWnd; // Field to hold our paint window struct info
HDC _hdcWnd; // Handle to the device contect were drawing to for window

/* Main window proc */
LRESULT CALLBACK PieWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	// The main window painting message (WM_PAINT is essential for paint and stylying our app 
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

#pragma endregion