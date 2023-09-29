#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>


class Timer {
    typedef std::vector<int> (*fncPtr)(int);
    std::chrono::duration<double> time {};

public:
    auto operator()(fncPtr fnc, int x) {
        auto start = std::chrono::steady_clock::now();
        const auto primes = fnc(x);  // Call the function to be profiled
        auto stop = std::chrono::steady_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::microseconds> (stop - start);
        time = std::chrono::duration<double> (t);
        return primes;
    }

    [[nodiscard]] auto getTime() const {
        return time.count();
    }
};


bool isPrime(const int n) {
    int i = 2;
    while (i < std::floor(n / 2 )) {
        if (n % i == 0) {
            return false;
        } else { i++; }
    }
    return true;
}

std::vector<int> primeFinder(const int n) {
    // find and return all the prime numbers from 1 -> n
    std::vector<int> primes {};
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.emplace_back(i);
        }
    }
    return primes;
}


int main() {
    constexpr int n = 20000;
    auto timer = Timer();

    const auto primes = timer(&primeFinder, n);
    const auto time = timer.getTime();

    std::cout << time << "s\n";
//    for (const auto p : primes) {
//        std::cout << p << ' ' << '\n';
//    }

    return 0;
}

