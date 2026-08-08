# Annotated low-level: Client_CombatChat_EmitEventLine_Inferred (`FUN_007ffef0`)

| Field | Value |
|---|---|
| Stable ID | `aa_007ffef0` |
| VA | `0x007ffef0`–`0x00800ad1` exclusive |
| Body size | **3041 B** (`0xBE1`) |
| System | combat chat UI / skills residual consumer |
| Date | 2026-08-04 (WQ9D-I dual; prior scaffold 2026-07-23) |
| Ghidra | `FUN_007ffef0` |
| Named | `Client_CombatChat_EmitEventLine_Inferred` |

## Machine-level notes

- **ABI:** two stack args, **`ret 8`**. Entry `mov eax,[esp+4]` → host; second arg combat-event blob.
- **Not** cast managers / skill sim — pure **client presentation**: format combat event → `CDlgChatLog_AppendChannelMessage`.
- **Callee of** `FUN_0093ffb0` (combat floater + chat path; CALL @ `0x00940e37`).
- Self-hit dodge spam gate: when target TFID == source TFID == local player and dodge flag, early return.
- Related-object filter uses `vtbl+0x1D8` related TFID + `FUN_0040aff0` copy + `TFID_NotEquals` vs null TFID `DAT_00a1e850`, then crew membership `FUN_005749d0` and option bits on `DAT_00af921c`.
- Name buffers: target → `local_140` (~50 B), actor → `local_10c` (~50 B), message → `local_c8` (~200 B).
- Localize via `FUN_007a6de0` / `StringPool_ApplyModeAndRingStore_Inferred` after `FUN_007a69d0` / `Locale_GetInstance_Inferred`.
- Channel codes `0x10`–`0x16` land in combat dual-pane of `CDlgChatLog` (see `aa_008f8200`).

## Event type switch (`param_2[3].dwCoidLo`)

| Case | English family | Channel |
|---|---|---|
| 0 | Damage / dodge / resist / deflect / crit / shielded | `0x10`/`0x11`/`0x12`/`0x16` |
| 1 | Repair / heal (amount negated) | `0x13` |
| 2 | Power gain/loss/sap | `0x15` |
| 3 | XP gain (`"XP"` @ `DAT_00a43258`) | `0x14` |
| default | fallback channel `0x11` | |

## Flags on `param_2[2]`

| Field | Role |
|---|---|
| `bPad0` | Crit |
| `bPad1` | Dodge → `"Dodges"` / `"Misses"` |
| `bPad2` | Resist |
| `bPad3` | Deflect |
| `dwCoidLo` | Amount |
| `dwCoidHi` | If == amount and non-crit → append `"(Shielded)"`, channel `0x16` |

## Relevance flags before format

| Flag | Meaning |
|---|---|
| `bVar1` | Target vehicle (`vtbl+0x210`) == host `+0xE98` |
| `bVar2` | Source vehicle == host `+0xE98` |
| `bVar3` | Related-object / crew option path (bits of `DAT_00af921c`) |

If none of the three and not crew-related via `FUN_005749d0` on source/target → suppress.

## Open gaps

1. Product/PDB symbol.
2. Exact product type of combat-event blob (decompiler `TFID_16*` is overlay).
3. Product English for `param_1+0xF40` / `DAT_00d1b644` gates.
4. Whether `DAT_00af921c` is truly combat options or Ghidra symbol collision with month-name table.
5. Runtime / bit-exact open.

## Pseudocode

See raw `aa_007ffef0_FUN_007ffef0.md` (authoritative) and clean `Client_CombatChat_EmitEventLine_Inferred.cpp`.
