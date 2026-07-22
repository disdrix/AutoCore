using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Net;
using AutoCore.Utils.Packets;

namespace AutoCore.Communicator.Tests.Packets;

internal static class PacketTestHelper
{
    public static byte[] WritePacket(IOpcodedPacket<CommunicatorOpcode> packet)
    {
        using var ms = new MemoryStream();
        using var bw = new BinaryWriter(ms);
        packet.Write(bw);
        return ms.ToArray();
    }

    public static void AssertTruncatedThrows(Action readAction)
    {
        try
        {
            readAction();
            Assert.Fail("Expected truncated buffer to throw.");
        }
        catch (EndOfStreamException)
        {
            // expected
        }
        catch (ArgumentException)
        {
            // expected for some partial reads (e.g. IPAddress)
        }
        catch (IOException)
        {
            // expected alternate EOF shape
        }
    }

    public static ServerData SampleServerData(byte id = 7) => new()
    {
        Id = id,
        Password = "secret-pass",
        Address = IPAddress.Parse("192.168.1.50"),
        Port = 27001
    };

    public static ServerInfo SampleServerInfo(byte serverId = 7) => new()
    {
        ServerId = serverId,
        Ip = IPAddress.Parse("10.0.0.5"),
        Port = 27001,
        AgeLimit = 18,
        PKFlag = 1,
        CurrentPlayers = 12,
        MaxPlayers = 200,
        Status = 1,
        Password = "info-pass"
    };

    public static RedirectRequest SampleRedirectRequest() => new()
    {
        AccountId = 42,
        Username = "tester",
        Email = "tester@example.com",
        OneTimeKey = 0xA1B2C3D4
    };
}
