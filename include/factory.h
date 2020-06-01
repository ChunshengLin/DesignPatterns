#pragma once

#include <iostream>

namespace designpattern
{
    namespace factory
    {
        // ѧ�׷���
        class LeiFeng
        {
        public:
            void sweep()
            {
                std::cout << "ɨ��" << std::endl;
            }
            void wash()
            {
                std::cout << "ϴ�·�" << std::endl;
            }
            void buyRice()
            {
                std::cout << "�����" << std::endl;
            }
            virtual ~LeiFeng() {
                std::cout << "LeiFeng" << std::endl;
            };
        };

        // ��ѧ��־Ը��
        class Undergraduate : public LeiFeng {};

        // ����־Ը��
        class Volunteer : public LeiFeng {};

        // ѧ�׷湤��
        class LeiFengFactory
        {
        public:
            virtual LeiFeng* createLeiFeng() = 0;
            virtual ~LeiFengFactory()
            {
                std::cout << "LeiFengFactory" << std::endl;
            }
        };

        // ��ѧ��־Ը�߹���
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

        // ����־Ը�߹���
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