#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Books {
    char Title[100];
    char Authors[100];
    char Press[100];
    int Page;
    int Price;
    int available;
};

typedef struct Books Books;

Books bookList[] = {
    { "Truth", "John", "Century", 300, 20000, 1 },
    { "Love", "Paul", "Goods", 200, 15000, 1 },
    { "Joy", "James", "Cookie", 250, 18000, 1 },
    { "Thanks", "Mark", "Saesong", 240, 21000, 1 },
    { "God", "Johnson", "Jungio", 450, 35000, 1 }
};

void displayBookList() {
    printf("%-15s%-15s%-15s%-8s%-8s\n", "Title", "Authors", "Press", "Page", "Price");
    printf("------         --------       ------         -----   ------ \n");

    int size = sizeof(bookList) / sizeof(bookList[0]);
    for (int i = 0; i < size; i++) {
        printf("%-15s%-15s%-15s%-8d%-8d%\n", bookList[i].Title, bookList[i].Authors, bookList[i].Press, bookList[i].Page, bookList[i].Price);
    }
}

void searchBook(char name[]) {
    for (int i = 0; name[i]; i++) {
        name[i] = tolower(name[i]);
    }

    int size = sizeof(bookList) / sizeof(bookList[0]);
    for (int i = 0; i < size; i++) {
        if (strcmp(name, _strlwr(bookList[i].Title)) == 0) {
            printf("%-15s%-15s%-15s%-8d%-8d%-10s\n", bookList[i].Title, bookList[i].Authors, bookList[i].Press, bookList[i].Page, bookList[i].Price, bookList[i].available ? "대출 가능" : "대출 중");
            return;
        }
    }

    printf("보유하고 있지 않은 책 제목입니다.\n");
}

void borrowBook(char name[]) {
    for (int i = 0; name[i]; i++) {
        name[i] = tolower(name[i]);
    }

    int size = sizeof(bookList) / sizeof(bookList[0]);
    for (int i = 0; i < size; i++) {
        if (strcmp(name, _strlwr(bookList[i].Title)) == 0) {
            if (bookList[i].available) {
                printf("대출 되었습니다.\n");
                bookList[i].available = 0;
            }
            else {
                printf("대출 중이라 대출 할 수 없습니다.\n");
            }
            return;
        }
    }

    printf("보유하고 있지 않은 책 제목입니다.\n");
}

void returnBook(char name[]) {
    for (int i = 0; name[i]; i++) {
        name[i] = tolower(name[i]);
    }

    int size = sizeof(bookList) / sizeof(bookList[0]);
    for (int i = 0; i < size; i++) {
        if (strcmp(name, _strlwr(bookList[i].Title)) == 0) {
            if (!bookList[i].available) {
                printf("책이 반납 되었습니다.\n");
                bookList[i].available = 1;
            }
            else {
                printf("대출 되지 않은 책입니다.\n");
            }
            return;
        }
    }

    printf("보유하고 있지 않은 책 제목입니다.\n");
}

int main() {
    int ch = 0;
    char name[100];

    while (ch != 5) {
        printf("[도서목록:1] [검색:2][대출:3][반납:4][종료:5] >>");
        scanf_s("%d", &ch);

        switch (ch) {
        case 1:
            displayBookList();
            break;
        case 2:
            printf("검색할 도서를 선택하세요\n");
            scanf_s("%99s", name, sizeof(name));
            searchBook(name);
            break;
        case 3:
            printf("대출할 도서를 선택하세요\n");
            scanf_s("%99s", name, sizeof(name));
            borrowBook(name);
            break;
        case 4:
            printf("반납할 도서를 선택하세요\n");
            scanf_s("%99s", name, sizeof(name));
            returnBook(name);
            break;
        }
    }

    return 0;
}
