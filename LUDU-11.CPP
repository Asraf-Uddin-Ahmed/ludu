#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<io.h>





	/*declare initial board*/
	int ib[15][15]={
			-1,-1,-1,-1,-1,-1,   0, 0, 0  ,-1,-1,-1,-1,-1,-1,
			-1, 0, 0, 0, 0,-1,   0, 0, 0  ,-1, 0, 0, 0, 0,-1,
			-1, 0, 0, 0, 0,-1,   0, 0, 0  ,-1, 0, 0, 0, 0,-1,
			-1, 0, 0, 0, 0,-1,   0, 0, 0  ,-1, 0, 0, 0, 0,-1,
			-1, 0, 0, 0, 0,-1,   0, 0, 0  ,-1, 0, 0, 0, 0,-1,
			-1,-1,-1,-1,-1,-1,   0, 0, 0  ,-1,-1,-1,-1,-1,-1,

			 0, 0, 0, 0, 0, 0,  -1,-1,-1  , 0, 0, 0, 0, 0, 0,
			 0, 0, 0, 0, 0, 0,  -1, 0,-1  , 0, 0, 0, 0, 0, 0,
			 0, 0, 0, 0, 0, 0,  -1,-1,-1  , 0, 0, 0, 0, 0, 0,

			-1,-1,-1,-1,-1,-1,   0, 0, 0  ,-1,-1,-1,-1,-1,-1,
			-1, 0, 0, 0, 0,-1,   0, 0, 0  ,-1, 0, 0, 0, 0,-1,
			-1, 0, 0, 0, 0,-1,   0, 0, 0  ,-1, 0, 0, 0, 0,-1,
			-1, 0, 0, 0, 0,-1,   0, 0, 0  ,-1, 0, 0, 0, 0,-1,
			-1, 0, 0, 0, 0,-1,   0, 0, 0  ,-1, 0, 0, 0, 0,-1,
			-1,-1,-1,-1,-1,-1,   0, 0, 0  ,-1,-1,-1,-1,-1,-1
		       };


	unsigned int ga[10000],gi=0;	//global array & global increment for storing mouse cursor point

	unsigned int br[5],bl[5],g[5],r[5];	//array of dice in outer board

	int cb[15][15];  /*change board*/

	int pb[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},p=1; /*passed board*/

	int count=1;  /*player count*/

	int v=0,v1=0,v2=0,v3=0,t=0;  /*dice value*/

	int cur=0;  /*cursor value of matrix*/

	int pv1_0=0,pv1_1=0,pv2_0=0,pv2_1=0,pv12_0=0,pv12_1=0,pv23_0=0,pv23_1=0,pv123_0=0,pv123_1=0; /*probable moving value*/

	int sv=1;  /*search value for turning dice has in baord(sv=1) or not(sv=0)*/

	int sr_2=0,sr_3=0,sr_4=0;  /*searching value of blue,red,green that all of has in board(sr_ =1) or not(sr_ =0).stop releasing dice if has not at outter board.*/

	int ypass=0,bpass=0,rpass=0,gpass=0;	/*check passed board dices*/

	int prev_count=0;	/*previous value of count,specially for PC*/

	int win1=0,win2=0,win3=0;	/*determine winner serially*/

	int b_passed=0,r_passed=0,g_passed=0,y_passed;	/*store values of y,b,r,gpass to help process them*/

	int SOUND=1,move_sound=0;	/*sound produce or not.if SOUND=0 not produce.if move_sound=1 then produce.*/

	int CHEAT=0;

	int PLAYER_NUMBER=2;

	int DICECOLOR_1=6,LINECOLOR_1=14,DICECOLOR_2=1,LINECOLOR_2=9,DICECOLOR_3=4,LINECOLOR_3=12,DICECOLOR_4=2,LINECOLOR_4=10;  /*coloring board & dice for user choice*/



/*yellow path*/
	int yp[57][2]= { 13,6,  12,6,  11,6,  10,6,  9,6,
			 8,5,   8,4,   8,3,   8,2,   8,1,   8,0,
			 7,0,
			 6,0,   6,1,   6,2,   6,3,   6,4,   6,5,
			 5,6,   4,6,   3,6,   2,6,   1,6,   0,6,
			 0,7,
			 0,8,   1,8,   2,8,   3,8,   4,8,   5,8,
			 6,9,   6,10,  6,11,  6,12,  6,13,  6,14,
			 7,14,
			 8,14,  8,13,  8,12,  8,11,  8,10,  8,9,
			 9,8,   10,8,  11,8,  12,8,  13,8,  14,8,
			 14,7,  13,7,  12,7,  11,7,  10,7,  9,7,
			 7,7 };
/*blue path*/
	int bp[57][2]= { 8,13,  8,12,  8,11,  8,10,  8,9,
			 9,8,   10,8,  11,8,  12,8,  13,8,  14,8,
			 14,7,
			 14,6,  13,6,  12,6,  11,6,  10,6,  9,6,
			 8,5,   8,4,   8,3,   8,2,   8,1,   8,0,
			 7,0,
			 6,0,   6,1,   6,2,   6,3,   6,4,   6,5,
			 5,6,   4,6,   3,6,   2,6,   1,6,   0,6,
			 0,7,
			 0,8,   1,8,   2,8,   3,8,   4,8,   5,8,
			 6,9,   6,10,  6,11,  6,12,  6,13,  6,14,
			 7,14,  7,13,  7,12,  7,11,  7,10,  7,9,
			 7,7 };
