n = 30
m = 10

puts "#{n} #{m}" 
m.times do 
    l = rand(n) + 1
    r = l + rand(n - l) + 1
    a = rand(10**9)
    b = rand(10**9)
    puts "#{l} #{r} #{a} #{b}"
end