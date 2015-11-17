class Platform::Network::Ethernet
  RET_OK            = 0
  ERR_INVALID_PARAM = -1003
  ERR_DEV_NOT_EXIST = -1004
  ERR_DEV_NOT_OPEN  = -1006
  ERR_NOT_CONNECT   = -1012
  RET_CONNECTING    = 1

  class << self
    attr_reader :media
    @media = :ethernet
  end

  def self.init(options)
    self.start
  end

  # @brief Get access to module
  #
  # @retval RET_OK Success.
  # @retval ERR_DEV_NOT_EXIST Fail to access device.
  # @retval ERR_DEV_BUSY Already in use.
  def self.start; self._start; end

  # @brief Sets module into the state of power-on and power-off.
  #
  # @param state [int]: 1 - power-on; 0 - power-off
  #
  # @retval RET_OK Success.
  # @retval ERR_INVALID_PARAM Invalid parameter.
  # @retval ERR_DEV_NOT_EXIST Fail to access device.
  # @retval ERR_DEV_NOT_OPEN Driver loading exception or module error.
  def self.power(state); self._power(state); end

  # @brief Start connection process.
  #
  # @retval RET_OK Success.
  # @retval RET_CONNECTING During connection process.
  # @retval ERR_INVALID_PARAM Invalid parameter.
  # @retval ERR_NOT_CONNECT Fail to connect.
  # @retval ERR_DEV_NOT_OPEN Driver loading exception or module error.
  def self.connnect; self._connnect; end

  # @brief Check is connected
  #
  # @retval RET_OK Success.
  # @retval RET_CONNECTING During connection process.
  # @retval ERR_INVALID_PARAM Invalid parameter.
  # @retval ERR_NOT_CONNECT Fail to connect.
  # @retval ERR_DEV_NOT_OPEN Driver loading exception or module error.
  def self.connnected?; self._connnected?; end

  # @brief Perform disconnect
  #
  # @retval RET_OK Success.
  # @retval ERR_DEV_NOT_OPEN Driver loading exception or module error.
  def self.disconnect; self._disconnect; end

  def self.type
    Network::NET_LINK_ETH
  end
end

