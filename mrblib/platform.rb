class Platform
  # Will be called at RunTime boot
  def self.setup
    Screen.setup(21, 7)
    begin
      require 'posxml_parser'
      require 'cloudwalk_handshake'
      CloudwalkHandshake.configure!
    rescue LoadError
    rescue NameError
    end
    # TODO Implement
  end

  def self.version
    "0.2.0"
  end
end

