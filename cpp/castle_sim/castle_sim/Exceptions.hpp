#pragma once
#include <stdexcept>
#include <string>

// Казарма переполнена: ошибка времени выполнения.
class BarracksFullException : public std::runtime_error
{
public:
    BarracksFullException(const std::string& barracksName, int capacity)
        : std::runtime_error{ "казарма " + barracksName + " переполнена (вместимость "
                              + std::to_string(capacity) + ")" }
    {}
};

// В казне не хватает золота.
class InsufficientGoldException : public std::runtime_error
{
public:
    InsufficientGoldException(int requested, int available)
        : std::runtime_error{ "недостаточно золота: нужно " + std::to_string(requested)
                              + ", есть " + std::to_string(available) }
    {}
};
