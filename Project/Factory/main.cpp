#include "Factory.h"

int main() {
    FactoryManager& manager = FactoryManager::getInstance();

    // ������ƷA��ָ�����Ȳ���
    std::unique_ptr<Product> productA = manager.createProduct("ProductA");
    if (productA) {
        manager.assignStrategy(productA.get(), "Heating");
        productA->process();
    }

    // ������ƷB��ָ����ȴ����
    std::unique_ptr<Product> productB = manager.createProduct("ProductB");
    if (productB) {
        manager.assignStrategy(productB.get(), "Cooling");
        productB->process();
    }

    // ������ƷC��ָ����ϲ���
    std::unique_ptr<Product> productC = manager.createProduct("ProductC");
    if (productC) {
        manager.assignStrategy(productC.get(), "Mixing");
        productC->process();
    }

    return 0;
}