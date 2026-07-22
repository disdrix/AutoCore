using AutoCore.Auth.Crypto;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Auth.Tests.Crypto;

[TestClass]
public class BlowfishTests
{
    [TestMethod]
    public void EncryptDecrypt_RoundTripsEightByteBlock()
    {
        var original = new byte[] { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF };
        var data = (byte[])original.Clone();

        Blowfish.Encrypt(data);
        CollectionAssert.AreNotEqual(original, data);

        Blowfish.Decrypt(data);
        CollectionAssert.AreEqual(original, data);
    }

    [TestMethod]
    public void EncryptDecrypt_RoundTripsMultipleBlocksWithOffset()
    {
        var buffer = new byte[24];
        for (var i = 0; i < buffer.Length; i++)
            buffer[i] = (byte)(i + 1);

        var working = (byte[])buffer.Clone();
        Blowfish.Encrypt(working, 8, 16);
        CollectionAssert.AreEqual(buffer.AsSpan(0, 8).ToArray(), working.AsSpan(0, 8).ToArray());
        CollectionAssert.AreNotEqual(buffer.AsSpan(8, 16).ToArray(), working.AsSpan(8, 16).ToArray());

        Blowfish.Decrypt(working, 8, 16);
        CollectionAssert.AreEqual(buffer, working);
    }

    [TestMethod]
    public void Encrypt_ZeroLength_DoesNotModifyBuffer()
    {
        var data = new byte[] { 0xAA, 0xBB, 0xCC, 0xDD, 0x11, 0x22, 0x33, 0x44 };
        var copy = (byte[])data.Clone();
        Blowfish.Encrypt(data, 0, 0);
        CollectionAssert.AreEqual(copy, data);
    }

    [TestMethod]
    public void Encrypt_IsDeterministicForSameInput()
    {
        var a = new byte[] { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80 };
        var b = (byte[])a.Clone();
        Blowfish.Encrypt(a);
        Blowfish.Encrypt(b);
        CollectionAssert.AreEqual(a, b);
    }

    [TestMethod]
    public void Decrypt_AfterEncrypt_RestoresKnownPlaintext()
    {
        // Known plaintext covering both F-function S-box paths.
        var plain = new byte[]
        {
            0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
            0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
        };
        var data = (byte[])plain.Clone();
        Blowfish.Encrypt(data);
        Blowfish.Decrypt(data);
        CollectionAssert.AreEqual(plain, data);
    }
}
