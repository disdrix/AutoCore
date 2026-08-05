# Review A (reconstruction fidelity): `aa_00461780` StdDestroyRange_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461780` |
| **VA** | `0x00461780`–`0x00461797` exclusive (**23 B**) |
| **Canonical name** | `StdDestroyRange_RcElem28` |
| **Ghidra name** | `FUN_00461780` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-O) |
| **Counterpart** | `reviews/B_aa_00461780_StdDestroyRange_RcElem28.md` |
| **System** | MSVC destroy-range refcounted-elem stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy half-open range `[begin, end)` of non-trivial 0x1c elements by releasing shared resource `@+0x10` on each (via `FUN_00460d70`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-O append) | `docs/reconstruction/raw/aa_00461780_FUN_00461780.md` |
| Annotated | `docs/reconstruction/raw/aa_00461780_FUN_00461780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdDestroyRange_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461780.cpp` |
| Function record | `docs/reconstruction/functions/aa_00461780_StdDestroyRange_RcElem28.md` |
| Callers | `FUN_004617a0` grow path; two catch handlers |
| Nested leaf | `FUN_00460d70` decompile (Release `@+0x10`) |

---

## 3. Signature (sealed)

```c
// EAX=begin*, EDI=end* exclusive; RET 0
void StdDestroyRange_RcElem28(RcElem28* begin, RcElem28* end);
```

| Formal | Source | Conf |
|---|---|---|
| begin* | EAX → ESI (`8B F0`) | **High** |
| end* | EDI (live across call; call sites load end into EDI) | **High** |
| RET 0 | `C3` | **High** |
| stride | `ADD ESI, 0x1C` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| `push esi; mov esi, eax` | bytes | **High** |
| `cmp esi, edi; je done` | bytes ≡ decompile | **High** |
| `mov eax, esi; call FUN_00460d70` | relative call target sealed | **High** |
| `add esi, 0x1c; cmp; jne` | bytes | **High** |
| `pop esi; ret` | bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (23 B) — raw W35-O append.

```
56 8B F0 3B F7 74 0E 8B C6 E8 E2 F5 FF FF 83 C6 1C 3B F7 75 F2 5E C3
```

Call: `E8 E2 F5 FF FF` → `0x00460d70`.  
Pad `CC` then parent InsertN at `0x004617a0`.

---

## 6. Gaps

- Product/PDB T English.
- Nested `FUN_00460d70` dual ownership residual.
- Runtime / bit-exact open.

---

## 7. Verdict

Register ABI, stride, and sole callee sealed; body is minimal and fully covered by bytes. Nested Release leaf product open → **accept-with-gaps**.
