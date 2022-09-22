#include <stdio.h>
//#include <conio.h>

int main()
{
	unsigned char first_char;
	int i,k,choose, high_bit, count_bits, current_bit;
	float second_float;
	long float2long;


//	clrscr();
	printf(" Your unsigned charis: ");
	scanf("%c",&first_char);
	printf("\n");
	for(i=7; i>=0; i--){
		printf(" %d",i);
		}
	printf("\n");
	for (i=7;i>=0;i--){
		printf(" %d", (first_char>>i)&1);
		}
	printf("\n\n ");
	printf("Your float is: ");
	scanf("%f",&second_float);
	printf("\n");
	float2long = *(long*)&second_float;
	k = 3;
	for(i = 31; i>=0;i--){
		if(i%10 == 0 && i>0){
		k--;
		}
		printf(" %d",k);
		}
	printf("\n");

	for(i = 31; i>=0;i--){
		printf(" %d",i%10);
		}
	printf("\n");
	printf("\n");
	for(i = sizeof(long)*8 - 1;i>=0; i--){
		printf(" %d",(float2long>>i)&1);
		}
	printf("\n");
	printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
	printf("|s|      exp      |                    mantissa                 |\n\n");
	printf("Select the var you want to change(1 - unsigned char; 2 - float): ");
	scanf("%d",&choose);
    printf("\nEnter the bit number, you want to start the change: ");
    scanf("%d", &high_bit);
    printf("\nEnter the length of the bit sequence: ");
    scanf("%d",&count_bits);
	if(choose == 1) {
        for (i = 0; i < count_bits; i++) {
            printf("Enter vlue of %d bit", high_bit);
            scanf("%d", &current_bit);
            if (current_bit == 1) {
                printf("\nbit is 1\n");
                first_char |= (1 << high_bit);

            } else {
                printf("\nbit is 0\n");
                first_char &= !(1 << high_bit);
            }
            high_bit++;
        }
        printf("%c", first_char);

    }
	else{
    printf("2");
	}


//	getch();

    return 0;
}