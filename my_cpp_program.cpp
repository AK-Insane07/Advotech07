#include <iostream>
#include <string>
#include <algorithm> // for std::transform
#include <sstream>   // for std::istringstream

struct Paragraph {
    std::string title;
    std::string content;
};

// Function to convert a string to lowercase
void toLowerCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

bool containsSubstring(const std::string& str, const std::string& substr) {
    std::string strLower(str);
    std::string substrLower(substr);

    // Convert both strings to lowercase for case-insensitive comparison
    std::transform(strLower.begin(), strLower.end(), strLower.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    std::transform(substrLower.begin(), substrLower.end(), substrLower.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    return (strLower.find(substrLower) != std::string::npos);
}

int main() {
    // Sample paragraphs and titles
    Paragraph paragraphs[] = {
        
        {"Robbery", " If someone robbed your something section 378  Theft. Whoever, intending to take dishonestly any movable property out of the possession of any person without that person' consent, moves that property in order to such taking, is said to commit "
        } , 
        {
            "Robbed " ,  " Section 154 - Information in Cognizable Cases\n"
            "Section 156 - Investigation by Police Officer\n"
                     "Following the filing of the FIR, the police officer registered the case and initiated an investigation under Section 156 of the CrPC.\n "
                     "\n"
                     "Section 157 - Procedure for Investigation\n"

                     "Under Section 157 of the CrPC, the investigating officer conducted a thorough investigation, which involved questioning witnesses, analyzing fingerprints, and obtaining CCTV footage from neighboring properties.\n "
                     "\n"
                     "Section 162 - Statements to Police\n"
                     "During the investigation, the police officer recorded statements from witnesses, including Ms. Aisha Sharma, under Section 162 of the CrPC. These statements were integral to understanding the sequence of events and determining the modus operandi of the theft.\n"
                     "\n"
                     "Section 173 - Report of Investigation\n"
                     "Upon completing the investigation, the police officer prepared a report of investigation in compliance with Section 173 of the CrPC.\n "
                     "\n"

        }
    };

    // Get user input
    std::string userInput;
    std::cout << "Enter a keyword to search for: "<<"\n";
    std::getline(std::cin, userInput);

    // Convert input to lowercase for case-insensitive comparison
    toLowerCase(userInput);

    // Split the input into words
    std::istringstream iss(userInput);
    std::string word;
    bool found = false;

    // Check each word for a matching title (case-insensitive)
    while (iss >> word) {
        for (const auto& paragraph : paragraphs) {
            if (containsSubstring(paragraph.title, word)) {
                std::cout << "Title: " << paragraph.title << "\n";
                std::cout << "Content: " << paragraph.content <<"\n\n"; 
                found = true;
                break;
            }
        }
        if (found)
            break;  // Stop searching if a match is found
    }

    if (!found)
        std::cout << "No matching title found.\n";

    return 0;
}
