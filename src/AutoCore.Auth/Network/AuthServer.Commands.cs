namespace AutoCore.Auth.Network;

using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;
using AutoCore.Utils.Commands;
using AutoCore.Utils;
using Microsoft.EntityFrameworkCore;

public partial class AuthServer
{
    private void RegisterConsoleCommands()
    {
        CommandProcessor.RegisterCommand("auth.create", ProcessCreateCommand);
        CommandProcessor.RegisterCommand("auth.exit", ProcessExitCommand);
    }

    internal void ProcessExitCommand(string[] parts)
    {
        var minutes = 0;

        if (parts.Length > 1)
            minutes = int.Parse(parts[1]);

        Timer.Add("exit", minutes * 60000, false, Shutdown);

        Logger.WriteLog(LogType.Command, $"Exiting the server in {minutes} minute(s).");
    }

    internal void ProcessCreateCommand(string[] parts)
    {
        if (parts.Length < 4)
        {
            Logger.WriteLog(LogType.Command, "Invalid create account command! Usage: create <email> <username> <password>");
            return;
        }

        var email = parts[1];
        var userName = parts[2];
        var password = parts[3];

        try
        {
            using var context = CreateAuthContext();

            // SS-15 / §10: check the predictable condition instead of inferring it from a
            // swallowed exception. The old bare catch reported *every* failure — connection
            // refused, schema mismatch, permission denied — as "already taken".
            if (context.Accounts.Any(a => a.Username == userName || a.Email == email))
            {
                Logger.WriteLog(LogType.Command, "Username or email is already taken!");
                return;
            }

            var salt = Account.CreateSalt();

            context.Accounts.Add(new Account
            {
                Email = email,
                Username = userName,
                Password = Account.Hash(password ?? string.Empty, salt),
                Salt = salt,
                JoinDate = DateTime.Now
            });
            context.SaveChanges();

            // Never log the password: this line previously echoed the plaintext credential
            // into the console and the log file.
            Logger.WriteLog(LogType.Command, $"Created account: {userName}!");
        }
        catch (DbUpdateException ex)
        {
            // Unique-index violation: another create won the race between the check and the
            // insert. Still a duplicate, but log the real cause rather than guessing.
            Logger.WriteException(LogType.Warning, $"create account '{userName}'", ex);
            Logger.WriteLog(LogType.Command, "Username or email is already taken!");
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error, $"create account '{userName}'", ex);
            Logger.WriteLog(LogType.Command, "Account creation failed. See the error log for details.");
        }
    }

    /*private void ProcessRestartCommand(string[] parts)
    {
        // TODO: delayed restart, with contacting globals, so they can warn players not to leave the server, or they won't be able to reconnect
    }

    private void ProcessShutdownCommand(string[] parts)
    {
        // TODO: delayed shutdown, with contacting globals, so they can warn players not to leave the server, or they won't be able to reconnect
        // TODO: add timer to report the remaining time until shutdown?
        // TODO: add timer to contact global servers to tell them periodically that we're getting shut down?
    }*/
}
