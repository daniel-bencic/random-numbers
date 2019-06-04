#include <cmath>
#include <random>
#include "../include/sampling.h"

#include <iostream>

double PDF(double x) {
        return 1 / x;
}

double InverseCDF(double x) {
        return std::pow(M_E, x + std::log(2));
}

std::map<double, int> RejectionSampling(int size) {
        std::map<double, int> nums;
        std::default_random_engine gen{ };
        std::uniform_real_distribution<> dis_x{ 2, 2 * M_E };
        std::uniform_real_distribution<> dis_u{ 0, 0.5 };
        
        for (int i = 0; i < size; i++) {
                double x = 2;
                double u = 1;
                
                do {
                        x = std::round(dis_x(gen) * 1000) / 1000;
                        u = dis_u(gen);
                } while (u > PDF(x));

                if (nums.find(x) == std::end(nums))
                        nums[x] = 1;
                else
                        nums[x]++;
        }

        return nums;
}

std::map<double, int> InversionSampling(int size) {
        std::map<double, int> nums;
        std::default_random_engine gen{ };
        std::uniform_real_distribution<> dis_p{ 0, 1 };

        double u = 0;
        double x = 0;
        for (int i = 0; i < size; i++) {
                u = dis_p(gen);
                x = std::round(InverseCDF(u) * 1000) / 1000;
                
                if (nums.find(x) == std::end(nums))
                        nums[x] = 1;
                else
                        nums[x]++;
        }

        return nums;
}
