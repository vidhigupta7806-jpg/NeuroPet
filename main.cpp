#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Pet {
private:
    string name;
    string emotion;
    int hunger, happiness, energy;

public:
    Pet(string n) {
        name = n;
        hunger = 50;
        happiness = 50;
        energy = 50;
        emotion = "calm";
    }

    // ---------------- EMOTION SYSTEM ----------------
    void updateEmotion() {
        if(hunger > 80) emotion = "irritated";
        else if(energy < 25) emotion = "tired";
        else if(happiness > 80) emotion = "excited";
        else if(happiness < 30) emotion = "low";
        else emotion = "balanced";
    }

    void showStatus() {
        cout << "\n--- Oreo Status ---\n";
        cout << "Hunger: " << hunger << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Energy: " << energy << endl;
        cout << "Emotional State: " << emotion << endl;
    }

    // ---------------- FOOD SYSTEM ----------------
    void feedMenu() {
        if(hunger < 20) {
            cout << "Oreo: I feel completely full right now. I think I should stop eating for a while.\n";
            return;
        }

        int choice;
        cout << "\nWhat would you like to feed Oreo?\n";
        cout << "1. Milk\n2. Biscuit\n3. Chicken\n4. Apple\n5. Pizza\n";
        cin >> choice;

        cout << "\nOreo responds:\n";

        switch(choice) {
            case 1:
                cout << "Warm milk feels calming and helps me regain energy.\n";
                energy += 10; happiness += 5;
                break;

            case 2:
                cout << "A biscuit is simple, but it brings a small sense of comfort.\n";
                happiness += 10;
                break;

            case 3:
                cout << "Chicken provides energy. This feels like a thoughtful choice.\n";
                energy += 20; hunger -= 20; happiness += 5;
                break;

            case 4:
                cout << "Apple is refreshing and healthy. It makes me feel balanced.\n";
                happiness += 5;
                break;

            case 5:
                cout << "Pizza is enjoyable, but I should not rely on it too often.\n";
                happiness += 15; energy -= 5;
                break;

            default:
                cout << "I am not comfortable with this choice.\n";
                return;
        }

        hunger -= 10;
        updateEmotion();

        cout << "Current emotional state: " << emotion << endl;
    }

    // ---------------- GAME SYSTEM ----------------
    void guessGame() {
        int number = rand()%10 + 1;
        int guess, attempts = 3;

        cout << "\nI am thinking of a number between 1 and 10.\n";
        cout << "You have 3 attempts to identify it.\n";

        while(attempts--) {
            cout << "Enter your guess: ";
            cin >> guess;

            if(guess == number) {
                cout << "That is correct. Your reasoning worked well.\n";
                happiness += 15;
                return;
            }
            else if(guess < number)
                cout << "Try considering a higher value.\n";
            else
                cout << "Try considering a lower value.\n";

            cout << "Remaining attempts: " << attempts << endl;
        }

        cout << "The correct number was " << number << ".\n";
        happiness -= 5;
    }

    void playMenu() {
        if(energy < 20) {
            cout << "I do not have enough energy to play right now.\n";
            return;
        }

        int option;
        cout << "\nGame Menu\n1. Guessing Game\n2. Quiet Interaction\n";
        cin >> option;

        if(option == 1) guessGame();
        else cout << "Not every moment needs activity. Sitting calmly also has value.\n";

        updateEmotion();
    }

    // ---------------- CONVERSATION SYSTEM ----------------
    void talk(string mood) {
        int option;
        cout << "\nConversation Menu\n";
        cout << "1. Reflect on my day\n";
        cout << "2. Receive guidance\n";
        cout << "3. I feel low\n";
        cout << "4. What do you feel?\n";
        cout << "5. Exit\n";
        cin >> option;

        switch(option) {

            case 1:
                cout << "\nReflection:\n";

                if(mood == "stressful")
                    cout << "Your day required effort and resilience. Even if it felt overwhelming, you stayed present and continued forward.\n";
                else if(mood == "lonely")
                    cout << "Loneliness can feel quiet but heavy. However, your presence still carries meaning.\n";
                else if(mood == "amazing")
                    cout << "Moments of positivity should be acknowledged. They provide energy for future challenges.\n";
                else
                    cout << "Even an ordinary day contributes to growth. Consistency matters more than intensity.\n";
                break;

            case 2:
                cout << "\nGuidance:\n";
                cout << "Focus on what is within your control.\n";
                cout << "Break complex problems into smaller steps.\n";
                cout << "Progress is built gradually, not instantly.\n";
                break;

            case 3:
                cout << "\nSupport:\n";
                cout << "It is acceptable to feel low.\n";
                cout << "You do not need to resolve everything immediately.\n";
                cout << "Allow yourself time to recover and reflect.\n";
                break;

            case 4:
                cout << "\nCurrent State:\n";
                cout << "I currently feel " << emotion << ".\n";
                cout << "Interaction helps maintain balance.\n";
                break;
        }
    }

    // ---------------- AUTONOMOUS BEHAVIOR ----------------
    void expressNeeds() {
        if(hunger > 70)
            cout << "\nI require nourishment. Consider feeding me.\n";
        else if(energy < 30)
            cout << "\nEnergy levels are low. Rest would be beneficial.\n";
        else if(happiness < 30)
            cout << "\nEmotional levels are low. Interaction may help.\n";
    }

    void applyDecay() {
        hunger += 5;
        energy -= 4;
        happiness -= 2;
    }
};

// ---------------- MAIN SYSTEM ----------------
int main() {
    srand(time(0));

    Pet oreo("Oreo");

    string mood;
    int input;

    cout << "\nHow was your day?\n";
    cout << "1. Good\n2. Stressful\n3. Amazing\n4. Tiring\n5. Lonely\n6. Productive\n";
    cin >> input;

    cout << "\nSystem Response:\n";

    switch(input) {
        case 2:
            mood = "stressful";
            cout << "Your day involved pressure and responsibility. Managing that requires strength.\n";
            break;
        case 3:
            mood = "amazing";
            cout << "Positive experiences like this contribute to long-term motivation.\n";
            break;
        case 4:
            mood = "tiring";
            cout << "Fatigue indicates effort. Recovery is equally important.\n";
            break;
        case 5:
            mood = "lonely";
            cout << "Periods of isolation can occur, but they do not define your value.\n";
            break;
        case 6:
            mood = "productive";
            cout << "Effective use of time reflects discipline and focus.\n";
            break;
        default:
            mood = "good";
            cout << "A stable day provides consistency, which is valuable.\n";
    }

    int choice;

    do {
        cout << "\nMain Menu\n";
        cout << "1. Feed\n2. Play\n3. Status\n4. Talk\n5. Exit\n";
        cin >> choice;

        switch(choice) {
            case 1: oreo.feedMenu(); break;
            case 2: oreo.playMenu(); break;
            case 3: oreo.showStatus(); break;
            case 4: oreo.talk(mood); break;
        }

        oreo.applyDecay();
        oreo.updateEmotion();
        oreo.expressNeeds();

    } while(choice != 5);

    int rating;
    cout << "\nRate your experience (1-10): ";
    cin >> rating;

    if(rating >= 9)
        cout << "Feedback acknowledged. High satisfaction detected.\n";
    else if(rating >= 7)
        cout << "Moderate satisfaction. Further refinement possible.\n";
    else
        cout << "Low satisfaction detected. Improvements required.\n";
}
