#include <stdio.h>
#include "pcmanage.h"

int main(void){
    User u[20];
    int count, menu;
    count=loadData(u);
    int index=count;
    // count = loadData(u);
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if ((menu==1) || (menu == 3) || (menu == 4)|| (menu == 6)|| (menu == 7))
            if(count == 0) {
                continue;
            }
        if (menu == 1){
            listUser(u, index);
        }
        else if (menu == 2){
            if(createUser(&u[index++]) == 1){
                count++;
            printf("추가됨!\n");
            }
            continue;
        }
        else if (menu == 3){
            int no = selectDataNo(u, index);
            if(no == 0){
                printf("=>취소됨!\n");
                continue;
            }
            if(updateUser(&u[no-1]) == 1)
              printf("==> 수정됨\n"); 
        }
        else if (menu == 4){
            int no = selectDataNo(u, index);
            if(no == 0){
                printf("=>취소됨!\n");
                continue;
            }
            if(deleteUser(&u[no-1]) == 0){
            count--;
        }
        }
        else if (menu == 5){
            saveData(u, index);
            printf("=>저장됨!\n");
        }
        else if(menu == 6){
        int no = selectDataNo(u, index);
            if(no == 0){
                printf("=>취소됨!\n");
                continue;
            }
            order(&u[no-1]);
        }
        else if(menu == 7)
            readUser(u, index);
    }
    printf("종료됨!\n");
    return 0;
}