#include "iGraphics.h"
#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

char times[]="images/*.bmp",name1[25],name2[25],next,selected='m',guti=0,fsave=0,tmove=0,a[]="images/**.bmp",b[]="images/*.bmp",player1[15]={0},player2[15]={0};
char savename1[25],savename2[25],savedead1[15],savedead2[15];
int savetime;
int ctr,mode=3,temp,kaysar=0,len=0,rks=0,tim=0,page=1,p=100,q=100,ball=1,x=0,y,row,column,row2,column2,timecount=0,counter=0,p1=0,p2=0,pos;
bool bck=0,wck=0;
double x2=250,y2=460,x3=250,y3=430;
char bcheck[]="Black in check!",wcheck[]="White in check!",white[]="WHITE's turn!",black[]="BLACK's turn!";
char savearray[8][8],parray[8][8];
char dfltarray[8][8]={ {'b','c','d','e','f','d','c','b'},
						{'a','a','a','a','a','a','a','a'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'g','g','g','g','g','g','g','g'},
						{'h','i','j','k','l','j','i','h'} };


void Starting()
{
	iShowBMP(0,0,"images/starting.bmp");
	counter++;
}


void FrontPage()
{	
	iShowBMP(0,0,"images/background.bmp");	
	iShowBMP(380,466,"images/button1.bmp");
	iShowBMP(380,392,"images/button2.bmp");
	iShowBMP(380,318,"images/button3.bmp");
	iShowBMP(380,244,"images/button4.bmp");
	iShowBMP(380,170,"images/button5.bmp");
}


void Board()
{
	iShowBMP(0,0,"images/loading.bmp");
	iSetColor(25,25,112);//outer border of the board
	iFilledRectangle(43,43,614,614);
	iSetColor(238,233,233);//white
	iFilledRectangle(46,46,608,608);
	iSetColor(128,128,128);//black
	for(int i=0;i<=7;i++)
		for(int j=0;j<=3;j++)
			iFilledRectangle(46+(76*(i%2))+(152*j),46+(76*i),76,76);
	
	iSetColor(0,0,0);
	//iLine(700.00,10.00,700.00,690.00);
	if (tmove%2==0) iShowBMP(720,592,"images/wturn.bmp");
	else if (tmove%2==1) iShowBMP(720,592,"images/bturn.bmp");
	iShowBMP(720,43,"images/sidebar.bmp");
	if (tmove%2==0)
	{
		iSetColor(0,0,0);
		iText(750,600,name1,GLUT_BITMAP_HELVETICA_18);
	}
	else if (tmove%2==1)
	{
		iSetColor(255,255,255);
		iText(750,600,name2,GLUT_BITMAP_HELVETICA_18);
	}
}

void Piecesload()
{
	for(int i=0;i<=7;i++) 
		for(int j=0;j<=7;j++)
			if (parray[i][j]!='0')
			{
				a[7] = parray[i][j];
				if ((i+j)%2==0) a[8]='1';
				else if ((i+j)%2==1) a[8]='2';
				iShowBMP(52+(76*j),584-(76*i),a);
			}
} 


void Number()
{
	if (guti>=97 && guti<=102)
		player1[p1++]=guti+14;
	else if (guti>=103 && guti<=108)
		player2[p2++]=guti+14;
}


void Deadpieces()
{	
	for(int i=0;i<=2;i++)
		for(int j=0;j<=4;j++)
		{
			pos=(5*i)+j;
			if (player1[pos]!='0')
			{
				b[7]=player1[pos];
				iShowBMP(758+(36*j),422-(36*i),b);
			}
			if (player2[pos]!='0')
			{
				b[7]=player2[pos];
				iShowBMP(758+(36*j),257-(36*i),b);
			}		
		}
}


void Selrec()
{
	iSetColor(65,105,225);
	if (selected!='m') 
	{
		if (((tmove%2==0) && (selected>=103 && selected<=108)) || ((tmove%2==1) && (selected>=97 && selected<=102)))
		{
			if ((row!=(-1)) && (column!=(-1)))
			{
				iRectangle(46+(76*column),578-(76*row),76,76);
				iRectangle(45+(76*column),577-(76*row),78,78);
				iRectangle(44+(76*column),576-(76*row),80,80);
			}
		}
	}
}


