

/**************************** enter_user_name ****************************************/

char *name;
int enter_user_name(void)
{int d=0,m;
closegraph();

gotoxy(25,12);
printf("Enter your name:\n");
gotoxy(25,13);
gets(name);

initgraph(&d,&m,"c:\\tc\\bgi");
return 0;
}



/**************************** L ****************************************/
/*
print L
*/
int L(int i,int j)
{
	setfillstyle(i,j);
	bar(120,180,150,280);
	bar(150,250,190,280);
return 0;
}


/**************************** U1 ****************************************/
/*
print first U
*/
int U1(int i,int j)
{
	setfillstyle(i,j);
	bar(210,180,240,280);
	bar(270,180,300,280);
	bar(210,250,300,280);
return 0;
}



/**************************** D ****************************************/
/*
print D
*/
int D(int i,int j)
{
	setfillstyle(i,j);
	bar(320,180,350,280);
	bar(350,180,370,210);
	bar(350,250,370,280);
	bar(370,240,390,270);
	bar(370,190,390,220);
	bar(380,200,400,260);
return 0;
}



/**************************** U2 ****************************************/
/*
print second U
*/
int U2(int i,int j)
{
	setfillstyle(i,j);
	bar(420,180,450,280);
	bar(480,180,510,280);
	bar(450,250,480,280);
return 0;
}


/**************************** blink_name ****************************************/
/*
print blinking name
*/
int blink_name(void)
{
	L(1,BLUE);
	delay(1000);

	L(0,0);
	U1(1,BROWN);
	delay(800);

	U1(0,0);
	D(1,RED);
	delay(800);

	D(0,0);
	U2(1,GREEN);
	delay(800);

	U2(0,0);
	delay(500);

return 0;
}


/**************************** print_name ****************************************/
/*
print static name
*/
int static_name(void)
{
	L(1,BLUE);
	U1(1,BROWN);
	D(1,RED);
	U2(1,GREEN);
return 0;
}



/**************************** menu_board ****************************************/
/*
print board menu
*/

int menu_board(void)
{
	setfillstyle(1,0);
	bar(0,0,640,480);

	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(0,0,8);
	setcolor(15);
	outtextxy(319,69,"MENU");
	setcolor(1);
	outtextxy(320,70,"MENU");

	settextstyle(0,0,3);
	char *str;
	for(int i=190,c=1;c<=6;i=i+40,c++)
	{
		if(c==1) str="New Game";
		else if(c==2) str="Load";
		else if(c==3) str="Option";
		else if(c==4) str="Rules";
		else if(c==5) str="Credits";
		else if(c==6) str="Exit";

		setcolor(15);
		outtextxy(319,i,str);
		setcolor(1);
		outtextxy(320,i,str);
	}
	board_ludu();

return 0;
}



/**************************** select_game ****************************************/
/*
print select game page
call main menu function of selected game
*/
int select_game(void)
{
char c;

DICECOLOR_1=6;
LINECOLOR_1=14;
DICECOLOR_2=1;
LINECOLOR_2=9;
DICECOLOR_3=4;
LINECOLOR_3=12;
DICECOLOR_4=2;
LINECOLOR_4=10;

	setfillstyle(1,15);
	bar(0,0,640,480);
	delay(500);
	blink_name();
	static_name();


//PLAYER number selection.
	setfillstyle(0,0);
	bar(210,310,400,370);

	setcolor(15);
	settextstyle(2,0,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(300,330,"How mauny PLAYER ?");

	outtextxy(300,340+textheight("h"),"press 2,3,4...");


/*continuing if c!=1 or 2*/
	while(1)
	{
		delay(500);
		setfillstyle(1,15);
		bar(120,180,510,280);
		delay(500);
		blink_name();
		static_name();

		if(kbhit())
		{
			c=getch();
			if(c=='2')
			{
				PLAYER_NUMBER=2;
				break;
			}
			else if(c=='3')
			{
				PLAYER_NUMBER=3;
				break;
			}
			else if(c=='4')
			{
				PLAYER_NUMBER=4;
				break;
			}

		}
	}


//USER color selection.
	setfillstyle(0,0);
	bar(210,310,400,410);

	setcolor(15);
	settextstyle(2,0,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(300,325,"Choose your color:");
	outtextxy(300,335,"press 1,2,3,4...");

	settextstyle(2,0,5);
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	setcolor(BROWN);
	outtextxy(260,350,"1) BROWN");
	setcolor(BLUE);
	outtextxy(260,365,"2) BLUE");
	setcolor(RED);
	outtextxy(260,380,"3) RED");
	setcolor(GREEN);
	outtextxy(260,395,"4) GREEN");


/*continuing if c!=1 or 2*/
	while(1)
	{
		delay(500);
		setfillstyle(1,15);
		bar(120,180,510,280);
		delay(500);
		blink_name();
		static_name();

		if(kbhit())
		{
			c=getch();
			if(c=='1')
			{
				menu_board();
				break;
			}
			else if(c=='2')
			{
				DICECOLOR_1=1;
				LINECOLOR_1=9;

				DICECOLOR_2=6;
				LINECOLOR_2=14;

				menu_board();
				break;
			}
			else if(c=='3')
			{
				DICECOLOR_1=4;
				LINECOLOR_1=12;

				DICECOLOR_3=6;
				LINECOLOR_3=14;

				menu_board();
				break;
			}
			else if(c=='4')
			{
				DICECOLOR_1=2;
				LINECOLOR_1=10;

				DICECOLOR_4=6;
				LINECOLOR_4=14;

				menu_board();
				break;
			}

		}
	}
return 0;
}



/**************************** initial_screen ****************************************/
/*
initial screen (1st screen)
*/
int initial_screen(void)
{
int i;
	blink_name();
	/*print various type of name*/
	for(i=1;i<13;i++)
	{
		if(kbhit())
			if(getch())       /*for pressing any key the showing name will terminated*/
				break;
		L(i,i);
		U1(i,i);
		D(i,i);
		U2(i,i);
		delay(500);
	}
	setfillstyle(1,0);
	bar(0,0,640,480);
	delay(500);

	static_name();

	/*print a blinking msg*/
	setfillstyle(1,0);
	settextstyle(0,0,1);
	while(!kbhit())
	{
		outtextxy(220,350,"prees any key to continue...");
		delay(500);
		bar(0,340,650,360);
		delay(500);
	}
	getch();
	setfillstyle(1,0);
	bar(0,0,getmaxx(),getmaxy());

	enter_user_name();
	select_game();

return 0;
}

