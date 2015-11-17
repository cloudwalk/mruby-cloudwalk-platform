
class Platform::Network
  NET_LINK_ETH       = 1 # Ethernet
  NET_LINK_ETH1      = 2 # USB Ethernet
  NET_LINK_WL        = 3 # GPRS,CDMA,TDSCDMA
  NET_LINK_WIFI      = 4 # WiFi
  NET_LINK_PPPOE     = 5 # ADSL
  NET_LINK_MODEM     = 6 # Modem PPP
  NET_LINK_PPPDIRECT = 7 # ppp_direct
  MEDIA_GPRS         = "gprs"
  MEDIA_WIFI         = "wifi"

  class << self
    attr_accessor :interface
  end

  def self.started?
    ! @interface.nil?
  end

  def self.ping(host, timeout)
    _ping TCPSocket.getaddress(host), timeout
  end

  def self.init(media, options)
    if media == MEDIA_GPRS
      @interface = Network::Gprs
    else
      @interface = Network::Wifi
    end
    @interface.init(options)
  end

  # TODO Scalone: Raise error if problem or do not exists
  def self.dhcp_client_start
    self._dhcp_client_start(@interface.type)
  end

  def self.dhcp_client_check
    self._dhcp_client_check(@interface.type)
  end

  def self.method_missing(method, *args, &block)
    if @interface.respond_to? method
      @interface.send(method, *args, &block)
    else
      super
    end
  end
end

