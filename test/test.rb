#x, y, r = gets.split.map(&:to_f)
xs = gets.chomp
m = gets.to_i

if xs.size == 1
    x = xs.to_i
    ans = x <= m ? 1 : 0
    puts ans
    exit
end

d = 0
xs.size.times do |i|
    xi = xs[i..i]
    d = [xi.to_i, d].max
end

wj = d + 1
xval = 0
xs.size.times do |i|
    xval *= wj
    xval += xs[i].to_i
end
if xval > m
    wa = wj
    puts 0
    exit
end

ac, wa = d + 1, 10**18+1
while ac + 1 < wa
    wj = (ac + wa)/2
    minv = wj
    if minv > m
        wa = wj
        next
    end

    xval = 0
    xs.size.times do |i|
        xval *= wj
        xval += xs[i].to_i
    end
    if xval > m
        wa = wj
        next
    end

    ac = wj
end

ans = ac - d
puts ans