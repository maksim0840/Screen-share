#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// WINAPI - соглашение на вызов STDCALL
	// hInstance - дескриптор экзампляра объетка (содержаит мета данные о программе) - адресс в памяти на начало сигнатуры
	// hPrevInstance - устарел (использовался для 16-бит систем)
	// pCmdLine - аргументы командной строки
	// nCmdShow - кол-во аргументов которые пришли с командной строки (минимум 1)

	MSG msg; // стуктура с информацией о сообщении
	HWND hwnd; // дескриптор окна (информация об окне)
	WNDCLASSEX wc; // стуктура с характристикой окна

	// ЗАПОЛНЕНИЕ ПОЛЕЙ СТРУКТУРЫ
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0; // дополнительное выделение памяти в класе окна (размер инофрмации)
	wc.cbWndExtra = 0; // дополнительное выделение памяти в класе окна (размер инофрмации)
	wc.hbrBackground =  (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // handle курсора
	wc.hInstance = hInstance; // мета данные об окне
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION); // иконка приложения на панеле задач (не файла)
	wc.hIconSm = LoadIcon(hInstance, IDI_APPLICATION); // иконка в заголовке окна
	wc.lpfnWndProc = DefWindowProc;
	wc.lpszClassName = L"MyWindow"; // имя класса
	wc.lpszMenuName = NULL; // указатель на имя меню
	wc.style = CS_VREDRAW | CS_HREDRAW; // стили окна (комбинация флагов (больше флагов есть в документации))

	if (!RegisterClassEx(&wc)) { //регистрация окна в системе + проверка
		return EXIT_FAILURE; // если создать окно не удалось
	}

	hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindow", L"WindowTitle", WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 400, NULL, NULL, hInstance, NULL); // параметр класса совпадает с названным ранее
	if (!hwnd) {
		return EXIT_FAILURE;
	}

	ShowWindow(hwnd, nCmdShow); // показать окно
	UpdateWindow(hwnd); // обновить окно

	while (GetMessage(&msg, NULL, 0, 0) > 0) { // цикл, обрабатывабщий вызовы
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return EXIT_SUCCESS;

}
	
