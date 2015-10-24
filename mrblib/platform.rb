class Platform
  class System
    class << self
      alias_method :restart, :reboot if self.respond_to? :reboot
    end
  end

  # Will be called at RunTime boot
  def self.setup
    # TODO Implement
  end
end
