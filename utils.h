namespace geometric {

//Function used for taking the dot product of an edge direction vector in Q and a hyperplane
inline mpq_class dot_product(const vector<mpq_class> &v1, const vector<mpz_class> &v2) {
    assert(v1.size() == v2.size());
    size_t dim = v1.size();
    mpq_class dot_prod;
    for(int j = 0; j < dim; ++j) {
        dot_prod += v1[j] * v2[j];
    }
    return dot_prod;
}

inline vector<mpq_class> get_direction(const vector<mpq_class> &v1, const vector<mpq_class> &v2) {
    size_t dim = v1.size();
    vector<mpq_class> e_dir(dim);
    for(int j = 0; j < dim; ++j) {
        e_dir[j] = (v2[j] - v1[j]);
    }
    return e_dir;
}

inline vector<mpz_class> get_direction(const vector<mpz_class> &v1, const vector<mpz_class> &v2) {
    size_t dim = v1.size();
    vector<mpz_class> e_dir(dim);
    for(int j = 0; j < dim; ++j) {
        e_dir[j] = (v2[j] - v1[j]);
    }
    return e_dir;
}

inline Integer gcd(Integer a, Integer b) {
    if(!a || !b) {
        return a + b;
    }
    if(a > b) {
        return gcd(a % b, b);
    }
    return gcd(b % a, a);
}

//Transform to integer vector by multiplying by a common denominator. Returns the vector and the common denominator
inline pair<vector<Integer>, Integer> get_int_vector(const vector<Rational> &v) {
    vector<Integer> v_int;
    Integer g = 1;
    for(const auto &x : v) {
        g *= x.get_den();
    }
    for(const auto &x : v) {
        v_int.push_back(x.get_num() * g / x.get_den());
    }
    return make_pair(v_int, g);
}

//checks if the 3 points are colinear.
inline bool is_collinear(const vector<Integer> &a, const vector<Integer> &b, const vector<Integer> &c) {
    vector<Integer> v1 = get_direction(a, b);
    vector<Integer> v2 = get_direction(a, c);
    int t = 0;
    while(t < v1.size() && v1[t] == 0) t++;
    if(t == v1.size()) {
        //a = b, so they are colinear
        return true;
    }

    Integer lambda = v2[t] / v1[t];
    v_scalar_multiplication(v1, lambda);
    return (v1 == v2);
}

// gets a vector as input and outputs a vector with the same direction but integer entries that are irreducible.
inline vector<Integer> get_min_vec(const vector<Integer> &a){
    assert(a.size() > 0);
    Integer g = a[0];
    vector<Integer> b = a;
    for(int i = 1, s = a.size(); i < s; ++i) {
        g = gcd(g, a[i]);
    }
    g = abs(g);
    for(int i = 0, s = a.size(); i < s; ++i) {
        b[i] /= g;
    }
    return b;
}

}