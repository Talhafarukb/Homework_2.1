#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }

    void display() {
        if (hours < 10) cout << "0";
        cout << hours << "h:";
        if (minutes < 10) cout << "0";
        cout << minutes << "m:";
        if (seconds < 10) cout << "0";
        cout << seconds << "s";
    }

    void read() {
        char c;
        cin >> hours >> c >> minutes >> c >> seconds;
    }

    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void fromSeconds(int totalSeconds) {
        hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }

    Time operator+(const Time& t) const {
        int totalSeconds = toSeconds() + t.toSeconds();
        return Time(totalSeconds);
    }

    Time operator-(const Time& t) const {
        int totalSeconds = toSeconds() - t.toSeconds();
        return Time(totalSeconds);
    }

    Time operator*(int scalar) const {
        int totalSeconds = toSeconds() * scalar;
        return Time(totalSeconds);
    }

    operator int() const {
        return toSeconds();
    }
};

int main() {
    Time t1(200);
    t1.display();

    Time t2;
    t2.read();

    Time t3 = t2 - t1;
    t3.display();

    int t3s = t3;
    cout << t3s;

    return 0;
}
