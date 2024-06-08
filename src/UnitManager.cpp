#include "UnitManager.h"
#include "Soldier.h"
#include "Tank.h"

std::shared_ptr<Unit> UnitManager::getUnit(const std::string& unitType) {
    auto it = m_Units.find(unitType);
    if (it != m_Units.end()) {
        return it->second;
    }

    std::shared_ptr<Unit> unit;
    if (unitType == "Soldier") {
        unit = std::make_shared<Soldier>();
    }
    else if (unitType == "Tank") {
        unit = std::make_shared<Tank>();
    }

    if (unit) {
        m_Units[unitType] = unit;
    }

    return unit;
}