/*red path*/
	int rp[57][2]= { 1,8,   2,8,   3,8,   4,8,   5,8,
			 6,9,   6,10,  6,11,  6,12,  6,13,  6,14,
			 7,14,
			 8,14,  8,13,  8,12,  8,11,  8,10,  8,9,
			 9,8,   10,8,  11,8,  12,8,  13,8,  14,8,
			 14,7,
			 14,6,  13,6,  12,6,  11,6,  10,6,  9,6,
			 8,5,   8,4,   8,3,   8,2,   8,1,   8,0,
			 7,0,
			 6,0,   6,1,   6,2,   6,3,   6,4,   6,5,
			 5,6,   4,6,   3,6,   2,6,   1,6,   0,6,
			 0,7,   1,7,   2,7,   3,7,   4,7,   5,7,
			 7,7 };
/*green path*/
	int gp[57][2]= { 6,1,   6,2,   6,3,   6,4,   6,5,
			 5,6,   4,6,   3,6,   2,6,   1,6,   0,6,
			 0,7,
			 0,8,   1,8,   2,8,   3,8,   4,8,   5,8,
			 6,9,   6,10,  6,11,  6,12,  6,13,  6,14,
			 7,14,
			 8,14,  8,13,  8,12,  8,11,  8,10,  8,9,
			 9,8,   10,8,  11,8,  12,8,  13,8,  14,8,
			 14,7,
			 14,6,  13,6,  12,6,  11,6,  10,6,  9,6,
			 8,5,   8,4,   8,3,   8,2,   8,1,   8,0,
			 7,0,   7,1,   7,2,   7,3,   7,4,   7,5,
			 7,7 };


board_ludu();	/*this function prototype defines this function to help calling function which before it*/
int click_sound();


#include"RGB1.cpp"
#include"messages.cpp"
#include"ludunam2.cpp"
#include"saveload.cpp"
#include"mouse1.cpp"
#include"6-dice.cpp"
#include"board-3.cpp"




/*
produce click sound
*/
int click_sound(void)
{
	if(SOUND==1)
	{
		sound(1000);
		delay(150);
		nosound();
	}
 return 0;
}

/*
produce dice move and relesed sound
*/
int dice_move_sound(void)
{
	if(SOUND==1)
	{
		sound(1000);
		delay(100);
		sound(3000);
		delay(150);
		nosound();
	}
 return 0;
}




/******************************** search_passed *******************************************/

/*
search passed board
determine winner
create restriction to play winner
*/
int search_passed(void)
{
char w1[20];

	win1=0;
	win2=0;
	win3=0;
	ypass=0;
	bpass=0;
	rpass=0;
	gpass=0;

	for(int i=0;i<15;i++)
	{
		if(pb[i]/10==1) ypass++;
		else if(pb[i]/10==2) bpass++;
		else if(pb[i]/10==3) rpass++;
		else if(pb[i]/10==4) gpass++;

		//give value to passed board
		/*
		if(i==5)bpass=4;
		if(i==10)rpass=4;
		if(i==14)gpass=4;
		*/

		/*winner*/
		if( (ypass==4||bpass==4||rpass==4||gpass==4) && (win1==0) )
		{
			setcolor(0);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			sprintf(w1,"WINNER");

			/*user winner*/
			if(ypass==4)
			{
				win1=1;
				settextstyle(1,0,1);
				outtextxy(getmaxx()/2,getmaxy()/2,"CONGRATULATION !!");
				y_passed=ypass;
				ypass=0;
				getch();
				exit(1);
			}

			/*PC winner*/
			else if(bpass==4)
			{
				win1=1;
				settextstyle(1,1,1);
				outtextxy(420,375,w1);
				b_passed=bpass;
				bpass=0;
			}
			else if(rpass==4)
			{
				win1=1;
				settextstyle(1,0,1);
				outtextxy(375,60,w1);
				r_passed=rpass;
				rpass=0;
			}
			else if(gpass==4)
			{
				win1=1;
				settextstyle(1,1,1);
				outtextxy(60,105,w1);
				g_passed=gpass;
				gpass=0;
			}
		}

		/*2nd position*/
		if( (ypass==4||bpass==4||rpass==4||gpass==4) && (win1==1&&win2==0) )
		{
			setcolor(0);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			sprintf(w1,"1st Runner up");

			/*user 2nd*/
			if(ypass==4)
			{
				win2=2;
				settextstyle(1,0,1);
				outtextxy(getmaxx()/2,getmaxy()/2,"You got 2nd position !!");
				y_passed=ypass;
				ypass=0;
				getch();
				exit(1);
			}

			/*PC 2nd*/
			else if(bpass==4)
			{
				win2=2;
				settextstyle(4,1,1);
				outtextxy(420,375,w1);
				b_passed=bpass;
				bpass=0;
			}
			else if(rpass==4)
			{
				win2=2;
				settextstyle(4,0,1);
				outtextxy(375,60,w1);
				r_passed=rpass;
				rpass=0;
			}
			else if(gpass==4)
			{
				win2=2;
				settextstyle(4,1,1);
				outtextxy(60,105,w1);
				g_passed=gpass;
				gpass=0;
			}
		}

		/*3rd position & looser*/
		if( (ypass==4||bpass==4||rpass==4||gpass==4) && (win2==2&&win3==0) )
		{
			setcolor(0);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			sprintf(w1,"2nd Runner up");

			/*user 3rd*/
			if(ypass==4)
			{
				settextstyle(1,0,1);
				outtextxy(getmaxx()/2,getmaxy()/2,"You got 3rd position !!");
				y_passed=ypass;
				ypass=0;
				getch();
				exit(1);
			}

			/*PC 3rd & user looser*/
			else
			{
				settextstyle(1,0,1);
				outtextxy(getmaxx()/2,getmaxy()/2,"You Lose !!");
				y_passed=ypass;
				ypass=0;
				getch();
				exit(1);
			}

		}


	}

return 0;
}



/********************************** dice_6 ********************************************************/

