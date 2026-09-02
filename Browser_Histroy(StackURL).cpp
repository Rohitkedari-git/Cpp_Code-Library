#include<iostream>
#include<string>
using namespace std;
#define MAX 5

class BrowserHistory {
public:
    string arr[MAX];
    int top;
    
    BrowserHistory() {
        top = -1;
    }
    
    void visit(string url) {
        if(top == MAX - 1) {
            cout << "History limit reached! (Overflow)" << endl;
        }
        else {
            top++;
            arr[top] = url;
            cout << "Visited: " << url << endl;
        }
    }
    
    void goBack() { 
        if(top == -1) {
            cout << "No history available to go back! (Underflow)" << endl;
        }
        else {
            cout << "Went back from: " << arr[top] << endl;
            top--;
        }
    }
    
    void displayHistory() {
        if(top == -1) {
            cout << "Browsing history is empty." << endl;
        } 
        else {
            cout << "--- Browsing History (Most Recent First) ---" << endl;
            for(int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    }
    
    void currentPage() { 
        if (top == -1) {
            cout << "No current page open." << endl;
            return;
        }
        cout << "Current Page: " << arr[top] << endl;
    }
}; 
    
int main() {
    BrowserHistory portal;
    
    portal.visit("https://chatgpt.com/");
    portal.visit("https://github.com/");
    portal.visit("https://web.whatsapp.com/");
    portal.visit("https://www.nmiet.edu.in/");
    portal.visit("https://onlinecourses.nptel.ac.in/e-learning/preview/noc26_cs109");
    portal.visit("https://leetcode.com/problems/smallest-divisible-digit-product-i/description/?envType=daily-question&envId=2026-08-06");
    
    portal.goBack(); 
    portal.goBack();
    portal.goBack();
    portal.goBack();
    portal.goBack();
    portal.goBack();
    
    portal.visit("");
    
    portal.currentPage();
    
    portal.displayHistory();
    
    return 0;
}
