#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

enum status {
    Dead = 0,
    Active = 1
};

void change(int p[][20], int n[][20], int x, int y) {
    int judge = -1 * p[x][y];
    for (int i = std::max(x - 1, 0); i <= std::min(x + 1, 19); i++) {
        for (int k = std::max(y - 1, 0); k <= std::min(y + 1, 19); k++) {
            if (p[i][k] == Active)
                judge++;
        }
    }
    if (p[x][y] == Active) {
        if (judge < 2 || judge > 3)
            n[x][y] = Dead;
        else
            n[x][y] = p[x][y];
    } else if (judge == 3)
        n[x][y] = Active;
}

void print(int pInt[][20]) {
    for (int i = 0; i < 20; i++) {
        for (int k = 0; k < 20; k++) {
            if (pInt[i][k] == Active)
                std::cout << "# ";
            else
                std::cout << "- ";
        }
        std::cout << std::endl;
    }
}

void random(int pInt[][20]) {
    int nums;
    std::cin >> nums;
    while (nums) {
        if (pInt[rand() % 20][rand() % 20] == Dead) {
            pInt[rand() % 20][rand() % 20] = Active;
            --nums;
        }
    }
}

int main() {

    srand((unsigned) time(nullptr));

    int pInt[20][20] = {Dead};
    int newInt[20][20] = {Dead};

    random(pInt);

    int gen = 1;
    std::cout << "----------------" << std::endl;
    std::cout << "   " << gen++ << "   " << std::endl;
    print(pInt);

    while(true)
    {
        Sleep(1000 / 30);
        system("cls");
        if(gen % 2 == 0) {
            memset(newInt, 0, sizeof(newInt));
            for (int i = 0; i < 20; i++) {
                for (int k = 0; k < 20; k++) {
                    change(pInt, newInt, i, k);
                }
            }

            std::cout << "----------------" << std::endl;
            std::cout << "   " << gen++ << "   " << std::endl;
            print(newInt);
        }
        else
        {
            memset(pInt, 0, sizeof(pInt));
            for (int i = 0; i < 20; i++) {
                for (int k = 0; k < 20; k++) {
                    change(newInt, pInt, i, k);
                }
            }

            std::cout << "----------------" << std::endl;
            std::cout << "   " << gen++ << "   " << std::endl;
            print(pInt);
        }
    }

}
