
/******************************* exit msg ***********************************************/

/*
show exit message
*/
int exit_msg(void)
{

	int midx=getmaxx()/2,midy=getmaxy()/2;
	/*print exit box*/
		setfillstyle(6,3);
		bar(midx-160,midy-30,midx+140,midy+30);
		setfillstyle(1,0);
		bar(midx-150,midy-20,midx+130,midy+20);

		setcolor(11);
		settextstyle(0,0,1);
		outtextxy(midx-10,midy,"Do you want to exit desktop (y/n)?");

	/*without pressing y or n loop will continuing.other pressing key cant break the loop.*/
		char c=0;
		while(1)
		{
			c=getch();
			if(c=='Y'||c=='y')	exit(1);
			else if(c=='N'||c=='n') break;
			//else printf("\a");
		}

return 0;
}




/******************************** delay_text **********************************/

int delay_text(int x,int y,char *str)
{        char *ch;
	//gotoxy(x,y);
	 //settextstyle(2,0,5);
	 for(int i=0;str[i]!='\0';i++)
	 {
		if(kbhit()) break;

		ch[0]=str[i];
		ch[1]='\0';
		outtextxy(x=x+textwidth("w"),y,ch);
		delay(30);
	 }
 return 0;
}



/******************************** CREDITS  *********************************************/
/*
has a uper moving text
print credits
*/
int credits(void)
{int i;
char str1[]="Special thanks to encourage us:",
     str2[]="Md. Bodrul Alam Mia",
     str3[]="Lecturer of ICT department,MBSTU.",
     str4[]="Mossaddeque Mahmood",
     str5[]="Student of ICT department,MBSTU.",

     str6[]="Thanks for participating to accomplished this game:",
     str7[]="1) Fatema Khatun          IT-09009",
     str8[]="2) Tanzeena Rahman        IT-09013",
     str9[]="3) Rucksana Safa Sultana  IT-09015",
     str10[]="4) Istiaq Hossain         IT-09042",
     str11[]="5) Asraf Uddin Ahmed      IT-09047";

	setcolor(6);
	for(i=480;i>=160;i=i-10)
	{
		int j=i;
		setfillstyle(1,0);
		bar(0,0,640,480);
		if(i==160)
		{
			setfillstyle(8,2);
			bar(100,90,540,390);

			setfillstyle(1,0);
			bar(115,105,525,375);
			bar(260,90,380,105);
			//delay(500);
		}
		settextjustify(CENTER_TEXT,TOP_TEXT);
		settextstyle(0,0,2);
		outtextxy(320,90,"Credits");

		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(0,0,1);
		outtextxy(getmaxx()/2,i,str1);
		outtextxy(getmaxx()/2,j+=20,str2);
		outtextxy(getmaxx()/2,j+=10,str3);
		outtextxy(getmaxx()/2,j+=20,str4);
		outtextxy(getmaxx()/2,j+=10,str5);
		j+=40;
		outtextxy(getmaxx()/2,j+=10,str6);

		settextjustify(LEFT_TEXT,CENTER_TEXT);
		outtextxy(120,j+=20,str7);
		outtextxy(120,j+=10,str8);
		outtextxy(120,j+=10,str9);
		outtextxy(120,j+=10,str10);
		outtextxy(120,j+=10,str11);
		delay(100);
		if(i<=170) delay(500);

	}
	setcolor(15);
	settextstyle(0,0,1);
	delay_text(200,420,"Press any key to continue...");
	getch();
return 0;
}


/**************************** loading_message  ********************************************/

/*
after loading need a click or press to see board for that print loading
don't need getch()
*/
int loading_msg(void)
{
	setcolor(15);
	setfillstyle(1,0);
	bar(0,0,640,480);
	settextstyle(3,0,5);
	delay_text(50,150,"LOADING. . .");
	settextstyle(2,0,5);
	delay_text(100,450,"Press any key to continue...");

return 0;
}


/******************************* option ***************************************/
/*
sound on/off
*/
int option(void)
{
	setfillstyle(1,0);
	bar(0,0,640,480);

	setfillstyle(8,2);
	bar(100,140,540,340);

	setfillstyle(1,0);
	bar(260,140,380,155);
	bar(115,155,525,230);
	bar(115,250,525,325);

	setcolor(15);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(0,0,1);
	outtextxy(320,400,"press enter to back main menu.");

	setcolor(6);
	settextjustify(CENTER_TEXT,TOP_TEXT);
	settextstyle(0,0,2);
	outtextxy(320,140,"Options");

	settextjustify(LEFT_TEXT,CENTER_TEXT);
	settextstyle(2,0,5);
	outtextxy(125,190,"Sound :");
	outtextxy(125,290,"press space to change sound.");

	char ch,str1[]="on",str2[]="off";

	do
	{
		if(ch==' ')	SOUND++;

		setfillstyle(1,0);
		bar(180,180,210,200);

		if(SOUND==1)
			outtextxy(190,190,str1);
		else
		{
			outtextxy(190,190,str2);
			SOUND=0;
		}
	}while( (ch=getch())!=13 );

 return 0;
}

