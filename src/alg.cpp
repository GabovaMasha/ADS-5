// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char oper) {
    switch (oper) {
        case '(': return 0;
        case ')': return 1;
        case '+': return 2;
        case '-': return 2;
        case '*': return 3;
        case '/': return 3;
        case ' ': return 4;
        default : return 5;
    }
}

int calcul(char oper, int a, int b) {
      switch (oper) {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/':
        if ( a != 0)
        return b / a;
        default : return 0;
    }
}

std::string infx2pstfx
  std::string post;
  char razd = ' ';
  TStack <char, 100> t1;
  for (int i = 0; i < inf.size(); i++) {
    if (prioritet(inf[i]) == 5) {
        post.push_back(inf[i]);
        post.push_back(razd);
    }
    else {
    if (prioritet(inf[i]) == 0) {
        t1.push(inf[i]);
    } else if (t.isEmpty()) {
       t1.push(inf[i]); 
    } else if ((prioritet(inf[i]) > prioritet(t.get()))) {
        t1.push(inf[i]);
    } else if (prioritet(inf[i]) == 1) {
        while (prioritet(t.get()) != 0) {
            post.push_back(t.get());
            post.push_back(razd);
            t1.pop();
        }
        t1.pop();
    } else {
        while (!t.isEmpty() && (prioritet(inf[i]) <= prioritet(t.get()))) {
            post.push_back(t.get());
            post.push_back(razd); 
            t1.pop();
        }
        t1.push(inf[i]);
    }   
    }
  }
  while (!t.isEmpty()) {
    post.push_back(t.get());
    post.push_back(razd);
    t1.pop();  
  }
  for (int j = 0; j < post.size(); j++) {
      if (post[post.size()-1] == ' ')
      post.erase(post.size() - 1);
  }
  return post;
}

int eval(std::string pref) {
TStack <int, 100> t2;
int res = 0;
for (int i = 0; i < pref.size(); i ++) {
    if (prioritet(pref[i])) == 5) {
        t2.push(pref[i] - '0');
    }
    else if (prioritet(pref[i]) < 4) {
        int x = t.get();
        t2.pop;
        int y = t.get();
        t2.pop;
        t2.push(calcul(pref[i], x, y));
    }
}
res = t2.get();
return res;
}
