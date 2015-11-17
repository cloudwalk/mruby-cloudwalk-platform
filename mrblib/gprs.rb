class Platform::Network::Gprs
  class << self
    attr_accessor :password, :user, :apn
    attr_reader :media
    @media = :gprs
  end

  def self.init(options = {})
    @apn      = options[:apn]
    @user     = options[:user]
    @password = options[:password]
    self.start
  end

  def self.type
    Network::NET_LINK_WL
  end
end
