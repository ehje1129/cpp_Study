#include <iostream>

using namespace std;

const int ARRSIZE = 10;

int get_scores(double scores[]);
double get_avg(double scores[], int n);
void print_scores(double scores[], int n, double avg);

int main()
{
    double scores[ARRSIZE] {0};
    int input_cnt;
    double avg;
    cout << "Enter golf scores up to 10 (enter non-numeric to quit): ";
    input_cnt = get_scores(scores);
    avg = get_avg(scores, input_cnt);
    print_scores(scores, input_cnt, avg);

    return 0;
}

int get_scores(double socres[]){
    int cnt=0;
    double score;
    while (cnt < ARRSIZE && cin >> score) {
        socres[cnt++] = score;
    }
    return cnt;
}

double get_avg(double scores[], int n){
    int num=n;
    double sum=0;
    while(num-- > 0){
        sum+=scores[num];
    }
    return sum/n;
}

void print_scores(double scores[], int n, double avg){
    cout << "golf scores:";
    for (int i=0; i<n; i++){
        cout << " " << scores[i];
    }
    cout << endl << "Average socore: " << avg;
}