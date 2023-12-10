#include "Scheduler.h"

int main() {
    Scheduler scheduler;

    scheduler.addJob(Job('A', 8, 1));
    scheduler.addJob(Job('B', 4, 1));
    scheduler.addJob(Job('C', 4, 2));
    scheduler.addJob(Job('D', 4, 3));
    scheduler.addJob(Job('E', 2, 2));

    // Planning
    scheduler.scheduleJobs();

    scheduler.printSchedule();

    return 0;
}

