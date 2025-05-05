#include&lt;stdio.h&gt;
#include&lt;time.h&gt;
#include&lt;stdlib.h&gt; /* To recognise exit function when compiling with gcc*/

void split(int[],int,int);
void combine(int[],int,int,int);
void main()
{
int a[15000],n, i,j,ch, temp;
clock_t start,end;
while(1)
{
printf("\n1:For manual entry of N value and array elements");
printf("\n2:To display time taken for sorting number of elements N in the range 500 to 14500");
printf("\n3:To exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nEnter the number of elements:");

scanf("%d",&n);
printf("\nEnter array elements: ");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
start=clock();
split(a,0,n-1);
end=clock();
printf("\nSorted array is: ");
for(i=0;i<n;i++)
printf("%d\t",a[i]);

printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));

break;

case 2:
n=500;
while(n&lt;=14500) {
for(i=0;i&lt;n;i++)
{
//a[i]=random(1000);
a[i]=n-i;
}
start=clock();
split(a,0,n-1);
//Dummy loop to create delay
for(j=0;j&lt;500000;j++){ temp=38/600;}
end=clock();
printf(&quot;\n Time taken to sort %d numbers is %f Secs&quot;,n, (((double)(end-start))/CLOCKS_PER_SEC));
n=n+1000;
}
break;
case 3: exit(0);
}
getchar();
}
}

void split(int a[],int low,int high)
{
int mid;
if(low&lt;high)
{
mid=(low+high)/2;
split(a,low,mid);
split(a,mid+1,high);
combine(a,low,mid,high);
}
}
void combine(int a[],int low,int mid,int high)
{
int c[15000],i,j,k;
i=k=low;
j=mid+1;
while(i&lt;=mid&amp;&amp;j&lt;=high)
{
if(a[i]&lt;a[j])
{
c[k]=a[i];
++k;
++i;
}
else
{
c[k]=a[j];
++k;
++j;
}
}
if(i&gt;mid)
{
while(j&lt;=high)
{
c[k]=a[j];
++k;
++j;
}
}
if(j&gt;high)
{
while(i&lt;=mid)
{
c[k]=a[i];
++k;
++i;
}
}
for(i=low;i&lt;=high;i++)
{
a[i]=c[i];
}
}
