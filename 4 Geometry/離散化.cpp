vector<int> discretize(vector<int> vals) {
    vector<int> tmp = vals;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int& v : vals)
        v = lower_bound(tmp.begin(), tmp.end(), v) - tmp.begin();
    return vals;
}