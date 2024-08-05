#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

// ����Ĳ�Ʒ��
class Product {
public:
    virtual ~Product() {}
    virtual void process() = 0;
};

// �ӹ����Խӿ�
class ProcessingStrategy {
public:
    virtual ~ProcessingStrategy() {}
    virtual void process() = 0;
};

// �����Ʒ�� ProductA
class ProductA : public Product {
    std::unique_ptr<ProcessingStrategy> strategy;
public:
    void setStrategy(ProcessingStrategy* strat);
    void process() override;
};

// �����Ʒ�� ProductB
class ProductB : public Product {
    std::unique_ptr<ProcessingStrategy> strategy;
public:
    void setStrategy(ProcessingStrategy* strat);
    void process() override;
};

// �����Ʒ�� ProductC
class ProductC : public Product {
    std::unique_ptr<ProcessingStrategy> strategy;
public:
    void setStrategy(ProcessingStrategy* strat);
    void process() override;
};

// ����ļӹ������� - Heating
class HeatingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

// ����ļӹ������� - Cooling
class CoolingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

// ����ļӹ������� - Mixing
class MixingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

// ���Թ���
class StrategyFactory {
public:
    ProcessingStrategy* createStrategy(const std::string& type);
};

// ������
class Factory {
public:
    std::unique_ptr<Product> createProduct(const std::string& type);
};

// ��������������
class FactoryManager {
    static FactoryManager* instance;
    Factory factory;
    StrategyFactory strategyFactory;

    FactoryManager() {}

public:
    static FactoryManager& getInstance();
    std::unique_ptr<Product> createProduct(const std::string& type);
    void assignStrategy(Product* product, const std::string& strategyType);
};

#endif

