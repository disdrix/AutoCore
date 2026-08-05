# Review A (reconstruction fidelity): `aa_005e07d0` LootCatalog_FillCandidateIds_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e07d0` |
| **VA** | `0x005e07d0` |
| **Canonical name** | `LootCatalog_FillCandidateIds_Inferred` |
| **Ghidra name** | `FUN_005e07d0` |
| **Prior names** | `FUN_005e07d0`; scaffold Named_CalleeOf…CVOGReaction_Dispa |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005e07d0_LootCatalog_FillCandidateIds_Inferred.md` |
| **System** | inventory / loot catalog generation |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callers, helper `005e0480` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Band/level table walker that pushes candidate item IDs into an out-vector** for the unfiltered catalog roll (`LootCatalog_RollCandidateId_Inferred` `0x005e1030`).

`this` / `param_1` = loot catalog host (global from `FUN_005e0580` → `DAT_00bc56d8`). Table base arrives as `param_11` (caller selects `this+0xc` vs `this+0x8700c`).

### High-level CF

1. **Map quality enum** `param_5` → band index `local_1c` ∈ {0,1,2,3} (3+ clamps to 3).
2. **Map type code** via `FUN_005e0480(param_6)` → type-row index (`iVar6`; −1 = “all subtypes” path).  
   `005e0480` maps gear type codes (6,8,10,0xc,0xe,0x10,0x1a,0x1c,0x32,0x34,0x44,0x46,…) → 0..0xb or `0xffffffff`.
3. **Optional faction/type affinity filter flag** (`param_9` non-null):
   - Level `param_2 < 6` → keep probability 1.0; else `1.0 - (level-5)*0.05`, floored at **0.2**.
   - Draw unit random; if `u <= keepProb` set `bVar4 = true` (later strip non-matching IDs).
4. **Clamp level window** `param_3`/`param_4` into usable bands (min/max with specials 1..0x4b / 5..0x50) then **decrement to 0-based** indices.
5. **Outer loop** `local_20 = param_8` downto 0 (quality/rank descent):
   - Early success if out-vector already non-empty **and** `local_20 < 0` → return 1.
   - For each level index in `[param_3, param_4]`:
     - If type index `< 0`: walk **12** subtype buckets (stride `0xb40` dwords-ish) copying ID ranges into out-vector via grow helper `FUN_004073a0` or in-place push.
     - Else: single typed bucket at computed offset; copy `[begin,end)` IDs.
     - If `param_7 == 0`: also merge a **secondary** table slice (broader pool).
   - If affinity flag: compact out-vector — keep IDs whose resolved entry matches catalog owner faction / related (2↔3 swap allowed) via `FUN_00418b80` lookup; else `memmove` erase.
6. Return 0 (low byte clear) when descent finishes without early success path.

**Sole live caller:** `FUN_005e1030` (then random-picks one ID).

**Not** the pick itself, not the filtered fill (`005e0cd0`), not the global getter.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_005e07d0_FUN_005e07d0.md` |
| Raw / annotated / clean | `aa_005e07d0_*` / `FUN_005e07d0.cpp` |
| Live decompile | Ghidra `0x005e07d0` (2026-07-29) — **≡ scaffold CF** |
| Type map | live `FUN_005e0480` |
| Caller dual | `A\|B_aa_005e1030_LootCatalog_RollCandidateId_Inferred` |
| Constants | `read_memory` doubles/floats below |

---

## 3. Constants (`read_memory`)

| Symbol | Bytes | Value / role |
|---|---|---|
| `_DAT_00aaa5f8` | `00 00 00 00 00 00 f0 3f` | **1.0** double (keep base) |
| `_DAT_00aaa5f0` | `9a 99 99 99 99 99 a9 3f` | **0.05** double (per level above 5) |
| `_DAT_009dbf10` | `00 00 00 a0 99 99 c9 3f` | **~0.2** double (keep floor) |
| `DAT_00aaa638` | `80 00 80 37` | **1/65536** (unit u16 scale) |

---

## 4. Signature (decompiler-shaped)

```c
// __thiscall catalog; many stack formals (roll context from 005e1030 pack)
uint __thiscall LootCatalog_FillCandidateIds_Inferred(
    void *catalog,          // param_1 / this
    int level,              // param_2
    int levelLo,            // param_3 — clamped/dec'd
    int levelHi,            // param_4 — clamped/dec'd
    int qualityEnum,        // param_5 → band 0..3
    int typeCode,           // param_6 → FUN_005e0480
    char skipSecondary,     // param_7 — 0 merges extra slice
    int rankCursor,         // param_8 — outer descent start
    void *affinityKey,      // param_9 — optional filter enable + compare key
    void *outVector,        // param_10 — std::vector-like {?,begin@+4,end@+8,cap@+0xc}
    int tableBase);         // param_11 — absolute table root
// returns: 1 if early non-empty success on rank underflow; else 0-ish
```

Formal English is **Probable** from structure; exact product names residual.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Fills dword ID out-vector from catalog tables | **Confirmed** | push / `004073a0` |
| Quality → 0..3 band | **Confirmed** | |
| Type via `005e0480` (−1 = all-subtypes loop ×12) | **Confirmed** | helper sealed |
| Level clamp + 0-based adjust | **Confirmed** | |
| Rank descent outer loop | **Confirmed** | |
| Optional affinity compact with 2↔3 exception | **High** | body |
| Keep-prob `1-(L-5)*0.05` floor 0.2 | **Confirmed** | constants |
| Sole caller `005e1030` | **High** | |
| Clean ≡ raw ≡ live CF | **High** | large body; scaffold match |
| Full table geometry product docs | **Tentative** | strides residual |
| Exact formal names | **Tentative** | |

---

## 6. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Band/type map + clamp | **Yes** |
| Affinity pre-roll | **Yes** |
| Nested copy loops + secondary merge | **Yes** |
| Compact filter | **Yes** |
| Early return 1 / fallthrough 0 | **Yes** |

---

## 7. Gaps / open

1. Full product schema of table roots `+0xc` / `+0x8700c` and cell strides (`0x90`, `0xb40`, `0x3c0`, …).
2. Exact meaning of rank cursor `param_8` vs quality band.
3. Affinity key object layout (`+0x10` type, `+0x14` flag) product names.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — fill role + main CF **High**; geometry English residual.
