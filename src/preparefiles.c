#include <stdio.h>
#include <Fileapi.h>
#include <dirent.h>

int main(){
	struct dirent *de;
	DIR *dr = opendir("dropImagesHere");
	char *curFile;
	char *ourCMD;
	int keyBurner=0;
	int pnt=0;
	while((de = readdir(dr))!=NULL){
		curFile = de->d_name;
		if(strstr(curFile,"png")){
			if(strstr(curFile,"prepared_0000.png")){
				closedir(dr);
				printf("%d files Prepared to be processed, Press any key to quit",pnt);
				system("pause>nul");
			return 0;
		}
		//printf("%s",curFile);
		if(pnt<10){
			sprintf(ourCMD,"REN dropImagesHere\\%s prepared_000%d.png",curFile,pnt);
		}else if (pnt<100){
			sprintf(ourCMD,"REN dropImagesHere\\%s prepared_00%d.png",curFile,pnt);
		}
		else if (pnt<1000){
			sprintf(ourCMD,"REN dropImagesHere\\%s prepared_0%d.png",curFile,pnt);
		}
		else{
			sprintf(ourCMD,"REN dropImagesHere\\%s prepared_%d.png",curFile,pnt);
		}
		//printf("%s\n",ourCMD);
		system(ourCMD);
		printf("Found png Frame=%d\n",pnt);
		pnt++;
		}else{
			printf("\tskipped %s \n",curFile);
		}
		if(pnt>4200){
			printf("\n\n\n!!!FATAL ERROR!!!\n\n\nThe program is looping,You will need to delete it and re-export your video from the start\n");
			system("pause>nul");
		return 1;
		}

	}
	closedir(dr);
	if(pnt<=0){
		printf("No files were found,make sure : \nThe folder is named \"dropImagesHere\"\nThe image files you copied in there are .png\nThe program was not run with admin privileges (It should not)\n");
	}
	printf("%d files Preppared to be processed, Press any key to quit",pnt);
	system("pause>nul");
	return 0;
}