int isQuardratic(int n, int p) {
    return powermod(((n%p) + p)%p, (p-1)/2, p) == 1;
}

/**
 * Computes x, s.t. x^2=n(mod p)
 * p is odd prime
 * n should satisfy n^((p-1)/2)=1(mod p)
 */
int ressol(int n, int p) {
    int i, j, S = 0, Q, z, c, R, t, M, tmp;
    n = ((n%p) + p)%p;
    if(p % 4 == 3) {
        return powermod(n, (p+1)/4, p);
    }
    Q = p-1;
    while(Q % 2 == 0) {
        S++;
        Q /= 2;
    }
    // There are (p-1)/2 nonresidue, so the following loop must terminate
    for(i = 2; i < p; i++) {
        if(!isQuardratic(i, p)) {
            z = i;
            break;
        }
    }
    c = powermod(z, Q, p);
    R = powermod(n, (Q+1) / 2, p);
    t = powermod(n, Q, p);
    while(t != 1) {
        tmp = t;
        i = 0;
        do {
            i++;
            tmp = (tmp * tmp) % p;
        } while(tmp != 1);
        for(j = 1; j <= S-i-1; j++) {
            c = (c * c) % p;
        }
        R = (R * c) % p;
        c = (c * c) % p;
        t = (t * c) % p;
        S = i;
    }
    return R;
}
