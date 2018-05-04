#include<iostream>
#include <cstdlib>
#include <ctime>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;
void delay(int x)
{
    x--;
    if(x!=0)
    delay(x);

}
struct node
{
    char arr[9];
    node* link;
};
char a[9]={'1','2','3','4','5','6','7','8','9'};
int flag=0;
class moves
{
    node *ptr,*start;
    public:
    moves()
    {
        ptr=NULL;
        start=NULL;
    }
    void insert(node* a)
    {   //cout<<"4";
        node *temp=new node;
        temp=a;
        temp->link=start;
        start=temp;

    }
    char search(char trackmoves[10],int movenum)
    {   int i,flag1=0;
        //cout<<"6";
        cout<<"\nTrackMoves:"<<trackmoves<<"\nMovenum:"<<movenum;
       // cout<<val;
        int j=0;
        node* ptr=start;
        //cout<<"\n"<<(char)ptr->arr[0]<<(char)ptr->arr[1];
        while(ptr->link!=NULL)
        {   //cout<<"\n7";
           //j++;
          //  cout<<"ptr->arr"<<ptr->arr<<"\n";
            for(i=0;i<=movenum-2;i++)
            {   //cout<<"8";
                //flag=0;
                //cout<<"(char)ptr->arr[i]"<<(char)ptr->arr[i]<<"\n";

                //cout<<"ptr->arr[i]"<<ptr->arr[i]<<"\n";
                if(trackmoves[i]==(char)ptr->arr[i])
                    {   //flag=1;
                        flag1++;
                        //cout<<"\n"<<flag1;
                        //cout<<j<<" ";
                        //cout<<ptr->arr[i+1];
                        //continue;
                    }
                else
                    break;

            }



            if(flag1==movenum-1)
            {   cout<<"\nptr->arr[i]:"<<ptr->arr[i]<<"\n";
                return ptr->arr[i];
            }
            flag1=0;
             ptr=ptr->link;
        }

    }
    void disp()
    {
        ptr=start;
        while(ptr!=NULL)
        {
            for(int i=0;ptr->arr[i]!='0';i++)
                cout<<(char)ptr->arr[i]<<" ";
            cout<<"\n";
            ptr=ptr->link;
        }
    }
};
moves m;
class singleplayer
{
    public:

    singleplayer()
    {
        a[0]='x';
    }
    char play()
    {
        char num;
        cout<<"Enter number:";
        cin>>num;
        for(int i=0;i<9;i++)
            {
                if(a[i]==num)
                    a[i]='o';
            }
            cout<<num<<" "<<(char)num;
        return (char)num;
    }
    char computermove(char trackmoves[9],int movenum)
    {   //cout<<"5";
        char compmove=m.search(trackmoves,movenum);
        for(int i=0;i<9;i++)
            {
                if(a[i]==compmove)
                    a[i]='x';
            }
        return compmove;
    }
    int check(int movenum)
    {   int flag=0;
        char ch='x';
        if((a[0]==a[1]&&a[1]==a[2]&&a[2]==ch)||(a[3]==a[4]&&a[4]==a[5]&&a[5]==ch)||(a[6]==a[7]&&a[7]==a[8]&&a[8]==ch)||(a[0]==a[3]&&a[3]==a[6]&&a[6]==ch)||(a[4]==a[1]&&a[1]==a[7]&&a[7]==ch)||(a[8]==a[5]&&a[5]==a[2]&&a[2]==ch)||(a[0]==a[4]&&a[4]==a[8]&&a[8]==ch)||(a[6]==a[4]&&a[4]==a[2]&&a[2]==ch))
        {
            cout<<"\nComputer Wins!!!!\n";
            flag=1;
        }
        else if((a[0]==a[1]&&a[1]==a[2]&&a[2]=='o')||(a[3]==a[4]&&a[4]==a[5]&&a[5]=='o')||(a[6]==a[7]&&a[7]==a[8]&&a[8]=='o')||(a[0]==a[3]&&a[3]==a[6]&&a[6]=='o')||(a[4]==a[1]&&a[1]==a[7]&&a[7]=='o')||(a[8]==a[5]&&a[5]==a[2]&&a[2]=='o')||(a[0]==a[4]&&a[4]==a[8]&&a[8]=='o')||(a[6]==a[4]&&a[4]==a[2]&&a[2]=='o'))
        {
            cout<<"\nPlayer Wins!!!!\n";
            flag=1;
        }
        else if(movenum==9||movenum==10)
        {
            cout<<"\nDraw...\n";
            flag=1;
        }
        return flag;
    }
    void boxdisplay()
    {
        cout << "     |     |     " << endl;
        cout << "  " << a[0] << "  |  " << a[1] << "  |  " << a[2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << a[3] << "  |  " << a[4] << "  |  " << a[5] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << a[6] << "  |  " << a[7] << "  |  " << a[8] << endl;
        cout << "     |     |     " << endl << endl;
    }

};

class multi
{

