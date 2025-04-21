#pragma once
#include <string>
#include <vector>
// Supports:
// 1. Adding items to cart
// 2. Applying coupons
// 3. Generating final bills.
class BillingSystem
{
public:
   void addItem(const std::string& itemName, double price);
   void applyCoupon(const std::string& code);
   void generateFinalBill();

private:
   std::vector<std::pair<std::string, double>> items;
   std::string couponCode;
   void PrintBill(double total, double discount, double coupon,
      double tax, double finalAmount);
   double calculateSubtotal();
   double calculateDiscount(double total);
   double applyCouponDiscount(double amountAfterDiscount);
   double calculateTax(double afterCoupon);
};


