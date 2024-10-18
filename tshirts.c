#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    
    assert(size(20) == 'S'); //Lower limit is not included which could be a error 
    assert(size(37) == 'S');
    assert(size(38) == 'S'); //Size 38 is not addressed
    assert(size(38) == 'M'); //Size 38 is not addressed
    assert(size(40) == 'M');
    assert(size(42) == 'M');
    assert(size(42) == 'L'); //Size 42 is not addressed
    assert(size(43) == 'L'); //Size 42 is not addressed
    assert(size(60) == 'S'); //Higher limit is not included which could be a error 
    printf("All is well (maybe!)\n");
    return 0;
}
