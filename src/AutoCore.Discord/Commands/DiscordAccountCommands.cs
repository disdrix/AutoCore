namespace AutoCore.Discord.Commands;

using AutoCore.Discord.Abstractions;
using AutoCore.Discord.Services;
using AutoCore.Utils;
using AutoCore.Utils.Reliability;

/// <summary>
/// Handles <c>/newAccount</c> and <c>/changePassword</c> slash commands.
/// Interaction entry is an architectural boundary (SS-25).
/// </summary>
public sealed class DiscordAccountCommands
{
    public const string NewAccountCommandName = "newaccount";
    public const string ChangePasswordCommandName = "changepassword";

    private readonly AccountLinkService _accountLinks;

    public DiscordAccountCommands(AccountLinkService accountLinks)
    {
        _accountLinks = accountLinks ?? throw new ArgumentNullException(nameof(accountLinks));
    }

    public static IReadOnlyList<DiscordSlashCommandRegistration> BuildRegistrations() =>
    [
        new DiscordSlashCommandRegistration
        {
            Name = NewAccountCommandName,
            Description = "Create a new game account linked to your Discord user.",
            Options =
            [
                new DiscordSlashCommandOption
                {
                    Name = "email",
                    Description = "Email address for the account",
                    Required = true,
                },
                new DiscordSlashCommandOption
                {
                    Name = "username",
                    Description = "Desired game username",
                    Required = true,
                },
                new DiscordSlashCommandOption
                {
                    Name = "password",
                    Description = "Account password (never shared or logged)",
                    Required = true,
                },
            ],
        },
        new DiscordSlashCommandRegistration
        {
            Name = ChangePasswordCommandName,
            Description = "Change the password of a game account linked to your Discord user.",
            Options =
            [
                new DiscordSlashCommandOption
                {
                    Name = "username",
                    Description = "Game username",
                    Required = true,
                },
                new DiscordSlashCommandOption
                {
                    Name = "new_password",
                    Description = "New password (never shared or logged)",
                    Required = true,
                },
            ],
        },
    ];

    /// <summary>
    /// SS-25: isolates one slash-command interaction so a handler failure cannot kill the bot.
    /// </summary>
    public async Task HandleAsync(DiscordSlashCommandContext context)
    {
        ArgumentNullException.ThrowIfNull(context);

        string? reply = null;
        var failed = false;

        Guard.Run(
            $"discord slash '{context.CommandName}' user={context.UserId}",
            () =>
            {
                reply = Dispatch(context);
            });

        // Guard.Run swallows unexpected exceptions after logging. If Dispatch never assigned
        // a reply, surface a generic error instead of leaving the interaction hanging.
        if (reply == null)
        {
            failed = true;
            reply = "Something went wrong processing that command. Please try again later.";
        }

        try
        {
            await context.RespondAsync(reply).ConfigureAwait(false);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(
                LogType.Warning,
                $"discord slash reply '{context.CommandName}' user={context.UserId}",
                ex);
            if (!failed)
            {
                // Best-effort already failed; nothing more to do.
            }
        }
    }

    internal string Dispatch(DiscordSlashCommandContext context)
    {
        // Allowed in any channel (guild or DM). Replies are ephemeral in production so
        // other channel members do not see success/error text; password options are still
        // visible briefly to the invoker in the slash UI — never log them.
        var name = context.CommandName?.Trim().ToLowerInvariant() ?? string.Empty;

        return name switch
        {
            NewAccountCommandName => HandleNewAccount(context),
            ChangePasswordCommandName => HandleChangePassword(context),
            _ => "Unknown command.",
        };
    }

    private string HandleNewAccount(DiscordSlashCommandContext context)
    {
        var email = context.GetOption("email") ?? string.Empty;
        var username = context.GetOption("username") ?? string.Empty;
        var password = context.GetOption("password") ?? string.Empty;

        // Intentionally do not include password in any returned string or log.
        var result = _accountLinks.CreateAccount(
            context.UserId,
            context.Username,
            email,
            username,
            password);

        return result.Message;
    }

    private string HandleChangePassword(DiscordSlashCommandContext context)
    {
        var username = context.GetOption("username") ?? string.Empty;
        var newPassword = context.GetOption("new_password") ?? string.Empty;

        var result = _accountLinks.ChangePassword(context.UserId, username, newPassword);
        return result.Message;
    }
}
