// 容器适配器
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>

int main(void) {
    std::queue<int> q;
    std::priority_queue<int> pq;
    std::stack<int> st;

    // 9.6
    // 9.52
    std::string expr;
    std::cout << "请输入括号化的表达式：";
    std::getline(std::cin, expr);

    std::stack<char> bracketStack;

    for (char c : expr) {
        if (c == '(') {
            bracketStack.push(c);  // 左括号入栈
        } else if (c == ')') {
            // 弹出栈中元素，直到找到对应的左括号
            while (!bracketStack.empty() && bracketStack.top() != '(') {
                bracketStack.pop();
            }
            if (!bracketStack.empty() && bracketStack.top() == '(') {
                bracketStack.pop();  // 弹出左括号
                bracketStack.push('#');  // 压入标记，表示子表达式处理完毕
            }
        }
        // 操作数、运算符等其他字符可忽略，此处仅处理括号逻辑
    }

    // 输出栈的最终状态，验证处理结果
    std::cout << "处理后的栈内容：";
    while (!bracketStack.empty()) {
        std::cout << bracketStack.top() << " ";
        bracketStack.pop();
    }
    std::cout << std::endl;

    return 0;
}