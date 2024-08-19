#include<bits/stdc++.h>
#include <windows.h>
#include<Tchar.h>

using namespace std;

string envVarStrings[] =
{
  TEXT("OS         = %OS%"),
  TEXT("PATH       = %PATH%"),
  TEXT("HOMEPATH   = %HOMEPATH%"),
  TEXT("TEMP       = %TEMP%")
};
#define  ENV_VAR_STRING_COUNT  (sizeof(envVarStrings)/sizeof(string))
#define INFO_BUFFER_SIZE 32767

char buffer[MAX_COMPUTERNAME_LENGTH + 1];
DWORD size = sizeof(buffer);

void getComputerName()
{
  if(GetComputerName(buffer, &size))
  {
    cout<<"ComputerName: "<<buffer<<endl;
  }
  else
  {
    cout<<"GetComputerName error"<<endl;
  }
}

void getUserName()
{
  if(GetUserName(buffer, &size))
  {
    cout<<"UserName: "<<buffer<<endl;
  }
  else
  {
    cout<<"GetUserName error"<<endl;
  }
}

void getSystemDirectory()
{
  if(GetSystemDirectory(buffer, size))
  {
    cout<<"SystemDirectory "<<buffer<<endl;
  }
  else
  {
    cout<<"GetSystemDirectory error"<<endl;
  }
}

void getWindowsDirectory()
{
  if(GetWindowsDirectory(buffer, size))
  {
    cout<<"WindowsDirectory  "<<buffer<<endl;
  }
  else
  {
    cout<<"GetWindowsDirectory error"<<endl;
  }
}

void expandEnvironmentStrings()
{
  //定义接受扩展环境变量字符串结果的缓冲区
  char infoBuf[INFO_BUFFER_SIZE];
  DWORD  bufCharCount = INFO_BUFFER_SIZE;
  cout<<"Small selection of Environment Variables:"<<endl; 

  for( int i = 0; i < ENV_VAR_STRING_COUNT; ++i )
  {
    bufCharCount = ExpandEnvironmentStrings(envVarStrings[i].c_str(), infoBuf,
        INFO_BUFFER_SIZE ); 
    if( bufCharCount > INFO_BUFFER_SIZE )
      cout<<"Buffer too small to expand: "<<envVarStrings[i].c_str()<<endl;
    else if( !bufCharCount )
      cout<<"ExpandEnvironmentStrings"<<endl;
    else
      cout<<endl<< infoBuf<<endl;
  }
}

void getVersionex()
{
  OSVERSIONINFO osvi; /* 接受操作系统信息的结构体函数 */
  BOOL bIsWindowsXPorLater;
  
  //结构体清零初始化
  ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
  osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

  GetVersionEx(&osvi);
  
  //得到主要版本号和次要版本号
  bIsWindowsXPorLater = 
      ( (osvi.dwMajorVersion > 5) ||
      ( (osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion >= 1) ));
   cout<<"the system version is"<<osvi.dwMajorVersion<<endl;

  if(bIsWindowsXPorLater)
      printf("The system meets the requirements.\n");
  else printf("The system does not meet the requirements.\n");
}

int main()
{
	
  getUserName();
  getComputerName();
  getSystemDirectory();
  getWindowsDirectory();
  expandEnvironmentStrings();
  getVersionex(); 
	return 0;
}
