module Kernel
  # TODO Implement
  SCREEN_X_SIZE  = 21
  SCREEN_Y_SIZE  = 7
  XUI_KEY1       = 2
  XUI_KEY2       = 3
  XUI_KEY3       = 4
  XUI_KEY4       = 5
  XUI_KEY5       = 6
  XUI_KEY6       = 7
  XUI_KEY7       = 8
  XUI_KEY8       = 9
  XUI_KEY9       = 10
  XUI_KEY0       = 11
  XUI_KEYCANCEL  = 223
  XUI_KEYTIMEOUT = 18
  XUI_KEYCLEAR   = 14
  XUI_KEYENTER   = 28
  XUI_KEYSHARP   = 55
  XUI_KEYF1      = 59
  XUI_KEYF2      = 60
  XUI_KEYF3      = 61
  XUI_KEYF4      = 62
  XUI_KEYALPHA   = 101
  XUI_KEYFUNC    = 102
  XUI_KEYUP      = 103
  XUI_KEYDOWN    = 108
  XUI_KEYMENU    = 139
  # TODO Implement

  IO_INPUT_NUMBERS = :numbers
  IO_INPUT_LETTERS = :letters
  IO_INPUT_SECRET  = :secret

  INPUT_NUMBERS = 36 # TODO Implement
  INPUT_LETTERS = 20 # TODO Implement
  INPUT_SECRET  = 28 # TODO Implement

  PLATFORM_KEYS = {
    XUI_KEY0       => "0",
    XUI_KEY1       => "1",
    XUI_KEY2       => "2",
    XUI_KEY3       => "3",
    XUI_KEY4       => "4",
    XUI_KEY5       => "5",
    XUI_KEY6       => "6",
    XUI_KEY7       => "7",
    XUI_KEY8       => "8",
    XUI_KEY9       => "9",
    XUI_KEYF1      => 0x01.chr,
    XUI_KEYF2      => 0x02.chr,
    XUI_KEYF3      => 0x03.chr,
    XUI_KEYF4      => 0x04.chr,
    XUI_KEYFUNC    => 0x06.chr,
    XUI_KEYUP      => 0x07.chr,
    XUI_KEYDOWN    => 0x08.chr,
    XUI_KEYMENU    => 0x09.chr,
    XUI_KEYALPHA   => 0x10.chr,
    XUI_KEYSHARP   => 0x11.chr,
    XUI_KEYTIMEOUT => 0x12.chr,
    XUI_KEYENTER   => 0x0D.chr,
    XUI_KEYCLEAR   => 0x0F.chr,
    XUI_KEYCANCEL  => 0x1B.chr
  }

  def print_line(buf, row=nil, column=nil)
    Platform::Display.print_line(buf, row, column)
  end

  def gets(separator = 0x0D.chr, limit = SCREEN_X_SIZE, mode = IO_INPUT_LETTERS)
    Device::IO.get_string(1, limit, mode).split(separator).first
  end

  def getc(timeout_io = nil)
    timeout_io ||= IO.timeout
    convert_key(IO._getc(timeout_io))
  end

  private
  def convert_key(value)
    PLATFORM_KEYS[value] || 0x1B.chr
  end
end

