#include <bits/stdc++.h>
using namespace std;

int first_come_first_serve(int n, int *arr, int head)
{
    int st = 0;
    int seq[n];
    for (int i = 0; i < n; i++)
    {
        st += abs(arr[i] - head);
        seq[i] = arr[i];
        head = arr[i];
    }
    cout << "the sequence is ";
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl
         << "fcfs -> ";
    return st;
}

int shortest_seek_time_first(int n, int *arr, int head)
{
    bool vis[n];
    int seq[n];
    int st = 0, min_idx, k = 0;
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        min_idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && (min_idx == -1 || abs(head - arr[j]) < abs(head - arr[min_idx])))
            {
                min_idx = j;
            }
        }
        st += abs(head - arr[min_idx]);
        seq[k++] = arr[min_idx];
        head = arr[min_idx];
        vis[min_idx] = true;
    }
    cout << "the sequence is ";
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl
         << "sstf -> ";
    return st;
}

int look(int n, int *arr, int head)
{
    int st = 0, k = 0;
    int seq[n];
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    int i = 0;
    while (i < n && arr[i] < head)
    {
        i++;
    }
    int flag = i;
    while (i < n)
    {
        st += (arr[i] - head);
        seq[k++] = arr[i];
        head = arr[i];
        i++;
    }
    i = flag - 1;
    while (i >= 0)
    {
        st += head - arr[i];
        seq[k++] = arr[i];
        head = arr[i];
        i--;
    }
    cout << "the sequence is ";
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl
         << "look -> ";
    return st;
}

int c_look(int n, int *arr, int head)
{
    int st = 0, k = 0;
    int seq[n];
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    int i = 0;
    while (i < n && arr[i] < head)
    {
        i++;
    }
    int flag = i;
    while (i < n)
    {
        st += (arr[i] - head);
        seq[k++] = arr[i];
        head = arr[i];
        i++;
    }
    i = 0;
    while (i < flag)
    {
        st += abs(arr[i] - head);
        seq[k++] = arr[i];
        head = arr[i];
        i++;
    }
    cout << "the sequence is ";
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl
         << "c-look -> ";
    return st;
}

int main()
{
    int n, head, choice = 0, ans;
    cout << "enter the number of disc requests" << endl;
    cin >> n;
    int arr[n] = {176, 79, 34, 60, 92, 11, 41, 114};
    cout << "enter the disc request sequence" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the initial head position" << endl;
    cin >> head;
    while (choice != -1)
    {
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << first_come_first_serve(n, arr, head) << endl;
            break;
        case 2:
            cout << shortest_seek_time_first(n, arr, head) << endl;
            break;
        case 3:
            cout << look(n, arr, head) << endl; // start direction is considerd as right
            break;
        case 4:
            cout << c_look(n, arr, head) << endl;
            break;
        case -1:
            return 0;
        }
    }
    return 0;
}
