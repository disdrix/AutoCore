# Dual A/B report — W34-B OWN `aa_006874b0` + `aa_009698a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-B  
**Scope:** VAs `0x006874b0`, `0x009698a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs + RTTI/ThrowInfo walk + wrapper bytes. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-B).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006874b0` IdvFileError_Ctor_MsgBracketErrno | **accept** — thiscall RET8 / RTTI IdvFileError / ThrowInfo / message formula sealed |
| `aa_009698a0` AssPathList_ListBasenames_FilterPush_Inferred | **accept-with-gaps** — EDI ABI + `"*.*"` list + filter push sealed; classifier/resolve product open |

---

## VA `0x006874b0` — sealed facts

1. **Body:** `0x006874b0`–`0x00687624` exclusive (**372 B** / `0x174`; pad `CC`).
2. **ABI:** **`__thiscall`** ECX=`this`; stack **`msg*`**, **`include_errno`** (char); **`RET 8`** (`C2 08 00`); returns **`this`** in EAX. SEH `LAB_009a9f39`.
3. **Semantics:** MSVC **`IdvFileError`** constructor:
   - `part = include_errno ? strerror(*errno()) : ""`
   - `built = msg + " [" + part + "]"` via `FUN_00416490` / `FUN_00416410` (literals `DAT_009ead6c` / `DAT_00a62c94`)
   - Base `FUN_00685b40(built)` → exception + intermediate vtbl `PTR_FUN_009ea778` + string @ `this+0x0c`
   - Install final vtbl **`PTR_FUN_009ead64`**
4. **Type:** RTTI `.?AVIdvFileError@@` @ `0x00af5480`. Catchables: IdvFileError → `std::runtime_error` → `exception` (size **0x28**). ThrowInfo **`DAT_00ac9e00`**.
5. **Classification:** worker (exception ctor; throw is caller-side).
6. **Callers:** 20+ SpeedTree parse workers (47 xrefs); e.g. `FUN_00687e40` (`"malformed lod info"`, flag 0) → ctor → `_CxxThrowException`.
7. **Callees:** `FUN_00685b40`, `FUN_00416490`, `FUN_00416410`, `_errno`, `strerror`, string ctor/dtor.
8. **Name:** `IdvFileError_Ctor_MsgBracketErrno` (Ghidra `FUN_006874b0`; **product RTTI**). Reject scaffold `Named_CalleeOf_*`.
9. **Related:** scalar-dtor `FUN_00687630` (vtbl[0]).  
   Full hex: raw W34-B append (372 B).

### Gaps

- Product method English on intermediate base vtbl / `what()`.  
- Full dual of base `FUN_00685b40` (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006874b0_IdvFileError_Ctor_MsgBracketErrno.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006874b0_IdvFileError_Ctor_MsgBracketErrno.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006874b0_FUN_006874b0.md` |
| Annotated | `docs/reconstruction/raw/aa_006874b0_FUN_006874b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/IdvFileError_Ctor_MsgBracketErrno.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006874b0.cpp` |
| Function | `docs/reconstruction/functions/aa_006874b0_FUN_006874b0.md` |
| Function named | `docs/reconstruction/functions/aa_006874b0_IdvFileError_Ctor_MsgBracketErrno.md` |
| Scratch | `docs/reconstruction/tmp/a_006874b0.md` |

---

## VA `0x009698a0` — sealed facts

1. **Body:** `0x009698a0`–`0x00969a4c` exclusive (**428 B** / `0x1AC`; pad `CC` then wrapper).
2. **ABI:** **stdcall** 3 stack formals + **EDI = out dword-vec shell***; **`RET 0xC`** (`C2 0C 00`); returns **0**. SEH `LAB_009afb56`.
3. **Semantics:**
   - Outer: walk `path_list` string vec (`+4` begin, `+8` end, stride **0x1c**).
   - `pattern = path + "*.*"` (`DAT_00aa1d38`) via `FUN_00416490`.
   - `FUN_0076b3f0` → flat basename string vec (W33-C).
   - Inner: `FUN_00989e00` with **ECX=`0x00d1eac8`** → handle; `classifier->vtbl[+0x10](&handle, &class_id)`.
   - If `type_filter == 0 || class_id == type_filter`: push handle to **EDI** vec (`FUN_00436ef0` if capacity else `FUN_0043bfb0` grow).
4. **Wrapper:** `0x00996aa0` (28 B, not a Ghidra function): `path_list = *DAT_00d1f1fc`, `EDI = out`, call this; sole code xref.
5. **Classification:** worker.
6. **Callers:** thin wrapper only.
7. **Callees:** `FUN_00416490`, `FUN_0076b3f0`, `FUN_00989e00`, `FUN_00436ef0`, `FUN_0043bfb0`, `~basic_string`, `operator_delete`.
8. **Name:** `AssPathList_ListBasenames_FilterPush_Inferred` (Ghidra `FUN_009698a0`; **Inferred**).  
   Decompiler `unaff_EDI` is intentional register formal. Ghidra false-noreturn on `operator_delete` ignored (loop continues).  
   Full hex: raw W34-B append (428 B).

### Gaps

- Product English for classifier `vtbl[+0x10]` and `FUN_00989e00` handle type.  
- AssManager plate for `DAT_00d1f1fc` (pair W31-E).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009698a0_AssPathList_ListBasenames_FilterPush_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009698a0_AssPathList_ListBasenames_FilterPush_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009698a0_FUN_009698a0.md` |
| Annotated | `docs/reconstruction/raw/aa_009698a0_FUN_009698a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPathList_ListBasenames_FilterPush_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009698a0.cpp` |
| Function | `docs/reconstruction/functions/aa_009698a0_FUN_009698a0.md` |
| Function named | `docs/reconstruction/functions/aa_009698a0_AssPathList_ListBasenames_FilterPush_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_009698a0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006874b0` | Port as **IdvFileError ctor**: build `msg + " [" + optional strerror + "]"`, base exception+string (`FUN_00685b40`), set IdvFileError vtbl. Do **not** throw inside this VA — callers `_CxxThrowException(..., DAT_00ac9e00)`. Object size **0x28**. |
| `009698a0` | Port as **path-list basename collect with filter**: for each path, list `"*.*"` basenames, resolve, classify, push matching handles to **EDI** out-vec. Wrapper binds Ass path list `*DAT_00d1f1fc`. No recurse / no full-path join. |
| Pair with | Base `FUN_00685b40`; scalar-dtor `FUN_00687630`; W33-C `Fs_ListDirBasenames_Inferred` (`0076b3f0`); W31-E Ass path vec / `DAT_00d1f1fc`; W33-F string `operator+`; resolve `FUN_00989e00`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs (+ RTTI/ThrowInfo + wrapper). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; RTTI name used for IdvFileError; structural `_Inferred` for path-list unit.  
- Rejected scaffold Named_CalleeOf plates.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit shells).
