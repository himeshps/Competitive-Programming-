while(l+1 < r){
int mid = l + (r-l) / 2;
if(check[mid]) r = mid;
else l = mid;
}  

// whenever your answer will be l, remember that this implementation will fail to help you there, what you are supposed to do then is to use this piece of code to help 
// yourself out of this situation :

ll val1;
if( l + 1 == r) {
     if(check(l)) val1 = l; // whatever way the condition has been set by you
     else val1 = r;
} 
ll val2 = r;
cout << min(val1 , val2) << endl;  // printing the answer step. 
