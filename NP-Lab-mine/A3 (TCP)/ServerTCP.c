#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<math.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{int welcome,new_soc,n;
char buffer[1024],fname[20];
struct sockaddr_in addr;
FILE *fp;
welcome=socket(PF_INET,SOCK_STREAM,0);
addr.sin_family=AF_INET;
addr.sin_port=htons(5001);
addr.sin_addr.s_addr=inet_addr("127.0.0.1");
bind(welcome,(struct sockaddr *)&addr,sizeof(addr));
printf("\nServer Online\n");
listen(welcome,5);
new_soc=accept(welcome,NULL,NULL);
recv(new_soc,fname,50,0);
printf("\nRequestingm file name:%s\n",fname);
fp=fopen(fname,"r");
if(fp==NULL)
{
send(new_soc,"\nFile not found\n",15,0);
}
else
{
while((fgets(buffer,1024,fp))!=NULL)
{
send(new_soc,buffer,strlen(buffer),0);
}
}
printf("\nRequest sent\n");
fclose(fp);
return 0;
}
/*
best possible program


*/