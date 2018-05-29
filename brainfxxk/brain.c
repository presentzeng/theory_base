#define  _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  
#include <stdlib.h>  
char s[30000]={0};  
char code[100000];  
int len = 0;  
int stack[100];  
int stack_len=0;  
int main(int argc,char**argv)  
{  
    char c;  
    int i=0,j,k,x=0;  
    FILE* f;  
    char* p=s+10000;  
     
    f=fopen(argv[1],"r");  
          
    //while(fread(&code[len],1,1,f)==1)  
    //{  
    //    printf("len %d code %s\n", len, code);	
    //    len++;  
    //}  
    fread(code,114,1,f);
    len = 114;
    //setbuf(stdout,NULL);  
    while(i<len) {  
        switch(code[i]) {  
            case '+':  
                (*p)++;  
                break;  
            case '-':  
                (*p)--;  
                break;  
            case '>':  
                p++;  
                break;  
            case '<':  
                p--;  
                break;  
            case '.':  
                putchar((int)(*p));  
                //printf("put:%hdn",*p);  
                break;  
            case ',':  
                *p=getchar();  
                break;  
            case '[':  
                if(*p) {  
                    stack[stack_len++]=i;  
                } else {  
                    for(k=i,j=0;k<len;k++) {  
                        code[k]=='['&&j++;  
                        code[k]==']'&&j--;  
                        if(j==0)break;  
                    }  
                    if(j==0)  
                        i=k;  
                    else {  
                        fprintf(stderr,"%s:%dn",__FILE__,__LINE__);  
                        return 3;  
                    }  
                }  
                break;  
            case ']':  
                i=stack[stack_len-- - 1]-1;  
                break;  
            default:  
                break;  
        }  
        i++;  
        //x++;  
        //printf("%d : i=%dn",x,i);  
    }  
    printf("\n");  
    system("pause");  
    return 0;  
}  
