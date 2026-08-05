# Review A (reconstruction fidelity): `aa_004a7aa0` StdVector_DestroyRange_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7aa0` |
| **VA** | `0x004a7aa0`–`0x004a7ac4` (**36 B**) |
| **Canonical name** | `StdVector_DestroyRange_BasicStringW` |
| **Ghidra name** | `FUN_004a7aa0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-S) |
| **Counterpart** | `reviews/B_aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md` |
| **System** | MSVC `vector<basic_string<wchar_t>>` destroy-range |
| **Evidence pass** | Live Ghidra `batch_decompile` + `get_function_by_address` + xrefs/callees + `read_memory` (full body). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy each `basic_string<wchar_t>` in `[first, last)` at stride **0x1c**. Buffer deallocation is separate (caller `operator_delete` after grow).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-S append) | `docs/reconstruction/raw/aa_004a7aa0_FUN_004a7aa0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7aa0_FUN_004a7aa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRange_BasicStringW.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004a7aa0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md` |
| Char twin | `StdVector_DestroyRange_BasicString` (`0x00431aa0`, W33-H) |
| Parent context | `StdVector_InsertN_BasicStringW` (W34-R) destroy-old after relocate |
| Live | decompile ≡ CF; `RET C2 08 00` + `ADD ESI,0x1C` + IAT `[0x009c62ac]` sealed |

---

## 3. Signature (sealed)

```c
// stack first*, last*; RET 0x08; void
void StdVector_DestroyRange_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last);
```

| Formal | Source | Conf |
|---|---|---|
| first / last | stack; ESI/EDI loop | **High** |
| stride 0x1c | `83 C6 1C` | **High** |
| dtor | `FF 15 AC 62 9C 00` | **High** |
| cleanup | `C2 08 00` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Early-out first==last | `CMP ESI,EDI; JE` | **High** |
| Loop dtor + stride | decompile ≡ bytes | **High** |
| RET 8 | epilogue bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (36 B) — see raw W36-S append.

```
568b742408578b7c24103bf774118bff8bceff15ac629c0083c61c3bf775f15f5ec20800
```

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (destroy helper) |
| Callers | insert-n main @ `0x004a7c82`; two catch sites |
| Callees | IAT `~basic_string<wchar_t>` |

---

## 7. Gaps

1. Product/MSVC demangle (`_Destroy_range` English).  
2. IAT dtor full symbol plate.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — destroy-range ABI/CF/stride/dtor sealed; product demangle residual.
