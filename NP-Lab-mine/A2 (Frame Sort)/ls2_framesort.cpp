#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int fsize,noofframes=0;

struct fragm{
string s;
int rno,len,seqno;

}frag[100],temp;
int main(){
  
    string msg;
  
    cout<<"enter message:";

    getline(cin,msg);  ///			important line

   
    cout<<"enter max frame len:";
    cin>>fsize;
    int c=0,i,j=0,k=0;
    while(c<msg.length()){
        i=rand()%fsize+1;
        frag[noofframes].s=msg.substr(c,i); ///note this line
        frag[noofframes].rno=rand()%100;        
        frag[noofframes].seqno=k++;
        frag[noofframes].len=i;
        noofframes++;
        c+=i;
    }
    cout<<"\n message at the sender side\nseqno\t\trandom number\t\tlength\t\tmessage\n";
    for(i=0;i<noofframes;i++){
        cout<<frag[i].seqno<<"\t\t"<<frag[i].rno<<"\t\t\t"<<frag[i].len<<"\t\t"<<frag[i].s<<endl;

    }
///sorting according to random number
for(i=0;i<noofframes;i++)
{   j=i-1;temp=frag[i];
    while(j>=0 && frag[j].rno>temp.rno){
            frag[j+1]=frag[j];j--;

    }
    frag[j+1]=temp;
}
/////////////////////////////////////////////***************


/*
for(i=0;i<noofframes*2;i++){
    sleep(1);
    cout<<"\nsending message......\n";
}
for(i=0;i<noofframes*2;i++){
   sleep(1);
    cout<<"\nreceiving message......\n";
}



*/
////////////////////////////////////////////***************************
cout<<"\n message at the receiver side\nseqno\t\trandom number\t\tlength\t\tmessage\n";
    for(i=0;i<noofframes;i++){
        cout<<frag[i].seqno<<"\t\t"<<frag[i].rno<<"\t\t\t"<<frag[i].len<<"\t\t"<<frag[i].s<<endl;

    }
cout<<"\n message after sorting\n";
for(i=0;i<noofframes;i++)
{   j=i-1;temp=frag[i];
    while(j>=0 && frag[j].seqno>temp.seqno){
            frag[j+1]=frag[j];j--;

    }
    frag[j+1]=temp;
}
    for(i=0;i<noofframes;i++){
        cout<<frag[i].seqno<<"\t\t"<<frag[i].rno<<"\t\t\t"<<frag[i].len<<"\t\t"<<frag[i].s<<endl;

}
cout<<"message received :"<<msg<<endl;

    return 0;
}
/*
hello good morning
3
*/