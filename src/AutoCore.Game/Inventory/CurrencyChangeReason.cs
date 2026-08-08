namespace AutoCore.Game.Inventory;

/// <summary>
/// Economy path that caused a credits mutation. Carried on every <c>CurrencyChanged</c>
/// audit event so the trail answers "where did this money come from / go".
/// </summary>
public enum CurrencyChangeReason
{
    Unknown,
    VendorBuy,
    VendorBuyback,
    VendorSell,
    MissionReward,
    KillLoot,
    AdminCommand,
}
