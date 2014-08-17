#include<stdio.h>
 
int main()
{
    int a, b, c, d;
    for( a = 2 ; a <= 200 ; a++ )
        for( b = 2 ; b < a ; b++ )
            for( c = b ; c < a ; c++ )
                for( d = c ; d < a ; d++ )
                    if( a*a*a == b*b*b + c*c*c + d*d*d )
                        printf( "Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d );
    return 0;
}