void Check()
{
	int bkx,bky,wkx,wky;
	bool side[8]={0};
	bck=0;
	wck=0;

	for(int i=0;i<=7;i++)
		for(int j=0;j<=7;j++)
		{
			if (parray[i][j]=='f')
			{
				bkx=i;
				bky=j;
			}
			else if (parray[i][j]=='l')
			{
				wkx=i;
				wky=j;
			}
		}

	for(i=1;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			if (side[i]==0)	
			{
						
			}
		}
	}


	iSetColor(0,0,0);

	if (wck==1) 
		iText(350,75,"WHITE in check !",GLUT_BITMAP_TIMES_ROMAN_24);
	if (bck==1) 
		iText(350,675,"BLACK in check !",GLUT_BITMAP_TIMES_ROMAN_24);

}


void Savegame()
{
	for(int i=0;i<=7;i++)
		for(int j=0;j<=7;j++)
			savearray[i][j]=parray[i][j];

	strcpy(savename1,name1);
	strcpy(savename2,name2);

	savetime=tim;

	for(i=0;i<=14;i++)
	{
		savedead1[i]=player1[i];	
		savedead2[i]=player2[i];
	}
}


void Help()
{	
	iShowBMP(0,0,"images/blur.bmp");
	if (page==1)
	{
		iShowBMP(250,160,"images/help1.bmp");
		iShowBMP(698,127,"images/on.bmp");
	}
	else if (page==2)
	{
		iShowBMP(250,160,"images/help2.bmp");
		iShowBMP(698,127,"images/np.bmp");
	}
	else if (page==3)
	{
		iShowBMP(250,160,"images/help3.bmp");
		iShowBMP(698,127,"images/np.bmp");
	}
	else if (page==4)
	{
		iShowBMP(250,160,"images/help4.bmp");
		iShowBMP(698,127,"images/np.bmp");
	}
	else if (page==5)
	{
		iShowBMP(250,160,"images/help5.bmp");
		iShowBMP(698,127,"images/np.bmp");
	}
	else if (page==6)
	{
		iShowBMP(250,160,"images/help6.bmp");
		iShowBMP(698,127,"images/op.bmp");
	}
	iShowBMP(380,60,"images/button8.bmp");
}


void Credit()
{
	iShowBMP(0,0,"images/blur.bmp");
	iShowBMP(250,160,"images/credit.bmp");
	iShowBMP(380,60,"images/button8.bmp");
}


void Saveexit() // this is called when exit>yes is clicked
{
	freopen("data/savegame.dat","w",stdout);	
	
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			printf("%c",savearray[i][j]);
		}
		printf("\n");
	}

	printf("%d\n",savetime);
		
	puts(savedead1);
	puts(savedead2);

	puts(savename1);
	puts(savename2);
}


void Exit()
{
	iShowBMP(0,0,"images/exit.bmp");
	iShowBMP(194,230,"images/button6.bmp");
	iShowBMP(550,230,"images/button7.bmp");
}


void Timer()									
{
	tim++;
}


void Showtime()
{
	int t1,t2,t3,t4;
	
	t4=(tim/60)/10;
	t3=(tim/60)%10;
	t2=(tim%60)/10;
	t1=(tim%60)%10;

	times[7]=t4+48;
	iShowBMP(760,510,times);
	times[7]=t3+48;
	iShowBMP(800,510,times);
	times[7]=t2+48;
	iShowBMP(862,510,times);
	times[7]=t1+48;
	iShowBMP(902,510,times);
}


