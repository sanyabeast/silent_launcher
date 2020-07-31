// silent_launcher.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include <iostream>
#include <sstream>
#include <string>
#include "silent_launcher.h"

std::string get_app_name();

#define LOG(text) OutputDebugString(_T( "SILENT LAUNCER X: " text "\n"));
#define CONCAT (x, y) x y


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
    std::string app_name = get_app_name();
    LOG("init instance ...");
    std::string extension = ".bat";
    std::string script_name = app_name + extension;
    WinExec(script_name.c_str(), 0);
    return TRUE;

    return 0;
}


std::string get_app_name() {
    char myexepath[MAX_PATH] = { 0 };
    DWORD returnCode = GetModuleFileNameA(NULL, myexepath, MAX_PATH);
    if (returnCode != 0 && returnCode < MAX_PATH)
    {
        std::string filepath(myexepath);
        filepath = filepath.substr(filepath.find_last_of('\\') + 1);
        std::ostringstream ss;
        ss << filepath;
        std::string name = ss.str();
        return name.substr(0, name.length() - 4);
    }
    else
    {
        return "";
    }
}
