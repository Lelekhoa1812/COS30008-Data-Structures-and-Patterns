#include "ComponentBase.h"
ComponentBase::ComponentBase(double aBaseValue,
    const std::string& aMajorUnit,
    const std::string& aMinorUnits) noexcept :
    fBaseValue (aBaseValue),
    fMajorUnit(aMajorUnit),
    fMinorUnits (aMinorUnits)
{
    assert(aMajorUnit.size() > 0 && aMinorUnits.size() > 0 && aMajorUnit[0] == aMinorUnits[0]);
}
 double ComponentBase::getBaseValue() const noexcept
{
    return fBaseValue;
}

void ComponentBase::setBaseValue(double aBaseValue) noexcept
{
    fBaseValue = aBaseValue;
}

const std::string &  ComponentBase::getMajorUnit() const noexcept
{
    return fMajorUnit;
}

const std::string &  ComponentBase::getMinorUnits() const noexcept
{
    return fMinorUnits;
}

double ComponentBase::getPotentialAt(double aCurrent, double aFrequency) const noexcept
{
    // R = U/I => U = R*I
    return getReactance(aFrequency) * aCurrent;
}

double ComponentBase::getCurrentAt(double aVoltage, double aFrequency) const noexcept
{
    // U = R*I => R = U/I
    assert(getReactance(aFrequency) != 0.0);
    return aVoltage/getReactance(aFrequency);
}

std::istream& operator>>(std::istream& aIStream, ComponentBase& aObject)
{
    double lValue;
    std::string lUnit;
    
    aIStream >> lValue >> lUnit;
    
    aObject.setBaseValue(lValue, lUnit);
    
    return aIStream;
}

std::ostream& operator<<(std::ostream& aOStream, const ComponentBase& aObject)
{
    double lValue;
    std::string lUnit;
    
    aObject.toUnitValue(lValue, lUnit);
    
    aOStream << lValue << " " << lUnit;

    return aOStream;
}
