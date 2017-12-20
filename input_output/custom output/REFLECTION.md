# 

#### *integer output manipulators*
- oct: use base-8 (octal) notation
- dec: use base-10 (decimal) notation
- hex: use base-16 (hexadecimal) notation
- showbase: prefix 0 for octal and 0x for hexadecimal
- noshowbase: don't use prefixes

#### *Floating-point formats*
- fixed: use-fixed point notation
- scientific: use mantissa and exponent notation; the mantissa is always in the (1:10) range; that is, there is a single nonzero digit before the decimal point
- defaultfloat: choose fixed or scientific to give the numerically most accurate representation, within the precision of defaultfloat

#### File stream open modes
- ios_base::app (append. add to the end of the file)
- ios_base::ate ("at end". open and seek to the end)
- ios_base::binary (binary mode - beware of system-specific behavior)
-