/*
show dynamic 6-dice & give its values
*/
int dice_6(void)
{
  int lb=0; 	/*declare loop breaker*/
  //time_t tm; 	/*declare time_t type veriable*/

	for(int i=1; lb<=2000 ;i++)
	{
	//produce sound for running
		if(SOUND==1)
			sound(40);

		setcolor(8);
		settextstyle(0,0,1);
		settextjustify(LEFT_TEXT,TOP_TEXT);
		if(i==1)      one();
		else if(i==2) two();
		else if(i==3) three();
		else if(i==4) four();
		else if(i==5) five();
		else if(i==6) six();

		else i=0;
		lb++;
	}

	nosound();

	//	mouse("pos");
	//	if(((button&1)==1)&&x>=250&&x<=284&&y>=255&&y<=284)

/*initializes a new random number generator*/
	//srand((unsigned) time(&tm));
	randomize();

/*put a random value into i*/
	//for( i=1;i!=rand()%7;i++);
	i=rand()%6+1;

/*CHEAT VALUE OF SIXER*/
	if(CHEAT>=1&&CHEAT<=6) i=CHEAT;
	CHEAT=0;

/*assign value for PC turn*/
	 prev_count=count;

/*print the inputed value or the value of 6-dice player got*/
	if(i==1)      one();
	else if(i==2) two();
	else if(i==3) three();
	else if(i==4) four();
	else if(i==5) five();
	else
	{
		six();
		i=6;
	}
/*if the value of i is less than 6,then turn to next player*/
	if(i<6) count++;
/*turn give to next if ones all dices are passed*/
	if(count==1&&y_passed==4) count=2;
	if(count==2&&b_passed==4) count=3;
	if(count==3&&r_passed==4) count=4;
	if(count==4&&g_passed==4) count=1;

t+=i;
if(t==18) t=0;

return i;
}




/********************************** turn_msg() ***********************************************************/

/*
show turn on player message
*/
int turn_msg(int pn)   /*pn=show exact player no*/
{ int i;
	char turn[20];
	setfillstyle(1,8);
	bar(197,197,283,223);
	setcolor(3);

	if(PLAYER_NUMBER==4 && count>=5 || count<=0) count=1;
	else if(PLAYER_NUMBER==3 && count>=4 || count<=0) count=1;

	else if(PLAYER_NUMBER==2 && count>=4 || count<=0) count=1;
	else if(PLAYER_NUMBER==2 && count>=2 || count<=0) count=3;  //for playing diagonally

	 if(pn==0)	//now the player turn
	 {
		if(count==1)	sprintf(turn,name);
		else	sprintf(turn,"player %d",count);
	 }
	 else	//player turn is not end.because he doesn't finish his dice moving.
	 {
		if(prev_count==1)	sprintf(turn,name);
		else	sprintf(turn,"player %d",prev_count);
	 }
	 //printf("%d ",count);

	  outtextxy(240,210,turn);

return 0;
}




/******************************** print_passed() *************************************************/

/*
print the passed dices
called by dynamic board
*/
print_passed(int p)	 //p use for check pb[20] array
{
	int j=0,i=0,k=0;
/*determining exact position of passed dices*/
	if(p<=5)
	{
		j=220;
		i=465+(p*30);
	}

	else if(p<=10)
	{
		k=p-5;
		j=250;
		i=465+(k*30);
	}

	else if(p<=15)
	{
		k=p-10;
		j=280;
		i=465+(k*30);
	}

/*check pb & print*/
	if(pb[p]/10==1)      yellow(i,j);
	else if(pb[p]/10==2) blue(i,j);
	else if(pb[p]/10==3) red(i,j);
	else if(pb[p]/10==4) green(i,j);

 return 0;
}




/*********************************** print_out() ********************************************************/

/*
print the outer dices from board
their position are determined in outer board
*/
int print_out(int i)
{
  int j,k=120,a,b,c;

/*put into array in search_out element*/
		for(a=11,b=615,c=1; a<=44 ;a++,b=b-30,c++)
		{
			if(i==a)
			{
				if(a/10==1)br[c]=i;
				else if(a/10==2)bl[c]=i;
				else if(a/10==3)r[c]=i;
				else if(a/10==4)g[c]=i;
				j=b;
				break;
			}

			if(a==14||a==24||a==34)
			{
				if(a==14||a==34) k=k+60;
				else if(a==24) k=k+150;
				a=a+6;
				c=0;
				b=645;
				//printf("%d %d\t",j,k);
			}
		}

/*print an element on its determined place*/
		if(i==11||i==12||i==13||i==14)       yellow(j,k);
		else if(i==21||i==22||i==23||i==24)  blue(j,k);
		else if(i==31||i==32||i==33||i==34)  red(j,k);
		else if(i==41||i==42||i==43||i==44)  green(j,k);

return 0;
}




/******************************* search_out() **************************************************************/

