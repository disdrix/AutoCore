using System.Net.Sockets;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Extensions;

using AutoCore.Utils.Extensions;

[TestClass]
public class SocketAsyncEventArgsExtensionsTests
{
    private sealed class Token
    {
        public int Id { get; init; }
    }

    [TestMethod]
    public void GetUserToken_WhenMatchingType_ReturnsToken()
    {
        using var args = new SocketAsyncEventArgs();
        var token = new Token { Id = 42 };
        args.UserToken = token;

        var result = args.GetUserToken<Token>();
        Assert.AreSame(token, result);
        Assert.AreEqual(42, result.Id);
    }

    [TestMethod]
    public void GetUserToken_WhenNull_ReturnsNull()
    {
        using var args = new SocketAsyncEventArgs();
        args.UserToken = null;
        Assert.IsNull(args.GetUserToken<Token>());
    }

    [TestMethod]
    public void GetUserToken_WhenWrongType_ReturnsNull()
    {
        using var args = new SocketAsyncEventArgs();
        args.UserToken = "not-a-token";
        Assert.IsNull(args.GetUserToken<Token>());
    }
}
