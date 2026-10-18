#include <stdio.h>
#include "div_diagnosis.h"

typedef struct {int vb, va, expected; const char *name;} TestCase;
int main(void)
{
    const TestCase tests[] = {
        {455,909,0,"DIV0 nominal"},
        {0,1000,1,"DIV1 R1 open"},
        {313,938,6,"DIV6 R1=20K"},
        {588,886,5,"DIV5 signature despite nominal physical 10K"},
        {454,912,0,"DIV0 observed"},
        {0,833,4,"DIV4 R2 short"}
    };
    unsigned int i;
    for(i=0; i<sizeof(tests)/sizeof(tests[0]); ++i)
    {
        int actual=DivClassify(tests[i].vb, tests[i].va);
        printf("%-43s VB=%d VA=%d -> %d %s\n",tests[i].name,
               tests[i].vb,tests[i].va,actual,actual==tests[i].expected ? "PASS":"FAIL");
        if(actual!=tests[i].expected)return 1;
    }
    return 0;
}
