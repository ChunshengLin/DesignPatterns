#pragma once

#include <iostream>
namespace designpattern 
{
    namespace simplefactory
    {
        // ������
        class Operation
        {
        public:
            virtual double getResult() {
                double result = 0;
                return result;
            }
            double getNumberA() {
                return _numberA;
            }
            double getNumberB() {
                return _numberB;
            }
            void setNumberA(double numberA) {
                _numberA = numberA;
            }
            void setNumberB(double numberB) {
                _numberB = numberB;
            }
            virtual ~Operation() {
                std::cout << "Operation" << std::endl;
            }
        private:
            double _numberA = 0;
            double _numberB = 0;
        };

        // �ӷ���
        class OperationAdd : public Operation
        {
        public:
            double getResult() {
                return getNumberA() + getNumberB();
            }
            ~OperationAdd() {
                std::cout << "Add" << std::endl;
            };
        };

        // ������
        class OperationSub : public Operation
        {
        public:
            double getResult() {
                return getNumberA() - getNumberB();
            }
            ~OperationSub() {
                std::cout << "Sub" << std::endl;
            };
        };

        // �˷���
        class OperationMul : public Operation
        {
        public:
            double getResult() {
                return getNumberA() * getNumberB();
            }
            ~OperationMul() {
                std::cout << "Mul" << std::endl;
            };
        };

        // ������
        class OperationDiv : public Operation
        {
        public:
            double getResult() {
                if (getNumberB() == 0) {
                    std::cout << "��������Ϊ0" << std::endl;
                    return DBL_MIN;
                }
                else
                    return getNumberA() / getNumberB();
            }
            ~OperationDiv() {
                std::cout << "Div" << std::endl;
            };
        };

        // ���㹤����
        class OperationFactory
        {
        public:
            Operation* createOperate(const char operation) {
                Operation *oper = nullptr;
                switch (operation)
                {
                case '+':
                    oper = new OperationAdd;
                    break;
                case '-':
                    oper = new OperationSub;
                    break;
                case '*':
                    oper = new OperationMul;
                    break;
                case '/':
                    oper = new OperationDiv;
                    break;
                }
                return oper;
            }
            ~OperationFactory() {
                std::cout << "xigou" << std::endl;
            }
        };

    } // namespace simplefactory
} // namespace designpattern
