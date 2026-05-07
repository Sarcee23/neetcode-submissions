#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> courseToPrereqs;  // Maps each course to its list of prerequisites
        for (const auto& prereq : prerequisites) {
            courseToPrereqs[prereq[0]].push_back(prereq[1]);
        }

        vector<int> order;  // Stores the resulting valid order of courses
        unordered_set<int> completed;  // Courses that have been fully processed
        unordered_set<int> processing;  // Courses currently being processed to detect cycles

        for (int course = 0; course < numCourses; course++) {
            if (!performDFS(course, courseToPrereqs, completed, processing, order)) {
                return {};  // Return an empty vector if a cycle is detected
            }
        }

        return order;  // Return the valid course order
    }

private:
    bool performDFS(int course, const unordered_map<int, vector<int>>& courseToPrereqs,
                    unordered_set<int>& completed, unordered_set<int>& processing, vector<int>& order) {
        if (processing.count(course)) {
            return false;  // Cycle detected
        }
        if (completed.count(course)) {
            return true;  // Already fully processed
        }

        processing.insert(course);  // Mark the course as currently being processed
        if (courseToPrereqs.count(course)) {
            for (int prereq : courseToPrereqs.at(course)) {
                if (!performDFS(prereq, courseToPrereqs, completed, processing, order)) {
                    return false;  // If any prerequisite cannot be processed, return false
                }
            }
        }
        processing.erase(course);  // Mark the course as fully processed
        completed.insert(course);  // Mark the course as fully processed
        order.push_back(course);  // Add the course to the output order
        return true;
    }
};
