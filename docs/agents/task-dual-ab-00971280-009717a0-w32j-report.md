# Dual A/B report — W32-J OWN `aa_00971280` + `aa_009717a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-J  
**Scope:** VAs `0x00971280`, `0x009717a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00971280` AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred | **accept-with-gaps** — RET8 + absent-tree gate + success/fail rings sealed; product method English + nested dual open |
| `aa_009717a0` AssPreloader_EnqueueKeyAndDeps_Inferred | **accept-with-gaps** — ECX/RET4/return0 + push→deps→enqueue→clear sealed; nested dep-collector dual open |

---

## VA `0x00971280` — sealed facts

1. **Body:** `0x00971280`–`0x00971472` exclusive (**498 B** / `0x1F2`; pad `CC`; Ghidra listed end `00971471`).
2. **ABI:** stack **`(AssPreloader* host, KeyVec* keys)`**; epilogue **`RET 8`** (`C2 08 00`); void. SEH `LAB_009afdde`. KeyVec: `+0x04` begin*, `+0x08` end* (flat dword pointer range).
3. **Classification:** **worker**.
4. **Semantics:** For each key* in range:
   - `FUN_00970fc0` (EAX=host).
   - Tree lower_bound on **host+0xDC** (`FUN_0044a860`); require iterator == **host+0xE0** (end header → **absent**).
   - Snapshot children: `FUN_0043c5f0` with ECX=`*(host+0x110)+0x28` into local GuardedVector.
   - For each child: `result = (*vtbl+0x0C)(key*)`. On first non-zero:
     - Optional CS **host+0x60** if `*(host+0x78)`; push `{*key, result}` via **`FUN_0043e970`** on **host+0x4C** (stride-2 U32x2).
     - Find-or-insert key in tree (`FUN_0043d700`); set value **1**.
   - If all fail: format name (`FUN_0096a630`), log **`assPreloader.cpp:0x241`** `"PRELOAD: unable to preload child asset %s"`; optional CS **host+0x90** if `*(host+0xA8)`; **`FUN_0043d670`** push key onto **host+0x7C**.
   - `Sleep(0)`; destroy local (`FUN_0040d9c0`).
5. **Callers (1):** `FUN_00972140` @ `0x009722cd` (`push vec; push host; call`).
6. **Callees:** `FUN_00970fc0`, `FUN_0044a860`, `FUN_0043c5f0`, vtbl+`0xc`, `FUN_0043e970`, `FUN_0043d700`, `FUN_0096a630`, `FUN_0076cec0`, `vog_LogMessage`, `~basic_string`, `FUN_0043d670`, `Sleep`, `FUN_0040d9c0`, CS enter/leave.
7. **Name:** `AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred` (Ghidra `FUN_00971280`; **Inferred** structural; product family via `assPreloader.cpp` string). Reject scaffold `Named_assPreloader_00971280` plate.
8. **Decompile ≡ raw** for CF; **bytes supersede** tree/EDI formals and **RET 8**.  
   Full hex: raw W32-J append (498 B).

### Gaps

- Product/PDB method English.  
- Nested drain / child snapshot / vtbl product duals (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00971280_AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00971280_AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00971280_FUN_00971280.md` |
| Annotated | `docs/reconstruction/raw/aa_00971280_FUN_00971280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971280.cpp` |
| Function | `docs/reconstruction/functions/aa_00971280_FUN_00971280.md` |
| Function named | `docs/reconstruction/functions/aa_00971280_AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.md` |

---

## VA `0x009717a0` — sealed facts

1. **Body:** `0x009717a0`–`0x0097181c` exclusive (**124 B** / `0x7C`; pad `CC`; Ghidra listed end `0097181b`).
2. **ABI:** **ECX=this** (`MOV ESI,ECX`); stack **`const int* key`**; epilogue **`RET 4`**; returns **0** (`XOR EAX,EAX`). SEH `LAB_009afe15`.
3. **Classification:** **worker**.
4. **Semantics:**
   - Zero local GuardedVector ring.
   - **`FUN_0043d670`(local, key)** push_back thiscall.
   - **`FUN_00744360`(key, &local)** with **ECX = \*(\*(this+0x110)+0x64)** (dependency expand into local).
   - **`FUN_00971640`(this)** with **ESI=local** → `AssPreloader_EnqueueEligibleFromRing_Inferred` (W31-K).
   - **`FUN_005b2ba0`(local)** clear/free.
   - Return 0.
5. **Callers (5 xrefs):** `FUN_004ed310` @ `0x004ed43b` (ECX=`[manager+0x6c]`); `FUN_007b69e0` @ `0x007b6a09`; plus `0x009137c1`, `0x009137f8`, `0x0091382f`.
6. **Callees:** `FUN_0043d670`, `FUN_00744360`, `FUN_00971640`, `FUN_005b2ba0`.
7. **Name:** `AssPreloader_EnqueueKeyAndDeps_Inferred` (Ghidra `FUN_009717a0`; **Inferred**). Single-key twin of multi-key loop `FUN_00971820`.
8. **Decompile ≡ raw** for stage order; **bytes supersede** dep-host ECX and ESI handoff into `00971640`.  
   Full hex: raw W32-J append (124 B).

### Gaps

- Product/PDB method English.  
- Nested `FUN_00744360` product dual (W32-L, not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009717a0_AssPreloader_EnqueueKeyAndDeps_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009717a0_AssPreloader_EnqueueKeyAndDeps_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009717a0_FUN_009717a0.md` |
| Annotated | `docs/reconstruction/raw/aa_009717a0_FUN_009717a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_EnqueueKeyAndDeps_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009717a0.cpp` |
| Function | `docs/reconstruction/functions/aa_009717a0_FUN_009717a0.md` |
| Function named | `docs/reconstruction/functions/aa_009717a0_AssPreloader_EnqueueKeyAndDeps_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00971280` | Port with **two stack args + ret 8**. Only process keys **absent** from tree **host+0xDC** (end at **+0xE0**). Success → stride-2 **+0x4C** + tree value 1; fail → log + **+0x7C**. Do **not** use pending **+0x1c** here. Honor optional CS flags **+0x78/+0xA8**. |
| `009717a0` | Port as **ECX this** + stack key + **ret 4** + **return 0**. Stage: seed local → deps via **\*(this+0x110)+0x64** → W31-K enqueue (ESI=local) → clear. Do not skip dep expand. |
| Pair with | W31-K `AssPreloader_EnqueueEligibleFromRing_Inferred` (`0x00971640`); W31-I `GuardedVector_PushBack_Thiscall` (`0x0043d670`); W31-J sibling stride-2 `FUN_0043e970`; W32-K `FUN_00971820` / `FUN_00972140`; W32-L `FUN_00744360`. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00971640` | EnqueueEligibleFromRing (W31-K) |
| `0x00971700` / `0x00971820` | bulk / multi-key enqueue wrappers |
| `0x00972140` | sole caller of `00971280` (W32-K) |
| `0x00970fc0` | pre-loop drain/process on host |
| `0x0043e970` | GuardedVector_PushBack_Stride2_U32x2 |
| `0x0043d670` | GuardedVector_PushBack_Thiscall |
| `0x00744360` | dependency key collector (W32-L) |
| `0x005b2ba0` | GuardedVector clear/free |
| `0x004ed310` | primary external caller of enqueue-key |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory (+ xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- No invented product plates; structural `_Inferred` names only.  
- Rejected scaffold `Named_assPreloader_00971280` alias plate.  
- Avoided bare `undefined4` in clean (`uint8_t` / `void*` / explicit structs).
