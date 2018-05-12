
// int main() {
//     // int a = 0;
//     // int b = 0;

// }

void mystery(int*x, int y) {
    *x += y;
}
void foo() {
    
}
void main() {
    int x = 3;
    mystery(&x,5);
    printf("%i\n", x);
}