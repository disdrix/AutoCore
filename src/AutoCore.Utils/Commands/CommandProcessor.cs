namespace AutoCore.Utils.Commands;

using AutoCore.Utils;
using AutoCore.Utils.Reliability;

public static class CommandProcessor
{
    private static readonly Dictionary<string, Action<string[]>> Commands = new();
    private static bool TrimScope = true;

    public static bool UseScopes() => TrimScope = false;

    public static void ProcessCommand()
    {
        Execute(ReadCommand());
    }

    /// <summary>
    /// Dispatch a command line without reading the console (unit-test and scripted use).
    /// </summary>
    public static void Execute(string command)
    {
        if (string.IsNullOrWhiteSpace(command))
            return;

        var parts = command.Split(' ');
        if (parts.Length < 1)
            return;

        if (TrimScope && parts[0].Contains('.'))
            parts[0] = parts[0][(parts[0].IndexOf(".") + 1)..];

        if (Commands.TryGetValue(parts[0], out var value))
        {
            // SS-08: a console command is operator-supplied input executed on the server's
            // main thread. Isolate the handler so a bad argument fails the command, not the
            // command loop. The failure is logged with its full stack trace.
            Guard.Run($"command '{parts[0]}'", () => value(parts));
            return;
        }

        Logger.WriteLog(LogType.Command, $"Invalid command: {command}");
    }

    private static string ReadCommand()
    {
        var command = string.Empty;

        if (Console.IsInputRedirected)
            return null;

        bool keyAvailable;
        try
        {
            keyAvailable = Console.KeyAvailable;
        }
        catch (InvalidOperationException)
        {
            return null;
        }

        if (keyAvailable)
        {
            while (true)
            {
                var key = Console.ReadKey();
                switch (key.Key)
                {
                    case ConsoleKey.Enter:
                        return command;

                    case ConsoleKey.Backspace:
                        if (command.Length > 0)
                            command = command[0..^1];
                        break;

                    default:
                        command += key.KeyChar;
                        break;
                }
            }
        }

        return null;
    }

    public static void RegisterCommand(string name, Action<string[]> handler)
    {
        if (TrimScope && name.Contains('.'))
            name = name[(name.IndexOf(".") + 1)..];

        if (Commands.ContainsKey(name))
        {
            Logger.WriteLog(LogType.Error, $"Command '{name}' is already registered. Overwriting with new handler.");
            Commands[name] = handler;
        }
        else
        {
            Commands.Add(name, handler);
        }
    }

    public static void RemoveCommand(string name)
    {
        if (TrimScope && name.Contains('.'))
            name = name[(name.IndexOf(".") + 1)..];

        Commands.Remove(name);
    }
}
