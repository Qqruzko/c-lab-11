
#include <iostream>
using namespace std;
class Time
{
public:
    Time() : hours{ 0 }, mins{ 0 }, sec{ 0 }
    {
        cout << "Class has been created" << endl;
    }
    Time(int h, int m, int s)
    {
        cout << "Class has been created" << endl;
        if (s > 59)
        {
            int buf = s / 60;
            m += buf;
            s = s % 60;
        }
        if (m > 59)
        {
            int buf = m / 60;
            h += buf;
            m = m % 60;
        }
        cout << "sec " << s << endl;
        cout << "min " << m << endl;
        cout << "hours  " << h << endl;
        Setsec(s);
        Setmins(m);
        Sethours(h);
    }
    Time(float hours)
    {
        cout << "Float type Class has been created" << endl;
        float flhrs = hours + mins / 60 + sec / 3600;      // Casting everything into hours with mins and secs
    }
    void Sethours(int h)
    {
        hours = h;
    }
    void Setmins(int m)
    {
        mins = m;
    }
    void Setsec(int s)
    {
        sec = s;
    }
    int Gethours()
    {
        return hours;
    }
    int Getmin()
    {
        return mins;
    }
    int Getsec()
    {
        return sec;
    }
    void Printtime()
    {
        cout << hours << " : " << mins << " : " << sec << '\n';
    }
    Time Addtime(Time b)
    {
        Time t;
        int temp_sec{ 0 }, temp_min{ 0 }, temp_hour{ 0 };
        temp_sec = sec + b.Getsec();
        if (temp_sec > 59)
        {
            int buf = temp_sec / 60;
            temp_min += buf;
            temp_sec = temp_sec % 60;
        }
        temp_min += mins + b.Getmin();
        if (temp_min > 59)
        {
            int buf = temp_min / 60;
            temp_hour += buf;
            temp_min = temp_min % 60;
        }
        temp_hour += hours + b.Gethours();
        t.Setsec(temp_sec);
        t.Setmins(temp_min);
        t.Sethours(temp_hour);
        return t;
    }
    Time operator+ (const Time&) const;
    Time operator- (const Time&) const;
    Time operator+(double) const;
    bool operator< (Time) const;
    friend std::ostream& operator<< (std::ostream& out, const Time& t);


    operator float() const
    {
        //Transfoming into hours float type
        float fsec = sec / 3600;
        float fmin = mins / 60;
        float fhours = static_cast<float>(hours) + fsec + fmin;
        return fhours;
    }
private:
    int hours;
    int mins;
    int sec;
};
Time Time::operator+ (const Time& t2) const
{
    int temp_sec{ 0 }, temp_min{ 0 }, temp_hour{ 0 };
    temp_sec = sec + t2.sec;
    if (temp_sec > 59)
    {
        int buf = temp_sec / 60;
        temp_min += buf;
        temp_sec = temp_sec % 60;
    }
    temp_min += mins + t2.mins;
    if (temp_min > 59)
    {
        int buf = temp_min / 60;
        temp_hour += buf;
        temp_min = temp_min % 60;
    }
    temp_hour += hours + t2.hours;
    return Time(temp_sec, temp_min, temp_hour);
}

Time Time::operator- (const Time& t2) const
{
    int temp_sec{ 0 }, temp_min{ 0 }, temp_hour{ 0 };
    temp_hour = hours - t2.hours;
    if (temp_hour < 0)
    {
        return Time(0, 0, 0);
    }
    temp_min = mins - t2.mins;
    if (temp_min < 0)
    {
        temp_hour--;
        temp_min = mins + 60 - t2.mins;
        if (temp_hour < 0)
        {
            return Time(0, 0, 0);
        }
    }
    temp_sec = sec - t2.sec;
    if (temp_sec < 0)
    {
        temp_min--;
        temp_sec = sec + 60 - t2.sec;
        if (temp_min < 0)
        {
            return Time(0, 0, 0);
        }
    }
    return Time(temp_sec, temp_min, temp_hour);
}
Time Time::operator+(double mult) const
{
    Time result;
    result.hours = hours + static_cast<int>(mult);
    result.mins = mins + ((int)(mult - (int)mult) / 60);
    result.sec = sec + ((mult - (int)mult) / 3600);
    return result;
}

bool Time::operator< (Time t1) const
{
    if ((hours * 3600 + mins * 60 + sec) < (t1.hours * 3600 + t1.mins * 60 + t1.sec))
        return true;
    else return false;
}

std::ostream& operator<< (std::ostream& out, const Time& t)
{
    out << t.hours << " : " << t.mins << " : " << t.sec << endl;
    return out;
}

int main()
{
    Time t1, t2;
    Time t3 = 2.35F;
    cout << t1;

}



