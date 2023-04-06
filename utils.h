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

inline mpz_class get_common_denom(const vector<mpq_class> &v) {
    mpz_class x = 1;
    for(auto a : v) {
        x *= a.get_den();
    }
    return x;
}

}