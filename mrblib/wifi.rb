
class Platform::Network::Wifi
  class << self
    attr_accessor :rssi, :authentication, :password, :essid, :bssid, :channel, :mode, :cipher
    attr_reader :media
    @media = :wifi
  end

  AUTH_NONE_OPEN       = "1"
  AUTH_NONE_WEP        = "2"
  AUTH_NONE_WEP_SHARED = "3"
  AUTH_IEEE8021X       = "4"
  AUTH_WPA_PSK         = "5"
  AUTH_WPA_EAP         = "6"
  AUTH_WPA_WPA2_PSK    = "7"
  AUTH_WPA_WPA2_EAP    = "8"
  AUTH_WPA2_PSK        = "9"
  AUTH_WPA2_EAP        = "10"

  PARE_CIPHERS_NONE   = 0x00.chr
  PARE_CIPHERS_WEP64  = 0x01.chr
  PARE_CIPHERS_WEP128 = 0x02.chr
  PARE_CIPHERS_WEPX   = 0x04.chr
  PARE_CIPHERS_CCMP   = 0x10.chr
  PARE_CIPHERS_TKIP   = 0x20.chr

  MODE_IBSS    = "1"
  MODE_STATION = "0"

  AUTHENTICATIONS = {
    "open"       => AUTH_NONE_OPEN,
    "wep"        => AUTH_NONE_WEP,
    "wep_shared" => AUTH_NONE_WEP_SHARED,
    "iEEE8021X"  => AUTH_IEEE8021X,
    "wpapsk"     => AUTH_WPA_PSK,
    "wpaeap"     => AUTH_WPA_EAP,
    "wpawpa2psk" => AUTH_WPA_WPA2_PSK,
    "wpawpa2eap" => AUTH_WPA_WPA2_EAP,
    "wpa2psk"    => AUTH_WPA2_PSK,
    "wpa2eap"    => AUTH_WPA2_EAP
  }
  INVERTED_AUTHENTICATIONS = AUTHENTICATIONS.invert

  CIPHERS = {
    "none"   => PARE_CIPHERS_NONE,
    "wep64"  => PARE_CIPHERS_WEP64,
    "wep128" => PARE_CIPHERS_WEP128,
    "wepx"   => PARE_CIPHERS_WEPX,
    "ccmp"   => PARE_CIPHERS_CCMP,
    "tkip"   => PARE_CIPHERS_TKIP
  }
  INVERTED_CIPHERS = CIPHERS.invert

  MODES = {
    "station" => MODE_STATION,
    "ibss"    => MODE_IBSS
  }
  INVERTED_MODES = MODES.invert

  def self.init(options = {})
    @essid          = options[:essid].to_s
    @bssid          = options[:bssid].to_s
    @mode           = MODES[options[:mode]].to_s
    @authentication = AUTHENTICATIONS[options[:authentication]].to_s
    @cipher         = CIPHERS[options[:cipher]].to_s
    @password       = options[:password].to_s
    @channel        = options[:channel].to_s
    self.start
  end

  def self.type
    Network::NET_LINK_WIFI
  end

  def self.signal
    @rssi
  end

  def self.scan
    @aps = []
    self._scan
    @aps
  end

  def self.ap(_essid, _bssid, _channel, _mode, _rssi, _authentication, _cipher)
    @aps ||= []
    @aps << {
      :essid          => _essid,
      :bssid          => _bssid,
      :channel        => _channel.to_s,
      :mode           => INVERTED_MODES[_mode.to_s],
      :rssi           => _rssi,
      :authentication => INVERTED_AUTHENTICATIONS[_authentication.to_s],
      :cipher         => INVERTED_CIPHERS[_cipher.chr]
    }
  end
end

