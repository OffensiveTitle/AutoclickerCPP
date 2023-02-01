#include <iostream>
#include <Windows.h>

using namespace std;

bool autoclickeron = false;
int vkey = 0x05;

void click(){

INPUT inputone = {0};
inputone.mi.dwFlags = MOUSEEVENTF_LEFTUP;
INPUT inputtwo = {0};
inputtwo.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

SendInput(1,&inputone, sizeof(INPUT));
SendInput(1,&inputtwo, sizeof(INPUT));

if(GetKeyState(vkey) < 1) {

autoclickeron = !autoclickeron;

}
}

int main(){
while(true){

if(GetKeyState(vkey) > 0) {

autoclickeron = !autoclickeron;

}

while(autoclickeron == true){

click();

}

}

    return 0;
}