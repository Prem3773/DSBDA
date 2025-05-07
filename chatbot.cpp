#include <iostream>
#include <string>
using namespace std;

// Simple chatbot class for bus booking system
class ChatBot {
private:
    // Store questions and answers
    string questions[8];    // List of keywords
    string answers[8];      // List of responses
    int totalResponses;     // Number of responses available

    // Make text lowercase for easier matching
    string makeLowercase(string text) {
        for(int i = 0; i < text.length(); i++) {
            text[i] = tolower(text[i]);
        }
        return text;
    }

    // Setup all questions and answers
    void setupResponses() {
        questions[0] = "hello";
        answers[0] = "Hello! Welcome to RedBus. How can I help you?";

        questions[1] = "book";
        answers[1] = "To book a ticket, tell me your starting city and destination.";

        questions[2] = "cancel";
        answers[2] = "To cancel a ticket, go to My Bookings section.";

        questions[3] = "refund";
        answers[3] = "Refunds take 5-7 days after cancellation.";

        questions[4] = "price";
        answers[4] = "Please tell me which cities you want to travel between for price info.";

        questions[5] = "help";
        answers[5] = "Call us at 1800-123-1234 for help.";

        questions[6] = "timing";
        answers[6] = "Tell me your route to check bus timings.";

        questions[7] = "exit";
        answers[7] = "Goodbye! Have a safe journey!";

        totalResponses = 8;
    }

public:
    // Constructor - sets up the chatbot when created
    ChatBot() {
        setupResponses();
    }

    // Find and return appropriate answer for user's question
    string getAnswer(string userInput) {
        userInput = makeLowercase(userInput);
        
        // Check each question for a match
        for(int i = 0; i < totalResponses; i++) {
            if(userInput.find(questions[i]) != string::npos) {
                return answers[i];
            }
        }
        
        // If no match found
        return "Sorry, I didn't understand. Please try again.";
    }
};

// Main program
int main() {
    ChatBot bot;           // Create chatbot
    string userInput;      // Store what user types

    // Show welcome message
    cout << "Welcome to Bus Booking Helper!\n";
    cout << "You can ask about: book, cancel, refund, price, timing, help\n";
    cout << "Type 'exit' to end chat\n\n";

    // Keep chatting until user types 'exit'
    while(true) {
        cout << "\nYou: ";
        getline(cin, userInput);

        // Check if user wants to exit
        if(userInput == "exit") {
            cout << "Bot: Goodbye!\n";
            break;
        }

        // Get and show bot's response
        string botResponse = bot.getAnswer(userInput);
        cout << "Bot: " << botResponse << endl;
    }

    return 0;
}