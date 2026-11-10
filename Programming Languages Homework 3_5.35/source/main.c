#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// a) 非遞迴費氏數列函式 (參數型態為 unsigned int，回傳型態為 unsigned long long int)
unsigned long long int fibonacci(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long int prev1 = 0; // 代表 F(0)
    unsigned long long int prev2 = 1; // 代表 F(1)
    unsigned long long int current = 0;

    for (unsigned int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return current;
}

int main() {
    unsigned int n;

    // 讓使用者自行輸入要計算第幾項
    printf("請輸入要計算第幾個費氏數 (n >= 0): ");
    scanf("%u", &n); // unsigned int 的格式指定字為 %u

    // unsigned long long int 的格式指定字為 %llu
    printf("第 %u 個費氏數 F(%u) = %llu\n\n", n, n, fibonacci(n));

    // b) 額外印出系統能表示的最大費氏數 (題目第二小題要求)
    unsigned int max_n = 1;
    unsigned long long int prev = 0, curr = 1;

    while (1) {
        unsigned long long int next = prev + curr;
        // 當無號整數發生溢位 (overflow) 時，相加結果會繞回變小 (next < curr)
        if (next < curr) {
            break;
        }
        prev = curr;
        curr = next;
        max_n++;
    }

    printf("--- 系統最大費氏數測試 (5.35 b) ---\n");
    printf("此系統能印出的最大費氏數為第 %u 項：F(%u) = %llu\n", max_n, max_n, curr);

    return 0;
}