class Solution {
public:

    bool isPrime(int n){
        if(n<=1) return false;
        if(n==2) return true;
        if(n%2==0) return false;
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        vector<int> primes;
        int temp = n;
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int reverse = stoi(s);
        int ans = 0;
        if(reverse<temp){
            swap(reverse,temp);
        }
        for(int i=temp;i<=reverse;i++){
            if(isPrime(i)) ans+=i;
        }
        return ans;
    }
};