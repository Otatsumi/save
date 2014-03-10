#encoding: utf-8

require_relative 'error/error.class.rb'

class Times

  def initialize k
    @k = k
  end

  def coef
    tab = Array.new
    nb = Array.new
    i = 0
    while i < @k.size
      neg = 0
      while @k[i] != '|' and  i < @k.size
        if (@k[i] == '-')
          neg = 1
        end
        nb << @k[i]
        i = i + 1
      end
      j = 0
      nbr =  0
      while j < nb.size
        nbr = nbr * 10 + nb[j].to_i
        j = j + 1
      end
      if neg == 1
        nbr = nbr * -1
      end
      tab << nbr
      nb = Array.new
      i = i + 1
    end
    return tab
  end

  def write_equation coef
    i = coef.size + 1
    j = 0
    k = 0
    s = Array.new
    while k <= coef.size - 1
      s[j] = coef[k].to_s
      if i - 2 != 0
        s[j + 1] = "x^"
        s[j + 2] = (i - 2).to_s
        s[j + 3] = "+"
      end
      j = j + 4
      i = i - 1
      k = k + 1
    end
    return s
  end

  def naif coef
    tab = Array.new
    x = 0.0
    start = Time.now
    while x <= 1000
      res = 0.0
      i = coef.size - 1
      pow = 1
      while i >= 0
        res = res + coef[i] * (x**pow)
        pow = pow + 1
        i = i - 1
      end
      tab << res
      x = x + 0.01
    end
    mend = Time.now
    t = mend - start
    return t
  end

  def horner coef
    x = 0.0
    tab = Array.new
    start = Time.now
    while x <= 1000
      i = 1
      res = coef[0]
      while i < coef.size
        res = coef[i] + (x * res)
        i = i + 1
      end
      tab << res
      x = x + 0.01
    end
    mend = Time.now
    t = mend - start
    return t
  end

  def trace v, g, h, id
    g = g.reverse
    h = h.reverse

    tab = Array.new
    x = -10.0
    while x <= 10
      i = 1
      res1 = g[0]
      while i < g.size
        res1 = g[i] + (x * res1)
        i = i + 1
      end
      i = 1
      res2 = h[0]
      while i < h.size
        res2 = h[i] + (x * res2)
        i = i + 1
      end
      if res2 != 0
        tab << res1/res2
      end
      x = x + 0.01
    end
    
    v.labels = { 0 => '-10', tab.size / 4 => '-5',
      tab.size / 2 => '0', tab.size / 4 * 3 => '5',
      tab.size - 1 => '10'}
    v.data :"courbe #{id}", tab
    return v
  end
end
