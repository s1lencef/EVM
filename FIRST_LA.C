#include <stdio.h>

void correct_i_input(int*i){
    while( !scanf("%d",i) ){
        scanf("%*s");
        printf("Incorrect input!\n");
    }
}

void output_char(unsigned char u){
    int i;

    printf("\n");
    printf("Its bit representation: \n\n");

    for(i=7; i>=0; i--){
        printf(" %d",i);
    }

    printf("\n");

    for (i=7;i>=0;i--){
        printf(" %d", (u>>i)&1);
    }

    printf("\n\n ");
}
void output_float(long l){
    int i,k = 3;

    printf("Its bit representation: \n\n");
    for(i = 31; i>=0;i--){
        if(i%10 == 9 && i>0){
            k--;
        }
        printf(" %d",k);
    }

    printf("\n");

    for(i = 31; i>=0;i--){
        printf(" %d",i%10);
    }

    printf("\n\n");

    for(i = sizeof(long)*8 - 1;i>=0; i--){
        printf(" %d",(l>>i)&1);
    }
    printf("\n");
    printf("|-|- - - - - - - -|- - - - - - - - - - - - - - - - - - - - - - -|\n");-
    printf("|s|      exp      |                    mantissa                 |\n\n");
}

void c_change(int count_bits, int high_bit,unsigned char *c){
    int i, current_bit;
    for (i = 0; i < count_bits; i++) {
        printf("Enter vlue of %d bit: ", high_bit);
        correct_i_input(&current_bit);
        if (current_bit == 1) {
            *c |= (1 << high_bit);
        }
        else {
            *c = *c &(~(1 << high_bit));
        }
        high_bit--;
    }

}
void f_change(int count_bits, int high_bit,long *l){
    int i, current_bit;
    for (i = 0; i < count_bits; i++) {
        printf("Enter vlue of %d bit: ", high_bit);
        correct_i_input(&current_bit);
        if (current_bit == 1) {
            printf("\n1\n");
            *l |= (1 << high_bit);
        }
        else {
            printf("\n0\n");
            *l &=  (~(1 << high_bit));
        }
        printf(" current_value:  %d \n",(*l>>high_bit)&1);
        high_bit++;
        
    }
}

void get_setup(int*high_bit, int*count_bits){
    printf("\nEnter the bit number, you want to start the change: ");
    correct_i_input(high_bit);
    printf("\nEnter the length of the bit sequence: ");
    correct_i_input(count_bits);

}


int main()
{
	unsigned char first_char;
	int choose, high_bit, count_bits;
	float second_float;
	long float2long;
    clrscr();
    printf("%d %d\n", sizeof(long), sizeof(float));
    while(1) {
       printf("Select the variable you want to work with(1 - unsigned char; 2 - float): ");
        correct_i_input(&choose);

        if (choose == 1) {

            printf(" Your unsigned char is: ");
            fflush (stdin);
            while( !scanf("%*c%c", &first_char) ){
                scanf("%*s");
                printf("Incorrect input!\n");
            }



            output_char(first_char);

            get_setup(&high_bit, &count_bits);

            c_change(count_bits, high_bit, &first_char);

            printf("\nNow char is \"%c\" \n", first_char);

            output_char(first_char);

        } else {

            printf("Your float is: ");
            while( !scanf("%f",&second_float) ){
                scanf("%*s");
                printf("Incorrect input!\n");
            }
            printf("\n\n");

            float2long = *(long *) &second_float;
            output_float(float2long);

            get_setup(&high_bit, &count_bits);

            f_change(count_bits, high_bit, &float2long);
            second_float = *(float *) &float2long;
            printf("\n\n");
            printf("\nNow float is \"%f\" \n", second_float);
            output_float(float2long);
        }
        printf("Do you want to continue? 1 - yes, 0 - no\n");
        correct_i_input(&choose);
        if(choose == 1) continue;
        else {
            printf("\nProgramm finished!\n");
            return 0;

        }


    }
    getch();

}