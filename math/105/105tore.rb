#!/usr/bin/ruby
#encoding: utf-8 

require_relative '105tore.class.rb'
require_relative 'error/error.class.rb'

if ARGV[0] == "--help"
  exec("man ./105tore.man")
end

def main
  if ARGV.size != 7
    Error::call "error, number of arguments is different of 7"
  end
  option = ARGV[0]
  Error::option? option.to_i
  coef = [ARGV[5].to_f, ARGV[4].to_f, ARGV[3].to_f, ARGV[2].to_f, ARGV[1].to_f]
  decimal = ARGV[6].to_i
  Error::decimal decimal
  Error::equa_null coef
  param = Tore.new option, coef, decimal
  param.Aff
end

main()
