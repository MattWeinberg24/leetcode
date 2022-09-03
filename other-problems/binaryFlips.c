
/**
 * @brief Start with a binary-like string of all "0".
 * You can "flip" a character. In that case, itself and all
 * characters to the right of it are changed from "0" to "1"
 * or from "1" to "0". How many flips are needed to generate
 * the target?
 * 
 * @param target binary-like string of "1" and "0"
 * @return int number of flips needed
 */
int binarySwitches(char* target) {
    int result = 0; // keep track of how many "switches" between 1 and 0
    char last = '0'; //keep track of last character (first switch must go to all 1's)
    while (*target != '\0') { //iterate through string
        char c = *target;
        if (c != last) { //if there is a switch...
            result++; //one extra flip is needed
        }
        last = c; //overwrite last for next iteration
        target++;
    }
    return result;
}