class Solution {
public:
    string predictPartyVictory(string s) {

        //71 test case hi pass krwa paya
        // int x=0,y=0;
        // string s1="Radiant";
        // string s2="Dire";
        // int n=senate.size();
        // for(int i=0;i<n;i++){
        //     if(senate[i]=='D'){
        //         x++;
        //     }
        //     else if(senate[i]=='R'){
        //         y++;
        //     }
        // }
        // if()
        // if(x>y){
        //     return s2;
        // }
        // else if(x<y){
        //     return s1;
        // }
        // else{
        //     if(senate[0]=='R'){
        //         return s1;
        //     }
        //     else{
        //         return s2;
        //     }
        // }


        queue<int> q;
        queue<int> qr;
        queue<int> qd;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                qr.push(i);
            }
            else if(s[i]=='D'){
                qd.push(i);
            }
            q.push(i);
        }
        while(q.size()>1){
            if(s[q.front()]=='X'){
                q.pop();
            }
            else if(s[q.front()]=='R'){
                if(qd.size()==0){
                    return "Radiant";
                }
                else{
                    s[qd.front()]='X';
                    qd.pop();
                    qr.push(qr.front());
                    qr.pop();
                    q.push(q.front());
                    q.pop();
                }
            }
            else if(s[q.front()]=='D'){
                if(qr.size()==0){
                    return "Dire";
                }
                else{
                    s[qr.front()]='X';
                    qr.pop();
                    qd.push(qd.front());
                    qd.pop();
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        if(s[q.front()]=='R') return "Radiant";
        else return "Dire";
    }
};