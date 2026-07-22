using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Packets;

using AutoCore.Utils.Packets;

[TestClass]
public class PacketQueueTests
{
    private sealed class DummyPacket : IBasePacket
    {
        public int Id { get; init; }
        public void Read(BinaryReader reader) { }
        public void Write(BinaryWriter writer) { }
    }

    [TestMethod]
    public void PopIncoming_WhenEmpty_ReturnsNull()
    {
        var queue = new PacketQueue();
        Assert.IsNull(queue.PopIncoming());
    }

    [TestMethod]
    public void PopOutgoing_WhenEmpty_ReturnsNull()
    {
        var queue = new PacketQueue();
        Assert.IsNull(queue.PopOutgoing());
    }

    [TestMethod]
    public void EnqueueIncoming_ThenPop_ReturnsInFifoOrder()
    {
        var queue = new PacketQueue();
        var a = new DummyPacket { Id = 1 };
        var b = new DummyPacket { Id = 2 };

        queue.EnqueueIncoming(a);
        queue.EnqueueIncoming(b);

        Assert.AreSame(a, queue.PopIncoming());
        Assert.AreSame(b, queue.PopIncoming());
        Assert.IsNull(queue.PopIncoming());
    }

    [TestMethod]
    public void EnqueueOutgoing_ThenPop_ReturnsInFifoOrder()
    {
        var queue = new PacketQueue();
        var a = new DummyPacket { Id = 10 };
        var b = new DummyPacket { Id = 20 };

        queue.EnqueueOutgoing(a);
        queue.EnqueueOutgoing(b);

        Assert.AreSame(a, queue.PopOutgoing());
        Assert.AreSame(b, queue.PopOutgoing());
        Assert.IsNull(queue.PopOutgoing());
    }

    [TestMethod]
    public void IncomingAndOutgoing_AreIndependent()
    {
        var queue = new PacketQueue();
        var incoming = new DummyPacket { Id = 1 };
        var outgoing = new DummyPacket { Id = 2 };

        queue.EnqueueIncoming(incoming);
        queue.EnqueueOutgoing(outgoing);

        Assert.AreSame(outgoing, queue.PopOutgoing());
        Assert.IsNull(queue.PopOutgoing());
        Assert.AreSame(incoming, queue.PopIncoming());
        Assert.IsNull(queue.PopIncoming());
    }
}