/*
determine which dices are not in board & passed board
calling print_out() for print outer dices
*/
int search_out(void)
{
 int c[50],i=0;

//assigning value to array which value aren't in board
 c[11]=0;c[12]=0;c[13]=0;c[14]=0;
 c[21]=0;c[22]=0;c[23]=0;c[24]=0;
 c[31]=0;c[32]=0;c[33]=0;c[34]=0;
 c[41]=0;c[42]=0;c[43]=0;c[44]=0;
 sr_2=0,sr_3=0,sr_4=0;

	for(int j=0;j<15;j++)
	{
		for(int k=0;k<15;k++)
		{
			if(cb[j][k]==0||cb[j][k]==-1);

			else if(cb[j][k]==11)  c[11]=1;
			else if(cb[j][k]==12)  c[12]=1;
			else if(cb[j][k]==13)  c[13]=1;
			else if(cb[j][k]==14)  c[14]=1;

			else if(cb[j][k]==21)  c[21]=1;
			else if(cb[j][k]==22)  c[22]=1;
			else if(cb[j][k]==23)  c[23]=1;
			else if(cb[j][k]==24)  c[24]=1;

			else if(cb[j][k]==31)  c[31]=1;
			else if(cb[j][k]==32)  c[32]=1;
			else if(cb[j][k]==33)  c[33]=1;
			else if(cb[j][k]==34)  c[34]=1;

			else if(cb[j][k]==41)  c[41]=1;
			else if(cb[j][k]==42)  c[42]=1;
			else if(cb[j][k]==43)  c[43]=1;
			else if(cb[j][k]==44)  c[44]=1;
		}
	}

	for(i=1;i<=15;i++)
	{
		if(pb[i]==0);

		else if(pb[i]==11) c[11]=1;
		else if(pb[i]==12) c[12]=1;
		else if(pb[i]==13) c[13]=1;
		else if(pb[i]==14) c[14]=1;

		else if(pb[i]==21) c[21]=1;
		else if(pb[i]==22) c[22]=1;
		else if(pb[i]==23) c[23]=1;
		else if(pb[i]==24) c[24]=1;

		else if(pb[i]==31) c[31]=1;
		else if(pb[i]==32) c[32]=1;
		else if(pb[i]==33) c[33]=1;
		else if(pb[i]==34) c[34]=1;

		else if(pb[i]==41) c[41]=1;
		else if(pb[i]==42) c[42]=1;
		else if(pb[i]==43) c[43]=1;
		else if(pb[i]==44) c[44]=1;
	}

	for(i=11;i<=44;i++)
	{
		if(c[i]!=1)  print_out(i);
		if(i==14||i==24||i==34) i=i+6;
	}

/*search value.if there no dice in board value is 0*/
sv=1;
i=count*10; //printf("   %d   ",count);
if(c[i+1]==0&&c[i+2]==0&&c[i+3]==0&&c[i+4]==0) sv=0;

/*stop releasing after released 4 dices for PC*/
if(c[21]==1&&c[22]==1&&c[23]==1&&c[24]==1) sr_2=4;
if(c[31]==1&&c[32]==1&&c[33]==1&&c[34]==1) sr_3=4;
if(c[41]==1&&c[42]==1&&c[43]==1&&c[44]==1) sr_4=4;

//printf(" %d ",count);

return 0;
}



/********************************* DEFAULT BOARD******************************************************/

/*
show default board
initial the values of cb[15][15]
*/
int default_board(void)
{
	board();
	turn_msg(0);

	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			cb[i][j]=ib[i][j];

	for(i=0;i<=20;i++)
		pb[i]=0;

	search_out();

 return 0;
}



/******************************* show_val_move ************************************************/

/*
show the valid move
called by dice_run()
*/
int show_val_move(int r,int c,int v1,int v2,int v3)
{ int i=0;

/*select valid clicking position has  &  cur=cursor point*/

/*assign probable value to go for yellow*/
	if(cb[r][c]/10==1)
	{
/*select the main position of star box*/
		if(r>=10&&r<=13&&c>=1&&c<=4) 		cur=0;
		else if(r>=1&&r<=4&&c>=1&&c<=4)		cur=13;
		else if(r>=1&&r<=4&&c>=10&&c<=13)	cur=26;
		else if(r>=10&&r<=13&&c>=10&&c<=13)	cur=39;

/*select the main position*/
	   for(i=0;i<57;i++)
		if(yp[i][0]==r&&yp[i][1]==c)  cur=i;

/*put probable move value*/
		pv1_0=yp[cur+v1][0];
		pv1_1=yp[cur+v1][1];

		pv12_0=yp[cur+v1+v2][0];
		pv12_1=yp[cur+v1+v2][1];

		pv2_0=yp[cur+v2][0];
		pv2_1=yp[cur+v2][1];

		pv23_0=yp[cur+v3+v2][0];
		pv23_1=yp[cur+v3+v2][1];

		pv123_0=yp[cur+v3+v2+v1][0];
		pv123_1=yp[cur+v3+v2+v1][1];
       }

/*print probable moving point*/
if(cb[r][c]/10==1)
{
       mouse("hide");
       setcolor(3);
       if(cur+v3+v2+v1<57) circle((pv123_1+1)*30,(pv123_0+1)*30,13);
       if(cur+v3+v2<57) circle((pv23_1+1)*30,(pv23_0+1)*30,13);
       if(cur+v2<57) circle((pv2_1+1)*30,(pv2_0+1)*30,13);
       if(cur+v2+v1<57) circle((pv12_1+1)*30,(pv12_0+1)*30,13);
       if(cur+v1<57) circle((pv1_1+1)*30,(pv1_0+1)*30,13);
}

return 0;
}





/********************************* dynamic board ***********************************************************/

