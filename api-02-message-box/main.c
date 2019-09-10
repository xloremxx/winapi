#include <windows.h>

INT APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
  return MessageBox(NULL, "Awesome Text", "Caption", 0);
}
