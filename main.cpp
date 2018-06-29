#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<string>
using namespace std;

string sid;
//static int tic[3][3]={0,0,0,0,0,0,0,0,0};

void disp_tic(int tic[3][3])
{
    char matrix[3][3];
	int t,i,j;

	for(i=0;i<3;i++)//print the output
    {
        for(j=0;j<3;j++)
        {
            if(tic[i][j]==10)
				matrix[i][j]='O';
            else if(tic[i][j]==11)
                matrix[i][j]='X';
			else
				matrix[i][j]=' ';
        }
    }

	for(t=0; t<3; t++) {
		printf(" %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
		if(t!=2) printf("\n---|---|---\n");
	}
	printf("\n");
}

//check he can not win and if u can win
void check_win(int tic[3][3])
  {
    int add_com_ro,add_com_col,i,j,k,par=0;

    for(i=0;i<3;i++)
	{
      add_com_ro=0;
      add_com_col=0;
      for(j=0;j<3;j++)//check if row or column wise wine or avast
        {
          add_com_ro+=tic[i][j];
          add_com_col+=tic[j][i];
		}
    if(add_com_ro==22&&par!=50)//siddhartha's A.I. er jonno check kora
       {
         for(k=0;k<3;k++)
           {
             if(tic[i][k]==0)
               {
                  tic[i][k]=11;
                  par=50;break;
               }
			}
		}
     else if(add_com_col==22&&par!=50)
		{
          for(k=0;k<3;k++)
			{
              if(tic[k][i]==0)
				{
                    tic[k][i]=11;
                    par=50;break;
				}
			}
		}
     else if((tic[0][0]+tic[1][1]+tic[2][2])==20/*&&par!=50*/)//diagonal er jonno check kora
		{
			if(tic[0][0]==0)
				tic[0][0]=11;
			else if(tic[2][2]==0)
				tic[2][2]=11;
			else if(tic[1][1]==0)
				tic[1][1]=11;
			par=50;break;
		}
     else if((tic[0][2]+tic[1][1]+tic[2][0])==20/*&&par!=50*/)
		{
			if(tic[0][2]==0)
				tic[0][2]=11;
			else if(tic[2][0]==0)
				tic[2][0]=11;
			else if(tic[1][1]==0)
				tic[1][1]=11;
			par=50;break;
		}

    }

     for(i=0;i<3;i++)
	   {
		 add_com_ro=0;
		 add_com_col=0;
         for(j=0;j<3;j++)//check if row or column wise wine or avast
		   {
             add_com_ro+=tic[i][j];
             add_com_col+=tic[j][i];
		   }
     if(add_com_ro==20&&par!=50)//user er jonno check kora
       {
         for(k=0;k<3;k++)
           {
             if(tic[i][k]==0)
               {
                 tic[i][k]=11;
                 par=50;break;
               }
           }
		}
     else if(add_com_col==20&&par!=50)
       {
         for(k=0;k<3;k++)
           {
             if(tic[k][i]==0)
               {
                 tic[k][i]=11;
                 par=50;break;
				}
           }
		}
    }
	//cout<<par;
	if(tic[2][0]==10&&tic[0][2]==10&&(tic[1][1]+tic[0][2]+tic[2][0])==31&&tic[0][0]==0&&tic[0][1]==0&&tic[2][1]==0&&par==0)//let problem7396,7198,3768
	  {
		tic[1][0]=11;
		par=60;
	  }
	else if ((tic[1][1]+tic[2][2])==20&&tic[0][2]==0&&par==0)//same err 19 usr1
	{
        tic[0][2]=11;
		par=60;
	}
	else if(tic[1][2]==10&&(tic[1][1]+tic[2][0]!=22)&&tic[0][1]==0&&tic[1][1]!=0&&par==0)//error 6, 76 usr7
      {
		tic[0][1]=11;
		par=60;
	  }
	//cout<<par;
	if(par==0)
      {
		if((tic[0][2]+tic[1][1]+tic[2][0]==22)&&tic[2][0]==0)//same1 diagonally 11
            tic[2][0]=11;
        else if((tic[0][0]+tic[2][2]==20)&&tic[0][1]==0)// same err 59 usr5
			tic[0][1]=11;
        else if((tic[1][1]+tic[2][0]==22)&&tic[0][2]==0)//same1
			tic[0][2]=11;
		else if(tic[1][1]==0)
			tic[1][1]=11;
		else if(tic[0][0]==0)
			tic[0][0]=11;
		else if(tic[2][2]==0)
			tic[2][2]=11;
		else if(tic[0][1]==0&&tic[1][2]!=10)
			tic[0][1]=11;
		else if(tic[1][0]==0&&tic[1][2]!=10)
			tic[1][0]=11;
        else if(tic[2][0]==0&&tic[0][2]==0&&(tic[0][0]+tic[1][1]+tic[2][2])==31)//if error 54297,1978
            tic[2][0]=11;
        else if(tic[1][0]==0||tic[1][2]==0&&(tic[0][0]+tic[1][1]+tic[2][2])==31)//if error 5936 && 13864  during usr5
           {
             if(tic[1][2]==0)
                tic[1][2]=11;
            else
                tic[1][0]=11;
           }
             par==60;
      }
	if(par!=60)
	   {
         if(tic[2][0]==0&&(tic[0][0]+tic[1][1]+tic[2][2])==32&&tic[1][0]==10&&tic[0][1]==10)//err 5429,924,942
           {
             tic[2][0]=11;
           }
	   }
  }

int check_tic(int aray[3][3])//check if the input if it is match
{
    int row_add,colom_add,p = 0,draw_check;
    for(int i=0;i<3;i++)//check adding row and column
      {
       row_add=0,colom_add=0;
       for(int j=0;j<3;j++)
         {
          row_add+=aray[i][j];
          colom_add+=aray[j][i];
         }
       if((row_add==30)||(row_add==33))//check row wise
		{
          if(row_add==30)
            cout<<"CONGRATULATION!!! "<<sid<<" Win Through Row Wise!";
          else
            cout<<"CONGRATULATION!!! Siddhartha's A.I. Win Through Row Wise!";
            p=14;
			break;
		}
      else if((colom_add==30)||(colom_add==33))//check column wise
		 {
           if(colom_add==30)
              cout<<"CONGRATULATION!!! "<<sid<<" Win Through Column Wise!";
			else
              cout<<"CONGRATULATION!!! Siddhartha's A.I. Win Through Column Wise!";
              p=14;
			 break;
		}
      else if((aray[0][0]+aray[1][1]+aray[2][2]==33)||(aray[0][0]+aray[1][1]+aray[2][2]==30))//check diagonally
		{
          if(aray[0][0]+aray[1][1]+aray[2][2]==30)
            cout<<"congrats "<<sid<<" Diagonally!";
          else
            cout<<"CONGRATULATION!!! Siddhartha's A.I. Win Through Diagonally!";
            p=14;
            break;
		}
      else if((aray[0][2]+aray[1][1]+aray[2][0]==33)||(aray[0][2]+aray[1][1]+aray[2][0]==30))//check diagonally
        {
          if(aray[0][2]+aray[1][1]+aray[2][0]==30)
            cout<<"congrats "<<sid<<" Diagonaly!";
          else
            cout<<"CONGRATULATION!!! Siddhartha's A.I. Win Throuth Diagonaly!";
            p=14;
            break;
		}
		else
			draw_check=2;
     }
  if(p==14)
      return 1;
  else
      return draw_check;
}

int main()
{
    int u1,u2,row,colum,i,j,p;
    int m,n,check_return,ran;
    char ch;

    cout<<"Enter Your Name: ";
    cin>>sid;
    cout<<endl;
    cout<<"\t\t\t***Welcome "<<sid<<"!***"<<endl;
  do
    {
    cout<<"   1   /  2  /  3 "<<endl;
    cout<<" -----------------"<<endl;
    cout<<"  4  /  5  /  6   "<<endl;
    cout<<" -----------------"<<endl;
    cout<<" 7 /  8  /  9   "<<endl;

int tic[3][3]={0,0,0,0,0,0,0,0,0};

    srand(time(0));
    ran=rand()%9+1;

    for(p=1;p<=9;p++)
       {
         if(ran%2==0)//check if the user 1 or 2 give the input first
           { m:
		     cout<<"\n"<<sid<<" Your Turn <1-9>: ";
             cin>>u1;
                if(u1<=0||u1>=10)
                    {
                        cout<<"Please enter a veiled position!";
                        goto m;
                    }
		     row=(u1-1)/3;
		    colum=(u1-1)%3;

		    if(tic[row][colum]!=10 && tic[row][colum]!=11)//storage the input
			   tic[row][colum]=10;
		    else
              {
			   cout<<"enter a empty place! \n";
			   goto m;
		      }
          }
         else
          {
			cout<<"\nComputer Play <1-9>:";
			check_win(tic);
		  }

		 cout<<endl;
		 disp_tic(tic);
		 ran++;//user sequence increase

         check_return=check_tic(tic);
		 if(check_return==1)//check tic tac condition
            break;
       }
	if(check_return==2)
		cout<<"\n OH! Match Draw!";

	cout<<"\n\nDo you want to play again?(Y/y for YES) ";
    cin>>ch;
  }while(ch=='y'||ch=='Y');
  cout<<"\n\t\t\t***"<<"Thank You "<<sid<<"!***\n\t\t\t   ***Game Over...!!!***"<<endl;
     return 0;
}
