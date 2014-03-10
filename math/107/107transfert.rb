#!/usr/bin/ruby
#encoding: utf-8

require 'gruff'
require_relative 'error/error.class.rb'
require_relative '107transfert.class.rb'

def main

  s = ARGV.size
  if s == 0
    Error::call "error : you need one argument minimum"
  end
  i = 0
  if s == 1 or ARGV[0] == "--compare"
    if ARGV[0] == "--compare"
      i = 1
    else
      i = 0
    end
    while i < ARGV.size

      r = ARGV[i].match /^([\-0-9])+(([\|\-0-9])*)+([\|\-0-9])$/
      if !r
        Error::call "error : argument #{i + 1} has an invalid syntaxe"
      end

      g = Times.new ARGV[i]
      h = g.coef
      s = g.write_equation h
      puts "évaluation du polynome #{s.join("")} en 1.000.000 de points :"
      t = g.naif h
      puts "algorithme naif: #{t} secondes"
      t = g.horner h
      puts "algorithme horner: #{t} secondes"
      puts
      i = i + 1
    end
  else
    if ARGV.size % 2 != 0
      Error::call "you need a number pair of argument only"
    end
    i = 0
    v = Gruff::Line.new ("1000x1000")
    v.title = '107transfert'
    id  = 1
    while i < ARGV.size
      
      r = ARGV[i].match /^([\-0-9])+(([\|\-0-9])*)+([\|\-0-9])$/
      if !r
        Error::call "error : argument #{i + 1} has an invalid syntaxe"
      end
      r = ARGV[i + 1].match /^([\-0-9])+(([\|\-0-9])*)+([\|\-0-9])$/
      if !r
        Error::call "error : argument #{i + 2} has an invalid syntaxe"
      end

      g1 = Times.new ARGV[i]
      g2 = Times.new ARGV[i + 1]

      h1 = g1.coef
      h2 = g2.coef
    
      t1 = g1.write_equation h1
      t2 = g2.write_equation h2
      puts "composant #{id}:\n\n"
      puts "#{t1.join("")}"
      puts "----------------------"
      puts "#{t2.join("")}"
      if i + 2 < ARGV.size
        puts
        puts
      end
      v = g1.trace v, h1, h2, id
      i = i + 2
      id  = id + 1
    end
    v.write('107-courbe.png')
    `eog 107-courbe.png`
  end

end

main()
