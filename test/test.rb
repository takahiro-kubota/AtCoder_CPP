#n, k = gets.split.map(&:to_i)

s = gets.chomp
n = s.size

ans = 0
cm = 0
if n > 100
    cm = s[0..].to_i
    ans = cm
end

l = [n-100, 0].max
100.times do |i|
    break if i+l >= n
    cm = cm*10 + s[i+l].to_i
    ans += cm
end

puts ans