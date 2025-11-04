#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double compute(char syb, double a, double b);
double compute(char syb, double a, double b){
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
    else if(op == '/') return a / b;
    else if(op == '^') return pow(a, b);

}

int main(){
    double stack[30];
    int top = 0, i;
    char expr[30], ch;
    double result, x, y;

    printf("Postfix expression?\n");
    gets(expr);
    for(i = 0; i <= strlen(expr); i++){
        ch = expr[i];
        if(ch >= '0' && ch <= '9'){
            stack[top] = ch - 48;
            top++;
        }
        else{
            y = stack[--top];
            x = stack[--top];
            result = compute(ch, x, y);
            stack[top++] = result;
        }
    }

    printf("Answer is: %.2lf\n", stack[--top]);
    return 0;
}
