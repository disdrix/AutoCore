# Dual A/B report — MEGA-118 OWN-ONLY (`0x004ce5c0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-118**  
**Scope:** VA `0x004ce5c0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_xrefs_to` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer residual of dualed **Client_SendInventoryUnequip** (`0x00862c00`); partition hint **Character_TownInventoryFallback**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004ce5c0` Character_TownInventoryFallback_Inferred | **accept-with-gaps** — CF/ABI/RET4/leaf/offsets/3 call sites sealed; product flag English + PDB open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): unequip-only / ECX=character / bare-ret / inventory-mutator / merge-with-004ce5f0 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004ce5c0` — sealed facts

1. **Body:** `0x004ce5c0`–`0x004ce5e3` (Ghidra end); **36 B** / `0x24` through final `RET 4`; `cc` pad then sibling `004ce5f0`.
2. **ABI:** **ECX** = mode host; stack `character*`; **AL** bool; **`RET 4`** ×3 exits.
3. **Semantics:** pure leaf predicate:
   - null character → false;
   - else true if `modeHost+0xf5`;
   - else `modeHost+0x7e != 0`.
4. **Callees:** none (leaf).
5. **Callers / xrefs (3 UNCONDITIONAL_CALL):**
   - `Client_SendInventoryUnequip` @ `0x00862caa` — ECX=`DAT_00d1b644`, push `DAT_00d1b6d8`; true → `char+0xcbc` free-slot retry.
   - `FUN_008012f0` mode-3 @ `0x00801351` — ECX=`client+0xe04`, push `client+0xe98`; true → locker grid `char+0xcbc`.
   - `FUN_008012f0` free-slot miss @ `0x00801654` — same ECX/stack; true → free-slot retry / mode **3**.
6. **Name:** `Character_TownInventoryFallback_Inferred` (Ghidra `FUN_004ce5c0`). Product map open → `_Inferred`. Retire `Named_CalleeOf_Client_SendInventoryUnequip_*`.
7. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.
8. **Sibling (not dualled):** `Character_HostModeGateForObjectV210` `0x004ce5f0` — same flags after object `vtbl+0x210(0)`.

### Gaps

- Product/PDB symbol.  
- Mode-host flag English (`+0xf5` / `+0x7e`); `DAT_00d1b644` ↔ `client+0xe04`.  
- Product “town” vs layout “locker” for `+0xcbc` (inv type 3).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004ce5c0_Character_TownInventoryFallback_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004ce5c0_Character_TownInventoryFallback_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004ce5c0_FUN_004ce5c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004ce5c0_FUN_004ce5c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_TownInventoryFallback_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004ce5c0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_SendInventoryUnequip_004ce5c0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_004ce5c0_FUN_004ce5c0.md` |
| Function named | `docs/reconstruction/functions/aa_004ce5c0_Character_TownInventoryFallback_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_SendInventoryUnequip  0x00862c00  [dualed parent]
  ├─ free-slot FUN_005714e0
  ├─ on fail: FUN_004ce5c0  Character_TownInventoryFallback_Inferred  [OWN MEGA-118]
  │     true → char+0xcbc (locker) free-slot retry
  └─ else toast space-full / send 0x203E

FUN_008012f0  (inventory move C2S 0x2036 builder)  [residual]
  ├─ mode 3: FUN_004ce5c0 → char+0xcbc place path
  └─ free-slot miss: FUN_004ce5c0 → retry / mode 3

FUN_004ce5f0  Character_HostModeGateForObjectV210  [dualed sibling; not OWN]
  └─ same +0xf5/+0x7e after object vtbl+0x210(0)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004ce5c0-mega-118-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004ce5c0` | Port as **pure bool gate**: `modeHost` this + `character*` stack, **`RET 4`**. No inventory mutation here. |
| True path | Callers rebind free-slot / mode-3 work to **`character+0xcbc`** (locker / inv type 3). |
| Flags | Preserve **`modeHost+0xf5`** then **`+0x7e`** without inventing product English. |
| Distinct from | sibling `004ce5f0` (adds object MI + vcall); free-slot `005714e0`; space helper `004f6a80`. |
| Pair with | dualed `Client_SendInventoryUnequip` `00862c00`; residual `FUN_008012f0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable

**Terminal:** false.
