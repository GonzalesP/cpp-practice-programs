#include <vector>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
};

class Solution {
public:
  void calculateLevelSums(TreeNode* root, int level, std::vector<long long>& sums) {
    if (sums.size() < level + 1) {
      sums.push_back(root->val);
    } else {
      sums.at(level) += root->val;
    }

    if (root->left != nullptr) {
      calculateLevelSums(root->left, level + 1, sums);
    }
    if (root->right != nullptr) {
      calculateLevelSums(root->right, level + 1, sums);
    }
  }

  long long kthLargestLevelSum(TreeNode* root, int k) {
    std::vector<long long> levelSums; // level n, sum of level n
    calculateLevelSums(root, 0, levelSums);
    if (levelSums.size() < k) {
      return -1;
    }

    // sort vector, then return kth largest element (would be better if it
    // was sorted in descending order)
    std::sort(levelSums.begin(), levelSums.end());
    return levelSums.at(levelSums.size() - k);
  }
};

// NOTE: IF FUNCTION TYPE IS LONG LONG, THEN EXPECT SUM TO POSSIBLY NEED ALL THAT SPACE
// RUNTIME ERROR OCCURS WHEN TRYING TO FIT TOO LARGE OF A NUMBER INTO INT INSTEAD OF LONG LONG