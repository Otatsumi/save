#encoding: utf-8

require_relative 'Method/bissection.class.rb'
require_relative 'Method/newtow.class.rb'
require_relative 'Method/steffenson.class.rb'
require_relative 'Method/secante.class.rb'
require_relative 'error/error.class.rb'

class Tore

  def initialize option, coef, decimal
    @option = option
    @coef = coef
    @decimal = decimal
  end

  def Aff
    puts "#{@coef[0]}x^4 + #{@coef[1]}x^3 + #{@coef[2]}x^2 + #{@coef[3]}x + #{@coef[4]} = 0"
    if @option.to_i == 1
      puts "Méthode de la bissection\n"
      g = Bissection.new @coef, @decimal
      h = g.resolve_b
    elsif @option.to_i == 2
      puts "Méthode de newtown\n"
      g = Newtown.new @coef, @decimal
      h = g.resolve_n
    elsif @option.to_i == 3
      puts "secante\n"
      g = Secante.new @coef, @decimal
      h = g.resolve_s
    elsif @option.to_i == 4
      puts "steffenson\n"
      g = Steffenson.new @coef, @decimal
      h = g.resolve_st
    else
      puts "pas d'option...\n"
    end
  end
end
