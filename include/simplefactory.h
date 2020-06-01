#pragma once

#include <iostream>
namespace designpattern 
{
    namespace simplefactory
    {
        // 运算类
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

        // 加法类
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

        // 减法类
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

        // 乘法类
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

        // 除法类
        class OperationDiv : public Operation
        {
        public:
            double getResult() {
                if (getNumberB() == 0) {
                    std::cout << "除数不能为0" << std::endl;
                    return DBL_MIN;
                }
                else
                    return getNumberA() / getNumberB();
            }
            ~OperationDiv() {
                std::cout << "Div" << std::endl;
            };
        };

        // 运算工厂类
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
