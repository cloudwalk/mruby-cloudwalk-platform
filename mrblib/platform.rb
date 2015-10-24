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
  end

  # Will be called at RunTime boot
  def self.setup
    # TODO Implement
  end
end
