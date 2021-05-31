//CONVERSIONS
//	c	->	symbol(char)
//	s	->	c-string
//	p	->	pointer [%#lx] or [%#x]
//	d	->	signed integer
//	i	->	signed integer
//	u	->	unsigned integer
//	x	->	unsigned hex (lowercase)
//	X	->	unsigned hex (UPPERCASE)
//--BONUS--
//	n	->	this specifies a variable pointer to integer which stores amount of symbols printed
//	f	->	decimal with floating point. Default precision is 6
//	g	->	uses e if exponent is less than -4, greater than or equal to precision, otherwise uses f. 
//	--	--	Removes trailing zeroes, decimal point is present only if there are significant digits after it
//	e	->	scientifitc notation for a double. Default precision is 6

//FLAGS
//	-	->	changes alignment to left (default is right) excludes [0, n]
//	0	->	puts zeroes instead of spaces
//	.	->	precision (supports * to get precision from next args). For [x,X,d,i,u] - shows max amnt of digits. For [f, e] - amount of digits after point. 
//	*	->	pulls next args to set precision or width
//--BONUS
//	#	->	tainted flag: 
//	--	--	x puts 0x in front of a hex value,
//	--	--	f, g, e always puts a decimal point
//	--	--	g does not remove trailing zeroes
//		->	always puts space in fron of a positive number or an empty string
//	+	->	always puts sign in front of a number
//	l	->	long/unsigned long int
//	ll	->	long long/unsinged long long int
//	h	->	short/unsigned short int
//	hh	->	signed/unsigned char 

//[WIDTH][FLAGS][PRECISION][CONVERSION]
//<signsym><lpadding><content><rpadding>