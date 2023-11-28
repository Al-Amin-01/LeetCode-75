class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int n=str1.size(),m=str2.size();
        int i=min(n,m);
        while(i>0){
            if(m%i==0 && n%i==0){
                bool f=0;
                string x=str1.substr(0,i);
                int k=0;
                while(k<n){
                    if(str1.substr(k,i)!=x) {
                        f=1;
                        break;
                    }
                    k+=i;
                }
                k=0;
                while(k<m){
                    if(str2.substr(k,i)!=x){
                        f=1;
                        break;
                    }
                    k+=i;
                }
                if(f==0) return x;
            }
            i--;

        }

        return "";
        
        
    }
};