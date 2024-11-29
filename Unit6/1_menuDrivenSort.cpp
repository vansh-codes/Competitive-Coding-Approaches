#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void quickSort(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);
void mergeSort(vector<int> &arr, int left, int right);
void merge(vector<int> &arr, int left, int mid, int right);

void addElements(vector<int> &arr)
{
    arr.clear();
    int n, element;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> element;
        arr.push_back(element);
    }
}

void displayElements(const vector<int> &arr)
{
    cout << "Array elements: ";
    for (const int &element : arr)
    {
        cout << element << " ";
    }
    cout << endl;
}

void quickSortMenu(vector<int> &arr)
{
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Quick Sort completed in " << duration.count() << " microseconds.\n";
}

void mergeSortMenu(vector<int> &arr)
{
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Merge Sort completed in " << duration.count() << " microseconds.\n";
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low;     // starting index of left subarray
    int j = mid + 1; // starting index of right subarray
    while (i <= mid && j <= high){
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high){
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

int main()
{
    vector<int> arr;
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Add elements into array\n";
        cout << "2. Quick Sort and print time complexity\n";
        cout << "3. Merge Sort and print time complexity\n";
        cout << "4. Display elements\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addElements(arr);
            break;
        case 2:
            quickSortMenu(arr);
            break;
        case 3:
            mergeSortMenu(arr);
            break;
        case 4:
            displayElements(arr);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}

/* #include <gtk/gtk.h>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

vector<int> arr;

// Function to add elements to the array
static void add_elements(GtkWidget *widget, gpointer entry)
{
    const gchar *entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
    stringstream ss(entry_text);
    int number;
    while (ss >> number)
    {
        arr.push_back(number);
        if (ss.peek() == ',')
            ss.ignore();
    }
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

// Function to perform Quick Sort
static void quick_sort(GtkWidget *widget, gpointer label)
{
    auto start = high_resolution_clock::now();
    sort(arr.begin(), arr.end()); // Replace with actual quickSort if implemented
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    stringstream ss;
    ss << "Quick Sort completed in " << duration.count() << " microseconds.";
    gtk_label_set_text(GTK_LABEL(label), ss.str().c_str());
}

// Function to perform Merge Sort
static void merge_sort(GtkWidget *widget, gpointer label)
{
    auto start = high_resolution_clock::now();
    sort(arr.begin(), arr.end()); // Replace with actual mergeSort if implemented
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    stringstream ss;
    ss << "Merge Sort completed in " << duration.count() << " microseconds.";
    gtk_label_set_text(GTK_LABEL(label), ss.str().c_str());
}

// Function to display the array elements
static void display_elements(GtkWidget *widget, gpointer label)
{
    stringstream ss;
    ss << "Array elements: ";
    for (const int &element : arr)
    {
        ss << element << " ";
    }
    gtk_label_set_text(GTK_LABEL(label), ss.str().c_str());
}

// Function to exit the application
static void exit_application(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

// Function to create a menu item and connect it to a callback
GtkWidget *create_menu_item(const char *label, GCallback callback, gpointer data)
{
    GtkWidget *menu_item = gtk_menu_item_new_with_label(label);
    g_signal_connect(menu_item, "activate", callback, data);
    return menu_item;
}

// Activate function to set up the GUI
static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *menu_bar;
    GtkWidget *menu;
    GtkWidget *menu_item;
    GtkWidget *entry;
    GtkWidget *label;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Sorting Application");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Menu bar
    menu_bar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, FALSE, 0);

    // Menu
    menu = gtk_menu_new();

    // Entry for array input
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);

    // Label to display messages
    label = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);

    // Menu items
    menu_item = create_menu_item("Add Elements", G_CALLBACK(add_elements), entry);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    menu_item = create_menu_item("Quick Sort", G_CALLBACK(quick_sort), label);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    menu_item = create_menu_item("Merge Sort", G_CALLBACK(merge_sort), label);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    menu_item = create_menu_item("Display Elements", G_CALLBACK(display_elements), label);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    menu_item = create_menu_item("Exit", G_CALLBACK(exit_application), NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);

    GtkWidget *menu_item_root = gtk_menu_item_new_with_label("Menu");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item_root), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item_root);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.sortingapp", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
 */