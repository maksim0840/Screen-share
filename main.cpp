#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// WINAPI - ���������� �� ����� STDCALL
	// hInstance - ���������� ���������� ������� (��������� ���� ������ � ���������) - ������ � ������ �� ������ ���������
	// hPrevInstance - ������� (������������� ��� 16 ��� �������)
	// pCmdLine - ��������� ��������� ������
	// nCmdShow - ���-�� ���������� ������� ������ � ��������� ������ (������� 1)

	MSG msg; // �������� � ����������� � ���������
	HWND hwnd; // ���������� ���� (���������� �� ����)
	WNDCLASSEX wc; // �������� � �������������� ����

	// ��������� ���� ���������
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0; // �������������� ��������� ������ � ����� ���� (�.�� �������� ������ ���� ��� ����������)
	wc.cbWndExtra = 0; // �������������� ��������� ������ � ����� ���� (�.�� �������� ������ ���� ��� ��������
	wc.hbrBackground =  (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // handle �������
	wc.hInstance = hInstance; // ���� ������ �� ����
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION); // ������ ���������� ����� �� ���������� (�� �����)
	wc.hIconSm = LoadIcon(hInstance, IDI_APPLICATION); // ������ � ��������� ����
	wc.lpfnWndProc = DefWindowProc;
	wc.lpszClassName = L"MyWindow"; // ��� ������
	wc.lpszMenuName = NULL; // ��������� �� ��� ����
	wc.style = CS_VREDRAW | CS_HREDRAW; // ����� ���� (���������� ������ (������ ������ ����� ���������� � ������������())

	if (!RegisterClassEx(&wc)) { //����������� ���� � ������� + ��������
		return EXIT_FAILURE; // ���� ������� ���� �� �������
	}

	hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindow", L"WindowTitle", WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 400, NULL, NULL, hInstance, NULL); // �������� ������ ��������� � ��������� �����
	if (!hwnd) {
		return EXIT_FAILURE;
	}

	ShowWindow(hwnd, nCmdShow); // �������� ����
	UpdateWindow(hwnd); // �������� ����

	while (GetMessage(&msg, NULL, 0, 0) > 0) { // ����, �������������� ������
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return EXIT_SUCCESS;

}
	