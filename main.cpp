#include <stdio.h>
#include <math.h>
#include <time.h>
float Q_rsort(float number){
    long i; // bit width : (2^31 = 2147483648 > 2147395600 = 46340^2)
    float x2, y;
    // y = 1 / sqrtf(x) = 1 / sqrtf(number)
    // x2 = number * 0.5F;
    const float threehalfs = 1.5F;// 1.5F = 1.5

    x2 = number * 0.5F;// 0.5F = 0.5
    y = number;//
    // y = number
    i = * ( long * ) &y;
    // The address of y is cast to a pointer to an integer, and then dereferenced to obtain the integer value from the address.
    i = 0x5f3759df - ( i >> 1 );//give me the mathmatical meaning of this line
    // 0x5f3759df = 1597463007 = 1011111101110110100111011110111 = 2^31
    // 0x5f3759df - ( i >> 1 ) = 2^31 - i / 2
    y = * ( float * ) &i;
    //cast the address of i to a pointer to a float, and then dereference the pointer to obtain the float value from the address.
    y = y * ( threehalfs - ( x2 * y * y ) );
    // y = y * ( 1.5 - ( number * 0.5 * y * y ) )
    // what is that meaning of newton iteration?
    return y;
}

int test_speed_qsort(){
    int i;
    clock_t start, finish;
    float x = scanf("%f", &x);
    start = clock();
    for(i = 0; i < 1000000; i++){
        Q_rsort(x);
        //Q_rsort(x);
    }
    finish = clock();
    return (finish - start);
}

//Test two sqrtf functions speed in calculating 1/sqrtf(x)
int test_speed_of_two_function(){
    int speed1,speed2;
    speed1 = test_speed_qsort();
    printf("The speed of sqrtf(x) is %d,and the final value is %f\n", speed1, y1);
    return 0;
}


int main(){
      test_speed_of_two_function();
    return 0;
}
