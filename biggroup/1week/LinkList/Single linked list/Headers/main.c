#include <stdio.h>
#include <stdlib.h>
#include "single.h"




int main() {
    ran *p, *head, *end;                                         //定义三个指针
    p = (struct address *) malloc(sizeof(struct address));
    head = p;
    end = p;                                                    //让p head end 在同一个地方开始
    head->next = NULL;                                         //头的下一个是空


    while (1) {
        printf("请输入一个数字\n");                          //起始菜单
        printf("1为增加\n");
        printf("2为删除\n");
        printf("3为查询\n");
        printf("4为修改\n");
        printf("5为所有查询\n");


        int choose;                                                  //选择
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                //增加
            {
                add(p,&end);
               break;
            }                                 //表示end是最后一个  跳出循环

            case 2:{
                delete(p,head);
                break;}                                         //跳出循环
                                              //删除成功 就离开删除的循环
            case 3:{
                  find(p,head);
                   break;  }                                            //找到了 就退出循环
            case 4:{
                modify(p,head);
                 break;}
                 case 5:{
                     findall(p,head); break;
                 }
        }

    }
    return 0;
}