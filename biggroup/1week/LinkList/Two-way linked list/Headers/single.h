//
// Created by HP on 2024/3/16.
//
#include <stdio.h>
#include <stdlib.h>



typedef struct address {
    int data ;                                                   //����
    struct address *next;                                      //����ָ��
    struct address *front;
} ran;
void add(struct address *p,struct address **end,struct address *head){
    ran *temp;
    printf("��ʼ����\n");
    p = (struct address *) malloc(sizeof(struct address));  //pָ������һ���´���Ԫ��
    printf("����������\n");
    scanf("%d", &p->data);
    (*end)->next = p;                                               //end����ָ����һ��
    (*end) = p;                                                      //����β�ڵ��ַ
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
        printf("������Ҫɾ��������\n");
        scanf("%d", &delete);
        for (q = NULL, p = head; p; q = p,p=p->next) {             //����ָ�� p����ɾ�� q�����¼ɾ����ǰһ��
            if (delete==p->data) {
                if (q) {                                         //��ֹqΪNULL
                    q->next = p->next;
                    free(p);                            //�ɹ�ɾ���� ������p תΪ��q��¼
                    printf("ɾ���ɹ�\n");
                    boolean1=1; d=1;
                    break;}                                         //����ѭ��
            }
        }
        if (boolean1 == 0) { printf("��Ҫɾ�������� ����������\n"); }
        if (d == 1) { break; }
}}
void find(struct address *p,struct address *head){
    int find ;
    int e = 0;
    while (1) {                                            //�Բ�ѯ�����ݽ����ж� ����� �����ӡ û�еĻ���������
        printf("������Ҫ��ѯ������\n");
        scanf("%d", &find);
        int boolean2 = 0;
        for (p = head->next; p; p=p->next) {
            if (find ==p->data ) {
                printf("�����ݴ���\n");
                e = 1;boolean2=1;
                break;

            }
        }
        if (boolean2 == 0) { printf("��Ҫ��ѯ�����ݲ�����,����������\n"); }
        if (e == 1) { break; }
    }
}
void modify(struct address *p,struct address *head){
    int modify;
    int f = 0;
    while (1) {                                                 //�Բ�ѯ�����ֽ����ж� ����� �����ӡ û�еĻ���������
        printf("������Ҫ�޸ĵ�����\n");
        scanf("%d", &modify);
        int boolean3 = 0;
        for (p = head->next; p; p=p->next) {
            if (modify==p->data) {
                boolean3=1;
                printf("������Ҫ�޸ĵ�����:\n");
                scanf("%d", &p->data);

                f=1;                                                    //�˳�ѭ��
            }
        }
        if (boolean3 == 0) { printf("��Ҫ�޸ĵ����ݲ�����,����������\n"); }
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