namespace AutoCore.Utils.Server;

using AutoCore.Utils.Commands;
using AutoCore.Utils.Reliability;

public abstract class BaseServer
{
    public abstract bool IsRunning { get; }
    public string Type { get; }

    public BaseServer(string type) => Type = type;

    /// <summary>Pause between command-loop iterations. Overridable so tests need not sleep.</summary>
    protected virtual int CommandLoopDelayMs => 25;

    /// <summary>
    /// Reads and dispatches one console command. Overridable as a test seam so the loop can
    /// be exercised without a real console.
    /// </summary>
    protected virtual void ProcessSingleCommand() => CommandProcessor.ProcessCommand();

    /// <summary>
    /// The foreground loop of every AutoCore executable; <c>Main</c> blocks here until shutdown.
    /// <para>
    /// SS-08: each iteration is isolated. Previously an exception from a console command (or
    /// from reading the console) ended this loop, after which the process stayed alive but
    /// accepted no further commands and never reached its shutdown path.
    /// </para>
    /// </summary>
    public void ProcessCommands()
    {
        while (IsRunning)
        {
            Guard.Run($"{Type} server command loop", ProcessSingleCommand);

            var delay = CommandLoopDelayMs;

            if (delay > 0)
                Thread.Sleep(delay);
        }
    }

    public void InitConsole()
    {
        Console.Title = $"AutoCore - {Type} Server";

        Logger.WriteLog(LogType.Initialize, @"                _         ______              ");
        Logger.WriteLog(LogType.Initialize, @"     /\        | |       / ____|              ");
        Logger.WriteLog(LogType.Initialize, @"    /  \  _   _| |_ ___ | |     ___  _ __ ___ ");
        Logger.WriteLog(LogType.Initialize, @"   / /\ \| | | | __/ _ \| |    / _ \| '__/ _ \");
        Logger.WriteLog(LogType.Initialize, @"  / ____ \ |_| | || (_) | |___| (_) | | |  __/");
        Logger.WriteLog(LogType.Initialize, @" /_/    \_\__,_|\__\___/ \_____\___/|_|  \___|");
        Logger.WriteLog(LogType.Initialize, @" Auto Assault Server - {0}", Type);
        Logger.WriteLog(LogType.Initialize, "");
    }
}
