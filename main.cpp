
#include <Windows.h>
#include <stdio.h>

int main(int argc,char** argv)
{
	if (argc < 2)
		return 0;
	HWND hwnd = GetClipboardOwner();
	if (hwnd == NULL)
	{
		printf("%d\n", GetLastError());
		return 0;
	}
	if (!OpenClipboard(hwnd))
		return 0;
	int length=strlen(argv[1]);
	HGLOBAL handler=GlobalAlloc(GHND, length + 1);
	if (EmptyClipboard()==0)
	{
		printf("%d\n", GetLastError());
		return 0;
	}
	if (handler == NULL)
	{ 
		CloseClipboard();
		return 0;
	}
	LPVOID p = GlobalLock(handler);
	if (p == NULL)
	{
		CloseClipboard();
		return 0;
	}
	strcpy((char*)p, argv[1]);
	GlobalUnlock(handler);
	if (NULL == SetClipboardData(CF_TEXT, handler))
	{
		printf("%d\n",GetLastError());
	}
	else
	{
		CloseClipboard();
	}
	return 0;
}