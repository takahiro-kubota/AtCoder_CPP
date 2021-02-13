x, y, r = gets.split.map(&:to_f)
#xs, ys, rs = gets.split

D = 10000

def isqrt(x)
    ac, wa = 0, 10**10*2
    while ac + 1 < wa
        wj = (ac + wa)/2;
        if wj*wj <= x
            ac = wj
        else
            wa = wj
        end
    end
    return ac
end

x = (x*D).round
y = (y*D).round
r = (r*D).round

lo = y - r
lo += (-lo)%D
up = y + r
up -= up%D

ans = 0
for i in lo/D..up/D
   dy = y - i*D
   dx = isqrt(r*r - dy*dy)
   lp = x - dx
   lp += (-lp)%D
   rp = x + dx
   rp -= rp%D
   ans += rp/D - lp/D + 1
end

puts ans
