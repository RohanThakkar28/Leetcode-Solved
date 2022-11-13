class Solution {
public:
    vector<double> convertTemperature(double c) {
        double k=273.15+c;
        double f=(1.8)*c+32.00;
        vector<double>d;
        d.push_back(k);
        d.push_back(f);
        return d;
        
        
    }
};