#include <iostream>
using namespace std;

static string get_from_store(const string& key, unordered_map<string, string> &store) {
  if (!store.contains(key)) {
    return "Not found!";
  }
  return store.at(key);
}

static void add_to_store(const string& key, const string& value,
                         unordered_map<string, string> &store) {
  if (!store.contains(key)) {
    store.insert({key, value});
    return;
  }
  cout << "Key already exists with value - " <<
    get_from_store(key, store) << endl;
}

static void update_to_store(const string& key, const string& value,
  unordered_map<string, string> &store) {
  if (!store.contains(key)) {
    cout << "Key does not exists in the DB. Insert first. " << endl;
    return;
  }
  store.at(key) = value;
}

static void remove_from_store(const string& key, unordered_map<string, string> &store) {
  if (!store.contains(key)) {
    cout << "Key not found in the DB." << endl;
    return;
  }
  store.erase(key);
}

int main() {
  cout << "Hello world!" << endl;

  unordered_map<string, string> store;
  string key, value;
  int operation;
  while (true){
    cout<<"Choose the method: 1.GET \n2. CREATE \n3. UPDATE\n4. DELETE\n"<< endl;
    cin >> operation;
    cout << "you have entered " << operation << endl;
    cout << endl;
    switch (operation) {
      case 1:
        cout << "*******GET OPERATION*******" << endl;
        cout << "Enter the key : ";
        cin >> key;
        cout<< get_from_store(key, store) << endl;
        break;
      case 2:
        cout << "*******CREATE OPERATION*******" << endl;
        cout << "Enter the Key : ";
        cin >> key;
        cout << "Enter the value : ";
        cin >> value;
        add_to_store(key, value, store);
        break;
      case 3:
        cout << "*******UPDATE OPERATION*******" << endl;
        cout << "Enter the Key : ";
        cin >> key;
        cout << "Enter the value : ";
        cin >> value;
        update_to_store(key, value, store);
        break;
      case 4:
        cout << "*******DELETE OPERATION*******" << endl;
        cout << "Enter the Key : ";
        cin >> key;
        remove_from_store(key, store);
        break;

      default:
        cout << "Please choose a valid operation." << endl;
        break;
    }
  }


  return 0;
}