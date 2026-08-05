# Annotated: StatusFlag_GetDisplayName (`aa_00580a20`)

| Field | Value |
|---|---|
| Stable ID | `aa_00580a20` |
| VA | `0x00580a20`–`0x00580ac0` |
| System | `skills-abilities` / status UI |
| Date | `2026-07-29` (W19-T) |

## Machine-level notes

- **ABI:** one stack arg (`[esp+4]`); plain `RET` — **not** thiscall.
- **Role:** map a **power-of-two status flag value** → product English display name for cast-block / UI toast suffixes.
- **Not** a single “Weapons Disabled” leaf — that string is only case `0x10`. Scaffold alias `Combat_Weapons_Disabled` is a plate-string misname.
- **Default:** unknown/non-power-of-two flags → `"in a world of hurt"`.
- **Compiler shape:** nested range checks + switch (MS jump table for low bits 1…0x20 after `add eax,-1`).

## Annotated CF

```c
// StatusFlag_GetDisplayName(flagValue) -> const char*
char * StatusFlag_GetDisplayName(int flagValue)
{
  // --- low band: flagValue <= 0x40 ---
  if (flagValue < 0x41) {
    if (flagValue == 0x40) return "Afraid";       // bit 6
    switch (flagValue) {
    case 0x01: return "GM Frozen";                // bit 0
    case 0x02: return "Stunned";                  // bit 1
    case 0x04: return "Locked Down";              // bit 2
    case 0x08: return "Silenced";                 // bit 3
    case 0x10: return "Weapons Disabled";         // bit 4
    case 0x20: return "GM Chat Banned";           // bit 5
    // other values in band fall through → default
    }
  }
  // --- mid band: 0x41 .. 0x2000 ---
  else if (flagValue < 0x2001) {
    if (flagValue == 0x2000) return "Immune to death"; // bit 13
    if (flagValue == 0x80)   return "Confused";        // bit 7
    if (flagValue == 0x200)  return "Blind";           // bit 9
    if (flagValue == 0x1000) return "Slowed";          // bit 12
  }
  // --- high band ---
  else {
    if (flagValue == 0x4000)  return "Speeding";       // bit 14
    if (flagValue == 0x10000) return "Zombied";        // bit 16
  }
  return "in a world of hurt";  // default / unknown
}
```

## Caller evidence (context only; not owned)

| Caller | How used |
|---|---|
| `Client_CastBlockFeedback` `0x0093b7f0` | After dead/waiting/town checks fail: status byte `@ dual+0xb8` bits → `GetDisplayName(2)` Stunned, `(0x80)` Confused, `(0x40)` Afraid; string fed to localizer + toast `"You can't do that while you are " + name + "!"` |
| `FUN_00618c80` | Many sites (11+ xrefs) — status name resolution in related UI/list path |

**Note:** Cast-block maps **status bit 8** → call with **value 2** (`"Stunned"`), not the bit mask `8`. Bit→value encoding is **caller-side**; this unit only maps the numeric **flag key** it is given.

## Open questions

1. Full product enum English for every power-of-two not hit by known callers (GM Frozen, Silenced, …).
2. Whether mid-band missing keys (`0x100`, `0x400`, `0x800`, …) are intentional dead codes or obsolete flags.
3. Whether any path ever passes multi-bit OR masks (would hit default).
