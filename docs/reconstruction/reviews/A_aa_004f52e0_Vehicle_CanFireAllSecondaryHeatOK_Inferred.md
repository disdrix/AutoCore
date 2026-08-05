# Review A (reconstruction fidelity): `aa_004f52e0` Vehicle_CanFireAllSecondaryHeatOK_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f52e0` |
| **VA** | `0x004f52e0` |
| **Canonical name** | `Vehicle_CanFireAllSecondaryHeatOK_Inferred` |
| **Ghidra symbol** | `FUN_004f52e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f52e0_Vehicle_CanFireAllSecondaryHeatOK_Inferred.md` |
| **System** | `combat` / vehicle weapon heat gate |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Vehicle **secondary heat quantifier** (predicate only). Walks the **3-slot weapon hardpoint pointer table** at `*(vehicle+0x260)` (indices 0..2, byte stride 4 / bound `0xC`). For each non-null weapon:

1. Call weapon vtbl **`+0x3C`** (thiscall on weapon) — secondary-group predicate (twin of primary `+0x38`).
2. If true, call **`Weapon_CanFireHeatCheck(weapon)`** (`0x0056aca0`).
3. On **first heat-fail** secondary → **return 0** (**universal ∀** — all secondary-marked slots must be heat-OK).

If every secondary-marked slot is heat-OK (including **empty / no secondary** table → vacuous success) → **return 1**.

Sole caller: `Input_TryFireSecondaryWeapons` (`0x0091a550`); fail path logs `Failed to fire secondary weapons due to heat.` before return. Fire twin: `FUN_004f5110`.

**Quantifier differs from primary** `0x004f5290` (**∃** first OK → 1; empty → 0).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f52e0_FUN_004f52e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004f52e0_FUN_004f52e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004f52e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f52e0_FUN_004f52e0.md` |
| Primary twin dual | `reviews/A_aa_004f5290_Vehicle_CanFireAnyPrimaryHeatOK_Inferred.md` |
| Fire twin dual (this batch) | `reviews/A_aa_004f5110_Vehicle_FireAllSecondaryWeapons_Inferred.md` |
| Heat callee dual | `reviews/A_aa_0056aca0_Weapon_CanFireHeatCheck.md` |
| Parent dual | `reviews/A_aa_0091a550_Input_TryFireSecondaryWeapons.md` |
| Ghidra | `decompile_function` + `read_memory` 80 B @ `0x004f52e0`; callers |
| Parent chain | DriveControlTick → secondary input |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` / ECX = vehicle | **High** | Asm `mov ebx,ecx` |
| Table base `*(vehicle+0x260)` | **High** | Same as primary heat dual |
| Loop: `i=0; i+=4; while i<0xC` → **3 slots** | **High** | Decomp + asm |
| Null weapon skipped | **High** | `test esi,esi` / `je` |
| Group filter = weapon vtbl **`+0x3C`** | **High** CF | Asm `call [edx+0x3c]` |
| Heat gate = `Weapon_CanFireHeatCheck` | **High** | Named in decompile; relative call |
| Quantifier = **∀** (first fail → 0; exhaust → 1) | **High** | Early `return 0`; fallthrough `al=1` |
| Empty / no-secondary → **1** (vacuous ∀) | **High** | Opposite of primary empty→0 |
| Pure predicate (no fire, no heat write) | **High** | Only vtbl+0x3C + CanFireHeatCheck |
| Product word “Secondary” for `+0x3C` | **Probable** | Structural dual with input/fire |
| Name `CanFireAll…` for ∀ | **Probable** | Distinguishes from primary `CanFireAny` (∃) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Walk 3 hardpoints via `*(v+0x260)` | **Yes** |
| Skip null | **Yes** |
| Require vtbl+0x3C truthy | **Yes** |
| Then heat check; first fail → 0 | **Yes** |
| Exhaust → 1 | **Yes** |
| No invented ∃ / fire apply | **Yes** |

### Sealed CF sketch

```
Vehicle_CanFireAllSecondaryHeatOK_Inferred(vehicle) -> bool:
  table = *(vehicle + 0x260)
  for i in 0..2:
    w = table[i]
    if w == null: continue
    if ! w->vtbl[+0x3C](): continue   // not secondary-group
    if ! Weapon_CanFireHeatCheck(w):
      return false                    // ∀ broken
  return true                         // vacuous OK if no secondary slots
```

### Primary vs secondary heat quantifier (**High**)

| | Primary `0x004f5290` | Secondary `0x004f52e0` |
|---|---|---|
| Hardpoint table | same `*(v+0x260)`, 3 slots | same |
| Group vtbl | **+0x38** | **+0x3C** |
| Heat quantifier | **∃** heat-OK → 1 | **∀** heat-OK → 1 (first fail → 0) |
| Empty group | **0** | **1** |
| Fire walker twin | `0x004f50d0` | `0x004f5110` |

### Asm anchors

| Bytes / form | Meaning |
|---|---|
| `8B D9` | `ebx = this` (vehicle) |
| `8B 83 60 02 00 00` | `eax = [ebx+0x260]` |
| `8B 34 07` / `85 F6` | `esi = table[i]`; null skip |
| `FF 52 3C` | `call [vtbl+0x3C]` |
| `E8 …` → `Weapon_CanFireHeatCheck` | heat predicate |
| `74 0E` → `32 C0` path | heat fail → `al=0` ret |
| `83 C7 04` / `83 FF 0C` / `7C D5` | i+=4; i&lt;0xC loop |
| fallthrough `B0 01` | `al=1` ret |

---

## 5. Callers / callees

| Direction | Addr / symbol | Role |
|---|---|---|
| Caller (only) | `Input_TryFireSecondaryWeapons` `0x0091a550` | Secondary gun heat gate |
| Callee | `Weapon_CanFireHeatCheck` `0x0056aca0` | Per-weapon → vehicle heat&lt;max |
| Callee (indirect) | weapon vtbl **+0x3C** | Secondary-group predicate |
| Sibling | `0x004f5290` | Primary **∃** heat quantifier |
| Fire twin | `0x004f5110` | Secondary fire apply (no heat re-check) |

---

## 6. Gaps / open

1. Seal product method names for vtbl **+0x38** / **+0x3C**.
2. Why secondary uses **∀** while primary uses **∃** (design intent; CF sealed either way).
3. Runtime golden for multi-hardpoint overheat mixtures.
4. Bit-exact / Launcher deferred.

**Verdict:** **accept-with-gaps**
