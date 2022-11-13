// #include <windows.h>
// #include <string>
// #include <stdio.h>

// using std::string;

// #pragma comment(lib, "ws2_32.lib")

// HINSTANCE hInst;
// WSADATA wsaData;
// void mParseUrl(char *mUrl, string &serverName, string &filepath, string &filename);
// SOCKET connectToServer(char *szServerName, WORD portNum);
// int getHeaderLength(char *content);
// char *readUrl2(char *szUrl, long &bytesReturnedOut, char **headerOut);

// int main()
// {
//     const int bufLen = 1024;
//     char *szUrl = "https://raw.githubusercontent.com/paimonhub/Paimonnode/main/base64";
//     long fileSize;
//     char *memBuffer, *headerBuffer;
//     FILE *fp;

//     memBuffer = headerBuffer = NULL;

//     if (WSAStartup(0x101, &wsaData) != 0)
//         return -1;

//     memBuffer = readUrl2(szUrl, fileSize, &headerBuffer);
//     printf("returned from readUrl\n");
//     printf("data returned:\n%s", memBuffer);
//     if (fileSize != 0)
//     {
//         printf("Got some data\n");
//         fp = fopen("downloaded.file", "wb");
//         fwrite(memBuffer, 1, fileSize, fp);
//         fclose(fp);
//         delete (memBuffer);
//         delete (headerBuffer);
//     }

//     WSACleanup();
//     return 0;
// }

// void mParseUrl(char *mUrl, string &serverName, string &filepath, string &filename)
// {
//     string::size_type n;
//     string url = mUrl;

//     if (url.substr(0, 7) == "http://")
//         url.erase(0, 7);

//     if (url.substr(0, 8) == "https://")
//         url.erase(0, 8);

//     n = url.find('/');
//     if (n != string::npos)
//     {
//         serverName = url.substr(0, n);
//         filepath = url.substr(n);
//         n = filepath.rfind('/');
//         filename = filepath.substr(n + 1);
//     }

//     else
//     {
//         serverName = url;
//         filepath = "/";
//         filename = "";
//     }
// }

// SOCKET connectToServer(char *szServerName, WORD portNum)
// {
//     struct hostent *hp;
//     unsigned int addr;
//     struct sockaddr_in server;
//     SOCKET conn;

//     conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//     if (conn == INVALID_SOCKET)
//         return NULL;

//     if (inet_addr(szServerName) == INADDR_NONE)
//     {
//         hp = gethostbyname(szServerName);
//     }
//     else
//     {
//         addr = inet_addr(szServerName);
//         hp = gethostbyaddr((char *)&addr, sizeof(addr), AF_INET);
//     }

//     if (hp == NULL)
//     {
//         closesocket(conn);
//         return NULL;
//     }

//     server.sin_addr.s_addr = *((unsigned long *)hp->h_addr);
//     server.sin_family = AF_INET;
//     server.sin_port = htons(portNum);
//     if (connect(conn, (struct sockaddr *)&server, sizeof(server)))
//     {
//         closesocket(conn);
//         return NULL;
//     }
//     return conn;
// }

// int getHeaderLength(char *content)
// {
//     const char *srchStr1 = "\r\n\r\n", *srchStr2 = "\n\r\n\r";
//     char *findPos;
//     int ofset = -1;

//     findPos = strstr(content, srchStr1);
//     if (findPos != NULL)
//     {
//         ofset = findPos - content;
//         ofset += strlen(srchStr1);
//     }

//     else
//     {
//         findPos = strstr(content, srchStr2);
//         if (findPos != NULL)
//         {
//             ofset = findPos - content;
//             ofset += strlen(srchStr2);
//         }
//     }
//     return ofset;
// }

// char *readUrl2(char *szUrl, long &bytesReturnedOut, char **headerOut)
// {
//     const int bufSize = 512;
//     char readBuffer[bufSize], sendBuffer[bufSize], tmpBuffer[bufSize];
//     char *tmpResult = NULL, *result;
//     SOCKET conn;
//     string server, filepath, filename;
//     long totalBytesRead, thisReadSize, headerLen;

//     mParseUrl(szUrl, server, filepath, filename);

//     ///////////// step 1, connect //////////////////////
//     conn = connectToServer((char *)server.c_str(), 80);

//     ///////////// step 2, send GET request /////////////
//     sprintf(tmpBuffer, "GET %s HTTP/1.0", filepath.c_str());
//     strcpy(sendBuffer, tmpBuffer);
//     strcat(sendBuffer, "\r\n");
//     sprintf(tmpBuffer, "Host: %s", server.c_str());
//     strcat(sendBuffer, tmpBuffer);
//     strcat(sendBuffer, "\r\n");
//     strcat(sendBuffer, "\r\n");
//     send(conn, sendBuffer, strlen(sendBuffer), 0);

//     //    SetWindowText(edit3Hwnd, sendBuffer);
//     printf("Buffer being sent:\n%s", sendBuffer);

//     ///////////// step 3 - get received bytes ////////////////
//     // Receive until the peer closes the connection
//     totalBytesRead = 0;
//     while (1)
//     {
//         memset(readBuffer, 0, bufSize);
//         thisReadSize = recv(conn, readBuffer, bufSize, 0);

//         if (thisReadSize <= 0)
//             break;

//         tmpResult = (char *)realloc(tmpResult, thisReadSize + totalBytesRead);

//         memcpy(tmpResult + totalBytesRead, readBuffer, thisReadSize);
//         totalBytesRead += thisReadSize;
//     }

//     headerLen = getHeaderLength(tmpResult);
//     long contenLen = totalBytesRead - headerLen;
//     result = new char[contenLen + 1];
//     memcpy(result, tmpResult + headerLen, contenLen);
//     result[contenLen] = 0x0;
//     char *myTmp;

