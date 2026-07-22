using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sector.Tests.Dev;

using AutoCore.Sector.Dev;

[TestClass]
public class DevPlayerSelectorTests
{
    [TestMethod]
    public void Select_SingleCharacter_NoName_ReturnsThatCharacter()
    {
        var character = Character(10, "Floppy");

        var selected = DevPlayerSelector.Select(new[] { character }, null);

        Assert.AreSame(character, selected);
        Assert.AreEqual(10L, selected.ConnectionId);
        Assert.AreEqual("admin", selected.AccountName);
        Assert.AreEqual("Floppy", selected.CharacterName);
        Assert.AreEqual(52L, selected.CharacterCoid);
        Assert.IsNull(selected.Connection);
    }

    [TestMethod]
    public void Select_WhitespaceName_TreatedAsUnspecified()
    {
        var character = Character(1, "Only");

        var selected = DevPlayerSelector.Select(new[] { character }, "   ");

        Assert.AreSame(character, selected);
    }

    [TestMethod]
    public void Select_ByName_IsCaseInsensitive()
    {
        var characters = new[] { Character(1, "Floppy"), Character(2, "Other") };

        var selected = DevPlayerSelector.Select(characters, "other");

        Assert.AreEqual("Other", selected.CharacterName);
        Assert.AreEqual(2L, selected.ConnectionId);
    }

    [TestMethod]
    public void Select_MultipleWithoutName_Throws()
    {
        var characters = new[] { Character(1, "A"), Character(2, "B") };

        var ex = Assert.ThrowsException<InvalidOperationException>(
            () => DevPlayerSelector.Select(characters, null));

        StringAssert.Contains(ex.Message, "Multiple connected characters");
    }

    [TestMethod]
    public void Select_EmptyListWithoutName_Throws()
    {
        var ex = Assert.ThrowsException<InvalidOperationException>(
            () => DevPlayerSelector.Select(Array.Empty<DevConnectedCharacter>(), null));

        Assert.AreEqual("No connected characters were found.", ex.Message);
    }

    [TestMethod]
    public void Select_MissingName_Throws()
    {
        var ex = Assert.ThrowsException<InvalidOperationException>(
            () => DevPlayerSelector.Select(new[] { Character(1, "Floppy") }, "Missing"));

        Assert.AreEqual("No connected character named 'Missing' was found.", ex.Message);
    }

    [TestMethod]
    public void Select_DuplicateNames_Throws()
    {
        var characters = new[] { Character(1, "Twin"), Character(2, "Twin") };

        var ex = Assert.ThrowsException<InvalidOperationException>(
            () => DevPlayerSelector.Select(characters, "Twin"));

        StringAssert.Contains(ex.Message, "Multiple connected characters named 'Twin'");
    }

    private static DevConnectedCharacter Character(long connectionId, string name)
    {
        return new DevConnectedCharacter(connectionId, "admin", name, 52, null);
    }
}
