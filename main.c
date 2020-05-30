#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//ADDITION
char* intal_add(const char* a, const char* b)
{

     char * sum = malloc(1001*sizeof(char));
     int i,j,c=0,l1,l2,s,k;
    
     l1=strlen(a);
     l2=strlen(b);
     
     i=l1-1;
     j=l2-1;
     
     k=l1>l2?l1:l2;
     sum[k]='\0';
     k--;
     
     while(i>=0 && j>=0)
     {
            
            s=(a[i]-48)+(b[j]-48)+c;
            sum[k]=s%10+48;
            c=s/10;
            i--;
            j--;
            k--;
     }
     
     if(i>=0)
     {
            while(i>=0)
           {
                  
                  s=(a[i]-48)+c;
                  sum[k]=s%10+48;
                  c=s/10;
                  i--;
                  k--;
           }
     
     }
     else if(j>=0)
     {
           while(j>=0)
           {
                  
                  s=(b[j]-48)+c;
                  sum[k]=s%10+48;
                  c=s/10;
                  j--;
                  k--;
           }
           
     }
     
     if(c>0)
     
     {
     for(i=strlen(sum);i>=0;i--)
    
      sum[i+1]=sum[i];
          sum[0]=c+48;
     
     }

 
    return sum;
    
}
/*
char * intal_add(const char * intal1 , const char * intal2)
{
char *newintal1 = malloc(1001 * sizeof(char));
  char *newintal2= malloc(1001 *sizeof(char));
  char *temp=malloc(1001 *sizeof(char));
  strcpy(newintal1,intal1);
  strcpy(newintal2,intal2);
  int firstintal1length=strlen(intal1);
  int secondintal2length=strlen(intal2);
  if(firstintal1length>secondintal2length){
    char*temp=newintal1;
    newintal1=newintal2;
    newintal2=temp;
  }
  int intal1length=strlen(newintal1);
  int intal2length=strlen(newintal2);
  //printf("%s\n",newintal1);
  //printf("%s\n",newintal2);
  int carry=0;
  char *newstring=malloc(1001 *sizeof(char));
  char *new1= malloc(1001 *sizeof(char));
  char *new2= malloc(1001 *sizeof(char));
  int i;
  int k=0;
  int l=0;
  for(int j=intal1length-1;j>=0;j--){
    new1[k]=newintal1[j];
    k++;
    
  }
  new1[intal1length]='\0';
  for(int m=intal2length-1;m>=0;m--){
    new2[l]=newintal2[m];
    l++;
    
  }
  new2[intal2length]='\0';
  //printf("%s",new2);
  for(i=0;i<intal1length;i++){
    int sum=(new1[i]-'0')+(new2[i]-'0')+carry;
    newstring[i]=sum%10 +'0';
    carry=sum/10;
  }
  for(i=intal1length;i<intal2length;i++){
    int sum=(new2[i]-'0') +carry;
    carry=sum/10;
    newstring[i]=sum%10+'0';
  }
  if(carry){
    newstring[i]=carry+'0';
  }
  int newlength=strlen(newstring);
  int h=0;
  newstring[newlength]='\0';
  char *new3=malloc(1001 *sizeof(char));
  for(int b=newlength-1;b>=0;b--){
    new3[h]=newstring[b];
    h++;
    
  }
  new3[newlength]='\0';
  free(newintal1);
  free(newintal2);
  free(new1);
  free(new2);
  free(temp);
  return new3;
}
*/

//COMPARE
int intal_compare(const char* intal1, const char* intal2)
{
  int l1=strlen(intal1);
  int l2=strlen(intal2);
  
    if(l1==l2)
    {
          for(int i=0;i<l1;i++)
          {
            if((intal1[i]-48)>(intal2[i]-48))
              return +1;
           
            if((intal1[i]-48)<(intal2[i]-48))
              return -1;
            
          }
      return 0;
    }
    
    else if(l1<l2)
        
        return -1;
  
    else
        return 1;
  

}

