/*
_________________________________________________________________________________________________________________________________________________________
TEAM MEMBERS : NEHA MODI  14ucs069
	       NEHA GUPTA  14ucs075
	       NISHANT GARG  14ucs077
	       NUPUR AGRAWAL  14ucs078
__________________________________________________________________________________________________________________________________________________________
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//________________________________________________________________________________________________________________________________________________________________

void find_binary(int i,int b)//print the respective binary number into output.txt using linr number return by find_opcode
{
	//printf("%d\n",i);
	FILE *fpb,*out;
	char c[40];
	int a=0;
	fpb=fopen("binary.txt","r");	
	out=fopen("output.txt","a");
	while(fgets(c,40,fpb) != NULL)
	{
		//l=strlen(c);
		c[strlen(c)-2]='\0';//to convert binary code into same line
		
		a++;
		if(a==i)
		{	
			fprintf(out,"%s",c);
			//puts(c);
			if(b==9){
				fprintf(out,"\n");

			}
			


		}	
	}
	fclose(fpb);
	fclose(out);
}


//______________________________________________________________________________________________________________________________________________________________

int* orr(int bin[],int i)
{	//printf("orr");
	int j,k;
	static int a []={0,0,0,0,0,0,0,0,0,0};
	for(j=(10-i-1),k=0;j<10 && k<=i;j++,k++)
	{
		if(bin[k] == 0)
		{	
			a[j]= 0;
//printf("%d\n",a[j]);
		}
		else
		{
			a[j] =1;
//printf("%d",a[j]);
		}
	}
int f;
for(f=0;f<10;f++){
printf("%d",a[f]);
}
printf("\n");
	return a;
}

//_____________________________________________________________________________________________________________________________________________________________

int* dec_bin(int n)  /* Function to convert decimal to binary.*/
{
	//printf("sbc");
    int rem, k,j ,bin[10],i=0;
	int bin_no[10];
	int * p;
    while (n!=0)
    {
	 bin[i++]= n % 2;

         n = n/ 2;
    }
	for( j=i-1,k=0;j>=0;j--,k++) 
      {
           bin_no[k]=bin[j];
	//printf("%d",bin_no[k]);
      }
	//printf("%d",k);
	
	p= orr(bin_no,k);
    return p;
}
        
//_____________________________________________________________________________________________________________________________________________________________	

void find_opcode(char ch[],int a)// find the opcode series number from opcode.txt and return its line number. 
{
	char c[20];
	int i=0;
	FILE *fpo;
	fpo = fopen ("opcode.txt","r");
	while(fgets(c,20,fpo) != NULL)
	{
		i++;
		//printf("%d",i);	
		int l;
		l=strlen(c);
		c[l-2]='\0';//to give null instead of \n(next line)
		//printf("%s %s\n",c,ch);
		if(strcmp(ch,c)==0)
		{
			//printf("%d",i);
			find_binary(i,a);	
			break;	
		}
		
	}
	
	close(fpo);
}

//___________________________________________________________________________________________________________________________________________________________________


void split(char ch[],int count)// split the instruction into single word
{
	int i,j;
	char str[]="00000000000000000000";
	FILE *out;
	out=fopen("output.txt","a");
      int num;
	int *array,*line;
	char arr[10];
	int a=0,b=0;
	for(j=0;j<4;j++)
	{
		for(i=0;i<15;i++,b++)
		{		
			if(ch[b]=='\n')
			{
				str[i] = '\0';
				//printf("str = %s",str);
				a=a+9;
				//printf("%d\n",a);
				find_opcode(str,a);
				a=0;
				//printf("%d\n",a);
				
				break;
			}
			else if(ch[b]==' ')
			{
				str[i] = '\0';
				//printf("str = %s",str);
				find_opcode(str,a);
				b++;
				//printf("%d",a);
				break;
			}
			else if (ch[b] == '#')
			{
				
				while(ch[b]!= '\n')
				{
				//printf("hii");
					b++;
					arr[i] = ch[b];
					
					i++;
					//puts(arr);
				}
				arr[i] ='\0';
				//puts(arr);
				num = atoi(arr);
				//printf("%d\n",num);
				array = dec_bin(num);
				int k;
				for( k = 0; k<10; k++)
				{
				//printf("%d",array[k]);
    				  fprintf(out, "%d",array[k]); 	
				}
				
				fprintf(out,"\n");
                   	}
		

			else if(ch[b]!=' ')
			{
				str[i]=ch[b];
				/**if(str[i]==':')
				{
					dec_bin(count);
					int x;
					for( x = 0; x<10; x++)
					{
    					  fprintf(out, "%d",line[x]); 	
					}
				} **/

			}
			
		}
		if(ch[b]=='\0')
		{
			break;
		}
		strcpy(str,"00000000000000000000");
	}
	fclose(out);		
}

//___________________________________________________________________________________________________________________________________________________________________

void main()
{
	int i=0;
	FILE *fp;
	int count=0;
	//char inp[10];
	//printf("enter input file : input.txt or input1.txt: \n");
	//scanf("%s",inp);
        fp = fopen("input.txt", "r");
	char c[20];
	while(fgets(c,20,fp) != NULL)
	{
		count++;
	       c[strlen(c)-2] = '\0';//putting the null(\0) at last instead of \n 
		split(c,count);// call function split
	}  
 	fclose(fp);
}


//_________________________________________________________________________________________________________________________________________________________________




