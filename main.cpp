#include <iostream>

using namespace std;
char arr[3][3]={'1','2','3','4','5','6','7','8','9'};
char player='x';
void theShape (){
    system("cls");
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<arr[i][j]<<"  ";
    }
    cout<<endl;
}
}
void input (){
char position;
cout<<"enter the position of player  "<<player<<endl;
cin>>position;
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(position==arr[i][j]){
            arr[i][j]=player;
        }
    }
}
if(player=='x'){
    player='o';
}
else{player='x';}
}
char theWinner (){
    int x=0;
    int o=0;
    int coun=0;
    //rows
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
       if(arr[i][j]=='x'){
        x++;
       }
       if(arr[i][j]=='o'){
        o++;

       }
             if(x==3 || o==3){
              if(x>o){
                return 'x';
           }
        else{return 'o';}
}
    }
    x=0;
    o=0;
}
//cols
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
       if(arr[j][i]=='x'){
        x++;
       }
       if(arr[j][i]=='o'){
        o++;

       }
             if(x==3 || o==3){
    if(x>o){
        return 'x';
    }
    else{return 'o';}
}
    }
    x=0;
    o=0;
}
//diagonal
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(i==j && arr[i][j]=='x' && arr[i][j]==arr[2][2]){
            return 'x';
        }
        else if(i==j && arr[i][j]=='o' && arr[i][j]==arr[3-1][3-1]){
            return 'o';
        }
        else if(i+j==2 && arr[i][j]=='x' && arr[i][j]==arr[3-1][0]){
            return 'x';
        }
           else if(i+j==2 && arr[i][j]=='o' && arr[i][j]==arr[3-1][0]){
            return 'o';
        }
    }
}

//draw
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(arr[i][j]!='x' && arr[i][j]!='o'){coun++;}
    }
}
if(coun==0){return 'd';}
return 'w';
}

void TheGameIsRunning (){
while(theWinner()=='w'){
      theShape();
        input();
    }
}
void game (){
    theShape();
    cout<<endl;
if(theWinner()=='d'){
    cout<<"no winner and the game end draw"<<endl;
}
else{cout<<"the winner is player of "<<theWinner()<<endl;}
}
void xoWithFrind (){
TheGameIsRunning();
game();
}
int main()
{
 xoWithFrind();
}
