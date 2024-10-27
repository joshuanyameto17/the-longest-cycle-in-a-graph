#include <iostream>
#include <vector>
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int numNodes = edges.size();
        vector<bool> visited(numNodes, false);
        int longestCycleLength = -1;  // Initialize with -1 to represent no cycle found.

        // Loop through each node to find the longest cycle, if any.
        for (int start = 0; start < numNodes; ++start) {
            // Skip if the node has been visited.
            if (visited[start]) {
                continue;
            }

            // Use two pointers to traverse the graph and record the cycle.
            int current = start;
            vector<int> cycleNodes;

            // Explore the graph to find a cycle.
            for (; current != -1 && !visited[current]; current = edges[current]) {
                visited[current] = true; // Mark the node as visited.
                cycleNodes.push_back(current); // Add to cycle list.
            }

            // If we did not encounter a cycle, continue with the next node.
            if (current == -1) {
                continue;
            }

            // Check the recorded nodes to determine the cycle's length.
            for (int idx = 0; idx < cycleNodes.size(); ++idx) {
                // Find the start index of the cycle within the cycle list.
                if (cycleNodes[idx] == current) {
                    // Calculate and store the maximum cycle length found so far.
                    longestCycleLength = max(longestCycleLength, static_cast<int>(cycleNodes.size() - idx));
                    break; // Break as we found the cycle start point.
                }
            }
        }
        return longestCycleLength; // Return the longest cycle length found.
    }
};
