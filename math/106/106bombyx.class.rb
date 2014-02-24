#encoding: utf-8


require 'RMagick'
require_relative 'error/error.class.rb'

class Bombyx

  def initialize k
    @xn = 10.0
    @xn1 = 0.0
    @k = k.to_f
    @gen = 1
  end
  
  def calc_basic
    
    picture = Magick::Image.new(1000, 1000)
    data = Magick::Draw.new
    i = 0

    tab = Array.new
    tab << @xn
    @xn1 = @k * @xn * ((1000 - @xn) / 1000)
    while @gen < 99
      @xn = @xn1
      @xn1 = @k * @xn * ((1000 - @xn) / 1000)      
      @gen = @gen + 1
      tab << @xn
    end
    
    xx = 9.6
    yx = 960 / tab.max
    #draw in the pict
    (tab.size - 1).times do |i|
      data.polyline(i * xx + 40,          960 - tab[i] * yx + 40,
                    (i + 1) * xx + 40,    960 - tab[i + 1] * yx + 40)
    end
    #display
    data.draw(picture)
    picture.display
  end

  def calc_in_tab a, b
    if a == b
      Error::call "error: argument are equivalent"
    elsif a < 0 or b < 0
      Error::call "error: number positiv only"
    elsif a < b
      min = a
      max = b
    else
      min = b
      max = a
    end

    picture = Magick::Image.new(1000, 1000)
    data = Magick::Draw.new

    k = 1.0
    nb = min
    while k < 4

      min = nb
      @gen = 1
      @xn = 10.0
      while min < max
        @xn1 = k * @xn * ((1000 - @xn) / 1000)
        while @gen < min
          @xn = @xn1
          @xn1 = k * @xn * ((1000 - @xn) / 1000)      
          @gen = @gen + 1
        end
        data.point(1040 - (1000 / k), 1000 - @xn1)
        min = min + 1
      end
      k = k + 0.01
    end

    #display
    data.draw(picture)
    picture.display
  end
end
