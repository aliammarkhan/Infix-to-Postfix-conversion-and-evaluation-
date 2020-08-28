#include<iostream>
#include<cstring>
#include<fstream>
#include<math.h>

using namespace std;


template<typename T>
class stack;

template<typename T>
class DynamicSafeArray
{
	
  	T   *data;
		int size;
	public:	
	 DynamicSafeArray()
	 {
	 	data=0;
	 	size=0;
	 }
	 DynamicSafeArray(int s)
	 {
	 	size=s;
	 	data=new T[s];
	 	memset(data,0,sizeof(int)*size);
	 }
	 
	  DynamicSafeArray (const  DynamicSafeArray &obj)
	  {
	  	  size=obj.size;
		  data=new T[size];
		  copy(obj.data,data+size,data);
	  	   
	}
	T &operator [](int i)const
	{
		
				return data[i];
		
	}

	
	 
	DynamicSafeArray &operator =(const DynamicSafeArray &obj)
	{
	     if(this!=&obj)
		 {
		    delete []data;
		    data=new T[obj.size];
		    size=obj.size;
			
			copy(obj.data,data+size,data);
			return *this;
			 	
		}	
		else return *this;
	  	
	}

 
	
	~ DynamicSafeArray()
	{
	    if(data!=0)
		delete[]data;
		data=0;	
		
	}
	void Resize(int s)
	{
		  if(s>size)
		  {
		  	int tempsize=size;
		  	int *temp=new int[size];
		  	copy(data,data+size,temp);
		  	delete[]data;
		  	size=s;
		  	data=new int[size];
		  	copy(temp,temp+size,data);
		  	for(int i=tempsize;i<size;i++)
		  	  data[i]=0;
		}
        		
		
   }
	
	friend class stack<T>;
};

template<typename T>
class stack
{
	
	private:
	int top;
	DynamicSafeArray<T> *Data;

	

	
	public:
		stack()
		{
			top=-1;
			*Data=0;
			
			
		}
		stack(int n)
		{
			Data=new DynamicSafeArray<T>(n);
			top=-1;
			
			
		}
		void push(T n)
		{
				
			top++;
			if(top>=Data->size)
			{
				cout<<"\n\nStack Overflow\n\n";
				exit(1);
				
			}
			(*Data)[top]=n;
		
		}
		T pop()
        {
        
        	T var;
        	var=(*Data)[top];
        	top--;
//        	if(top==-1)
//        	cout<<"\n\n Stack underflow\n\n";
        	return var;
         	
        	
		}	
		
		bool isempty()
		{
			if(top<=-1)
            return true;
			return false;			
			
		}
			bool full()
		{
			if(top==Data->size)
            return true;
			return false;			
			
		}
		void peek()
		{
			if(top!=-1)
			cout<<(*Data)[top]<<endl;
			else
			cout<<"\n\nStack is empty\n\n";
			
			
		}
		void display()
		{
			for(int i=top;i>=0;i--)
			{
			   
			   cout<<(*Data)[i]<<endl;	
				
			
			}
			
			
			
		}
		T capacity()
		{
			return Data->size;
		}
		T size()
		{
			
			return (top+1);
		}


int get_priority(char ch)
{
    if(ch=='-')
	   return 0;	
	else  if(ch=='+')
	      return 1;	
    else if(ch=='/')
	   return 2;	
	else if(ch=='*')
	return 3;
	else if(ch=='^')
	return 4;	
	else 
	return -1;
 		
 	
	
}	
	


char* infix_to_postfix(char s1[],int size)
 {

    int i=0,j=0,p1=-1,p2=-1;
    static char s2[100]={'\0'},temp;
    cout<<s1<<endl;
    s1[size]=')';
     push('(');
  
    


   

 	  while(!isempty())
 	  {
 
 	 
 	  	if(s1[i]=='(')
 	  	{
 	  	
 	  		push(s1[i]);
 	  		i++;
 
		}
		else if(s1[i]==')')
		{
			while(1)
			{
			
				
				temp=pop();
				if(temp=='(')
				{
					break;
					
				}
				
						
				s2[j]=temp;
				j++;
				
				s2[j]=' ';
				j++;
			
				
				
				
			}
			i++;

			
			
		}
		else if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='^')
		{
		
			if((*Data)[top]=='+'||(*Data)[top]=='-'||(*Data)[top]=='*'||(*Data)[top]=='/'||(*Data)[top]=='^')
			{
			  
			    p1=get_priority(s1[i]);
			
			
				while(1)
				{
					
		            p2=get_priority((*Data)[top]);
			    
					if(p1<=p2)
					{
						temp=pop();
						
				        s2[j]=temp;
						j++;
					
					    s2[j]=' ';
						j++;
						
					    p2=-1;
	         
					}
					else
					{
					push(s1[i]);
				    i++;
					break;
				    }
				
					
				}
		
				
			}
			else
			{
					
			push(s1[i]);
			i++;
		
		    }
		}
		else
		{
		
			s2[j]=s1[i];
			i++;
			j++;
			if(!(s1[i]>=48&&s1[i]<=57||s1[i]>=97&&s1[i]<=122))
			{
				s2[j]=' ';
				j++;
			}
			
			
		}
		
 	  
 
 	  	
	}


   
   
