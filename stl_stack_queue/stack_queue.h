#pragma once
#include<deque>
  
namespace mystack_queue
{
    //最小栈
    class MinStack {
    public:
        MinStack() {

        }

        void push(int val) {
            if (st.empty() || Minst.top() >= val)
            {
                Minst.push(val);
            }
            st.push(val);

        }

        void pop() {
            if (st.top() == Minst.top())
            {
                Minst.pop();
            }

            st.pop();
        }

        int top() {
            return st.top();
        }

        int getMin() {
            return Minst.top();
        }

        stack<int> st;
        stack<int> Minst;
    };

    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */


     
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param pushV int整型vector
         * @param popV int整型vector
         * @return bool布尔型
         */
         //栈的压入弹出序列
        bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
            // write code here

            stack<int> st;
            int pushi = 0, popi = 0;
            while (pushi < pushV.size())
            {
                st.push(pushV[pushi]);
                while (!st.empty() && st.top() == popV[popi])
                {
                    st.pop();
                    popi++;
                }
                pushi++;
            }

            return st.empty();
        }

        //逆波兰表达式求值
        int evalRPN(vector<string>& tokens) {
            stack<int> st;

            for (int i = 0; i < tokens.size(); i++)
            {
                int result = 0;
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
                {
                    int right = st.top();
                    st.pop();
                    int left = st.top();
                    st.pop();
                    if(tokens[i]=="+")result = left + right;
                    else if (tokens[i] == "-")result = left - right;
                    else if (tokens[i] == "*")result = left * right;
                    else if (tokens[i] == "/")result = left / right;
                    st.push(result);
                }
                else
                {
                    st.push(stoi(tokens[i]));
                }
            }
            return st.top();
        }
    };


        //用两个栈实现队列
        template<class T>
        class MyQueue {
        private:
            std::stack<T> st1;//用来实现从队尾入队列
            std::stack<T> st2;//用来实现从队头出队列
        public:
            MyQueue() {

            }

            void push(T x) {
                st1.push(x);
            }

            T pop() {
                if (st2.empty())
                {
                    while (!st1.empty())
                    {
                        st2.push(st1.top());
                        st1.pop();
                    }
                }
                T top = st2.top();
                st2.pop();
                return top;
            }

            T peek() {
                if (st2.empty())
                {
                    while (!st1.empty())
                    {
                        st2.push(st1.top());
                        st1.pop();
                    }
                }
                return st2.top();
            }

            bool empty() {
                return st1.empty() && st2.empty();
            }
        };

}


namespace mystack
{
    template<class T, class Container=deque<T>>
    class stack
    {
    public:

        void push(const T& x)
        {
            _con.push_back(x);
        }

        void pop()
        {
            _con.pop_back();
        }

        const T& top()
        {
            return _con.back();
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

    private:
        Container _con;
    };
}


namespace myqueue
{
    template<class T,class Container=deque<T>>
    class queue
    {
    public:
        void push(const T& x)
        { 
            _con.push_back(x);
        }

        void pop()
        {
            _con.pop_front();
        }

        const T& front()
        {
            return _con.front();
        }

        const T& back()
        {
            return _con.back();
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

    private:
        Container _con;
    };
}
