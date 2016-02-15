class Platform
  class System
    class << self
      alias_method :restart, :reboot if self.respond_to? :reboot
    end

    def self.versions
      hash = Hash.new
      hash["OS"]     = self.os_version
      hash["SDK"]    = self.sdk_version
      hash["EMV"]    = Platform::EMV.version if Platform.const_defined? :EMV
      hash["Pinpad"] = self.pinpad_version
      hash
    end
  end
end

