while(l+1 < r){
int mid = l + (r-l) / 2;
if(check[mid]) r = mid;
else l = mid;
}  
