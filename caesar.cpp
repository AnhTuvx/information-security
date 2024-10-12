#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ma_hoa(char *van_ban, int khoa) {
    for (int i = 0; van_ban[i] != '\0'; ++i) {
        if (isalpha(van_ban[i])) {
            if (isupper(van_ban[i])) {
                van_ban[i] = (van_ban[i] + khoa - 'A') % 26 + 'A';
            } else {
                van_ban[i] = (van_ban[i] + khoa - 'a') % 26 + 'a';
            }
        }
    }
}

void giai_ma(char *van_ban, int khoa) {
    ma_hoa(van_ban, 26 - khoa); 
}

void pha_ma(char *van_ban) {
    for (int khoa = 0; khoa < 26; khoa++) {
        char van_ban_giai_ma[100];
        strcpy(van_ban_giai_ma, van_ban);
        giai_ma(van_ban_giai_ma, khoa);
        printf(" Khoa %d, van ban giai ma la: %s\n", khoa, van_ban_giai_ma);
    }
}

int main() {
    char van_ban[100];
    int khoa, lua_chon;

    printf("Nhap van ban : ");
    fgets(van_ban, 100, stdin);

    printf("Chon :\n");
    printf("1. Ma hoa\n");
    printf("2. Giai ma\n");
    printf("3. Pha khoa\n");
    printf("Nhap su lua chon (1,2,3)\n");
    scanf("%d", &lua_chon);

    switch (lua_chon) {
        case 1:
            printf("Nhap khoa dich chuyen van ban: ");
            scanf("%d", &khoa);
            ma_hoa(van_ban, khoa);
            printf("Van ban ma hoa : %s voi khoa %d \n", van_ban,khoa);
            break;
        case 2:
            printf("Nhap khoa dich chuyen van ban: ");
            scanf("%d", &khoa);;
            giai_ma(van_ban, khoa);
            printf("Van ban giai ma: %s voi khoa %d \n", van_ban,khoa);
            break;
        case 3:
            pha_ma(van_ban);
            break;
        default:
            printf("Fail\n");
    }

    return 0;
}
