


/*
show 6-dice shuffle
*/
dice(void)
{
//setcolor(DICECOLOR_3);
setfillstyle(5,RED);
bar(205,257,275,283);

setfillstyle(1,YELLOW);
bar(208,259,272,280);

setcolor(0);
settextstyle(4,0,2);
settextjustify(CENTER_TEXT,CENTER_TEXT);
outtextxy(242,265,"shuffle");

return 0;
}


/*
show pressed shuffle button
*/
int short_dice(void)
{
//setcolor(DICECOLOR_3);
setfillstyle(5,GREEN);
bar(205,257,275,283);

setfillstyle(1,YELLOW);
bar(210,261,270,278);

setcolor(0);
settextstyle(4,0,1);
settextjustify(CENTER_TEXT,CENTER_TEXT);
outtextxy(242,265,"shuffle");
 return 0;
}


/*
print star
*/
star(int i,int j)
{
setcolor(7);
setfillstyle(1,8);

line(i+12,j+12,i+15,j+2);
line(i+15,j+2,i+18,j+12);

line(i+2,j+12,i+12,j+12);
line(i+18,j+12,i+28,j+12);

line(i+2,j+12,i+10,j+18);
line(i+28,j+12,i+20,j+18);

line(i+10,j+18,i+5,j+28);
line(i+20,j+18,i+25,j+28);

line(i+5,j+28,i+15,j+22);
line(i+25,j+28,i+15,j+22);

floodfill(i+15,j+12,7);

return 0;
}



