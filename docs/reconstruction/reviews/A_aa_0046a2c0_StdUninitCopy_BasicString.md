# Review A (reconstruction fidelity): `aa_0046a2c0` StdUninitCopy_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a2c0` |
| **VA** | `0x0046a2c0`–`0x0046a34c` (**140 B**) |
| **Canonical name** | `StdUninitCopy_BasicString` |
| **Ghidra name** | `FUN_0046a2c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-G) |
| **Counterpart** | `reviews/B_aa_0046a2c0_StdUninitCopy_BasicString.md` |
| **System** | MSVC `_Uninit_copy` / `basic_string` stride `0x1c` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 140 B) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Uninitialized range-copy of `basic_string` elements from `[first, last)` into `dest`, stride **0x1C**, returning dest-end. SEH-guarded with catch destroy + `_CxxThrowException`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-G append) | `docs/reconstruction/raw/aa_0046a2c0_FUN_0046a2c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a2c0_FUN_0046a2c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_BasicString.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0046a2c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0046a2c0_StdUninitCopy_BasicString.md` |
| Parent consumer | `StdVector_InsertN_BasicString` (W32-B) |
| Live | decompile happy-path ≡ loop; bytes seal catch + `C3` |

---

## 3. Signature (sealed)

```c
// cdecl; bare RET; returns dest_end
BasicString_0x1c* StdUninitCopy_BasicString(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest);
```

| Formal | Source | Conf |
|---|---|---|
| first / last / dest | stack; EDI/ESI in loop | **High** |
| return dest-end | `MOV EAX, ESI` | **High** |
| cleanup | bare `C3` | **High** |
| stride | `ADD …, 0x1C` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| SEH install `LAB_009bcce1` | prolog bytes | **High** |
| Loop first≠last; copy-ctor IAT | decompile + `CALL [0x009C62EC]` | **High** |
| Null dest skips ctor still advances | decompile | **High** |
| Success JZ → epilogue (skip catch) | `JZ` target `0x0046A339` | **High** |
| Catch destroy + `_CxxThrowException` | bytes @ `0x0046A318` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (140 B) — see raw W33-G append.

Entry: `55 8B EC 6A FF 68 E1 CC 9B 00`.  
Epilogue: `5B 8B E5 5D C3`.  
Pad `CC`.

---

## 6. Gaps

- Product/MSVC demangle string for exact `_Uninit_copy` specialization.
- Allocator trailing args on some call sites (unused by body).
- Runtime / bit-exact / differential.

---

## 7. Verdict

Happy-path CF, ABI, stride, IAT ctor, and catch residual sealed by decompile+bytes. Residual product plate → **accept-with-gaps**.
