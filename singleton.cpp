#include <memory>
#include <string>
#include <iostream>

using std::string;


class History {
	
	static std::unique_ptr<History> singleton;
	string content="";

	History()=default;

public:
	
	static History &get() { 
		if ( not History::singleton ) {
			singleton = std::unique_ptr<History>(new History());
		} return *singleton;
	}

	void add(string s) { this->content += s + "\n"; }
	void display() const { std::cout << this->content << std::endl; }

};

std::unique_ptr<History> History::singleton = nullptr;


int main() {
	History::get().add("Start Main");
	
	History &history = History::get();
	history.add("History has been get");
	
	History::get().add("End of Main");
	history.display();
	return 0;
}

