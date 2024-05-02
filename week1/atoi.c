#include <stdio.h>

int atoi(const char s[]) {
    int i = 0;
    int num = 0;
    int sign = 1;

    // skip leading white space
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
        i++;
    }

    // handling sign
    if (s[i] == '+' || s[i] == '-'){
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9'){
        num = num * 10 + (s[i] - '0');
        i++;
    }

    return sign * num;


}
int main(void) {
printf("%d\n", atoi(""));
printf("%d\n", atoi("0"));
printf("%d\n", atoi("0123"));
printf("%d\n", atoi("1234"));
printf("%d\n", atoi("-1234"));
return 0;
}
