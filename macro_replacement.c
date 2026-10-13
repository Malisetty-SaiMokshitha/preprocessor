#include <string.h>
#include <stdio.h>
#include "preprocessor.h"
int macro_replacement(char *file,char *output){
        char str[1000];
        FILE *fp,*op;
        int i,j,len,n;
        char def[50][50];
        char val[50][200];
        char temp[1000];
        char *p;
        int flag=0;
        int cnt=0;
        fp=fopen(file,"r");
        if(fp==NULL)
                return 0;
        op=fopen(output,"w");
        if(op==NULL)
        {
                fclose(fp);
                return 0;
        }
        while(fgets(str,1000,fp)!=NULL){
                if(strncmp(str,"#define",7)==0 && (str[7]==' ' || str[7]=='\t' || str[7]== '\n' || str[7] =='\r'))
                {
                        if(cnt<50 && sscanf(str,"#define %s %[^\n]",def[cnt],val[cnt])>=1)
                        {
                                cnt++;
                        }
                }
                else
                {
                        for(i=0;i<cnt;i++)
                        {
                                p=str;
                                while((p=strstr(p,def[i]))!=NULL)
                                {
                                        len=strlen(def[i]);
                                      if((p==str ||
                                !(((p[-1] >= 'A' && p[-1] <= 'Z')||(p[-1] >= 'a' && p[-1] <= 'z') ||(p[-1] >= '0' && p[-1] <= '9') ||p[-1] == '_')) &&
                                                           !((p[len] >= 'A' && p[len] <= 'Z') ||
                                   (p[len] >= 'a' && p[len] <= 'z') ||
                                   (p[len] >= '0' && p[len] <= '9') ||
                                                p[len] == '_')))
                                                {
                                                strcpy(temp,p+len);
                                                strcpy(p,val[i]);
                                                strcat(p,temp);
                                                p=p+strlen(val[i]);
                                        }
                                        else
                                        {
                                                p++;
                                        }
                                }
                        }
                        fputs(str,op);

                }
        }
        fclose(fp);
        fclose(op);
        return 1;
}
