require './Hello'
require 'benchmark'

Benchmark.bm 10 do |r|
  r.report "Case01" do
    (1000*1000).times do
    #(1).times do
        hello = Hello::new
        hello.say
    end
  end
end

#p res
