#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<stdio.h>

	class highscore
	{
	public:
	char name[15][10];
	int scores[15];
	int temps[15];
	char nam[15];
	char temp2[15][10];
	int a;
	void compare(int score);
	}hsc;
	
	class brick_game
	{
	 private:
	   int x,y,i,j,m,l,r;
	   int k,f,p,t,u,v,a,b;
	   int brks[40][110];
	   int score;
	   int lives;
	   int count;
	   char levels[25][25];

	   void page();
	   void drawbrks();
	   void play();
	   void game();

	public:
	   int beep,speed;

	   void setspeed();
	   brick_game();
	   void beeponoff();
	   void drawcircl(int x,int y,int color);
	   void drawrect(int left,int top,int right,int bottom,int color);
	   void brkgame();

	}game;


	class pingpong:public brick_game
	{
	   int k,m,f,g;
	   int c,d;
	   int x,y;
	   int p;
	   int i,j;
	   int score1,score2;
	   char player1[30],player2[30];
	   void play();
	   void page();
	   void movepaddle();
	   void moveball();
	   void ballbounce();
	public:

	pingpong()
		{
		f=0,g=0;
		c=0,d=0;
		x=320,y=230;
		i=-1,j=-1;
		score1=0,score2=0;
		speed=1;
		}

	   void game();
	}pong;
	
	void main()
	{

	int ch,m=0,key;
	int driver,mode;
	driver=DETECT;
	initgraph(&driver,&mode,"");
	 clrscr();
	 cleardevice();

	 do{

	 setlinestyle(0,0,1);
	 setpalette(WHITE,27);
	rectangle(180,200,370,310);
	game.drawrect(190,225+m*20,360,240+m*20,BLUE);
	game.drawcircl(181,232+m*20,WHITE);
	game.drawcircl(369,232+m*20,WHITE);
	settextstyle(0,0,2);
		 outtextxy(200,180,"Main Menu");
	settextstyle(0,0,1);
	  outtextxy(230,230,"Arkanoid");
	 outtextxy(230,250,"PingPong");
	  outtextxy(230,270,"Exit");
	  delay(60);
	  key=0;
	if(kbhit())
	{
	cleardevice();

	key=getch();

	if(key==80)

	{if(m!=2)
	{m++;}
	 else
	 if(m==2)
	 {m=0;}}
	if(key==72)
	{if(m!=0)
	{m--;}
	 else
	 if(m==0)
	 {m=2;}}
	 }
	if(key==13)
	{
	switch(m+1)
	 {


	 case 1:game.brkgame();
		break;
	 case 2:pong.game();
		break;

	 case 3: exit(0);
		 break;
	}
	cleardevice();
	}

	}while(key!=27);

	}
	void highscore::compare(int score)
	{    a=0;
	 for(int i=0;i<13;i++)
	 {
	  if(scores[i]<score)
	 {   a=1;
	 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	  settextstyle(0,0,2);
	  outtextxy(100,100,"You have set a High score !!");
	   settextstyle(0,0,1);
	  outtextxy(120,195,"Enter Your Name:");
	   cin>>nam;
	 break; }
	  }
	  if(a==1)
	 { temps[i]=scores[i];
	  scores[i]=score;
	  strcpy(temp2[i],name[i]);
	  strcpy(name[i],nam);

	while(i<12)
	 {
	  temps[i+1]=scores[i+1];
	  scores[i+1]=temps[i];
	  strcpy(temp2[i+1],name[i+1]);
	  strcpy(name[i+1],temp2[i]);
	  i++;
	  }}
	}

	brick_game::brick_game()
	{
		x=610,y=30,m=10,l=200,r=300;
		f=1,u=0;
		score=0;
		count=0;
		speed=5;
		strcpy(levels[0],"LEVEL 1");strcpy(levels[1],"LEVEL 2");strcpy(levels[2],"LEVEL 3");
		strcpy(levels[3],"LEVEL 4");strcpy(levels[4],"LEVEL 5");strcpy(levels[5],"LEVEL 6");
		strcpy(levels[6],"LEVEL 7");strcpy(levels[7],"LEVEL 8");strcpy(levels[8],"LEVEL 9");
	}
	 void brick_game::drawcircl(int x,int y,int color)
	{
	circle(x,y,5);
	setfillstyle(SOLID_FILL,color);
	floodfill(x,y,color);
	}
	void brick_game::drawrect(int left,int top,int right,int bottom,int color)
	{
	setfillstyle(SOLID_FILL,color);
	bar(left,top,right,bottom);
	}
	void brick_game::page()
	{settextstyle( DEFAULT_FONT, HORIZ_DIR,1);
	   rectangle(10,30,getmaxx(),getmaxy());
	   settextstyle(0,0,1);
	   outtextxy(220,5,"LIVES-");setfillstyle(SOLID_FILL,WHITE);for(p=0;p<lives-1;p++){bar(280+p*30,5,300+p*30,10);}
	   outtextxy(50,5,"SCORE-");
	   outtextxy(460,5,levels[u-1]);

	 }

	 void brick_game::setspeed()
	{
	speed=5;
	int k=0;

	 do{

	 if(kbhit())
	{ cleardevice();
	  k=getch();
	   if(k==77 && speed!=10)
	   {speed++;}
	   if(k==75 && speed!=1)
	   {speed--;}
	}
	 settextstyle(0,0,3);
	 outtextxy(230,250,"SPEED");
	 if(speed==1)
	 outtextxy(360,250,"1");
	 if(speed==2)
	 outtextxy(360,250,"2");
	 if(speed==3)
	 outtextxy(360,250,"3");
	 if(speed==4)
	 outtextxy(360,250,"4");
	 if(speed==5)
	 outtextxy(360,250,"5");
	 if(speed==6)
	 outtextxy(360,250,"6");
	 if(speed==7)
	 outtextxy(360,250,"7");
	 if(speed==8)
	 outtextxy(360,250,"8");
	 if(speed==9)
	 outtextxy(360,250,"9");
	 if(speed==10)
	 outtextxy(360,250,"10");


	 settextstyle(0,0,1);
	}while(k!=13);

	}
	 void brick_game::beeponoff()
	{

	 int k=0;
	 do{

	 if(kbhit())
	{ cleardevice();
	  k=getch();
	   if(k==75)
	   beep=0;
	   if(k==77)
	   beep=1;
	}
	 settextstyle(0,0,3);
	 outtextxy(230,250,"SOUND");
	 if(beep==0)
	 outtextxy(360,250,"OFF");
	 if(beep==1)
	 outtextxy(360,250,"ON");
	  settextstyle(0,0,1);
	}while(k!=13);
	if(beep==1)
	{sound(400);delay(200); nosound();sound(600);delay(300); nosound();}
	}
	void brick_game::drawbrks()
	{
	 for(t=0;t<71;t=t+35)
	  { for(p=0;p<=400;p=p+40)
	  {
	if(brks[t/35][p/40]==1)
	{drawrect(120+p,85+t,150+p,115+t,WHITE);}
	}}
	}

	void brick_game::play()
	{

	drawbrks();
	page();
	if(x>609)
	i=-1;
	if(x<21)
	i=1;
	x+=i*speed;
	if(y<41)
	j=1;
	y+=j*speed;
	if(y>=445)
	{
	for(p=0;p<101;p=p+1)
	{
	if((l+m)+p==x && f==1)
	{i=1;j=-1; if(beep==1)sound(600);delay(23); nosound();
	}
	if((l+m)+p==x && f==0)
	{i=-1;j=-1;if(beep==1)sound(600);delay(23); nosound();
	}
	}
	}
	drawcircl(x,y,WHITE);
	delay(16);
	drawcircl(x,y,BLACK);
	if(kbhit())

	k=getch();
	if((r+m)<630 && f==1)
	{
	m=m+speed;
	}
	if((l+m)>10 && f==0)
	{
	m=m-speed;
	}
	if(k==75)
	{f=0;}
	if(k==77)
	{f=1;}
	setfillstyle(SOLID_FILL,WHITE);
	bar(l+m,445,r+m,460);
	floodfill(l+m,450,WHITE);
	setfillstyle(0,BLACK);
	if(f==1)
	bar(l+m-(110),445,r+m-(110),460);
	if(f==0)
	bar(l+m+(110),445,r+m+(110),460);
	for(t=1;t<=71;t=t+35)
	  { for(p=1;p<=401;p=p+40)
		{	if(brks[t/35][p/40]==1&&(x+2)>=(120+p)&&(x-2)<=(150+p)&&(y+6)>=(85+t)&&(y-6)<=(115+t))
		{clrscr();
		 cleardevice();
		if(beep==1){sound(400);delay(23); nosound();}
		 count++;
		 score=score+speed;
		 cout<<"\t\t    "<<score;

		if((t/35)!=1)
	   { i=1*i; j=-1*j;brks[t/35][p/40]=0;}
		else
	   { i=-1*i; j=1*j;brks[t/35][p/40]=0;}
		   }
		   }}
	}
	  void brick_game::game()
	{
	ifstream ifile;
	ofstream ofile;
	int driver,mode;
	   driver=DETECT;
	   initgraph(&driver,&mode,"");

	lives=4;
	u=0;
	score=0;

	level:

	setpalette(WHITE,10+u);
	   count=0;
	   u++;
	   for(b=0;b<=2;b++)
	  {for(a=0;a<=10;a++)brks[b][a]=1; }
	while(lives>0)
	{   clrscr();
		cleardevice();
		i=1;j=-1;
		x=(l+m+50);y=436;
		if(count!=0)
	  {  lives--;}
	 if(lives==0)
	break;
	   page();
	   bar(l+m,445,r+m,460);
	   drawcircl(x,y,WHITE);
	   drawbrks();

	   cout<<"\t\t   "<<score;
	   if(k!=27)
	   getch();
	   drawcircl(x,y,BLACK);
	do
	{
	if(lives==0)
	break;
	{play();
	if(k==112)
	{
	settextstyle(0,0,3);
	outtextxy(250,300,"PAUSE");
	getch();
	cleardevice();
	}
	}
	   if(count==33)
	   goto level;

	}while(k!=27 && y<460 && count!=33);
	if(lives<=1)
	{
	setcolor(BLACK);
	for(int i=450;i>=0;i--)
	{
	 circle(331,251,i);
	 circle(329,249,i);
	 circle(335,255,i);

	}
	setcolor(WHITE);
	}

	}


	settextstyle(0,0,3);
	outtextxy(230,250,"GAME OVER");
	getch();
	cleardevice();
	settextstyle(0,0,1);
	ifile.open("HISCORE.dat",ios::beg,ios::binary);
		   ifile.seekg(0,ios::beg);
		   ifile.read((char*)&hsc,sizeof(hsc));
		   hsc.compare(score);
		   ifile.close();
		   ofile.open("HISCORE.dat",ios::beg,ios::binary);
		   ofile.write((char*)&hsc,sizeof(hsc));


	clrscr();
	cleardevice();

	}
	void brick_game::brkgame()
	{

	  int gdriver=DETECT,gmode,errorcode;
	  initgraph(&gdriver,&gmode,"");
	  int ch;
	  int a=0;
	  int key=0;
	  int m=0;
	  ifstream ifile;

	do{
	  setpalette(WHITE,27);
	  settextstyle(0,0,3);
	  setcolor(LIGHTBLUE);
	  outtextxy(183,165,"ARKANOID");
	  setcolor(WHITE);
	  settextstyle(0,0,1);

	rectangle(180,200,370,370);
	drawrect(190,225+m*20,360,240+m*20,BLUE);
	drawcircl(181,232+m*20,WHITE);
	drawcircl(369,232+m*20,WHITE);

	  outtextxy(230,230,"New Game");
	  outtextxy(230,250,"Hiscores");
	  outtextxy(230,270,"Speed");
	  outtextxy(230,290,"Sound");
	  outtextxy(230,310,"Instructions");
	  outtextxy(230,330,"Exit");

	   key=0;

	if(kbhit())
	{cleardevice();


	key=getch();

	if(key==80)

	{if(m!=5)
	{m++;}
	 else
	 if(m==5)
	 {m=0;}}
	if(key==72)
	{if(m!=0)
	{m--;}
	 else
	 if(m==0)
	 {m=5;}}

	}

	if(key==13)
	{
	switch(m+1)
	 {
	case 1:
		game();
		break;

	case 2:setpalette(WHITE,11);
		   setpalette(7,WHITE);
		   cout<<"\n";
		   a=0;
		   settextstyle(0,0,3);
		   outtextxy(230,20,"HI-SCORES");
		   settextstyle(0,0,1);
		   ifile.open("HISCORE.dat",ios::beg,ios::binary);
		   ifile.seekg(0,ios::beg);
		   ifile.read((char*)&hsc,sizeof(hsc));
	for(int i=0;i<13;i++)
	 {for(int j=0;j<strlen(hsc.name[i]);j++)
	 {
	 hsc.name[i][j]=toupper(hsc.name[i][j]);
	} }
	for(i=0;i<13;i++)
	{ a++;
	 cout<<"\n\n\t\t\t\t\t\t\t\t\t"<<hsc.scores[i];
	 outtextxy(100,35+(a*30),"...........................................................");
	 outtextxy(50,35+(a*30),hsc.name[i]);
	 }
	ifile.close();
	getch();
	break;

	case 3:
		clrscr();
		cleardevice();
		setspeed();
		break;

	case 4:clrscr();
		   cleardevice();
		   beeponoff();
		   break;

	case 5: clrscr();
		cleardevice();
		settextstyle(0,0,2);
		outtextxy(13,100,"Instructions");
		settextstyle(0,0,1);
		outtextxy(14,130,"The objective of the game is to break all bricks and proceed to the next level.");
		outtextxy(14,140,"Move the bat using left or right arrow key.Scoring depends on the speed which");
		outtextxy(14,150,"you have chosen.Each brick you hit adds points equal to the speed.To quit the");
		outtextxy(14,160,"game in between press ESC.");
		getch();
		break;

	case 6:
		a=1;
		break;
	 }
	 clrscr();
	 cleardevice();
	}
	}while(a!=1);
	}

	void pingpong::page()
	{
	  cout<<"\t\t\t\t"<<score1;
	   cout<<"\t\t"<<score2;
	   settextstyle(0,0,3);
	   outtextxy(300,20,"VS");
	   settextstyle(0,0,1);
	   outtextxy(200,5,"Score- ");
	   outtextxy(400,5,"-Score");
	   outtextxy(100,10,player1);
	   outtextxy(500,10,player2);
	   setpalette(WHITE,10);
	   setlinestyle(0,1,1);
	   rectangle(0,30,getmaxx(),getmaxy());
	   setlinestyle(4,10,1);
	   circle(320,230,70);
	   circle(320,230,7) ;
	   line(320,10,320,160);
	   line(320,490,320,310);

	}
	 void pingpong::movepaddle()
	{

	if(kbhit())
	{

	k=getch();
	if(k==72)
	{f=0;}
	 if(k==80)
	{f=1;}
	 if(k==119)
	{g=0;}
	 if(k==115)
	{g=1;}
	}
	if((300+c)<480 && f==1)
	{
	c=c+(5+speed);
	}
	if((200+c)>40 && f==0)
	{
	c=c-(5+speed);
	}
	if((300+d)<480 && g==1)
	{
	d=d+(5+speed);
	}
	if((200+d)>40 && g==0)
	{
	d=d-(5+speed);
	}

	drawrect(50,200+c,60,300+c,WHITE);
	delay(5);
	setfillstyle(0,BLACK);
	if(f==1)
	drawrect(40,200+c-100,70,300+c-100,BLACK);
	if(f==0)
	drawrect(40,200+c+100,70,300+c+100,BLACK);

	drawrect(570,200+d,580,300+d,WHITE);
	delay(5);

	setfillstyle(0,BLACK);
	if(g==1)
	drawrect(550,200+d-100,590,300+d-100,BLACK);
	if(g==0)
	drawrect(550,200+d+100,590,300+d+100,BLACK);

	}
	void pingpong::moveball()
	{
	drawcircl(x,y,WHITE);
	delay(20);
	drawcircl(x,y,BLACK);
	if(x>609)
	i=-1;
	if(x<21)
	i=1;
	x+=i*(9+speed);
	if(y<40)
	j=1;
	if(y>460)
	j=-1;
	y+=j*3;
	}
	void pingpong::ballbounce()
	{
	 if(x<=70)
	{
	for(p=0;p<=100;p=p+1)
	{
	if((200+c)+p==y && f==1)
	{i=1;j=1;if(beep==1){ sound(600);delay(23); nosound(); }
	}
	if((200+c)+p==y && f==0)
	{i=1;j=-1;if(beep==1){ sound(600); delay(20);nosound();}
	}

	}
	}
	if(x>=570)
	{
	for(p=0;p<=100;p=p+1)
	{
	if((200+d)+p==y && g==1)
	{i=-1;j=1;if(beep==1){sound(600);delay(20); nosound();}
	}
	if((200+d)+p==y && g==0)
	{i=-1;j=-1;if(beep==1){sound(600);delay(20);nosound();}
	}
	}
	}
	}
	void pingpong::play()

	 {
	   if(x<40)
	   score2++;
	   if(x>550)
	   score1++;
	   clrscr();

	   cleardevice();
	   page();
	   d=0;c=0;
	   drawrect(50,200+c,60,300+c,WHITE);
	   drawrect(570,200+d,580,300+d,WHITE);
	   i=-1*i;j=-1*j;
	   x=320;y=230;

	drawcircl(x,y,WHITE);
	k=getch();
	if(k==13)
	 do{

	   setpalette (WHITE,10);
	   setlinestyle(0,1,1);
	   rectangle(0,30,getmaxx(),getmaxy());
	   setlinestyle(4,10,1);
	   circle(320,230,70) ;
	   circle(320,230,7) ;

	   line(320,10,320,160);
	   line(320,490,320,310);

	  movepaddle();
	  moveball();
	  ballbounce();

	}while(x>30 && x<580);
	}

	 void pingpong::game()
		   {

	   int driver,mode;
	   driver=DETECT;
	   initgraph(&driver,&mode,"");
		   cleardevice();
		 int key;
		 int a=0;
	do{
	  setpalette(WHITE,27);
	  settextstyle(0,0,3);
	  setcolor(2);
	  outtextxy(167,165,"PING PONG");
	  setcolor(WHITE);
	  settextstyle(0,0,1);
	  setlinestyle(0,0,0);
	rectangle(180,200,370,350);
	drawrect(190,225+m*20,360,240+m*20,BLUE);
	drawcircl(181,232+m*20,WHITE);
	drawcircl(369,232+m*20,WHITE);

	  outtextxy(230,230,"New Game");
	  outtextxy(230,250,"Sound");
	  outtextxy(230,270,"Speed");
	  outtextxy(230,290,"Instructions");
	  outtextxy(230,310,"Exit");

	key=0;

	if(kbhit())
	{
	cleardevice();

	key=getch();

	if(key==80)

	{if(m!=4)
	{m++;}
	 else
	 if(m==4)
	 {m=0;}}
	if(key==72)
	{if(m!=0)
	{m--;}
	 else
	 if(m==0)
	 {m=4;}}

	 }
	if(key==13)
	{
	switch(m+1)
	 {
	case 1:
		score1=0;score2=0;
	  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ";
	  outtextxy(220,200,"Enter first players name");
	  rectangle(260,215,390,240);
	  gets(player1);
	  cout<<"\n\n\t\t\t\t  ";
	  outtextxy(220,250,"Enter second players name");
	  rectangle(260,265,390,290);
	  gets(player2);
	 do{
		   play();
		if(score1==10)
	  {
	   settextstyle(0,0,3);
	   outtextxy(250,190,player1);
	   outtextxy(263,240," WINS ");
	   getch();
	   break;
	  }
		if(score2==10)
	  {
	   settextstyle(0,0,3);
	   outtextxy(250,190,player2);
	   outtextxy(263,240," WINS ");
	   getch();
	   break;
	  }



	}while(k!=27);
		break;

	case 2:clrscr();
		   cleardevice();
		   beeponoff();
	break;
	case 3:
		clrscr();
		cleardevice();
		setspeed();
		break;



	case 4: clrscr();
		cleardevice();
		settextstyle(0,0,2);
		outtextxy(13,100,"Instructions");
		settextstyle(0,0,1);
		outtextxy(14,130,"This is a 2-player game.This game is almost like playing ping-pong.You have to");
		outtextxy(14,140,"make sure that you dont miss the ball.If the opposite player misses the ball");
		outtextxy(14,150,"You score a point.Score 10 points to win the game.To quit the game in between");
		outtextxy(14,160,"press ESC.");
		settextstyle(0,0,2);
		outtextxy(14,180,"Game controls:");
		settextstyle(0,0,1);
		outtextxy(10,210,"Player 1 ");
		outtextxy(300,210,"Player 2 ");
		outtextxy(10,240,"UP arrow");
		outtextxy(10,260,"DOWN arrow");
		outtextxy(330,240,"W");
		outtextxy(330,260,"S");

		getch();
		break;

	case 5:
		a=1;
		break;
	 }

	 clrscr();
	 cleardevice();
	}
	}while(a!=1);
	}