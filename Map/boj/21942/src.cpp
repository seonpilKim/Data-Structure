#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>
#include <cctype>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N, rental_minutes, fine;
	string period;
	vector<int> days_of_month = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	cin >> N >> period >> fine;
	rental_minutes = stoi(period.substr(0, 3)) * 1440 + stoi(period.substr(4, 2)) * 60 + stoi(period.substr(7, 2));

	map<pair<string, string>, pair<string, string>> rentals;
	map<string, long long> fines;

	while (N--) {
		string yyMMdd, hhmm, part, name;
		cin >> yyMMdd >> hhmm >> part >> name;

		if (rentals.find({name, part}) == rentals.end()) 
			rentals[{name, part}] = {yyMMdd, hhmm};
		else {
			long long cur_minutes = 0, prev_minutes = 0, dist_minutes;
			auto [rental_yyMMdd, rental_hhmm] = rentals[{name, part}];

			cur_minutes += (days_of_month[stoi(yyMMdd.substr(5, 2))] + stoi(yyMMdd.substr(8, 2))) * 1440;
			cur_minutes += stoi(hhmm.substr(0, 2)) * 60;
			cur_minutes += stoi(hhmm.substr(3, 2));

			prev_minutes += (days_of_month[stoi(rental_yyMMdd.substr(5, 2))] + stoi(rental_yyMMdd.substr(8, 2))) * 1440;
			prev_minutes += stoi(rental_hhmm.substr(0, 2)) * 60;
			prev_minutes += stoi(rental_hhmm.substr(3, 2));
			
			dist_minutes = cur_minutes - prev_minutes;
			if (dist_minutes > rental_minutes)
				fines[name] += (dist_minutes - rental_minutes) * fine;
			rentals.erase({name, part});
		}
	}

	if (fines.empty())
		cout << -1;
	else {
		auto iter = fines.begin();
		while (iter != fines.end()) {
			cout << iter->first << ' ' << iter->second << '\n';
			++iter;
		}
	}
	
	return 0;
}