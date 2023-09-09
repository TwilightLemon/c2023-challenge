//
// Created by twlm on 9/7/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
///C0
int main(){
    setbuf(stdout,NULL);
    printf("Hello world��I'm ��������");

    extern int MaxNum_v3(int,...);
    printf("Max = %d",MaxNum_v3(5,2,1,9,8,88));
    printf("\r\n");

    extern void Print99Chart();
    printf("\r\n");
    Print99Chart();

    extern void PrintReverse();
    PrintReverse();

    extern void PopOutExistence();
    PopOutExistence();

    extern void Sort();
    Sort();

    extern int Plus(int data[],int length);
    int data[]={1,2,4,7,3,4,1};
    printf("%d",Plus(data,7));
    printf("\r\n");

    extern int Factorial(int n);
    printf("%d", Factorial(5));
    printf("\r\n");

    extern void Fibonacci(int a1,int a2,int length);
    Fibonacci(1,1,20);
    printf("\r\n");

    extern int IsRT(int a,int b,int c);
    printf("%s",IsRT(3,4,5)?"RT!":"No RT..");

    extern float USDToRMB(float USD);
    float usd;
    printf("\r\nusd=");
    scanf("%f",&usd);
    printf("%f USD = %f",usd, USDToRMB(usd));
    return 0;
}

///C1 1.
int isPositiveNum(int n){
    return n>0;
}
///C1 2.
int isEvenNum(int n){
    return n%2==0;
}
///C1 3.
///Bing Says:�ܱ�4�����������ܱ�100���������ܱ�400���������Ϊ����
int isLeapYear(int year){
    return (year%4==0&&year%100!=0)||year%400==0;
}
///C1 4.
int MaxNum(int n1,int n2){
    return n1>n2?n1:n2;
}
///C1 5.
int MaxNum_v2(int n1,int n2,int n3){
    int m=n1>n2?n1:n2;
    return MaxNum(m,n3);
}
///C1 6.
int MaxNum_v3(int NumCount,...){
    va_list args;
    va_start(args,NumCount);
    int max= va_arg(args,int);
    for(int i=1;i<NumCount;i++){
        max= MaxNum(max,va_arg(args,int));
    }
    va_end(args);
    return max;
}

///C2 1.
void SayHello(){
    for(int i=0;i<10000;i++){
        printf("��ã�");
    }
}
///C2 2.
void PrintEvenNum(){
    for(int i=2;i<101;i+=2){
        printf("%d",i);
    }
}
///C2 3.
void PrintNum(){
    for(int i=1;i<=100;i++){
        if(i%3==0&&i%5!=0)
          printf("%d",i);
    }
}
void PrintNum_v2(){
    int sum=0;
    for(int i=1;i<=100;i++){
        if(i%7==0||i%10==7){
            printf("%d",i);
            sum+=i;
        }
    }
    printf("%d",sum);
}
void Print99Chart(){
    for(int i=1;i<10;i++){
        for(int x=1;x<i+1;x++){
            printf("%d x %d = %d  ",i,x,i*x);
        }
        printf("\r\n");
    }
}
///����n����(?���Բ���)Ȼ�������
void PrintReverse(){
    int n;
    printf("����n����(or any)����������������� n=");
    scanf("%d",&n);
    printf("Enter nums split by ','\r\n");
    char str[100];
    scanf("%s",str);
    char d[2]=",";
    char *token=strtok(str,d);
    char *data[n];
    int i=0;
    while(token!=NULL){
        data[n-i-1]=token;
        token=strtok(NULL,d);
        i++;
    }
    for(int x=0;x<n;x++){
        printf("%s\r\n",data[x]);
    }
}

void PopOutExistence(){
    char n[6];
    printf("����5��0-9����,���0-9��û�г��ֹ�������");
    scanf("%s",n);
    char std[] ="0123456789";
    for(int i=0;i<5;i++){
        char *p=strchr(std,n[i]);
        if(p!=NULL)
            std[p-std]='x';
    }
    printf("%s",std);
}
void Sort(){
    int n[6];
    printf("\r\n����5��0-9����(�ո����) Ȼ���С��������");
    scanf("%d %d %d %d %d",&n[0],&n[1],&n[2],&n[3],&n[4]);
    //ð����
    int c;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(n[j]>n[j+1]){
                c=n[j];
                n[j]=n[j+1];
                n[j+1]=c;
            }
        }
    }
    for(int i=0;i<5;i++)
        printf("%d ",n[i]);
}
/*     C3     */
int Plus(int data[],int length){
    int value=0;
    for(int i=0;i<length-1;i++)
        value+=data[i];
    return value;
}
//�׳�!
int Factorial(int n){
    int value=1;
    for(int i=1;i<n+1;i++)
        value*=i;
    return value;
}
//쳲���������
void Fibonacci(int a1,int a2,int length){
    int a=a1,b=a2,c;
    for(int i=0;i<length-1;i++){
        c=a1+a2;
        printf("%d  ",c);
        a1=a2;
        a2=c;
    }
}
//�Ƿ�Ϊֱ��������
int IsRT(int a,int b,int c){
    return pow(a,2)+pow(b,2)==pow(c,2)||
            pow(a,2)+pow(c,2)==pow(b,2)||
            pow(c,2)+pow(b,2)==pow(a,2);
}

float USDToRMB(float USD){
    return USD*7.34;//9��8�� UTC 21:00
}