#include <stdio.h>
#include <stdlib.h>
#include "single.h"




int main() {
    ran *p, *head, *end;                                         //��������ָ��

    p = (struct address *) malloc(sizeof(struct address));
    head = p;
    head->front = NULL;
    end = p;                                                    //��p head end ��ͬһ���ط���ʼ
    head->next = NULL;                                         //ͷ����һ���ǿ�


    while (1) {
        printf("������һ������\n");                          //��ʼ�˵�
        printf("1Ϊ����\n");
        printf("2Ϊɾ��\n");
        printf("3Ϊ������ѯ\n");
        printf("4Ϊ�޸�\n");
        printf("5Ϊ����\n");
        printf("6Ϊ���в�ѯ\n");


        int choose;                                                  //ѡ��
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                //����
            {
                add(p,&end,head);
               break;
            }                                 //��ʾend�����һ��  ����ѭ��

            case 2:{
                delete(p,head);
                break;}                                         //����ѭ��
                                              //ɾ���ɹ� ���뿪ɾ����ѭ��
            case 3:{
                  find(p,head);
                   break;  }                                            //�ҵ��� ���˳�ѭ��
            case 4:{
                modify(p,head);
                 break;}
                 case 5:{printf("������Ҫ�����λ��\n");
                     int in ;
                     scanf("%d",&in);
                     printf("������Ҫ���������\n");
                     int insedata;
                     scanf("%d",&insedata);
                     insert(in,insedata,p,head);
                     break;
                 }
                 case 6:{ findall(p,head); break;}
        }

    }
    return 0;
}