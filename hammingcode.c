#include &lt;stdio.h&gt;
#include &lt;math.h&gt;
int input[32];
int code[32];
int ham_calc(int,int);
void main()
{
int n,i,p_n = 0,c_l,j,k;
printf(&quot;Please enter the length of the Data Word: &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Please enter the Data Word:\n&quot;);
for(i=0;i&lt;n;i++)
{
scanf(&quot;%d&quot;,&amp;input[i]);
}

i=0;
while(n&gt;(int)pow(2,i)-(i+1))
{
p_n++;
i++;
}

c_l = p_n + n;

j=k=0;
for(i=0;i&lt;c_l;i++)
{

if(i==((int)pow(2,k)-1))

{
code[i]=0;
k++;
}
else
{
code[i]=input[j];
j++;
}
}
for(i=0;i&lt;p_n;i++)
{
int position = (int)pow(2,i);
int value = ham_calc(position,c_l);
code[position-1]=value;
}
printf(&quot;\nThe calculated Code Word is: &quot;);
for(i=0;i&lt;c_l;i++)
printf(&quot;%d&quot;,code[i]);
printf(&quot;\n&quot;);
printf(&quot;Please enter the received Code Word:\n&quot;);
for(i=0;i&lt;c_l;i++)
scanf(&quot;%d&quot;,&amp;code[i]);

int error_pos = 0;
for(i=0;i&lt;p_n;i++)
{
int position = (int)pow(2,i);
int value = ham_calc(position,c_l);
if(value != 0)
error_pos+=position;

}

if(error_pos == 1)
printf(&quot;The received Code Word is correct.\n&quot;);
else
printf(&quot;Error at bit position: %d\n&quot;,error_pos);

}
int ham_calc(int position,int c_l)
{
int count=0,i,j;
i=position-1;
while(i&lt;c_l)
{
for(j=i;j&lt;i+position;j++)
{
if(code[j] == 1)
count++;

}
i=i+2*position;
}
if(count%2 == 0)
return 0;
else
return 1;

}
