#pragma once
#include "fstream"
struct Vector2D  // Represents a 2D vector
{
    float x = 0;  // The first coordinate
    float y = 0;  // The second coordinate
    Vector2D operator*(float scale) { return Vector2D{x * scale, y * scale}; }  // Scalar multiplication
    Vector2D operator/(float scale) { return Vector2D{x / scale, y / scale}; }  // Scalar division
    Vector2D operator+(float scale) { return Vector2D{x + scale, y + scale}; }  // Scalar addition
    Vector2D operator-(float scale) { return Vector2D{x - scale, y - scale}; }  // Scalar subtraction
    Vector2D operator*(const Vector2D & v) { return Vector2D{x * v.x, y * v.y}; }  // Element-wise multiplication
    Vector2D operator/(const Vector2D & v) { return Vector2D{x / v.x, y / v.y}; }  // Element-wise division
    Vector2D operator+(const Vector2D & v) { return Vector2D{x + v.x, y + v.y}; }  // Element-wise addition
    Vector2D operator-(const Vector2D & v) { return Vector2D{x - v.x, y - v.y}; }  // Element-wise subtraction
    Vector2D & operator*=(const Vector2D & v) { x *= v.x; y *= v.y; return *this; }  // Element-wise multiplication
    Vector2D & operator/=(const Vector2D & v) { x /= v.x; y /= v.y; return *this; }  // Element-wise division
    Vector2D & operator+=(const Vector2D & v) { x += v.x; y += v.y; return *this; }  // Element-wise addition
    Vector2D & operator-=(const Vector2D & v) { x -= v.x; y -= v.y; return *this; }  // Element-wise subtraction
};

enum FlipperType { LEFT, RIGHT };

