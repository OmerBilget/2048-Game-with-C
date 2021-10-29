#include<stdio.h>
#include<time.h>
#include<math.h>
#include<conio.h>
int main(){
	srand(time(0));
	int a[4][4];
	int progress=0;
	int rand_num=2;
	int rand_numx,rand_numy;
	int check_place=0;
	int possible_moves=1000;
	char dir;
	int score=0;
	int tmp;
	int zero_check;
	int dir_check;
	int play_again;
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			a[i][j]=0;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// RANDOM PUT 2
	while(check_place<2){
		rand_numx=rand() % 4;
    	rand_numy=rand() % 4;
	    if(rand_numx>=0 && rand_numx<4 && rand_numy>=0 && rand_numy<4 && a[rand_numx][rand_numy]==0){
		    a[rand_numx][rand_numy]=rand_num;
		    check_place+=1;
    	}
	}
	check_place=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
		printf("\n");
		printf("\n");
	}
	printf("score :%d\n",score);
    printf("\n");
    printf("Made by OMER SINAN BILGET\n");
	printf("Have fun\n");
	printf("\n");
	///////////////////////////////////////////////////////////////////////////////////////////////////
	// STEP EVENT
	while(possible_moves>0){
		possible_moves=0;
		////////////////////////////////////////////////////////////////////////////////////////////////
		// SLIDE AND ADD
		printf("enter a direction\n");
		printf("a.left w.up s.down d.right\n");
		dir=getch();
		system("cls");
		////////////////////////////////////////////////////////////////////////////////////////////////
		// MOVE LEFT
		if(dir=='a'){
			for(i=0;i<4;i++){
				for(j=0;j<3;j++){
				    for(k=0;k<3-j;k++){
				    	if(a[i][k]==0){
				        	a[i][k]=a[i][k+1];
				    	    a[i][k+1]=0;
				    	}
					}
			    }
				for(k=0;k<4;k++){
					if(a[i][k+1]==a[i][k] && k+1<4){
						a[i][k]=2*a[i][k];
						score+=a[i][k];
						a[i][k+1]=0;
						k+=1;
					}
				}
			    	for(j=0;j<3;j++){
				    for(k=0;k<3-j;k++){
				    	if(a[i][k]==0){
				        	a[i][k]=a[i][k+1];
				    	    a[i][k+1]=0;
				    	}
					}
			    }
			}
		}
		///////////////////////////////////////////////////////////////////////
		// MOVE RIGHT
        if(dir=='d'){
			for(i=0;i<4;i++){
				for(j=3;j>0;j--){
				    for(k=3;k>3-j;k--){
				    	if(a[i][k]==0){
				        	a[i][k]=a[i][k-1];
				    	    a[i][k-1]=0;
				    	}
					}
			    }
				for(k=3;k>0;k--){
					if(a[i][k]==a[i][k-1] && k-1>=0){
						a[i][k]=2*a[i][k];
						score+=a[i][k];
						a[i][k-1]=0;
						k-=1;
					}
				}
			    for(j=3;j>0;j--){
				    for(k=3;k>3-j;k--){
				    	if(a[i][k]==0){
				        	a[i][k]=a[i][k-1];
				    	    a[i][k-1]=0;
				    	}
					}
			    }
			}
		}
		//////////////////////////////////////////////////////////////////////
		// MOVE UP
		if(dir=='w'){
			for(i=0;i<4;i++){
				for(j=0;j<3;j++){
				    for(k=0;k<3-j;k++){
				    	if(a[k][i]==0){
				        	a[k][i]=a[k+1][i];
				    	    a[k+1][i]=0;
				    	}
					}
			    }
				for(k=0;k<4;k++){
					if(a[k+1][i]==a[k][i] && k+1<4){
						a[k][i]=2*a[k][i];
						score+=a[k][i];
						a[k+1][i]=0;
						k+=1;
					}
				}
			    	for(j=0;j<3;j++){
				        for(k=0;k<3-j;k++){
				         	if(a[k][i]==0){
				            	a[k][i]=a[k+1][i];
				        	    a[k+1][i]=0;
				        	}
				    	}
			        }
		    	}
	    	}
		//////////////////////////////////////////////////////////////////////
		// MOVE DOWN
		if(dir=='s'){
			for(i=0;i<4;i++){
				for(j=3;j>0;j--){
				    for(k=3;k>3-j;k--){
				    	if(a[k][i]==0){
				        	a[k][i]=a[k-1][i];
				    	    a[k-1][i]=0;
				    	}
					}
			    }
				for(k=3;k>0;k--){
					if(a[k][i]==a[k-1][i] && k-1>=0){
						a[k][i]=2*a[k][i];
						score+=a[k][i];
						a[k-1][i]=0;
						k-=1;
					}
				}
			    for(j=3;j>0;j--){
				    for(k=3;k>3-j;k--){
				    	if(a[k][i]==0){
				        	a[k][i]=a[k-1][i];
				    	    a[k-1][i]=0;
				    	}
					}
			    }
			}
		}
		//////////////////////////////////////////////////////////////////////
		//ZERO CHECK
		zero_check=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(a[i][j]==0){
					zero_check=1;
				}
			}
		}
		//////////////////////////////////////////////////////////////////////
		// DIRECTION CHECK
		dir_check=0;
		if(dir=='a' || dir=='s' || dir=='w'|| dir=='d'){
			dir_check=1;
		}
		//////////////////////////////////////////////////////////////////////
		// RANDOM NUMBER
		while(check_place<1 && zero_check==1 && dir_check==1){
	    	rand_numx=rand() % 4;
         	rand_numy=rand() % 4;
         	rand_num=1 + rand() % (progress/80+1);
         	rand_num=pow(2,rand_num);
	        if(rand_numx>=0 && rand_numx<4 && rand_numy>=0 && rand_numy<4 && a[rand_numx][rand_numy]==0){
		        a[rand_numx][rand_numy]=rand_num;
		        check_place+=1;
         	}
    	}
    	check_place=0;
		//////////////////////////////////////////////////////////////////////
		// PRINT GAME
		for(i=0;i<4;i++){
	    	for(j=0;j<4;j++){
		    	printf("%d\t",a[i][j]);
	    	}
	    	printf("\n");
	    	printf("\n");
     		printf("\n");
    	}
    	printf("score :%d\n",score);
    	printf("\n");
    	//////////////////////////////////////////////////////////////////////
    	// CHECK POSSIBILITY
    	for(i=0;i<4;i++){
	    	for(j=0;j<4;j++){
	    		if(a[i][j]==a[i][j+1] && j+1<4){
	    			possible_moves+=1;
				}
				if(a[j][i]==a[j+1][i] && j+1<4){
					possible_moves+=1;
				}
				if(a[i][j]==0){
					possible_moves+=1;
				}
	        }
		}
		progress+=1;
    }
	///////////////////////////////////////////////////////////////////////////////////////////////////
	// STEP EVENT END
	printf("Do you want to play again\n");
	printf("1.yes      2.no\n");
	scanf("%d",&play_again);
	if(play_again==1){
		main();
	}else{
		return 0;
	}
}

