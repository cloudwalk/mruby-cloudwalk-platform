class Platform
  Network = ::Network if Kernel.const_defined? :Network
  IO      = ::IO

  class System
    class << self
      alias_method :restart, :reboot if self.respond_to? :reboot
    end

  end

  class IO
    def self.get_string(min, max, mode = :letters)
      PAX._gets(min, max, convert_input_type(mode), Screen.y, Screen.x)
    end
  end

  # Will be called at RunTime boot
  def self.setup
    # TODO Implement
  end
end
