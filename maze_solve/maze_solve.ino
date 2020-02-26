int i,j,l,k,m;
int c;
String p;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 
  for(m=0;m<30;m++)
{p=Serial.readString();
}

p[m]='\0';
solve_maze_left();
printf("\t");
        Serial.print(p);
}

void solve_maze_left()
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


void solve_maze_right()
{
  
  for(k=0;k<strlen(p);k++)
  {
   for(i=0;i<strlen(p);i++)
  {
     if(p[i]=='R'&&p[i+1]=='U'&&p[i+2]=='L')
     {    p[i]='U';
        maze_replace();        
     }
     if(p[i]=='R'&&p[i+1]=='U'&&p[i+2]=='S')
     {    p[i]='L';
        maze_replace();
     }
     if(p[i]=='L'&&p[i+1]=='U'&&p[i+2]=='R')
     {    p[i]='U';
        maze_replace();
     }
     if(p[i]=='S'&&p[i+1]=='U'&&p[i+2]=='R')
     {    p[i]='L';
        maze_replace();
     }
     if(p[i]=='R'&&p[i+1]=='U'&&p[i+2]=='R')
     {    p[i]='S';
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
