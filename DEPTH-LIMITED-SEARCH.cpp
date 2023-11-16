#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct State {
    int a, b, c;
    State(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
    bool operator==(const State& other) const {
        return (a == other.a && b == other.b && c == other.c);
    }
};

namespace std {
    template <>
    struct hash<State> {
        size_t operator()(const State& s) const {
            return hash<int>()(s.a) ^ hash<int>()(s.b) ^ hash<int>()(s.c);
        }
    };
}

bool isGoalState(const State& s) {
    return (s.a == 4 && s.b == 4);
}

bool isValidState(const State& s) {
    return (s.a >= 0 && s.b >= 0 && s.c >= 0 &&
            s.a <= 8 && s.b <= 5 && s.c <= 3);
}

void printPath(const vector<State>& path) {
    for (const auto& state : path) {
        cout << "A:" << state.a << " B:" << state.b << " C:" << state.c << endl;
    }
}

bool depthLimitedSearch(State currentState, int depth, int maxDepth, unordered_set<State>& visited, vector<State>& path) {
    if (isGoalState(currentState)) {
        path.push_back(currentState);
        return true;
    }

    if (depth == maxDepth) {
        return false;
    }

    visited.insert(currentState);

    // Pour water from A to B
    if (currentState.a > 0 && currentState.b < 5) {
        int amount = min(currentState.a, 5 - currentState.b);
        State newState(currentState.a - amount, currentState.b + amount, currentState.c);
        if (visited.find(newState) == visited.end() && depthLimitedSearch(newState, depth + 1, maxDepth, visited, path)) {
            path.push_back(currentState);
            return true;
        }
    }

    // Pour water from A to C
    if (currentState.a > 0 && currentState.c < 3) {
        int amount = min(currentState.a, 3 - currentState.c);
        State newState(currentState.a - amount, currentState.b, currentState.c + amount);
        if (visited.find(newState) == visited.end() && depthLimitedSearch(newState, depth + 1, maxDepth, visited, path)) {
            path.push_back(currentState);
            return true;
        }
    }

    // Pour water from B to A
    if (currentState.b > 0 && currentState.a < 8) {
        int amount = min(currentState.b, 8 - currentState.a);
        State newState(currentState.a + amount, currentState.b - amount, currentState.c);
        if (visited.find(newState) == visited.end() && depthLimitedSearch(newState, depth + 1, maxDepth, visited, path)) {
            path.push_back(currentState);
            return true;
        }
    }

    // Pour water from B to C
    if (currentState.b > 0 && currentState.c < 3) {
        int amount = min(currentState.b, 3 - currentState.c);
        State newState(currentState.a, currentState.b - amount, currentState.c + amount);
        if (visited.find(newState) == visited.end() && depthLimitedSearch(newState, depth + 1, maxDepth, visited, path)) {
            path.push_back(currentState);
            return true;
        }
    }

    // Pour water from C to A
    if (currentState.c > 0 && currentState.a < 8) {
        int amount = min(currentState.c, 8 - currentState.a);
        State newState(currentState.a + amount, currentState.b, currentState.c - amount);
        if (visited.find(newState) == visited.end() && depthLimitedSearch(newState, depth + 1, maxDepth, visited, path)) {
            path.push_back(currentState);
            return true;
        }
    }

    // Pour water from C to B
    if (currentState.c > 0 && currentState.b < 5) {
        int amount = min(currentState.c, 5 - currentState.b);
        State newState(currentState.a, currentState.b + amount, currentState.c - amount);
        if (visited.find(newState) == visited.end() && depthLimitedSearch(newState, depth + 1, maxDepth, visited, path)) {
            path.push_back(currentState);
            return true;
        }
    }

    return false;
}

bool DepthLimitedSearch() {
    State initialState(8, 0, 0);
    int maxDepth = 10; //Informar a profundidade maxima se necessario
    unordered_set<State> visited;
    vector<State> path;

    if (depthLimitedSearch(initialState, 0, maxDepth, visited, path)) {
        cout << "Solucao encontrada:\n";
        printPath(path);
        return true;
    } else {
        cout << "Solucao nao encontrada com o limite de profundidade.\n";
        return false;
    }
}

int main() {
    DepthLimitedSearch();
    return 0;
}
