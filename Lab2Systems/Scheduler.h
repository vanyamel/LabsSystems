#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Job.h"

class Scheduler {
private:
    std::vector<Job> jobs; 
    std::vector<Job> completed_jobs; 
    int currentTime;

public:
    Scheduler() : currentTime(0) {}

    void addJob(Job job);
    void scheduleJobs();
    void printSchedule();

    const std::vector<Job>& getCompletedJobs() const {
        return completed_jobs;
    }
};

#endif 
