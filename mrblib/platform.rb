class Platform
  Network = ::Network
  IO      = ::IO

  class IO
    def self.read_card(timeout)
      # TODO Implement
    end
  end

  class Audio
    def self.beep(tone, milliseconds)
      Platform::Audio._beep(tone, milliseconds)
      # TODO Implement
    end
  end

  class Runtime
    def self.execute(app)
      # TODO Scalone
      PAX._execute(app)
    end
  end

  class Display
    def self.clear
      # TODO Implement
    end

    def self.clear_line(line)
      # TODO Implement
    end

    def self.display_bitmap(path, row, column)
      # TODO Implement
    end
  end

  class System
    DEFAULT_BACKLIGHT = 1 # TODO Implement
    def self.serial
      # TODO C Implement
      Platform::System._serial
    end

    def self.backlight=(level)
      # TODO C Implement
      Platform::System._backlight=level
    end

    def self.backlight
      DEFAULT_BACKLIGHT
    end

    def self.battery
      # TODO C Implement
      Platform::System._battery
    end

    def self.reboot
      # TODO C Implement
      Platform::System._reboot
    end

    class << self
      alias_method :restart, :reboot
    end
  end

  def self.setup
    # TODO Implement
  end
end
