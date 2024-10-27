cout << "start" << endl;
	for(int i = 0; i < n; i++) {
		int st;
		cin >> st;
		cout << "taken" << endl;
		stars.push_back(st);
		connections.push_back(0);
		edge.push_back(vector<int> ());
	}