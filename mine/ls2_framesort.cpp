#include <bits/stdc++.h>
#include<windows.h>
using namespace std;
int fsize,noofframes=0;

struct frag{
string s;
int rno,len,seqno;

}frag[100],temp;
int main(){
    char msg[100];
    //int randnosarray[100][1];
    cout<<"enter message:";
    cin>>msg;
    //cout<<msg;
    cout<<"enter max frame len:";
    cin>>fsize;
    int c=0,i,j=0,k=0;
    while(c<strlen(msg)){
        i=rand()%fsize+1;

        for(j=0;j<i && (c+j)<strlen(msg);j++)
            frag[noofframes].s+=msg[c+j]; ///note this line

        frag[noofframes].rno=rand()%100;
        //randnosarray[i][0]=frag[noofframes].rno;

        frag[noofframes].seqno=k++;
        frag[noofframes].len=i;


        cout<<frag[noofframes].s<<endl;

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
for(i=0;i<noofframes*2;i++){
    Sleep(200);
    cout<<"\nsending message......\n";
}
for(i=0;i<noofframes*2;i++){
    Sleep(200);
    cout<<"\nreceiving message......\n";
}
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
