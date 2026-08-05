# Dual A/B report — W31-E OWN `aa_0040d590` + `aa_00969830`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-E  
**Scope:** VAs `0x0040d590`, `0x00969830` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs + caller call-site bytes. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040d590` Class_009c7938_ScalarDeletingDtor | **accept** — scalar-dtor CF/ABI/vtbl[0]/false-noreturn sealed; product demangle naming-only |
| `aa_00969830` StringVec_PushFront_EnsureTrailingDirSep | **accept-with-gaps** — ESI ABI + front insert + trailing-sep stage sealed; nested helpers + product list English open |

---

## VA `0x0040d590` — sealed facts

1. **Body:** `0x0040d590`–`0x0040d5ad` exclusive (**29 B** / `0x1D`; pad `CC CC` then `FUN_0040d5b0`).
2. **ABI:** **ECX=`this`**; stack **flags**; **`RET 4`** (`C2 04 00`); returns **`this`** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** for vtbl family **`PTR_FUN_009c7938`**:
   - Always call complete dtor **`FUN_0040d820`**.
   - If `(flags & 1)`: `operator_delete(this)`.
   - Return `this`.
4. **Classification:** worker.
5. **Callers:** DATA only — dword @ `0x009c7938` = `0x0040d590` (vtbl[0]).
6. **Callees:** `FUN_0040d820`, `operator_delete`.
7. **Name:** `Class_009c7938_ScalarDeletingDtor` (Ghidra `FUN_0040d590`; **Inferred** structural).
8. **Decompile ≡ bytes**; Ghidra false-noreturn on `operator_delete` ignored (epilogue present).  
   Full hex: raw W31-E append (29 B).

### Gaps

- Product/MSVC demangle for host class behind `PTR_FUN_009c7938`.  
- Complete dtor body not owned (`FUN_0040d820`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d590_Class_009c7938_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0040d590_Class_009c7938_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d590_FUN_0040d590.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d590_FUN_0040d590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7938_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d590.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d590_FUN_0040d590.md` |
| Function named | `docs/reconstruction/functions/aa_0040d590_Class_009c7938_ScalarDeletingDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d590.md` |

---

## VA `0x00969830` — sealed facts

1. **Body:** `0x00969830`–`0x00969897` exclusive (**103 B** / `0x67`; pad `CC…`).
2. **ABI:** **ESI=`StringVecShell*`** (`*DAT_00d1f1fc` from callers); stack path `basic_string*`; **`RET 4`**; void. SEH `LAB_009acaf6`.
3. **Semantics:**
   - Build local string via **`FUN_009694e0`**: copy; if non-empty and last char ∉ {`:`, `/`, `\\`}, append `/`.
   - **`FUN_00430310`(ESI, &out, begin=`*(ESI+4)`, local)** → insert **one** `basic_string` (stride `0x1c`) at **begin** (push_front).
   - Destroy local string (IAT dtor).
4. **Classification:** worker.
5. **Callers:** `FUN_007b75b0` (`AssManager_InitPrecompileAndResolvers`) @ `0x007b770c`, `0x007b77cb`.
6. **Callees:** `FUN_009694e0`, `FUN_00430310`, IAT `~basic_string`.
7. **Name:** `StringVec_PushFront_EnsureTrailingDirSep` (Ghidra `FUN_00969830`; **Inferred**). Reject scaffold `Named_CalleeOf_Named_assManager_*` plate.
8. **Decompile ≡ bytes** for stage order; ESI ABI sealed from call-site `mov esi,[DAT_00d1f1fc]`.  
   Full hex: raw W31-E append (103 B).

### Gaps

- Product English for path-list role.  
- Nested `FUN_009694e0` / `FUN_00430310` / `FUN_004306b0` product plates.  
- Full `StringVecShell` product type beyond begin/end/0x1c.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00969830_StringVec_PushFront_EnsureTrailingDirSep.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00969830_StringVec_PushFront_EnsureTrailingDirSep.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00969830_FUN_00969830.md` |
| Annotated | `docs/reconstruction/raw/aa_00969830_FUN_00969830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_PushFront_EnsureTrailingDirSep.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00969830.cpp` |
| Function | `docs/reconstruction/functions/aa_00969830_FUN_00969830.md` |
| Function named | `docs/reconstruction/functions/aa_00969830_StringVec_PushFront_EnsureTrailingDirSep.md` |
| Scratch | `docs/reconstruction/tmp/a_00969830.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040d590` | Port as **scalar deleting only**: call complete dtor (`FUN_0040d820`), then optional `operator_delete` on bit0. vtbl[0] of `PTR_FUN_009c7938`. Do **not** inline tree clear (`0040d5b0`) or complete body here. |
| `00969830` | Port as **path-list push_front** on `*DAT_00d1f1fc`: ensure trailing dir sep, then `vector<string>::insert(begin, path)`. Callers must supply the StringVecShell as this (retail ESI). Closes unresolved `FUN_00969830` residual named in AssManager init clean. |
| Pair with | Complete dtor `FUN_0040d820`; tree clear `StdTree_Clear_PtrVal_Vtbl0C` (`0x0040d5b0`, W30-P); AssManager init `0x007b75b0` (W30-D); release dual front-erase on same vec. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs (+ call-site bytes for ESI). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Rejected AssManager scaffold alias plate for `00969830`.  
- Avoided bare `undefined4` in clean (`uint8_t` / explicit structs).
