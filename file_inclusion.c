#include <stdlib.h>
#include "preprocessor.h"
int file_inclusion(char *file,char *output){
        char temp[100];
        char str[1000];
        FILE *fp,*out,*inc;
        fp=fopen(file,"r");
        if(fp==NULL)
                return 0;
        out=fopen(output,"w");
        if(out==NULL){
                fclose(fp);
                return 0;
        }
        while(fgets(str,100,fp)!=NULL){
                if(strstr(str,"#include<stdio.h>")!=NULL)
                {
                        inc=fopen("/usr/include/stdio.h","r");
                        if(inc==NULL){
                                fclose(fp);
                                fclose(out);
                                return 0;
                        }
                        while(fgets(temp,100,inc)!=NULL)
                        {
                                fputs(temp,out);
                        }
                        fclose(inc);
                }
                else
                {
                        fputs(str,out);
                }
        }
        fclose(fp);
        fclose(out);
        return 1;
}
