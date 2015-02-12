class Addrinfo
  def self.foreach(nodename, service, family=nil, socktype=nil, protocol=nil, flags=0, &block)
    nodename = IPSocket.getaddress(nodename)
    a = self.getaddrinfo(nodename, service, family, socktype, protocol, flags)
    a.each { |ai| block.call(ai) }
    a
  end
end
