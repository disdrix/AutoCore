# Dual A/B report — W21-N OWN-ONLY (`0x00745ea0`, `0x0044e8c0`)

**Date:** 2026-07-29  
**Agent:** W21-N  
**Scope:** OWN VAs only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + `get_function_by_address`. No `disassemble_bytes`.  
**Program:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | VA | Canonical | Verdict |
|------|-----|-----------|---------|
| `aa_00745ea0` | `0x00745ea0` | `NDResource_DecRef` | **accept** — soft shell decref sealed by bytes |
| `aa_0044e8c0` | `0x0044e8c0` | `HashMap_FindIterator_Inferred` | **accept-with-gaps** — find CF + register ABI sealed |

---

## `0x00745ea0` — NDResource_DecRef

### Sealed facts

1. **`__thiscall`**, ECX = NDResource shell; **0 stack args**; plain **`ret`** (`C3`). Body `0x00745ea0`–`0x00745ed9`.  
2. Optional lock: flag **`this+0x38`**; CS at **`this+0x20`**. Leave re-checks flag as **`[CS+0x18]`** (same byte).  
3. IAT Enter `0x009c61bc`, Leave `0x009c61b8` (same as acquire sibling).  
4. If **`refcount (this+0x10) != 0`**: decrement; return **0**. Else return **`0xffffffff`** (no under-decrement).  
5. **No** free, **no** vtbl, **no** inner/`+0x1c` touch — pure soft decref status.  
6. Sibling acquire: **`NDResource_AcquireInnerObject`** (`0x00745ee0`) bumps same `+0x10` under same layout.  
7. Decompile ≡ bytes (stable vs 2026-07-23 raw). 12 xrefs.

### Gaps

- Product English method spelling.  
- Caller policy on `-1`.  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00745ea0_NDResource_DecRef.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00745ea0_NDResource_DecRef.md` |
| Function record | `docs/reconstruction/functions/aa_00745ea0_FUN_00745ea0.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/NDResource_DecRef.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00745ea0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00745ea0_FUN_00745ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_00745ea0_FUN_00745ea0.annotated.md` |

---

## `0x0044e8c0` — HashMap_FindIterator_Inferred

### Sealed facts

1. Custom ABI: **`EDI` = map***, **`EBX` = key***, stack **`out_it*`**, **`ret 4`**, returns `out_it*` in EAX. Body `0x0044e8c0`–`0x0044e945`.  
2. Hash via **`FUN_0043b870`**: ELF-style string hash on `*(char**)key`.  
3. Bucket: `(hash & mask map+0x20)`; fold `idx += -1 - (mask>>1)` when `idx >= bucket_count map+0x24`.  
4. Table at **`map+0x14`**: chain from `table[idx]` to **`table[idx+1]`** (adjacent end). Nodes: **next `@+0`**, **key dword `@+8`**.  
5. Ordered walk: advance while `node.key < *key`; equal → write node; greater/empty/exhaust → write **end sentinel `map+0x08`**.  
6. Primary caller: **`NDResourceCache_LookupOrCreate`** (`0x0075dba0`); **20** xrefs total.  
7. Decompiler `unaff_EDI`/`unaff_EBX` are **live formals**, not junk — sealed against “junk register” residual.

### Gaps

- Product container / method name (`_Inferred`).  
- Key domain (interned string pointer vs numeric id) — equality is dword, not strcmp.  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0044e8c0_HashMap_FindIterator_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0044e8c0_HashMap_FindIterator_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0044e8c0_FUN_0044e8c0.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/HashMap_FindIterator_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0044e8c0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0044e8c0_FUN_0044e8c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044e8c0_FUN_0044e8c0.annotated.md` |

---

## AutoCore impact

- **NDResource lifetime:** ports must pair `AcquireInnerObject` (+1) with this soft **`DecRef`** (0 / -1); do not treat this unit as full `Release`/free. Flag `+0x38` gates CS on both sides.  
- **Resource cache lookup:** find helper expects **map in EDI, key in EBX**, out-iterator on stack; miss returns **`map+0x08`**. Do not assume pure stdcall stack formals. Bucket chains are **key-ordered**.

---

## Compliance

| Rule | Status |
|------|--------|
| OWN VAs only (`00745ea0`, `0044e8c0`) | Yes |
| Dual A + B per VA | Yes |
| raw + annotated + reconstructed-exact + function record | Yes |
| `decompile_function` + `read_memory` (no `disassemble_bytes`) | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