/*
print game screen
*/
int board(void)
{
 setcolor(WHITE);

 RGB(YELLOW,63,50,0);

 for(int i=15;i<=465;i=i+30)
 {
	for(int j=15;j<=465;j=j+30)
	{
	/*box green & red*/
		if(i==15&&j==195)
		{
			setfillstyle(6,DICECOLOR_4);
			bar3d(i,i,j,j,0,0);
			setfillstyle(6,DICECOLOR_3);
			bar3d(i+270,i,j+270,j,0,0);
		}
	/*box mid*/
		if(i==195&&j==285)
		{
			setfillstyle(1,8);
			bar3d(i,i,j,j,0,0);
		}
	/*box brown & blue*/
		if(i==285&&j==465)
		{
			setfillstyle(6,DICECOLOR_2);
			bar3d(i,i,j,j,0,0);

			setfillstyle(6,DICECOLOR_1);
			bar3d(i-270,i,j-270,j,0,0);
		}
	/*LINE*/
		if(i==195&&j<=435)
		{
		/*light green line*/
			if(j<=165)
			{
				setfillstyle(1,LINECOLOR_4);
				bar3d(i,j,i+30,j+30,0,0);
				bar3d(j,i,j+30,i+30,0,0);
			}
		/*light red line & light brown line*/
			else if(j>=285)
			{
			setfillstyle(1,LINECOLOR_3);
				bar3d(j,i,j+30,i+30,0,0);
				setfillstyle(1,LINECOLOR_1);
				bar3d(i,j,i+30,j+30,0,0);
			}
		}
		if(i==255&&j<=435)
		{
		/*light red line & light brown line*/
			if(j<=165)
			{
				setfillstyle(1,LINECOLOR_3);
				bar3d(i,j,i+30,j+30,0,0);
				setfillstyle(1,LINECOLOR_1);
				bar3d(j,i,j+30,i+30,0,0);
			}
		/*light blue line*/
			else if(j>=285)
			{
				setfillstyle(1,LINECOLOR_2);
				bar3d(j,i,j+30,i+30,0,0);
				bar3d(i,j,i+30,j+30,0,0);
			}
		}
	/*mid line*/
		if(i==225&&j<=435)
		{

			if((j>=45&&j<=165)||(j>=285&&j<=405))
			{
				setfillstyle(1,7);
				bar3d(j,i,j+30,i+30,0,0);
				bar3d(i,j,i+30,j+30,0,0);
			}
			else if(j>=15&&j<=45)
			{
				setfillstyle(1,LINECOLOR_4);
				bar3d(j,i,j+30,i+30,0,0);
				setfillstyle(1,LINECOLOR_3);
				bar3d(i,j,i+30,j+30,0,0);
			}
			else if(j>=435&&j<=465)
			{
				setfillstyle(1,LINECOLOR_2);
				bar3d(j,i,j+30,i+30,0,0);
				setfillstyle(1,LINECOLOR_1);
				bar3d(i,j,i+30,j+30,0,0);
			}
		}

	}/*j loop end*/
 }/*i loop end*/

 setfillstyle(1,15);
 bar3d(225,225,255,255,0,0);
 /*box bar*/
	setfillstyle(1,LINECOLOR_4);
	bar(45,45,165,165);

	setfillstyle(1,LINECOLOR_3);
	bar(315,45,435,165);

	setfillstyle(1,LINECOLOR_2);
	bar(315,315,435,435);

	setfillstyle(1,LINECOLOR_1);
	bar(45,315,165,435);

 /*star*/
   setcolor(5);
   star(195,405);
   star(45,195);
   star(255,45);
   star(405,255);

   dice();

 /*player statistics box*/
	for(int j=75;j<=375;j=j+30)
	{
		if(j==105)
		{
			setfillstyle(9,DICECOLOR_1);
			bar(500,j-15,630,j+30);
			setfillstyle(1,0);
			bar(502,j+2,628,j+28);
		}

		if(j==165)
		{
			setfillstyle(9,DICECOLOR_2);
			bar(500,j-15,630,j+30);
			setfillstyle(1,0);
			bar(502,j+2,628,j+28);
		}

		if(j==315)
		{
			setfillstyle(9,DICECOLOR_3);
			bar(500,j-15,630,j+30);
			setfillstyle(1,0);
			bar(502,j+2,628,j+28);
		}

		if(j==375)
		{
			setfillstyle(9,DICECOLOR_4);
			bar(500,j-15,630,j+30);
			setfillstyle(1,0);
			bar(502,j+2,628,j+28);
		}
	 }

/*inner name*/
  settextjustify(CENTER_TEXT,TOP_TEXT);
  settextstyle(2,0,5);
  //setusercharsize(1,2,1,3);

  setcolor(LINECOLOR_4);
  outtextxy(105,15,"PLAYER 4");
  setcolor(LINECOLOR_3);
  outtextxy(375,15,"PLAYER 3");
  setcolor(LINECOLOR_2);
  outtextxy(375,435,"PLAYER 2");

  setusercharsize(2,1,2,1);
  setcolor(LINECOLOR_1);
  outtextxy(105,435,name);

/*outer name*/
  settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
  settextstyle(2,0,5);

  setcolor(LINECOLOR_4);
  outtextxy(630,370,"PLAYER 4");
  setcolor(LINECOLOR_3);
  outtextxy(630,310,"PLAYER 3");
  setcolor(LINECOLOR_1);
  outtextxy(630,100,name);
  setcolor(LINECOLOR_2);
  outtextxy(630,160,"PLAYER 2");

 /*HOME-passed box*/
  for(i=480;i<630;i=i+30)
  {
	setcolor(8);
	for(j=205;j<=265;j=j+30)
	{
		setfillstyle(1,7);
		bar3d(i,j,i+30,j+30,0,0);
	}
  }
  setcolor(11);
  settextstyle(0,1,1);
  outtextxy(480,266,"HOME");


/*menu,new,save*/
  for(i=15;i<=445;i=i+25)
  {
	  setfillstyle(5,13);
	  bar(510,i,620,i+15);
	  setfillstyle(1,5);
	  bar(512,i+2,618,i+13);
	  if(i==65) i=420-25;
  }
  setcolor(11);
  settextjustify(CENTER_TEXT,CENTER_TEXT);
  settextstyle(0,0,1);
  outtextxy(565,23,"Menu");
  outtextxy(565,48,"New");
  outtextxy(565,73,"Save");
  outtextxy(565,428,"Rules");
  outtextxy(565,453,"Exit");


 return 0;
}


/*
print yellow dice
*/
yellow(int i,int j)
{
 setcolor(DICECOLOR_1);
 setfillstyle(1,DICECOLOR_1);
 fillellipse(i,j,13,13);

 return 0;
}


/*
print green dice
*/
green(int i,int j)
{
 setcolor(DICECOLOR_4);
 setfillstyle(1,DICECOLOR_4);
 fillellipse(i,j,13,13);

 return 0;
}


/*
print red dice
*/
red(int i,int j)
{
 setcolor(DICECOLOR_3);
 setfillstyle(1,DICECOLOR_3);
 fillellipse(i,j,13,13);

 return 0;
}


/*
print blue dice
*/
blue(int i,int j)
{
 setcolor(DICECOLOR_2);
 setfillstyle(1,DICECOLOR_2);
 fillellipse(i,j,13,13);

 return 0;
}


