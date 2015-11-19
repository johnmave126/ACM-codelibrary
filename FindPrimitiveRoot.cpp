/**
 * Find a primitive root mod p
 * p is an odd prime
 * Need to know the prime factorization of (p-1), assumed in array 
 * bp, with p-1 only has n prime factors, bp[0] to bp[n-1]
 */
int findRoot(int p, int *bp, int n) {
    int i, j, f;
    for(i = 2; i < p; i++) {
        f = 1;
        for(j = 0; j < n && f; j++) {
            if(powermod(i, (p-1)/bp[j], p) == 1) {
                f = 0;
            }
        }
        if(f == 1) {
            return i;
        }
    }
    return 0;
}
