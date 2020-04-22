#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 50
char s[SIZE];
int top=-1;      
push(char elem)
{                       
    s[++top]=elem;
}
 
char pop()
{                      
    return(s[top--]);
}
 
int pr(char elem)
{                 
    switch(elem)
    {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    case '^': return 4;
    }
}

int k = 0;
int getop(char array[]){
    return array[k++];
}
 
void main()
{                        
    char infx[50],pofx[50],ch,elem;
    int i=0,k=0;

    printf("\n\nRead the Infix Expression ? ");
    scanf("%s",infx);
    push('#');
    while( (ch=infx[i++]) != '\0'){
        if( ch == '(') push(ch);
        else if(isalnum(ch))
            pofx[k++]=ch;
        else if( ch == ')'){
            while( s[top] != '(')
                pofx[k++]=pop();
            elem=pop(); 
        }
        else{       
            while( pr(s[top]) >= pr(ch) )
                pofx[k++]=pop();
            push(ch);
        }
    }
    while( s[top] != '#')     
        pofx[k++]=pop();
    pofx[k]='\0';          
    printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n",infx,pofx);


    int counter=0;
    int op;
    int op2;
    while((op = getop(pofx)) != '\0'){
        if( (op - '0') >= 0 && (op - '0') <= 9 )
            push(op - '0');
        else if(op == '+')
            push(pop()+pop());
        else if(op == '-'){
            op2 = pop();
            push(pop()-op2);
        }
        else if(op == '*')
            push(pop()*pop());
        else if(op == '/'){
            op2 = pop();
            push(pop()/op2);
        }
    }
    printf("\n\n\nRESULT : %d\n\n\n",pop());
    getch();
}