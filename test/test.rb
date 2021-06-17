a, b = gets.split(" ").map(&:to_i)

def gcd(a, b)
  a, b = b, a if a > b
  return b if a == 0
  return gcd(a, b%a)
end

g = gcd(a, b)
l = a*b/g
if l > 10**18
  l = "Large"
end

puts l