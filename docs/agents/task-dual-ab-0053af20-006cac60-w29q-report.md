# Dual A/B report — W29-Q OWN `aa_0053af20` + `aa_006cac60`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-Q  
**Scope:** VAs `0x0053af20`, `0x006cac60` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` (+ callers/callees/xrefs/signature). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md` → W29-Q  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0053af20` StdTree_OperatorIndex_Val12 | **accept-with-gaps** — lower_bound/hit/miss/InsertHint CF/ABI/`ret 0x04`/mapped@+0x10 sealed; product demangle open |
| `aa_006cac60` LinkPair_QuickSort_DualKey_Inferred | **accept** — dual-key qsort CF/ABI/stride8/key@+4/left-recurse+right-tail sealed; `param_4` unused |

---

## VA `0x0053af20` — sealed facts

1. **Body:** `0x0053af20`–`0x0053af91` exclusive (**113** B); pad `CC` after final `RET 0x04`.
2. **ABI:** **`__thiscall`**; ECX = map (`head` @ `+4`); stack `(int* key)`; **`RET 0x04`**; returns `mapped*` at `node+0x10`.
3. **Semantics:** MSVC `_Tree` / map **operator[]-style** get-or-insert (unique Val12): lower_bound on signed key@+0x0c with isnil@+0x19; hit → return mapped; miss → InsertHint `{key,0,0}` → return new mapped.
4. **Insert primitive:** `FUN_0053a8e0` StdTree_InsertHint_Val12 (W28-Q sealed).
5. **Node:** Val12 — key@+0x0c mapped@+0x10/+0x14 color@+0x18 **isnil@+0x19**.
6. **Callees:** `FUN_0053a8e0` only.
7. **Callers (3 / 3 xrefs):** `FUN_005305b0` @ `005305e6`; `FUN_00530610` @ `00530646`; `CVOGCharacter_ApplyCreateFromPacket` @ `005352ee`.
8. **Name:** `StdTree_OperatorIndex_Val12` (Ghidra `FUN_0053af20`). Legacy Named_CalleeOf_CVOGCharacter_* is **narrow**.
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23); full body hex sealed.

### Gaps

- Product English / demangle for map element type per owner.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0053af20_StdTree_OperatorIndex_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0053af20_StdTree_OperatorIndex_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0053af20_FUN_0053af20.md` |
| Annotated | `docs/reconstruction/raw/aa_0053af20_FUN_0053af20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_OperatorIndex_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0053af20.cpp` |
| Function | `docs/reconstruction/functions/aa_0053af20_FUN_0053af20.md` |
| Function named | `docs/reconstruction/functions/aa_0053af20_StdTree_OperatorIndex_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_0053af20.md` |

---

## VA `0x006cac60` — sealed facts

1. **Body:** `0x006cac60`–`0x006cad2f` exclusive (**207** B); full body hex sealed.
2. **ABI:** **`__cdecl`**; `(pairArray*, lo, hi, unused)`; void; plain **`ret`**.
3. **Semantics:** Dual-key quicksort of 8-byte pairs: pivot mid; partition on unsigned `(a+4, b+4)`; swap full pairs; recurse left; right via outer-loop tail.
4. **Key:** unsigned dword at object **+4**; stride **8**.
5. **Callees:** self only (left recurse).
6. **Callers (2 / 2 xrefs):** `FUN_006cad30` LinkPair_CanonAndSort @ `006cad76`; self @ `006cad11`.
7. **Role:** nested qsort for sorted pair prep; sole external consumer is CanonAndSort (W28-Q).
8. **Name:** `LinkPair_QuickSort_DualKey_Inferred` (Ghidra `FUN_006cac60`). Legacy Named_VOG_DEBUG_* is **narrow**.
9. **Decompile ≡ bytes** for CF; **`param_4` unused** (dead pass-through from count low-byte clear).

### Gaps

- Product type of pair pointees.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006cac60_FUN_006cac60.md` |
| Annotated | `docs/reconstruction/raw/aa_006cac60_FUN_006cac60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LinkPair_QuickSort_DualKey_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006cac60.cpp` |
| Function | `docs/reconstruction/functions/aa_006cac60_FUN_006cac60.md` |
| Function named | `docs/reconstruction/functions/aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_006cac60.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0053af20` | Port Val12 map **operator[]** (get-or-insert), not bare lower_bound and not always-insert. Preserve signed key compare, isnil@+0x19, default mapped zeros, return **mapped@+0x10** (callers write two dwords). Use with `StdTree_InsertHint_Val12`. |
| `006cac60` | Dual-key qsort after per-pair canon. Match lexicographic `(a.Key4, b.Key4)` used by `LinkPair_SortedDiffWalk`. Do not invent use for 4th arg. Left recurse + right tail-loop is equivalent to dual recurse. |
| Pair with | InsertHint `0053a8e0`, CanonAndSort `006cad30`, merge `006caaa0`, commit `006297e0`. Closes residuals left open by W28-Q. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + get_function_by_address (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` / structural StdTree names from evidence.
