#encoding: utf-8

require_relative '../error/error.class.rb'

class Bissection

  def initialize tab, dec
    @coef = tab
    @x1 = 0.0
    @x2 = 1.0
    @xm = 0.0
    @value = 0.0
    @dec = -1 * (dec)
    @i = 1
    @choix = 0
  end

  def calc_x2
    (@coef[0] * @x2**4) + (@coef[1] * @x2**3) + (@coef[2] * @x2**2) + (@coef[3] * @x2) + @coef[4]
  end

  def calc_x1
    x = (@coef[0] * @x1**4) + (@coef[1] * @x1**3) + (@coef[2] * @x1**2) + (@coef[3] * @x1) + @coef[4]
  end

  def calc_xm
    xm = (@coef[0] * @xm**4) + (@coef[1] * @xm**3) + (@coef[2] * @xm**2) + (@coef[3] * @xm) + @coef[4]
  end

  def resolve_b

    puts "point initial 1: #{@x1}\n"
    puts "point initial 2: #{@x2}\n"
    while 1
      @xm = (@x1 + @x2) / 2
      Error::zerro @xm
      puts "itération #{@i} x = #{@xm}"
      @value = ((@x2 - @x1).abs / 2 * (@xm.abs))

      if @value < 10**@dec
        if @choix == 2
          result = calc_x2
        elsif @choix == 1
          result = calc_x1
        end
        puts "f(x) = #{result}"
        exit
      end

      if @i > 100
        puts "convenrgence not found\n"
        exit
      end

      fx1 = calc_x1
      fxm = calc_xm
      if (fx1 * fxm) < 0
        @x2 = @xm
        @choix = 2
      else
        @x1 = @xm
        @choix = 1
      end
      @i = @i + 1
    end
  end
end
