// Fig. 5.8: DollarAmount.h
// DollarAmount class stores dollar amounts as a whole numbers of pennies
#include <string>
#include <cmath>
#include <iostream>

class DollarAmount {
public:
   // initialize amount from an int64_t value
   DollarAmount(int64_t value)
   : dollars{value},
     cents{0}
    { }

   // add right's amount to this object's amount
   void add(DollarAmount right) {
      // can access private data of other objects of the same class
      dollars += right.dollars;
      cents += right.cents;

      if(cents >= 100){
         dollars++;
         cents -= 100;
      } 
   }

   // subtract right's amount from this object's amount
   void subtract(DollarAmount right) {
      // can access private data of other objects of the same class
      dollars -= right.dollars;
      cents -= right.cents;

      if(cents < 0){
         dollars--;
         cents = 100 - abs(cents);
      } 
   }


   // set values for variables: dollars and cents
   void set(int balance){
      dollars = balance;
   }

   // uses integer arithmetic to calculate interest amount, 
   // then calls add with the interest amount
   void addInterest(int rate, int divisor) {
      // create DollarAmount representing the interest
      DollarAmount interest{
         ((dollars * 100 + cents) * rate + divisor / 2) / divisor
      };

      add(interest); // add interest to this object's amount
   }

   // return a string representation of a DollarAmount object
   std::string toString() const {
      std::string dumdollars{std::to_string(dollars)};
      std::string dumcents{std::to_string(std::abs(cents))};
      return dumdollars + "." + (dumcents.size() == 1 ? "0" : "") + dumcents;
   }
private:
   int64_t dollars{0};
   int64_t cents{0};
};


/**************************************************************************
* (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
* Pearson Education, Inc. All Rights Reserved.                           *
*                                                                        *
* DISCLAIMER: The authors and publisher of this book have used their     *
* best efforts in preparing the book. These efforts include the          *
* development, research, and testing of the theories and programs        *
* to determine their effectiveness. The authors and publisher make       *
* no warranty of any kind, expressed or implied, with regard to these    *
* programs or to the documentation contained in these books. The authors *
* and publisher shall not be liable in any event for incidental or       *
* consequential damages in connection with, or arising out of, the       *
* furnishing, performance, or use of these programs.                     *
*************************************************************************/
