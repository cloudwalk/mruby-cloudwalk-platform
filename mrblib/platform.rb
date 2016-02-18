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
    "0.2.1"
  end

  def self.setup_keyboard
    Device::IO.setup_keyboard(["qzQZ _,.", "abcABC", "defDEF", "ghiGHI", "jklJKL",
                              "mnoMNO", "prsPRS", "tuvTUV", "wxyWXY", "spSP"])
  end
end

