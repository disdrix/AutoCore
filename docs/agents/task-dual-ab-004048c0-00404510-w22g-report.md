# Dual A/B report — W22-G OWN-ONLY (`aa_004048c0`, `aa_00404510`)

**Date:** 2026-07-29  
**Agent:** W22-G OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004048c0`, `0x00404510`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004048c0` Win32_ThrowLastErrorAsHresult_Inferred | **accept** — GetLastError → HRESULT_FROM_WIN32 pack → noreturn throw sealed (26 B) |
| `aa_00404510` UiToast_UninitializedCopy_0x98 | **accept-with-gaps** — **32-byte** trampoline → range copy +0x98 sealed; worker dual residual |

---

## Sealed facts — `0x004048c0`

1. **ABI:** no formals; **noreturn**. Body **`0x004048c0`–`0x004048d9`** (**26 bytes**).

2. **IAT:** `call dword ptr [0x009c6230]` = **GetLastError** (`read_memory`).

3. **Algorithm:** `err = GetLastError()`; if `(int)err > 0` then `err = (err & 0xffff) | 0x80070000`; `FUN_004048e0(err)`.

4. **Throw leaf:** `FUN_004048e0` / `Cxx_ThrowException_Param_Inferred` with ThrowInfo **`DAT_00acc3fc`** (prior dual).

5. **Role:** Win32 last-error → FACILITY_WIN32 HRESULT → C++ throw. Callers: 7 sites including `MbcsString_ConvertFromWide` @ `0x00403450`.

6. **Name:** `Win32_ThrowLastErrorAsHresult_Inferred` — role-sealed **INFERRED** from CF + pack constants. Ghidra: `FUN_004048c0`.

7. **Distinct from:** raw-param throw `004048e0` alone; `_com_raise_error` @ `0x007181c0`.

---

## Sealed facts — `0x00404510`

1. **ABI:** `void *UiToast_UninitializedCopy_0x98(void *srcBegin, void *srcEnd, void *dst)` — **three stack args**, **`ret 0x0C`**. ECX phantom-pushed into worker only.

2. **Body:** `0x00404510`–`0x0040452f` (**32 bytes**).

3. **Algorithm:** call `FUN_004047a0` (range loop stride **0x98**, element via sealed `UiToast_PodCopyElement_0x98` @ `0x00404710`); return advanced dest (EAX).

4. **Phantom formals:** decompiler shows thiscall + 4/5 args; bytes push five dwords and `add esp,0x14`; worker uses three formals.

5. **Parent:** sole caller `UiToastVector_InsertN` (`0x00403980`) — four xrefs (realloc relocate + in-place shift).

6. **Name:** `UiToast_UninitializedCopy_0x98` — role-sealed from parent insert dual + twin floater trampoline. Ghidra: `FUN_00404510`.

7. **Twin:** `CombatFloater_UninitializedCopy_0x38_Inferred` @ `0x004044c0` (same shape, stride 0x38). Sibling fill-n: `UiToast_UninitializedFillN_0x98` @ `0x00404130`.

---

## Gaps

### `004048c0`
1. Product/PDB English symbol.  
2. Full ThrowInfo / catchable-type RTTI under `DAT_00acc3fc` — residual of `004048e0`.  
3. Runtime / bit-exact / differential — open.

### `00404510`
1. Product/PDB symbol (`uninitialized_copy` / compiler helper).  
2. Optional dual of worker `FUN_004047a0` (scaffold; not OWN this wave).  
3. Parent call-site formal order audit beyond bytes map.  
4. Runtime / bit-exact / differential — open.

---

## Files

### `aa_004048c0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004048c0_Win32_ThrowLastErrorAsHresult_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004048c0_Win32_ThrowLastErrorAsHresult_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004048c0_Win32_ThrowLastErrorAsHresult_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004048c0_FUN_004048c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Win32_ThrowLastErrorAsHresult_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004048c0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004048c0_FUN_004048c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004048c0_FUN_004048c0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_004048c0.md` |

### `aa_00404510`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00404510_UiToast_UninitializedCopy_0x98.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00404510_UiToast_UninitializedCopy_0x98.md` |
| Function record | `docs/reconstruction/functions/aa_00404510_UiToast_UninitializedCopy_0x98.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00404510_FUN_00404510.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiToast_UninitializedCopy_0x98.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00404510.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00404510_FUN_00404510.md` |
| Annotated | `docs/reconstruction/raw/aa_00404510_FUN_00404510.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_00404510.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004048c0-00404510-w22g-report.md` |

---

## AutoCore impact

### `004048c0`
- Port Win32 fail arms as **hard throw** after last-error sample.
- Pack positive codes with `(err & 0xffff) | 0x80070000` before exception object.
- Shared by string convert, DB/COM, and other fail sites — do not invent silent recovery.

### `00404510`
- Port as `end = CopyRange(srcBegin, srcEnd, dst)` with **stride 0x98** (toast POD).
- No allocation in this unit; parent InsertN owns grow/delete.
- Keep distinct from fill-n `00404130` (template ConstructN) and assign-patch `00404530`.
