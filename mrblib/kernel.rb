module Kernel
  # TODO Implement
  SCREEN_X_SIZE = 20
  SCREEN_Y_SIZE = 7
  XUI_KEY1      = 2
  XUI_KEY2      = 3
  XUI_KEY3      = 4
  XUI_KEY4      = 5
  XUI_KEY5      = 6
  XUI_KEY6      = 7
  XUI_KEY7      = 8
  XUI_KEY8      = 9
  XUI_KEY9      = 10
  XUI_KEY0      = 11
  XUI_KEYCANCEL = 223
  XUI_KEYCLEAR  = 14
  XUI_KEYENTER  = 28
  XUI_KEYSHARP  = 55
  XUI_KEYF1     = 59
  XUI_KEYALPHA  = XUI_KEYF1
  XUI_KEYF2     = 60
  XUI_KEYF3     = 61
  XUI_KEYF4     = 62
  XUI_KEYFUNC   = 102
  XUI_KEYUP     = 103
  XUI_KEYDOWN   = 108
  XUI_KEYMENU   = 139
  # TODO Implement

  IO_INPUT_NUMBERS = :numbers
  IO_INPUT_LETTERS = :letters
  IO_INPUT_SECRET  = :secret

  INPUT_NUMBERS = 36 # TODO Implement
  INPUT_LETTERS = 20 # TODO Implement
  INPUT_SECRET  = 28 # TODO Implement

  def getc
    case PAX._getc
    when XUI_KEY0 then "0"
    when XUI_KEY1 then "1"
    when XUI_KEY2 then "2"
    when XUI_KEY3 then "3"
    when XUI_KEY4 then "4"
    when XUI_KEY5 then "5"
    when XUI_KEY6 then "6"
    when XUI_KEY7 then "7"
    when XUI_KEY8 then "8"
    when XUI_KEY9 then "9"
    when XUI_KEYCANCEL then 0x1B.chr
    when XUI_KEYCLEAR then 0x0F.chr
    when XUI_KEYENTER then 0x0D.chr
    when XUI_KEYALPHA then 0x10.chr
    when XUI_KEYSHARP then 0x11.chr
    when XUI_KEYF1 then 0x01.chr
    when XUI_KEYF2 then 0x02.chr
    when XUI_KEYF3 then 0x03.chr
    when XUI_KEYF4 then 0x04.chr
    when XUI_KEYFUNC then 0x06.chr
    when XUI_KEYUP then 0x07.chr
    when XUI_KEYDOWN then 0x08.chr
    when XUI_KEYMENU then 0x09.chr
    else
      0x1B.chr
    end
  end

  def print_line(buf, row=nil, column=nil)
    __printstr__(buf, row, column)
  end

  def gets(separator, limit, mode)
    get_string(1, limit, mode).split(separator).first
  end

  def get_string(min, max, mode = IO_INPUT_LETTERS)
    PAX._gets(min, max, input_type(mode), Screen.y, Screen.x)
  end

  # TODO Scalone refactory NEEDED
  def __printstr__(str, y = nil, x = nil)
    Screen.y = (y || Screen.y || 0)
    Screen.x = (x || Screen.x || 0)

    screen_add_y(1) if str == "\n"

    str.split("\n").each_with_index do |string,index|
      screen_add_y(1) if index > 0

      if (Screen.x + string.size) < SCREEN_X_SIZE
        _printstr__(string, Screen.y, Screen.x)
        Screen.x += string.size
      else
        space = SCREEN_X_SIZE - Screen.x
        _printstr__("#{string[0..(space - 1)]}", Screen.y, Screen.x)
        screen_add_y(1)
        __printstr__("#{string[(space)..-1]}")
      end
    end
  end

  private
  def screen_add_y(value)
    Screen.y += value
    Screen.x = 0
    if Screen.y > (SCREEN_Y_SIZE - 1)
      Screen.y = 0
    end
  end

  def input_type(type)
    case type
    when IO_INPUT_NUMBERS then INPUT_NUMBERS
    when IO_INPUT_LETTERS then INPUT_LETTERS
    when IO_INPUT_SECRET then INPUT_SECRET
    else
      INPUT_LETTERS
    end
  end
end
