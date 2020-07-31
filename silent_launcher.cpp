// silent_launcher.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include <iostream>
#include <sstream>
#include <string>
#include "silent_launcher.h"

std::string get_app_name();
std::string get_executable_name();


std::string replace(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
    return str;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
    std::string command_code = get_executable_name();
    std::string launch_type = command_code;
    command_code = command_code.substr(1, command_code.length() - 5);
    launch_type = launch_type.substr(0, 1); 
    
    command_code = replace( command_code, "[fsh]", "/" );
    command_code = replace( command_code, "[bsh]", "\\");
    command_code = replace( command_code, "[qot]", "\"");
    command_code = replace( command_code, "[arx]", "*");
    command_code = replace( command_code, "[lth]", "<");
    command_code = replace( command_code, "[gth]", ">");
    command_code = replace( command_code, "[cln]", ":");
    command_code = replace( command_code, "[bar]", "|");
    command_code = replace( command_code, "[qst]", "?");
    WinExec(command_code.c_str(), launch_type.compare("~") == 0 ? 0 : 1 );
    return TRUE;
}

std::string get_executable_name() {
    char myexepath[MAX_PATH] = { 0 };
    DWORD returnCode = GetModuleFileNameA(NULL, myexepath, MAX_PATH);
    if (returnCode != 0 && returnCode < MAX_PATH) {
        std::string filepath(myexepath);
        filepath = filepath.substr(filepath.find_last_of('\\') + 1);
        std::ostringstream ss;
        ss << filepath;
        std::string name = ss.str();
        return name;
    }
    else {
        return "~exit.exe";
    }
}
