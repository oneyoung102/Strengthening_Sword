#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <conio.h>    //kbhit()
#include <vector>
#include <math.h>

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

int i,j,p,q;
int click,manu_select,str_select,swo_select,per_select;
int level=0,power=0,hardness=0,sharpness=0;
int basic_dam;
int damage,variability,critical;
char name[10];
char sword_length=0;
int pow_str_per[15]={90,79,74,69,62,57,52,47,42,37,32,30,27,25,22};
int pow_fail_per[15]={10,13,17,19,24,27,27,32,34,35,35,35,35,35,35};
int pow_degrade_per[15]={0,3,4,6,8,8,13,13,16,18,20,20,22,24,27};

int har_str_per[15]={95,86,81,76,66,64,61,54,50,46,41,38,36,34,31};
int har_fail_per[15]={5,5,6,7,15,15,15,18,20,20,22,23,23,23,23};
int har_degrade_per[15]={0,9,13,15,17,17,20,20,21,23,25,25,27,29,32};

int sha_str_per[15]={95,91,87,82,74,68,59,52,46,43,39,34,30,25,20};
int sha_fail_per[15]={5,7,10,15,18,20,25,25,30,30,30,31,33,35,35};
int sha_degrade_per[15]={0,2,3,3,6,9,13,15,15,16,18,20,22,25,30};





using namespace std;
std::string Path = "text.txt";
std::ifstream readFile(Path);
std::ofstream writeFile(Path);
ofstream fout;
ifstream fin;

/////////////////////////////////////////////////////////////////////////
void textcolor(int foreground, int background) //글자색 
{ 
int color=foreground+background*16; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}


