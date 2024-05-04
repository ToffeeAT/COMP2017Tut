#include <stdio.h>
#include <stdio.h>

struct customer {
    char name[128];
    int age;
    char item[128];
};

#define CUST_LEN (300) // set size of customer max 
#define BUF_LEN (300)

int main() {
    struct customer customers[CUST_LEN];
    char buf[BUF_LEN];
    int i;
    for (i = 0; i < CUST_LEN; i++) {
        printf("Welcome to ShopMocha\n Could you please tell me your name, age and what you are looking for?\n");
        fgets(buf, BUF_LEN, stdin);
        sscanf(buf, "%s %d %s", customers[i].name, &customers[i].age, customers[i].item);
        printf("Hrmm, I think you should talk to a ShopaMocha assistant to find \"%s\"\n", 
        customers[i].item);
        printf("Have a good day!\n");
    }

    for(int j = 0; j < i; j++) {
        printf("Customer %d, Name: %s, Age: %d, Looking for: %s\n", 
            j, 
            customers[j].name,
            customers[j].age,
            customers[j].item);
    }

    return 0;
}
