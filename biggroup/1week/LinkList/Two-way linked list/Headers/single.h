//
// Created by HP on 2024/3/16.
//
#include <stdio.h>
#include <stdlib.h>



typedef struct address {
    int data ;                                                   //数据
    struct address *next;                                      //定义指针
    struct address *front;
} ran;
void add(struct address *p,struct address **end,struct address *head){
    ran *temp;
    printf("开始增加\n");
    p = (struct address *) malloc(sizeof(struct address));  //p指向了下一个新创建元素
    printf("请输入数据\n");
    scanf("%d", &p->data);
    (*end)->next = p;                                               //end跟着指向下一个
    (*end) = p;                                                      //更新尾节点地址
    (*end)->next = NULL;
    for(temp = head,p = head->next ;p;p=p->next,temp = temp->next ){
        p->front = temp ;
    }
}
void delete(struct address *p,struct address *head){
    ran *q;
    int delete ;
    int boolean1 = 0;
    int d = 0;
    while (1) {
        printf("请输入要删除的数据\n");
        scanf("%d", &delete);
        for (q = NULL, p = head; p; q = p,p=p->next) {             //两个指针 p负责删除 q负责记录删除的前一个
            if (delete==p->data) {
                if (q) {                                         //防止q为NULL
                    q->next = p->next;
                    free(p);                            //成功删除后 不再用p 转为用q记录
                    printf("删除成功\n");
                    boolean1=1; d=1;
                    break;}                                         //跳出循环
            }
        }
        if (boolean1 == 0) { printf("你要删除的数据 请重新输入\n"); }
        if (d == 1) { break; }
}}
void find(struct address *p,struct address *head){
    int find ;
    int e = 0;
    while (1) {                                            //对查询的数据进行判断 如果有 输出打印 没有的话重新输入
        printf("请输入要查询的数据\n");
        scanf("%d", &find);
        int boolean2 = 0;
        for (p = head->next; p; p=p->next) {
            if (find ==p->data ) {
                printf("该数据存在\n");
                e = 1;boolean2=1;
                break;

            }
        }
        if (boolean2 == 0) { printf("你要查询的数据不存在,请重新输入\n"); }
        if (e == 1) { break; }
    }
}
void modify(struct address *p,struct address *head){
    int modify;
    int f = 0;
    while (1) {                                                 //对查询的名字进行判断 如果有 输出打印 没有的话重新输入
        printf("请输入要修改的数据\n");
        scanf("%d", &modify);
        int boolean3 = 0;
        for (p = head->next; p; p=p->next) {
            if (modify==p->data) {
                boolean3=1;
                printf("请输入要修改的内容:\n");
                scanf("%d", &p->data);

                f=1;                                                    //退出循环
            }
        }
        if (boolean3 == 0) { printf("你要修改的数据不存在,请重新输入\n"); }
        if (f == 1) {   break; }
}}
void insert(int i ,int data ,struct address *p,struct address *head){
    int count = 0;
    ran *q;
    for (p = head->next; p; p=p->next){
        count ++;
        if(count == i){ q = (struct address *) malloc(sizeof(struct address)); q->data = data;
        q->front = p->front;
        q->front->next=q;
        q->next=p;
        p->front = q;}
    }

}
void findall(struct address *p,struct address *head){
    for (p=head->next; p;p=p->next ) {
        printf("%d ", p->data);

    }
    printf("\n");
}