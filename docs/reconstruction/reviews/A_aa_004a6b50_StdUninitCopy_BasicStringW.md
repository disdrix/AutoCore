# Review A (reconstruction fidelity): `aa_004a6b50` StdUninitCopy_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a6b50` |
| **VA** | `0x004a6b50`–`0x004a6bdc` (**140 B**) |
| **Canonical name** | `StdUninitCopy_BasicStringW` (**Inferred**) |
| **Ghidra name** | `FUN_004a6b50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-R) |
| **Counterpart** | `reviews/B_aa_004a6b50_StdUninitCopy_BasicStringW.md` |
| **System** | MSVC `_Uninit_copy` / `basic_string<wchar_t>` stride `0x1c` |
| **Evidence pass** | Live Ghidra `decompile_function` + `get_function_by_address` + `get_xrefs_to` + `read_memory` (full 140 B). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Uninitialized range-copy of `basic_string<wchar_t>` elements from `[first, last)` into `dest`, stride **0x1C**, returning dest-end. SEH-guarded with catch destroy + `_CxxThrowException`.

Sole parent: `StdVector_InsertN_BasicStringW` (`0x004a7ad0`, W34-R) uses this for prefix/suffix relocate on grow and hole paths.

**Not** POD uninit-copy (`0x004673b0`), not char-string twin (`0x0046a2c0` IAT differs), not memmove.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-R append) | `docs/reconstruction/raw/aa_004a6b50_FUN_004a6b50.md` |
| Annotated | `docs/reconstruction/raw/aa_004a6b50_FUN_004a6b50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_BasicStringW.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004a6b50.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a6b50_StdUninitCopy_BasicStringW.md` |
| Parent consumer | `StdVector_InsertN_BasicStringW` (W34-R) |
| Live | decompile happy-path ≡ loop; bytes seal catch + `C3` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// cdecl; bare RET; returns dest_end
BasicStringW_0x1c* StdUninitCopy_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    BasicStringW_0x1c* dest);
```

| Formal | Source | Conf |
|---|---|---|
| first | stack `[ebp+8]` → EDI | **High** |
| last | stack `[ebp+0xC]` | **High** |
| dest | stack `[ebp+0x10]` → ESI | **High** |
| return dest-end | `MOV EAX, ESI` | **High** |
| cleanup | bare `C3` | **High** |
| stride | `ADD …, 0x1C` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| SEH install `LAB_009a1181` | prolog bytes | **High** |
| Loop first≠last; copy-ctor IAT | decompile + `CALL [0x009C62B4]` | **High** |
| Null dest skips ctor still advances | decompile + bytes | **High** |
| Success JZ → epilogue (skip catch) | `JZ` +0x44 → epilogue | **High** |
| Catch destroy + `_CxxThrowException` | bytes @ catch; call → `0x006A3D60` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (140 B) — see raw W36-R append.

Entry: `55 8B EC 6A FF 68 81 11 9A 00`.  
Epilogue: `5B 8B E5 5D C3`.  
Pad `CC` @ `0x004a6bdc`.

---

## 6. Gaps

- Product/MSVC demangle string for exact `_Uninit_copy` specialization.
- Runtime / bit-exact / differential.
- Null-dest path residual (unused by sole known parent).

---

## 7. Verdict

Happy-path CF, ABI, stride, IAT ctor, and catch residual sealed by decompile+bytes. Residual product plate → **accept-with-gaps**.
