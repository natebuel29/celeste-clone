#include <iostream>
#include "nb_lib.h"

// ########################################
//       Platform Globals
// ########################################

static bool running = true;

// ########################################
//       Platform Functions
// ########################################

bool platform_create_window(int width, int height, char *title);
void platform_update_window();

// ########################################
//      Windows Platform
// ########################################
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
// ########################################
//       Windows Globals
// ########################################
static HWND window;

// ########################################
//       Windows Platform Implementation
// ########################################

LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    switch (msg)
    {
    case WM_CLOSE:
    {
        running = false;
        break;
    }
    default:
    {
        // Let window handle the default input for now
        result = DefWindowProcA(window, msg, wParam, lParam);
    }
    }

    return result;
}
bool platform_create_window(int width, int height, char *title)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title;
    wc.lpfnWndProc = windows_window_callback; // w Callback for Input into the window

    if (!RegisterClassA(&wc))
    {
        return false;
    }

    // combines the most common into one
    // WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX
    int dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowExA(0,
                             title,
                             title,
                             dwStyle,
                             100,
                             100,
                             width,
                             height,
                             NULL,
                             NULL,
                             instance,
                             NULL);

    if (window == NULL)
    {
        return false;
    }

    ShowWindow(window, SW_SHOW);

    return true;
}

void platform_update_window()
{
    MSG msg;

    while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

#endif

int main()
{
    platform_create_window(1200, 720, "NB Motor");
    while (running)
    {
        platform_update_window();
        NB_TRACE("Test");
        NB_WARN("TEST");
        NB_ERROR("TEST");
        NB_ASSERT(false, "ASSERTION HIt");
    }

    return 0;
}