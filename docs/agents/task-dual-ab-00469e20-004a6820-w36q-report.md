# Dual A/B report — W36-Q OWN `aa_00469e20` + `aa_004a6820`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-Q  
**Scope:** VAs `0x00469e20`, `0x004a6820` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00469e20` StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred | **accept-with-gaps** — EDI=vec / stack outIt+where+value / RET C / count=1 rebind sealed; product T open |
| `aa_004a6820` StdVector_ThrowTooLong_B_Inferred | **accept-with-gaps** — noreturn plate+ThrowInfo+IAT exception path sealed; RTTI English open |

---

## VA `0x00469e20` — sealed facts

1. **Body:** `0x00469e20`–`0x00469e92` exclusive (**114 B** / `0x72`; pad `CC` @ `0x00469e92`).
2. **ABI:** **EDI=`vec*`**, stack **`(outIt*, where, value*)`**, returns **`outIt*`**, **`RET 0x0C`**. Decompiler omits value* formal and shows `unaff_EDI` — **bytes win**.
3. **Semantics:** MSVC-style **insert-one + rebind iterator** for POD T size **0x1c**:
   - Snapshot `index = empty ? 0 : (where−begin)/0x1c` (magic `0x92492493`).
   - `StdVector_InsertN_Elem28_ValueEdx_Inferred` (`0x00469f50`) with **EDX=value***, stack vec+where, **count=1**.
   - `*outIt = begin' + index*0x1c` (survives realloc).
4. **Classification:** worker — thin insert-one wrapper (push_back slow path).
5. **Callers (1):** `FUN_00469c80` @ `0x00469cf9` (spare-cap → `FUN_0046a260` fill-n; else this).
6. **Name:** `StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred` (Ghidra `FUN_00469e20`; **Inferred**). Reject scaffold long `Named_CalleeOf_*assPackManag*`.
7. **Decompile ≡ bytes** for index/rebind CF; **bytes win** on third stack formal + RET C + EDI=vec.  
   Full hex: raw W36-Q append (114 B).

### Gaps

- Product/PDB T English.  
- Parent `FUN_00469c80` unowned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00469e20_StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00469e20_StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00469e20_FUN_00469e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00469e20_FUN_00469e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469e20.cpp` |
| Function | `docs/reconstruction/functions/aa_00469e20_FUN_00469e20.md` |
| Function named | `docs/reconstruction/functions/aa_00469e20_StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.md` |

---

## VA `0x004a6820` — sealed facts

1. **Body:** `0x004a6820`–`0x004a6890` exclusive (**112 B** / `0x70`; pad `CC` @ `0x004a6890`).
2. **ABI:** **no formals**; **noreturn** (final `_CxxThrowException` @ `0x006a3d60`).
3. **Semantics:** MSVC-style **`vector::_Xlen`** overflow throw:
   - SEH `LAB_009a11a2`.
   - `basic_string` from **`"vector<T> too long"`** @ `0x00a15830`.
   - IAT `exception::exception` + string copy; vtbls `PTR_FUN_009c7628` / `PTR_FUN_009c7634`.
   - `_CxxThrowException(ex, &DAT_00acc388)`.
4. **Classification:** worker — shared throw helper (004a* cluster).
5. **Callers (4):** `FUN_004a69f0` @ `0x004a6a15`; `FUN_004a6f70` @ `0x004a6fbc`; `FUN_004a76e0` @ `0x004a7746`; `FUN_004a7ad0` @ `0x004a7b60` (`StdVector_InsertN_BasicStringW` overflow, W34-R).
6. **Name:** `StdVector_ThrowTooLong_B_Inferred` (Ghidra `FUN_004a6820`; **Inferred**). Twin of W19-B `StdVector_ThrowTooLong` (`0x004540b0`) with different exception wrap path. Reject scaffold `Named_CalleeOf_*VOG_DEBUG*`.
7. **Decompile ≡ bytes** for plate/throw CF; plate confirmed via `read_memory`.  
   Full hex: raw W36-Q append (112 B).

### Gaps

- Exception C++ type / RTTI English.  
- Why B-path exists vs `004540b0` (instantiation/link unit) residual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a6820_StdVector_ThrowTooLong_B_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004a6820_StdVector_ThrowTooLong_B_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a6820_FUN_004a6820.md` |
| Annotated | `docs/reconstruction/raw/aa_004a6820_FUN_004a6820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_ThrowTooLong_B_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a6820.cpp` |
| Function | `docs/reconstruction/functions/aa_004a6820_FUN_004a6820.md` |
| Function named | `docs/reconstruction/functions/aa_004a6820_StdVector_ThrowTooLong_B_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00469e20` | Port as **insert-one + rebind**: **EDI=vec**, stack **outIt+where+value***, **RET 0xC**. Index before insert; rebind after. Engine = W34-Q ValueEdx insert-n with count=1. Do **not** drop-in for RC insert-one (`004612d0`) or dword thiscall (`0040dbf0`). |
| `004a6820` | Port as **vector Xlen throw** for 004a* family: plate `"vector<T> too long"`, ThrowInfo `0x00acc388`, noreturn. Same product effect as `StdVector_ThrowTooLong` (`004540b0`); exception object construction path differs — match retail only if bit-exact exception type matters. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00469f50` | `StdVector_InsertN_Elem28_ValueEdx_Inferred` (W34-Q) — insert-one engine |
| `0x00469c80` | sole parent push_back of `00469e20` |
| `0x0046a260` | fill-n (push_back spare-cap path) |
| `0x004612d0` | RC insert-one rebind twin (W35-Q) |
| `0x004540b0` | `StdVector_ThrowTooLong` A-path (W19-B) |
| `0x004a7ad0` | `StdVector_InsertN_BasicStringW` (W34-R) — throw caller |
| `0x00a15830` | plate string |
| `0x00acc388` | ThrowInfo |

Together they close the **POD ValueEdx insert-one parent** of W34-Q insert-n and the **004a* Xlen throw** used by W34-R wstring insert-n overflow.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
