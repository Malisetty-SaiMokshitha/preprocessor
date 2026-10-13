#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "preprocessor.h"
int main(int argc,char *argv[])
{
        char temp1[]="temp1.tmp";
        char temp2[]="temp2.tmp";
        char op[100];
        char str[100];
        char *ptr;
        FILE *fp,*out;
        if(argc<2){
                printf("invalid input\n");
                exit(0);
        }
        strcpy(op,argv[1]);
        ptr=strrchr(op,'.');
        if(ptr!=NULL)
                strcpy(ptr,".i");
        else
                strcat(op,".i");
        if(comment_removal(argv[1],temp1)==0)
                return 1;
        if(file_inclusion(temp1,temp2)==0)
                return 1;
        fp=fopen(temp2,"r");
        if(fp==NULL)
                return 1;
        out=fopen(op,"w");
        if(out==NULL)
        {
                fclose(fp);
                return 1;
        }
        while(fgets(str,sizeof(str),fp)!=NULL)
                fputs(str,out);
        fclose(fp);
        fclose(out);
        if(macro_replacement(temp2,op)==0)
                return 1;
        return 0;
}
        fclose(out);
