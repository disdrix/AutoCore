namespace AutoCore.Game.Diagnostics;

using AutoCore.Game.Entities;

/// <summary>
/// Bridges combat HP changes into <see cref="PlayerActionTrace"/> without coupling
/// entity TakeDamage to full identity resolution at every call site.
/// </summary>
internal static class PlayerCombatTrace
{
    public static void OnDamage(ClonedObjectBase victim, ClonedObjectBase attacker, int actualDamage)
    {
        if (victim == null || actualDamage <= 0)
            return;

        try
        {
            var victimChar = ResolveCharacter(victim);
            var attackerChar = ResolveCharacter(attacker);

            if (victimChar != null)
            {
                PlayerActionTrace.DamageTaken(
                    victimChar,
                    attacker,
                    actualDamage,
                    victim.GetCurrentHP(),
                    victim.GetMaximumHP());
            }

            if (attackerChar != null && !ReferenceEquals(attackerChar, victimChar))
            {
                PlayerActionTrace.DamageDealt(
                    attackerChar,
                    victim,
                    actualDamage,
                    isCrit: false);
            }
        }
        catch
        {
            // Never throw from combat path.
        }
    }

    public static void OnHeal(ClonedObjectBase target, int amount, string source)
    {
        if (target == null || amount <= 0)
            return;

        try
        {
            var character = ResolveCharacter(target);
            if (character == null)
                return;

            PlayerActionTrace.Healed(
                character,
                amount,
                target.GetCurrentHP(),
                target.GetMaximumHP(),
                source);
        }
        catch
        {
            // never throw
        }
    }

    private static Character ResolveCharacter(ClonedObjectBase obj)
    {
        if (obj == null)
            return null;

        var asChar = obj.GetAsCharacter();
        if (asChar != null)
            return asChar;

        // Player vehicle: owner is the character.
        var vehicle = obj.GetAsVehicle();
        if (vehicle?.Owner != null)
        {
            asChar = vehicle.Owner.GetAsCharacter();
            if (asChar != null)
                return asChar;
        }

        return obj.GetSuperCharacter(includeSummons: true);
    }
}
