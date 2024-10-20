#include <iostream>
#include <vector>

class Solution {
public:
    int expReader = 0;  // read expression, start at index 0

    bool parseNotExpr(std::string expression) {
        ++expReader;
        ++expReader;
        bool innerExpression = parseBoolExpr(expression);
        ++expReader;  // you forgot that NOT has TWO parantheses: !(...)
        return !innerExpression;  // which is a total of THREE char skips!!
    }

    bool parseAndExpr(std::string expression) {
        ++expReader;
        ++expReader;

        std::vector<bool> exprBoolValues;  // results of all inner expressions
        bool moreExpressions = true;

        while(moreExpressions) {
            bool subExpr = parseBoolExpr(expression);
            exprBoolValues.push_back(subExpr);

            // , -> evaluate next sub expression
            if (expression[expReader] == ',') {
                ++expReader;
            }
            // ) -> no more inner expressions
            else if (expression[expReader] == ')') {
                moreExpressions = false;
            }
        }

        // return exprBoolValues.count(false) == 0;  -lol
        ++expReader;
        for (int expr = 0; expr < exprBoolValues.size(); ++expr) {
            if (exprBoolValues.at(expr) == false) {
                return false;
            }
        }
        return true;
    }

    bool parseOrExpr(std::string expression) {
        ++expReader;
        ++expReader;

        std::vector<bool> exprBoolValues;  // results of all inner expressions
        bool moreExpressions = true;

        while(moreExpressions) {
            bool subExpr = parseBoolExpr(expression);
            exprBoolValues.push_back(subExpr);

            // , -> evaluate next sub expression
            if (expression[expReader] == ',') {
                ++expReader;
            }
            // ) -> no more inner expressions
            else if (expression[expReader] == ')') {
                moreExpressions = false;
            }
        }

        // return exprBoolValues.count(true) >= 1;  -lol
        ++expReader;
        for (int expr = 0; expr < exprBoolValues.size(); ++expr) {
            if (exprBoolValues.at(expr) == true) {
                return true;
            }
        }
        return false;
    }

    bool parseBoolExpr(std::string expression) {
        if (expression[expReader] == 't') {
            ++expReader;
            return true;
        }
        else if (expression[expReader] == 'f') {
            ++expReader;
            return false;
        }
        // !(...)
        else if (expression[expReader] == '!') {
            return parseNotExpr(expression);
        }
        // &(...)
        else if (expression[expReader] == '&') {
            return parseAndExpr(expression);
        }
        // |(...)
        return parseOrExpr(expression);
    }
};

// I think a much more efficient processor would use a ASM TABLE/STACK

int main() {
    Solution s;
    // 1 - true, 0 - false
    std::cout << s.parseBoolExpr("&(|(f))") << std::endl;
    s.expReader = 0;  // reset reader to start at beginning of next expression

    std::cout << s.parseBoolExpr("|(f,f,f,t)") << std::endl;
    s.expReader = 0;

    std::cout << s.parseBoolExpr("!(&(f,t))") << std::endl;
    s.expReader = 0;
    return 0;
}

// I think a much more efficient processor would use a ASM TABLE/STACK