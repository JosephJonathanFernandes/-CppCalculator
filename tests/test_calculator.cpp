// tests/test_calculator.cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "../include/calculator.h"

TEST_CASE("Basic arithmetic") {
    Calculator calc;
    double out{};
    std::string err;

    REQUIRE(calc.performOperation(2.0, '+', 3.0, out, err));
    REQUIRE(out == Approx(5.0));

    REQUIRE(calc.performOperation(10.0, '-', 4.0, out, err));
    REQUIRE(out == Approx(6.0));

    REQUIRE(calc.performOperation(3.0, '*', 4.0, out, err));
    REQUIRE(out == Approx(12.0));

    REQUIRE(calc.performOperation(9.0, '^', 2.0, out, err));
    REQUIRE(out == Approx(81.0));
}

TEST_CASE("Division and errors") {
    Calculator calc;
    double out{};
    std::string err;

    REQUIRE(calc.performOperation(10.0, '/', 2.0, out, err));
    REQUIRE(out == Approx(5.0));

    REQUIRE_FALSE(calc.performOperation(1.0, '/', 0.0, out, err));
    REQUIRE(err.find("Division") != std::string::npos);
}

TEST_CASE("Modulus behavior") {
    Calculator calc;
    double out{};
    std::string err;

    REQUIRE(calc.performOperation(10.0, '%', 3.0, out, err));
    REQUIRE(out == Approx(10 % 3));

    REQUIRE_FALSE(calc.performOperation(3.5, '%', 2.0, out, err));
    REQUIRE(err.find("integer") != std::string::npos);
}
