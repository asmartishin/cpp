#include <iostream>
#include <vector>


int main(){
    std::string walkthrough;

    int x;
    int y;
    int len;

    std::cin >> len;
    std::cin >> walkthrough;
    std::cin >> x;
    std::cin >> y;

    std::vector<int> result(4, 0);

    int dy = 0;
    int dx = 0;
    int steps = 0;

    if (x >= 0 && y >= 0) {
	for (std::string::iterator it = walkthrough.begin(); it != walkthrough.end(); ++it) {
            steps++;
	    if (*it == 'R' && dx != x) {
                dx++;
                if (dx == x) {
                    result[2] = steps;
                }
    	    } else if (*it == 'U' && dy != y) {
                dy++;
                if (dy == y) {
                    result[1] = steps;
                }
            }

            if (dx == x && dy == y) {
                break;
            }
	}
    } else if (x >= 0 && y <= 0) {
	for (std::string::iterator it = walkthrough.begin(); it != walkthrough.end(); ++it) {
            steps++;
	    if (*it == 'R' && dx != x) {
                dx++;
                if (dx == x) {
                    result[2] = steps;
                }
    	    } else if (*it == 'D' && dy != y) {
                dy--;
                if (dy == y) {
                    result[3] = steps;
                }
            }

            if (dx == x && dy == y) {
                break;
            }
	}
    } else if (x <= 0 && y <= 0) {
	for (std::string::iterator it = walkthrough.begin(); it != walkthrough.end(); ++it) {
            steps++;
	    if (*it == 'L' && dx != x) {
                dx--;
                if (dx == x) {
                    result[0] = steps;
                }
    	    } else if (*it == 'D' && dy != y) {
                dy--;
                if (dy == y) {
                    result[3] = steps;
                }
            }

            if (dx == x && dy == y) {
                break;
            }
	}
    } else if (x <= 0 && y >= 0) {
	for (std::string::iterator it = walkthrough.begin(); it != walkthrough.end(); ++it) {
            steps += 1;
	    if (*it == 'L' && dx != x) {
                dx -= 1;
                if (dx == x) {
                    result[0] = steps;
                }
    	    } else if (*it == 'U' && dy != y) {
                dy += 1;
                if (dy == y) {
                    result[1] = steps;
                }
            }

            if (dx == x && dy == y) {
                break;
            }
	}
    }

    if (dx != x || dy != y) {
        std::cout << "-1";
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i] << ' ';
        }
    }

    return 0;
}
