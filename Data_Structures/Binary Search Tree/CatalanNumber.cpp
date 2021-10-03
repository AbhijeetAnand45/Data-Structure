

/*
   Catalan numbers are a sequence of natural numbers that occurs in 
   many interesting counting problems like following :-
   1. Count the number of expressions containing n pairs of parentheses which are 
   correctly matched. 
   For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
   2. Count the number of possible Binary Search Trees with n keys (See this)

   3. Count the number of full binary trees (A rooted binary tree is full,
    if every vertex has either two children or no children) with n+1 leaves.
   4. Given a number n, return the number of ways you can draw n chords in a 
    circle with 2 x n points such that no 2 chords intersect.

    The first few Catalan numbers
     for n = 0, 1, 2, 3,.. are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ...
*/

/* By Abhijeet Anand */

#include<bits/stdc++.h>

using namespace std;

// Recursive Approach 

unsigned long int catalan(int n){
    if(n<=1){
        return 1;
    }
    unsigned long int ans = 0;
    for(int i=0;i<n;i++){
        ans += catalan(i) * catalan(n-i-1);
    }

    return ans;

}


// dynamic programming : Efficient Approach // overlapping subproblem O(n^2)

unsigned long int catalanNo(unsigned int n){

    unsigned long int catalanNo[n+1];

    catalanNo[0] = catalanNo[1] = 1;

    // c2 = c0*c1 + c1*c0;
    // c3 = c0*c2 + c1*c1 + c2 * c0;
    // ["((()))","(()())","(())()","()(())","()()()"]
    for(int i=2;i<=n;i++){
        catalanNo[i] = 0;
        for(int j=0;j<i;j++){
            catalanNo[i] += catalanNo[j] * catalanNo[i-j-1];
        }
    }
    return catalanNo[n];

}

// There is another approach to find nth catalan no. in O(n) time by
// Calculating the Binomial Coefficient. i.e. (2*nCn) / (n+1)

unsigned long int BinomialCoefficient(unsigned long int n, unsigned int k){
    unsigned long int ans = 1;

    if(k > n-k){
        k = n-k;
    }

    // nCk = (n*(n-1)*(n-2)*....*(n-k+1))/(k*(k-1)*(k-2)*...*1)

    for(int i=0;i<k;i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}


unsigned long int catalanNos(unsigned int n){
    unsigned long int c = BinomialCoefficient(2*n,n);

    // where c = 2*nCn
    return c/(n+1);
}



int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<catalan(i)<<" ";
        // cout<<catalanNo(i)<<" ";
    }
}