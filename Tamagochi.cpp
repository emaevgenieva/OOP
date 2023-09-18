#include <iostream>
using namespace std;
// Създайте структура Tamagotchi. Нека първоначално тамагочито си има само име (най-много 20 символа). 
// Създайте едно тамагочи в main функцията. Въведете името му от клавиатурата и го отпечатайте на екрана.

//2
//Добавете метод (функция) void printStatus() в структурата Tamagotchi, който да печата на екрана името на тамагочито.

//3
// Напишете външна за структурата функция, void readTamagotchi(<тип> тamagotchi), 
// която да инициализира тамагочито с въвеждане на данните му от клавиатурата.


//4
// Добавете член данна енергия (число между 0 и 100) към тамагочито. 
// Съответно ще трябва да промените/подобрите метода printStatus и функцията readTamagotchi.

//5
// Добавете два метода:

//     void speak(char *speech), който ще отпечатва на екрана низа speech, 
//         но преди печатането да проверява дали конкретното тамагочи има достатъчно енергия да говори (считаме, че говоренето струва 2 енергия)

//     void sleep(int hours), който зарежда енергията на тамагочито с hours * 8 енергия.
//      Направете проверка дали новополучената енергия надхвърля максимума 100 и ако да, то тогава я намалете до 100.

//6
// Добавете член данна attackPower на тамагочито. 
//Създайте метод void fightWith(Tamagotchi other), който ще печата победителя от конкретната битка като победител е тамагочито с повече attackPower, 
// а ако са с равен attackPower да се печата на екрана "It is a draw!".

//7
// Напишете външна за структурата функция void singSong(char *songs[], Tamagotchi tamagotchies[], int size) ,
//  която на tamagotchies[i] казва да каже фраза songs[i], 
//  където i е между 0 и size (size е броят на тамагочитата, съответно и на елементите на масива от низове songs).

struct Vehicle
{
    char name[20];
    int speed;

    void printStatus(){
        std::cout << "The name of the vehicle is: " << name << endl;
        std::cout << "The speed of the vehicle is: " << speed << endl;
    }
};

struct Tamagochi{
    char name[20];
    int energy;
    int attackPower;
    Vehicle vehicle;

    void printStatus(){
        cout << "The name of the tamagochi is: \n" << name;
        cout << "The energy status of the tamagochi is: \n" << energy;
        cout << "The attack power of the tamagochi is: \n"<< attackPower;
        cout << "The Tamagotchi has the following vehicle: " << endl;
        vehicle.printStatus();
    }

    void speak(char* speech){
        if(energy >= 2){
            cout << "Thamagochi " << name << " says " << speech << endl;
            energy -= 2;
        }
    }

    void sleep(int hours){
        energy += hours*8;
        if(energy > 100){
            energy = 100;
        }
    }

    void fightWith(Tamagochi other){
        if(attackPower > other.attackPower){
            cout << "The winner is: " << name << endl;  
        }
        if(attackPower == other.attackPower){
            cout << "It's a draw! \n";
        }
        if(attackPower < other.attackPower){
            cout << "The winner is: " << name << endl;
        }
    }

    int compare(Tamagochi other){
        if(attackPower < other.attackPower){
            return 0;
        }
        if(attackPower == other.attackPower){
            return 0;
        }
        if(attackPower > other.attackPower){
            return 1;
        }
    }
};


void singSong(char *songs[], Tamagochi tamagochies[], int size){
    for(size_t i=0; i<size; i++){
        tamagochies[i].speak(songs[i]);
    }
}

void readTamagochi(Tamagochi &tamagochi){
    cout << "Input the name of the tamagochi: "<<endl;
    cin.getline(tamagochi.name,20);

    cout <<"Input the energy status of the tamagochi : "<<endl;
    cin >> tamagochi.energy;

    cout << "Input the attackpower of the tamagochi: "<<endl;
    cin >> tamagochi.attackPower;

    cin.ignore();
    cout << "Please input the name of the vehicle of the Tamagotchi: "<<endl;
    std::cin.getline(tamagochi.vehicle.name, 20);
    std::cout << "Please input the speed of the vehicle of the Tamagotchi: "<<endl;
    std::cin >> tamagochi.vehicle.speed;

    std::cin.ignore();

}
/*Напишете външна за структурата функция Tamagotchi 
findTheStrongest(Tamagotchi tamagotchies[], int size) , 
която връща най-силното тамагочи (т.е. това с най-много attackPower). 
*/
Tamagochi findTheStrongest(Tamagochi tamagochies[], int size){
    int candidate = 0;
    for(size_t i=0; i<size; i++){
        if (tamagochies[i].compare(tamagochies[candidate]) > 0)
            candidate = i;
    }
    return tamagochies[candidate];
}

void race(Tamagochi tamagochies[], int size){
    for (int i = 0; i < size; i++)
    {
        int fastest = i;
        for (int j = i; j < size; j++)
        {
            if (tamagochies[j].compare(tamagochies[fastest]) > 0)
                fastest = j;
        }
        std::swap(tamagochies[i], tamagochies[fastest]);
    }
}

int main(){
    Tamagochi t1;
    readTamagochi(t1);

    Tamagochi t2;
    readTamagochi(t2);

    // Tamagochi t3;
    // readTamagochi(t3);

    // Tamagochi t4;
    // readTamagochi(t4);

    Tamagochi tamagochies[] = {t1, t2};

    char song[] = "hello";
    char song1[] = "world";
    char song2[] = "how are";
    char song3[] = "you";
    char *songs[] = {song, song1, song2, song3};

    
    singSong(songs, tamagochies, 2);

    Tamagochi strongest = findTheStrongest(tamagochies, 2);
    strongest.printStatus();

    race(tamagochies, 2);
    tamagochies[0].printStatus();

    return 0;
    
}
