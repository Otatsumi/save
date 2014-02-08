#encoding: utf-8

require_relative '../error/error.class.rb'

class Newtown

  def initialize tab, dec
    @coef = tab
    @xn = 0.5
    @dec = -1 * (dec)
    @i = 1
    @value = 0.0
  end

  def calc_fct
    fct = (@coef[0] * @xn**4) + (@coef[1] * @xn**3) + (@coef[2] * @xn**2) + (@coef[3] * @xn) + @coef[4]
  end

  def calc_fct_der
    dfect = (4 * @coef[0] * @xn**3) + (3 * @coef[1] * @xn**2) + (2 * @coef[2] * @xn) + @coef[3]
  end

  def resolve_n

    puts "point initial : #{@xn}\n"
    xn1 = @xn - (calc_fct/calc_fct_der)
    @xn = xn1
    while 1
      xn1 = @xn - (calc_fct/calc_fct_der)
      Error::zerro xn1
      @value = (xn1 - @xn).abs / xn1.abs
      if @value < 10**@dec
        xn = xn1
        puts "itération #{@i} x = #{xn}"
        result = calc_fct
        puts "f(x) = #{result}"
        exit
      end

      if @i > 100
        puts "convenrgence not found\n"
        exit
      end

      puts ("itération #{@i} x = #{@xn}")
      @xn = xn1
      @i = @i + 1
    end
  end
end
