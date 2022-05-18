#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourMap
{
    MapNode<V> **buckets;
    int count;
    int numBuckets;

public:
    ourMap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];

        for (int i = 0; i < numBuckets; i++) // Initialising Array To Be NULL
        {
            buckets[i] = NULL;
        }
    }

    ~ourMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int CurrentCoeff = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode = key[i] * CurrentCoeff + hashCode;
            hashCode = hashCode % numBuckets;
            CurrentCoeff = CurrentCoeff * 37;
            CurrentCoeff = CurrentCoeff % numBuckets;
        }
        //(a*b*c)%n = (a%n * b%n * c%n)%n
        return hashCode % numBuckets;
    }

public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V deleteKey(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    temp->next = head->next;
                }
                V val = head->value;
                head->next = NULL;
                delete head;
                count--;
                return val;
            }
            prev = head;
            head = head->next;
        }

        return 0;
    }

    int size()
    {
        return count;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    return 0;
}