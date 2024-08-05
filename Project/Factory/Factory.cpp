#include "Factory.h"

// 具体产品类 ProductA
void  ProductA::setStrategy(ProcessingStrategy* strat) {
    strategy.reset(strat);
}

void ProductA::process() {
    {
        std::cout << "Processing ProductA with strategy: ";
        if (strategy) strategy->process();
    }
}

// 具体产品类 ProductB
void ProductB::setStrategy(ProcessingStrategy* strat) {
    strategy.reset(strat);
}

void ProductB::process() {
    std::cout << "Processing ProductB with strategy: ";
    if (strategy) strategy->process();
}

// 具体产品类 ProductC
void ProductC::setStrategy(ProcessingStrategy* strat) {
    strategy.reset(strat);
}

void ProductC::process() {
    std::cout << "Processing ProductC with strategy: ";
    if (strategy) strategy->process();
}

// 具体的加工策略类 - Heating
void HeatingStrategy::process() {
    std::cout << "Cooling\n";
}

// 具体的加工策略类 - Cooling
void CoolingStrategy::process() {
    std::cout << "Cooling\n";
}

// 具体的加工策略类 - Mixing
void MixingStrategy::process() {
    std::cout << "Mixing\n";
}

// 策略工厂
ProcessingStrategy* StrategyFactory::createStrategy(const std::string& type) {
    if (type == "Heating") {
        return new HeatingStrategy();
    }
    else if (type == "Cooling") {
        return new CoolingStrategy();
    }
    else if (type == "Mixing") {
        return new MixingStrategy();
    }
    return nullptr;
}

// 工厂类
std::unique_ptr<Product> Factory::createProduct(const std::string& type) {
    if (type == "ProductA") {
        return std::make_unique<ProductA>();
    }
    else if (type == "ProductB") {
        return std::make_unique<ProductB>();
    }
    else if (type == "ProductC") {
        return std::make_unique<ProductC>();
    }
    return nullptr;
}

// 单例工厂管理者
FactoryManager* FactoryManager::instance = nullptr;

FactoryManager& FactoryManager::getInstance(){
    if (!instance) {
        instance = new FactoryManager();
    }
    return *instance;
}

std::unique_ptr<Product> FactoryManager::createProduct(const std::string& type) {
    return factory.createProduct(type);
}

void FactoryManager::assignStrategy(Product* product, const std::string& strategyType) {
    if (auto* p = dynamic_cast<ProductA*>(product)) {
        p->setStrategy(strategyFactory.createStrategy(strategyType));
    }
    else if (auto* p = dynamic_cast<ProductB*>(product)) {
        p->setStrategy(strategyFactory.createStrategy(strategyType));
    }
    else if (auto* p = dynamic_cast<ProductC*>(product)) {
        p->setStrategy(strategyFactory.createStrategy(strategyType));
    }
}