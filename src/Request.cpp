#include "Request.h"
Request::Request(int* arr) : time_(std::time(nullptr)) {
    op = arr[0];
    usd = arr[1];
    rub = arr[2];
    usr_id = arr[3];
}

Request::Request(int op, int usd, int rub, int id) : op(op), usd(usd), rub(rub), usr_id(id), time_(std::time(nullptr)) {};

Request::Request(const Request& req) {
    op = req.get_option();
    usd = req.get_usd();
    rub = req.get_rub();
    usr_id = req.get_id();
}

int Request::get_option() const {
    return op;
}

int Request::get_rub() const {
    return rub;
}

int Request::get_usd() const {
    return usd;
}

const std::time_t Request::get_time() const {
    return time_;
}

void Request::change_rub(int chng) {
    rub += chng;
}

void Request::set_rub(int rub) {
    this->rub = rub;
}

void Request::change_usd(int chng) {
    usd += chng;
}

void Request::set_usd(int usd) {
    this->usd = usd;
}

void Request::set_id(int id)
{
    this->usr_id = id;
}

int Request::get_id() const
{
    return usr_id;
}

bool operator<(const Request& a, const Request& b) {
    if (a.get_rub() != b.get_rub())
    {
        if(a.get_option() == -1)return a.get_rub() > b.get_rub();
        else return a.get_rub() < b.get_rub();
    }
    return a.get_time() < b.get_time();
}

inline bool operator>(const Request& a, const Request& b) { return b < a; }
inline bool operator<=(const Request& a, const Request& b) { return !(a > b); }
inline bool operator>=(const Request& a, const Request& b) { return !(a < b); }

std::ostream& operator<<(std::ostream& os, const Request& obj)
{
    os << (obj.get_option() == 1 ? "Покупка" : "Продажа") << " " << obj.get_usd() << " $ За " << obj.get_rub() << " рублей " << "От ID: " << obj.get_id() << "\n";
    return os;
}

