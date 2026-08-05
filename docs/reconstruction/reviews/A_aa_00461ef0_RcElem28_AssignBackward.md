# Review A (reconstruction fidelity): `aa_00461ef0` RcElem28_AssignBackward

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461ef0` |
| **VA** | `0x00461ef0`–`0x00461f7a` exclusive (**138 B**) |
| **Canonical name** | `RcElem28_AssignBackward` |
| **Ghidra name** | `FUN_00461ef0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-P) |
| **Counterpart** | `reviews/B_aa_00461ef0_RcElem28_AssignBackward.md` |
| **System** | RcElem28 assign-backward stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Overlap-safe reverse assign of live RcElem28 range for mid-insert shift (MSVC `copy_backward` shape).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-P append) | `docs/reconstruction/raw/aa_00461ef0_FUN_00461ef0.md` |
| Annotated | `docs/reconstruction/raw/aa_00461ef0_FUN_00461ef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_AssignBackward.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461ef0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00461ef0_RcElem28_AssignBackward.md` |
| Parent | `StdVector_InsertN_RcElem28` mid @ `0x00461a7c` |

---

## 3. Signature (sealed)

```c
// EAX=dest_end*, stack (first*, last*); plain RET; returns final dest*
RcElem28* RcElem28_AssignBackward(
    RcElem28* dest_end,
    RcElem28* first,
    RcElem28* last);
```

| Formal | Source | Conf |
|---|---|---|
| dest_end* | **EAX** → ESI | **High** |
| first* | stack param1 | **High** |
| last* | stack param2 → EBP | **High** |
| return | final dest* in EAX (`8B C6`) | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty first==last early-out | decompile + bytes | **High** |
| Pre-decrement both by 0x1c then loop | decompile + bytes | **High** |
| Same RC assign as fill helper | decompile + bytes | **High** |
| Return final dest | `8B C6` before RET | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (138 B) — raw W35-P append.

Entry: `55 8B 6C 24 0C 39 6C 24 08 56 8B F0`.  
Epilogue: `5F 5B 8B C6 5E 5D C3`.  
Pad `CC`×6 then `00461f80`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| Callers | `FUN_004617a0` ×1 mid path |
| Callees | vtbl+4 / vtbl+8 only |

---

## 7. Gaps

1. Product/PDB class English.  
2. Exact parent bound expressions for `last` / dest_end (parent not owned).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Reverse CF, ABI, RC lanes, body size sealed. Gaps product + parent arithmetic residual → **accept-with-gaps**.
