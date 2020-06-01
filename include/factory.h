#pragma once

#include <iostream>

namespace designpattern
{
    namespace factory
    {
        // 学雷锋类
        class LeiFeng
        {
        public:
            void sweep()
            {
                std::cout << "扫地" << std::endl;
            }
            void wash()
            {
                std::cout << "洗衣服" << std::endl;
            }
            void buyRice()
            {
                std::cout << "买大米" << std::endl;
            }
            virtual ~LeiFeng() {
                std::cout << "LeiFeng" << std::endl;
            };
        };

        // 大学生志愿者
        class Undergraduate : public LeiFeng {};

        // 社区志愿者
        class Volunteer : public LeiFeng {};

        // 学雷锋工厂
        class LeiFengFactory
        {
        public:
            virtual LeiFeng* createLeiFeng() = 0;
            virtual ~LeiFengFactory()
            {
                std::cout << "LeiFengFactory" << std::endl;
            }
        };

        // 大学生志愿者工厂
        class UndergraduateFactory : public LeiFengFactory
        {
        public:
            LeiFeng* createLeiFeng()
            {
                return new Undergraduate;
            }
            ~UndergraduateFactory()
            {
                std::cout << "UndergraduateFactory" << std::endl;
            }
        };

        // 社区志愿者工厂
        class VolunteerFactory : public LeiFengFactory
        {
        public:
            LeiFeng* createLeiFeng()
            {
                return new Volunteer;
            }
            ~VolunteerFactory()
            {
                std::cout << "VolunteerFactory" << std::endl;
            }
        };
    } // namespace factory
} // namespace designpattern