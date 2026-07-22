using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Packets;

using AutoCore.Utils.Packets;

[TestClass]
public class PacketRouterTests
{
    private enum TestOpcode : ushort
    {
        Hello = 1,
        Bye = 2,
        Extra = 3,
        AlsoExtra = 4,
        Missing = 99
    }

    private sealed class HelloPacket : IOpcodedPacket<TestOpcode>
    {
        public TestOpcode Opcode => TestOpcode.Hello;
        public int Value { get; set; }
        public void Read(BinaryReader reader) { }
        public void Write(BinaryWriter writer) { }
    }

    private sealed class ByePacket : IOpcodedPacket<TestOpcode>
    {
        public TestOpcode Opcode => TestOpcode.Bye;
        public void Read(BinaryReader reader) { }
        public void Write(BinaryWriter writer) { }
    }

    private sealed class ExtraPacket : IOpcodedPacket<TestOpcode>
    {
        public TestOpcode Opcode => TestOpcode.Extra;
        public void Read(BinaryReader reader) { }
        public void Write(BinaryWriter writer) { }
    }

    private sealed class AlsoExtraPacket : IOpcodedPacket<TestOpcode>
    {
        public TestOpcode Opcode => TestOpcode.AlsoExtra;
        public void Read(BinaryReader reader) { }
        public void Write(BinaryWriter writer) { }
    }

    private sealed class CleanHandlerTarget
    {
        public HelloPacket LastHello { get; private set; }
        public int HelloCount { get; private set; }
        public int ByeCount { get; private set; }

        [PacketHandler(TestOpcode.Hello)]
        public void OnHello(HelloPacket packet)
        {
            LastHello = packet;
            HelloCount++;
        }

        [PacketHandler(TestOpcode.Bye)]
        public void OnBye(ByePacket packet) => ByeCount++;
    }

    private sealed class MultiAttrHandlerTarget
    {
        public int CallCount { get; private set; }

        [PacketHandler(TestOpcode.Extra)]
        [PacketHandler(TestOpcode.AlsoExtra)]
        public void OnEither(IOpcodedPacket<TestOpcode> packet) => CallCount++;
    }

    private sealed class BadHandlerTarget
    {
        [PacketHandler(TestOpcode.Hello)]
        public void NoParameters() { }
    }

    private sealed class UnknownPacket : IOpcodedPacket<TestOpcode>
    {
        public TestOpcode Opcode => TestOpcode.Missing;
        public void Read(BinaryReader reader) { }
        public void Write(BinaryWriter writer) { }
    }

    [TestMethod]
    public void Constructor_RegistersAttributedHandlers()
    {
        var router = new PacketRouter<CleanHandlerTarget, TestOpcode>();

        Assert.AreEqual(typeof(HelloPacket), router.GetPacketType(TestOpcode.Hello));
        Assert.AreEqual(typeof(ByePacket), router.GetPacketType(TestOpcode.Bye));
    }

    [TestMethod]
    public void RoutePacket_InvokesMatchingHandler()
    {
        var router = new PacketRouter<CleanHandlerTarget, TestOpcode>();
        var target = new CleanHandlerTarget();
        var packet = new HelloPacket { Value = 42 };

        router.RoutePacket(target, packet);

        Assert.AreEqual(1, target.HelloCount);
        Assert.AreSame(packet, target.LastHello);
        Assert.AreEqual(0, target.ByeCount);
    }

    [TestMethod]
    public void RoutePacket_RoutesDifferentOpcodesIndependently()
    {
        var router = new PacketRouter<CleanHandlerTarget, TestOpcode>();
        var target = new CleanHandlerTarget();

        router.RoutePacket(target, new HelloPacket());
        router.RoutePacket(target, new ByePacket());
        router.RoutePacket(target, new HelloPacket());

        Assert.AreEqual(2, target.HelloCount);
        Assert.AreEqual(1, target.ByeCount);
    }

    [TestMethod]
    public void RoutePacket_UnknownOpcode_DoesNotThrow()
    {
        var router = new PacketRouter<CleanHandlerTarget, TestOpcode>();
        var target = new CleanHandlerTarget();

        router.RoutePacket(target, new UnknownPacket());

        Assert.AreEqual(0, target.HelloCount);
        Assert.AreEqual(0, target.ByeCount);
    }

    [TestMethod]
    public void GetPacketType_UnknownOpcode_ReturnsNull()
    {
        var router = new PacketRouter<CleanHandlerTarget, TestOpcode>();
        Assert.IsNull(router.GetPacketType(TestOpcode.Missing));
    }

    [TestMethod]
    public void SetupHandlers_MethodWithoutParameters_Throws()
    {
        var ex = Assert.ThrowsException<Exception>(() => new PacketRouter<BadHandlerTarget, TestOpcode>());
        Assert.IsTrue(ex.Message.Contains("Invalid PacketHandler", StringComparison.Ordinal));
    }

    [TestMethod]
    public void MultipleAttributes_RegisterSameHandlerForMultipleOpcodes()
    {
        var router = new PacketRouter<MultiAttrHandlerTarget, TestOpcode>();
        var target = new MultiAttrHandlerTarget();

        Assert.AreEqual(typeof(IOpcodedPacket<TestOpcode>), router.GetPacketType(TestOpcode.Extra));
        Assert.AreEqual(typeof(IOpcodedPacket<TestOpcode>), router.GetPacketType(TestOpcode.AlsoExtra));

        router.RoutePacket(target, new ExtraPacket());
        router.RoutePacket(target, new AlsoExtraPacket());
        Assert.AreEqual(2, target.CallCount);
    }

    [TestMethod]
    public void PacketData_ToString_ContainsTypeAndHandlerName()
    {
        var router = new PacketRouter<CleanHandlerTarget, TestOpcode>();
        // Build PacketData from a real method delegate like SetupHandlers does
        var method = typeof(CleanHandlerTarget).GetMethod(nameof(CleanHandlerTarget.OnHello))!;
        var del = method.CreateDelegate(typeof(Action<CleanHandlerTarget, HelloPacket>));
        var data = new PacketRouter<CleanHandlerTarget, TestOpcode>.PacketData(typeof(HelloPacket), del);

        var text = data.ToString();
        Assert.IsTrue(text.Contains("HelloPacket", StringComparison.Ordinal));
        Assert.IsTrue(text.Contains("OnHello", StringComparison.Ordinal));
        Assert.IsTrue(text.Contains(typeof(CleanHandlerTarget).FullName!, StringComparison.Ordinal));
        Assert.AreEqual(typeof(HelloPacket), data.Type);
        Assert.AreSame(del, data.Handler);

        // silence unused
        _ = router;
    }

    [TestMethod]
    public void PacketHandlerAttribute_GetOpcode_ReturnsStoredValue()
    {
        var attr = new PacketHandlerAttribute(TestOpcode.Hello);
        Assert.AreEqual(TestOpcode.Hello, attr.GetOpcode<TestOpcode>());
    }

    [TestMethod]
    public void SetupHandlers_CalledTwice_ThrowsOnDuplicateOpcode()
    {
        var router = new PacketRouter<CleanHandlerTarget, TestOpcode>();
        Assert.ThrowsException<ArgumentException>(() => router.SetupHandlers());
    }
}
