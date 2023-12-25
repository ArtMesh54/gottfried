#pragma once

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

namespace gui {

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI OpenWindow(HINSTANCE hInstance = 0, 
                      HINSTANCE hPrevInstance = 0, 
                      PSTR pCmdLine = 0, 
                      int nCmdShow = SW_SHOWNORMAL)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"CalculatorWindow";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.
    HWND h_main_window = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Gottfried",                   // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (h_main_window == NULL)
    {
        return 0;
    }

    HWND hwnd_input_field = CreateWindow(TEXT("Edit"), TEXT("Equation"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 20, 200, 20, h_main_window, NULL, NULL, NULL);
    HWND hwnd_result_field = CreateWindow(TEXT("Edit"), TEXT("here will be result"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 50, 140, 20, h_main_window, NULL, NULL, NULL);
    HWND hwnd_calculate_button = CreateWindow(TEXT("button"), TEXT("Calculate"), WS_CHILD | WS_VISIBLE | WS_BORDER, 320, 20, 100, 30, h_main_window, NULL, NULL, NULL);

    ShowWindow(h_main_window, nCmdShow);
    UpdateWindow(h_main_window);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {

            }
        }
        case WM_CREATE:
        {
            CreateWindow(
                TEXT("button"), // lp class name
                TEXT("Beep"), // lp window name
                WS_VISIBLE | WS_CHILD, // dw style
                20, // x
                50, // y
                80, // n width
                25, // n height
                hwnd, // hwnd parent
                (HMENU) 1, // h menu
                NULL, // h instance
                NULL); // lp param
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
            return 0;

    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

}