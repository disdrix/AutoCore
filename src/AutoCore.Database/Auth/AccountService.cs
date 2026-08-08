using Microsoft.EntityFrameworkCore;

namespace AutoCore.Database.Auth;

using AutoCore.Database.Auth.Models;
using AutoCore.Utils;

/// <summary>
/// Shared account create / password-change helpers used by Auth console commands and
/// the optional Discord module. Keeps hashing and SS-15 duplicate handling in one place.
/// </summary>
public static class AccountService
{
    public const int DefaultMinPasswordLength = 1;
    public const int DefaultMinUsernameLength = 1;
    public const int DefaultMaxUsernameLength = 64;
    public const int DefaultMaxEmailLength = 256;

    public static AccountCreateResult TryCreate(
        AuthContext context,
        string email,
        string username,
        string password,
        AccountCreateOptions options = null)
    {
        ArgumentNullException.ThrowIfNull(context);

        if (options == null)
            options = AccountCreateOptions.Default;

        var validation = ValidateCreateInputs(email, username, password, options);
        if (validation.HasValue)
            return AccountCreateResult.Fail(validation.Value, validation.Value.ToUserMessage());

        email = email.Trim();
        username = username.Trim();

        try
        {
            if (context.Accounts.Any(a => a.Username == username || a.Email == email))
            {
                return AccountCreateResult.Fail(
                    AccountCreateError.DuplicateUsernameOrEmail,
                    "Username or email is already taken.");
            }

            var salt = Account.CreateSalt();
            var account = new Account
            {
                Email = email,
                Username = username,
                Password = Account.Hash(password, salt),
                Salt = salt,
                JoinDate = DateTime.UtcNow,
                Level = options.Level,
                Validated = options.Validated,
                Locked = false,
            };

            context.Accounts.Add(account);
            context.SaveChanges();

            return AccountCreateResult.Ok(account);
        }
        catch (DbUpdateException ex)
        {
            // Unique-index race between check and insert (SS-15).
            Logger.WriteException(LogType.Warning, $"create account '{username}'", ex);
            return AccountCreateResult.Fail(
                AccountCreateError.DuplicateUsernameOrEmail,
                "Username or email is already taken.");
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, $"create account '{username}'", ex);
            return AccountCreateResult.Fail(
                AccountCreateError.DatabaseError,
                "Account creation failed. See the server log for details.");
        }
    }

    public static AccountPasswordChangeResult TryChangePassword(
        AuthContext context,
        Account account,
        string newPassword,
        int minPasswordLength = DefaultMinPasswordLength)
    {
        ArgumentNullException.ThrowIfNull(context);
        ArgumentNullException.ThrowIfNull(account);

        if (string.IsNullOrEmpty(newPassword) || newPassword.Length < minPasswordLength)
        {
            return AccountPasswordChangeResult.Fail(
                AccountPasswordChangeError.PasswordTooShort,
                $"Password must be at least {minPasswordLength} character(s).");
        }

        try
        {
            var salt = Account.CreateSalt();
            account.Salt = salt;
            account.Password = Account.Hash(newPassword, salt);
            context.SaveChanges();
            return AccountPasswordChangeResult.Ok();
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, $"change password for account id={account.Id}", ex);
            return AccountPasswordChangeResult.Fail(
                AccountPasswordChangeError.DatabaseError,
                "Password change failed. See the server log for details.");
        }
    }

    private static AccountCreateError? ValidateCreateInputs(
        string email,
        string username,
        string password,
        AccountCreateOptions options)
    {
        if (string.IsNullOrWhiteSpace(email) || email.Trim().Length > options.MaxEmailLength)
            return AccountCreateError.InvalidEmail;

        email = email.Trim();
        if (!email.Contains('@') || email.StartsWith('@') || email.EndsWith('@'))
            return AccountCreateError.InvalidEmail;

        if (string.IsNullOrWhiteSpace(username))
            return AccountCreateError.InvalidUsername;

        username = username.Trim();
        if (username.Length < options.MinUsernameLength || username.Length > options.MaxUsernameLength)
            return AccountCreateError.InvalidUsername;

        if (string.IsNullOrEmpty(password) || password.Length < options.MinPasswordLength)
            return AccountCreateError.PasswordTooShort;

        return null;
    }
}

public sealed class AccountCreateOptions
{
    public static AccountCreateOptions Default { get; } = new();

    public int MinPasswordLength { get; init; } = AccountService.DefaultMinPasswordLength;
    public int MinUsernameLength { get; init; } = AccountService.DefaultMinUsernameLength;
    public int MaxUsernameLength { get; init; } = AccountService.DefaultMaxUsernameLength;
    public int MaxEmailLength { get; init; } = AccountService.DefaultMaxEmailLength;
    public byte Level { get; init; }
    public bool Validated { get; init; }
}

public enum AccountCreateError
{
    None = 0,
    InvalidEmail,
    InvalidUsername,
    PasswordTooShort,
    DuplicateUsernameOrEmail,
    DatabaseError,
}

public enum AccountPasswordChangeError
{
    None = 0,
    PasswordTooShort,
    DatabaseError,
}

public readonly struct AccountCreateResult
{
    public bool Success { get; }
    public AccountCreateError Error { get; }
    public string Message { get; }
    public Account Account { get; }

    private AccountCreateResult(bool success, AccountCreateError error, string message, Account account)
    {
        Success = success;
        Error = error;
        Message = message;
        Account = account;
    }

    public static AccountCreateResult Ok(Account account)
        => new(true, AccountCreateError.None, "Account created.", account);

    public static AccountCreateResult Fail(AccountCreateError error, string message)
        => new(false, error, message, null);
}

public readonly struct AccountPasswordChangeResult
{
    public bool Success { get; }
    public AccountPasswordChangeError Error { get; }
    public string Message { get; }

    private AccountPasswordChangeResult(bool success, AccountPasswordChangeError error, string message)
    {
        Success = success;
        Error = error;
        Message = message;
    }

    public static AccountPasswordChangeResult Ok()
        => new(true, AccountPasswordChangeError.None, "Password changed.");

    public static AccountPasswordChangeResult Fail(AccountPasswordChangeError error, string message)
        => new(false, error, message);
}

internal static class AccountCreateErrorExtensions
{
    public static string ToUserMessage(this AccountCreateError error) => error switch
    {
        AccountCreateError.InvalidEmail => "A valid email address is required.",
        AccountCreateError.InvalidUsername => "Username length is invalid.",
        AccountCreateError.PasswordTooShort => "Password is too short.",
        AccountCreateError.DuplicateUsernameOrEmail => "Username or email is already taken.",
        AccountCreateError.DatabaseError => "Account creation failed. See the server log for details.",
        _ => "Account creation failed.",
    };
}
