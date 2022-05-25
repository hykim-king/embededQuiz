#include<stdio.h>

void fileCopy(char *src, char *des){
   FILE *source = fopen(src, "rb");

   FILE *destination = fopen(des, "wb");

   FILE *error = NULL;


   char buffer[1024];
   int readCount;


   if(NULL == source || NULL ==destination ){
       error = fopen("error.txt","wt");
       fputs("파일을 읽거나 생성할 수 없습ㄴ디ㅏ.\n",error);

        if(NULL != error){
            fclose(error);
        }

        return;

   }

    while(1){
       readCount = fread(buffer,sizeof(char),sizeof(buffer),source);
       if(readCount < sizeof(buffer)){
           fwrite(buffer,sizeof(char),readCount,destination);
           break;
       }else{
           fwrite(buffer,sizeof(char),sizeof(buffer),destination);
       }
    }

}

int main(void){
    fileCopy("EmbededfileCopy.c","EmbededfileCopy_new.c");
    return 0;
}


