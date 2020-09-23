n, k = gets.split.map(&:to_i)

nstr = n.to_s

lst = []
mstr = ""
ans = 10**17
cands = []
nstr.length.times do |i|
    if lst.include?(nstr[i])
        mstr += nstr[i]
    elsif k == 1
        
    elsif k > 1
        lst << nstr[i]
        mstr += nstr[i]
        k -= 1
    else

    end
    ans = 0 if i == nstr.length - 1
end

puts ans
