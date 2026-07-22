using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Memory;

using AutoCore.Utils.Memory;

[TestClass]
public class SingletonTests
{
    public sealed class SampleSingleton : Singleton<SampleSingleton>
    {
        public int Value { get; set; }
        public Guid Id { get; } = Guid.NewGuid();
    }

    public sealed class AnotherSingleton : Singleton<AnotherSingleton>
    {
        public string Name { get; set; } = "default";
    }

    [TestMethod]
    public void Instance_ReturnsNonNull()
    {
        Assert.IsNotNull(SampleSingleton.Instance);
    }

    [TestMethod]
    public void Instance_IsSameAcrossAccesses()
    {
        var a = SampleSingleton.Instance;
        var b = SampleSingleton.Instance;
        Assert.AreSame(a, b);
        Assert.AreEqual(a.Id, b.Id);
    }

    [TestMethod]
    public void Instance_StateIsShared()
    {
        SampleSingleton.Instance.Value = 123;
        Assert.AreEqual(123, SampleSingleton.Instance.Value);
        SampleSingleton.Instance.Value = 0;
    }

    [TestMethod]
    public void DifferentSingletonTypes_HaveIndependentInstances()
    {
        var a = SampleSingleton.Instance;
        var b = AnotherSingleton.Instance;
        Assert.IsNotNull(a);
        Assert.IsNotNull(b);
        Assert.AreNotSame((object)a, b);
        AnotherSingleton.Instance.Name = "x";
        Assert.AreEqual("x", AnotherSingleton.Instance.Name);
        AnotherSingleton.Instance.Name = "default";
    }
}
