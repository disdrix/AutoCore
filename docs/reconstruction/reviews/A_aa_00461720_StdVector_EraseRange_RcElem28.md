# Review A (reconstruction fidelity): `aa_00461720` StdVector_EraseRange_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461720` |
| **VA** | `0x00461720`–`0x0046177F` exclusive (**95 B**) |
| **Canonical name** | `StdVector_EraseRange_RcElem28` |
| **Ghidra name** | `FUN_00461720` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-N) |
| **Counterpart** | `reviews/B_aa_00461720_StdVector_EraseRange_RcElem28.md` |
| **System** | MSVC `vector` erase-range, refcounted-elem stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `analyze_function_complete` (no disasm) + `read_memory` (full body 95 B + pad) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Erase `[first, last)` in an RC-elem28 vector: move tail down with RC assign, destroy leftover range, publish new end, return iterator to first.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-N append) | `docs/reconstruction/raw/aa_00461720_FUN_00461720.md` |
| Annotated | `docs/reconstruction/raw/aa_00461720_FUN_00461720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_EraseRange_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461720.cpp` |
| Function record | `docs/reconstruction/functions/aa_00461720_StdVector_EraseRange_RcElem28.md` |
| Resize parent dual | W35-Q `aa_004611e0` |
| Destroy-range sibling | W35-O `aa_00461780` |
| Callers | `FUN_004611e0` @ `0x00461293` |

---

## 3. Signature (sealed)

```c
// stdcall RET 0x10
RcElem28** StdVector_EraseRange_RcElem28(
    StdVectorRc28* vec,
    RcElem28** outIt,
    RcElem28* first,
    RcElem28* last);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | stack `[esp+4]` → EBP | **High** |
| outIt* | stack `[esp+8]` | **High** |
| first | stack `[esp+0xC]` → EAX | **High** |
| last | stack `[esp+0x10]` → EDX | **High** |
| RET 0x10 | `C2 10 00` both exits | **High** |
| stride 0x1c | `ADD ESI, 0x1C` destroy loop | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| first==last early out | decompile ≡ bytes | **High** |
| Move `[last,end)` → first | call `0x00461e60` + `ADD ESP,0xC` | **High** |
| Destroy leftover `[new_end,old_end)` | call `0x00460d70` stride 0x1c | **High** |
| Publish end + *outIt=first | decompile ≡ bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (95 B) — raw W36-N append.

Entry: `8B 54 24 10 8B 44 24 0C 3B C2`.  
Calls: `E8 1D 07 00 00` → `0x00461e60`; `E8 18 F6 FF FF` → `0x00460d70`.  
Epilogue both paths: `C2 10 00`.  
Pad `CC` then `FUN_00461780`.

---

## 6. Gaps

- Product/PDB T English.  
- Nested `FUN_00461e60` / `FUN_00460d70` not dual-owned here.  
- Runtime / bit-exact open.

---

## Verdict

**accept-with-gaps** — erase ABI/CF/stride/call graph sealed against RC-elem28 resize/destroy family.
