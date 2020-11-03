# ll x, y, a, b;
# cin >> x >> y >> a >> b;
# ll cnt = 0;
# while (true)
# {
#     if ((a - 1) * x > b || a * x >= y)
#         break;
#     x = a * x;
#     cnt++;
# }
# cnt += (y - 1 - x) / b;
# cout << cnt << endl;

x, y, a, b = map(int, input().split())
cnt = 0

while True:
    if (a - 1) * x > b or a * x >= y:
        break
    x = a * x
    cnt += 1

cnt += (y - 1 - x) // b
print(cnt)