//SUBTRACTION
char * intal_diff(const char *a , const char *b)
{
      int t = strlen(a)>strlen(b)?strlen(a):strlen(b);
      char * re = malloc((t+1)*sizeof(char));
      char * a1 = malloc((strlen(a)+1)*sizeof(char));
      char * b1 = malloc((strlen(b)+1)*sizeof(char));

      int i,j,l1,l2,d,k;
      
      strcpy(a1,a);
      strcpy(b1,b);

      if(intal_compare(a1,b1)==-1)
      {

            char * temp = a1;
            a1=b1;
            b1=temp;
      }     

      l1=strlen(a1);
      l2=strlen(b1);

      
      i=l1-1;
      j=l2-1;
     
     k=l1>l2?l1:l2;
     re[k]='\0';
     k--;

     int carry=0;
     while(i>=0 && j>=0)
     {
           // printf("%s",r);
            d=(a1[i]-48)-(b1[j]-48)-carry ;
           
            if(d<0)
            {
                  d+=10;
                 
                  carry=1;
            }
            
            else{
            
            carry=0;
       
            }
            re[k]=d+'0';
            k--;
            i--;
            j--;
           // printf("i:%dj:%d\n",i,j);
         
     }
     
     if(i>=0)
     {
     
     
            while(i>=0)
           {
                  
                  
                  re[k]=a1[i]-carry;
                  carry=0;
                  i--;
                  k--;
           }
     
     }
     else if(j>=0)                                                                        
     {
           while(j>=0)
           {
                  
                  
                  re[k]=b1[j]-carry;
                  carry=0;
                  j--;
                  k--;
           }
           
     }
     
      int m=0;
      while(re[m]=='0' && m>=0)
                  m++;
      if(m==strlen(re))
      return "0";
      char * diff = malloc((strlen(re)+1)*sizeof(char));

      for(int i =0 ; i<strlen(re);i++)
       {
       diff[i]=re[m]; m++;
       }

      free(a1);
      free(b1);
      free(re);
      a1=NULL;
      b1=NULL;
      re=NULL;
return diff;
      
}

//FACTORIAL

char * intal_factorial( unsigned int n)
{   
    int s=2;
    int *arr = malloc(1001*sizeof(int));
    char *res = malloc(1001*sizeof(char)); 
    arr[0] = 1;
    int len = 1;
    int x = 0;
    int num = 0;
    while(s<=n)
    {
        x=0;
        num =0;
        while(x<len)
        {
            arr[x] = arr[x] *s;
            arr[x] = arr[x]+num;
            num = arr[x]/10;
            arr[x] = arr[x]%10;
            x++;
        }
        while(num!=0)
        {
            arr[len] = num%10;
            num = num/10;
            len++;
        }
        s++;
    }
    len--;
    int k=0;
    while(len>=0)
    {
        res[k++]=arr[len--]+'0';

    }
    res[k]='\0';
    free(arr);
    return res;
}
//MULTIPLICATION
char * intal_multiply(const char *a ,const char * b)
{
      int * result = malloc(sizeof(int)*(strlen(a)+strlen(b)));
      for( int i = strlen(a) - 1; i >= 0; i-- )
      {
            for( int j = strlen(b) - 1; j >= 0; j-- )
            {
             result[ i + j + 1 ] += ( b[ j ] - '0') * ( a[ i ] - '0' ); //single array to store intermediate values
            }
      }
      for( int i = strlen(a) + strlen(b); i >= 0; i-- )
      {
            if( result[ i ] >= 10 )
            {
            result[ i - 1 ] += result[ i ] / 10;
            result[ i ] %= 10;
            }
      }
      
      
     char * product = malloc(sizeof(char)*(strlen(a)+strlen(b)-1));
     int x = 0,k=0;
     while(x>=0 && result[x]==0)
     x++;
     while(x<strlen(a)+strlen(b))
     {
            product[k] = result[x]+48;
            k++;
            x++;           
     }
     product[k]='\0';
   
    free(result);
    result=NULL;
    return product;
 }



//FIBONACCI


char* intal_fibonacci(unsigned int n)
{ 
    char* fib1=malloc(sizeof(char)*2); 
    fib1[0]='0'; 
    fib1[1]='\0'; 
    char* fib2=malloc(sizeof(char)*2); 
    fib2[0]='1'; 
    fib2[1]='\0'; 
    char* temp; 
    for(int i=2;i<=n;i++)
    { 
           temp=fib1; 
    	   fib1=fib2; 
    	   fib2=intal_add(temp,fib2); 
        
    } 
    return fib2;       
}
char* coin_row_problem(char **arr, int n)
{
	char **dp[n+1];
	char *result=(char *)malloc(1001*sizeof(char));
	result="0";
	int i,j;
	for(i=0;i<n+1;i++)
		dp[i]="$";
	dp[0]="0";
	char *string[1000];
	char *ptr=arr;
	for(i=1;i<n+1;i++)
	{
		for (j=0;j<n;j++){
			int temp=n,k=0;
			while(temp!=0)
			{
				string[k++]=(temp%10)+'0';
				temp/=10;
			}
			string[k]='\0';
			if(intal_compare(arr[j],i)!=1 && intal_compare(dp[i-atoi(*(ptr+j))]+1,dp[i])==-1)
				dp[i]=intal_add(dp[i-atoi(*(ptr+j))],1);
		}
	}	
	strcpy(result,dp[n]);
	return result;
	
}