//     myTmp = new char[headerLen + 1];
//     strncpy(myTmp, tmpResult, headerLen);
//     myTmp[headerLen] = NULL;
//     delete (tmpResult);
//     *headerOut = myTmp;

//     bytesReturnedOut = contenLen;
//     closesocket(conn);
//     return (result);
// }
// ===================================================================
// #include <string.h>
// #include <winsock2.h>
// #include <windows.h>
// #include <iostream>
// #include <vector>
// #include <locale>
// #include <sstream>
// using namespace std;
// #pragma comment(lib,"ws2_32.lib")




// int main( void ){

// WSADATA wsaData;
// SOCKET Socket;
// SOCKADDR_IN SockAddr;
// int lineCount=0;
// int rowCount=0;
// struct hostent *host;
// locale local;
// char buffer[10000];
// int i = 0 ;
// int nDataLength;
// string website_HTML;

// // website url
// string url = "https://raw.githubusercontent.com/paimonhub/Paimonnode/main/base64";

// //HTTP GET
// string get_http = "GET / HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";


//     if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
//         cout << "WSAStartup failed.\n";
//         system("pause");
//         //return 1;
//     }

//     Socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
//     host = gethostbyname(url.c_str());

//     SockAddr.sin_port=htons(80);
//     SockAddr.sin_family=AF_INET;
//     SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

//     if(connect(Socket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr)) != 0){
//         cout << "Could not connect";
//         system("pause");
//         //return 1;
//     }

//     // send GET / HTTP
//     send(Socket,get_http.c_str(), strlen(get_http.c_str()),0 );

//     // recieve html
//     while ((nDataLength = recv(Socket,buffer,10000,0)) > 0){        
//         int i = 0;
//         while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r'){

//             website_HTML+=buffer[i];
//             i += 1;
//         }               
//     }

//     closesocket(Socket);
//     WSACleanup();

//     // Display HTML source 
//     cout<<website_HTML;

//     // pause
//     cout<<"\n\nPress ANY key to close.\n\n";
//     cin.ignore(); cin.get(); 


//  return 0;
// }

// Edit : rewritten for cURLpp 0.7.3
// Note : namespace changed, was cURLpp in 0.7.2 ...

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <wininet.h>
#define MAXBLOCKSIZE 28+1 // openID 固定长 28
#pragma   comment(lib,"wininet.lib") //引入动态库

char* getWeiXinFromUserNameFromSEA(const char*);
using namespace std;

int main(){
    char *p=NULL; //用于存放返回结果
    p=getWeiXinFromUserNameFromSEA("https://raw.githubusercontent.com/paimonhub/Paimonnode/main/base64");

    cout<<p;
    return 0 ;
}

//我这里设置了函数 带有 返回值，大家可以不适用返回值！
char* getWeiXinFromUserNameFromSEA(const char *Url){
    char *str = new char[MAXBLOCKSIZE]; // 用于最后返回的结果，动态分配
    const char *x="From_AF"; int i = 0;//第一个是打开标记，i是下面的转化控制变量
    WCHAR exchange_text_from_url[256],exchange_text_from_x[256];
    LPCWSTR py = exchange_text_from_url;// url 转 lpcwstr 的中间变量
    LPCWSTR pz = exchange_text_from_x; //另外的信息
    //unicode编码 下的 设置，我这里使用了宽字节，免去转换的麻烦
    MultiByteToWideChar( 0, 0,x, -1,exchange_text_from_x, 64 );//WCHAR to LPCWSTR，转化
    MultiByteToWideChar( 0, 0,Url, -1, exchange_text_from_url, 256 );
    //结束转化
    HINTERNET handle_for_init_internet = InternetOpen("From_AF", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
     if (handle_for_init_internet != NULL){
         HINTERNET handle_for_read_info = InternetOpenUrl(handle_for_init_internet, Url, NULL,NULL,NULL,NULL);
         if (handle_for_read_info != NULL){
             char result[MAXBLOCKSIZE]; //用于保存 缓冲区的数据组合
             char buffer[MAXBLOCKSIZE];//下载文件的缓冲区
             DWORD bytes_read = 1;//下载的字节数
             BOOL temp_boolean;
             while(bytes_read!=0){
                 //使用 InternetReadFile 从缓存区 读取 数据到 buffer 字符串，要度的字节数是 buffer的有效长度，控制是 bytes_read
                 temp_boolean = InternetReadFile(handle_for_read_info,buffer,sizeof(buffer), &bytes_read);
             }
             for(i;i<MAXBLOCKSIZE-1;i++){
                 if(i==MAXBLOCKSIZE-2 && buffer[i]=='0'){ //去掉最后的干扰值 0

                 }else if(buffer[i]>=34 && buffer[i]<=126){ //多种测试，最终还是使用 ASCII 码范围判断来解决了 烫烫烫~~~~
                    //cout<<buffer[i]; //通过使用循环 针对性地 输出单个 字符消除缓冲区的其他混杂 空量
                    //这里不直接搞出 buffer 是因为，缓存区里有很多 不知什么数据在输出的时候会变成很多烫，一般是空才会有烫
                     result[i]=buffer[i];  //经过测试，这个逐个赋值能够去掉 其中夹杂的 烫~~~
                 }
             }
             result[i]='\0'; //赋值 结尾 符，防止 自身爆 烫
             strcpy(str,result); //copy 给 字符串指针，用于返回
             //安全操作，销毁句柄
             InternetCloseHandle(handle_for_read_info); handle_for_read_info = NULL;
         }
         InternetCloseHandle(handle_for_init_internet); handle_for_init_internet = NULL;
         return str;
    }
}