# Z Array / Algorithm
```cpp
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
```
Z algorithm is used in the case of strings for the purpose of pattern matching. I have learnt it using Tushar Roy's tutorials.<br>
The element at the i-th index in a z array represents the number of prefix indexes that match starting from that specific index. <br>
This is the basic crude definition for the algo/array. <br>
Using this is helpful when dealing with problems involving suffix / prefix segments of a string.
