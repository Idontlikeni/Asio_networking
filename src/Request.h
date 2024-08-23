#pragma once
#include <chrono>
#include <iostream>

class Request {
public:
    Request(int op, int usd, int rub, int id);
    Request(int* arr);
    Request(const Request& req);
    friend bool operator<(const Request& a, const Request& b);
    friend bool operator>(const Request& a, const Request& b);
    friend bool operator<=(const Request& a, const Request& b);
    friend bool operator>=(const Request& a, const Request& b);
    friend std::ostream& operator<<(std::ostream& os, const Request& obj);
    //friend std::ostream& operator>>(std::ostream& os, const Request& obj);

    int get_option() const;

    int get_rub() const;

    int get_usd() const;

    int get_id() const;

    const std::time_t get_time() const;

    void change_rub(int chng);

    void set_rub(int rub);

    void change_usd(int chng);

    void set_usd(int usd);

    void set_id(int id);
private:
    int op, usd, rub, usr_id;
    std::time_t time_;
};