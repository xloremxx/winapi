#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
  static TCHAR szAppName[] = _T("HelloWin");
  HWND hwnd;
  MSG msg;
  WNDCLASSEX wndclass;

  wndclass.cbSize = sizeof (wndclass);
  wndclass.style = CS_HREDRAW | CS_VREDRAW;
  wndclass.lpfnWndProc = WndProc;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.hInstance = hInstance;
  wndclass.hIcon = LoadIcon (NULL, IDI_APPLICATION);
  wndclass.hCursor = LoadCursor (NULL, IDC_ARROW);
  wndclass.hbrBackground = (HBRUSH) GetStockObject (LTGRAY_BRUSH);
  wndclass.lpszMenuName = NULL;
  wndclass.lpszClassName = szAppName;
  wndclass.hIconSm = LoadIcon (NULL, IDI_APPLICATION);

  RegisterClassEx (&wndclass);

  hwnd = CreateWindow (szAppName,		 // window class name
      _T("Window"),		 // window caption
      WS_OVERLAPPEDWINDOW,	 // window style
      CW_USEDEFAULT,			 // initial x position
      CW_USEDEFAULT,			 // initial y position
      CW_USEDEFAULT,			 // initial x size
      CW_USEDEFAULT,			 // initial y size
      NULL,					// parent window handle
      NULL,					// window menu handle
      hInstance,				 // program instance handle
      NULL);					 // creation parameters

  ShowWindow (hwnd, iCmdShow);
  UpdateWindow (hwnd);

  while (GetMessage (&msg, NULL, 0, 0))
  {
    TranslateMessage (&msg);
    DispatchMessage (&msg);
  }
  return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
  HDC hdc;
  PAINTSTRUCT ps;
  RECT rect;

  switch (iMsg)
  {
    case WM_PAINT :
      hdc = BeginPaint (hwnd, &ps);

      GetClientRect (hwnd, &rect);
      SetBkMode(hdc, TRANSPARENT);

      DrawText (hdc, _T("RANDOM TEXT"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
      EndPaint (hwnd, &ps);
      return 0;

    case WM_DESTROY :
      PostQuitMessage (0);
      return 0;
  }

  return DefWindowProc (hwnd, iMsg, wParam, lParam);
}
