#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height)
{
    m_width = width;
    m_height = height;

    m_matrix = new char* [m_height];
    for (int i = 0; i < m_height; ++i)
    {
        m_matrix[i] = new char[m_width];
    }

    Clear();
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < m_width && y >= 0 && y < m_height)
        m_matrix[y][x] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int r2 = ray * ray;

    for (int i = y - ray; i <= y + ray; ++i) {
        for (int j = x - ray; j <= x + ray; ++j) {
            int dx = j - x;
            int dy = i - y;
            int d2 = dx * dx + dy * dy;
            if (d2 >= r2 - ray && d2 <= r2 + ray) {
                SetPoint(j, i, ch);
            }
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = y - ray; i <= y + ray; ++i)
        for (int j = x - ray; j <= x + ray; ++j)
            if ((i - y) * (i - y) + (j - x) * (j - x) <= ray * ray)
                SetPoint(j, i, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; ++i)
        for (int j = left; j <= right; ++j)
            if (i == top || i == bottom || j == left || j == right)
                SetPoint(j, i, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; ++i)
        for (int j = left; j <= right; ++j)
            SetPoint(j, i, ch);
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int deltaX = abs(x2 - x1);
    int deltaY = abs(y2 - y1);
    int stepX = x1 < x2 ? 1 : -1;
    int stepY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;

    while (true)
    {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int doubleError = error * 2;
        if (doubleError > -deltaY) {
            error -= deltaY;
            x1 += stepX;
        }
        if (doubleError < deltaX) {
            error += deltaX;
            y1 += stepY;
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < m_height; ++i)
    {
        for (int j = 0; j < m_width; ++j)
            cout << m_matrix[i][j];
        cout << endl;
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < m_height; ++i)
        for (int j = 0; j < m_width; ++j)
            m_matrix[i][j] = ' ';
}
