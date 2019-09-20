/*
 * 		loan_schedule.c
 *  	Created on: Nov 25, 2018
 *      Author: William Lyons
 */

#include<stdio.h>
#include<math.h>

double monthlypayment(double loan_amount, double apr, int num_payments){

	double x = pow((1+apr),num_payments);
	double monthly_payment = loan_amount*((apr * x)/(x - 1));
	return monthly_payment;
}
void amortization_schedule(double const mp, double balance, double apr, double num_payments){
	double interest, principle;
	int i,payment_num = 0;
	printf("\n# \t Payment \t Principle \t Interest \t Balance");
	for(i=1;i<=num_payments;i++){
		interest = balance*apr;
		principle = mp - interest;
		balance = balance - principle;
		payment_num++;
		printf("\n%d \t %.2lf \t %.2lf \t %6.2lf \t %.2lf",payment_num,mp,principle,interest,balance);
	}
}

int main(){
	int num_payments;
	double loan_amount, apr, mp;


	printf("Enter amount of loan : $");
	scanf("%lf",&loan_amount);
	printf("Enter Annual Interest Rate : %%");
	scanf("%lf",&apr);
	printf("Enter Number of Payments : ");
	scanf("%d",&num_payments);

	apr = (apr/12)/100;

	mp = monthlypayment(loan_amount, apr, num_payments);

	printf("\nMonthly Payment: $%.2lf\n",mp);

	amortization_schedule(mp,loan_amount,apr,num_payments);
}


