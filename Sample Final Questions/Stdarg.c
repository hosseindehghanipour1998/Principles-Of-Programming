#include <stdarg.h>
#include <stdio.h>

 /* minprintf: minimal printf with variable argument list */
 void minprintf(char *fmt, ...){
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
 }


 void myprintf(char *fmt , ...){
    va_list arg_pointer;
    char *temp;

    int int_val;
    double double_val;
    char *string_val;

    va_start(arg_pointer , fmt);

    for(temp = fmt ; *temp != '\0' ; temp++){
        if(*temp != '%'){
            putchar(*temp);
        }
        else
            if(*temp == '%'){
                temp++;
                if(*temp == 'd'){
                    int_val = va_arg(arg_pointer , int);
                    printf("%d" , int_val);
                }
                else if(*temp == 'f'){
                    double_val = va_arg(arg_pointer , double);
                    printf("%f" , double_val);
                }
                else if(*temp == 's'){
                    string_val = va_arg(arg_pointer , char*);
                    printf("%s" , string_val);
                }
            }
    }
     va_end(arg_pointer);
 }

 void myscanf(char *fmt , ...){
     va_list arg_pointer;
     char *temp;
     char c;

     int int_val;
     double double_val;
     char *char_val;
     char *str_val;

     va_start(arg_pointer , fmt);

     for(temp = fmt ; *temp != '\0' ; temp++){
        if(*temp != '%'){
            if(c = getchar() != *temp){
                printf("wrong input.");
                break;
            }
            continue;    
        }
        else
            if(*temp == '%'){
                temp++;
                if(*temp == 'd'){
                    int_val = va_arg(arg_pointer , int);
                    scanf("%d" , int_val);
                }
                else if(*temp == 'f'){
                     double_val = va_arg(arg_pointer , double);
                     scanf("%f" , double_val);
                }
                else if(*temp == 'c'){
                     char_val = va_arg(arg_pointer , char*);
                     scanf("%c" , char_val);
                }
                else if(*temp == 's'){
                    str_val = va_arg(arg_pointer , char*);
                    scanf("%s" , str_val);
                }
            }
     }
 }

 void main(int argc, char const *argv[])
 {
    char x[10]= "hello";
    myscanf("%s" , &x);
    printf("\n\n%s" , x);
 }
 