#include<stdio.h>
void convert(char*a,char*b,char*c,char*d){
    int x,y,z;
    y=0;
    for(x=0;a[x]!=0;x++){
        y++;
        if(a[x]=='+'){
            d[0]='+';
            break;
        }
         if(a[x]=='*'){
            d[0]='*';
            break;
        }
        if(a[x]=='-'){
            d[0]='-';
            break;
        }
         if(a[x]=='/'){
            d[0]='/';
            break;
        }
        if(a[x]<48 || a[x]>58){
        	d[0]=a[x];
        	break;
		}
        b[x]=a[x]-48;
    }
    for(x=0;a[x+y]!=0;x++){
        c[x]=a[x+y]-48;
    }
}
void numtostring(int*x,int c,int g){
    int a,b;
    char x1[c];
    for(a=0;a<c;a++){
        x1[a]=(int)x[a];
        x1[a]=x1[a]+48;
    }
    if(x[0]!='\0'){
    	if(g==0){
    		for(a=0;a<c;a++){
    			printf("%c",x1[a]);
			}
		}
		else{
			printf("-%s",x1);
		}
	}
	else{
		printf("0");
	}
}
void leadingzeroes(int*ans,int d,int g){
    int a,b,c;
    b=0;
    for(a=0;a<d;a++){
        if(ans[a]==0){
            b++;
        }
        else{
            break;
        }
}
    if(b==d){
    	printf("0");
    	return;
	}
    c=d-b;
    int e;
    int x[c];
    for(e=0;e<c;e++){
        x[e]=ans[b+e];
    }
    if(ans[d-1]>9){
		int newans[2];
		newans[0]=ans[d-1]/10;
		newans[1]=ans[d-1]%10;
		char char_ans[2];
		char_ans[1]=(int)newans[1]+48;
		char_ans[0]=(int)newans[0]+48;
		printf("x as string is %s",char_ans);
		return;
	}
	numtostring(x,c,g);
    }
