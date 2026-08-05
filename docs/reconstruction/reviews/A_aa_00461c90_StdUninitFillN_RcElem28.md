# Review A (reconstruction fidelity): `aa_00461c90` StdUninitFillN_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461c90` |
| **VA** | `0x00461c90`–`0x00461d74` exclusive (**228 B**) |
| **Canonical name** | `StdUninitFillN_RcElem28` |
| **Ghidra name** | `FUN_00461c90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-O) |
| **Counterpart** | `reviews/B_aa_00461c90_StdUninitFillN_RcElem28.md` |
| **System** | MSVC `_Uninit_fill_n` refcounted-elem stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct `count` copies of a non-trivial 0x1c element (shared resource `@+0x10`) into an uninitialized destination range, with AddRef-correct lifetime.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-O append) | `docs/reconstruction/raw/aa_00461c90_FUN_00461c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00461c90_FUN_00461c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461c90.cpp` |
| Function record | `docs/reconstruction/functions/aa_00461c90_StdUninitFillN_RcElem28.md` |
| Callers | `FUN_004617a0` (×2), `FUN_00460f90` (count=1) |
| Parent context | W34-P `StdVector_InsertN_RcElem28` names this as fill-n helper |

---

## 3. Signature (sealed)

```c
// ECX=value*, EDX=count, stack dest*; RET 0
void StdUninitFillN_RcElem28(
    const RcElem28* value,
    int count,
    RcElem28* dest);
```

| Formal | Source | Conf |
|---|---|---|
| value* | ECX → EDI (`8B F9`) | **High** |
| count | EDX → EBX (`8B DA`) | **High** |
| dest* | stack `[ebp+8]` → ESI | **High** |
| RET 0 | `C3` | **High** |
| Extra stack dword at some call sites | `ADD ESP,8` (unused by body) | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| SEH prologue (`6A FF` / `LAB_009bdd71`) | bytes + decompile | **High** |
| count==0 early exit | `TEST EBX` / `JBE` | **High** |
| Per-elem copy 4 dwords + AddRef `@+0x10` + 3 bytes + dword | decompile ≡ bytes | **High** |
| Advance dest `+0x1c` / count-- | `ADD ESI,1C` / `SUB EBX,1` | **High** |
| EH unwind Release range (vtbl+8) | bytes (decompiler omits detail) | **High** |
| Epilogue restore FS:[0] + `RET` | bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (228 B) — raw W35-O append.

Entry: `55 8B EC 6A FF 68 71 DD 9B 00`.  
Epilogue: `5B 8B E5 5D C3`.  
Pad `CC`.

---

## 6. Gaps

- Product/PDB T English (gfx residual only).
- Exact AddRef-when-refcount-becomes-1 gate semantics residual (match port to bytes, not invent IUnknown).
- Nested resource vtbl / `FUN_00460d70` not dual-owned here.
- Runtime / bit-exact open.

---

## 7. Verdict

Fill-n ABI, stride, AddRef, and SEH shape sealed against parent InsertN and call sites. Product plate open → **accept-with-gaps**.
