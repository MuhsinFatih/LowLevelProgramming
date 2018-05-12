void swap(int *x, int *y) {
    int t0 = *x;
    int t1 = *y;
    *x = t1;
    *y = t0;
}
int zip1 = 3, zip2 = 2;
int main() {
    swap(&zip1, &zip2);
}