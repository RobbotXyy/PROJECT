#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

// 抽象的产品类
class Product {
public:
    virtual ~Product() {}
    virtual void process() = 0;
};

// 加工策略接口
class ProcessingStrategy {
public:
    virtual ~ProcessingStrategy() {}
    virtual void process() = 0;
};

// 具体产品类 ProductA
class ProductA : public Product {
    std::unique_ptr<ProcessingStrategy> strategy;
public:
    void setStrategy(ProcessingStrategy* strat);
    void process() override;
};

// 具体产品类 ProductB
class ProductB : public Product {
    std::unique_ptr<ProcessingStrategy> strategy;
public:
    void setStrategy(ProcessingStrategy* strat);
    void process() override;
};

// 具体产品类 ProductC
class ProductC : public Product {
    std::unique_ptr<ProcessingStrategy> strategy;
public:
    void setStrategy(ProcessingStrategy* strat);
    void process() override;
};

// 具体的加工策略类 - Heating
class HeatingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

// 具体的加工策略类 - Cooling
class CoolingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

// 具体的加工策略类 - Mixing
class MixingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

// 策略工厂
class StrategyFactory {
public:
    ProcessingStrategy* createStrategy(const std::string& type);
};

// 工厂类
class Factory {
public:
    std::unique_ptr<Product> createProduct(const std::string& type);
};

// 单例工厂管理者
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

