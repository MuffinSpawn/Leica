import CESAPI

status = b'\x00\x00\x00\x00'

enc = CESAPI.Encoder()
enc.Initialize()
print(enc.getPacket())
packet = b''.join((b'\x10', enc.getPacket()[1:], status))
dec = CESAPI.Decoder()
print(packet)
message = dec.decode(packet)
ans = message.getCommand()
print(ans.packetHeader.lPacketSize)
print(ans.packetHeader.type)
print(ans.command)
print(ans.status)

enc.GetAT4xxInfo()
print(enc.getPacket())
packet = b''.join((b'\x10', enc.getPacket()[1:], status))
print(packet)
dec = CESAPI.Decoder()
message = dec.decode(packet)
ans = message.getCommand()
print(ans.packetHeader.lPacketSize)
print(ans.packetHeader.type)
print(ans.command)
print(ans.status)
