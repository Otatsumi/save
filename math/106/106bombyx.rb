#!/usr/bin/ruby
#encoding: utf-8

require_relative 'error/error.class.rb'
require_relative '106bombyx.class.rb'

def main

  if ARGV.size > 2 or ARGV.size < 1
    Error::call "error, you need one or two argument minimum"
  end

  s = ARGV.size
  i = 0
  if s == 1
    if !Error::isnum? ARGV[0]
      Error::call "error, invalid parameter"
    end
    if ARGV[0].to_f >= 1 and ARGV[0].to_f <= 4
      g = Bombyx.new ARGV[0]
      h = g.calc_basic
    else
      Error::call "error, number #{ARGV[0]} is invalid"
    end
  else
    if !Error::isnum? ARGV[0] or !Error::isnum? ARGV[1]
      Error::call "error, invalid parameters"
    end
    g = Bombyx.new 0
    h = g.calc_in_tab ARGV[0].to_f, ARGV[1].to_f
  end

end

main()
