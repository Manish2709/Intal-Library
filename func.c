#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int min(int a,int b)
{
	return(a<b)?a:b;
}
static int convert_to_int(char ch) 
{
  return (int)(ch - 48);
}
static char convert_to_char(int in)
{
  return (char)(in + 48);
}
static char* removezeroes(char* a,int n) 
{ 
	int count = 0; 
	for (int i = 0; i < n; i++)
	{
		if(a[i] == '0')
		{
			count++;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i+count];
	}
	int j = 0;
	while(count)
	{
		a[n-j] = '\0';
		count--;
		j++;
	}
	return a;
} 
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
//COMPARE
int intal_compare(const char* intal1, const char* intal2)
{
	if(strlen(intal1)>strlen(intal2))
		return 1;
	else if(strlen(intal2)>strlen(intal1))
		return -1;
	else
	{
		int i=0;
		while(intal1[i]==intal2[i] && i<strlen(intal1))
			i++;
		if(i==strlen(intal1))
			return 0;
		else if(intal1[i]>intal2[i])
			return 1;
		else
			return -1;
	}
}
//SUBTRACTION
char* intal_diff(const char* intal1,const char* intal2)
{
  int cmp = intal_compare(intal1, intal2);
  if(cmp == 0)
  {
    char* result = (char*)malloc(2 * sizeof(char));
    result[0] = '0';
    result[1] = '\0';
    return result;
  }
  else if(cmp == -1)
  {
    const char* tmp = intal1;
    intal1 = intal2;
    intal2 = tmp;
  }
  int l1 = strlen(intal1);
  int l2 = strlen(intal2);
  int l = (l1 > l2)? l1: l2;
  int s = l1 + l2 - l;
  int i, d1, d2, rd, c = 0;
  char* result = (char*)malloc((l + 1) * sizeof(char));
  for(i = 0 ; i < s; ++i)
  {
    d1 = convert_to_int(intal1[l1 - 1 - i]) - c;
    d2 = convert_to_int(intal2[l2 - 1 - i]);
    c = (d2 > d1)? 1: 0;
    d1 = (d2 > d1)? d1 + 10: d1;
    rd = d1 - d2;
    result[l - 1 - i] = convert_to_char(rd);
  }
  while(i < l)
  {
    rd = convert_to_int(intal1[l1 - 1 - i]) - c;
    c = (rd > -1)? 0: 1;
    rd = (rd > -1)? rd: rd + 10;
    result[l - 1 - i] = convert_to_char(rd);
    ++i;
  }
  for(i = 0; i < l; ++i)
  {
    if(result[i] != '0')
      break;
  }
  result[l] = '\0';
  int trim = i;
  if(trim != 0)
  {
    for(i = 0; i <= l - trim; ++i)
      result[i] = result[i + trim];
    result = realloc(result, (l - trim + 1) * sizeof(char));
  }
  return result;
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
char* intal_multiply(const char* s1, const char* s2)
{
	  int i,j;
	  int temp,finallen;
	  int l1 = strlen(s1);
	  int l2 = strlen(s2); 
	  int *a = malloc(sizeof(int)*l1);
	  int *b = malloc(sizeof(int)*l2);
	  int *ans = calloc((l1+l2),sizeof(int));
	  for(i = l1-1,j=0;i>=0;i--,j++)
    {
        a[j] = s1[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        b[j] = s2[i]-'0';
    }
    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            ans[i+j] += b[i]*a[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        temp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + temp;
    }
    for(; i>= 0;i--)
    {
        if(ans[i] >=0 && ans[i] <=9)
            break;
    }
	  finallen = i;
	  char* finalres = calloc(finallen,sizeof(int));
    for(j=0;i >= 0;i--,j++)
    {
		    if(ans[i] >=0 && ans[i] <=9)
			      finalres[j] = ans[i] + '0';
		    else
		    {
			      finalres[j] = '\0';
			      break;
		    }
    }
	 free(ans);free(a);free(b);
	 removezeroes(finalres,finallen);
	 return finalres;
}
char* intal_pow(const char* intal1, unsigned int n)
{
	char *result = "1";
	char * base =(char*)malloc(sizeof(char)*1001);
	strcpy(base,intal1);
	if(*base == '0')
		return "0";
	while(n>0)
	{
		if(n & 1)
		{
			result = intal_multiply(result,base);
		}
		n = n>>1;
		base = intal_multiply(base,base); 		
	} 
	return result;
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
char* intal_mod(const char* intal1,const char* intal2)
{
  int cmp = intal_compare(intal1, intal2);
  if(cmp == -1)
  {
    char* result = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
    strcpy(result, intal1);
    return result;
  }
  else if(cmp == 0)
  {
    char* result = (char*)malloc((2) * sizeof(char));
    strcpy(result, "0");
    return result;
  }
  int p = strlen(intal2);
  int stop = strlen(intal1);
  char* current = (char*)malloc((strlen(intal2) + 2) * sizeof(char));
  for(int i = 0; i < p; ++i)
    current[i] = intal1[i];
  current[p] = '\0';
  do 
  {
    if(intal_compare(current, intal2) == -1 && p < stop)
    {
      int len = strlen(current);
      if(strcmp(current, "0") == 0)
        len = 0;
      current[len] = intal1[p];
      current[len + 1] = '\0';
      ++p;
    }
    if(intal_compare(current, intal2) != -1)
    {
      char* result = intal_diff(current, intal2);
      while(intal_compare(result, intal2) > -1)
      {
        char* tmp = result;
        result = intal_diff(result, intal2);
        free(tmp);
      }
      strcpy(current, result);
      free(result);
    }    
  } while(p < stop);
  current = realloc(current, (strlen(current) + 1) * sizeof(char));
  current[strlen(current) + 1] = '\0';
  return current;
}
char* intal_gcd(const char* intal1,const char* intal2)
{
  char* a = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
  strcpy(a, intal1);
  char* b = (char*)malloc((strlen(intal2) + 1) * sizeof(char));
  strcpy(b, intal2);
  int flag = strcmp(a, "0");
  while(flag != 0)
  {
    char* tmp = b;
    b = a;
    a = intal_mod(tmp, a);
    free(tmp);
    flag = strcmp(a, "0");
  }
  free(a);
  return b;
}
char* coin_row_problem(char **arr, int n)
{
	if(n ==0)
	{
		return "0";
 	}
        char* prev = "0";
        char *cur = arr[0];
        char*next;
        for(int i=2;i<=n;i++)
	      {
          	char*arrvalue=arr[i-1];
          	char*temp=intal_add(prev,arrvalue);
          	int value=intal_compare(temp,cur);
          	if(value==1)
	  	      {
               		next=temp;
          	}
         	else
	 	      {
               		next=cur;
         	}
         	prev=cur;
         	cur=next;
        }
        return cur;
}
char* intal_bincoeff(unsigned int n, unsigned int k)
{
    char **c = (char**) malloc((k+1) * sizeof(char*));
    for(int j = 0; j < n; j++)
    {
        c[j] = (char*) malloc(1001 * sizeof(char));
    }
    for(int j=0;j<=k;j++)
    {
             c[j]="0";
    }
    c[0]="1";
    char*temp;
    char*temp1; 
    for(int i=1;i<=n;i++)
    { 
        for(int j=min(i,k);j>0;j--)
        { 
             temp=c[j];
             temp1=c[j-1];
             temp=intal_add(temp,temp1);
             c[j]=temp;                   
        }
    } 
    return c[k]; 
}
int intal_min(char **arr, int n)
{
	int result=0,i;
	for(i=0;i<n;i++)
		if(intal_compare(arr[result],arr[i])==1)
			result=i;
	return result;
}
// Returns the offset of the largest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_max(char **arr, int n)
{
	int result=0,i;
	for(i=0;i<n;i++)
		if(intal_compare(arr[result],arr[i])==-1)
			result=i;
	return result;
}
// Returns the offset of the first occurrence of the key intal in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000
int intal_search(char **arr, int n, const char* key)
{
	int result=-1,i;
	for(i=0;i<n;i++)
		if(intal_compare(arr[i],key)==0)
		{
			result=i;
			break;
		}
	return result;
}
// Returns the offset of the first occurrence of the key intal in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
// The implementation should be a O(log n) algorithm.
static int binsearch(char **arr,int start,int end,const char *key)
{
	while (start <= end) 
	{ 
        	int mid=start+(end-start)/2; 
        	if(intal_compare(arr[mid],key)==0) 
            		return mid;  
        	if(intal_compare(arr[mid],key)==-1) 
            		start=mid+1; 
        	else
            		end=mid-1; 
    	}  
    	return -1; 
}

int intal_binsearch(char **arr, int n, const char* key)
{
	return binsearch(arr,0,n,key);
}
// Sorts the array of n intals.
// 1 <= n <= 1000
// The implementation should be a O(n log n) algorithm.
//Implementation of merge sort in INTAL datatype
static void Merge(char** arr, int l, int m, int e)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = e-m;
	char** Left_half =(char**)malloc(n1*sizeof(char*));
	char** Right_half =(char**)malloc(n2*sizeof(char*));
	for(i=0; i<n1; i++)
	{
		Left_half[i] = arr[l+i];
	}
	for(j=0; j<n2; j++)
	{
		Right_half[j] = arr[m+j+1];
	}
	i=0; j=0; k=l;
	while(i<n1 && j<n2)
	{
		if(intal_compare(*(Left_half+i),*(Right_half+j)) != 1)
		{
			arr[k] = Left_half[i];
			i++;
		}
		else if(intal_compare(*(Left_half+i),*(Right_half+j)) == 1)
		{
			arr[k] = Right_half[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k] = Left_half[i];
		i++; k++;
	}
	while(j<n2)
	{
		arr[k] = Right_half[j];
		j++; 
		k++;
	}
	free(Left_half);
	free(Right_half);
}
static void MergeSort(char** arr, int start, int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid+1, end);
		Merge(arr, start, mid, end);
	}
}
void intal_sort(char **arr, int n)
{
	int start = 0, end = n-1;
	MergeSort(arr, start, end);
}


