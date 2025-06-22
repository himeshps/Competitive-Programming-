class DSU{
private : 
    vector<int> p; 
    vector<int> sizes; 
    vector<int> r; 
    /* vector<int> sum , min ; */
public :
    DSU(int size) : p(size) , sizes(size , 1) , r(size , 0) {
        for ( int i = 0 ; i < size ; ++i ){ 
            p[i] = i ;
        }
    }
    int get(int a){
        return p[a] = ( p[a] == a ? a : get( p[a] ) ); 
    }
    bool unite(int a , int b){
        if( get(a) == get(b) ){
            return false ; 
        }
        a = get(a) ; 
        b = get(b) ; 
        if(r[a] == r[b]){
            r[a]++ ;
        }
        if(r[a] > r[b]){
            p[b] = a ;
            /* sum[a] += sum[b]
            min[a] = min(min[a], min[b]) */
        }
        else{ 
            p[a] = b ;
            /* sum[b] += sum[a]
            min[b] = min(min[a], min[b]) */
        }
        return true ;
    }
}; 
