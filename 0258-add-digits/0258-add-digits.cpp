class Solution {
public:
    int addDigits(int num) {
        // while(len(num) > 1)
//         while(num > 9)
//         {
//             int sum = 0;
//             int temp = num;
//             while(temp)
//             {
//                 sum += temp%10;
//                 temp /= 10;
//             }
//             num = sum;
//         }
        
//         return num;
        
        // O(1) Approach
        /* Logic is
        "Every number can be represented as 
        (Sum of its digits) + (Multiple of 9) " */
        /* Also simple idea why digital root equals to mod 9 if we've got an ABCD number
        ABCD = 1000A+100B+10*C+D = (A + B + C + D) + 9 * (111 * A + 11 * B + C)
        this equals (mod 9) to A + B + C + D.
        */
        
        if(num == 0) return 0;
        else if(num%9 == 0) return 9;
        else return (num%9);
    }
    
//     int len(int n)
//     {
//         return to_string(n).length();
//     }
};