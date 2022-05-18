#include <iostream>
#include <string>
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
        delete[] buckets;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoeff = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode = key[i] * currentCoeff + hashCode;
            hashCode = hashCode % numBuckets;
            currentCoeff = currentCoeff * 37;
            currentCoeff = currentCoeff % numBuckets;
        }
        //(a*b*c)%n = (a%n * b%n * c%n)%n
        return hashCode % numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[numBuckets * 2];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets = numBuckets * 2;
        count = 0;
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (count * 1.0) / numBuckets;
    }

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

        double loadFactor = (count * 1.0) / numBuckets;

        if (loadFactor > 0.7)
        {
            rehash();
        }
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
                    prev->next = head->next;
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

    ourMap<int> map;
    for (int i = 0; i < 10; i++)
    {
        string key = "abc";
        char c = '0' + i;
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        // cout << map.getLoadFactor() << endl;
    }

    cout <<map.size()<<endl;
    cout << map.deleteKey("abc2") << endl;
    cout << map.deleteKey("abc7") << endl;
    cout << map.size() << endl;

    for (int i = 0; i < 10; i++)
    {
        string key = "abc";
        char c = '0' + i;
        key = key + c;

        cout <<key<<": " << map.getValue(key) << endl;
    }

    return 0;
}