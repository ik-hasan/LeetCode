class Solution {
public:
    double getAngle(double a, double b, double c){
        double val = (a*a + b*b - c*c)/(2*a*b);
        val = max(-1.0,min(1.0,val));
        return acos(val)*180.0/M_PI;
    }
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        if(a+b <= c || b+c<=a || c+a<= b) return {};

        double angle1 = getAngle(a,b,c);
        double angle2 = getAngle(b,c,a);
        double angle3 = getAngle(c,a,b);

        vector<double> ans = {angle1,angle2,angle3};
        sort(ans.begin(),ans.end());
        return ans;
    }
};