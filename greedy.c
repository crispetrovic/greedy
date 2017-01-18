#include <stdio.h>
#include <cs50.h>
#include <math.h>

int q = 25;
int d = 10;
int n = 5;
int p = 1;
int balance = 0;
int cents_owed = 0;
int quarters = 0;
int dimes = 0;
int nickels = 0;
int pennies = 0;

// Determine the minimum amount of coins needed to give the appropriate change due
int main(void)
{
	// Declare variable
	float change_due = 0;

	// Get change due from user
	do {
	    printf("How much change is owed?\n");
	    change_due = GetFloat();
	    if(change_due == 0||change_due <= 0)
        printf("That was not a positive number.\n");
		   }
	while (change_due <= 0);

	// Round float and convert to cents
	cents_owed = round(change_due*100);

	// Start with largest coin amount and loop through available coins (quarters, dimes, nickles, pennies)
    quarters = (cents_owed / q);
    cents_owed = cents_owed - (quarters * q);

    dimes = (cents_owed / d);
    cents_owed = cents_owed - (dimes * d);

    nickels = (cents_owed / n);
    cents_owed = cents_owed - (nickels * n);

    pennies = (cents_owed / p);

    // Add the number of each coin owed
    int coin_count = quarters + dimes + nickels + pennies;

    printf("%d\n", coin_count);

    return 0;

}
