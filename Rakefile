task :default, [:cat, :qnum] do |t, args|
  category = args[:cat] ? args[:cat] : "ABC"
  qnumber  = args[:qnum] ? args[:qnum].to_i : 6
  filename = `date \"+%Y%m%d#{category}\"`.chomp
  sh "mkdir #{filename}"
  qnumber.times do |i|
    sh "cp -r tplt #{filename}/q#{i}"
  end
end
