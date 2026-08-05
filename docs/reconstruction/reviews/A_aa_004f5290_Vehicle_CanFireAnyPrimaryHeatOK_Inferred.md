# Review A (reconstruction fidelity): `aa_004f5290` Vehicle_CanFireAnyPrimaryHeatOK_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5290` |
| **VA** | `0x004f5290` |
| **Canonical name** | `Vehicle_CanFireAnyPrimaryHeatOK_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f5290_Vehicle_CanFireAnyPrimaryHeatOK_Inferred.md` |
| **System** | `combat` / vehicle weapon heat gate |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Vehicle **primary heat quantifier** (predicate only). Walks the **3-slot weapon hardpoint pointer table** at `*(vehicle+0x260)` (indices 0..2, byte stride 4 / bound `0xC`). For each non-null weapon:

1. Call weapon vtbl **`+0x38`** (thiscall on weapon) — group/role predicate (primary twin of secondary `+0x3C`).
2. If true, call **`Weapon_CanFireHeatCheck(weapon)`**.
3. On first heat-OK primary → **return 1** (**existential ∃**).

If no primary-marked slot is heat-OK (including empty / all-null table) → **return 0**.

Sole caller: `Input_TryFirePrimaryWeapons_Inferred` (`0x00922270` @ `0x00922361`), after tip `0x12`, before primary fire walker `FUN_004f50d0`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f5290_FUN_004f5290.md` |
| Annotated | `docs/reconstruction/raw/aa_004f5290_FUN_004f5290.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_CanFireAnyPrimaryHeatOK_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f5290_Vehicle_CanFireAnyPrimaryHeatOK_Inferred.md` |
| Sibling secondary | `FUN_004f52e0` (Ghidra decompile) — `vtbl+0x3C` + **universal ∀** heat OK |
| Fire twin | `FUN_004f50d0` — same `+0x260` / `vtbl+0x38` walk → `FUN_0056d520` |
| Heat callee dual | `reviews/A_aa_0056aca0_Weapon_CanFireHeatCheck.md` |
| Parent dual | `reviews/A_aa_00922270_Input_TryFirePrimaryWeapons_Inferred.md` |
| Hardpoint table dual | `reviews/A_aa_004f8b80_Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.md` |
| Ghidra | `decompile_function` + `analyze_function_complete` + `read_memory` @ `0x004f5290` (80 B) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` / ECX = vehicle (`param_1`) | **High** | Asm: `mov ebx,ecx`; caller loads `char+0x250` into ECX |
| Table base `*(vehicle+0x260)` (pointer-to-array) | **High** | Asm `mov eax,[ebx+0x260]` then `[edi+eax]`; sealed on sibling duals |
| Loop: `i=0; i+=4; while i<0xC` → **3 slots** | **High** | Decomp + asm `cmp edi,0xC` / `jl` |
| Null weapon skipped | **High** | `test esi,esi` / `je` |
| Group filter = weapon vtbl **`+0x38`** thiscall → bool | **High** CF | Asm `call [edx+0x38]`; dual of secondary `+0x3C` |
| Heat gate = `Weapon_CanFireHeatCheck` on weapon ECX | **High** | Named callee; pure heat&lt;max on owner vehicle |
| Quantifier = **∃** (first heat-OK → 1; else 0) | **High** | Early `return 1`; fallthrough `xor al,al` |
| Empty / no-primary / all-overheat → **0** | **High** | Opposite of secondary empty→1 |
| Pure predicate (no fire, no heat write) | **High** | Only vtbl+0x38 + CanFireHeatCheck |
| Product word “Primary” for `+0x38` | **Probable** | Structural dual with secondary input/fire; no RTTI/string in unit |
| Product name without retail string | **Probable** | `_Inferred`; role sealed by CF + call graph |
| Ghidra signature `undefined FUN…(void)` | **Noise** | Decomp `__fastcall(int)` + asm ECX; return AL bool |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Walk 3 hardpoints via `*(v+0x260)` | **Yes** |
| Skip null | **Yes** |
| Require vtbl+0x38 truthy | **Yes** |
| Then heat check; first OK → 1 | **Yes** |
| Exhaust → 0 | **Yes** |
| No invented secondary-style ∀ / log | **Yes** |

### Sealed CF sketch

```
Vehicle_CanFireAnyPrimaryHeatOK_Inferred(vehicle) -> bool:
  table = *(vehicle + 0x260)          // weapon* [3]
  for i in 0..2:
    w = table[i]
    if w == null: continue
    if ! w->vtbl[+0x38](): continue   // not primary-group
    if Weapon_CanFireHeatCheck(w):    // vehicle heat < max
      return true                     // ∃
  return false
```

### Primary vs secondary heat quantifier (**High**)

| | Primary `0x004f5290` | Secondary `0x004f52e0` |
|---|---|---|
| Hardpoint table | same `*(v+0x260)`, 3 slots | same |
| Group vtbl | **+0x38** | **+0x3C** |
| Heat quantifier | **∃** heat-OK → 1 | **∀** heat-OK → 1 (first fail → 0) |
| Empty group | **0** | **1** |
| Fire walker twin | `0x004f50d0` | `0x004f5110` |

### Asm anchors (`read_memory` + decomp)

| Bytes / form | Meaning |
|---|---|
| `8B D9` | `ebx = this` (vehicle) |
| `8B 83 60 02 00 00` | `eax = [ebx+0x260]` |
| `8B 34 07` / `85 F6` | `esi = table[i]`; null skip |
| `FF 52 38` | `call [vtbl+0x38]` |
| `E8 …` → `Weapon_CanFireHeatCheck` | heat predicate |
| `75 0E` → `B0 01` | heat OK → `al=1` ret |
| `83 C7 04` / `83 FF 0C` / `7C D5` | i+=4; i&lt;0xC loop |
| fallthrough `32 C0` | `al=0` ret |

---

## 5. Callers / callees

| Direction | Addr / symbol | Role |
|---|---|---|
| Caller (only) | `Input_TryFirePrimaryWeapons_Inferred` `0x00922270` @ `0x00922361` | Primary gun path heat gate |
| Callee | `Weapon_CanFireHeatCheck` `0x0056aca0` | Per-weapon → vehicle heat&lt;max |
| Callee (indirect) | weapon vtbl **+0x38** | Primary-group predicate |
| Sibling | `FUN_004f52e0` | Secondary **∀** heat quantifier |
| Fire twin | `FUN_004f50d0` | Primary fire apply (no heat re-check in that walker) |

---

## 6. Gaps / open

1. Seal product method name for weapon vtbl **+0x38** / **+0x3C** (IsPrimary/IsSecondary_Inferred) — no RTTI in this unit.
2. Global Ghidra/NAMING_REGISTRY rename from residual `FUN_004f5290` (out of force-rename unless owned).
3. Runtime: one of two primaries overheated → still allow primary fire path (∃); both overheat → silent skip at caller (no secondary heat log).
4. Confirm whether turret slot at `+0x264` is ever in the `+0x260` table or is intentionally out-of-band for this gate (table-only walk — **High** for this body).
5. Bit-exact vs retail deferred.

**Verdict:** **accept-with-gaps**
