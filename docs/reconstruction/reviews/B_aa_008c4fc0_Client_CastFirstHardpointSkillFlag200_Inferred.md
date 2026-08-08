# Review B (skeptical / adversarial): `aa_008c4fc0` Client_CastFirstHardpointSkillFlag200_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c4fc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ8R-F) |
| **Counterpart** | `reviews/A_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/callers/cast ABI; **falsify** quick-bar-slot and inventory-mutate confusions |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Walks **quick-bar slots** (name “QB skill path”) | Body never touches QB pack/`ActivateSlot`; walks **HB list** + RTTI skill base | **Falsified** as slot walker — parent nickname only |
| 2 | Inventory grab/drop/equip transfer | No inventory opcodes, no grid/hardpoint grab send | **Falsified** — cast leaf only |
| 3 | Same as `Input_TryFirePrimaryWeapons` skill walk | Primary uses `char+0x550` stride-0xC list + category CD; this uses TraversalLock list + RTTI + flag **0x200** | **Falsified** as same walker |
| 4 | Casts all matching skills | `break` after first; single optional cast | **Falsified** as multi-cast |
| 5 | Always casts when skill found | Requires `+0x614 & 0x200`; match without bit is silent no-op | **Falsified** |
| 6 | Client in ECX/EAX for cast | Asm `MOV ESI,&DAT_00d1a840`; push skillId only | **Falsified** register story |
| 7 | Multiple static callers | `get_function_callers` → **only** `FUN_008c50f4` | **Falsified** as multi-entry |
| 8 | Runs when enhanced (`+0x6b9`) | Parent: `+0x6b8 && !+0x6b9` → this; else mod-chip | **Falsified** as enhanced path |
| 9 | `JLE` after TEST means signed ≤ comparison of full flags | Mask `0x200` → ZF-only meaningful; equiv “bit clear → skip” | **Sealed** as bit test |
| 10 | Product name Confirmed | No string/RTTI on VA | **Open** — keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sole caller + parent gate | **High** | Wrong UI/mod-chip branch |
| List lock/unlock pairing | **High** | Deadlock / double LeaveCS |
| RTTI skill filter | **High** | Cast wrong HB type |
| Flag `0x200` + id `+0x5fc` | **High** | Wrong skill / always/never cast |
| Client singleton ESI | **High** | Cast-block probe uses wrong client |
| `+0x6b8` English “host mode” | **Tentative** | Misnamed gate in port docs |
| Bit 0x200 product meaning | **Open** | Wrong skill class filter on server mirror |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + parent

Parent `FUN_008c50f4` (context only):

```
if player+0x6b8 && !player+0x6b9:
  CALL 0x008c4fc0          ; this unit
else if DAT_00d1b778 && vtbl+0x3d8():
  CALL Client_Input_TryUseModChip
; then optional gauge vtbl tail
return 1
```

Body re-decompile 2026-08-04 ≡ 2026-07-23 raw (no CF drift).  
Cast site bytes match dual residual table in `reviews/a_009418e0.md` (caller ESI + skill from HB `+0x5fc` if flags `&0x200`).

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `Client_CastFirstHardpointSkillFlag200_Inferred` | **Accept INFERRED** — RTTI + first match + bit 0x200 + cast |
| `Client_QuickBar_Activate…` | **Reject** — no slot pack |
| `Client_SendInventoryGrab_Hardpoint` sibling | **Reject** — no inventory wire |
| `Input_TryFirePrimaryWeapons` | **Reject** — different list + gates |
| `FUN_008c4fc0` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
if hostFlag_6b8:
  list = vehicle_list_or_player_list_MI_b4
  lock_walk_first enabled CVOGHBSkillBase
  if skill.flags & 0x200:
    CastSkillFromQuickBarSlot(globalClient, skill.skillId)
// does not run when enhanced +0x6b9 (parent diverts to mod-chip)
// does not mutate inventory grids
```

**Verdict:** **accept-with-gaps**.
