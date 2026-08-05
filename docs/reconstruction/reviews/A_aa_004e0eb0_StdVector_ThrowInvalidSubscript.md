# Review A (reconstruction fidelity): `aa_004e0eb0` StdVector_ThrowInvalidSubscript

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e0eb0` |
| **VA** | `0x004e0eb0` |
| **Canonical name (Ghidra)** | `FUN_004e0eb0` |
| **Proposed name** | `StdVector_ThrowInvalidSubscript` (**High** — string literal sealed) |
| **Prior scaffold alias** | (none meaningful) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004e0eb0_StdVector_ThrowInvalidSubscript.md` |
| **System** | `containers` / CRT (vector bounds) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Throw `std::out_of_range` (or sibling) with message `"invalid vector<T> subscript"`** — noreturn MSVC STL bounds-check path.

Control flow:

1. SEH frame `LAB_009a1e62`.
2. Construct `basic_string` from literal `"invalid vector<T> subscript"`.
3. Construct exception base; set vtbl sequence `PTR_FUN_009c7628` → `PTR_FUN_009c7640`.
4. `_CxxThrowException(local, &DAT_00acc34c)` — **does not return**.

### Combat nested use

Callee of multi-target hit path `0x004da2e0` on the **empty-vector / bad subscript edge** after deferred record alloc (parent dual: fallback when count==0 after alloc edge). Also `004d3ba0`, `004e25d0`.

**Not** insert-N grow (`004e39d0`), not hit apply.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004e0eb0` |
| Callers | `get_function_callers` → `004da2e0`, `004d3ba0`, `004e25d0` |
| Parent dual | `A_aa_004da2e0_*` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004e0eb0` |
| Function record | `docs/reconstruction/functions/aa_004e0eb0_FUN_004e0eb0.md` |

**This pass:** live decompile; callers; string seal. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// noreturn
void StdVector_ThrowInvalidSubscript(void);
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `std::basic_string` ctor | Message |
| `exception::exception` | Base |
| `_CxxThrowException` | Throw |

| Caller | Role |
|---|---|
| `0x004da2e0` | Multi-target edge |
| `0x004d3ba0` / `0x004e25d0` | Other vector operators |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Literal string construct | Yes |
| Exception vtbl chain | Yes |
| Noreturn throw | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Invalid vector subscript throw | **High** | exact string |
| Noreturn | **High** | decompiler warning + `_CxxThrowException` |
| Nested residual of multi-target path | **High** | live caller |
| Exact `std::out_of_range` vs `length_error` type | **Probable** | ThrowInfo `DAT_00acc34c` not fully typed |

---

## 7. Gaps / open

1. Exact RTTI of thrown type (`DAT_00acc34c`).
2. Runtime not needed for static seal.

**Verdict:** **accept** — string + noreturn CF sealed.
