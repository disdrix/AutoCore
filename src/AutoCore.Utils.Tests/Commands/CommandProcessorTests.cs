using System.Reflection;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Commands;

using AutoCore.Utils.Commands;

[TestClass]
public class CommandProcessorTests
{
    private readonly List<string> _registered = new();
    private static readonly FieldInfo CommandsField = typeof(CommandProcessor)
        .GetField("Commands", BindingFlags.NonPublic | BindingFlags.Static)!;
    private static readonly FieldInfo TrimScopeField = typeof(CommandProcessor)
        .GetField("TrimScope", BindingFlags.NonPublic | BindingFlags.Static)!;

    private static Dictionary<string, Action<string[]>> Commands =>
        (Dictionary<string, Action<string[]>>)CommandsField.GetValue(null)!;

    private static bool TrimScope
    {
        get => (bool)TrimScopeField.GetValue(null)!;
        set => TrimScopeField.SetValue(null, value);
    }

    [TestInitialize]
    public void Init()
    {
        // Restore default scope-trimming so tests are order-independent.
        TrimScope = true;
    }

    [TestCleanup]
    public void Cleanup()
    {
        foreach (var name in _registered)
        {
            Commands.Remove(name);
            // Also remove possible untrimmed form
            if (name.Contains('.'))
                Commands.Remove(name[(name.IndexOf('.') + 1)..]);
            else
                Commands.Remove(name);
        }

        _registered.Clear();
        TrimScope = true;
    }

    private void Track(string storedName) => _registered.Add(storedName);

    [TestMethod]
    public void RegisterCommand_StoresHandler_UnderPlainName()
    {
        string[] captured = null;
        CommandProcessor.RegisterCommand("ut_cp_plain", parts => captured = parts);
        Track("ut_cp_plain");

        Assert.IsTrue(Commands.ContainsKey("ut_cp_plain"));
        Commands["ut_cp_plain"](new[] { "ut_cp_plain", "a", "b" });
        CollectionAssert.AreEqual(new[] { "ut_cp_plain", "a", "b" }, captured);
    }

    [TestMethod]
    public void RegisterCommand_WithScopePrefix_TrimsByDefault()
    {
        CommandProcessor.RegisterCommand("mod.ut_cp_trim", _ => { });
        Track("ut_cp_trim");

        Assert.IsTrue(Commands.ContainsKey("ut_cp_trim"));
        Assert.IsFalse(Commands.ContainsKey("mod.ut_cp_trim"));
    }

    [TestMethod]
    public void RegisterCommand_SameName_OverwritesHandler()
    {
        var first = 0;
        var second = 0;
        CommandProcessor.RegisterCommand("ut_cp_ow", _ => first++);
        Track("ut_cp_ow");
        CommandProcessor.RegisterCommand("ut_cp_ow", _ => second++);

        Commands["ut_cp_ow"](new[] { "ut_cp_ow" });
        Assert.AreEqual(0, first);
        Assert.AreEqual(1, second);
    }

    [TestMethod]
    public void RemoveCommand_WithScopePrefix_RemovesTrimmedName()
    {
        CommandProcessor.RegisterCommand("mod.ut_cp_rm", _ => { });
        Track("ut_cp_rm");
        Assert.IsTrue(Commands.ContainsKey("ut_cp_rm"));

        CommandProcessor.RemoveCommand("mod.ut_cp_rm");
        Assert.IsFalse(Commands.ContainsKey("ut_cp_rm"));
    }

    [TestMethod]
    public void RemoveCommand_Missing_DoesNotThrow()
    {
        CommandProcessor.RemoveCommand("ut_cp_never_registered_xyz");
    }

    [TestMethod]
    public void UseScopes_DisablesTrimOnRegisterAndRemove()
    {
        CommandProcessor.UseScopes();
        Assert.IsFalse(TrimScope);

        CommandProcessor.RegisterCommand("full.ut_cp_scope", _ => { });
        Track("full.ut_cp_scope");

        Assert.IsTrue(Commands.ContainsKey("full.ut_cp_scope"));
        Assert.IsFalse(Commands.ContainsKey("ut_cp_scope"));

        CommandProcessor.RemoveCommand("full.ut_cp_scope");
        Assert.IsFalse(Commands.ContainsKey("full.ut_cp_scope"));
    }

    [TestMethod]
    public void ProcessCommand_WhenNoConsoleInput_DoesNotThrow()
    {
        CommandProcessor.ProcessCommand();
        CommandProcessor.ProcessCommand();
    }

    [TestMethod]
    public void Execute_DispatchesRegisteredCommand()
    {
        string[] captured = null;
        CommandProcessor.RegisterCommand("ut_cp_dispatch", parts => captured = parts);
        Track("ut_cp_dispatch");

        CommandProcessor.Execute("ut_cp_dispatch x y");
        CollectionAssert.AreEqual(new[] { "ut_cp_dispatch", "x", "y" }, captured);
    }

    [TestMethod]
    public void Execute_TrimsScopeOnCommandName()
    {
        string[] captured = null;
        CommandProcessor.RegisterCommand("ut_cp_scope_run", parts => captured = parts);
        Track("ut_cp_scope_run");

        CommandProcessor.Execute("mod.ut_cp_scope_run arg1");
        CollectionAssert.AreEqual(new[] { "ut_cp_scope_run", "arg1" }, captured);
    }

    [TestMethod]
    public void Execute_InvalidCommand_DoesNotThrow()
    {
        CommandProcessor.Execute("ut_cp_invalid_zzz");
    }

    [TestMethod]
    public void Execute_Whitespace_IsNoOp()
    {
        CommandProcessor.Execute("   ");
        CommandProcessor.Execute(null);
        CommandProcessor.Execute("");
    }

    [TestMethod]
    public void Execute_WithScopesDisabled_UsesFullName()
    {
        CommandProcessor.UseScopes();
        var hit = false;
        CommandProcessor.RegisterCommand("full.ut_cp_line", _ => hit = true);
        Track("full.ut_cp_line");

        CommandProcessor.Execute("full.ut_cp_line");
        Assert.IsTrue(hit);
    }

    [TestMethod]
    public void UseScopes_ReturnsFalse()
    {
        // Method returns the assigned value (false).
        Assert.IsFalse(CommandProcessor.UseScopes());
        Assert.IsFalse(TrimScope);
    }
}
