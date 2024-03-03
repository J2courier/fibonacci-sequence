#include <stdio.h>
#include <windows.h>
#define g gotoxy
#define p printf
#define s scanf


void gotoxy(int x,int y){
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
    system("cls");
     int i, next_term, previous_term = 0, present_term = 1, term, first_no = 0;
     char ans[20];
    do {
        g(2, 2);p("Enter No of Sequence: ");
        g(25, 2);s("%d", &term);
        for (i = 0; i < term; i++){
            if (i <= 1){
                next_term = i; 
            }
            else {
                next_term = previous_term + present_term;
                previous_term = present_term;
                present_term = next_term;
            }
            //g(1 , 3);p("%d\t", first_no);
            g(3 * i, 3);p(" %d\t", next_term);
        }
        g(2, 5);p("TRY AGAIN? Y/N: ");
        g(25, 5);s("%s", &ans);
        g(25, 2);p("           ");
        g(1, 3);p("            ");
        g(2, 3);p("            ");
        g(25, 5);p("           ");
    } while (ans == 'y' || ans == 'y');
    system("cls");
    exit(0);
}