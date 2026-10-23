#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

static string get_store(const string& key, unordered_map<string, string> &store) {
  if (!store.contains(key)) {
    return "(nil)";
  }
  return store.at(key);
}

static void set_store(const string& key, const string& value,
                         unordered_map<string, string> &store) {
  if (!store.contains(key)) {
    store.insert({key, value});
    cout << "OK" << endl;
    return;
  }
  store.at(key) = value;
  cout << "OK" << endl;
}

static void del_store(const string& key, unordered_map<string, string> &store) {
  if (!store.contains(key)) {
    cout<<"0"<<endl;
    return;
  }
  store.erase(key);
  cout << "1" << endl;
}

int main() {
  cout << "Hello world!" << endl;

  unordered_map<string, string> store;
  while (true){
    string query;
    vector<string> queryArgs;
    cout << "redis-cli> ";
    getline(cin, query);
    if (!getline(cin, query)) {
      break;
    }
    stringstream queryStream(query);
    string queryArg;
    while (queryStream >> queryArg) {
      queryArgs.push_back(queryArg);
    }

    if (queryArgs.empty()) {
      continue;
    }

    if (queryArgs.size()>3) {
      cout << "Invalid query" << endl;
      continue;
    }

     if (queryArgs.size()<2 && !queryArgs.empty()) {
      if (queryArgs[0] == "exit" || queryArgs[0] == "EXIT") {
        cout << "OK" << endl;
        exit(0);
      }
      cout << "invalid query" << endl;
    }
     else if (queryArgs[0] == "GET") {
      if (queryArgs.size() < 2 || queryArgs.size() >2) {
        cout << "Invalid query" << endl;
        continue;
      }
      cout << get_store(queryArgs[1], store) << endl;
    }else if (queryArgs[0] == "SET") {
      if (queryArgs.size() < 3 || queryArgs.size() > 3) {
        cout << "Invalid query" << endl;
        continue;
      }
      set_store(queryArgs[1], queryArgs[2], store);
    }else if (queryArgs[0] == "DEL") {
      if (queryArgs.size() < 2 || queryArgs.size() >2) {
        cout << "Invalid query" << endl;
        continue;
      }
      del_store(queryArgs[1], store);
    } else {
      cout << "Invalid query" << endl;
    }
  }


  return 0;
}