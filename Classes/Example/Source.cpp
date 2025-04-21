#include <iostream>
#include "BillingSystem.h"
using namespace std;
/*
Discounts:
   5% off if total > Rs 1000
   10% off if total > Rs 5000
Coupons:
   "SAVE50" = Rs 50 off
   "SAVE100" = Rs 100 off (only if total > Rs 2000)
Tax:
   Tax = 10% on total
*/

int main(void)
{
   BillingSystem bill;

   bill.addItem("Laptop", 3000);
   bill.addItem("Mouse", 50);
   bill.addItem("Headphones", 150);
   
   bill.applyCoupon("SAVE100");

   bill.generateFinalBill();  

   return 0;
}
