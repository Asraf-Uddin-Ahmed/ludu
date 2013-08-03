

int save(char ch)
{
FILE *fp;
int i,j;
struct ftime ft;	//for measure time
char *f_name,str[3];

str[0]=ch;
str[1]='\0';

	if( (fp=fopen(str,"rb"))!=NULL )
	{
		char msg[50];
		int midx=getmaxx()/2,midy=getmaxy()/2;

		setfillstyle(6,3);
		bar(midx-200,midy-30,midx+140,midy+30);
		setfillstyle(1,0);
		bar(midx-190,midy-20,midx+130,midy+20);

		setcolor(11);
		settextstyle(0,0,1);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		sprintf(msg,"Do you want to overwrite file no.%c(y/n)?",ch);
		outtextxy(midx-30,midy,msg);
		if(getch()=='n') return 0;
	}


	fp=fopen(str,"wb");	//create ch=1,2,3,4,5 named file to save game data

	//time measuring
	getftime(fileno(fp),&ft); 	//get file create time
	sprintf(f_name,"%u.%u.%u (%u:%u:%u)",ft.ft_day,ft.ft_month,ft.ft_year+1980,ft.ft_hour,ft.ft_min,ft.ft_tsec*2);

	//data saving
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{
			//fprintf(fp,"%d",cb[i][j]);
			putc(cb[i][j],fp);
			fflush(fp);
		}
	for(i=0;i<=20;i++)
	{
		//fprintf(fp,"%d",pb[i]);
		putc(pb[i],fp);
		fflush(fp);
	}
	fclose(fp);

	//saving file create time into file
	if(ch=='1')fp=fopen("ft1","w");
	else if(ch=='2')fp=fopen("ft2","w");
	else if(ch=='3')fp=fopen("ft3","w");
	else if(ch=='4')fp=fopen("ft4","w");
	else if(ch=='5')fp=fopen("ft5","w");

	for(i=0;f_name[i]!='\0';i++)
	{
		putc(f_name[i],fp);
		fflush(fp);
	}
	fclose(fp);

	//saving msg
	setfillstyle(10,3);
	bar(105,135,375,345);
	setfillstyle(1,0);
	bar(135,165,345,315);

	setcolor(11);
	settextstyle(0,0,1);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	char sm[10]="SAVING...";
	outtextxy(195,240,sm);

return 0;
}


int load(char ch)
{
FILE *fp;
int i,j;

char str[3];

str[0]=ch;
str[1]='\0';
	//if( (fp=fopen(str,"rb"))==NULL ) return 0;

	fp=fopen(str,"rb");
	i=0;
	j=0;
	while( i<15 )   //store array cb
	{
		//fscanf(fp,"%d",&cb[i][j]);
		cb[i][j]=getc(fp);
		j++;
		if(j==15)
		{
			i++;
			j=0;
		}
	}
	i=0;
	while( (pb[i]=getc(fp))!=EOF )
	//while( fscanf(fp,"%d",&pb[i])!=EOF)
		i++;
	fclose(fp);
return 0;
}


/*
print save box
print load box
*/
int file_name_box(char ch)
{FILE *fp;
char file_time1[25]="Empty",file_time2[25]="Empty",file_time3[25]="Empty",file_time4[25]="Empty",file_time5[25]="Empty";
int i,c;
char *no;


//assign name into file_time
//retrive file name means time from file_time1
if( (fp=fopen("ft1","rb"))!=NULL )
{
	i=0;
	while( (file_time1[i]=getc(fp))!=EOF )
		i++;
	fclose(fp);
}
//retrive file name means time from file_time2
if( (fp=fopen("ft2","rb"))!=NULL )
{
	i=0;
	while( (file_time2[i]=getc(fp))!=EOF )
		i++;
	fclose(fp);
}
//retrive file name means time from file_time3
if( (fp=fopen("ft3","rb"))!=NULL )
{
	i=0;
	while( (file_time3[i]=getc(fp))!=EOF )
		i++;
	fclose(fp);
}
//retrive file name means time from file_time4
if( (fp=fopen("ft4","rb"))!=NULL )
{
	i=0;
	while( (file_time4[i]=getc(fp))!=EOF )
		i++;
	fclose(fp);
}
//retrive file name means time from file_time5
if( (fp=fopen("ft5","rb"))!=NULL )
{
	i=0;
	while( (file_time5[i]=getc(fp))!=EOF )
		i++;
	fclose(fp);
}

//box
setfillstyle(10,3);
bar(105,135,375,345);
setfillstyle(1,0);
bar(135,165,345,315);
bar(195,140,285,160);
//save & load
setcolor(8);
settextstyle(0,0,2);
settextjustify(CENTER_TEXT,CENTER_TEXT);

if(ch=='s') outtextxy(240,150,"SAVE");
else if(ch=='l') outtextxy(240,150,"LOAD");

//no. of file
setcolor(11);
settextstyle(0,0,1);
for(i=180,c=1;i<=300;i=i+30,c++)
{
	sprintf(no,"%d)",c);
	outtextxy(150,i,no);
}

//print file name
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(165,180,file_time1);
outtextxy(165,210,file_time2);
outtextxy(165,240,file_time3);
outtextxy(165,270,file_time4);
outtextxy(165,300,file_time5);

return 0;
}

