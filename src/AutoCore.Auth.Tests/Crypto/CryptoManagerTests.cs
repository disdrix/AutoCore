using AutoCore.Auth.Crypto;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Auth.Tests.Crypto;

[TestClass]
public class CryptoManagerTests
{
    [TestMethod]
    public void EncryptDecrypt_RoundTripsExactMultipleOfEight()
    {
        var payload = new byte[] { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
        var buffer = new byte[64];
        Array.Copy(payload, buffer, payload.Length);
        var length = payload.Length;

        CryptoManager.Encrypt(buffer, 0, ref length, buffer.Length);
        Assert.AreEqual(16, length); // 8 data + 8 checksum block

        Assert.IsTrue(CryptoManager.Decrypt(buffer, 0, length));
        CollectionAssert.AreEqual(payload, buffer.AsSpan(0, 8).ToArray());
    }

    [TestMethod]
    public void Encrypt_PadsNonMultipleOfEightWith0xCC()
    {
        var buffer = new byte[64];
        buffer[0] = 0xAA;
        buffer[1] = 0xBB;
        buffer[2] = 0xCC; // length 3 -> pad to 8
        var length = 3;

        CryptoManager.Encrypt(buffer, 0, ref length, buffer.Length);
        Assert.AreEqual(16, length);

        Assert.IsTrue(CryptoManager.Decrypt(buffer, 0, length));
        Assert.AreEqual(0xAA, buffer[0]);
        Assert.AreEqual(0xBB, buffer[1]);
        // remaining pad bytes after decrypt (0xCC fill)
        Assert.AreEqual(0xCC, buffer[2]);
        Assert.AreEqual(0xCC, buffer[3]);
        Assert.AreEqual(0xCC, buffer[4]);
        Assert.AreEqual(0xCC, buffer[5]);
        Assert.AreEqual(0xCC, buffer[6]);
        Assert.AreEqual(0xCC, buffer[7]);
    }

    [TestMethod]
    public void Encrypt_WithOffset_PreservesPrefix()
    {
        // Production auth path always uses offset 0; offset!=0 encrypt still must not touch the prefix.
        // (Decrypt checksum verification assumes offset 0 — see cold-path note in work-stream summary.)
        var buffer = new byte[64];
        buffer[0] = 0xFE;
        buffer[1] = 0xED;
        buffer[4] = 0x11;
        buffer[5] = 0x22;
        buffer[6] = 0x33;
        buffer[7] = 0x44;
        var length = 4;

        CryptoManager.Encrypt(buffer, 4, ref length, buffer.Length - 4);
        Assert.AreEqual(0xFE, buffer[0]);
        Assert.AreEqual(0xED, buffer[1]);
        Assert.AreEqual(16, length);
        // Ciphertext at offset 4 must differ from plaintext input region.
        Assert.IsFalse(buffer[4] == 0x11 && buffer[5] == 0x22 && buffer[6] == 0x33 && buffer[7] == 0x44);
    }

    [TestMethod]
    public void Decrypt_ThrowsWhenLengthNotMultipleOfEight()
    {
        var data = new byte[10];
        Assert.ThrowsException<ArgumentOutOfRangeException>(() => CryptoManager.Decrypt(data, 0, 10));
    }

    [TestMethod]
    public void Encrypt_ThrowsWhenExceedsMaxLength()
    {
        var data = new byte[16];
        var length = 8;
        // length becomes 16 after padding+checksum, maxLength 15 fails
        Assert.ThrowsException<ArgumentOutOfRangeException>(() =>
            CryptoManager.Encrypt(data, 0, ref length, 15));
    }

    [TestMethod]
    public void Decrypt_ReturnsFalseWhenChecksumCorrupted()
    {
        var buffer = new byte[64];
        for (var i = 0; i < 8; i++)
            buffer[i] = (byte)i;
        var length = 8;
        CryptoManager.Encrypt(buffer, 0, ref length, buffer.Length);

        // Flip a ciphertext byte so decrypted checksum fails.
        buffer[0] ^= 0xFF;
        Assert.IsFalse(CryptoManager.Decrypt(buffer, 0, length));
    }

    [TestMethod]
    public void EncryptDecrypt_EmptyPayload_AddsChecksumBlockOnly()
    {
        var buffer = new byte[32];
        var length = 0;
        CryptoManager.Encrypt(buffer, 0, ref length, buffer.Length);
        Assert.AreEqual(8, length);
        Assert.IsTrue(CryptoManager.Decrypt(buffer, 0, length));
    }
}
