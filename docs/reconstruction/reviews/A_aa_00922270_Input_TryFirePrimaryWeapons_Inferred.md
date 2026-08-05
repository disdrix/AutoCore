# Review A (reconstruction fidelity): `aa_00922270` Input_TryFirePrimaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00922270` |
| **VA** | `0x00922270` |
| **Canonical name** | `Input_TryFirePrimaryWeapons_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00922270_Input_TryFirePrimaryWeapons_Inferred.md` |
| **System** | `combat` / `skills-abilities` (input fire entry) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **primary-weapon / hardpoint fire attempt** from input. Two-phase body:

1. **Hardpoint skill walk** over character list at `DAT_00d1b6d8+0x550` … `+0x554`, stride **0xC**. First enabled entry whose skill passes block flags + **category-1** cooldown remaining == 0 is cast via `Client_CastSkillFromQuickBarSlot(skill+0x5FC)`, then UI tail only.
2. **Gun path** (list empty/exhausted): same outer gates as `Input_TryFireSecondaryWeapons` (local player, multi-inherit flags `+0xB8 & 0xD2 == 0`, sector net vtbl+8, vehicle `char+0x250`). Then first-time tip **0x12**, primary heat probe `FUN_004f5290` (vehicle thiscall), primary fire `FUN_004f50d0`, optional chrome `FUN_0089ff80`.

Sibling of named `Input_TryFireSecondaryWeapons` (`0x0091A550`). Callers: `Client_QuickBar_ActivateSlot` (slot0 off-foot remap) and `Client_Input_DriveControlTick` (held primary fire).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00922270_FUN_00922270.md` |
| Annotated | `docs/reconstruction/raw/aa_00922270_FUN_00922270.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Input_TryFirePrimaryWeapons_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00922270_Input_TryFirePrimaryWeapons_Inferred.md` |
| Sibling dual | `reviews/A_aa_0091a550_Input_TryFireSecondaryWeapons.md` |
| Callees (Ghidra decompile) | `0x004f5290`, `0x004f50d0`, `0x004f52e0`, `0x004f5110`, `0x0056d520`, `0x0089ff80` |
| Ghidra | `decompile_function` + `analyze_function_complete` + `read_memory` prolog |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Skill list `@char+0x550/+0x554`, stride **0xC** | **High** | Decomp + asm `/0xc` magic `0x2AAAAAAB` |
| Entry layout: ptr@+0, enable char@+8 | **High** | Body |
| Skill gates: `*(skill+0x615)&1==0`, `*(skill+0x628)==0` | **High** | Body |
| Category CD: `Skill_GetCategoryCooldownRemaining(skill+0x5E8, 1, …)` == 0 | **High** | Cat arg literal **1**; ST0 vs `g_flZero` |
| Cast uses `skill+0x5FC` → `Client_CastSkillFromQuickBarSlot` | **High** | Call @ `0x00922312` → `0x009418E0` |
| Skill path skips gun fire (goto UI tail) | **High** | `goto LAB_00922371` after cast |
| Outer gates match secondary (player / `0xD2` / net / `+0x250`) | **High** | Parallel to sibling body |
| Vehicle thiscall into heat+fire: ECX = `char+0x250` | **High** | Asm: `mov esi,[eax+0x250]` then `mov ecx,esi` before both calls |
| `FUN_004f5290` = primary can-fire probe (`vtbl+0x38`, **any** heat-OK → true) | **High** CF | Sibling `FUN_004f52e0` uses `vtbl+0x3C` + **all** must pass |
| `FUN_004f50d0` = primary fire walk (`vtbl+0x38` → `FUN_0056d520`) | **High** CF | Sibling `FUN_004f5110` uses `vtbl+0x3C` |
| Tip **0x12** before heat on gun path | **High** | Call order |
| No heat-fail log string (unlike secondary) | **High** | Body silence on AL==0 |
| UI tail: `+0x6B8`/`+0x6B9` + `DAT_00d1b8f0` vtbl **+0x3D8** → `FUN_0089ff80` | **High** | Shared with secondary |
| Product name `Input_TryFirePrimaryWeapons` | **Probable** | Structural sibling + QB slot0; no retail string in unit |
| `vtbl+0x38` product word "IsPrimary" | **Probable** | Dual with secondary `+0x3C`; no RTTI seal |
| Mask `0xD2` bit semantics | **Medium** | Shared open with secondary dual |
| `unaff_EDI` third CD arg | **Low** / noise | Decompiler phantom; asm pushes fixed **1** as category |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Skill walk → first cast → UI | **Yes** |
| Exhaust → gates → tip → heat → fire → UI | **Yes** |
| Skill path does not call heat/fire | **Yes** |
| Heat fail: no log, no fire | **Yes** |
| No invented modernization branches | **Yes** |

### Sealed CF sketch

```
Input_TryFirePrimaryWeapons_Inferred():
  char = DAT_00d1b6d8
  for i in skillList(char+0x550, end+0x554, stride 0xC):
    if entry.enabled && skill.okFlags && category1CD==0:
      Client_CastSkillFromQuickBarSlot(skill.skillId@+0x5FC)
      goto UI_TAIL
  // gun path
  if char && !(flags@+0xB8 & 0xD2) && netLive && vehicle@+0x250:
    Client_MaybeShowFirstTimeTip(0x12)
    if Vehicle_CanFireAnyPrimaryHeatOK(vehicle):   // FUN_004f5290
      Vehicle_FireAllPrimaryWeapons(vehicle)      // FUN_004f50d0
      UI_TAIL:
        if (+0x6B8 || +0x6B9) && host && host.vtbl+0x3D8():
          FUN_0089ff80()
  return
