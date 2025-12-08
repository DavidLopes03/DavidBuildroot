// overflow.c
char buffer_overflow() {
    char tab[16];
    for (int i = 0; i < 26; i++)
        tab[i] = 42;
    return tab[0];
}

int main() {
    return buffer_overflow();
}