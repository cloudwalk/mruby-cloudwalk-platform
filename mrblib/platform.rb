class Platform
  Network = ::Network
  IO      = ::IO

  class System
    class << self
      alias_method :restart, :reboot
    end
  end

  # Will be called at RunTime boot
  def self.setup
    # TODO Implement
  end
end
