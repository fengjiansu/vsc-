

void sieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true); //prime[i]ָʾi�Ƿ�Ϊ����
    prime[0] = prime[1] = false; // 0 �� 1 ��������

    for (int p = 2; p * p <= n; p++) // ֻ����n��ƽ����
    {
        if (prime[p] == true) {
            // ���ʱ��ֱ�Ӵ�p��ƽ����ʼ
            for (int i = p * p; i <= n; i += p)  
            {
                prime[i] = false;
            }
        }
    }
    // ������е�����
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
}
