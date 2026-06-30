#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _dataBase(other._dataBase) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_dataBase.operator=(other._dataBase);
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::load_data_base() 
{

    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open Data Base file" << std::endl;
        return ;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        int year, month, day = 0;
        double value = 0.0;
        char dilimiter;
        std::istringstream stream(line);
        if (stream >> year >> dilimiter >> month >> dilimiter >> day >> dilimiter >> value) {
            this->_dataBase.insert(std::make_pair(Date(year, month, day), value));
        }
        else {
            std::cerr << "Error: could not load data base" << std::endl;
        }
    }

    std::cout << "data base loaded seccusfully" << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------------- the result of appling rate is -------------------------------" << std::endl << std::endl;
}

void BitcoinExchange::print_data_base() {
    for (std::map<Date, double>::iterator it = _dataBase.begin(); it != _dataBase.end(); it++) {
        std::cout << "date " << it->first << " value: " << it->second << std::endl;
    }
}

void BitcoinExchange::parse_header(std::ifstream& file, std::string& line) {

    while (std::getline(file, line)) {
        line = trim(line);
        if (line == "")
        {
            continue ;
        }
        else
        {
            void **splited_items = split_into_items(line, 3);
            if (!splited_items) {
                std::cerr << "Error: invalid header " << line << std::endl;
            } else {
                std::string warning_message = "Warning:";
                if (*(reinterpret_cast<std::string *>(splited_items[0])) != "date") {
                    warning_message += " unkown " + *(reinterpret_cast<std::string *>(splited_items[0]));
                }
                if (*(reinterpret_cast<std::string *>(splited_items[1])) != "|") {
                    if (warning_message != "Warning:")
                        warning_message += " and";
                    warning_message +=  " unkown " + *(reinterpret_cast<std::string *>(splited_items[1]));
                }
                if (*(reinterpret_cast<std::string *>(splited_items[2])) != "value") {
                    if (warning_message != "Warning:")
                        warning_message += " and";
                    warning_message += " unkown " + *(reinterpret_cast<std::string *>(splited_items[2]));
                }
                if (warning_message != "Warning:") {
                    warning_message += " from header input file.";
                    std::cerr << warning_message << std::endl;
                }
            }
            delete_items(splited_items, 3);
            break ;
        }
    }

}

std::pair<bool, Date> BitcoinExchange::parse_date(const std::string& date)
{
    int year, month, day = 0;
    char dilimiter;
    std::istringstream stream(date);
    
    if (stream >> year >> dilimiter >> month >> dilimiter >> day) {
        std::pair<bool, Date> p(false, Date(year, month, day));
        if (year < 2009) {
            std::cerr << "Error: invalid year bitcoin was not exist this year." << std::endl;
            return p;
        }
        if (month < 1 || month > 12) {
            std::cerr << "Error: invalid month (month should be between 1 and 12)." << std::endl;
            return p;
        }
        if (day < 1 || day > Date::getMaxDaysInMonth(month, year)) {
            std::cerr << "Error: invalid day " << day << std::endl;
            return p;
        }
        p.first = true;
        return p;
    }

    std::cerr << "Error: invalid date => " << date << std::endl;
    return std::make_pair(false, Date(0,0,0));
}

std::pair<bool, double> BitcoinExchange::parse_value(const std::string& val)
{
    double value = 0.0;
    std::istringstream stream(val);
    
    if (stream >> value) {

        if (value > 1000.0) {
            std::cerr << "Error: number too large (number must be between 0 and 1000)." << std::endl;
            return std::make_pair(false, value);
        }

        if (value < 0.0) {
            std::cerr << "Error: not a positive number " << value << std::endl;
            return std::make_pair(false, value);
        }

        return std::make_pair(true, value);
    }

    std::cerr << "Error: invalid argument for the value => " << value << std::endl;
    return std::make_pair(false, 0.0);
}


