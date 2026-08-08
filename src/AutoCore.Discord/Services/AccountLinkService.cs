namespace AutoCore.Discord.Services;

using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;
using AutoCore.Discord.Config;
using AutoCore.Utils;
using Microsoft.EntityFrameworkCore;

/// <summary>
/// Discord-facing account create / password-change with per-Discord-user quotas and
/// linked-only authorization.
/// </summary>
public sealed class AccountLinkService
{
    private readonly Func<AuthContext> _contextFactory;
    private readonly DiscordConfig _config;

    public AccountLinkService(Func<AuthContext> contextFactory, DiscordConfig config)
    {
        _contextFactory = contextFactory ?? throw new ArgumentNullException(nameof(contextFactory));
        _config = config ?? throw new ArgumentNullException(nameof(config));
    }

    public AccountLinkCreateResult CreateAccount(
        ulong discordUserId,
        string? discordUsername,
        string email,
        string username,
        string password)
    {
        if (!_config.AllowAccountCreation)
        {
            return AccountLinkCreateResult.Fail(
                AccountLinkCreateError.CreationDisabled,
                "Account creation via Discord is currently disabled.");
        }

        if (discordUserId == 0)
        {
            return AccountLinkCreateResult.Fail(
                AccountLinkCreateError.InvalidDiscordUser,
                "Invalid Discord user.");
        }

        try
        {
            using var context = _contextFactory();

            var linkedCount = context.DiscordAccountLinks.Count(l => l.DiscordUserId == discordUserId);
            if (linkedCount >= _config.MaxAccountsPerDiscordUser)
            {
                return AccountLinkCreateResult.Fail(
                    AccountLinkCreateError.QuotaExceeded,
                    $"You already have the maximum of {_config.MaxAccountsPerDiscordUser} account(s) linked to this Discord user.");
            }

            var createOptions = new AccountCreateOptions
            {
                MinPasswordLength = _config.MinPasswordLength,
                MinUsernameLength = _config.MinUsernameLength,
                MaxUsernameLength = _config.MaxUsernameLength,
                Validated = true,
                Level = 0,
            };

            var created = AccountService.TryCreate(context, email, username, password, createOptions);
            if (!created.Success || created.Account == null)
            {
                return AccountLinkCreateResult.Fail(
                    MapCreateError(created.Error),
                    created.Message);
            }

            context.DiscordAccountLinks.Add(new DiscordAccountLink
            {
                DiscordUserId = discordUserId,
                AccountId = created.Account.Id,
                CreatedAt = DateTime.UtcNow,
                CreatedByUsername = string.IsNullOrWhiteSpace(discordUsername) ? null! : discordUsername.Trim(),
            });
            context.SaveChanges();

            // Never include the password in the success message.
            return AccountLinkCreateResult.Ok(
                created.Account.Username,
                $"Account '{created.Account.Username}' created and linked to your Discord account.");
        }
        catch (DbUpdateException ex)
        {
            Logger.WriteException(LogType.Warning, $"discord create account for user {discordUserId}", ex);
            return AccountLinkCreateResult.Fail(
                AccountLinkCreateError.DuplicateUsernameOrEmail,
                "Username or email is already taken.");
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, $"discord create account for user {discordUserId}", ex);
            return AccountLinkCreateResult.Fail(
                AccountLinkCreateError.DatabaseError,
                "Account creation failed. Please try again later.");
        }
    }

    public AccountLinkPasswordResult ChangePassword(
        ulong discordUserId,
        string username,
        string newPassword)
    {
        if (discordUserId == 0)
        {
            return AccountLinkPasswordResult.Fail(
                AccountLinkPasswordError.InvalidDiscordUser,
                "Invalid Discord user.");
        }

        if (string.IsNullOrWhiteSpace(username))
        {
            return AccountLinkPasswordResult.Fail(
                AccountLinkPasswordError.AccountNotFound,
                "Username is required.");
        }

        username = username.Trim();

        try
        {
            using var context = _contextFactory();

            var account = context.Accounts.FirstOrDefault(a => a.Username == username);
            if (account == null)
            {
                return AccountLinkPasswordResult.Fail(
                    AccountLinkPasswordError.AccountNotFound,
                    "No account with that username is linked to your Discord user.");
            }

            var linked = context.DiscordAccountLinks.Any(
                l => l.AccountId == account.Id && l.DiscordUserId == discordUserId);

            if (!linked)
            {
                return AccountLinkPasswordResult.Fail(
                    AccountLinkPasswordError.NotLinked,
                    "That account is not linked to your Discord user.");
            }

            var change = AccountService.TryChangePassword(
                context,
                account,
                newPassword,
                _config.MinPasswordLength);

            if (!change.Success)
            {
                return AccountLinkPasswordResult.Fail(
                    change.Error == AccountPasswordChangeError.PasswordTooShort
                        ? AccountLinkPasswordError.PasswordTooShort
                        : AccountLinkPasswordError.DatabaseError,
                    change.Message);
            }

            return AccountLinkPasswordResult.Ok(
                $"Password updated for account '{account.Username}'.");
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, $"discord change password for user {discordUserId}", ex);
            return AccountLinkPasswordResult.Fail(
                AccountLinkPasswordError.DatabaseError,
                "Password change failed. Please try again later.");
        }
    }

    private static AccountLinkCreateError MapCreateError(AccountCreateError error) => error switch
    {
        AccountCreateError.InvalidEmail => AccountLinkCreateError.InvalidEmail,
        AccountCreateError.InvalidUsername => AccountLinkCreateError.InvalidUsername,
        AccountCreateError.PasswordTooShort => AccountLinkCreateError.PasswordTooShort,
        AccountCreateError.DuplicateUsernameOrEmail => AccountLinkCreateError.DuplicateUsernameOrEmail,
        _ => AccountLinkCreateError.DatabaseError,
    };
}

public enum AccountLinkCreateError
{
    None = 0,
    CreationDisabled,
    InvalidDiscordUser,
    InvalidEmail,
    InvalidUsername,
    PasswordTooShort,
    DuplicateUsernameOrEmail,
    QuotaExceeded,
    DatabaseError,
}

public enum AccountLinkPasswordError
{
    None = 0,
    InvalidDiscordUser,
    AccountNotFound,
    NotLinked,
    PasswordTooShort,
    DatabaseError,
}

public readonly struct AccountLinkCreateResult
{
    public bool Success { get; }
    public AccountLinkCreateError Error { get; }
    public string Message { get; }
    public string? Username { get; }

    private AccountLinkCreateResult(bool success, AccountLinkCreateError error, string message, string? username)
    {
        Success = success;
        Error = error;
        Message = message;
        Username = username;
    }

    public static AccountLinkCreateResult Ok(string username, string message)
        => new(true, AccountLinkCreateError.None, message, username);

    public static AccountLinkCreateResult Fail(AccountLinkCreateError error, string message)
        => new(false, error, message, null);
}

public readonly struct AccountLinkPasswordResult
{
    public bool Success { get; }
    public AccountLinkPasswordError Error { get; }
    public string Message { get; }

    private AccountLinkPasswordResult(bool success, AccountLinkPasswordError error, string message)
    {
        Success = success;
        Error = error;
        Message = message;
    }

    public static AccountLinkPasswordResult Ok(string message)
        => new(true, AccountLinkPasswordError.None, message);

    public static AccountLinkPasswordResult Fail(AccountLinkPasswordError error, string message)
        => new(false, error, message);
}
