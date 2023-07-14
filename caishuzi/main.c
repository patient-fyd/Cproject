#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // 设置编码格式
    system("chcp 65001");
    // 1. 生成一个随机数
    // 1.1 以时间戳作为随机数种子
    srand((unsigned int) time(NULL));

    // 1.2 生成随机数
    int random = rand() % 100 + 1;
    // 2. 猜数字
    int guess = 0;
    while (1) {
        // 提示玩家输入
        printf("请输入你猜的数字: ");
        // 接收玩家输入
        scanf("%d", &guess);
        // 3. 进行判断
        // 3.1 判断是否相等
        if (guess == random) {
            printf("恭喜你猜对了!\n");
            // 选择是否重新开始游戏
            printf("是否重新开始游戏? 1.是 2.否\n");
            int choice = 0;
            scanf("%d", &choice);
            if (choice == 1) {
                // 重新开始游戏
                random = rand() % 100 + 1;
                continue;
            } else {
                printf("游戏结束!\n");
                return 0;
            }
        }
        // 3.2 判断大小
        if (guess > random) {
            printf("你猜的数字大了!\n");
        } else {
            printf("你猜的数字小了!\n");
        }
    }
}
