class Platform
  # Will be called at RunTime boot
  def self.setup
    Screen.setup(21, 7)
    begin
      require 'posxml_parser'
      require 'cloudwalk_handshake'
      CloudwalkHandshake.configure!
      self.setup_keyboard
    rescue LoadError
    rescue NameError
    end
    # TODO Implement
  end

  def self.version
    "0.2.0"
  end

  def self.setup_keyboard
    Device::IO::ONE_LETTERS   = "qzQZ _,."
    Device::IO::TWO_LETTERS   = "abcABC"
    Device::IO::THREE_LETTERS = "defDEF"
    Device::IO::FOUR_LETTERS  = "ghiGHI"
    Device::IO::FIVE_LETTERS  = "jklJKL"
    Device::IO::SIX_LETTERS   = "mnoMNO"
    Device::IO::SEVEN_LETTERS = "prsPRS"
    Device::IO::EIGHT_LETTERS = "tuvTUV"
    Device::IO::NINE_LETTERS  = "wxyWXY"
    Device::IO::ZERO_LETTERS  = "spSP"
  end
end

