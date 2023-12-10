#include "Job.h"
#include <iostream>

void Job::printJobInfo() const {
    std::cout << "Job " << id << " - Duration: " << duration
        << ", Arrival: " << arrival << ", Start: " << start_time
        << ", Completion: " << completion_time << ", Wait: " << wait_time
        << ", Turnaround: " << turnaround_time << std::endl;
}
