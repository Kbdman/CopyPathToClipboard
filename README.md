# CopyPathToClipboard

##introduce
A small tool to copy file path to clipboard.

##build
build with Visual Studio

##intall
Copy exe to a directory ,then regist to right-mouse menu by using command below,replace the path with your own path 
Reg ADD HKEY_CLASSES_ROOT\*\shell\CopyFilePath\command /d  "D:\tools\CopyPathToClipboard.exe %1" /f