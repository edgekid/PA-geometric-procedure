namespace geometric {

//Function used for taking the dot product of an edge direction vector and a hyperplane
Rational dot_product(vector<Rational> v1, vector<Integer> v2) {
    assert(v1.size() == v2.size());
    size_t dim = v1.size();
    Rational dot_prod;
    for(int j = 0; j < dim; ++j) {
        dot_prod += v1[j] * v2[j];
    }
    return dot_prod;
}

vector<Rational> get_direction(vector<Rational> v1, vector<Rational> v2) {
    size_t dim = v1.size();
    vector<Rational> e_dir(dim);
    for(int j = 0; j < dim; ++j) {
        e_dir[j] = (v2[j] - v1[j]);
    }
    return e_dir;
}

}