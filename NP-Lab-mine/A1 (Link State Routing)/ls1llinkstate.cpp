#include <iostream>

using namespace std;
#define  inf 999
//function correct aagi oodu saaku
void fndij(int   cm[][100],int non,int so,int de,int * vis,int * pa,int * dis){

    int i,j,k,a,vmin;
    for (i=0;i<non;i++){vis[i]=0;pa[i]=so;dis[i]=cm[so][i];}
    vis[so]=1;
    while(true){
        a=-1;vmin=inf;
        for(i=0;i<non;i++){
            if(vis[i]==0){
                if(dis[i]<vmin){
                    vmin=dis[i];
                    a=i;
                }
            }
        }
        if(a==-1)return;
        vis[a]=1;
        if(a==de) return;
        for(i=0;i<non;i++){
           if(vis[i]==0) //check removing this
            if( (dis[a]+cm[a][i]) < dis[i]){
                    dis[i]=(dis[a]+cm[a][i]);
                    pa[i]=a;

            }
        }

    }




}
int cm[100][100],non,so,de,pa[100],vis[100],dis[100];
//int cm[][9]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
void pcm(){
    int i,j;
    cout<<endl;
    for (i=0;i<non;i++)
    {
        for(j=0;j<non;j++)
            cout<<cm[i][j]<<" ";
        cout<<endl;

    }
        cout<<endl;

}
//Link state routnng
int main()
{
    int i,j,k;
    cout << "Hello world! enter number of nodes: " << endl;
    cin>>non;
    cout<<"\nenter the cost matrix\n";
    for (i=0;i<non;i++)
        for(j=0;j<non;j++)
            cin>>cm[i][j];
    cout<<endl;
    pcm();
    for (i=0;i<non;i++)
        for(j=0;j<non;j++){
            if(j!=i)
            cout<<"sending hello packets from:"<<(char)(i+65)<<" to:"<<(char)(j+65)<<" \n"<<"sending echo packets from:"<<(char)(j+65)<<" to:"<<(char)(i+65)<<" \n";;
        }

for (i=0;i<non;i++){

        so=i;
        cout<<"\n\n\nfrom source:"<<(char)(so+65);

        for(j=0;j<non;j++){
            de=j;
            cout<<"\nto destination:"<<(char)(de+65)<<endl;
        fndij(cm,non,so,de,vis,pa,dis);
        if (dis[de]>=inf){
            cout<<"no path exitst\n";


        }
        else{
        	cout<<" --"<<(char)(de+65);
                k=pa[j];// just a temporary variable

            do{
                cout<<" --"<<(char)(k+65)<<" --";k=pa[k];
            }while(k!=so);
            cout<<" --"<<(char)(so+65)<<"\ncost="<<dis[de]<<endl;
        }



        }

}



    return 0;
}
/*
4
0 2 999 999
2 0 2 5
999 2 0 1
999 5 1 0


*/