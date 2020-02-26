#include<iostream>
#include<conio.h>



main()
{
  
  for(k=0;k<strlen(p);k++)
  {
   for(i=0;i<strlen(p);i++)
  {
     if(p[i]=='L'&&p[i+1]=='U'&&p[i+2]=='R')
     {    p[i]='U';
        maze_replace();
     }
     if(p[i]=='L'&&p[i+1]=='U'&&p[i+2]=='S')
     {    p[i]='R';
        maze_replace();
     }
     if(p[i]=='R'&&p[i+1]=='U'&&p[i+2]=='L')
     {    p[i]='U';
        maze_replace();
     }
     if(p[i]=='S'&&p[i+1]=='U'&&p[i+2]=='L')
     {    p[i]='R';
        maze_replace();
     }
     if(p[i]=='L'&&p[i+1]=='U'&&p[i+2]=='L')
     {    p[i]='R';
        maze_replace();
     }  
  }
  }
}

void maze_replace()
{
j=i;
        do 
         {p[j+1]=p[j+3];
         j++;
         }while(p[j+3]!='\0');
p[j+1]='\0';
p[j+2]='\0';
}