/********************************* rules  ****************************************/


int rules(void)
{int j;
/*BASIC rules*/
	setfillstyle(1,0);
	bar(0,0,640,480);

	setfillstyle(8,2);
	bar(50,60,590,420);

	setfillstyle(1,0);
	bar(65,75,575,405);
	bar(50,60,130,75);

	setcolor(6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(0,0,3);
	outtextxy(320,40,"Rules");

	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(0,0,2);
	outtextxy(50,60,"Basic");

	settextstyle(0,0,1);
	setcolor(15);
	outtextxy(200,440,"Press any key to see next page...");

	j=95;
	setcolor(6);
	settextstyle(0,0,1);
	delay_text(70,j,"1) Maximum 4 players can play LUDU.Each player has a different");
	delay_text(70,j+=10,"   color of module and also has 4 same color of dices to play.");
	delay_text(70,j+=20,"2) Another type of dice called `Sixer' which actually controls");
	delay_text(70,j+=10,"   the game.This `Sixer' holds number from 1 to 6 individully");
	delay_text(70,j+=10,"   on its individual surfaces.");
	delay_text(70,j+=20,"3) To start the game,this `Sixer' must be thrown on board.The");
	delay_text(70,j+=10,"   number of upper surface is taken as `Sixer' value.");
	delay_text(70,j+=20,"4) At first to release a dice from initial board to game board");
	delay_text(70,j+=10,"   least a `6' must be needed.If one gets `6' then throw again");
	delay_text(70,j+=10,"   `Sixer'.If one gets `6' in three times sequently,can not");
	delay_text(70,j+=10,"   count any of them.");
	delay_text(70,j+=20,"5) Dice must be move to cosidering `Sixer' value.The total");
	delay_text(70,j+=10,"   `Sixer' value and the number of moving is same.");
	delay_text(70,j+=20,"6) While moving a dice,there is possibility to overlapping of");
	delay_text(70,j+=10,"   two dices:");
	delay_text(70,j+=20,"    i) If dices were different players,then 1st can replace by");
	delay_text(70,j+=10,"       2nd.1st player will get that dice on initial board.");
	delay_text(70,j+=20,"   ii) If dices were same players,there will a chance to make");
	delay_text(70,j+=10,"       `Pair'. (This term is not in our LUDU)");
	delay_text(70,j+=20,"7) Acoording this rules,all dice of a player reached `HOME'");
	delay_text(70,j+=10,"   first is WINNER.And the 2nd,3rd & Last sequently.");

	getch();

/*ADVANCED rules*/
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(0,0,3);
	outtextxy(320,40,"Rules");

	setfillstyle(1,0);
	bar(0,60,640,480);

	setfillstyle(8,2);
	bar(50,60,590,420);

	setfillstyle(1,0);
	bar(65,75,575,405);
	bar(50,60,180,75);

	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(0,0,2);
	outtextxy(50,60,"Advanced");

	settextstyle(0,0,1);
	setcolor(15);
	outtextxy(200,440,"Press any key to back main menu...");

	j=115;
	setcolor(6);
	settextstyle(0,0,1);
	delay_text(70,j,"1) Press `Shuffle' to start the game.Wait for a while until");
	delay_text(70,j+=10,"   `Sixer' (situated middle of board) stop and show its value.");
	delay_text(70,j+=30,"2) At first you have to get `6' to bring dice into board.");
	delay_text(70,j+=10,"   Unless wait for a while until next 3 players complete");
	delay_text(70,j+=10,"   their turn.");
	delay_text(70,j+=30,"3) After getting `6' press `Shuffle' more time.");
	delay_text(70,j+=30,"4) To release the dice from initial board (right of screen)");
	delay_text(70,j+=10,"   just click left button of mouse.");
	delay_text(70,j+=30,"5) To move your dice,click left button of mouse on desired");
	delay_text(70,j+=10,"   dice and then click right button to move the dice showing");
	delay_text(70,j+=10,"   board by circle.Remember,if your total `Sixer' value is");
	delay_text(70,j+=10,"   more than 6,then move will continue to descending order");
	delay_text(70,j+=10,"   like first 6 then,less than 6.");
	delay_text(70,j+=30,"6) You have to move all 4 dices to HOME first to WIN the game.");
	delay_text(70,j+=10,"   Unless you will lose.");

	getch();


 return 0;
}
