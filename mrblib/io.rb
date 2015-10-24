class Platform
  IO = ::IO
  class IO
    DEFAULT_TIMEOUT = 30000

    class << self
      attr_accessor :timeout
    end
    self.timeout = DEFAULT_TIMEOUT
  end
end

