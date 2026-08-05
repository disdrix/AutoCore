# Review A (reconstruction fidelity): `aa_004a74f0` StdUninitFillN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a74f0` |
| **VA** | `0x004a74f0`–`0x004a757c` (**140 B**) |
| **Canonical name** | `StdUninitFillN_BasicStringW` (**Inferred**) |
| **Ghidra name** | `FUN_004a74f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-R) |
| **Counterpart** | `reviews/B_aa_004a74f0_StdUninitFillN_BasicStringW.md` |
| **System** | MSVC `_Uninit_fill_n` / `basic_string<wchar_t>` stride `0x1c` |
| **Evidence pass** | Live Ghidra `decompile_function` + `get_function_by_address` + `get_xrefs_to` + `read_memory` (full 140 B). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Uninitialized fill-n of `basic_string<wchar_t>`: construct `count` copies of `*value` at `dest`, stride **0x1C**. Full SEH loop body (not a thin thiscall rebind).

Parents: insert-n fill arm `FUN_004a7ad0`; hole helper `FUN_004a7a70`; resize/fill `FUN_004a8100`.

**Not** POD fill-n (`0x00467320`), not char thin wrapper (`0x00430390`), not range copy.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-R append) | `docs/reconstruction/raw/aa_004a74f0_FUN_004a74f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a74f0_FUN_004a74f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicStringW.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004a74f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a74f0_StdUninitFillN_BasicStringW.md` |
| Live | decompile happy-path ≡ loop; bytes seal catch + `C3` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// cdecl; bare RET; void
void StdUninitFillN_BasicStringW(
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| dest | stack `[ebp+8]` → ESI | **High** |
| count | stack `[ebp+0xC]` → EDI | **High** |
| value* | stack `[ebp+0x10]` | **High** |
| return | void | **High** |
| cleanup | bare `C3` | **High** |
| stride | `ADD …, 0x1C` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| SEH install `LAB_009a11c1` | prolog bytes | **High** |
| Loop count≠0; copy-ctor IAT from value | decompile + `CALL [0x009C62B4]` | **High** |
| Null dest skips ctor still advances | decompile + bytes | **High** |
| count==0 early-out (`JBE`) | bytes | **High** |
| Catch destroy + `_CxxThrowException` | bytes; call → `0x006A3D60` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (140 B) — see raw W36-R append.

Entry: `55 8B EC 6A FF 68 C1 11 9A 00`.  
Epilogue: `5B 8B E5 5D C3`.  
Pad `CC` @ `0x004a757c`.

---

## 6. Gaps

- Product/MSVC demangle for exact `_Uninit_fill_n` specialization.
- Nested dual seal of non-owned callers `FUN_004a7a70` / `FUN_004a8100`.
- Runtime / bit-exact / differential.

---

## 7. Verdict

Happy-path CF, ABI, stride, IAT ctor, and catch residual sealed by decompile+bytes. Residual product plate → **accept-with-gaps**.
