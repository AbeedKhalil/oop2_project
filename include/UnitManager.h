#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include "Unit.h"
#include <map>
#include <string>
#include <memory>

class UnitManager {
public:
    static UnitManager& getInstance() {
        static UnitManager instance;
        return instance;
    }

    std::shared_ptr<Unit> getUnit(const std::string& unitType);

private:
    UnitManager() {}
    UnitManager(const UnitManager&) = delete;
    UnitManager& operator=(const UnitManager&) = delete;

    std::map<std::string, std::shared_ptr<Unit>> m_Units;
};

#endif // UNITMANAGER_H
