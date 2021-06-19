class MyCalendar {
    
public:
    MyCalendar() {
        
    }
    
    map<int, int> cal;
    
    bool book(int start, int end) {
        
        auto curr = cal.lower_bound(end);
        
        if(curr != cal.begin() and (--curr)->second > start) {
            return false;
        }
        
        cal.insert(make_pair(start, end));
        
        return true;
    }
};