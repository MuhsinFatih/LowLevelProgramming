

int main (){
    // int a = 5;
    // int b = &a;

    // int x, y, z;
    // while(1) {
    //     x = 1;
    //     y = 1;
    //     z = 1;
    //     do {
    //         printf("%d\n", z);
    // 
    //         z = x + y;
    //         x = y;
    //         y = z;
    //     } while(z<255);
    // }

a1:;
    int size = 15;
    int arr[size];
    int x = 0, y = 0;
    x = 3;
    y = 5;
    for(int i = 0;i < 5;i++) {
        printf("&arr[%i]: %25p\n",i, &arr[i]);
    }
    printf("...\n&arr[last]: %22p\n", &arr[size]);
    printf("&x: %30p\n",&x);
    while(1) {
        arr[x] = x;
        printf("%i\n", x);
        // arr[y] = 1;
        x += 1;
    }
    arr[y] = x;

    return 0;
    // while(1);
}
