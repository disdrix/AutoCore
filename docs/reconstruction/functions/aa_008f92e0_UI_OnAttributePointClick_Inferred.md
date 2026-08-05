# Function record: UI_OnAttributePointClick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f92e0` |
| **Canonical name** | `UI_OnAttributePointClick_Inferred` |
| **Address** | `0x008f92e0` – `0x008f96bc` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / character sheet UI (client) |
| **Completion status** | **Dual reviewed** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `docs/reconstruction/reviews/A_aa_008f92e0_UI_OnAttributePointClick_Inferred.md` |
| **Dual B** | `docs/reconstruction/reviews/B_aa_008f92e0_UI_OnAttributePointClick_Inferred.md` |

## Purpose

UI message handler: on event type **8** and control IDs **`0x9C41`–`0x9C44`**, spends one free point from local character **`+0x6CE`** into one of four stat shorts, refreshes sheet chrome, and may send sector packet **`0x205A`**. Control **`0x9C40`** is a non-spend path (`FUN_007fca10`). Arena flag and empty pool return handled without spend.

## Signature (body-sealed)

```c
uint32_t __thiscall UI_OnAttributePointClick_Inferred(
    int *uiHost /* this */,
    int eventType,
    uint32_t controlId);
/* ret 8 — two stack args */
```

## Control map (sealed)

| controlId | stat offset | packet flags | notes |
|-----------|-------------|--------------|-------|
| `0x9C40` | — | — | `FUN_007fca10` only |
| `0x9C41` | `+0x13E` | `0x1` | |
| `0x9C42` | `+0x13C` | `0x10000` | vehicle combat pools + max heat |
| `0x9C43` | `+0x140` | `0x100` | char vtbl `+0x5C` |
| `0x9C44` | `+0x142` | `0x1000000` | |

Pool: `CVOGCharacter_AddSkillPoints(pool - 1)` assigns `+0x6CE`. Not `+0x6CC` / `AddAttributePoints`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008f92e0_UI_OnAttributePointClick_Inferred.md`
- Annotated: `docs/reconstruction/raw/aa_008f92e0_UI_OnAttributePointClick_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_OnAttributePointClick_Inferred.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_008f92e0_*`, `B_aa_008f92e0_*`

## Callers / callees

| Direction | Detail |
|-----------|--------|
| Xrefs | 1× DATA `0x00a35a2c` (handler table slot) |
| Code callers | none (indirect dispatch) |
| Key callees | `CVOGCharacter_AddSkillPoints`, `Client_SendSectorPacket`, `Client_RefreshMissionDialogChrome`, `Vehicle_RecalcCombatPools`, `Vehicle_CalcHeatMaximum`, getters/setters `0x0040dd*0`/`0x004c2e*`, toast `FUN_007fdfb0`, default `FUN_0087b500` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompile ≡ raw | **High** |
| Stat offset / flag map | **High / Sealed** |
| Signature `ret 8` thiscall | **High** |
| Packet `0x205A` | **High** |
| Product names of four stats | **Open** |
| `+0x6CE` product glossary vs skill/attribute | **Open** |
| Server authority | **Open** |
| Overall | **accept-with-gaps** |