/*
show the changing position of dice
dice can't overlap same kind of dice
dice can overlap different dice
dices can't go forbidden area
dice can auto move from star
print passed board dices
print main board dices
*/
int dynamic_board(void)
{ int i;
	mouse("hide");
	board();
	if(v1==0) turn_msg(0);     //show new player no. when previous player turn is end
	else if(v1>0) turn_msg(1); //show player no. when player turn is not end

/*auto move from main board to passed board*/
	if(cb[7][7]>0)
	{
		pb[p]=cb[7][7];
		cb[7][7]=0;
		p++;
	}
/*auto move from star*/
	else if(cb[13][6]>0)
	{
		for(int i=12;i>=10;i--)
			for(int j=4;j>=1;j--)
				if(cb[i][j]==0)
				{
					cb[i][j]=cb[13][6];
					cb[13][6]=0;
					break;
				}
	}
	else if(cb[6][1]>0)
	{
		for(int i=2;i<=4;i++)
			for(int j=4;j>=1;j--)
				if(cb[j][i]==0)
				{
					cb[j][i]=cb[6][1];
					cb[6][1]=0;
					break;
				}
	}
	else if(cb[1][8]>0)
	{
		for(int i=2;i<=4;i++)
			for(int j=10;j<=13;j++)
				if(cb[i][j]==0)
				{
					cb[i][j]=cb[1][8];
					cb[1][8]=0;
					break;
				}
	}
	else if(cb[8][13]>0)
	{
		for(int i=12;i>=10;i--)
			for(int j=10;j<=13;j++)
				if(cb[j][i]==0)
				{
					cb[j][i]=cb[8][13];
					cb[8][13]=0;
					break;
				}
	}
//pb[1]=11;pb[2]=21;pb[3]=22;   //for checking pb
/*print passed dices*/
	for(int k=1;k<=16;k++)
		print_passed(k);

/*print main board's dices*/
	if(move_sound==1)
	{
		sound(3000);
		delay(150);
		move_sound=0;
	}
	for( i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(cb[i][j]/10==4)
			{
				green((j+1)*30,(i+1)*30);
			}
			else if(cb[i][j]/10==3)
			{
				red((j+1)*30,(i+1)*30);
			}
			else if(cb[i][j]/10==1)
			{
				yellow((j+1)*30,(i+1)*30);
			}
			else if(cb[i][j]/10==2)
			{
				blue((j+1)*30,(i+1)*30);
			}
		}
	}
	search_out();
	search_passed();

	nosound();
	mouse("show");
return 0;
}





/******************************* full_dice_6  **************************************************************/

/*
calling dice_6
run 6-dice
differ the values
*/
int full_dice_6(void)
{
	mouse("hide");
	v=dice_6();
		//printf("%d ",count);
		v1=0;
		v2=0;
		v3=0;
		if(v<6)
		{
			if(t<6)
			{
				v1=t;
				//printf("%d ",v1);
				t=0;
			}
			else if(t<12)
			{
				v2=6;
				v1=t-v2;
				//printf("%d+%d=%d ",v2,v1,t);
				t=0;
			}
			else if(t<18)
			{
				v3=6;
				v2=6;
				v1=t-2*v2;
				//printf("%d+%d+%d=%d ",v3,v2,v1,t);
				t=0;
			}
			v=0;
		}
return 0;
}


/*********************************** MOUSE *******************************************/



