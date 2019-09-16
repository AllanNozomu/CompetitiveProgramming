class Solution {
public:
    int sumChar(char a, char b, int carry){
        int aux = 0;
        if (a == '1'){
            if (b == '1')
                aux = 2;
            else
                aux = 1;
        } else {
            if (b == '1')
                aux = 1;
            else
                aux = 0;
        }
        aux += carry ? 1 : 0;
        return aux;
    }
    
    string addBinary(string a, string b) {
        int ia = a.size() - 1, ib = b.size() - 1;
        string res = "";
        int carry = 0;
        
        while(ia >= 0 && ib >=0){
            char ca = a[ia], cb = b[ib];
            
            int aux = sumChar(ca, cb, carry);
            carry = aux > 1 ? 1 : 0;
            res = (aux % 2 ? "1" : "0") + res;
            ia--;
            ib--;
        }
        while(ia >= 0){
            char ca = a[ia];
            
            int aux = sumChar(ca, '0', carry);
            carry = aux > 1 ? 1 : 0;
            res = (aux % 2 ? "1" : "0") + res;
            ia--;
        }
        while(ib >=0){
            char cb = b[ib];
            
            int aux = sumChar(cb, '0', carry);
            carry = aux > 1 ? 1 : 0;
            res = (aux % 2 ? "1" : "0") + res;
            ib--;
        }
        if (carry){
            res = "1" + res;
        }
        
        return res;
    }
};