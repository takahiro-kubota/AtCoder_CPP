#n,m = gets.split(" ").map(&:to_i)

x = gets.chomp
m = gets.to_i

if x.size == 1
    puts (x.to_i <= m ? 1 : 0)
    exit
end

d = 0
for i in 0..x.size-1
    d = [d, x[i].to_i].max
end

l = d
r = m+1
while l+1 < r
    tmp = 0
    mid = (l+r)/2
    for i in 0..x.size-1
        tmp *= mid
        tmp += x[i].to_i
        break if tmp > m
    end
    if tmp <= m
        l = mid
    else
        r = mid
    end
end

puts l-d