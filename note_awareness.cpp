#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <ctime>
using namespace std;

void print_main_banner() {
    system("cls");
    cout<<"*** NOTE AWARENESS TESTER (chords edition) ***\n\n";
}

int main() {

    vector<string> notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    vector<string> chord_types = {"major", "minor", "augmented", "diminished"};
    vector<string> inversions = {"root", "1st", "2nd"};
    int major_third_interval = 4;
    int minor_third_interval = 3;
    
    char to_continue = 'Y';
    char to_use_inversions = 'Y';
    bool use_inversions = true;
    vector<int> scores;

    print_main_banner();
    cout<<"(NOTE: Please go through the readme for instructions on how to play.)\n\n";
    cout<<"Include chord inversions? (Y/N): ";
    cin>>to_use_inversions;
    use_inversions = (to_use_inversions == 'Y' || to_use_inversions == 'y');
    srand((unsigned) time(NULL)); //generate truly random number by using current timestamp as seed value

    while(to_continue == 'Y' || to_continue == 'y') {
        print_main_banner();

        int note = rand() % notes.size();
        int chord_type = rand() % chord_types.size();

        int interval_1, interval_2;
        

        switch(chord_type) {
            case 0:
                interval_1 = major_third_interval;
                interval_2 = interval_1 + minor_third_interval;
                break;
            case 1:
                interval_1 = minor_third_interval;
                interval_2 = interval_1 + major_third_interval;
                break;
            case 2:
                interval_1 = major_third_interval;
                interval_2 = interval_1 + major_third_interval;
                break;
            case 3:
                interval_1 = minor_third_interval;
                interval_2 = interval_1 + minor_third_interval;
                break;
            default:
                interval_1 = major_third_interval;
                interval_2 = interval_1 + minor_third_interval;
                break;
        }

        vector<string> answer_notes = {"", ""};
        deque<string> correct_answers = {notes[(note + interval_1) % 12], notes[(note + interval_2) % 12]};

        cout<<"Chord: "<<notes[note]<<" "<<chord_types[chord_type];

        if(use_inversions) {
            answer_notes.push_back("");
            correct_answers.push_front(notes[note]);

            int inversion = rand() % inversions.size();
            for(int j=0; j<inversion; j++) {
                string rotated_note = correct_answers.front();
                correct_answers.pop_front();
                correct_answers.push_back(rotated_note);
            }

            cout<<" ("<<inversions[inversion]<<" inversion)";
        }
        cout<<"\n";
        cout<<"Intervals: "<<interval_1<<", "<<interval_2<<"\n\n";
        
        auto start = std::chrono::system_clock::now();
        for(int j=0; j < answer_notes.size(); j++) {
            cout<<"Note "<<(j + 1)<<": ";
            cin>>answer_notes[j];
        }
        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end-start;

        int marks = 1;

        for(int i=0; i < answer_notes.size(); i++) {
            if(answer_notes[i] != correct_answers[i]) {
                cout<<"Note "<<i + 1<<" was wrong!\n";
                marks = 0;
            }
        }

        if(marks == 1)
            cout<<"Correct!\n";
        cout<<"Time taken: "<<elapsed_seconds.count()<<"s\n";
        
        scores.push_back(marks);
        cout<<"Continue? (Y/N)";
        cin>>to_continue;
    }

    int total_score = 0;
    for(int i=0; i<scores.size(); i++) {
        total_score += scores[i];
    }

    cout<<"You got a score of "<<total_score<<" in "<<scores.size()<<" attempt(s)";
    double accuracy = (((double) total_score) / scores.size()) * 100;
    cout<<"\nAccuracy: "<<accuracy<<"%\n";
    cout<<"*** THANK YOU FOR USING THE NOTE AWARENESS TESTER ***\n\n";
    return 0;
}