int crct_num(char*n1,char*n2,char*op,int b,int c){
	int i,j;
	for(i=0;i<b-1;i++){
		if(n1[i]>=0 && n1[i]<=9){
		}
		else{
			op[0]='#';
		}
	}
	for(i=0;i<c-1;i++){
		if(n2[i]>=0 && n2[i]<=9){
		}
		else{
			op[0]='#';
		}
	}
}
void add(int*big,int*small,int*ans,int d){
    int t,u;
    u=0;
    for(t=d-1;t>=0;t--){
        ans[t+1]=big[t]+small[t]+u;
        u=ans[t+1]/10;
        if(t!=0){
            ans[t+1]=ans[t+1]%10;
        }
    }
}
void add1(char*n1,char*n2,int b,int c){
    int d,e,f,g;
    if(b>=c){
        d=b;
        e=c;
        f=b-c;
    }
     else{
        d=c;
        e=b;
        f=c-b;
    }
    int big[d],small[d],ans[d+1];
     if(b>=c){
         for(g=0;g<f;g++){
             small[g]=0;
         }
         for(g=0;g<e;g++){
             small[g+f]=(char)n2[g];
             
         }
         for(g=0;g<d;g++){
             big[g]=(char)n1[g];
         }
     }
    else{
         for(g=0;g<f;g++){
             small[g]=0;
         }
         for(g=0;g<e;g++){
             small[g+f]=(char)n1[g];
         }
         for(g=0;g<d;g++){
             big[g]=(char)n2[g];
         }
    }
    add(big,small,ans,d);
    int r;
    if(ans[1]>9){
        r=ans[1]/10;
        ans[1]=ans[1]%10;
        ans[0]=r;
    }
    else{
        ans[0]=0;
    }
    d=d+1;
    leadingzeroes(ans,d,0);
}
void multiply(int*num1,int*num2,int*ans,int b,int c,int d){
	int a,x,y,z,i;
	for(i=b-1;i>=0;i--){
	x=0;
	for(a=c-1;a>=0;a--){
		ans[a+i+1]+=(num1[i]*num2[a])+x;
		if(a!=0){
			x=ans[a+i+1]/10;
			ans[a+i+1]=ans[a+i+1]%10;
			}
		}
	}
}
void multiply1(char*n1,char*n2,int b,int c){
    int d,e,f,g,h,i;
    d=b+c;
    e=0;
    g=0;
    if(b>=c){
    	f=b;
    	h=c;
	}
	else{
		f=c;
		h=b;
	}
    int num1[h],num2[f],ans[d];
    if(b>=c){
    	for(i=0;i<c;i++){
        num1[i]=(char)n2[i];
        e++;
    }
    for(i=0;i<b;i++){
        num2[i]=(char)n1[i];
        g++;
    }
}
    else{
    	for(i=0;i<b;i++){
        num1[i]=(char)n1[i];
        e++;
    }
    for(i=0;i<c;i++){
        num2[i]=(char)n2[i];
        g++;
    }
	}
    for(i=0;i<d;i++){
        ans[i]=0;
    }
    multiply(num1,num2,ans,h,f,d);
    if(ans[1]>9){
		ans[0]=ans[1]/10;
		ans[1]=ans[1]%10;
	}
	else{
		ans[0]=0;
	}
	leadingzeroes(ans,d,0);
}
void subtraction(int*num1,int*num2,int*ans,int d){
	int a,b,c,e,f,h,i;
	a=0;
	for(i=d-1;i>=0;i--){
		if(num2[i]>num1[i]){
			if(i==0){
				goto sub;
			}
			num1[i]+=10;
			num1[i-1]-=1;
		}
		sub:ans[i]=num1[i]-num2[i];
	}
}
void subtraction1(char*n1,char*n2,int b,int c){
	int d,e,f,g,h,j;
	if(b>=c){
		d=b;
		e=b-c;
	}
	else{
		d=c;
		e=c-b;
	}
	int num1[d],num2[d],ans[d];
	if(b>=c){
		int i;
		for(i=0;i<d;i++){
			num1[i]=(char)n1[i];
		}
		for(i=0;i<e;i++){
			num2[i]=0;
		}
		for(i=e;i<d;i++){
			num2[i]=(char)n2[i-e];
		}
	}
	else{
		int i;
		for(i=0;i<d;i++){
			num2[i]=(char)n2[i];
		}
		for(i=0;i<e;i++){
			num1[i]=0;
		}
		for(i=e;i<d;i++){
			num1[i]=(char)n1[i-e];
		}
	}
	g=0;
	for(j=0;j<d;j++){
		if(num1[j]>num2[j]){
			g=0;
			break;
		}
		if(num1[j]<num2[j]){
			g=1;
			break;
		}
		else{
			g=0;
		}
	}
	if(g==0){
		subtraction(num1,num2,ans,d);
		leadingzeroes(ans,d,g);
	}
	else{
		subtraction(num2,num1,ans,d);
		leadingzeroes(ans,d,g);
		
	}
}
int check_zero(char*n2,int c){
	for(int i=0;i<c;i++){
		if(n2[i]!=0){
			return 0;
		}
	}
	return 1;
}
int large(int*num1,int*n2,int large,int init){
    int i;
    for(i=0;i<large;i++){
        if(num1[i+init]>n2[i]){
            return 1;
        }
        if(n2[i]>num1[i+init]){
            return 2;
        }
    }
    return 3;
}
int large_num(int*num1,int*num2,int large){
	int i;
	for(i=0;i<large;i++){
		if(num1[i]<num2[i]){
			return 1;
		}
		if(num1[i]>num2[i]){
			return 3;
		}
	}
	return 2;
}
void division2(int*num1,int*num2,int x,int y){
    int a,b,c,i,j,g;
    a=x-y+1;
    b=y+1;
    int n2[b],quo[a];
    n2[0]=0;
    for(i=1;i<b;i++){
        n2[i]=num2[i-1];    }
    for(i=0;i<a;i++){
        quo[i]=0;
    }
    for(i=0;i<a-1;i++){
        g=large(num1,n2,b,i);
        while(g!=2){
            quo[i+1]+=1;
            for(j=b-1;j>=0;j--){
                if(n2[j]>num1[j+i]){
                    if(j==0){
                        goto sub;
                    }
                    num1[i+j]+=10;
                    num1[i+j-1]-=1;
                }
                sub:num1[i+j]-=n2[j];
            }
            g=large(num1,n2,b,i);
         }
    }
    if(quo[1]>9){
    	quo[0]=quo[1]/10;
    	quo[1]=quo[1]%10;
	}
	printf("Quotient: ");
    leadingzeroes(quo,a,0);
    printf("\nReminder: ");
    leadingzeroes(num1,x,0);
}
void equi_division(int*num1,int*num2,int large){
	int quo[large],rem[large],l[large];
	int i,j,g,c,d;
	for(i=0;i<large;i++){
		quo[i]=0;
		l[i]=num2[i];
	}
	g=large_num(num1,num2,large);
	while(g!=1){
		c=0;
		for(j=large-1;j>=0;j--){
			num2[j]+=l[j];
			num2[j]+=c;
			if(num2[j]>9){
				c=num2[j]/10;
				num2[j]=num2[j]%10;
			}
			else{
				c=0;
			}
		}
		g=large_num(num1,num2,large);
		quo[large-1]+=1;
		for(j=large-1;j>=0;j--){
			if(quo[j]>9){
				quo[j-1]+=1;
				quo[j]=quo[j]%10;
			}
		}
	}
	printf("\nQuotient:");
	leadingzeroes(quo,large,0);
	subtraction(num2,l,num2,large);
	printf("\nReminder:");
	subtraction(num1,num2,rem,large);
	leadingzeroes(rem,large,0);
}
void division1(char*n1,char*n2,int b,int c){
	if(check_zero(n2,c)==1){
		printf("Undefined");
		return;
	}
	int x,y,i;
	x=b;
	y=c;
	for(i=0;n1[i]==0;i++){
		x--;
	}
	for(i=0;n2[i]==0;i++){
		y--;
	}
	int num1[x],num2[y];
	for(i=0;i<x;i++){
		num1[i]=(char)n1[i+b-x];
	}

	for(i=0;i<y;i++){
		num2[i]=(char)n2[i+c-y];
	}
	if(y>x){
		printf("\nQuotient: 0");
		printf("\nRemainder: ");
		leadingzeroes(num1,x,0);
	}
	if(y==x){
		int g;
		g=0;
		for(i=0;i<x;i++){
			if(num1[i]>num2[i]){
				g=1;
				break;
			}
			if(num2[i]>num1[i]){
				g=2;
				break;
			}
		}
		if(g==0){
			printf("\nQuotient: 1");
			printf("\nRemainder: 0");
			return;
		}
		if(g==2){
			printf("\nQuotient: 0");
		    printf("\nRemainder: ");
		    leadingzeroes(num1,x,0);
		    return;
		}
		if(g==1){
			equi_division(num1,num2,x);
		}
	}	
	if(x>y){
        division2(num1,num2,x,y);
	}
}
int main(){
    char qn[102],n1[51],n2[51],op[2];
    back:printf("Calc>>");
    scanf("%s",qn);
    if(qn[0]=='E' || qn[0]=='e' && qn[1]=='x' && qn[2]=='i' && qn[3]=='t'&& qn[4]==0){
    	printf("Thank you!!");
		return 0;
	}
    convert(qn,n1,n2,op);
    int a,b,c;
    b=0;
    c=0;
    for(a=0;qn[a]!=op[0];a++){
        b++;
    }
    for(a=0;qn[a+b+1]!=0;a++){
        c++;
    }
    crct_num(n1,n2,op,b,c);
    if(op[0]=='+'){
        add1(n1,n2,b,c);
        goto random;
    }
    else if(op[0]=='*'){
        multiply1(n1,n2,b,c);
        goto random;
    }
    else if(op[0]=='-'){
        subtraction1(n1,n2,b,c);
        goto random;
    }
    else if(op[0]=='/'){
    	division1(n1,n2,b,c);
        goto random;
    }
    else{
    	printf("Invalid Question");
	}
	random:printf("\n");
	goto back;
}
