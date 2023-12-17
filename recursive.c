#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[100];
int i, e = 1;

void Eprime();
void E();
void T();
void Tprime();
void F();

int main() {
    printf("Enter:");
    scanf("%s", input);
    i = 0;  // Initialize i to 0 before parsing each input
    E();
    if (e == 1 && input[i] == '\0') {
        printf("accept");
    } else {
        printf("reject");
    }
    return 0;
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (input[i] == '+' || input[i] == '-') {
        i++;
        T();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (input[i] == '*' || input[i] == '/') {
        i++;
        F();
        Tprime();
    }
}

void F() {
    if (isalnum(input[i])) {
        i++;
    } else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            e = 0;
        }
    } else {
        e = 0;
    }
}