   static int count;
    public:
    char ch;
    multi(char x)
    {

         ch=x;
         count=0;
    }
    void box()
    {
        cout << "     |     |     " << endl;
        cout << "  " << a[0] << "  |  " << a[1] << "  |  " << a[2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << a[3] << "  |  " << a[4] << "  |  " << a[5] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << a[6] << "  |  " << a[7] << "  |  " << a[8] << endl;
        cout << "     |     |     " << endl << endl;

    }

    void entry()
    {
        char n;
        cout<<"Enter number:";
        cin>>n;
        //if(n>=1&& n<=9)
        {
            for(int i=0;i<9;i++)
            {
                if(a[i]==n)
                a[i]=ch;
            }
        count++;
        }

    }
    void check(multi m)
    {
        if((a[0]==a[1]&&a[1]==a[2]&&a[2]==ch)||(a[3]==a[4]&&a[4]==a[5]&&a[5]==ch)||(a[6]==a[7]&&a[7]==a[8]&&a[8]==ch)||(a[0]==a[3]&&a[3]==a[6]&&a[6]==ch)||(a[4]==a[1]&&a[1]==a[7]&&a[7]==ch)||(a[8]==a[5]&&a[5]==a[2]&&a[2]==ch)||(a[0]==a[4]&&a[4]==a[8]&&a[8]==ch)||(a[6]==a[4]&&a[4]==a[2]&&a[2]==ch))
        {cout<<"\nPlayer 1 wins!!!!\n";
        flag=1;}
        else if((a[0]==a[1]&&a[1]==a[2]&&a[2]==m.ch)||(a[3]==a[4]&&a[4]==a[5]&&a[5]==m.ch)||(a[6]==a[7]&&a[7]==a[8]&&a[8]==m.ch)||(a[0]==a[3]&&a[3]==a[6]&&a[6]==m.ch)||(a[4]==a[1]&&a[1]==a[7]&&a[7]==m.ch)||(a[8]==a[5]&&a[5]==a[2]&&a[2]==m.ch)||(a[0]==a[4]&&a[4]==a[8]&&a[8]==m.ch)||(a[6]==a[4]&&a[4]==a[2]&&a[2]==ch))
        {cout<<"\nPlayer 2 wins!!!!\n";
        flag=1;}
        if(count==9)
        {
            cout<<"\nDraw...\n";
            flag=1;
        }
    }
};
int multi::count=0;


int main()
{   int choice;
    char result;
    fstream ifile("jo.txt",ios::in);
    node *ptr=new node;
    char ch;
    int i=0;
    //cout<<"0";
    while(!ifile.eof())
    { //  cout<<"1";
        ch=ifile.get();
        ptr->arr[i++]=ch;
        ptr->link=NULL;
        if(ch=='$')
        {//   cout<<"2";
            ptr->arr[i-1]='\0';
            i=0;
            m.insert(ptr);
            ptr=new node;
        }
    }
    //m.disp();
    cout<<"1.Single player \n2.Multiplayer\n";
    cin>>choice;
    if(choice==1)
    {
        cout<<"HEY...\nTHIS IS LIAM,THE POSSIBILITY OF WINNING AGAINST ME IS..\nA PERFECT 0...\nANYWAY GIVE IT A GO!!!";
        system("pause");
        system("cls");
        int i=1,movenum=1;
        char plmove[9];
        plmove[0]='1';
        singleplayer sp;
        sp.boxdisplay();
        playmove:
        movenum++;
        plmove[i++]=sp.play();
        plmove[i]='\0';
        result=sp.check(movenum);
        system("cls");
        sp.boxdisplay();
        if(result==1)
            exit(1);//break;
        movenum++;
        plmove[i++]=sp.computermove(plmove,movenum);
        plmove[i]='\0';
        system("cls");
        sp.boxdisplay();
        result=sp.check(movenum);
        if(result==1)
            exit(1);//break;
        //system("cls");
        goto playmove;
    }
    else if(choice==2)
    {
        cout<<"Player1:x\nPlayer2:O\n";
        multi p1('x');
        multi p2('o');

       a:
       while(flag!=1)
       {

            p1.box();
            p1.entry();
            p1.check(p2);
            if(flag!=1)
            system("CLS");
            if (flag==1)
            {
                p1.box();
                goto a;
            }
            p2.box();
            p2.entry();
            p1.check(p2);
            if(flag!=1)
            system("CLS");
            if(flag==1)
            {
                p2.box();
                goto a;
            }

       }
    }
}
