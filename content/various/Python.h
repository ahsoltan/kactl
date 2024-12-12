/**
 * Author:
 * License: CC0
 * Source: Own work
 * Description: Two ways to deal with fractions in python.
 */

from fractions import Fraction
from decimal import Decimal, getcontext

# Set precision for Decimal operations
getcontext().prec = 50  # 50 decimal places

# Fractions example
f1 = Fraction(3, 4) + Fraction(2, 3)  # Sum of fractions
f2 = Fraction(50, 100).limit_denominator()  # Reduce fraction
print("Fractions:", f1, f2)

# Decimal example
d1 = Decimal(0.5) + Decimal('0.2') + Decimal(10)  # Sum of decimals
d2 = Decimal(1) / Decimal(7)  # Division with high precision
print("Decimals:", d1, d2)

