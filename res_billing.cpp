#include <bits/stdc++.h>
using namespace std;

class Restaurant {
   public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_tax;
};

/**
 * @brief the function takes all food input;
 * @param r -> the restaurant object
 * @return void;
 */
void items_initial_input(Restaurant &r, int n) {
    cout << "Enter all food data: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> r.food_item_codes[i];
        string s;
        scanf(" ");
        getline(cin, r.food_item_names[i]);
        cin >> r.food_item_prices[i];
    }
}

/**
 * @brief the function prints all food in the store;
 * @param r -> the restaurant object;
 * @return void;
 */
void all_items_show(Restaurant &r, int n) {
    cout << "                  Make Bill                " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Item Code\t\tItem Name\t\tItem Price\n";
    for (int i = 0; i < n; i++) {
        cout << r.food_item_codes[i] << "\t\t" << r.food_item_names[i] << "\t\t" << r.food_item_prices[i] << endl;
    }
}

/**
 * @brief the function takes user order for corrsponding table;
 * @param r -> the restaurant object;
 * @return void;
 */

void user_order(Restaurant &res, int n) {
    cout << "Enter the table number: ";
    int table;
    cin >> table;
    cout << "Enter number of items: ";
    int num_of_items;
    cin >> num_of_items;
    int item_codes[num_of_items];
    int item_quantities[num_of_items];
    for (int i = 0; i < n; i++) {
    fail:
        cout << "Enter item " << i + 1 << " code: ";
        int item_code;
        cin >> item_code;
        for (int k = 0; k < n; k++) {
            if (item_code == res.food_item_codes[k]) {
                goto success;
            }
        }
        cout << "Item code not found" << endl;
        goto fail;
    success:
        cout << "Enter item " << i + 1 << " quantity: ";
        int item_quantity;
        cin >> item_quantity;
        item_codes[i] = item_code;
        item_quantities[i] = item_quantity;
    }
    cout << res << endl;
    table_order(res, n, table, num_of_items, item_codes, item_quantities);
}

/**
 * @brief the function prints table order with price;
 * @param r -> the restaurant object;
 * @return void;
 */
void table_order(Restaurant &r, int n, int table, int num_of_items, int *item_codes, int *item_quantities) {
    cout << "                       Bill Summary                    " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Table Number: " << table << endl;
    cout << "Item Code\t\tItem Name\t\tItem Price\t\tQuantity\t\tTotal Price\n";
    double total_price = 0;
    for (int i = 0; i < num_of_items; i++) {
        for (int j = 0; j < n; j++) {
            if (item_codes[i] == r.food_item_codes[j]) {
                total_price += r.food_item_prices[j] * item_quantities[i];
                cout << r.food_item_codes[j] << "\t\t" << r.food_item_names[j] << "\t\t" << r.food_item_prices[j] << "\t\t" << item_quantities[i] << "\t\t" << r.food_item_prices[j] * item_quantities[i] << endl;
            }
        }
    }
    double Tax = total_price * 0.05;
    double total_bill = total_price + Tax;
    cout << "----------------------------------------------------" << endl;
    cout << "Total Price:                                                               " << total_price << endl;
}

int main() {
    cout << "Enter the number of data to be entered: ";
    int n;
    cin >> n;
    Restaurant restaurant;
    items_initial_input(restaurant, n);
    all_items_show(restaurant, n);
    user_order(restaurant, n);
    return 0;
}