void BitcoinExchange::parse_data_and_display(const std::string& line) {

    void **splited_items = split_into_items(line, 3);

    if (!splited_items || *(reinterpret_cast<std::string *>(splited_items[1])) != "|") {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }

    bool is_valid = true;

    std::pair<bool, Date> p_date = parse_date(*(reinterpret_cast<std::string *>(splited_items[0])));

    if (!p_date.first) {
        is_valid = false;
    }

    std::pair<bool, double> p_val;
    if (is_valid) {
        p_val = parse_value(*(reinterpret_cast<std::string *>(splited_items[2])));
    }

    if (!p_val.first) {
        is_valid = false;
    }

    if (is_valid) {
        double result = get_exchange_rate_for_that_year(p_date.second, p_val.second);
        std::cout << *(reinterpret_cast<std::string *>(splited_items[0])) << " => " << p_val.second << " = " << result << std::endl;
    }

    delete_items(splited_items, 3);
}

double BitcoinExchange::get_exchange_rate_for_that_year(Date dt, const double& val)
{
    Date currentDate = dt;

    while (true) {
        std::map<Date, double>::iterator it = _dataBase.find(currentDate);
        if (it != _dataBase.end()) {
            return (it->second * val);
        }
        --currentDate;
        if (currentDate.get_year() == 0) {
            std::cout << "No data base performd ";
            return 0.0;
        }
    }
}

void BitcoinExchange::applyRate(std::string file_name)
{
    std::ifstream file(file_name.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }

    std::string line;
    parse_header(file, line);
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line == "") {
            continue ;
        } else {
            parse_data_and_display(line);
        }
    }

    std::cout << std::endl;
    std::cout << "-------------------------------------------- Done. ----------------------------------------------" << std::endl;
}



// --------------------------------------------helpers---------------------------------------------------------------------

void BitcoinExchange::delete_items(void **addresses, const size_t& size) {
    if (!addresses) return;
    for (size_t i = 0; i < size; i++) {
        delete reinterpret_cast<std::string *>(addresses[i]);
    }
    delete[] addresses;
}

void **BitcoinExchange::split_into_items(const std::string& line, const size_t& items_size) {

    void **address_holder = new void*[items_size];
    size_t items_counter = 0;
    size_t index = 0;
    size_t start = 0;

    while (line[index])
    {
        if (!is_whitespace(line[index]) && line[index + 1] != '\0') {
            index++;
            continue ;
        }
        else {
            if (line[index + 1] == '\0') {
                index++;
            }
            if (items_counter >= items_size) {
                delete_items(address_holder, items_counter);
                return NULL;
            }
            address_holder[items_counter++] = reinterpret_cast<void *>(new std::string(line.substr(start, index - start)));
            while (line[index])
            {
                if (is_whitespace(line[index])) {
                    index++;
                    continue ;
                } else {
                    break;
                }
            }
            start = index;
        }
    }
    if (items_counter < items_size) {
        delete_items(address_holder, items_counter);
        return NULL;
    }
    return address_holder;
}

bool BitcoinExchange::is_whitespace(const char& c) const {
    return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
}

std::string BitcoinExchange::trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");

    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.get_year() << "-" << date.get_month() << "-" << date.get_day();
    return os;
}

// ---------------- date class ---------------------------------------------

Date::Date(int year, int month, int day) : _year(year), _month(month), _day(day) {}

Date::Date(const Date& other) {
    this->_year = other._year;
    this->_month = other._month;
    this->_day = other._day;
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        this->_year = other._year;
        this->_month = other._month;
        this->_day = other._day;
    }
    return *this;
}

Date::~Date() {}

bool Date::operator<(const Date& other) const {
    if (_year != other._year) return _year < other._year;
    if (_month != other._month) return _month < other._month;
    return _day < other._day;
}

bool Date::operator==(const Date& other) const {
    return _year == other._year && _month == other._month && _day == other._day;
}

Date& Date::operator--() {
    if (this->_day > 1) {
        this->_day -= 1;
    }
    else if (this->_month > 1) {
        this->_month -= 1;
        this->_day = Date::getMaxDaysInMonth(this->_month, this->_year); 
    }
    else if (this->_year > 2009) {
        this->_year -= 1;
        this->_month = 12;
        this->_day = 31;
    }
    else {
        this->_year = 0;
        this->_month = 0;
        this->_day = 0;
    }
    return *this;
}

int Date::get_year() const {
    return this->_year;
}

int Date::get_month() const {
    return this->_month;
}

int Date::get_day() const {
    return this->_day;
}

bool Date::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::getMaxDaysInMonth(int month, int year) {

    const int daysPerMonth[14] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && Date::isLeapYear(year)) {
        return 29;
    }

    return daysPerMonth[month];
}