```

### Primary vs secondary heat quantifier (**High**)

| | Primary `FUN_004f5290` | Secondary `FUN_004f52e0` |
|---|---|---|
| Weapon group vtbl | **+0x38** | **+0x3C** |
| Heat quantifier | **∃** primary with heat OK → 1 | **∀** secondary heat OK → 1 (fail any → 0) |
| Fire walker | `FUN_004f50d0` | `FUN_004f5110` |
| Heat-fail UX | silent | log `"Failed to fire secondary weapons due to heat.\n"` |

---

## 5. Callers / callees

| Direction | Addr / symbol | Role |
|---|---|---|
| Caller | `Client_QuickBar_ActivateSlot` `0x009436C0` @ `0x00943754` | Slot0 off-foot primary |
| Caller | `Client_Input_DriveControlTick` `0x009223B0` @ `0x009233DA` | Held primary fire |
| Callee | `Skill_GetCategoryCooldownRemaining` | Category **1** remaining |
| Callee | `Client_CastSkillFromQuickBarSlot` `0x009418E0` | Hardpoint skill cast |
| Callee | `Client_MaybeShowFirstTimeTip` | Tip id **0x12** |
| Callee | `FUN_004f5290` | Primary heat probe (vehicle) |
| Callee | `FUN_004f50d0` | Primary fire apply (vehicle) |
| Callee | `FUN_0089ff80` | Weapon-chrome UI residual |

---

## 6. Gaps / open

1. Promote product symbols for `FUN_004f5290` / `FUN_004f50d0` (and secondary twins) in NAMING_REGISTRY — evidence-strong, still FUN in Ghidra.
2. Seal `vtbl+0x38` / `+0x3C` method names (IsPrimary/IsSecondary_Inferred).
3. Map flag mask **0xD2** bits (dead / combat-disabled / stealth — open on secondary dual too).
4. Tip **0x12** product string / first-time-flag bit.
5. Skill list owner type name (`char+0x550` hardpoint / weapon-skill vector).
6. Runtime: held fire while overheated should tip once-path + silent skip; skill-ready hardpoint should cast without gun heat path.
7. Bit-exact vs retail deferred.

**Verdict:** **accept-with-gaps**
