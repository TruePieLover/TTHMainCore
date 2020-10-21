/////////////////////////////////////////////////////////////////////////
//				TTHMainCore vTTHMain1.0 (DevBuild)
// Project: PieCore
// Author: Pie
// Project: PieCore
// Creation Date: 10/7/2020
// Copyright2020: TTH and all registered domains
// PieCore.h: Main app header file
/////////////////////////////////////////////////////////

#pragma once

#include "resource.h"
#include "framework.h"
#include <new>

#define MAD_STRING_SIZE 100

/* Global PieCore module declares */
HINSTANCE g_hInst;
static HWND g_hWnd;
static TCHAR g_szPieWndTitle[MAD_STRING_SIZE] = _T("DesktopApp");
static TCHAR g_szPieWndClass[MAD_STRING_SIZE] = _T("Windows Desktop Guided Tour Application");
ATOM RegisterPieWindow(HINSTANCE hInstance); // Register our window
BOOL InitAppInstance(HINSTANCE, int);
LRESULT CALLBACK PieWndProc(HWND, UINT, WPARAM, LPARAM); // Main app window procedure
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

struct WindowStateData {

};
WindowStateData* ptrState = new (std::nothrow)  WindowStateData;