int dice_run(void)
{ int i=0,j=0;

mouse("show");

 while(1)
 {

	mouse("pos");

/*
6-dice
put 6-dice value in different veriables
*/
	if(((button&1)==1)&&x>=205&&x<=275&&y>=257&&y<=283 && v1==0)
	{
		mouse("hide");
		short_dice();
		delay(150);

		full_dice_6();
		mouse("show");
/*without any existance of a dice on the board v1 is valueless*/
			if(sv==0&&v2==0) v1=0;
			//printf("%d %d ",sv,v2);
			// printf("%d ",count);
	 delay(1000);
	 break;
	}



	/******************* PC auto run 6-dice ****************************************/

/*auto run 6-dice for PC-p2,p3,p4*/
       else if( (count==2||count==3||count==4) && v1==0)
       {
		do
		{
			full_dice_6();
			delay(1000);
		}
		while(v==6);

/*without any existance of a dice on the board v1 is valueless*/
			if(sv==0&&v2==0) v1=0;

/*use for test*/ //v1=0;
		break;
       }



/*assigning value at cb[15][15] array*/

/*USER-auto move for v1*/
	else if( ((button&2)==2) && v1>0 && v2==0)
	{    	      /*1st>0*/		       /*2nd>=0 && 2nd<=44*/                  	    /*forbid to same color overlap*/
		if(  (cb[ga[gi]][ga[gi-1]]/10==1&&cb[pv1_0][pv1_1]>=0&&cb[pv1_0][pv1_1]<=44) && (cb[ga[gi]][ga[gi-1]]/10!=cb[pv1_0][pv1_1]/10) )
				      /*play when only player turn*/
			//if(  (count-1==cb[ga[gi]][ga[gi-1]]/10||count==cb[ga[gi]][ga[gi-1]]/40) )
				   /*forbid the exceed move than passed*/
				if(cur+v1<57)
				{
					cb[pv1_0][pv1_1]=cb[ga[gi]][ga[gi-1]];
					cb[ga[gi]][ga[gi-1]]=0;
					v1=0;

					//dice_move_sound();
					if(SOUND==1)
					{
						sound(1000);
						delay(100);
						move_sound=1;
					}
				}
		mouse("hide");
		break;
	}

/*USER-auto move for v2*/
	else if( ((button&2)==2) && v1>0 && v2==6)
	{    	      /*1st>0*/		       /*2nd>=0 && 2nd<=44*/                  		    /*forbid to same color overlap*/
		if(  (cb[ga[gi]][ga[gi-1]]/10==1&&cb[pv2_0][pv2_1]>=0&&cb[pv2_0][pv2_1]<=44) && (cb[ga[gi]][ga[gi-1]]/10!=cb[pv2_0][pv2_1]/10) )
				      /*play when only player turn*/
			//if(  (count-1==cb[ga[gi]][ga[gi-1]]/10||count==cb[ga[gi]][ga[gi-1]]/40) )
				  /*forbid the exceed move than passd*/
				if(cur+v2<57)
				{
					//printf("%d ",count);
					cb[pv2_0][pv2_1]=cb[ga[gi]][ga[gi-1]];
					cb[ga[gi]][ga[gi-1]]=0;
					v2=v3;
					v3=0;
					//dice_move_sound();
					if(SOUND==1)
					{
						sound(1000);
						delay(100);
						move_sound=1;
					}
				}
		mouse("hide");
		break;
	}


/*search out*/
/*count value increase 1 than plyer no. because,turn_msg() calling before.*/

/*USER-p1 unreleased dices turn to release*/
	else if(((button&1)==1)&&y>=105&&y<=135&&x<630&&x>=510 &&v2==6)
	{
		for(i=630,j=1;i>=510;i=i-30,j++)
			if(x>=i-30&&x<i&&br[j]>0)
			{
				//printf("%d %d",j,br[j]);
				cb[13][j]=br[j];
				br[j]=0;
				v2=v3;
				v3=0;

				dice_move_sound();
			}
		mouse("hide");
		delay(100);
		break;
	}




	/**************** PC auto release the unreleased dice **********************************/

/*PC-p2 unreleased dices turn to release*/
	else if(prev_count==2&&v2==6&&sr_2!=4)
	{       //printf("%d %d ",v2,sv);
		for(i=0;i<5;i++)
			if(bl[i]>0)
			{
				v2=v3;
				v3=0;

				dice_move_sound();
				break;
			}
		for(j=10;j<=13;j++)
			if(cb[j][13]==0) break;

		cb[j][13]=bl[i];
		bl[i]=0;

		delay(500);
		break;
	}

/*PC-p3 unreleased dices turn to release*/
	else if(prev_count==3&&v2==6&&sr_3!=4)
	{
		for(i=0;i<5;i++)
			if(r[i]>0)
			{
				v2=v3;
				v3=0;

				dice_move_sound();
				break;
			}
		for(j=10;j<=13;j++)
			if(cb[1][j]==0) break;

		cb[1][j]=r[i];
		r[i]=0;

		delay(500);
		break;
	}

/*PC-p4 unreleased dices turn to release*/
	else if(prev_count==4&&v2==6&&sr_4!=4)
	{       //printf("%d %d ",v2,sv);
		for(i=0;i<5;i++)
			if(g[i]>0)
			{
				v2=v3;
				v3=0;  //printf("%d ",v2);

				dice_move_sound();
				break;
			}
		for(j=4;j>=1;j--)
			if(cb[j][1]==0) break;

		cb[j][1]=g[i];
		g[i]=0;

		delay(500);
		break;
	}


/*EXIT menu*/
	else if((button&1)==1&&x>=510&&x<=620&&y>=445&&y<=460)
	{
		click_sound();
		exit_msg();
		break;
	}

	else if(kbhit())
	{
		char khit=getch();
		if(khit==27)
		{
			click_sound();
			exit_msg();
		}
/***********CHEAT**************/
		else if(khit=='c')
		{
			//printf("%d ",CHEAT);
			char ch=getch();
			char str[3];
			str[0]=ch;
			str[1]='\0';
			CHEAT=atoi(str);
			//printf("%d ",CHEAT);
		}
		break;
	}


/*RULES menu*/
	else if((button&1)==1&&x>=510&&x<=620&&y>=420&&y<=435)
	{
		mouse("hide");
		click_sound();
		rules();
		setfillstyle(1,0);
		bar(0,0,640,480);
		break;
	}


/*SAVE menu*/
	else if((button&1)==1&&x>=510&&x<=620&&y>=65&&y<=80)
	{
		click_sound();
		mouse("hide");

		file_name_box('s');
		char ch,str[3];
		ch=getch();
		//FILE *fp;

		if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5')
			save(ch);

		break;
	}


/*NEW game menu*/
	else if((button&1)==1&&x>=510&&x<=620&&y>=40&&y<=55)
	{
		click_sound();

		int midx=getmaxx()/2,midy=getmaxy()/2;

		setfillstyle(6,3);
		bar(midx-210,midy-30,midx+140,midy+30);
		setfillstyle(1,0);
		bar(midx-200,midy-20,midx+130,midy+20);

		setcolor(11);
		settextstyle(0,0,1);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		outtextxy(midx-40,midy,"Are you sure to play new game (y/n)?");

		char ch=getch();
		if(ch=='y')
			default_board();

		else	break;
	}


/*main MENU menu*/   //here also use for see matrix (now inactive)
	else if((button&1)==1&&x>=510&&x<=620&&y>=15&&y<=30)
	{
		click_sound();

		int midx=getmaxx()/2,midy=getmaxy()/2;

		setfillstyle(6,3);
		bar(midx-210,midy-30,midx+140,midy+30);
		setfillstyle(1,0);
		bar(midx-200,midy-20,midx+130,midy+20);

		setcolor(11);
		settextstyle(0,0,1);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		outtextxy(midx-40,midy,"Are you sure to back main menu (y/n)?");
		if(getch()=='y')
		{
			mouse("hide");
			select_game();
			board_ludu();
		}
		/*
		clrscr();
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<15;j++)
			{
				printf("%5d",cb[i][j]);
			}
		printf("\n");
		}
		getch();
		*/
		break;
	}


/*change board*/
	else if((button&1)==1)
	{
		for(int i=15;i<=465;i=i+30)
		{
			for(int j=15;j<=465;j=j+30)
			{
				if(x>=i&&x<=i+30&&y>=j&&y<=j+30)
				{
					gi++;
			      /*mid x*/	x=(i+i+30)/2;
					//mp[gi]=x;
				  /*j*/	ga[gi]=x/30-1;
					gi++;
			      /*mid y*/	y=(j+j+30)/2;
					//mp[gi]=y;
				  /*i*/	ga[gi]=y/30-1;
				}
			}

		}
/*refresh previous board for showing probable move*/
	dynamic_board();

/*calling show_val_move()*/
	show_val_move(ga[gi],ga[gi-1],v1,v2,v3);
		 mouse("show");

		//printf("%d %d ",x,y);

		delay(200);
	}




	 /************************* PC auto move **********************************/
/*PC-auto move p2*/

	else if(prev_count==2&&v1>0)
	{
		int i,j,k=0,l=0,dtbl=0,mvbl=0,home=0;

	/*check the board path*/
		for(i=56;i>=0;i--)
			if(cb [bp[i][0]] [bp[i][1]]/10==2)
			{
				if(i+v2>56) continue;
				else if(i+v1>56) continue;
				dtbl=i;
				//printf("%d %d ",cb [bp[dtbl][0]] [bp[dtbl][1]],cb [bp[mvbl][0]] [bp[mvbl][1]]);
				break;
			}

	/*check the yellow star box blue has or not*/
		if(dtbl==0)
			for(i=10;i<=12;i++)
				for(j=1;j<=4;j++)
					if(cb[i][j]/10==2)
					{
						k=i;
						l=j;
						dtbl=13;
						break;
					}

	/*check the green star box blue has or not*/
		if(dtbl==0)
			for(i=1;i<=4;i++)
				for(j=2;j<=4;j++)
					if(cb[i][j]/10==2)
					{
						k=i;
						l=j;
						dtbl=26;
						break;
					}


	/*check the blue star box blue has or not*/
		if(dtbl==0)
			for(i=10;i<=13;i++)
				if(cb[i][13]/10==2)
				{      	//printf("%d",cb[i][j]);
					k=i;
					l=13;
					dtbl=0;
					home++;
					break;
				}

	/*check the red star box blue has or not*/
		if(home==0&&dtbl==0)
			for(i=2;i<=4;i++)
				for(j=10;j<=13;j++)
					if(cb[i][j]/10==2)
					{
						k=i;
						l=j;
						dtbl=39;
						break;
					}

	/*assign the dice value*/

		if(v2==6)
		{       //printf("move v2");
			mvbl=dtbl+v2;
			v2=v3;
			v3=0;
		}
		else if(v1>0)
		{
			mvbl=dtbl+v1;
			v1=0;
		}
		//printf("%d ",cb[k][l]);
	/*interchange*/
		if(mvbl<57&&k==0)
		{
			cb [bp[mvbl][0]] [bp[mvbl][1]]=cb [bp[dtbl][0]] [bp[dtbl][1]];
			cb [bp[dtbl][0]] [bp[dtbl][1]]=0;
			if(SOUND==1)
			{
				sound(1000);
				move_sound=1;
			}
		}
		else if(mvbl<57)
		{
			cb [bp[mvbl][0]] [bp[mvbl][1]]=cb[k][l];
			cb[k][l]=0;
			if(SOUND==1)
			{
				sound(1000);
				move_sound=1;
			}
		}
		//printf("%d %d ",cb [bp[dtbl][0]] [bp[dtbl][1]],cb [bp[mvbl][0]] [bp[mvbl][1]]);
		delay(200);
		break;
	}

/*PC-auto move p3*/

	else if(prev_count==3&&v1>0)
	{
		int i,j,k=0,l=0,dtbl=0,mvbl=0,home=0;

	/*check the board path*/
		for(i=56;i>=0;i--)
			if(cb [rp[i][0]] [rp[i][1]]/10==3)
			{
				if(i+v2>56) continue;
				else if(i+v1>56) continue;
				dtbl=i;
				//printf("%d %d ",cb [bp[dtbl][0]] [bp[dtbl][1]],cb [bp[mvbl][0]] [bp[mvbl][1]]);
				break;
			}

	/*check the blue star box red has or not*/
		if(dtbl==0)
			for(i=10;i<=13;i++)
				for(j=10;j<=12;j++)
					if(cb[i][j]/10==3)
					{
						k=i;
						l=j;
						dtbl=13;
						break;
					}

	/*check the yellow star box red has or not*/
		if(dtbl==0)
			for(i=10;i<=12;i++)
				for(j=1;j<=4;j++)
					if(cb[i][j]/10==3)
					{
						k=i;
						l=j;
						dtbl=26;
						break;
					}


	/*check the red star box red has or not*/
		if(dtbl==0)
			for(i=10;i<=13;i++)
				if(cb[1][i]/10==3)
				{      	//printf("%d",cb[i][j]);
					k=1;
					l=i;
					dtbl=0;
					home++;
					break;
				}

	/*check the green star box red has or not*/
		if(home==0&&dtbl==0)
			for(i=1;i<=4;i++)
				for(j=2;j<=4;j++)
					if(cb[i][j]/10==3)
					{
						k=i;
						l=j;
						dtbl=39;
						break;
					}

	/*assign the dice value*/

		if(v2==6)
		{       //printf("move v2");
			mvbl=dtbl+v2;
			v2=v3;
			v3=0;
		}
		else if(v1>0)
		{
			mvbl=dtbl+v1;
			v1=0;
		}
		//printf("%d ",cb[k][l]);
	/*interchange*/
		if(mvbl<57&&k==0)
		{
			cb [rp[mvbl][0]] [rp[mvbl][1]]=cb [rp[dtbl][0]] [rp[dtbl][1]];
			cb [rp[dtbl][0]] [rp[dtbl][1]]=0;
			if(SOUND==1)
			{
				sound(1000);
				move_sound=1;
			}
		}
		else if(mvbl<57)
		{
			cb [rp[mvbl][0]] [rp[mvbl][1]]=cb[k][l];
			cb[k][l]=0;
			if(SOUND==1)
			{
				sound(1000);
				move_sound=1;
			}
		}

		//printf("%d %d ",cb [bp[dtbl][0]] [bp[dtbl][1]],cb [bp[mvbl][0]] [bp[mvbl][1]]);
		delay(200);
		break;
	}

/*PC-auto move p4*/

	else if(prev_count==4&&v1>0)
	{
		int i,j,k=0,l=0,dtbl=0,mvbl=0,home=0;

	/*check the board path*/
		for(i=56;i>=0;i--)
			if(cb [gp[i][0]] [gp[i][1]]/10==4)
			{
				if(i+v2>56) continue;
				else if(i+v1>56) continue;
				dtbl=i;
				//printf("%d %d ",cb [bp[dtbl][0]] [bp[dtbl][1]],cb [bp[mvbl][0]] [bp[mvbl][1]]);
				break;
			}

	/*check the red star box green has or not*/
		if(dtbl==0)
			for(i=2;i<=4;i++)
				for(j=10;j<=13;j++)
					if(cb[i][j]/10==4)
					{
						k=i;
						l=j;
						dtbl=13;
						break;
					}

	/*check the blue star box green has or not*/
		if(dtbl==0)
			for(i=10;i<=13;i++)
				for(j=10;j<=12;j++)
					if(cb[i][j]/10==4)
					{
						k=i;
						l=j;
						dtbl=26;
						break;
					}


	/*check the green star box green has or not*/
		if(dtbl==0)
			for(i=1;i<=4;i++)
				if(cb[i][1]/10==4)
				{      	//printf("%d",cb[i][j]);
					k=i;
					l=1;
					dtbl=0;
					home++;
					break;
				}

	/*check the yellow star box green has or not*/
		if(home==0&&dtbl==0)
			for(i=10;i<=12;i++)
				for(j=1;j<=4;j++)
					if(cb[i][j]/10==4)
					{
						k=i;
						l=j;
						dtbl=39;
						break;
					}

	/*assign the dice value*/

		if(v2==6)
		{       //printf("m=%d ",v2);
			mvbl=dtbl+v2;
			v2=v3;
			v3=0;
		}
		else if(v1>0)
		{
			mvbl=dtbl+v1;
			v1=0;
		}
		//printf("%d ",cb[k][l]);
	/*interchange*/
		if(mvbl<57&&k==0)
		{
			cb [gp[mvbl][0]] [gp[mvbl][1]]=cb [gp[dtbl][0]] [gp[dtbl][1]];
			cb [gp[dtbl][0]] [gp[dtbl][1]]=0;
			if(SOUND==1)
			{
				sound(1000);
				move_sound=1;
			}
		}
		else if(mvbl<57)
		{
			cb [gp[mvbl][0]] [gp[mvbl][1]]=cb[k][l];
			cb[k][l]=0;
			if(SOUND==1)
			{
				sound(1000);
				move_sound=1;
			}
		}

		//printf("%d %d ",cb [bp[dtbl][0]] [bp[dtbl][1]],cb [bp[mvbl][0]] [bp[mvbl][1]]);
		delay(200);
		break;
	}

	/*
	else if(2==(button&2))
	{       //v1=0;
		mouse("hide");
		break;
	}
	*/

 } /*end of while loop*/

 dynamic_board();
 //delay(1000);

 return 0;
}




