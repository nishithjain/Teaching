#include "BillingSystem.h"
#include <iostream>

void BillingSystem::addItem(const std::string& itemName, double price)
{
   items.push_back({ itemName, price });
}

void BillingSystem::applyCoupon(const std::string& code)
{
   couponCode = code;
}

void BillingSystem::generateFinalBill()
{
   double total = calculateSubtotal();
   double discount = calculateDiscount(total);
   double afterDiscount = total - discount;

   double coupon = applyCouponDiscount(afterDiscount);
   double afterCoupon = afterDiscount - coupon;

   double tax = calculateTax(afterCoupon);
   double finalAmount = afterCoupon + tax;

   PrintBill(total, discount, coupon, tax, finalAmount);
}

void BillingSystem::PrintBill(double total, double discount, 
   double coupon, double tax, double finalAmount)
{
   std::cout << "Subtotal: Rs" << total << "\n";
   std::cout << "Discount: -Rs" << discount << "\n";
   std::cout << "Coupon (" << couponCode << "): -Rs" << coupon << "\n";
   std::cout << "Tax (10%): +Rs" << tax << "\n";
   std::cout << "----------------------------------\n";
   std::cout << "Final Bill Amount: Rs" << finalAmount << "\n";
}

double BillingSystem::calculateSubtotal()
{
   double total = 0;
   for (auto& item : items) {
      total += item.second;
   }
   return total;
}

double BillingSystem::calculateDiscount(double total)
{
   if (total > 5000) 
   { 
      return total * 0.10; 
   }
   else if (total > 1000) 
   {
      return total * 0.05;
   }
   return 0;
}

double BillingSystem::calculateTax(double afterCoupon)
{
   return afterCoupon * 0.10; // 10% tax
}

double BillingSystem::applyCouponDiscount(double amountAfterDiscount)
{
   if (couponCode == "SAVE50") return 50;
   if (couponCode == "SAVE100" && amountAfterDiscount > 2000) return 100;
   return 0;
}
