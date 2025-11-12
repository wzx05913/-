#pragma once
#ifndef FOOD_H
#define FOOD_H

#include <QString>
#include <QList>

// 餐食类型枚举
enum class FoodType {
    MainCourse,  // 主餐
    Vegetable,   // 蔬菜
    Fruit,       // 水果
    Snack,       // 零食
    Beverage     // 饮料
};

class Food {
private:
    int m_id;
    QString m_name;
    FoodType m_type;
    double m_price;
    int m_calories;
    bool m_isVegetarian;
    bool m_containsAllergens;
    QString m_description;

public:
    Food(int id, const QString& name, FoodType type, double price);

    // Getter/Setter方法
    int getId() const { return m_id; }
    QString getName() const { return m_name; }
    FoodType getType() const { return m_type; }
    double getPrice() const { return m_price; }
    int getCalories() const { return m_calories; }
    bool isVegetarian() const { return m_isVegetarian; }
    bool containsAllergens() const { return m_containsAllergens; }

    void setCalories(int calories) { m_calories = calories; }
    void setVegetarian(bool vegetarian) { m_isVegetarian = vegetarian; }
    void setContainsAllergens(bool allergens) { m_containsAllergens = allergens; }
    void setDescription(const QString& desc) { m_description = desc; }

    // 静态方法 - 餐食类型转换
    static QString foodTypeToString(FoodType type);
    static FoodType stringToFoodType(const QString& typeStr);

    QString getFoodInfo() const;
    bool isSuitableFor(const QString& dietaryRestriction) const;
};

#endif // FOOD_H