/******************************* board_ludu() ***************************************/


/*
play board ludu
take command for board menu
calling dice_run()
called by menu board_menu in file ludu-nam.cpp
*/
int board_ludu(void)
{

//take command from menu board
	settextstyle(0,0,1);
	setfillstyle(1,0);
	while(1)
	{
		mouse("show");
		mouse("pos");

		//if((button&1)==1)
		  //	printf("%d %d ",x,y);
		//NEW GAME
			if(((button&1)==1)&&x>=225&&x<=415&&y>=175&&y<=200)
			{
				click_sound();
				mouse("hide");

				setfillstyle(1,0);
				bar(0,0,640,480);
				default_board();
				break;
			}
		//LOAD
			else if(((button&1)==1)&&x>=270&&x<=365&&y>=215&&y<=240)
			{
				click_sound();
				mouse("hide");

				file_name_box('l');
				char ld;
				ld=getch();

				char str[3];
				FILE *fp;
				str[0]=ld;
				str[1]='\0';
				if( (fp=fopen(str,"rb"))!=NULL )
				{
					if(ld=='1'||ld=='2'||ld=='3'||ld=='4'||ld=='5')
					{
						load(ld);
						loading_msg();
					}
					break;
				}
				else
				{
					menu_board();
					board_ludu();
				}


			}
		//OPTION
			else if(((button&1)==1)&&x>=245&&x<=390&&y>=255&&y<=280)
			{
				mouse("hide");
				click_sound();
				option();
				menu_board();
				board_ludu();
			}
		//RULES
			else if(((button&1)==1)&&x>=260&&x<=380&&y>=295&&y<=320)
			{
				click_sound();
				mouse("hide");
				rules();
				menu_board();
				board_ludu();
			}
		//CREDITS
			else if(((button&1)==1)&&x>=245&&x<=385&&y>=335&&y<=360)
			{
				click_sound();
				mouse("hide");

				credits();
				menu_board();
				board_ludu();
			}
		//EXIT
			else if(((button&1)==1)&&x>=270&&x<=365&&y>=375&&y<=400)
			{
				click_sound();
				mouse("hide");

				if(exit_msg()==0)
				{
					menu_board();
					board_ludu();
				}
			}

		delay(100);
	}

//play whole board game
	 while(1)
		dice_run();


//return 0;
}



/*********************************** MAIN ****************************************/

int main()
{int gdriver=DETECT,gmode;

 clrscr();


 /*graphics initialising*/
 initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
 if(graphresult()!=0)
 {
	printf("graphics ERROR!!\nerror occurs for initialising...\npress any key to exit.");
	getch();
	exit(1);
 }

 mouse("load");

 initial_screen();
// enter_user_name();

// select_game();
// board_ludu();

 getch();
 return 0;
}