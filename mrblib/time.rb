class Time
  def hwclock
    Platform::System.hwclock(self.year, self.month, self.day, self.hour, self.min, self.sec)
  end
end

