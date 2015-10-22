
class Platform
  class Display
    def self.display_bitmap(*args)
      print_bitmap(*args)
    end

    def self.print_in_line(buf, row=nil, column=nil)
      print_line(buf, row, column)
    end
  end
end

