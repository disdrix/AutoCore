# Review A (reconstruction fidelity): `aa_00406ee0` StdVector_UninitializedFillN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406ee0` |
| **VA** | `0x00406ee0` |
| **Body** | `0x00406ee0`–`0x00406efd` (**29 B** / `0x1d`); pad `CC` |
| **Canonical name** | `StdVector_UninitializedFillN_Elem12_Inferred` |
| **Ghidra name** | `FUN_00406ee0` |
| **Prior scaffold** | `FUN_00406ee0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **WQ9G-I**) |
| **Counterpart** | `reviews/B_aa_00406ee0_StdVector_UninitializedFillN_Elem12_Inferred.md` |
| **System** | util / container (`std::vector` Ufill POD **elem 0xC**) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` / `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Fill-N / uninitialized_fill_n** for POD elements of size **0xC**:

1. Call construct-N `FUN_00409db0` with dest / count / template value.  
2. Return **`dst + count * 0xC`** (end of just-constructed range).

Sole caller: **`FUN_004082f0`** (InsertN for elem-0xC) when planting N template copies into a hole (realloc or in-place insert). Pair of InsertOne `0x00406e70`. Twin shape: `StdVector_UninitializedFillN_Elem28_Inferred` (`0x00467320`), toast/floater Ufill wrappers.

**Not** grow, free, insert-N policy, or domain logic.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **EDI** | `T*` dest |
| **ESI** | `int` count |
| stack0 | `const T*` value (12-byte POD) |
| return | EAX = dest + count×12; **`ret 4`** |

```c
T* __customcc StdVector_UninitializedFillN_Elem12(
    /*EDI*/ T *dest, /*ESI*/ int count, /*stack*/ const T *value);
```

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00406ee0` (2026-08-04) ≡ raw scaffold CF |
| Bytes | `read_memory` 64 B — construct-N call, `lea` end = dest+n×12, **`C2 04 00`** |
| Callee chain | `FUN_00409db0` + `FUN_00409f50` (3-dword copy; `add dest,0xC` per iter) |
| Parent | `FUN_004082f0` call sites @ `0x00408426`, `0x0040851b` |
| Raw / annotated / clean | `aa_00406ee0_*`, `StdVector_UninitializedFillN_Elem12_Inferred.cpp` |
| Callers | `get_function_callers` → `FUN_004082f0` only (2 xrefs) |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

```c
// void *FillN(dst, count, template)
FUN_00409db0(dst, count /*, ECX=template*/);
return dst + count * 0xC;
```

| Stage | Match |
|---|---|
| Single construct-N call | **Yes** |
| Return advanced pointer | **Yes** (`lea edx,[esi+esi*2]; lea eax,[edi+edx*4]`) |
| No grow / no free | **Yes** |
| `ret 4` | **Yes** |
| Phantom pushes + `add esp,0x10` | **Yes** (MSVC Ufill wrapper pattern) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls `FUN_00409db0` then returns end | **Confirmed** | raw ≡ live ≡ bytes |
| End = `dst + count * 0xC` | **Confirmed** | decompile + lea chain |
| Stride **0xC** | **Confirmed** | return arithmetic + callee `add esi,0xC` |
| Body **29 B** / `ret 4` | **Confirmed** | `read_memory` |
| Construct-N = loop 3-dword POD copy | **High** | `00409f50` decompile + loop bytes |
| Used as insert fill-n | **High** | sole parent InsertN (2 sites) |
| Product name | **Open** | `_Inferred` |

---

## 6. Gaps / open

1. Product English for 12-byte `T`.  
2. Full dual of construct-N `00409db0` / copy `00409f50`.  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
