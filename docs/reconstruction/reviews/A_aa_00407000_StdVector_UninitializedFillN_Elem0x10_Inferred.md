# Review A (reconstruction fidelity): `aa_00407000` StdVector_UninitializedFillN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407000` |
| **VA** | `0x00407000` |
| **Body** | `0x00407000`–`0x0040701d` (**29 B** / `0x1d`); pad `CC` |
| **Canonical name** | `StdVector_UninitializedFillN_Elem0x10_Inferred` |
| **Ghidra name** | `FUN_00407000` |
| **Prior scaffold** | `Named_CalleeOf_*Cli_00407000` (**retired**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **R10-007**) |
| **Counterpart** | `reviews/B_aa_00407000_StdVector_UninitializedFillN_Elem0x10_Inferred.md` |
| **System** | util / container (`std::vector` Ufill POD **elem 0x10**); partition host interaction-activation |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Fill-N / uninitialized_fill_n** for POD elements of size **0x10**:

1. Call construct-N `FUN_00409e20` (`StdVector_ConstructN_Elem0x10_Inferred`) with dest / count / template value.  
2. Return **`dst + count * 0x10`** (end of just-constructed range).

Sole caller: dualed **`FUN_00408640`** (`StdVector_InsertN_Elem0x10_Inferred`) when planting N template copies into a hole (realloc or in-place insert). Twin shape: `StdVector_UninitializedFillN_Elem12_Inferred` (`0x00406ee0`), `StdVector_UninitializedFillN_Elem0x28_Inferred` (`0x00406e50`).

**Not** grow, free, insert-N policy, or domain / input-poll logic.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **EDI** | `T*` dest |
| **ESI** | `int` count |
| stack0 | `const T*` value (16-byte POD) |
| return | EAX = dest + count×0x10; **`ret 4`** |

```c
T* __customcc StdVector_UninitializedFillN_Elem0x10(
    /*EDI*/ T *dest, /*ESI*/ int count, /*stack*/ const T *value);
```

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00407000` (2026-08-05) ≡ raw scaffold CF |
| Disasm | `disassemble_function` full body (12 insns) |
| Bytes | `read_memory` 64 B — construct-N call, `shl/add` end = dest+n×0x10, **`C2 04 00`** |
| Callee chain | dualed `FUN_00409e20` + residual `FUN_00409f70` (4-dword copy; `add dest,0x10` per iter) |
| Parent | dualed `FUN_00408640` call sites @ `0x00408746`, `0x0040880c` |
| Raw / annotated / clean | `aa_00407000_*`, `StdVector_UninitializedFillN_Elem0x10_Inferred.cpp` |
| Callers | `get_function_callers` → `FUN_00408640` only (2 xrefs) |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

```c
// void *FillN(dst, count, template)
FUN_00409e20(dst, count /*, ECX=template*/);
return dst + count * 0x10;
```

| Stage | Match |
|---|---|
| Single construct-N call | **Yes** |
| Return advanced pointer | **Yes** (`mov eax,esi; shl eax,4; add eax,edi`) |
| No grow / no free | **Yes** |
| `ret 4` | **Yes** |
| Phantom pushes + `add esp,0x10` | **Yes** (MSVC Ufill wrapper pattern) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls `FUN_00409e20` then returns end | **Confirmed** | raw ≡ live ≡ disasm |
| End = `dst + count * 0x10` | **Confirmed** | decompile + `shl 4` + `add edi` |
| Stride **0x10** | **Confirmed** | return arithmetic + callee `add esi,0x10` |
| Body **29 B** / `ret 4` | **Confirmed** | `read_memory` + disasm |
| Construct-N = loop 4-dword POD copy | **High** | dualed MEGA-044 + `00409f70` decompile |
| Used as insert fill-n | **High** | sole parent InsertN (2 sites) |
| Product name | **Open** | `_Inferred` |

---

## 6. Gaps / open

1. Product English for 16-byte `T`.  
2. Dual seal of PodCopy `00409f70` (construct-N already dualed).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
