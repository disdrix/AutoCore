# Review A (reconstruction fidelity): `aa_00406e50` StdVector_UninitializedFillN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406e50` |
| **VA** | `0x00406e50` |
| **Body** | `0x00406e50`–`0x00406e6c` (28 bytes) |
| **Canonical name** | `StdVector_UninitializedFillN_Elem0x28_Inferred` |
| **Prior scaffold** | `FUN_00406e50` |
| **Review date** | `2026-08-04` (WQ9G-H dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00406e50_StdVector_UninitializedFillN_Elem0x28_Inferred.md` |
| **System** | util / container (elem **0x28**) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**Fill-N / uninitialized_fill_n** for **0x28-byte** POD elements:

1. Call `FUN_00409d40` (ConstructN) with dest / count / template payload.
2. Return **`dst + count * 0x28`** (end of just-constructed range).

Sole caller: insert-N `FUN_00408050` (`0x00408050`) — two sites when constructing N template copies into a hole (realloc or in-place insert). Twin pattern of `UiToast_UninitializedFillN_0x98` (`0x00404130`).

ABI: **`ret 4`** (1 stack arg = value*); **EDI**=dst, **ESI**=count.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00406e50` |
| Bytes | `read_memory` 48 B — ConstructN call, `lea` end = `dst + n*0x28`, `C2 04 00` |
| Bounds | `get_function_by_address` body `00406e50`–`00406e6c` |
| Callers | `FUN_00408050` ×2 (`get_function_xrefs`) |
| Callee | `FUN_00409d40` → loop `FUN_00409f30` (10 dword PodCopy = 0x28) |
| Raw / clean | `aa_00406e50_*`, named plate |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls `FUN_00409d40` then returns end | **Confirmed** | raw ≡ live ≡ bytes |
| End = `dst + count * 0x28` | **Confirmed** | `lea edx,[esi+esi*4]; lea eax,[edi+edx*8]` |
| Stride **0x28** | **Confirmed** | return arithmetic + construct step |
| Body **28 bytes** / `ret 4` | **Confirmed** | `read_memory` + bounds |
| ConstructN = loop PodCopy 10 dwords | **High** | callee bytes: `add esi,0x28` |
| Phantom extra pushes into ConstructN | **Confirmed** | 4 dwords pushed, `add esp,0x10` |
| Used as insert fill-n | **High** | sole parent insert-N |
| Product name | **Open** | INFERRED |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
// void *FillN(dst /*EDI*/, count /*ESI*/, template /*stack*/)
FUN_00409d40(template /*ECX*/, dst, count);
return dst + count * 0x28;
```

| Stage | Match |
|---|---|
| Single construct-N call | Yes |
| Return advanced pointer | Yes |
| No grow / no free | Yes |
| ret 4 | Yes |

---

## 5. Gaps / open

1. Product symbol / element English type.
2. ConstructN `FUN_00409d40` / PodCopy `FUN_00409f30` undualed (CF sealed from bytes).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
