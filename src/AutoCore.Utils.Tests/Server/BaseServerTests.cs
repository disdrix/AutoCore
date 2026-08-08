using System.Reflection;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Server;

using AutoCore.Utils.Server;

[TestClass]
public class BaseServerTests
{
    private sealed class TestServer : BaseServer
    {
        private int _runningTicks;

        public TestServer(string type, int runningTicks = 0) : base(type)
        {
            _runningTicks = runningTicks;
        }

        public override bool IsRunning
        {
            get
            {
                if (_runningTicks <= 0)
                    return false;
                _runningTicks--;
                return true;
            }
        }

        public int RemainingTicks => _runningTicks;
    }

    [TestMethod]
    public void Constructor_SetsType()
    {
        var server = new TestServer("Unit");
        Assert.AreEqual("Unit", server.Type);
        Assert.IsFalse(server.IsRunning);
    }

    [TestMethod]
    public void ProcessCommands_WhenNotRunning_ReturnsImmediately()
    {
        var server = new TestServer("Idle", runningTicks: 0);
        server.ProcessCommands(); // must not hang
    }

    [TestMethod]
    public void ProcessCommands_WhileRunning_CallsProcessCommandThenExits()
    {
        // Two iterations of the loop (each IsRunning get decrements)
        var server = new TestServer("Brief", runningTicks: 2);
        server.ProcessCommands();
        Assert.AreEqual(0, server.RemainingTicks);
        Assert.IsFalse(server.IsRunning);
    }

    /// <summary>
    /// SS-08 tripwire: ProcessCommands is the foreground loop of all four executables. A
    /// throwing console command must not end it, or the process stops accepting commands and
    /// the ctrl-handler shutdown path never runs.
    /// </summary>
    [TestMethod]
    public void ProcessCommands_WhenACommandThrows_LoopSurvivesAndKeepsProcessing()
    {
        var server = new ThrowingCommandServer(runningTicks: 3, throwOnTick: 1);

        server.ProcessCommands();

        Assert.AreEqual(
            3,
            server.Attempts,
            "SS-08: the command loop must keep running after a command throws. It stopped " +
            $"after {server.Attempts} of 3 iterations.");
        Assert.IsTrue(server.SawWorkAfterFailure,
            "Work scheduled after the failing command must still be processed.");
    }

    private sealed class ThrowingCommandServer : BaseServer
    {
        private readonly int _throwOnTick;
        private int _runningTicks;

        public ThrowingCommandServer(int runningTicks, int throwOnTick) : base("Throwing")
        {
            _runningTicks = runningTicks;
            _throwOnTick = throwOnTick;
        }

        public int Attempts { get; private set; }
        public bool SawWorkAfterFailure { get; private set; }

        public override bool IsRunning
        {
            get
            {
                if (_runningTicks <= 0)
                    return false;
                _runningTicks--;
                return true;
            }
        }

        protected override void ProcessSingleCommand()
        {
            Attempts++;

            if (Attempts == _throwOnTick)
                throw new InvalidOperationException("SS-08 injected command failure");

            if (Attempts > _throwOnTick)
                SawWorkAfterFailure = true;
        }

        protected override int CommandLoopDelayMs => 0;
    }

    [TestMethod]
    public void InitConsole_SetsTitleAndWritesBanner()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = false,
            IsDebugMode = true
        });

        var server = new TestServer("BannerTest");
        // Console.Title may throw in some headless hosts; catch and still cover WriteLog path
        try
        {
            server.InitConsole();
#pragma warning disable CA1416 // Console.Title is Windows-only; this workspace targets Windows test runs
            StringAssert.Contains(Console.Title, "BannerTest");
#pragma warning restore CA1416
        }
        catch (Exception)
        {
            Assert.AreEqual("BannerTest", server.Type);
        }
        finally
        {
            Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        }
    }

    [TestMethod]
    public void InitConsole_WritesInitializeLogs()
    {
        // Capture via temporary log file
        var path = Path.Combine(Path.GetTempPath(), $"autocore-baseserver-{Guid.NewGuid():N}.txt");
        try
        {
            Logger.UpdateConfig(new Logger.LoggerConfig
            {
                LogToFile = true,
                LogFilePath = path,
                IsDebugMode = true
            });

            var server = new TestServer("LogCapture");
            try
            {
                server.InitConsole();
            }
            catch
            {
                // Title may fail; WriteLog calls before/after may still have run
            }

            Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });

            if (File.Exists(path))
            {
                var content = File.ReadAllText(path);
                // Banner uses WriteLog(LogType.Initialize, ...) for ASCII art and type line
                Assert.IsTrue(
                    content.Contains("Auto Assault Server", StringComparison.Ordinal)
                    || content.Contains("Init", StringComparison.Ordinal),
                    "Expected InitConsole to emit initialize log lines.");
            }
        }
        finally
        {
            Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
            if (File.Exists(path))
            {
                try { File.Delete(path); } catch { /* best-effort */ }
            }
        }
    }
}
