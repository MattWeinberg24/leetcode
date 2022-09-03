/**
 * @brief Is it possible to go from (a,b) to (c,d)?
 * Two operations can be performed in any order any number of times:
 * (a,b) -> (a+b,b)
 * or
 * (a,b) -> (a,b+a)
 * 
 * @param a integer a
 * @param b integer b
 * @param c integer c
 * @param d integer d
 * @return "Yes" if can, "No" if can't
 */
char* isPossible(int a, int b, int c, int d) {
    // base case if successful
    if (a == c && b == d) {
        return "Yes";
    }
    // base case if impossible from this point on
    if (a > c || b > d) {
        return "No";
    }
    
    // recursion case 1
    char * method1 = isPossible(a+b,b,c,d);
    
    // recursion case 2
    char * method2 = isPossible(a,b+a,c,d);
    
    if (*method1 == 'Y' || *method2 == 'Y') {
        return "Yes";
    }
        
    return "No";
}
