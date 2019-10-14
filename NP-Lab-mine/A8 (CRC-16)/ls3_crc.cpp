#include <bits/stdc++.h>
#include<windows.h>
using namespace std;
int gp[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
int a[100],b[100],k,len;
//x^16+x^12+x^5 + 1
void vsdiv(){
    int i,j,cnt=0;
    for(i=0;i<k;i++){
        if(a[i]==gp[0])///remember it is gp[0] zero not i
            for(j=i;j<=17+i;j++) a[j]=a[j]^gp[cnt++];
        cnt=0;
    }


}
int main(){
    int i,j;

    cout<<"\n enter the length of data frame: Ex: 4 )  ";
    cin>>len;
    cout<<"\n enter the message: binary input with space like :   1 0 1 1 ) ";
    for(i=0;i<len;i++) cin>>a[i];
    //cout<<a;
    for(i=0;i<17;i++)  a[len++]=0;
    k=len-17;
    ///take a copy to B
    for(i=0;i<len;i++) b[i]=a[i];

    vsdiv();
    cout<<"\ndb-------\n";
    for(i=0;i<len;i++) cout<<a[i];

    ///XOR b's elements with respective elements of a thats the data to be trasmitted
    for(i=0;i<len;i++) b[i]=b[i]^a[i];

    cout<<"\n data to be transmitted:";
    for(i=0;i<len;i++) cout<<b[i];

    cout<<"\nwhether you wish to introduce error(1) or not(0) : ";
    int f;
    cin>>f;


    if(f==0)//a to b
		for(i=0;i<len;i++)  a[i]=b[i];

	else
		for(i=0;i<len;i++)  a[i]=b[i]^(rand()%2);

    cout<<"\n recived message is=";
    for(i=0;i<len;i++) cout<<a[i];

    vsdiv();
    ///after dividing a should have all zeros if no error else not and display a as remainder
    for(i=0;i<len;i++)
        if(a[i]!=0)
    {
        cout<<"\n error  in recieved data";
        goto End;
    }

    End:cout<<"\n remender is:";
    for(i=0;i<len;i++) cout<<a[i];
    cout<<endl;








    return 0;
}
