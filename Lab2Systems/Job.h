#ifndef JOB_H
#define JOB_H

class Job {
public:
    char id;
    int duration;
    int arrival;
    int start_time;
    int completion_time;
    int wait_time;
    int turnaround_time;

    Job(char id, int duration, int arrival)
        : id(id), duration(duration), arrival(arrival), start_time(0),
        completion_time(0), wait_time(0), turnaround_time(0) {}

    void printJobInfo() const;
    bool operator==(const Job& other) const {
        return id == other.id;
    }
};

#endif 
