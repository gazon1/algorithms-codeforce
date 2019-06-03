// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <exception>
#include <tuple>

#define _DEBUG 1
#define DEBUG() if(_DEBUG)
#define PVAR(x) DEBUG(){ cout << (#x) << ": " << x << "; "; }




using namespace std;

struct Day {
  int value;

  explicit Day(int new_value) { value = new_value; }

};

struct Month {
  int value;

  explicit Month(int new_value) { value = new_value; }

};

struct Year {
  int value;

  explicit Year(int new_value) { value = new_value; }

};



class Date {
public:
  int day;
  int month;

  int year;

  Date(Day new_day,
       Month new_month,
       Year new_year) {
    day = new_day.value;
    month = new_month.value;
    year = new_year.value;
  }

  Date(const Date& date) {
    day = date.GetDay();
    month = date.GetMonth();
    year = date.GetYear();
  }
  
  int GetYear() const { return day; }
  int GetMonth() const { return month; }
  int GetDay() const { return year; }

  string GetString() const;
};



ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(2) << setfill('0') << date.GetYear() << "-"
	 << setw(2) << setfill('0') << date.GetMonth() << "-"
	 << setw(2) << setfill('0') << date.GetDay();
  return stream;
}



bool operator<(const Date& lhs, const Date& rhs) {
  return tie(lhs.year, lhs.month, lhs.day) <  tie(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Date& lhs, const Date& rhs) {
  return tie(lhs.year, lhs.month, lhs.day) ==  tie(rhs.year, rhs.month, rhs.day);
}





class Event {
public:
  string value;
  Event(string s): value(s) {}
};
struct Record {
  Date date;
  Event event;
};
 
istream& operator>>(istream& stream, Event& event) {
  getline(stream, event.value);
  return stream;
}



class Database {
public:
  void AddEvent(const Date& date, const string& event);
  bool DeleteEvent(const Date& date, const string& event);
  int  DeleteDate(const Date& date);

  vector<Record> Find(const Date& date) const;
  
  void Print() const;
  void Delete(const Date& date, const string& event);
  
private:
  const string file_name = "BD.txt";
  const vector<string> columns = {"Дата", "Событие"};
  const int width = 5;

  vector<Record> rows;
};


vector<Record> Database::Find(const Date& date) const {
  vector<Record> to_return;
  for (auto& i : this->rows) {
    if (i.date == date) {
      to_return.push_back(i);
    }
  }

  return to_return;

}






void Database::AddEvent(const Date& date, const string& event) {
  ofstream output(this->file_name, ios::app);
  if (output) {
    output << date << " " << event << endl;
    cout << "Event записан!" << endl;
  } else {
    cout << "Ошибка при открытии файла в методе AddEvent!" << endl;
  }
}



void Database::Print() const {
  for (const auto& c : this->columns) {
    cout << setw(this->width) << c << ' ';
  }

  cout << endl;
  cout << fixed << setprecision(2);
  ifstream file(this->file_name);
  string line;

  if (file) {
    while (getline(file, line)) {
      cout << line << endl;
    }
    cout << "Все данные прочитаны!" << endl;
  } else {
    cout << "Ошибка при попытке открыть файл" << endl;
  }

}





enum class Command {
  ADD,
  DEL,
  FIND,
  PRINT
};

Command getCommand(string str_command) {
  if (str_command == "Add") return Command::ADD;
  if (str_command == "Del") return Command::DEL;
  if (str_command == "Find") return Command::FIND;
  if (str_command == "Print") return Command::PRINT;

  stringstream ss;
  ss << "Error: found unsuported command: " << str_command << endl;
  throw runtime_error(ss.str());
}

void EnsureNextSymbolAndSkip(stringstream& stream) {
  if (stream.peek() != '-') {
    stringstream ss;
    ss << "Error: expected '-' in input as a delimiter in date but found " << stream.peek() << endl;
    throw runtime_error(ss.str());
  }
  stream.ignore(1);
}

Date parseDate(const string& s) {
  stringstream stream(s);
  int day, month, year;
  stream >> day;
  EnsureNextSymbolAndSkip(stream);
  stream >> month;
  EnsureNextSymbolAndSkip(stream);
  stream >> year;

  return Date(Day(day), Month(month), Year(year));
}


Event parseEvent(const string& s) {
  return Event(s);
}


int main() {
  Database db;

  ifstream input("BD.txt");
  string line;
  if (input) {
    while (getline(input, line)) {
      cout << line << endl;
    }
  } else {
    cout << "Ошибка при открытии файла" << endl;
  }

  string command;
  stringstream ss;
  while (getline(cin, command)) {
    string whole_string;
    ss.str(command);
    whole_string = command;
    try {
      ss >> command;
      PVAR(command);
      PVAR(whole_string);
      Command operation = getCommand(command);

    switch (operation) {
    case Command::ADD: {
      string str;
      ss >> str;
      Date date(parseDate(str));
      db.AddEvent(date, whole_string.substr(command.length() + str.length() + 1));
      break;
    }
    case Command::DEL: {
      string str;
      ss >> str;
      Date date(parseDate(str));
      ss >> str;
      //      Event event(parseEvent(str));
      //      db.Delete(date, event);
      break;

    }
    case Command::PRINT: {
      db.Print();
      break;
    }
    case Command::FIND: {
      string str;
      ss >> str;

      vector<Record> output(db.Find(parseDate(str)));
      cout << "Резулльтаты поиска: " << endl;
      for (auto& i : output) cout << i.date << i.event.value << endl;
      break;
    }
    }
    } catch (exception& ex) {
      cout << ex.what();
    }
    
  }
  return 0;
}
