#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex idx);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};

};

class Screen {
    friend void Window_mgr::clear(ScreenIndex idx);
public:
    using pos = std::string::size_type; // 类型成员

    Screen() : contents(), cursor(0), height(0), width(0) {}
    
    Screen(pos ht, pos wd, char ch = ' ')
        : contents(ht * wd, ch), height(ht), width(wd) {}

    char get() const { return contents[cursor]; }

    char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);

    void some_member() const { ++count; }

    Screen &set(char ch);

    Screen &set(pos row, pos col, char ch);

    Screen &display(std::ostream &os) { do_display(os); return *this; }

    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
    
private:
    std::string contents;
    pos cursor = 0;
    pos height = 0, width = 0;

    mutable size_t count = 0;

    void do_display(std::ostream &os) const { os << contents; }
};

inline char Screen::get(pos r, pos c) const {
    return contents[r * width + c];
}

inline Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;
    return *this;
}

inline void Window_mgr::clear(ScreenIndex idx) {
    Screen &s = screens[idx];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif // SCRREN_H