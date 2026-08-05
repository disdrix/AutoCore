# Dual A/B report — W36-B OWN `aa_0046c1b0` + `aa_0046bf90`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-B  
**Scope:** VAs `0x0046c1b0`, `0x0046bf90` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-B).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0046c1b0` NestedHash0x10_FindIterator_Inferred | **accept** — ESI=map / ECX=key* / EAX=out_it* / bare RET / identity hash / leaf sealed |
| `aa_0046bf90` NestedHash0x10_Insert_Inferred | **accept** — EDI=map / stack out+kv / RET 8 / rehash+buynode0x10 / pair{it,bool} sealed |

---

## VA `0x0046c1b0` — sealed facts

1. **Body:** `0x0046c1b0`–`0x0046c223` inclusive (**116 B** / `0x74`; pad `CC` then next).
2. **ABI:** **ESI=`map*`**, **ECX=`key*`**, **EAX=`out_it*`**; bare **`RET`**. Reject scaffold thiscall / gfxDeviceIB name.
3. **Semantics:** NestedHash0x10 **find-iterator**:
   - `idx = (*key) & mask(+0x20)`; fold if `idx >= bucket_count(+0x24)`.
   - Walk ordered chain `table[+0x14][idx] … table[idx+1]`; compare key at **`node+8`**.
   - Hit → `*out = node`; miss / greater → `*out = map+0x08` end sentinel.
   - **No** string-hash leaf (contrast `HashMap_FindIterator_Inferred` `0x0044e8c0`).
4. **Classification:** leaf worker.
5. **Callers (13):** sto factory `004449b0`/`00444a40`, `00437b00`/`00437c90`, `00449f20`/`0044a070`, `0044fe10`, `004641d0`, operator[] `0046bf40`, `0046c890`, `0074dba0`, `0096bc80`, GfxMesh `0098fef0`.
6. **Callees:** none.
7. **Name:** `NestedHash0x10_FindIterator_Inferred` (Ghidra `FUN_0046c1b0`; **Inferred**). **Reject** `Named_CalleeOf_Named_gfxDeviceIB_0046c1b0`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on ESI/ECX/EAX formals, bare RET, identity hash.  
   Full hex: raw W36-B append (116 B).

### Gaps

- Product/PDB NestedHash English.  
- Key domain (FourCC vs numeric) — dword eq sealed.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0046c1b0_NestedHash0x10_FindIterator_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0046c1b0_NestedHash0x10_FindIterator_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0046c1b0_FUN_0046c1b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0046c1b0_FUN_0046c1b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash0x10_FindIterator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046c1b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0046c1b0_FUN_0046c1b0.md` |
| Function named | `docs/reconstruction/functions/aa_0046c1b0_NestedHash0x10_FindIterator_Inferred.md` |

---

## VA `0x0046bf90` — sealed facts

1. **Body:** `0x0046bf90`–`0x0046c1ae` inclusive (**543 B** / `0x21F`; pad `CC` then sibling find).
2. **ABI:** **EDI=`map*`**, stack **`out_pair*`** + **`kv*`**; **`RET 0x8`**.
3. **Semantics:** NestedHash0x10 **insert-or-find**:
   - Load gate: if `maxidx(+0x24) <= list_size(+0xc)>>2` → grow mask (`*2+1`) or rebuild via `FUN_0044a380` + redistribute; `maxidx++`.
   - Find ordered insert point (identity hash).
   - Existing key → `{node, inserted=0}`.
   - Miss → `FUN_0046c2a0` buynode **`new(0x10)`** (next/prev/key/value), `FUN_0046c230(1, map+4)` list size++, splice + bucket-start repair → `{node, inserted=1}`.
4. **Classification:** worker.
5. **Callers (4):** `FUN_004449b0`, `FUN_00444a40`, `FUN_0046bf40`, `FUN_0098fef0`.
6. **Callees:** `FUN_0044a380`, `FUN_0046c2a0`, `FUN_0046c230`.
7. **Name:** `NestedHash0x10_Insert_Inferred` (Ghidra `FUN_0046bf90`; **Inferred**). **Reject** scaffold long Named_CalleeOf chain.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EDI + RET8 + pair out; unreachable block after first RET is dead fallthrough.  
   Full hex: raw W36-B append (543 B).

### Gaps

- Product/PDB English.  
- Full rehash redistribute bit-exact in clean (raw is authority).  
- Unowned callee contracts.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0046bf90_NestedHash0x10_Insert_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0046bf90_NestedHash0x10_Insert_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0046bf90_FUN_0046bf90.md` |
| Annotated | `docs/reconstruction/raw/aa_0046bf90_FUN_0046bf90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash0x10_Insert_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046bf90.cpp` |
| Function | `docs/reconstruction/functions/aa_0046bf90_FUN_0046bf90.md` |
| Function named | `docs/reconstruction/functions/aa_0046bf90_NestedHash0x10_Insert_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0046c1b0` | Port as **NestedHash0x10 find**: **ESI=map**, **ECX=key\***, **EAX=out_it\***, bare **RET**. Identity hash `key & mask`. Do **not** use string-hash twin ABI (`0x0044e8c0`). |
| `0046bf90` | Port as **NestedHash0x10 insert-or-find**: **EDI=map**, stack out-pair + kv, **RET 8**. Node **0x10**. Rehash under load. Do **not** treat as find-only. |
| Shared | Same NestedHash0x10 bag as W34-E ctor `0x00457ac0` / once-gets / sto factory maps / GfxMesh edge bag. Server needs one correct u32-key ordered-bucket hash table (find + insert). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00457ac0` | NestedHash_Ctor_Sentinel0x10 (W34-E) |
| `0x00438c40` / `0x00438ca0` | Sto factory map once-gets (W35-D) |
| `0x004449b0` / `0x00444a40` | Sto factory insert wrappers (W36-A/C partition) |
| `0x0046bf40` | NestedHash operator[] shell (find→insert→value*) |
| `0x0046c2a0` | Buynode `new(0x10)` |
| `0x0046c230` | List size++ / `"list<T> too long"` |
| `0x0044a380` | Bucket vector resize |
| `0x0044e8c0` | String-hash HashMap find twin (different ABI) |
| `0x0098fef0` | GfxMesh_BuildNonInteriorEdgeIB (W35-F consumer) |

Closes W36-B OWN pair: NestedHash0x10 **find** + **insert** left open as high-mention nested callees under sto factory / GfxMesh / operator[] paths.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Distinguished identity-hash NestedHash0x10 find from string-hash `HashMap_FindIterator_Inferred`.
