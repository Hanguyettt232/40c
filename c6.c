#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef long long ll;

ll ChiaNghichDao(ll a, ll b);
ll NhanBinhPhuongCoLap(ll x, ll y, ll m);
int KiemTraMiller_Rabin(ll n);
int PhanTichThuaSo(ll x, int ThuaSo[]);
int KiemTraPhanTuSinh(ll p, ll g, int ThuaSo[], ll index);
int Check(ll mang_aj[], ll t, ll m);

int main()
{
    ll n, a, b, m, t, a_m, Nda_m;
    int ThuaSo[100] = {0};
    printf("Nhap n: ");
    scanf("%lld", &n);
    while (!KiemTraMiller_Rabin(n))
    {
        printf("Vui long nhap n la so nguyen to\n");
        scanf("%lld", &n);
    }
    int index = PhanTichThuaSo(n - 1, ThuaSo);
    printf("Nhap phan tu sinh a: ");
    scanf("%lld", &a);
    while (!KiemTraPhanTuSinh(n, a, ThuaSo, index))
    {
        printf("Vui long nhap lai phan tu sinh a: \n");
        scanf("%lld", &a);
    }
    printf("Nhap b: ");
    scanf("%lld", &b);
    m = (ll)ceil(sqrt(n - 1)); // m xem d?nh nghia trong d?
    ll mang_aj[10000];         // Gi? d?nh m <= 10000 d? luu b?ng baby steps
    for (int i = 0; i < m; i++)
    {
        mang_aj[i] = NhanBinhPhuongCoLap(a, i, n);
    }
    a_m = NhanBinhPhuongCoLap(a, m, n);
    Nda_m = ChiaNghichDao(a_m, n);
    for (int i = 0; i < m; i++)
    {
        t = NhanBinhPhuongCoLap(Nda_m, i, n);
        t = NhanBinhPhuongCoLap(b * t, 1, n); // Tính b * (a^-m)^i mod n
        // Tìm t trong mang_aj
        // N?u tìm th?y, tr? v? ch? s? i và giá tr? m * i + ch? s?
        if (Check(mang_aj, t, m) != -1)
        {
            printf("%lld\n", m * i + Check(mang_aj, t, m));
            return 0;
        }
    }
    return 0;
}

// Tìm (a^m)^-1 mod n
ll ChiaNghichDao(ll a, ll b)
{
    ll q, r, x, y, x1, x2, y1, y2;
    x2 = y1 = 1;
    x1 = y2 = 0;
    while (b > 0)
    {
        q = a / b;
        r = a % b;
        x = x2 - x1 * q;
        y = y2 - x2 * q;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    return x2;
}
// Tính a^j mod n, (a^-m)^i mod n.
ll NhanBinhPhuongCoLap(ll x, ll y, ll m)
{
    ll b = 1, a = x % m;
    if (y % 2 == 1)
    {
        b = a;
    }
    y /= 2;
    while (y > 0)
    {
        a = (a * a) % m;
        if (y % 2 == 1)
            b = (b * a) % m;
        y /= 2;
    }
    return (b + m) % m;
}

// check n là nguyên t?
int KiemTraMiller_Rabin(ll n)
{
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n < 2)
        return 0;
    ll n_1 = n - 1, r, y, a;
    int s = 0;
    while (n_1 % 2 == 0)
    {
        s += 1;
        n_1 /= 2;
    }
    r = n_1;
    srand(time(NULL));
    for (int i = 1; i <= 5; i++)
    {
        a = 2 + rand() % (n - 3); // Sinh s? ng?u nhiên trong [2, n-2]
        y = NhanBinhPhuongCoLap(a, r, n);
        if (y == 1 || y == n - 1)
            continue;
        else
        {
            for (int j = 1; j <= s - 1; j++)
            {
                y = (y * y) % n;
                if (y == n - 1)
                    break;
                if (y == 1)
                    return 0;
            }
            if (y != n - 1)
                return 0;
        }
    }
    return 1;
}

// Tìm th?a s? c?a n-1 ( thu?t toán trang 24_chuong 2)
int PhanTichThuaSo(ll x, int ThuaSo[])
{
    int i = 2, index = 0;
    while (!KiemTraMiller_Rabin(x) && x != 1)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                x /= i;
            }
            ThuaSo[index] = i;
            index++;
        }
        i++;
    }
    if (x > 1)
    {
        ThuaSo[index] = x;
        index++;
    }
    return index;
}

// Ð?m b?o g^((p-1)/q) ? 1 mod p
int KiemTraPhanTuSinh(ll p, ll g, int ThuaSo[], ll index)
{
    for (int i = 0; i < index; i++)
    {
        if (NhanBinhPhuongCoLap(g, (p - 1) / ThuaSo[i], p) == 1)
            return 0;
    }
    return 1;
}

/*
M?c dích: Tìm t trong mang_aj
Vai trò: So kh?p giant steps v?i baby steps.
*/
int Check(ll mang_aj[], ll t, ll m)
{
    for (int i = 0; i < m; i++)
    {
        if (mang_aj[i] == t)
            return i;
    }
    return -1;
}
