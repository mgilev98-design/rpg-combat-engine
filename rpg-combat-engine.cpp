#include <iostream>
#include <clocale>

void DisplayStatus(int hp, int armor, int dr_hp) {
    std::cout << "Текущее здоровье: " << hp << "\n";
    std::cout << "Текущая броня: " << armor << "\n";
    std::cout << "Здоровье дракона: " << dr_hp << "\n \n";
}

void TakeDamage(int& hp, int& armor, int damage) {
    if (armor >= damage) {
        armor -= damage;
    } else {
        int remaining_damage = damage - armor;
        armor = 0;
        hp -= remaining_damage;
    }
}

void HealHero(int& hp, int heal_amount) {
    hp += heal_amount;
    if (hp >= 100) {
        hp = 100;
    }
}

int CalculateTotalHeal(int potions[], int size) {
    int all_heal = 0;
    for (int i = 0; i < size; ++i) {
        all_heal += potions[i];
    }
    return all_heal;
}

int CalculateDamageCombo(int damage, int  schet_hit) {
    if (schet_hit <= 0) {
        return 0;
    }
    return damage + CalculateDamageCombo(damage + 10, schet_hit - 1);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int hero_hp = 100;
    int hero_armor = 30;
    int dragon_hp = 300;
    int potions[3] = { 20, 35, 50 };
    int num_op = 0;

    while (hero_hp > 0 && dragon_hp > 0) {
        std::cout << "1 - Обычный удар, 2 - Комбо-удар Берсерка, 3 - Выпить зелье \n \n ";
        std::cout << "\n Введите номер операции: ";
        std::cin >> num_op;
        switch (num_op) {
        case 1: {
            std::cout << "\n Начальное положение: \n";
            DisplayStatus(hero_hp, hero_armor, dragon_hp);
            dragon_hp -= 30;
            TakeDamage(hero_hp, hero_armor, 40);
            DisplayStatus(hero_hp, hero_armor, dragon_hp);
            break;
        }
        case 2: {
            std::cout << "\n Начальное положение: \n";
            DisplayStatus(hero_hp, hero_armor, dragon_hp);
            int kol_hit = 0;
            std::cout << "\n Введите количество ударов: ";
            std::cin >> kol_hit;
            dragon_hp -= CalculateDamageCombo(40, kol_hit);
            TakeDamage(hero_hp, hero_armor, 40);
            DisplayStatus(hero_hp, hero_armor, dragon_hp);
            break;
        }
        case 3: {
            std::cout << "Начальное положение: \n";
            DisplayStatus(hero_hp, hero_armor, dragon_hp);
            int num_pot = 0;
            std::cout << "введите 0 для того, чтобы вылечить на 20, 1 - на 35, 2 - на 50 \n \n";
            std::cout << "выберите банку лечения: ";
            std::cin >> num_pot;
            if (num_pot < 3 && num_pot >= 0) {
                HealHero(hero_hp, potions[num_pot]);
                DisplayStatus(hero_hp, hero_armor, dragon_hp);
                TakeDamage(hero_hp, hero_armor, 40);
            } else {
                std::cout << "\n \n ОШИБКА! Введите число банки от 0 до 2";
            }
            break;
        }
        default:
            std::cout << "\n \n Введите корректное число!!! ОШИБКА!";
            break;
        }
    }
    if (hero_hp <= 0) {
        std::cout << "Вы погибли. ПОБЕДА ДРАКОНА! \n";
    }
    else {
        std::cout << "Дракон погиб. ПОБЕДА ВАША! \n";
    }
    return 0;
}
