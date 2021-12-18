/* 
 *	timePersion:记录对应times的票数最高者
 *	alltimes:times的拷贝
 *	timePersion:每个人获得的票数
 *	二分查找：查找<=t的最后一个数
 */
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int num = persons.size();
        timePersion.assign(num, 0);
        for (int i = 0; i < num; i++) {
            persionVote[persons[i]]++;
            alltimes.push_back(times[i]);
            if (i == 0) {
                timePersion[i] = persons[i];
            } else {
                timePersion[i] = persionVote[persons[i]] >= persionVote[timePersion[i - 1]] ? persons[i] : timePersion[i - 1];
            }
        }
    }
    
    int q(int t) {
        int left = 0;
        int right = alltimes.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (alltimes[mid] <= t) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return timePersion[right];
    }
    vector<int> alltimes;
    vector<int> timePersion;
    unordered_map<int, int> persionVote;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */