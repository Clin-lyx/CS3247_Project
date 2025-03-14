#include "EnchantmentDamageData.h"

#include "CS3247_Project/UI/Texts/TextUtil.h"

FString FEnchantmentDamageData::ToString() const {
	const int Dmg = FMath::CeilToInt(this->DamageValue);
	return FString::Printf(TEXT("%d %s damage"), Dmg, *this->DamageType.ToString());
}

FString FEnchantmentDamageData::ToRichText() const {
	const int Dmg = FMath::CeilToInt(this->DamageValue);
	const FString DmgNum = UTextUtil::Red(FString::Printf(TEXT("%d"), Dmg));
	const FString DmgType = UTextUtil::BfIt(FString::Printf(TEXT("%s"), *this->DamageType.ToString()));
	return FString::Printf(TEXT("Deals %s %s damage"), *DmgNum, *DmgType);
}

FEnchantmentDamageData FEnchantmentDamageData::operator+(const double Offset) const {
	return FEnchantmentDamageData(this->DamageType, this->DamageValue + Offset);
}

FEnchantmentDamageData FEnchantmentDamageData::operator-(const double Offset) const {
	return *this + (-Offset);
}

FEnchantmentDamageData FEnchantmentDamageData::operator*(const double Factor) const {
	return FEnchantmentDamageData(this->DamageType, this->DamageValue * Factor);
}

FEnchantmentDamageData FEnchantmentDamageData::operator+=(const double Value) const {
	return *this + Value;
}

FEnchantmentDamageData FEnchantmentDamageData::operator-=(const double Value) const {
	return *this - Value;
}

FEnchantmentDamageData FEnchantmentDamageData::operator*=(const double Value) const {
	return *this * Value;
}

bool FEnchantmentDamageData::operator>(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) > Value;
}

bool FEnchantmentDamageData::operator<(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) < Value;
}

bool FEnchantmentDamageData::operator==(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) == Value;
}

bool FEnchantmentDamageData::operator!=(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) != Value;
}

bool FEnchantmentDamageData::operator>=(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) >= Value;
}

bool FEnchantmentDamageData::operator<=(const int Value) const {
	return FMath::CeilToInt(this->DamageValue) <= Value;
}

