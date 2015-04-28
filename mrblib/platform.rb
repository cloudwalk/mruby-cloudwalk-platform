class Platform
  Network = ::Network if Kernel.const_defined? :Network
  IO      = ::IO

  class System
    class << self
      alias_method :restart, :reboot if self.respond_to? :reboot
    end
  end

  class IO
    DEFAULT_TIMEOUT = 30000

    class << self
      attr_accessor :timeout
    end

    # get_string c implementation.
    #
    # @param min [Fixnum] Minimum length of the input string.
    # @param max [Fixnum] Maximum length of the input string (127 bytes maximum).
    # @param mode [Symbol] Mode to input, check IO_INPUT_* variables.
    def self.get_string(min, max, mode = :letters)
      _gets(min, max, convert_input_type(mode), 0, 2)
    end
  end

  # Will be called at RunTime boot
  def self.setup
    # TODO Implement
  end
end
