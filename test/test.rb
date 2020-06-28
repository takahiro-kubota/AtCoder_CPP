#n, m, k = gets.split.map(&:to_i)

n = gets.to_i

ans = 0
for i in 1..n
    ans += (i+i*(n/i))*(n/i)/2
end

puts ans