void DrawTextBox()
{	
	iShowBMP(0,0,"images/blur.bmp");

	if (rks==1)
	{
		iSetColor(218,165,32);
		iFilledRectangle(376,331, 308, 38);
	
		iSetColor(255,255,255);
		iText(376,380,"Player 1 name :",GLUT_BITMAP_TIMES_ROMAN_24);
		iFilledRectangle(380,335,300,30);
		iText(365, 10, "Press Tab when type is finished",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(0,0,0);
		iText(383,342,name1,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	else if (rks==2)
	{
		iSetColor(218,165,32);
		iFilledRectangle(376, 331, 308, 38);
	
		iSetColor(255,255,255);
		iText(376,380,"Player 2 name :",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0,0,0);
		iFilledRectangle(380,335,300,30);
		iSetColor(255,255,255);
		iText(365, 10, "Press Tab when type is finished",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255,255,255);
		iText(383,342,name2,GLUT_BITMAP_TIMES_ROMAN_24);
	}
}


void iDraw()
{
	iClear();
	
	if (mode==1) //new game
	{
	    if (rks<3) DrawTextBox();
		else 
		{
			Board();
			Piecesload();
			Deadpieces();
			Showtime();
			kaysar=1;
			Selrec();
			//Check();
		}
	}

	else if (mode==2) //exit
		Exit();

	else if (mode==3) //new game
	{
		if (counter<=7) Starting();
		else FrontPage();	
	}

	else if (mode==4) //credit
		Credit();

	else if (mode==5) //help
		Help();

	else if ((mode==6) && (x<=792)) //loading
	{
		iShowBMP(0,0,"images/loading.bmp");
		iSetColor(0,0,0);
		iFilledRectangle(100,25,800,20);
		iSetColor(255,255,255);
		iFilledRectangle(104,29,x,12);
		x+=66;
	}

	else if (mode==7) //new game from loading
	{
		Board();
		Piecesload();
		Deadpieces();
		Showtime();
		kaysar=1;
		Selrec();
		//Check();
	}

	if ((mode==6) && (x>792)) //game load
	{
		x=0;
		tim=savetime;
		mode=7;
	}	
}


void iMouseMove(int mx, int my)
{ 
}


void iMouse(int button, int state, int mx, int my)
{
		
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 
		
		//for new game
		if (mode==3 && mx>=380 && mx<=636 && my>=466 && my<=530)
		{
			for(int i=0;i<=7;i++)
				for(int j=0;j<=7;j++)
					parray[i][j]=dfltarray[i][j];

			
			for(i=0;i<=24;i++)
			{
				name1[i]=' ';
				name2[i]=' ';
			}
			
			for(i=0;i<=14;i++)
			{
				player1[i]='0';
				player2[i]='0';
			}

			p1=0;
			p2=0;
			mode=1;
			tmove=0;
			row=-1;
			column=-1;
			tim=0;
			rks=1;
			ctr=0;
		}
		
		//for exit
		else if(mode==3 && mx>=380 && mx<=636 && my>=170 && my<=234 && !kaysar)
			mode=2;
		
		//for exit > yes/no
		else if (mode==2)
		{
			if (mx>=194 && mx<=450 && my>=230 && my<=294) //exit > yes
			{
				Saveexit();
				exit(0);
			}
			else if (mx>=550 && mx<=806 && my>=230 && my<=294) //exit > no
				mode=3;
		}
				
		//for credit
		else if (mode==3 && mx>=380 && mx<=636 && my>=244 && my<=308 && !kaysar)
			mode=4;
		
		//return to frontpage from credits		
		else if (mode==4 && mx>=380 && mx<=636 && my>=60 && my<=124)
			mode=3;
		
		//for help
		else if (mode==3 && mx>=380 && mx<=636 && my>=318 && my<=382)
			mode=5;
		
		//return to frontpage from help
		else if (mode==5 && mx>=380 && mx<=636 && my>=60 && my <=124)
		{
			mode=3;
			page=1;
		}
		
		//help page access
		else if (mode==5 && page==1 &&  mx>=735 && mx<=754 && my>=136 && my<=152)
			page++;
		
		else if (mode==5 && page>=2 && page<=5 && mx>=735 && mx<=754 && my>=136 && my<=152)
			page++;
		
		else if (mode==5 && page>=2 && page<=5 && mx>=707 && mx<=724 && my>=136 && my<=151)
			page--;
		
		else if (mode==5 && page==6 &&  mx>=707 && mx<=724 && my>=136 && my<=151)
			page--;
		
		//load game
		else if (mode==3 && mx >= 380 && mx <= 636 && my >= 392 && my <=456 && !kaysar)
		{
			mode=6;

			for(int i=0;i<=7;i++)
				for(int j=0;j<=7;j++)
					parray[i][j]=savearray[i][j];
			
			for(i=0;i<=14;i++)
			{
				player1[i]=savedead1[i];
				player2[i]=savedead2[i];
			}

			for(i=0;i<=24;i++)
			{
				name1[i]=' ';
				name2[i]=' ';
			}

			strcpy(name1,savename1);
			strcpy(name2,savename2);

			p1=0;
			p2=0;
			tmove=0;
			tim=0;
			row=-1;
			column=-1;
			rks=1;
			ctr=0;
		}
		//return to main menu from new/load game
		else if((mode==1 || mode==7) && mx>=738 && mx<=956 && my>=115 && my<=156)
		{
			
			kaysar=0;
			mode=3;	
		}

		//for piece selection
		else if ((mode==1 || mode==7) && selected=='m' && mx>=46 && mx<=654 && my>=46 && my<=654)
		{
			column=(int)((mx-46)/76);
			row=(int)((654-my)/76);
			if (parray[row][column]!='0')
				if ((parray[row][column]>=97 && parray[row][column]<=102) && tmove%2==1)
				{
					selected=parray[row][column];
					PlaySound("sounds\\click.wav", NULL, SND_ASYNC);
				}
				else if ((parray[row][column]>=103 && parray[row][column]<=108) && tmove%2==0)
				{
					selected=parray[row][column];
					PlaySound("sounds\\click.wav", NULL, SND_ASYNC);
				}
		}

		//for selected piece movement
		else if ((mode==1 || mode==7) && selected!='m' && mx>=46 && mx<=654 && my>=46 && my<=654)
		{
			column2=(int)((mx-46)/76);
			row2=(int)((654-my)/76);
			next=parray[row2][column2];
			if (selected!='0')
			{
				if (selected>=97 && selected<=102)
				{	
					if (((next==48) || (next>=103 && next<=108)) && (tmove%2==1))
					{
						if (next!='0') 
						{
							guti=next;
							//PlaySound("sounds\\a.wav", NULL, SND_ASYNC);
							Number();
						}
						parray[row][column]='0';
						parray[row2][column2]=selected;
						tmove++;
						selected='m';
					}
					else if (next>=97 && next<=102)
					{
						selected=next;
						row=row2;
						column=column2;
					}
				}
				else if (selected>=103 && selected<=108)
				{	
					if (((next==48) || (next>=97 && next<=102)) && (tmove%2==0))
					{
						if (next!='0') 
						{
							guti=next;
							//PlaySound("sounds\\a.wav", NULL, SND_ASYNC);
							Number();
						}
						parray[row][column]='0';
						parray[row2][column2]=selected;
						tmove++;
						selected='m';
					}
					else if (next>=103 && next<=108)
					{
						selected=next;
						row=row2;
						column=column2;
					}
				}			
			}
		}
		
		//for save game
		else if ((mode==1 || mode==7) && mx>=738 && mx<=956 && my>=59 && my<=99)
		{
			Savegame();
		}

	}
	
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	} 
}


void iKeyboard(unsigned char key)
{
	if ((key==9) & (rks<3)) 
	{
		rks++;
		tim=0;
		ctr=0;
	}
	else if ((key==8) && (rks<3))
	{
		if (rks==1) 
		{
			if (ctr>=1) name1[--ctr]=' ';
		}
		else if (rks==2) 
		{
			if (ctr>=1) name2[--ctr]=' ';
		}
	}
	else
	{
		if (rks==1) name1[ctr++]=key;
		else if (rks==2) name2[ctr++]=key;
	}
	
}


void iSpecialKeyboard(unsigned char key)
{
}


int main()
{
	int i;
	
	freopen("data/savegame.dat","r",stdin);

	for(i=0;i<=63;i++)
	{
		cin>>savearray[i/8][i%8];
	}

	cin>>savetime;
	
	for(i=0;i<=14;i++)
	{
		cin>>savedead1[i]; 
	}

	for(i=0;i<=14;i++)
	{
		cin>>savedead2[i]; 
	}

	cin>>savename1;// problem:
	cin>>savename2;// 1 word er besi nai naa kan??
	
	iSetTimer(1000,Timer);

	iInitialize(1000, 700, "CHESS");	
	
	return 0;
}