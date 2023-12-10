#include "Scheduler.h"
#include "gtest/gtest.h"

TEST(SJFSchedulerTest, ScheduleJobs) {
    Scheduler scheduler;
    scheduler.addJob(Job('A', 8, 0));
    scheduler.addJob(Job('B', 4, 1));
    scheduler.addJob(Job('C', 4, 2));
    scheduler.addJob(Job('D', 4, 3));

    scheduler.scheduleJobs();

    const auto& completed_jobs = scheduler.getCompletedJobs();

    EXPECT_EQ(completed_jobs.size(), 4);


    EXPECT_EQ(completed_jobs[0].id, 'A');
    EXPECT_EQ(completed_jobs[1].id, 'B');
    EXPECT_EQ(completed_jobs[2].id, 'C');
    EXPECT_EQ(completed_jobs[3].id, 'D');


    EXPECT_EQ(completed_jobs[0].completion_time, 8);
    EXPECT_EQ(completed_jobs[1].completion_time, 12);
    EXPECT_EQ(completed_jobs[2].completion_time, 16);
    EXPECT_EQ(completed_jobs[3].completion_time, 20);
}

TEST(SchedulerTest, CorrectlyCalculatesWaitTimes) {
    Scheduler scheduler;
    scheduler.addJob(Job('A', 8, 0));
    scheduler.addJob(Job('B', 4, 1));
    scheduler.addJob(Job('C', 4, 2));
    scheduler.addJob(Job('D', 4, 3));

    scheduler.scheduleJobs();

    const auto& completed_jobs = scheduler.getCompletedJobs();

    
    EXPECT_EQ(completed_jobs[0].wait_time, 0); 
    EXPECT_EQ(completed_jobs[1].wait_time, 7); 
    EXPECT_EQ(completed_jobs[2].wait_time, 10); 
    EXPECT_EQ(completed_jobs[3].wait_time, 13); 
}


TEST(SchedulerTest, CorrectlyCalculatesTurnaroundTimes) {
    Scheduler scheduler;

    scheduler.scheduleJobs();

    const auto& completed_jobs = scheduler.getCompletedJobs();

    
    EXPECT_EQ(completed_jobs[0].turnaround_time, 8); 
    EXPECT_EQ(completed_jobs[1].turnaround_time, 11); 
    EXPECT_EQ(completed_jobs[2].turnaround_time, 14);
    EXPECT_EQ(completed_jobs[3].turnaround_time, 17);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
