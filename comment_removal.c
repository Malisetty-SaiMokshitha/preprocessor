#include <string.h>
#include<stdio.h>
#include "preprocessor.h"
int comment_removal(char *file,char *output){
        char str[100];
        FILE *fp,*out;
        int i;
        int flag=0;
        fp=fopen(file,"r");
        if(fp==NULL)
                return 0;
        out=fopen(output,"w");
        if(out==NULL)
        {
                fclose(fp);
                return 0;
        }
while(fgets(str,100,fp)!=NULL){
                for(i=0;str[i]!='\0';i++){
                        if(flag==0){
                        if(str[i]=='/'&&str[i+1]=='/')
                          {
                                while(str[i]!='\0'&&str[i]!='\n'){
                                        str[i]=' ';
                                        i++;
                                }
                          }
                        else if(str[i]=='/'&&str[i+1]=='*')
                        {
                                str[i]=' ';
                                str[i+1]=' ';
                                flag=1;
                                i++;
                        }
                        }
                        else
                        {
                                if(str[i]=='*' && str[i+1]=='/'){
                                     str[i]=' ';
                                        str[i+1]=' ';
                                        flag=0;
                                        i++;
                                }
                                else if(str[i]!='\n'){
                                        str[i]=' ';
                                }
                        }
                }
                fputs(str,out);
        }
        fclose(fp);
        fclose(out);
        return 1;
}
