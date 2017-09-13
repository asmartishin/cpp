#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <set>

inline long long int get_id(const long long int type, const long long int index, const long long int A) {
    return (type - 1) * A + index - 1;
}

void add_to_chozen(
    std::set<long long int>& first_chozen,
    std::set<long long int>& second_chozen,
    const long long int id,
    const long long int A
) {
    if (id < A) {
        first_chozen.insert(id + 1);
    } else {
        second_chozen.insert(id + 1 - A);
    }
}


void do_one_test() {
    long long int N, A, B;
    std::cin >> N >> A >> B;

    std::set<long long int> first_chozen;
    std::set<long long int> second_chozen;
    std::vector<long long int> score(A + B, 0);
    std::map<long long int, std::unordered_set<long long int> > person_by_score;
    std::vector<std::vector<long long int > > accepted_by_rejected(A + B);


    for (size_t i = 0; i < N; ++i) {
        long long int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        ++score[get_id(a, b, A)];
        --score[get_id(c, d, A)];
        accepted_by_rejected[get_id(c, d, A)].push_back(get_id(a, b, A));
    }

    for (size_t i = 0; i < A + B; ++i) {
        if (score[i] > 0) {
            person_by_score[score[i]].insert(i);
        }
    }

    while (person_by_score.size() > 0) {
        auto it = person_by_score.end();
        --it;
        if (it->second.size() > 0) {
            auto person = *(it->second.begin());
            add_to_chozen(first_chozen, second_chozen, person, A);
            for (size_t i = 0; i < accepted_by_rejected[person].size(); ++i) {
                auto accepted_person = accepted_by_rejected[person][i];

                person_by_score[score[accepted_person]].erase(accepted_person);
                --score[accepted_person];
                if (score[accepted_person] > 0) {
                    person_by_score[score[accepted_person]].insert(accepted_person);
                }
            }
            it->second.erase(person);
        } else {
            person_by_score.erase(it->first);
        }
    }

    std::cout << first_chozen.size() << std::endl;
    for (auto it = first_chozen.begin() ;it != first_chozen.end(); ++it) {
        std::cout << *it;
        auto it2 = it;
        ++it2;
        if (it2 != first_chozen.end()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    std::cout << second_chozen.size() << std::endl;
    for (auto it = second_chozen.begin() ;it != second_chozen.end(); ++it) {
        std::cout << *it;
        auto it2 = it;
        ++it2;
        if (it2 != second_chozen.end()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    long long int T;
    std::cin >> T;
    for (size_t i = 0; i < T; ++i) {
        do_one_test();
    }
    return 0;
}
