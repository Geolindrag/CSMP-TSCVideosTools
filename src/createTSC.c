#include <stdio.h>
#include <Fileapi.h>

int main(){
	int pnt=0;
	int delay=5;
	int frames=0;
	int fps=1;
	int startpnt=0;
	int extrafolder=0;
	printf("Which is the number of the first image\n(Dont add extra zeros)0000 = Incorrect / 0 = Correct\n");
	if(scanf("%d",&startpnt)!=1){
		printf("ERROR :Value provided was not a number\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}else if (startpnt<0||startpnt>9999){
		printf("ERROR :Value provided was out of scope (Min 0,Max 9999)\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}
	printf("Which is the last number of you last image ?\n(The higher one)\n(Dont add extra zeros)0900 = Incorrect / 900=Correct\n");
	if(scanf("%d",&frames)!=1){
		printf("ERROR :Value provided was not a number\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}else if(frames>9999||frames<=0){
		printf("ERROR :Value provided was out of scope (Min 1,Max 9999)\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}else if(startpnt>frames){
		printf("ERROR :First number provided is higher than the last number\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}
	
	if(startpnt!=0){
		frames=frames-startpnt;
	}
	
	/*
	10FPS = WAIT 5 and -1 every 40 frames
	15FPS = WAIT 3 ,-1 every even frame,and -1 every 3 frames (not counting if is even the number)
	12FPS = WAIT 4 and -1 every 40 frames
	*/
	system("cls");
	printf("Which is the framerate of the video?\n1 = 10FPS\n2 = 15FPS\n3 = 12FPS\n");
	if(scanf("%d",&fps)!=1){
		printf("ERROR :Value provided was not a number\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}
	
	switch (fps){
		case 1://10FPS
			delay=5;
			break;
		case 2://15FPS
			delay=3;
		break;
		case 3://12FPS 	//I dont know if is posible to have a higher framerate than 15, as it seems that going below 2 on a <WAI doesnt do anything
			delay=4;	//Maybe is a performance issue on my part, as my graphics device is an Intel HD Graphics Sandy brige 
		break;			//as CPU wise seems fine,not reaching 70%> usage on my end (Pentium G640/Dual core 2.6GHz)
		default:
		printf("ERROR :Value provided was invalid\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}
	system("cls");
	printf("Do you want to create a non-reduced video? \nYou should not use them unless you know what are you doing \naka: Recommended = No \n0 = No / 1 = Yes");
	if(scanf("%d",&extrafolder)!=1){
		printf("ERROR :Value provided was not a number\nPress any key to exit...");
		system("pause>nul");
		return 1;
	}else if (extrafolder!=0&&extrafolder!=1){
		printf("ERROR :Value provided was invalid\nAssuming response as \"No\"\nPress any key to continue, Or close the window to exit");
		system("pause>nul");
	}
	system("cls");
	if(extrafolder==1){
		printf("Write the folder ID it will go into (0-9999)");
		if(scanf("%d",&extrafolder)!=1){
			printf("ERROR :Value provided was not a number\nPress any key to exit...");
			system("pause>nul");
			return 1;
		}else if (extrafolder<0||extrafolder>9999){
			printf("ERROR :Value provided was out of scope (Min 0,Max 9999)\nPress any key to exit...");
			system("pause>nul");
			return 1;
		}
		while(pnt<=frames){
			if(extrafolder<10){
				printf("<IMF000%d:",extrafolder);
			}else if(extrafolder<100){
				printf("<IMF00%d:",extrafolder);
			}else if(extrafolder<1000){
				printf("<IMF0%d:",extrafolder);
			}else{
				printf("<IMF%d:",extrafolder);
			}
			if(pnt+startpnt<10){
				if((pnt%40==0&&fps==1)||(pnt%2==0&&fps==2)||(pnt%3==0&&fps==2)||(pnt%40==0&&fps==3)){
					printf("000%d<WAI000%d",startpnt+pnt,delay-1);
				}else{
				printf("000%d<WAI000%d",startpnt+pnt,delay);
				}
			}else if (pnt+startpnt<100){
				if((pnt%40==0&&fps==1)||(pnt%2==0&&fps==2)||(pnt%3==0&&fps==2)||(pnt%40==0&&fps==3)){
					printf("00%d<WAI000%d",startpnt+pnt,delay-1);
				}else{
				printf("00%d<WAI000%d",startpnt+pnt,delay);
				}
			}
			else if (pnt+startpnt<1000){
				if((pnt%40==0&&fps==1)||(pnt%2==0&&fps==2)||(pnt%3==0&&fps==2)||(pnt%40==0&&fps==3)){
					printf("0%d<WAI000%d",startpnt+pnt,delay-1);
				}else{
				printf("0%d<WAI000%d",startpnt+pnt,delay);
				}
			}
			else{
				if((pnt%40==0&&fps==1)||(pnt%2==0&&fps==2)||(pnt%3==0&&fps==2)||(pnt%40==0&&fps==3)){
					printf("%d<WAI000%d",startpnt+pnt,delay-1);
				}else{
				printf("%d<WAI000%d",startpnt+pnt,delay);
				}
			}
			pnt=pnt+1;
		
		}
		printf("<IMC");
		if(pnt>2928){
			printf("\n\t\t\t!!!WARNING!!!\n Your script surpasses the Hard limit by %d frames, It will 99%% CRASH YOUR GAME\nReduce the framerate, or trim down your video",pnt-2928);
		}else if (pnt>2600){
			printf("\n\t\t\t!!CAUTION!!\nYour script surpasses the safe limit by %d frames,This leaves you with roughtly %.1fKB for map scripting\n(Assuming your head.tsc is the deafult or 2KB)\nYour game might crash at this point!\n",pnt-2600,((float)(2928-pnt)/48));
		}else if (pnt>2200){
			printf("\n\t\t\tCAUTION\nYour script is getting close to the safe limit\nThis leaves you with roughtly %.1fKB for map scripting\n(Assuming your head.tsc is the deafult or 2KB)",((float)(2928-pnt)/48));
		}
		
		if (startpnt+pnt>9999){
				printf("\n\t\t\t!!!WARNING!!!\n Your script is out of scope by %d frames\nit will not be recognized by the game!\nReduce the framerate,trim down your video,or allocate it as a normal type video",startpnt+pnt-9999);
		}
		
		printf("\n\nCopy the text from above\n1- Click on the end of the text\n2- Scroll to the start with the scrollbar so it's faster\n3- While holding mayus, click the start of the text\n4- After that,just CTRL+C\n\nPress any key to exit");
		system("pause>nul");
		return 0;	
	}
	
	
	while(pnt<=frames){
		if(pnt+startpnt<10){
			if((pnt%40==0&&fps==1)||(pnt%2==0&&fps==2)||(pnt%3==0&&fps==2)||(pnt%40==0&&fps==3)){
				printf("<IMG000%d<WAI000%d",startpnt+pnt,delay-1);
			}else{
			printf("<IMG000%d<WAI000%d",startpnt+pnt,delay);
			}
		}else if (pnt+startpnt<100){
			if((pnt%40==0&&fps==1)||(pnt%2==0&&fps==2)||(pnt%3==0&&fps==2)||(pnt%40==0&&fps==3)){
				printf("<IMG00%d<WAI000%d",startpnt+pnt,delay-1);
			}else{
			printf("<IMG00%d<WAI000%d",startpnt+pnt,delay);
			}
		}
		else if (pnt+startpnt<1000){
			if((pnt%40==0&&fps==1)||(pnt%2==0&&fps==2)||(pnt%3==0&&fps==2)||(pnt%40==0&&fps==3)){
				printf("<IMG0%d<WAI000%d",startpnt+pnt,delay-1);
			}else{
			printf("<IMG0%d<WAI000%d",startpnt+pnt,delay);
			}
		}
		else{
			if((pnt%40==0&&fps==1)||(pnt%2==0&&fps==2)||(pnt%3==0&&fps==2)||(pnt%40==0&&fps==3)){
				printf("<IMG%d<WAI000%d",startpnt+pnt,delay-1);
			}else{
			printf("<IMG%d<WAI000%d",startpnt+pnt,delay);
			}
		}
		pnt=pnt+1;
		
	}
	printf("<IMC");
	if(pnt>3932){
		printf("\n\t\t\t!!!WARNING!!!\n Your script surpasses the Hard limit by %d frames, It will 99%% CRASH YOUR GAME\nReduce the framerate, or trim down your video",pnt-3932);
	}else if (pnt>3500){
		printf("\n\t\t\t!!CAUTION!!\nYour script surpasses the safe limit by %d frames,This leaves you with roughtly %.1fKB for map scripting\n(Assuming your head.tsc is the deafult or 2KB)\nYour game might crash at this point!\n",pnt-3500,((float)(3964-pnt)/64));
	}else if (pnt>3000){
		printf("\n\t\t\tCAUTION\nYour script is getting close to the safe limit\nThis leaves you with roughtly %.1fKB for map scripting\n(Assuming your head.tsc is the deafult or 2KB)",((float)(3964-pnt)/64));
	}
	
	if (startpnt+pnt>9999){
			printf("\n\t\t\t!!!WARNING!!!\n Your script is out of scope by %d frames\nit will not be recognized by the game!\nReduce the framerate,trim down your video,or allocate it as a normal type video",startpnt+pnt-9999);
	}
	
	printf("\n\nCopy the text from above\n1- Click on the end of the text\n2- Scroll to the start with the scrollbar so it's faster\n3- While holding mayus, click the start of the text\n4- After that,just CTRL+C\n\nPress any key to exit");
	system("pause>nul");
	return 0;
}