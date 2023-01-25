#include <iostream>
#include <vector>


class Observer {
public:
	virtual void update()=0;
};

class Subject {

	std::vector<Observer*> observers;

public:
	
	void registerObserver(Observer* observer) {
		observers.push_back(observer);
	}
	void removeObserver(Observer* observer) {
		for ( auto it = observers.begin(); it!= observers.end(); ++it ) {
			if ( *it == observer ) { 
				observers.erase(it);
				break;
			}
		}
	}
	void notifyObserver() const {
		for ( auto &observer : observers ) { observer ->update(); }
	}

};

