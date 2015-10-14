class LRUCache {
private:
	int m_capacity;
	unordered_map<int, list<pair<int, int> >::iterator> m_map;
	list<pair<int, int> > m_list;
public:
	LRUCache(int capacity)£ºm_capacity(capacity){

	}

	int get(int key) {
		unordered_map<int, list<pair<int, int> >::iterator>::iterator tempIter = m_map.find(key);
		if (tempIter == m_map.end())
			return -1;
		m_list.splice(m_list.begin(), m_list, tempIter->second);
		return tempIter->second->second;
	}

	void set(int key, int value) {
		unordered_map<int, list<pair<int, int> >::iterator>::iterator tempIter = m_map.find(key);
		if (tempIter != m_map.end())
		{
			m_list.splice(m_list.begin(), m_list, tempIter->second);
			tempIter->second->second = value;
			return;
		}
		if (m_list.size() == m_capacity)
		{
			int delKey = m_list.back().first;
			m_list.pop_back();
			m_map.erase(delKey);
		}
		m_list.emplace_front(key, value);
		m_map[key] = m_list.begin();
	}
};