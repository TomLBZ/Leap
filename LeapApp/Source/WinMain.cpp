#include <Windows.h>

#define MAX_NAME_STRING	256
#define HInstance()	GetModuleHandle(NULL)

WCHAR	WindowClass[MAX_NAME_STRING];
WCHAR	WindowTitle[MAX_NAME_STRING];

INT		WindowWidth;
INT		WindowHeight;

int CALLBACK WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT)
{
	/* - Initialize Global Variables - */

	wcscpy_s(WindowClass, TEXT("AppClass"));	// assign value to the wchar variable
	wcscpy_s(WindowTitle, TEXT("First Window"));	// assign value to the wchar variable
	WindowWidth = 1366;
	WindowHeight = 768;

	/* - Create Window Class - */

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);	// size of window obj
	wcex.style = CS_HREDRAW | CS_VREDRAW;	// window style
	wcex.cbClsExtra = 0;	// extra memory: not needed here
	wcex.cbWndExtra = 0;	// extra memory: not needed here

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);	// cursor style
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);	// background style

	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);	// icon (taskbar)
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);	// small icon (corner)

	wcex.lpszClassName = WindowClass;	// class name
	wcex.lpszMenuName = nullptr;	// menu name

	wcex.hInstance = HInstance();	// instance of the window

	wcex.lpfnWndProc = DefWindowProc;	// window behaviour

	RegisterClassEx(&wcex);	// register the windowclassex class

	/* - Create and Display Window - */

	// CreateWindow(class name, title, window style, window location h, window location v, width, height, parent window, menu, instance, instructions)
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd) 	// shut down immediately if the handle is not created properly
	{
		MessageBox(0, L"Failed to Create Window", 0, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);

	/* - Listen for Message Events - */

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

	return 0;
}