#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Function to generate random applicants with quality scores
std::vector<int> generateApplicants(int n) {
    std::vector<int> applicants(n);
    for (int i = 0; i < n; ++i) {
        applicants[i] = i + 1;
    }
    std::random_shuffle(applicants.begin(), applicants.end());
    return applicants;
}

// Function to implement the secretary problem algorithm
int selectBestApplicant(const std::vector<int>& applicants) {
    int n = applicants.size();
    int k = static_cast<int>(n / std::exp(1)); // Number of applicants to skip
    
    int bestSoFar = -1;
    for (int i = 0; i < k; ++i) {
        if (applicants[i] > bestSoFar) {
            bestSoFar = applicants[i];
        }
    }

    for (int i = k; i < n; ++i) {
        if (applicants[i] > bestSoFar) {
            return applicants[i]; // Select the first applicant better than bestSoFar
        }
    }

    return applicants[n-1]; // If no better applicant is found, select the last one
}

int main() {
    std::srand(std::time(0)); // Seed for random number generation

    int n = 100; // Number of applicants
    std::vector<int> applicants = generateApplicants(n);

    std::cout << "Applicants' quality scores: ";
    for (int score : applicants) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    int bestApplicant = selectBestApplicant(applicants);
    std::cout << "Best applicant selected with quality score: " << bestApplicant << std::endl;

    return 0;
}
