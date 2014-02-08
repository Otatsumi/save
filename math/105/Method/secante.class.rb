#encoding: utf-8

require_relative '../error/error.class.rb'

class Secante

  def initialize tab, dec
    @coef = tab
    @x1 = 0.4
    @x2 = 0.8
    @xn = 0.0
    @dec = -1 * (dec)
    @i = 1
    @value = 0.0
  end

  def calc_x1
    fct = (@coef[0] * @x1**4) + (@coef[1] * @x1**3) + (@coef[2] * @x1**2) + (@coef[3] * @x1) + @coef[4]
  end

  def calc_x2
    fct = (@coef[0] * @x2**4) + (@coef[1] * @x2**3) + (@coef[2] * @x2**2) + (@coef[3] * @x2) + @coef[4]
  end

  def calc_xn
    fct = (@coef[0] * @xn**4) + (@coef[1] * @xn**3) + (@coef[2] * @xn**2) + (@coef[3] * @xn) + @coef[4]
  end

  def resolve_s
    
    puts "point initial 1: #{@x1}\n"
    puts "point initial 2: #{@x2}\n"
    while 1
      @xn = @x2 - ((calc_x2 * (@x2 - @x1)) / (calc_x2 - calc_x1))
      Error::zerro @xn
      @value = (@xn - @x2).abs / (@xn).abs

      if @value < 10**@dec
        result = calc_x2
        puts "f(x) = #{result}"
        exit
      end
      
      if @i > 100
        puts "convenrgence not found\n"
        exit
      end

      puts ("itération #{@i} x = #{@xn}")
      @x1 = @x2
      @x2 = @xn
      @i = @i + 1
    end
  end

end