void Gotoxy(int x, int y)          //gotxy
{
	COORD Pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
void Cursorview()             //커서 삭제 
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
void Write(int foreground, int background, int x, int y, char data[10000]){
	textcolor(foreground,background);
	Gotoxy(x,y);
	cout<<data;
}
void int_Write(int foreground, int background, int x, int y, int* data){
	textcolor(foreground,background);
	Gotoxy(x,y);
	cout<<*data;
}


void Start_sword(int x, int y){
			Write(BROWN,BLACK,x,y,"■");
	Write(DARKGRAY,BLACK,x-2,y,"〓");
	Write(DARKGRAY,BLACK,x-4,y,"■");
	Write(DARKGRAY,BLACK,x-4,y-1,"▲");
	Write(DARKGRAY,BLACK,x-4,y+1,"▼");
	Write(LIGHTGRAY,LIGHTGRAY,x-19,y,"abcdefghijklmop");
	Write(LIGHTGRAY,BLACK,x-20,y,"◀");		
}

void Sword(int x, int y, int sword){
	if(sword==0){
		Write(BROWN,BLACK,x,y,"※");
	Write(DARKGRAY,BLACK,x-2,y,"〓");
	Write(DARKGRAY,BLACK,x-4,y,"■");
	Write(DARKGRAY,BLACK,x-4,y-1,"△");
	Write(DARKGRAY,BLACK,x-4,y+1,"※");
	Write(LIGHTGRAY,BLACK,x-15,y,"▒▒▒▧▒▒▧▒▒");
	Write(LIGHTGRAY,BLACK,x-20,y,"   ◁");
	Write(LIGHTRED,BLACK,x-6,y-1,"  ");
	Write(LIGHTRED,BLACK,x-6,y+1,"  ");	
	Write(LIGHTRED,BLACK,x-7,y-1,"  ");
	Write(LIGHTRED,BLACK,x-7,y+1,"  ");		
	}
else{
	if(hardness>=0&&hardness<=1)
	Write(BROWN,BLACK,x,y,"■");
	else if(hardness>=2&&hardness<=4)
	Write(BROWN,BLACK,x,y,"▣");
	else if(hardness>=5&&hardness<=8)
	Write(BROWN,BLACK,x,y,"ⓞ");
	else if(hardness>=9&&hardness<=11)
	Write(LIGHTRED,BLACK,x,y,"ⓞ");
	else if(hardness>=12&&hardness<=14)
	Write(LIGHTRED,BLACK,x,y,"⊙");
	else if(hardness==15)
	Write(LIGHTMAGENTA,BLACK,x,y,"⊙");
	
	if(hardness>=0&&hardness<=8)
	Write(DARKGRAY,BLACK,x-2,y,"〓");
	else if(hardness>=9&&hardness<=14)
	Write(RED,BLACK,x-2,y,"〓");
	else if(hardness==15)
	Write(MAGENTA,BLACK,x-2,y,"〓");
	
	if(power>=0&&power<=3)
	Write(DARKGRAY,BLACK,x-4,y,"■");
	else if(power>=4&&power<=8)
	Write(DARKGRAY,BLACK,x-4,y,"▣");
	else if(power>=9&&power<=11)
	Write(LIGHTRED,BLACK,x-4,y,"▣");
	else if(power>=12&&power<=14)
	Write(LIGHTRED,BLACK,x-4,y,"▩");
	else if(power==15)
	Write(LIGHTMAGENTA,BLACK,x-4,y,"▩");
	
	if(power>=0&&power<=2){
	Write(DARKGRAY,BLACK,x-4,y-1,"▲");
	Write(DARKGRAY,BLACK,x-4,y+1,"▼");		
	}
	else if(power>=3&&power<=7){
	Write(DARKGRAY,BLACK,x-4,y-1,"△");
	Write(DARKGRAY,BLACK,x-4,y+1,"▽");		
	}
	else if(power>=8&&power<=11){
	Write(RED,BLACK,x-4,y-1,"△");
	Write(RED,BLACK,x-4,y+1,"▽");	
	Write(LIGHTRED,BLACK,x-6,y-1,"↙");
	Write(LIGHTRED,BLACK,x-6,y+1,"↖");		
	}
    else if(power>=12&&power<=14){
	Write(RED,BLACK,x-4,y-1,"△");
	Write(RED,BLACK,x-4,y+1,"▽");	
	Write(LIGHTRED,BLACK,x-6,y-1,"↙");
	Write(LIGHTRED,BLACK,x-6,y+1,"↖");	
	Write(LIGHTRED,BLACK,x-7,y-1,"↙");
	Write(LIGHTRED,BLACK,x-7,y+1,"↖");		
	}
	else if(power==15){
	Write(MAGENTA,BLACK,x-4,y-1,"△");
	Write(MAGENTA,BLACK,x-4,y+1,"▽");	
	Write(LIGHTMAGENTA,BLACK,x-6,y-1,"↙");
	Write(LIGHTMAGENTA,BLACK,x-6,y+1,"↖");	
	Write(LIGHTMAGENTA,BLACK,x-7,y-1,"↙");
	Write(LIGHTMAGENTA,BLACK,x-7,y+1,"↖");		
	}
	if(sharpness>=0&&sharpness<=2)
	Write(LIGHTGRAY,LIGHTGRAY,x-15,y,"abcdefghijk");
	else if(sharpness>=3&&sharpness<=5){
	Write(DARKGRAY,LIGHTGRAY,x-15,y,"=-=-===-=-=");	
	}
	else if(sharpness>=6&&sharpness<=9){
	Write(RED,LIGHTGRAY,x-15,y,"=-=-===-=-=");	
	}
	else if(sharpness>=10&&sharpness<=12){
	Write(RED,LIGHTGRAY,x-15,y,"=-=-===◁▤");	
	}
	else if(sharpness>=13&&sharpness<=14){
	sword_length=3;
	Write(RED,LIGHTGRAY,x-15-sword_length,y,"▷ =-===-=◁▤");	
	}
	else if(sharpness==15){
		sword_length=3;
	Write(LIGHTMAGENTA,LIGHTGRAY,x-15-sword_length,y,"▷ =-===-=◁▤");	
	}
	
	else if(sharpness>=0&&sharpness<=2)
	Write(LIGHTGRAY,LIGHTGRAY,x-15,y,"abcdefghijk");
	else if(sharpness>=0&&sharpness<=2)
	Write(LIGHTGRAY,LIGHTGRAY,x-15,y,"abcdefghijk");

	
	if(power>=0&&power<=2)
	Write(LIGHTGRAY,BLACK,x-17-sword_length,y," ◀");	
	else if(power>=3&&power<=7)
	Write(LIGHTGRAY,BLACK,x-17-sword_length,y," ≪");	
	else if(power>=8&&power<=11)
	Write(RED,BLACK,x-17-sword_length,y," ≪");	
	else if(power>=12&&power<=14)
	Write(RED,BLACK,x-17-sword_length,y,"<≪");	
	else if(power==15)
	Write(MAGENTA,BLACK,x-17-sword_length,y,"<≪");	
}
	
}
void Human(int color, int x){
	Write(color,BLACK,6+x,3,"┌──┐ ");
	Write(color,BLACK,6+x,4,"│..│ ");
	Write(color,BLACK,4+x,5,"┌─┘  └─┐ ");
	Write(color,BLACK,4+x,6,"│      │ ");
	Write(color,BLACK,4+x,7,"│      │ ");
	Write(color,BLACK,4+x,8,"└─┐  ┌─┘ ");
	Write(color,BLACK,6+x,9,"│  │ ");
	Write(color,BLACK,6+x,10,"│  │ ");
	Write(color,BLACK,6+x,11,"└──┘ ");
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

int main(){
vector<string> level_name = {"ε   ","ε+","ε++","ε+++","υ   ","υ+ ","υ++","υ+++","κ   ","κ+  ","κ++ ","κ+++","ζ   ","ζ+  ","ζ++ ","ζ+++","ω   ","ω+  ","ω++ ","ω+++","σ   ","σ+  ","σ++ ","σ+++"};	 
//////////////////////////////// 
Cursorview();
////////////////////////////////
i=-3;
j=6;
while(i<=11){
system("cls");
Write(WHITE,BLACK,2,3,"◎》=-==-==-===-==-==-=《◎");
Write(WHITE,BLACK,2,9,"◎》=-==-==-===-==-==-=《◎");
Start_sword(35-i,j);
Write(WHITE,BLACK,1.9*i+5,3,"《◎                        ");
Write(WHITE,BLACK,1.9*i+5,9,"《◎                        ");
Sleep(5);
i+=2;
}
//////////////////////////////////////////////
Write(LIGHTRED,BLACK,2,6,"≫");
Sleep(25);
Write(LIGHTRED,BLACK,0,6,"≫");
Sleep(25);
Write(LIGHTRED,BLACK,2,5,"※");
Write(LIGHTRED,BLACK,2,7,"※");
Sleep(50);
Write(LIGHTRED,BLACK,2,6,"  ");
Sleep(10);
Write(LIGHTRED,BLACK,0,6,"  ");
Sleep(10);
Write(LIGHTRED,BLACK,2,5,"  ");
Write(LIGHTRED,BLACK,2,7,"  ");
Sleep(70);
///////////////////////////////////////////
Write(LIGHTRED,BLACK,6,5,"∨");
Write(LIGHTRED,BLACK,6,7,"∧");
Write(BLACK,LIGHTGRAY,6,6,"Ｓ");
Sleep(20);
Write(LIGHTRED,BLACK,6,5,"  ∨");
Write(LIGHTRED,BLACK,6,7,"  ∧");
Write(BLACK,LIGHTGRAY,8,6,"Ｗ");
Sleep(20);
Write(LIGHTRED,BLACK,8,5,"  ∨");
Write(LIGHTRED,BLACK,8,7,"  ∧");
Write(BLACK,LIGHTGRAY,10,6,"Ｏ");
Sleep(20);
Write(LIGHTRED,BLACK,10,5,"  ∨");
Write(LIGHTRED,BLACK,10,7,"  ∧");
Write(BLACK,LIGHTGRAY,12,6,"Ｒ");
Sleep(20);
Write(LIGHTRED,BLACK,12,5,"  ∨");
Write(LIGHTRED,BLACK,12,7,"  ∧");
Write(BLACK,LIGHTGRAY,14,6,"Ｄ");
Sleep(20);
Write(LIGHTRED,BLACK,14,5,"  ");
Write(LIGHTRED,BLACK,14,7,"  ");
////////////////////////////////////////////////
Sleep(230);
Write(WHITE,BLACK,6,7,"St");
Sleep(20);
Write(WHITE,BLACK,8,7,"re");
Sleep(20);
Write(WHITE,BLACK,10,7,"ng");
Sleep(20);
Write(WHITE,BLACK,12,7,"th");
Sleep(20);
Write(WHITE,BLACK,14,7,"en");
Sleep(20);
Write(WHITE,BLACK,16,7,"in");
Sleep(20);
Write(WHITE,BLACK,17,7,"ng");
Sleep(20);
////////////////////////////////////////////////
i=0;
while(1){
	Sleep(250);
	Write(WHITE,BLACK,3,11,"   Press 'q' To Start  ");
	if(kbhit()){
		click=_getch();
		if(click=='q'){
			goto Manu;
		}
	}
	Sleep(250);
	Write(WHITE,BLACK,3,11,"                       ");
	////////////////////////////////////////////////
}
manu_select=0;
Manu :
system("cls");

while(1){
	if(manu_select%3==0){
		Write(WHITE,BLACK,5,2,"◎》=-====-=《◎");
	Write(WHITE,BLACK,5,3,"｝ Strengthen ｛");
	Write(WHITE,BLACK,5,4,"◎》=-====-=《◎");
	}
	else{
		Write(DARKGRAY,BLACK,5,2,"◎》=-====-=《◎");
	Write(DARKGRAY,BLACK,5,3,"｝ Strengthen ｛");
	Write(DARKGRAY,BLACK,5,4,"◎》=-====-=《◎");
	}
	if(manu_select%3==1){
		Write(WHITE,BLACK,5,6,"◎》=-====-=《◎");
	Write(WHITE,BLACK,5,7,"｝   Swords   ｛");
	Write(WHITE,BLACK,5,8,"◎》=-====-=《◎");
	}
	else{
		Write(DARKGRAY,BLACK,5,6,"◎》=-====-=《◎");
	Write(DARKGRAY,BLACK,5,7,"｝   Swords   ｛");
	Write(DARKGRAY,BLACK,5,8,"◎》=-====-=《◎");
	}
	if(manu_select%3==2){
	    Write(WHITE,BLACK,5,10,"◎》========《◎");
	Write(WHITE,BLACK,5,11,"｝Probability｛");
	Write(WHITE,BLACK,5,12,"◎》========《◎");
	}
	else{
		Write(DARKGRAY,BLACK,5,10,"◎》=-====-=《◎");
	Write(DARKGRAY,BLACK,5,11,"｝Probability｛");
	Write(DARKGRAY,BLACK,5,12,"◎》=-====-=《◎");
	}
	if(manu_select%3==0){
		Write(LIGHTGRAY,BLACK,23,3,"<==}");
		Write(DARKGRAY,BLACK,27,3,"=");
		Write(BROWN,BLACK,28,3,"0");
		Write(LIGHTGRAY,BLACK,21,7,"         ");
		Write(LIGHTGRAY,BLACK,21,11,"        ");
	}
	else if(manu_select%3==1){
		Write(LIGHTGRAY,BLACK,23,7,"<==}");
		Write(DARKGRAY,BLACK,27,7,"=");
		Write(BROWN,BLACK,28,7,"0");
		Write(LIGHTGRAY,BLACK,21,11,"         ");
		Write(LIGHTGRAY,BLACK,21,3,"        ");
	}
	else if(manu_select%3==2){
		Write(LIGHTGRAY,BLACK,23,11,"<==}");
		Write(DARKGRAY,BLACK,27,11,"=");
		Write(BROWN,BLACK,28,11,"0");
		Write(LIGHTGRAY,BLACK,21,7,"         ");
		Write(LIGHTGRAY,BLACK,21,3,"        ");
	}
	
	Write(WHITE,BLACK,4,15,"w/s : Up/Down");
	Write(WHITE,BLACK,4,16,"q : Select");
	
	if(kbhit()){
		click=_getch();
		if(click=='w'){
			if(manu_select>=0)
		    	manu_select-=1;
		    if(manu_select<0)
		    	manu_select=2;
		}
		else if(click=='s'){
			manu_select+=1;
		}
		else if(click=='q'){
			if(manu_select%3==0){
				level=0;
			power=0;
			hardness=0;
			sharpness=0;
			sword_length=0;
			goto Strengthen;
			}
			
			else if(manu_select%3==1)
			goto Sword;
			else if(manu_select%3==2)
			goto Probability;
		}
	}
}
////////////////////////////////////////////////
////////////////////////////////////////////////
Probability :
	per_select=0;
	system("cls");
Re_probability :
	Write(WHITE,BLACK,2,5,"    Probability(%)   | ");
	j=1;
while(j<=per_select){
	Write(BROWN,BLACK,5*j+19,5," ◎  ");
	j+=1;
}
j=1;
while(j<=15-per_select){
Write(WHITE,BLACK,5*(16-j)+19,5," ○  ");
	j+=1;	
}
	Write(WHITE,BLACK,2,7,"   Power Stregthen   | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		int_Write(WHITE,BLACK,5*i+25,7,&pow_str_per[i]);
		else if(per_select!=i)
		int_Write(DARKGRAY,BLACK,5*i+25,7,&pow_str_per[i]);
		Write(WHITE,BLACK,5*i+27,7," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,8,"     Power Fail      | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,8);
		if(pow_fail_per[i]>=10)
		cout<<pow_fail_per[i];
		else if(pow_fail_per[i]<10)
		cout<<" "<<pow_fail_per[i];
		Write(WHITE,BLACK,5*i+27,8," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,9,"    Power Degrade    | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,9);
		if(pow_degrade_per[i]>=10)
		cout<<pow_degrade_per[i];
		else if(pow_degrade_per[i]<10)
		cout<<" "<<pow_degrade_per[i];
		Write(WHITE,BLACK,5*i+27,9," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,10,"    Power Destroy    | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,10);
		if(100-pow_str_per[i]-pow_fail_per[i]-pow_degrade_per[i]>=10)
		cout<<100-pow_str_per[i]-pow_fail_per[i]-pow_degrade_per[i];
		else if(100-pow_str_per[i]-pow_fail_per[i]-pow_degrade_per[i]<10)
		cout<<" "<<100-pow_str_per[i]-pow_fail_per[i]-pow_degrade_per[i];
		Write(WHITE,BLACK,5*i+27,10," | ");
		i+=1;
	}
	////////////////////////////////////////////////////////
	Write(WHITE,BLACK,2,12," Hardness Stregthen  | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,12);
		cout<<har_str_per[i];
		Write(WHITE,BLACK,5*i+27,12," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,13,"   Hardness Fail     | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,13);
		if(har_fail_per[i]>=10)
		cout<<har_fail_per[i];
		else if(har_fail_per[i]<10)
		cout<<" "<<har_fail_per[i];
		Write(WHITE,BLACK,5*i+27,13," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,14,"  Hardness Degrade   | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,14);
		if(har_degrade_per[i]>=10)
		cout<<har_degrade_per[i];
		else if(har_degrade_per[i]<10)
		cout<<" "<<har_degrade_per[i];
		Write(WHITE,BLACK,5*i+27,14," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,15,"  Hardness Destroy   | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,15);
		if(100-har_str_per[i]-har_fail_per[i]-har_degrade_per[i]>=10)
		cout<<100-har_str_per[i]-har_fail_per[i]-har_degrade_per[i];
		else if(100-har_str_per[i]-har_fail_per[i]-har_degrade_per[i]<10)
		cout<<" "<<100-har_str_per[i]-har_fail_per[i]-har_degrade_per[i];
		Write(WHITE,BLACK,5*i+27,15," | ");
		i+=1;
	}
	////////////////////////////////////////////////////////
	Write(WHITE,BLACK,2,17," Sharpness Stregthen | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,17);
		cout<<sha_str_per[i];
		Write(WHITE,BLACK,5*i+27,17," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,18,"   Sharpness Fail    | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,18);
		if(sha_fail_per[i]>=10)
		cout<<sha_fail_per[i];
		else if(sha_fail_per[i]<10)
		cout<<" "<<sha_fail_per[i];
		Write(WHITE,BLACK,5*i+27,18," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,19,"  Sharpness Degrade  | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,19);
		if(sha_degrade_per[i]>=10)
		cout<<sha_degrade_per[i];
		else if(sha_degrade_per[i]<10)
		cout<<" "<<sha_degrade_per[i];
		Write(WHITE,BLACK,5*i+27,19," | ");
		i+=1;
	}
	Write(WHITE,BLACK,2,20,"  Sharpness Destroy  | ");
	i=0;
	while(i<=14){
		if(per_select==i)
		textcolor(WHITE,BLACK);
		else if(per_select!=i)
		textcolor(DARKGRAY,BLACK);
		Gotoxy(5*i+25,20);
		if(100-sha_str_per[i]-sha_fail_per[i]-sha_degrade_per[i]>=10)
		cout<<100-sha_str_per[i]-sha_fail_per[i]-sha_degrade_per[i];
		else if(100-sha_str_per[i]-sha_fail_per[i]-sha_degrade_per[i]<10)
		cout<<" "<<100-sha_str_per[i]-sha_fail_per[i]-sha_degrade_per[i];
		Write(WHITE,BLACK,5*i+27,20," | ");	
		i+=1;
	}
	
	Write(WHITE,BLACK,2,23,"a/d : Left/right");
	Write(WHITE,BLACK,2,24,"Space : Manu");
	/////////////////////////////////////////////
	while(1){
	if(kbhit()){
		click=_getch();
		if(click==' '){
			goto Manu;
		}
		if(click=='a'){
			if(per_select>=0)
		    	per_select-=1;
		    if(per_select<0)
		    	per_select=14;
		goto Re_probability;
		}
		else if(click=='d'){
			per_select+=1;
			if(per_select==15)
			per_select=0;
			goto Re_probability;
		}
	}	
	}
	////////////////////////////////////////////////
	//////////////////////////////////////////////////
	////////////////////////////////////////////////////
Strengthen :
	i=-3;
	j=4;
	while(i<=16){
system("cls");
Write(WHITE,BLACK,2,1,"◎》=-==-==-========-==-==-=《◎");
Write(WHITE,BLACK,2,7,"◎》=-==-==-========-==-==-=《◎");
Sword(40-i,j,1);
Write(WHITE,BLACK,1.7*i+5,1,"《◎                            ");
Write(WHITE,BLACK,1.7*i+5,7,"《◎                            ");
Sleep(5); 
i+=2;
}
Sleep(150); 
    j=9;
	while(j<=20){	
Write(WHITE,BLACK,2,1,"◎》=-==-==-========-==-==-=《◎");
Write(WHITE,BLACK,2,7,"◎》=-==-==-========-==-==-=《◎"); 
Sword(25,4,1);
Write(WHITE,BLACK,2,9,"ＳＷＯＲＤ | level ε");
Write(LIGHTGRAY,BLACK,2,11,"  Power  ==------------------=");
Write(LIGHTGRAY,BLACK,2,12,"○○○○○○○○○○○○○○○");
Write(DARKGRAY,BLACK,2,14,"Hardness ==-----------------=");
Write(DARKGRAY,BLACK,2,15,"○○○○◇○○○○◇○○○○○");
Write(DARKGRAY,BLACK,2,17,"Sharpness==-----------------=");
Write(DARKGRAY,BLACK,2,18,"○○○○○○○◇○○○○○○○");
Write(WHITE,BLACK,2,j-1,"                                ");
Write(WHITE,BLACK,2,j,"◎》=-==-==-========-==-==-=《◎");
Write(WHITE,BLACK,2,j+1,"                                ");
Write(WHITE,BLACK,2,j+2,"                                ");
Write(WHITE,BLACK,2,j+3,"                                ");
Write(WHITE,BLACK,2,j+4,"                                ");
Write(WHITE,BLACK,2,j+5,"                                ");
Write(WHITE,BLACK,2,j+6,"                                ");
Write(WHITE,BLACK,2,j+7,"                                ");
Write(WHITE,BLACK,2,j+8,"                                ");
Sleep(40-j*1.98); 
j+=1;
}
Write(WHITE,BLACK,2,23,"w/s : Up/Down");
Write(WHITE,BLACK,2,24,"q : Select");
Write(WHITE,BLACK,2,25,"Space : Record");

level=0;
basic_dam=rand()%20+90;
////////////////////////////////////////////////
while(1){
	Sword(25,4,level+1);
Write(WHITE,BLACK,2,9,"ＳＷＯＲＤ | level ");
level=(power*1.3+hardness+sharpness*1.3)/2.3;
Gotoxy(21,9);
cout<<level_name.at(level); 
////////////////////////////////////////////////
if(str_select%3==0){
Write(WHITE,BLACK,2,11,"  Power  ==------------------=");
i=1;
while(i<=power){
	Write(BROWN,BLACK,2*i,12,"◎");
	i+=1;
}
i=1;
while(i<=15-power){
Write(WHITE,BLACK,2*(16-i),12,"○");
	i+=1;	
}
}
else{
Write(DARKGRAY,BLACK,2,11,"  Power  ==------------------=");
i=1;
while(i<=power){
	Write(DARKGRAY,BLACK,2*i,12,"◎");
	i+=1;
}
i=1;
while(i<=15-power){
Write(DARKGRAY,BLACK,2*(16-i),12,"○");
	i+=1;	
}
}
if(str_select%3==1){
Write(WHITE,BLACK,2,14,"Hardness ==------------------=");
i=1;
while(i<=hardness){
	if(i!=5&&i!=10)
	Write(BROWN,BLACK,2*i,15,"◎");
	else
	Write(BROWN,BLACK,2*i,15,"◈");
	i+=1;
}
i=1;
while(i<=15-hardness){
	if(16-i!=5&&16-i!=10)
Write(WHITE,BLACK,2*(16-i),15,"○");
else
Write(WHITE,BLACK,2*(16-i),15,"◇");
	i+=1;	
}
}
else {
Write(DARKGRAY,BLACK,2,14,"Hardness ==------------------=");
i=1;
i=1;
while(i<=hardness){
	if(i!=5&&i!=10)
	Write(DARKGRAY,BLACK,2*i,15,"◎");
	else
	Write(DARKGRAY,BLACK,2*i,15,"◈");
	i+=1;
}
i=1;
while(i<=15-hardness){
	if(16-i!=5&&16-i!=10)
Write(DARKGRAY,BLACK,2*(16-i),15,"○");
else
Write(DARKGRAY,BLACK,2*(16-i),15,"◇");
	i+=1;	
}
}
if(str_select%3==2){
Write(WHITE,BLACK,2,17,"Sharpness==------------------=");
i=1;
while(i<=sharpness){
	if(i!=8)
	Write(BROWN,BLACK,2*i,18,"◎");
	else
	Write(BROWN,BLACK,2*i,18,"◈");
	i+=1;
}
i=1;
while(i<=15-sharpness){
	if(16-i!=8)
Write(WHITE,BLACK,2*(16-i),18,"○");
else 
Write(WHITE,BLACK,2*(16-i),18,"◇");
	i+=1;	
}
}
else {
Write(DARKGRAY,BLACK,2,17,"Sharpness==------------------=");
i=1;
while(i<=sharpness){
	if(i!=8)
	Write(DARKGRAY,BLACK,2*i,18,"◎");
	else
	Write(DARKGRAY,BLACK,2*i,18,"◈");
	i+=1;
}
i=1;
while(i<=15-sharpness){
	if(16-i!=8)
Write(DARKGRAY,BLACK,2*(16-i),18,"○");
else 
Write(DARKGRAY,BLACK,2*(16-i),18,"◇");
	i+=1;	
}
}
//////////////////////////////////////////////////////////

if(kbhit()){
		click=_getch();
		if(click=='w'){
			if(str_select==1||str_select==2)
		    	str_select-=1;
		    	Write(BLACK,BLACK,2,13,"                  ");
		    	Write(BLACK,BLACK,2,16,"                  ");
		    	Write(BLACK,BLACK,2,19,"                  ");
		}
		else if(click=='s'){
			if(str_select==0||str_select==1)
			str_select+=1;
			Write(BLACK,BLACK,2,13,"                  ");
			Write(BLACK,BLACK,2,16,"                  ");
			Write(BLACK,BLACK,2,19,"                  ");
		}
		else if(click=='q'){
			
		if(str_select%3==0){
			if(power!=15){
				
				if(rand()%100+1<=pow_str_per[power]){
				power+=1;	
				Write(BLACK,BLACK,2,13,"                  ");
				Sleep(100);
				Write(LIGHTGREEN,BLACK,2,13,"[Strengthen!]");
				}
				else if(rand()%100+1>pow_str_per[power]&&rand()%100+1<=pow_str_per[power]+pow_fail_per[power]){
				Write(BLACK,BLACK,2,13,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,13,"[Fail!]");	
				}			
				else if(rand()%100+1>pow_str_per[power]+pow_fail_per[power]&&rand()%100+1<=pow_str_per[power]+pow_fail_per[power]+pow_degrade_per[power]){
				if(power!=0)
				power-=1;
				Write(BLACK,BLACK,2,13,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,13,"[Degrade!]");
				}				
				else if(rand()%100+1>pow_str_per[power]+pow_fail_per[power]+pow_degrade_per[power]){
				Write(BLACK,BLACK,2,13,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,13,"[Destory!]");
				goto Destroy;	
				}
				
			}
			else{
				Write(BLACK,BLACK,2,13,"                  ");
				Sleep(100);
			    Write(LIGHTGREEN,BLACK,2,13,"[Max!]");	
			}
			
		}
        else if(str_select%3==1){
        	if(hardness!=15){

        		if(rand()%100+1<=har_str_per[hardness]){
        		hardness+=1;	
        		Write(BLACK,BLACK,2,16,"                  ");
        		Sleep(100);
        		Write(LIGHTGREEN,BLACK,2,16,"[Strengthen!]");
				}	
				else if(rand()%100+1>har_str_per[hardness]&&rand()%100+1<=har_str_per[hardness]+har_fail_per[hardness]){
				Write(BLACK,BLACK,2,16,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,16,"[Fail!]");		
				}			
				else if(rand()%100+1>har_str_per[hardness]+har_fail_per[hardness]&&rand()%100+1<=har_str_per[hardness]+har_fail_per[hardness]+har_degrade_per[hardness]){
				if(hardness!=5&&hardness!=10){
				if(hardness!=0)
				hardness-=1;
				Write(BLACK,BLACK,2,16,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,16,"[Degrade!]");	
				}
				else{
				Write(BLACK,BLACK,2,16,"                  ");
				Sleep(100);
				Write(LIGHTGREEN,BLACK,2,16,"[Invalid!]");	
				}				
				}				
				else if(rand()%100+1>har_str_per[hardness]+har_fail_per[hardness]+har_degrade_per[hardness]){
				Write(BLACK,BLACK,2,16,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,16,"[Destory!]");
				goto Destroy;	
				}
				
			}
			else{
				Write(BLACK,BLACK,2,16,"                  ");
				Sleep(100);
		    	Write(LIGHTGREEN,BLACK,2,16,"[Max!]");	
			}      	
		}
		else if(str_select%3==2){
        	if(sharpness!=15){
        		if(rand()%100+1<=sha_str_per[sharpness]){
        		sharpness+=1;	
        		Write(BLACK,BLACK,2,19,"                  ");
        		Sleep(100);
        		Write(LIGHTGREEN,BLACK,2,19,"[Strengthen!]");
				}	
				else if(rand()%100+1>sha_str_per[sharpness]&&rand()%100+1<=sha_str_per[sharpness]+sha_fail_per[sharpness]){
				Write(BLACK,BLACK,2,19,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,19,"[Fail!]");		
				}			
				else if(rand()%100+1>sha_str_per[sharpness]+sha_fail_per[sharpness]&&rand()%100+1<=sha_str_per[sharpness]+sha_fail_per[sharpness]+sha_degrade_per[sharpness]){
				if(sharpness!=8){
				if(sharpness!=0)
				sharpness-=1;
				Write(BLACK,BLACK,2,19,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,19,"[Degrade!]");
			}
			else {
				Write(BLACK,BLACK,2,19,"                  ");
				Sleep(100);
				Write(LIGHTGREEN,BLACK,2,19,"[Invalid!]");
			}
				}				
				else if(rand()%100+1>sha_str_per[sharpness]+sha_fail_per[sharpness]+sha_degrade_per[sharpness]){
				Write(BLACK,BLACK,2,19,"                  ");
				Sleep(100);
				Write(LIGHTRED,BLACK,2,19,"[Destory!]");
				goto Destroy;	
				}
				
			}
			else{
				Write(BLACK,BLACK,2,19,"                  ");
				Sleep(100);
		    	Write(LIGHTGREEN,BLACK,2,19,"[Max!]");	
			}      	
		}

		}
		//////////////////////////////////////////	//////////////////////////////////////////
			//////////////////////////////////////////	//////////////////////////////////////////
	else if(click==' '){
		
		////////////////////////////////////////////
		j=4;
		while(j<=8){
			system("cls");
			Sword(25,j,level+1);
			Sleep(1);
			j+=1;
		}
		i=0;
		while(i<=17){
			Write(WHITE,BLACK,2,11,"◎》=-==-==-========-==-==-=《◎"); 
			Write(WHITE,BLACK,1.7*i+2,11,"《◎                            ");
			Sleep(5);
			i+=2;
		}
		Sleep(150);
		i=0;
		while(i<=17){
			Write(WHITE,BLACK,2,20,"◎》=-==-==-========-==-==-=《◎"); 
			Write(WHITE,BLACK,1.7*i+2,20,"《◎                            ");
			Sleep(5);
			i+=2;
		}
		Sleep(150);
		i=0;
		while(i<=17){
             Write(WHITE,BLACK,2,13,"ＳＷＯＲＤ | level ");
             Gotoxy(21,13);
             cout<<level_name.at(level); 
			Write(WHITE,BLACK,1.7*i+2,13,"                           ");
			Sleep(5);
			i+=2;
		}
		i=0;
		//////////////////////////////////////////////////////////////
		while(i<=20){
             Write(WHITE,BLACK,2,15,"Your Name : ");
             Write(DARKGRAY,BLACK,2,16,"(Don't Include Blank)");
		     Write(DARKGRAY,BLACK,2,17,"(Max Legth Is 10 (Korean is 5) )");
			Write(WHITE,BLACK,1.7*i+2,15,"                           ");
			Write(WHITE,BLACK,1.7*i+2,16,"                           ");
			Write(WHITE,BLACK,1.7*i+2,17,"                           ");
			Sleep(5);
			i+=2;
		}
		Gotoxy(2,23);
		Write(WHITE,BLACK,2,23,"Enter : Record");
		Gotoxy(14,15);
		scanf("%s",&name);
            fout.open("name.txt");
            fout<<name;
		fout.close();
            fout.open("sword.txt");
		fout<<power+hardness*100+sharpness*10000+basic_dam*1000000;
		fout.close();		
		Write(LIGHTGREEN,BLACK,2,18,"[Record!]");
		Write(WHITE,BLACK,2,23,"Space : Manu   ");
		while(1){
		if(kbhit()){
		click=_getch();
		if(click==' '){
			
			str_select=0;
			goto Manu;
		}
	}	
}
		
	}
	}
}
//////////////////////////////////////////////
Destroy :
	
	Gotoxy(21,9);
	level=0;
	cout<<level_name.at(level); 
	Sword(25,4,0);
////////////////////////////////////////////////////////////	
	Write(DARKGRAY,BLACK,2,11,"  Power  ==------------------=");
i=1;
while(i<=power){
	Write(DARKGRAY,BLACK,2*i,12,"◎");
	i+=1;
}
i=1;
while(i<=15-power){
Write(DARKGRAY,BLACK,2*(16-i),12,"○");
	i+=1;	
}

Write(DARKGRAY,BLACK,2,14,"Hardness ==------------------=");
i=1;
i=1;
while(i<=hardness){
	if(i!=5&&i!=10)
	Write(DARKGRAY,BLACK,2*i,15,"◎");
	else
	Write(DARKGRAY,BLACK,2*i,15,"◈");
	i+=1;
}
i=1;
while(i<=15-hardness){
	if(16-i!=5&&16-i!=10)
Write(DARKGRAY,BLACK,2*(16-i),15,"○");
else
Write(DARKGRAY,BLACK,2*(16-i),15,"◇");
	i+=1;	
}

Write(DARKGRAY,BLACK,2,17,"Sharpness==------------------=");
i=1;
while(i<=sharpness){
	if(i!=8)
	Write(DARKGRAY,BLACK,2*i,18,"◎");
	else
	Write(DARKGRAY,BLACK,2*i,18,"◈");
	i+=1;
}
i=1;
while(i<=15-sharpness){
	if(16-i!=8)
Write(DARKGRAY,BLACK,2*(16-i),18,"○");
else 
Write(DARKGRAY,BLACK,2*(16-i),18,"◇");
	i+=1;	
}
///////////////////////////////////////////////
	Write(WHITE,BLACK,2,25,"Space : Manu   ");
	while(1){
		if(kbhit()){
		click=_getch();
		if(click==' '){
			level=0;
			power=0;
			hardness=0;
			sharpness=0;
			sword_length=0;
			str_select=0;
			goto Manu;
		}
	}	
}	
	////////////////////////////////////////////////
	////////////////////////////////////////////////
Sword :
	srand((unsigned int) time(NULL));
	
	swo_select=0;
	if(power==0&&hardness==0&&sharpness==0)
	basic_dam=rand()%20+90;
	//power=15;
    //hardness=15;
	//sharpness=15;
	
	system("cls");
	i=0;
		while(i<=19){
			Write(WHITE,BLACK,2,1,"◎》==-==-==-==========-==-==-==《◎"); 
			Write(WHITE,BLACK,1.75*i+2,1,"《◎                            ");
			Write(WHITE,BLACK,2,13,"◎》==-==-==-==========-==-==-==《◎"); 
			Write(WHITE,BLACK,1.75*i+2,13,"《◎                            ");
			Write(WHITE,BLACK,2,19,"◎》==-==-==-==========-==-==-==《◎"); 
			Write(WHITE,BLACK,1.75*i+2,19,"《◎                            ");
			Sleep(5);
			i+=2;
		}
///////////////////////////////////////////////////////////
Re_sword :

i=0;
		    	j=3;
		    	while(i<=14){
		    		while(j<=11){
		    			Write(BLACK,BLACK,i,j," ");
		    			j+=1;
					}
		    		i+=1;
		    		j=3;
				}
	
    Sword(26,16,level+1);
	Gotoxy(15,3);
	textcolor(YELLOW,BLACK);
	cout<<name<<"'S"<<"       ";
	Write(WHITE,BLACK,14,4," ＳＷＯＲＤ | level ");
	Sleep(5);
	Gotoxy(33,4); 
    cout<<level_name.at(level); 
    Write(WHITE,BLACK,16,6,"  Power  =------=");
    Sleep(5);
i=15;
while(i-14<=power){
	Write(BROWN,BLACK,i+1,7,"o");
	i+=1;
}
i=15;
while(i-14<=15-power){
Write(WHITE,BLACK,(45-i),7,".");
i+=1;	
}
Write(WHITE,BLACK,16,8,"Hardness =------=");
Sleep(5);
i=15;
while(i-14<=hardness){
	Write(BROWN,BLACK,i+1,9,"o");
	i+=1;
}
i=15;
while(i-14<=15-hardness){
Write(WHITE,BLACK,(45-i),9,".");
i+=1;	
}
Write(WHITE,BLACK,16,10,"Sharpness=------=");
Sleep(5);
i=15;
while(i-14<=sharpness){
	Write(BROWN,BLACK,i+1,11,"o");
	i+=1;
}
i=15;
while(i-14<=15-sharpness){
Write(WHITE,BLACK,(45-i),11,".");	
i+=1;
}	
	Human(WHITE,0);
	Write(WHITE,BLACK,2,21,"q : Attack");
	Write(WHITE,BLACK,2,22,"w/s : Up/Down");
	Write(WHITE,BLACK,2,23,"Space : Manu");
	
    ///////////////////////////////////////////////////////////
	
	int var_squ=pow(1.12,hardness);
			
			
			int dam_squ=pow(1.72,power);
		    
			int cri_pro_squ=10*pow(1.1659,sharpness);
			int cri_dam_squ=1.5*pow(1.17,sharpness);
	
	/////////////////////////////////////////////////////////
	while(1){
		if(swo_select%4==0){
			Write(WHITE,BLACK,40,2,"◎》=-====-=《◎");
			Write(WHITE,BLACK,40,3,"｝=-- MINE --=｛");
			Write(WHITE,BLACK,40,4,"◎》=-====-=《◎");
		}
		else{
			Write(DARKGRAY,BLACK,40,2,"◎》=-====-=《◎");
			Write(DARKGRAY,BLACK,40,3,"｝=-- MINE --=｛");
			Write(DARKGRAY,BLACK,40,4,"◎》=-====-=《◎");
		}
		Write(LIGHTGRAY,BLACK,40,6,"◎》=------=《◎");
		if(swo_select%4==1){
			Write(WHITE,BLACK,40,8,"◎》=-====-=《◎");
			Write(WHITE,BLACK,40,9,"｝=-- 1 st --=｛");
			Write(WHITE,BLACK,40,10,"◎》=-====-=《◎");
		}
		else{
			Write(DARKGRAY,BLACK,40,8,"◎》=-====-=《◎");
			Write(DARKGRAY,BLACK,40,9,"｝=-- 1 st --=｛");
			Write(DARKGRAY,BLACK,40,10,"◎》=-====-=《◎");
		}
		if(swo_select%4==2){
			Write(WHITE,BLACK,40,12,"◎》=-====-=《◎");
			Write(WHITE,BLACK,40,13,"｝=-- 2 nd --=｛");
			Write(WHITE,BLACK,40,14,"◎》=-====-=《◎");
		}
		else{
			Write(DARKGRAY,BLACK,40,12,"◎》=-====-=《◎");
			Write(DARKGRAY,BLACK,40,13,"｝=-- 2 nd --=｛");
			Write(DARKGRAY,BLACK,40,14,"◎》=-====-=《◎");
		}
		if(swo_select%4==3){
			Write(WHITE,BLACK,40,16,"◎》=-====-=《◎");
			Write(WHITE,BLACK,40,17,"｝=-- 3 rd --=｛");
			Write(WHITE,BLACK,40,18,"◎》=-====-=《◎");
		}
		else{
			Write(DARKGRAY,BLACK,40,16,"◎》=-====-=《◎");
			Write(DARKGRAY,BLACK,40,17,"｝=-- 3 rd --=｛");
			Write(DARKGRAY,BLACK,40,18,"◎》=-====-=《◎");
		}
		textcolor(WHITE,BLACK);
		if(kbhit()){
		click=_getch();
		if(click=='q'){
			
			variability = rand()%(var_squ*((dam_squ+20)/20)+2);
			i=0;
		    	j=3;
		    	while(i<=14){
		    		while(j<=11){
		    			Write(BLACK,BLACK,i,j," ");
		    			j+=1;
					}
		    		i+=1;
		    		j=3;
				}
			
			int mov_human=1;
			
			if(rand()%100+1<=cri_pro_squ){
				
				damage=(basic_dam+variability)*dam_squ*cri_dam_squ;
				if(damage>=0&&damage<=50000)
				mov_human=1;
				if(damage>=50000&&damage<=1000000)
				mov_human=2;
				if(damage>=1000000&&damage<100000000)
				mov_human=3;
						    	Sleep(10);
		    	Human(DARKGRAY,0);
		    	Human(RED,mov_human);
		    	Sleep(10);
		    	Human(DARKGRAY,mov_human);
		    	Human(RED,0);	
				Sleep(5);	
				Human(BLACK,mov_human);   	
		    	Human(DARKGRAY,0);
		    	Human(RED,-mov_human);
		    	Sleep(5);
		    	Human(DARKGRAY,-mov_human);
		    	Human(RED,0);
		    	Sleep(5);
		    	Human(BLACK,-mov_human);
		    	Human(WHITE,0);
		    	
		    	Gotoxy(rand()%5+3,rand()%4+5);		
		    	textcolor(BROWN,BLACK);
		    	cout<<damage;
		    	textcolor(WHITE,BLACK);
			}
			else{
			
				damage=(basic_dam+variability)*dam_squ;
				if(damage>=0&&damage<=50000)
				mov_human=1;
				if(damage>=50000&&damage<=500000)
				mov_human=2;
				if(damage>=500000)
				mov_human=3;
				
		    	Sleep(10);
		    	Human(DARKGRAY,0);
		    	Human(WHITE,mov_human);
		    	Sleep(10);
		    	Human(DARKGRAY,mov_human);
		    	Human(WHITE,0);	
				Sleep(5);	
				Human(BLACK,mov_human);   	
		    	Human(DARKGRAY,0);
		    	Human(WHITE,-mov_human);
		    	Sleep(5);
		    	Human(DARKGRAY,-mov_human);
		    	Human(WHITE,0);
		    	Sleep(5);
		    	Human(BLACK,-mov_human);
		    	Human(WHITE,0);
		    			    	
		    	Gotoxy(rand()%5+3,rand()%4+5);	
		    	textcolor(WHITE,BLACK);
		    	cout<<damage;
		    	textcolor(WHITE,BLACK);
		    	
			}
					
			
					}
		else if(click=='w'){
			if(swo_select>=0)
		    	swo_select-=1;
		    if(swo_select<0)
		    	swo_select=3;
		    	goto Re_sword;
		}
		else if(click=='s'){
			swo_select+=1;
			goto Re_sword;
		}
		else if(click==' '){
        	goto Manu;
		}
	}

	}
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	

}
