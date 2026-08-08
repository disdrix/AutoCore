using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace AutoCore.Database.Auth.Models;

/// <summary>
/// Links a Discord user (snowflake) to a game <see cref="Account"/>.
/// Used by the optional AutoCore.Discord module for account creation quotas and
/// linked-only password changes.
/// </summary>
[Table("discord_account_link")]
public class DiscordAccountLink
{
    [Key]
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public uint Id { get; set; }

    /// <summary>Discord user snowflake.</summary>
    public ulong DiscordUserId { get; set; }

    /// <summary>FK to <see cref="Account.Id"/>. Unique — one Discord owner per account.</summary>
    public uint AccountId { get; set; }

    public DateTime CreatedAt { get; set; }

    /// <summary>Discord username at link time (audit only; may go stale).</summary>
    public string CreatedByUsername { get; set; }
}
