#include "Factory.h"

// �����Ʒ�� ProductA
void  ProductA::setStrategy(ProcessingStrategy* strat) {
    strategy.reset(strat);
}

void ProductA::process() {
    {
        std::cout << "Processing ProductA with strategy: ";
        if (strategy) strategy->process();
    }
}

// �����Ʒ�� ProductB
void ProductB::setStrategy(ProcessingStrategy* strat) {
    strategy.reset(strat);
}

void ProductB::process() {
    std::cout << "Processing ProductB with strategy: ";
    if (strategy) strategy->process();
}

// �����Ʒ�� ProductC
void ProductC::setStrategy(ProcessingStrategy* strat) {
    strategy.reset(strat);
}

void ProductC::process() {
    std::cout << "Processing ProductC with strategy: ";
    if (strategy) strategy->process();
}

// ����ļӹ������� - Heating
void HeatingStrategy::process() {
    std::cout << "Cooling\n";
}

// ����ļӹ������� - Cooling
void CoolingStrategy::process() {
    std::cout << "Cooling\n";
}

// ����ļӹ������� - Mixing
void MixingStrategy::process() {
    std::cout << "Mixing\n";
}

// ���Թ���
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

// ������
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

// ��������������
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