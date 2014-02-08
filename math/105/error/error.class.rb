#encoding: utf-8 

class Error

  ERR_HIGH = "Fatal Error"
  ERR_MEDIUM = "Error"
  ERR_LOW = "Warning"
  ERR_COLOR_RED = "0;31"
  ERR_COLOR_GREEN = "0;32"
  ERR_COLOR_YELLOW = "1;33"
  ERR_COLOR_BLUE = "0;34"
  ERR_COLOR_ORANGE = "0;33"
  @@errors = 0

  def self.isnum? string
    if string.is_a?String and string != nil
      if string.to_i.to_s == string or string.to_f.to_s == string
        return true
      elsif string.to_i.to_s == string[1..-1] or string.to_f.to_s == string[1..-1]
        true
      else
        return false
      end
    elsif string.is_a?Numeric
      true
    else
      Error.call "'#{string}' is not a String"
      return false
    end
  end

  def self.call m, level=Error::ERR_HIGH

    if level != Error::ERR_HIGH and level != Error::ERR_MEDIUM and level != Error::ERR_LOW
      self.call "Error::call : error level invalid", Error::ERR_MEDIUM
    end
    
    #message color
    if level == Error::ERR_HIGH
      color = Error::ERR_COLOR_RED
    elsif level == Error::ERR_MEDIUM
      color = Error::ERR_COLOR_ORANGE
    elsif level == Error::ERR_LOW
      color = Error::ERR_COLOR_YELLOW
    end

    #message display
    if level == Error::ERR_HIGH
      puts "\033[#{color}m#{level} : #{m}.\033[00m"
      exit
    elsif level == Error::ERR_MEDIUM
      puts "\033[#{color}m#{level} : #{m}.\033[00m"
    elsif level == Error::ERR_LOW
      puts "\033[#{color}m#{level} : #{m}.\033[00m"
    end

    @@errors += 1
    return self
  end

  def self.errors
    @@errors
  end

  def self.option? option
    if option != 1 and option != 2 and option != 3 and option != 4
      Error.call "option inconnu"
    end
  end

  def self.zerro param

    if param == 0
      Error.call "division par 0"
      exit
    end

  end

  def self.equa_null coef
    if coef[0] == 0 and coef[1] == 0 and coef[2] == 0 and coef[3] == 0 and coef[4] == 0
      Error.call "error, tout les parametre valent 0"
      exit
    end
  end

  def self.decimal dec
    if dec < 0
      Error.call "error, the last argment is a positive number only"
    end
  end
end
