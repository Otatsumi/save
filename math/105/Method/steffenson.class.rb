#encoding: utf-8

require_relative '../error/error.class.rb'
require_relative '../105tore.class.rb'

class Steffenson
 
  def initialize tab, dec
    @coef = tab
    @x0 = 0.5
    @x1 = 0.0
    @x2 = 0.0
    @xe = 0.0
    @dec = -1 * (dec)
    @i = 1
    @value = 0.0
  end

  def calc_fct x
    fct = (@coef[0] * x**4) + (@coef[1] * x**3) + (@coef[2] * x**2) + (@coef[3] * x) + @coef[4]
  end

  def resolve_st
    puts "point initial : #{@x0}\n"
    while 1

      @x1 = calc_fct @x0
      @x2 = calc_fct @x1
      Error::zerro (@x2 - (2 * @x1) + @x0)
      @xe = @x0 - ((@x1 - @x0)**2 / (@x2 - (2 * @x1) + @x0))
      Error::zerro @xe
      @value = (@xe - @x0).abs / @xe.abs

      if @value < 10**@dec
        puts "x = #{@xe}\n"
        fx = calc_fct @xe
        puts "f(x) = #{fx}\n"
        exit
      end

      if @i > 100
        puts "convenrgence not found\n"
        exit
      end

      puts ("itération #{@i} x = #{@xe}")
      @x0 = @xe
      @i = @i + 1
    end
  end
end

