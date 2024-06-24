#include "UnitManager.h"
#include "Shooter1.h"
#include "Tank1.h"

std::shared_ptr<Unit> UnitManager::getUnit(const std::string& unitType) {
    auto it = m_Units.find(unitType);
    if (it != m_Units.end()) {
        return it->second;
    }

    std::shared_ptr<Unit> unit;
    if (unitType == "Soldier") {
        unit = std::make_shared<Shooter1>();
    }
    else if (unitType == "Tank") {
        unit = std::make_shared<Tank1>();
    }

    if (unit) {
        m_Units[unitType] = unit;
    }

    return unit;
}
