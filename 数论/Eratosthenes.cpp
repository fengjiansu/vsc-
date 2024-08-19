

void sieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true); //prime[i]指示i是否为素数
    prime[0] = prime[1] = false; // 0 和 1 不是素数

    for (int p = 2; p * p <= n; p++) // 只处理到n的平方根
    {
        if (prime[p] == true) {
            // 标记时可直接从p的平方开始
            for (int i = p * p; i <= n; i += p)  
            {
                prime[i] = false;
            }
        }
    }
    // 输出所有的素数
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
}
