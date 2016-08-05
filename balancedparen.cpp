# include<stdio.h>
# define MAX_SIZE 100


void _printParenthesis(int pos, int n, int open, int close);

/* Wrapper over _printParenthesis()*/
void printParenthesis(int n)
{
    if (n>0){
        _printParenthesis(0, n, 0, 0);
    }
    return;
}

void _printParenthesis(int pos, int n, int open, int close)
{
    static char result[MAX_SIZE];
    
    if (n == close){
        printf("%s \n", result);
        return;
    }else{
        if (n > open){
            result[pos] = '(';
            _printParenthesis(pos+1, n, open+1, close);
        }
        if (close < open){
            result[pos] = ')';
            _printParenthesis(pos+1, n, open, close+1);
        }
    }
}


/* driver program to test above functions */
int main()
{

    printParenthesis(4);
    return 0;
}