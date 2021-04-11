// Pseudo code for finding single repeated element while other elments are twice repeated in an array in C.

// 1. Loop through the entire array.
// 2. Add elements into the set, it will only contain unique elements.
// 3. And also add the elements seen so far while ieterating throught the loop.
// 4. Now add the eleemnts in the set and multiple by 2.
// 5. And subtract the sum of all the elements seen so far.
// {a, b, c, d, a, b, c}
// set will contain a, b, c, d
// their sum a+b+c+d
// 2*(a+b+c+d)
// elements seen so far and their sum (a + b + c + d + a + b + c)
// 2*(a+b+c+d) - (a + b + c + d + a + b + c)
// answer will be d.


// implement set data structure in C
