#include "pch.h"
/* -------------------------------------------- */
/*   Filename: WinMain.cpp                      */
/*   Author: TomLBZ                             */
/*   License: MIT License                       */
/* -------------------------------------------- */


/* -------------------------------------------- */
/*   Global Variables                           */
/* -------------------------------------------- */
#pragma region GlobalVariables

WCHAR	WindowClass[MAX_NAME_STRING];
WCHAR	WindowTitle[MAX_NAME_STRING];
INT		WindowWidth;
INT		WindowHeight;
HICON	hIcon;

#pragma endregion
/* -------------------------------------------- */

/* -------------------------------------------- */
/*   Pre-Declarations                           */
/* -------------------------------------------- */
#pragma region Pre-Declarations

VOID InitializeVariables();
VOID CreateWindowClass();
VOID InitializeWindow();
VOID MessageLoop();
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);

#pragma endregion
/* -------------------------------------------- */

/* -------------------------------------------- */
/*   Operations                                 */
/* -------------------------------------------- */
#pragma region Operations

int CALLBACK WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT)
{
	InitializeVariables();
	CreateWindowClass();
	InitializeWindow();
	MessageLoop();

	return 0;
}

LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam) // handle, message, arg, arg
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}

#pragma endregion
/* -------------------------------------------- */

/* -------------------------------------------- */
/*   Functions                                  */
/* -------------------------------------------- */
#pragma region Functions

VOID InitializeVariables()
{
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING); // assign window title from resources
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING); // assign window class from resources

	WindowWidth = 1366;
	WindowHeight = 768;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

VOID CreateWindowClass()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);			// size of window obj
	wcex.style = CS_HREDRAW | CS_VREDRAW;		// window style
	wcex.cbClsExtra = 0;						// extra memory: not needed here
	wcex.cbWndExtra = 0;						// extra memory: not needed here
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);	// cursor style
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);	// background style
	wcex.hIcon = hIcon;							// icon (taskbar)
	wcex.hIconSm = hIcon;						// small icon (corner)
	wcex.lpszClassName = WindowClass;			// class name
	wcex.lpszMenuName = nullptr;				// menu name
	wcex.hInstance = HInstance();				// instance of the window
	wcex.lpfnWndProc = WindowProcess;			// window behaviour
	RegisterClassEx(&wcex);						// register the windowclassex class
}

VOID InitializeWindow()
{
	// CreateWindow(class name, title, window style, window location h, window location v, width, height, parent window, menu, instance, instructions)
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
	if (!hWnd) 	// shut down immediately if the handle is not created properly
	{
		MessageBox(0, L"Failed to Create Window", 0, 0);
		PostQuitMessage(0);
	}
	else 
	{
		ShowWindow(hWnd, SW_SHOW);
	}
}

VOID MessageLoop()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		// If there are Window messages then process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

#pragma endregion
/* -------------------------------------------- */
