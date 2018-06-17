#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>

using namespace std;

enum EState {
    Inactive  = 1,
    Stable = 2,
    Unstable = 3,
};

array<pair<int, int>, 4> NEIGHBOURS{{{0, -1}, {-1, 0}, {0, 1}, {1, 0}}};


struct TCell {
    int Changes;
    EState State;
    EState NewState;
    pair<int, int> Coordinates;

    TCell(int defaultState, int row, int column)
        : Changes(0)
        , NewState(Unstable)
        , Coordinates{row, column}
    {
        if (defaultState == 1)
            State = Inactive;
        else if (defaultState == 2)
            State = Stable;
        else
            State = Unstable;
    }

    void UpdateState() {
        if (NewState != State) {
            State = NewState;
            ++Changes;
        }
    }
};


void solve(vector<vector<TCell> > &field, int n, int m) {
    for (auto &row: field) {
        for (auto &cell: row) {
            int stableCount = 0;
            int activeCount = 0;
            for (auto const &neighbourCoordinates: NEIGHBOURS) {
                int neighbourRow = cell.Coordinates.first + neighbourCoordinates.first;
                int neighbourColumn = cell.Coordinates.second + neighbourCoordinates.second;

                if ((neighbourRow < n) && (neighbourRow >= 0) &&
                    (neighbourColumn < m) && (neighbourColumn >= 0))
                {
                    auto &neighbour = field[neighbourRow][neighbourColumn];
                    if (neighbour.State == Stable) {
                        ++stableCount;
                        ++activeCount;
                    } else if (neighbour.State == Unstable)
                        ++activeCount;
                }
            }
            if (stableCount >= 2)
                cell.NewState = Stable;
            else if (activeCount >= 1)
                cell.NewState = Unstable;
            else
                cell.NewState = Inactive;
        }
    }

    for (auto &row: field) {
        for (auto &cell: row) {
            cell.UpdateState();
        }
    }
}


int main() {
    int n, m, k, s;

    cin >> n >> m >> k;

    vector<vector<TCell> > field(n, vector<TCell>());

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> s;
            field[i].push_back(TCell(s, i, j));
        }
    }

    for (size_t i = 0; i < k; ++i)
        solve(field, n, m);

    for (auto const &row: field) {
        for (auto const &cell: row) {
            cout << cell.Changes << ' ';
        }
        cout << endl;
    }

    return 0;
}
