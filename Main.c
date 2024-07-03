#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

void clicking(int);
void initiation();

bool paused = false;
int Main()
{
  initiation();
  return 0;
}
void initiation()
{
  int cps;
  printf("Enter clicks per second: ");
  scanf("%d", &cps);
  clicking(cps);
}
void clicking(int cps)
{
    paused = false;
    while(!paused)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            Sleep(1000/cps);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        }

        if(GetAsyncKeyState(VK_F1)) // press f1 it restarts
        {
            break;
        }
        if(GetAsyncKeyState(VK_F3))
        {
            paused = true;
            break;
        }
        if(GetAsyncKeyState(VK_F5))
        {
            getchar();
            system("cls");
            printf("\nQuitting process...\n");
            ExitProcess(0x27); // exits the program
        }
    }
    if(paused)
    {
        do{
            Sleep(1);
        }while(!GetAsyncKeyState(VK_RBUTTON));
        paused = false;
        clicking(cps);
    }
    //reset console
    getchar();
    system("cls");
    //startover
    inititation();
    getch();
}
