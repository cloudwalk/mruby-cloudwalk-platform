class Platform
  class System
    class << self
      alias_method :restart, :reboot if self.respond_to? :reboot
    end
  end
end

