n = gets.to_i
s = gets.chomp
q = gets.to_i

flp = false
q.times do
  t, a, b = gets.split(" ").map(&:to_i)
  a -= 1
  b -= 1
  if t == 1
    if flp
      a = (a + n) % (2*n)
      b = (b + n) % (2*n)
    end
    s[a], s[b] = s[b], s[a]
  else
    flp = !flp
  end
end

if flp
  puts s[n..-1] + s[0..n-1]
else
  puts s
end

#a = gets.split(" ").map(&:to_i).max