   		return s2;


 }	
 
 


	
	
	
};

template<typename stack>

int evaluation(char s[],stack &st,ofstream &writefile)
{

cout<<s<<endl;


   for(int i=0;i<strlen(s);i++)
        {
        		
        	if(s[i]>=97&&s[i]<=122)
			{
				cout<<"\ncannot be operated\n";
				writefile.close();
			 exit(1);
		       
			}
        }
   

		

  int n=strlen(s);
  
  int i=0;  
  
   while (i<n)
  {
 
 
    if(s[i]>=48&&s[i]<=57)
  	 {
  	 
  	 	char array[8]={'\0'};
		   int j=1;
  	 	array[0]=s[i];
  	     i++;

  	 	while(s[i]>=48&&s[i]<=57)
  	 	{
  	 	  array[j]=s[i];
			i++;
			j++;	
  	 	}
  
     int n=strlen(array);
     int x=0;
     for(int k=n-1,l=0;k>=0;k--,l++)
    {
    
	   x=x+(array[l]-48)*pow(10,k);
    } 
    
  	st. push(x);	
     
  
  	 	
  	}
    else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
    {
    
    	int result=0, a, b;
     if(s[i]=='-')
	   { 
	       b=st.pop();
	      a=st.pop();
	     result=a-b;
         i++;
	     st.push(result);
	   	}	
	else  if(s[i]=='+')
	      { 
	       b=st.pop();
	      a=st.pop();
	     
	     result=a+b;
	    
	       i++;
	     st.push(result);
	   	}
    else if(s[i]=='/')
	    { 
	       b=st.pop();
	      a=st.pop();
	     result=a/b;
           i++;
	     st.push(result);
	   	}	
	else if(s[i]=='*')
	 { 
	       b=st.pop();
	      a=st.pop();
	     result=a*b;
	      i++;
	 
	     st.push(result);
	   	}
	else if(s[i]=='^')
	 { 
	    b=st.pop();
	    a=st.pop();
	    result=pow(a,b);
	    st.push(result);
	     i++;
	 }
	 
	}
	else
	i++;
	

  	
 
  	}
  
int var=st.pop();
cout<<var;
return var;

 
}


int main()
{
  ofstream writefile("output.txt"); 

   ifstream readfile;
   readfile.open("ip 3.txt"); //input file

  char s1[100]={'\0'};
  readfile>>s1;
  readfile.close();
  
  
  
  int size=strlen(s1);
  char *postfix;
  
  
  
  stack<int> st(size);
 stack <char>s(size);

postfix=s.infix_to_postfix(s1,size);
writefile<<postfix;

   
int var=evaluation(postfix,st,writefile);
writefile<<endl;
writefile<<var;
writefile.close();




  return 0;
	
}
