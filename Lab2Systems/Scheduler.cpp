#include "Scheduler.h"
#include <algorithm>
#include <iostream>
#include <limits>

void Scheduler::addJob(Job job) {
    jobs.push_back(job);
}

void Scheduler::scheduleJobs() {
    std::vector<Job> waitingQueue; 
    // Arrival time sorting
    std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.arrival < b.arrival;
        });

    int currentTime = 0; 

    while (!jobs.empty() || !waitingQueue.empty()) {
        auto it = jobs.begin();
        while (it != jobs.end()) {
            if (it->arrival <= currentTime) {
                waitingQueue.push_back(*it);
                it = jobs.erase(it);
            }
            else {
                ++it;
            }
        }

        if (!waitingQueue.empty()) {
            auto sjfJobIt = std::min_element(waitingQueue.begin(), waitingQueue.end(),
                [](const Job& a, const Job& b) { return a.duration < b.duration; });
            Job& sjfJob = *sjfJobIt;

            sjfJob.start_time = currentTime;
            sjfJob.completion_time = currentTime + sjfJob.duration;
            sjfJob.wait_time = sjfJob.start_time - sjfJob.arrival;
            sjfJob.turnaround_time = sjfJob.completion_time - sjfJob.arrival;
            currentTime = sjfJob.completion_time;

            sjfJob.printJobInfo();

            waitingQueue.erase(sjfJobIt);
        }
        else {
            currentTime++;
        }
    }
}

void Scheduler::printSchedule() {
    for (const auto& job : completed_jobs) {
        job.printJobInfo();
    }
}
