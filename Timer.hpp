//
// Created by fergus on 01/08/17.
//

#pragma once

#include <chrono>

class Timer
{
private:

    std::chrono::time_point<std::chrono::system_clock> mLastPolledTime;

public:

    Timer() : mLastPolledTime(std::chrono::system_clock::now())
    {}

    void PollTime()
    {
        mLastPolledTime = std::chrono::system_clock::now();
    }

    double GetElapsedTime()
    {
        auto now = std::chrono::system_clock::now();
        auto time_spent = std::chrono::duration_cast<std::chrono::duration<double>>(now - mLastPolledTime);

        return time_spent.count();
    }
};