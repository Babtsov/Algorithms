//
//  Project1
//
//  Created by Ben on 3/5/16.
//  Copyright © 2016 Ben. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

// ---------------------- Utility functions ----------------------------------------
inline bool is_op(string operation){
    static set<string> ops ={"+", "-", "*","/","^"};
    return ops.count(operation) > 0;
}
inline int compare_precedence(string lhs,string rhs) {
    static unordered_map<string,int> precedence = {{"+",0},{"-",0},{"*",1},{"/",1},{"^",2}};
    return precedence[lhs] - precedence[rhs];
}
inline bool is_parenth(string token) {
    return (token == "(" || token == ")");
}
// ---------------------- Reverse Polish Notation & Shunting Yard functions ---------
vector<string> conv_rpn(vector<string> tokens) {
    vector<string> rpn_tokens;
    stack<string> opStack;
    for (string token : tokens) {
        if (is_op(token)) {
            string o1 = token;
            while (!opStack.empty() && !is_parenth(opStack.top())) {
                string o2 = opStack.top();
                if (o1 != "^" && compare_precedence(o1, o2) <= 0) {
                    rpn_tokens.push_back(o2);
                    opStack.pop();
                }
                else {
                    break;
                }
            }
            opStack.push(o1);
        } else if ( token == "(") {
            opStack.push(token);
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                rpn_tokens.push_back(opStack.top());
                opStack.pop();
            }
            if (opStack.empty() || opStack.top() != "(") {
                throw runtime_error("Parenthesis-Mismatch");
            }
            opStack.pop();
        } else {
            rpn_tokens.push_back(token);
        }
    }
    while (!opStack.empty()) {
        if ( is_parenth(opStack.top()) ) {
            throw runtime_error("Parenthesis-Mismatch");
        }
        rpn_tokens.push_back(opStack.top());
        opStack.pop();
    }
    return rpn_tokens;
}
double eval_rpn(unordered_map<string,double>& vars,const vector<string> rpn_tokens) {
    stack<double> calc_stack;
    for (string token : rpn_tokens) {
        if (is_op(token)) {
            auto right = calc_stack.top();
            calc_stack.pop();
            auto left = calc_stack.top();
            calc_stack.pop();
            double result;
            if (token == "*") {
                result = left * right;
            } else if (token == "+") {
                result = left + right;
            } else if (token == "-") {
                result = left - right;
            } else if (token == "^") {
                result = pow(left, right);
            } else { // division
                if (abs(right) < 1e-10) {
                    throw runtime_error("Division-By-Zero");
                }
                result = left / right;
            }
            calc_stack.push(( abs(result) < 1e-10)? 0: result);
        } else if (isalpha(token[0])) { // if the first char is alphabetic, then we have a var!
            try {
                calc_stack.push(vars.at(token));
            } catch (const out_of_range& e) {
                throw runtime_error("Undeclared-Variable");
            }
        } else { // must be a float
            try {
                calc_stack.push(stod(token));
            } catch (const invalid_argument& e) {
               throw runtime_error("Invalid-Number");
            }
        }
    }
    return calc_stack.top();
}
// ---------------------- Parsing and tokenizing functions -------------------------
double compute_expr(const string& str, int& itr, unordered_map<string,double>& vars) {
    int end = static_cast<int>(str.length());
    vector<string> tokens;
    while (itr < end) {
        if (str[itr] == ' ') { // ignore blank spaces when evaluating expression
            itr++;
            continue;
        }
        string s = string(1,str[itr]);
        if (is_parenth(s) || is_op(s)) {
            tokens.push_back(s);
            itr++;
        } else if (isdigit(str[itr])) { // parse an integer or a float
            string num;
            while (itr < end && isdigit(str[itr])) {
                num += str[itr];
                itr++;
            }
            if (itr < end && str[itr] == '.') {
                num += '.';
                itr++;
                while (itr < end && isdigit(str[itr])) {
                    num += str[itr];
                    itr++;
                }
            }
            tokens.push_back(num);
        } else if (isalpha(str[itr])) { // parse a variable name
            string var_name;
            while (itr < end && isalnum(str[itr])) {
                var_name += str[itr];
                itr++;
            }
            tokens.push_back(var_name);
        } else {
            throw runtime_error("Invalid-Character-Detected");
        }
    }
    vector<string> rpn_tokens = conv_rpn(tokens);
    return eval_rpn(vars, rpn_tokens);
}
static inline void skip_space(const string& str, int& itr) {
    int end = static_cast<int>(str.length());
    while (itr < end && str[itr] == ' ') {
        itr++;
    }
}
static inline bool match_str(string needle, const string& haystack,int pos) {
    for (char c : needle) {
        if (pos >= haystack.length() || haystack[pos] != c) { // failed to match
            return false;
        }
        pos++;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    unordered_map<string, double> vars_table;
    while (true) {
        string raw_input;
        getline(cin,raw_input);
        int itr = 0;
        int end = static_cast<int>(raw_input.length());
        skip_space(raw_input,itr);
        if (itr == end) { // empty line. Simply skip it.
            continue;
        }
        try {
            if (match_str("quit",raw_input,itr) && itr + 4 >= end) {
                exit(EXIT_SUCCESS);
            } else if (match_str("let ",raw_input,itr)) {
                itr += 4; // advance itr past the "let "
                string var_name;
                skip_space(raw_input,itr);
                if (itr >= end || !isalpha(raw_input[itr])) {
                    throw runtime_error("Invalid-let-statement");
                }
                while (itr < end && isalnum(raw_input[itr])) {
                    var_name += raw_input[itr];
                    itr++;
                }
                skip_space(raw_input,itr);
                if (itr >= end || !(raw_input[itr] == '=')) {
                    throw runtime_error("Invalid-let-statement");
                }
                itr++; // skip '='
                skip_space(raw_input,itr);
                if (itr >= end) {
                    throw runtime_error("Invalid-let-statement");
                }
                try {
                    vars_table.at(var_name) = compute_expr(raw_input, itr, vars_table);
                } catch (const out_of_range& e) {
                    throw runtime_error("Undeclared-Variable");
                }
            } else { // parse expression
                cout << compute_expr(raw_input, itr, vars_table) << endl;
            }
        } catch (runtime_error& re) {
            cout << re.what() << endl;
        }
    }
    return 0;
}