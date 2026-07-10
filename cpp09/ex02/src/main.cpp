#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

bool compare(const std::string& a, const std::string& b) {
    return (a + b) > (b + a);
}

int main() {
    int len;
    std::cin >> len;

    std::vector<std::string> nums;

    for (int i = 0; i < len; i++) {
        int item;
        std::cin >> item;

        std::ostringstream oss;
        oss << item;
        nums.push_back(oss.str());
    }

    std::sort(nums.begin(), nums.end(), compare);

    std::string result;
    for (size_t i = 0; i < nums.size(); i++) {
        result += nums[i];
    }

    std::cout << result << std::endl;
    return 0;
}