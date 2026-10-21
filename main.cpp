#include <iostream>
#include <sstream>
using namespace std;

static string get_store(const string& key, unordered_map<string, string> &store) {
  if (!store.contains(key)) {
    return "NA";
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
    return;
  }
  store.erase(key);
  cout << "OK" << endl;
}

int main() {
  cout << "Hello world!" << endl;

  unordered_map<string, string> store;
  while (true){
    string query;
    vector<string> queryArgs;
    cout << "redis-cli> ";
    getline(cin, query);
    stringstream queryStream(query);
    while (getline(queryStream, query,' ')) {
      queryArgs.push_back(query);
    }

    if (queryArgs.size()>3) {
      cout << "Invalid query" << endl;
      continue;
    }

    if (queryArgs.size()>2 && queryArgs[0][0] != 'S') {
      cout << "Invalid query" << endl;
      continue;
    }

    if (queryArgs.size() == 1 &&
      (queryArgs[0] == "exit" || queryArgs[0] == "EXIT")) {
      exit(0);
    }

    switch (queryArgs[0][0]) {
      case 'S': set_store(queryArgs[1], queryArgs[2], store);
        break;
      case 'D': del_store(queryArgs[1], store);
        break;
       case 'G': cout<< get_store(queryArgs[1], store) << endl;
        break;
      default: cout << "Invalid query" << endl;
        break;
    }

  }


  return 0;
}