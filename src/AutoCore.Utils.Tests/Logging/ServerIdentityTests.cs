using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class ServerIdentityTests
{
    [TestMethod]
    public void BuildVersion_IsNonEmpty()
    {
        Assert.IsFalse(string.IsNullOrWhiteSpace(ServerIdentity.BuildVersion),
            "Every log stream must be attributable to a build.");
    }

    [TestMethod]
    public void CommitHash_IsNeverNull()
    {
        Assert.IsNotNull(ServerIdentity.CommitHash,
            "CommitHash degrades to a placeholder when SourceLink info is absent; it is never null.");
    }

    [TestMethod]
    public void ServerInstanceId_IsStableWithinTheProcess_AndNonEmpty()
    {
        var first = ServerIdentity.ServerInstanceId;
        var second = ServerIdentity.ServerInstanceId;

        Assert.IsFalse(string.IsNullOrWhiteSpace(first));
        Assert.AreEqual(first, second,
            "The instance id distinguishes restarts; it must not change within one process.");
    }
}
