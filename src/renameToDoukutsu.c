#include <stdio.h>
#include <Fileapi.h>
#include <dirent.h>

int main(){
	struct dirent *de;
	DIR *dr = opendir("dropImagesHere");
	char *curFile;
	char *ourCMD;
	int pnt=0;
	int startpnt=0;
	
	printf("\tWARNING\nMake sure your image files names start with a letter\nIf you are trying to re-process images that were already procesed by this program:\nRun first the \"Preparefiles.exe\" program\n\n");
	printf("Insert the start offset\nSet it to any other value than 0 if ya plan on adding multiple videos\n(For example, If you want 2 videos, and video 1 ends at frame 2500,\nYou should set the offset to 0 for the first video, and then 2501 for the second video)\n");
	if(scanf("%d",&startpnt)!=1){
		printf("Value provided was not a number\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}else if (startpnt<0||startpnt>9999){
		printf("Value provided was out of scope (Min 0,Max 9999)\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}
	while((de = readdir(dr))!=NULL){
		curFile = de->d_name;
		if(strstr(curFile,"png")){
		//printf("%s",curFile);
		if(pnt+startpnt<10){
			sprintf(ourCMD,"REN dropImagesHere\\%s 000%d.png",curFile,pnt+startpnt);
		}else if (pnt+startpnt<100){
			sprintf(ourCMD,"REN dropImagesHere\\%s 00%d.png",curFile,pnt)+startpnt;
		}
		else if (pnt+startpnt<1000){
			sprintf(ourCMD,"REN dropImagesHere\\%s 0%d.png",curFile,pnt+startpnt);
		}
		else{
			sprintf(ourCMD,"REN dropImagesHere\\%s %d.png",curFile,pnt+startpnt);
		}
		//printf("%s\n",ourCMD);
		system(ourCMD);
		printf("Found png Frame=%d\n",pnt+startpnt);
		pnt++;
		}else{
			printf("\tskipped %s \n",curFile);
		}
		if(pnt>4200){
			printf("\n\n\n!!!FATAL ERROR!!!\n\n\nThe program is looping, or your video surpasses 4200 frames,(It will not run)\nBe sure that your image files start with a letter character to prevent looping\nor trim down your video\nLikelly your video got scrambled,you will need to delete it and re-export your video from the start\n");
			system("pause>nul");
		return 1;
		}else if(pnt+startpnt>9999){
			printf("\n\n\n!!!FATAL ERROR!!!\n\n\nYour video has surpassed the 9999 frame pointer (Max value readable by the game)\nStart with a lower frame offset or trim down your video\n");
			
		}
		
	}
	closedir(dr);
	if(pnt<=0){
		printf("No files were found,make sure : \nThe folder is named \"dropImagesHere\"\nThe image files you copied in there are .png\nThe program was not run with admin privileges (It should not)\n");
	}
	printf("%d files Procesed, Press any key to quit",pnt);
	system("pause>nul");
	return 0;
}