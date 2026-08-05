# Dual A/B report — W28-Q OWN `aa_0053a8e0` + `aa_006cad30`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-Q  
**Scope:** VAs `0x0053a8e0`, `0x006cad30` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` (+ callers/callees/xrefs/signature). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md` → W28-Q  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0053a8e0` StdTree_InsertHint_Val12 | **accept-with-gaps** — Val12 hint-insert CF/ABI/`ret 0x0c`/neighbor paths sealed; product demangle open |
| `aa_006cad30` LinkPair_CanonAndSort_Inferred | **accept** — pair canon+qsort CF/ABI/key@+4 sealed; nested qsort residual |

---

## VA `0x0053a8e0` — sealed facts

1. **Body:** `0x0053a8e0`–`0x0053aa43` exclusive (**355** B); pad `CC` after `RET 0x0C`.
2. **ABI:** **`__thiscall`**; ECX = map (`head` @ `+4`, `size` @ `+8`); stack `(outIt*, hint*, value*)`; **`RET 0x0C`**; returns `outIt*`.
3. **Semantics:** MSVC `_Tree` **insert with hint** (unique Val12): empty → insert left of head; leftmost/end fast paths; neighbor via Prevnode (`FUN_005ae050`) / Nextnode (`FUN_005ae0b0`) + isnil@+0x19; else InsertOrFind (`FUN_0053a1a0`).
4. **Insert primitive:** `FUN_00539210` StdTree_InsertAndRebalance_Val12 (W27-Q sealed).
5. **Node:** Val12 — key@+0x0c color@+0x18 **isnil@+0x19**.
6. **Callees:** `FUN_00539210`, `FUN_0053a1a0`, `FUN_005ae050`, `FUN_005ae0b0`.
7. **Callers (1 / 1 xref):** `FUN_0053af20` @ `0053af74` (lower-bound / insert-or-return `node+0x10`).
8. **Name:** `StdTree_InsertHint_Val12` (Ghidra `FUN_0053a8e0`). Legacy Named_CVOGCharacter_* is **narrow**.
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23); decomp aliases Prevnode/Nextnode local as `param_3` — clean separates locals.

### Gaps

- Product English / demangle for map of `FUN_0053af20`.  
- Nested duals of pred/succ / InsertOrFind (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0053a8e0_StdTree_InsertHint_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0053a8e0_StdTree_InsertHint_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0053a8e0_FUN_0053a8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0053a8e0_FUN_0053a8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertHint_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0053a8e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0053a8e0_FUN_0053a8e0.md` |
| Function named | `docs/reconstruction/functions/aa_0053a8e0_StdTree_InsertHint_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_0053a8e0.md` |

---

## VA `0x006cad30` — sealed facts

1. **Body:** `0x006cad30`–`0x006cad7f` exclusive (**79** B); full body hex sealed.
2. **ABI:** **`__cdecl`**; `(pairArray*, count)`; void; plain **`ret`**.
3. **Semantics:** For each 8-byte pair, if `b->key4 < a->key4` swap; if `count > 1` call `FUN_006cac60(array, 0, count-1, count&0xffffff00)` dual-key quicksort.
4. **Key:** unsigned dword at object **+4**; stride **8**.
5. **Callees:** `FUN_006cac60` only.
6. **Callers (4 / 6 xrefs):** `FUN_006297e0` ×2, `FUN_00634450` ×2, `FUN_0055ff20`, `FUN_00560020`.
7. **Role:** prep for sorted pair merge (`006caaa0`) and pair-list commit (`006297e0`); dual-invoked on list A and B.
8. **Name:** `LinkPair_CanonAndSort_Inferred` (Ghidra `FUN_006cad30`). Legacy Named_VOG_DEBUG_* is **narrow**.
9. **Decompile ≡ bytes** for CF; low-byte clear of count is unused 4th arg to qsort.

### Gaps

- Product type of pair pointees.  
- Nested `FUN_006cac60` dual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006cad30_LinkPair_CanonAndSort_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006cad30_LinkPair_CanonAndSort_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006cad30_FUN_006cad30.md` |
| Annotated | `docs/reconstruction/raw/aa_006cad30_FUN_006cad30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LinkPair_CanonAndSort_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006cad30.cpp` |
| Function | `docs/reconstruction/functions/aa_006cad30_FUN_006cad30.md` |
| Function named | `docs/reconstruction/functions/aa_006cad30_LinkPair_CanonAndSort_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_006cad30.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0053a8e0` | Port Val12 map **insert-with-hint** (not raw always-insert). Preserve empty/leftmost/end/neighbor CF and InsertOrFind fallthrough. Use with `StdTree_InsertAndRebalance_Val12` + isnil@+0x19. Sole consumer today: create-from-pack style `FUN_0053af20` (operator[]-like return `node+0x10`). |
| `006cad30` | Before sorted dual-range walk / pair-list commit, **canon each pair by key@+4** then **sort**. Dual-call on both side lists. Do not skip when count==1 (canon still runs; qsort skipped). Closes nested residual left open by W27-M (`006297e0`) / W27-N (`006caaa0`). |
| Pair with | Insert rebalance `00539210`, merge `006caaa0`, commit `006297e0`, release `0055f4c0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + get_function_by_address (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` / structural StdTree names from evidence.
