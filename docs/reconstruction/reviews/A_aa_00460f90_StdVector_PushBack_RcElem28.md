# Review A (reconstruction fidelity): `aa_00460f90` StdVector_PushBack_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_00460f90` |
| **VA** | `0x00460f90`–`0x00461011` exclusive (**129 B**) |
| **Canonical name** | `StdVector_PushBack_RcElem28` |
| **Ghidra name** | `FUN_00460f90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-O) |
| **Counterpart** | `reviews/B_aa_00460f90_StdVector_PushBack_RcElem28.md` |
| **System** | MSVC `vector::push_back`, refcounted elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Push **one** RC-elem28 onto a triad vector. **Spare capacity** → uninit-fill-n count=1 at `end` then advance. **Full / empty buffer** → insert-one-rebind at `end` (growth path).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-O append) | `docs/reconstruction/raw/aa_00460f90_FUN_00460f90.md` |
| Annotated | `docs/reconstruction/raw/aa_00460f90_FUN_00460f90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00460f90.cpp` |
| Function record | `docs/reconstruction/functions/aa_00460f90_StdVector_PushBack_RcElem28.md` |
| Fill-n dual | W35-O `aa_00461c90` |
| Insert-one dual | W35-Q `aa_004612d0` |
| Caller site | `0x00966449` assembly context |

---

## 3. Signature (sealed)

```c
// EAX=vec*, ECX=value*, RET 0
void StdVector_PushBack_RcElem28(StdVectorRc28* vec, const RcElem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | EAX → EDI (`8B F8`) | **High** |
| value* | ECX (prologue `PUSH ECX`; fast path reload `[esp+0x10]`) | **High** |
| RET 0 | `C3` both paths; no `C2` | **High** |
| stride | `/ 0x1c` via magic `0x92492493` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| size = (end−begin)/0x1c or 0 | decompile ≡ bytes | **High** |
| spare: size < cap | cmp size,cap / jae slow | **High** |
| fill-n count=1 at end | `BA 01 00 00 00` + call `00461c90` | **High** |
| end += 0x1c | `83 C6 1C` / store `[edi+8]` | **High** |
| slow insert-one at end | call `004612d0` with where=end | **High** |
| discard outIt | local slot only | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (129 B) — raw W36-O append.

Entry: `51 53 55 56 57 8B F8 …`.  
Fast call: `E8 A3 0C 00 00` → `0x00461c90`.  
Slow call: `E8 C5 02 00 00` → `0x004612d0`.  
Epilogue: `5F 5E 5D 5B 59 C3`. Pad `CC`.

---

## 6. Gaps

- Product/PDB T English (gfx residual only).
- Nested fill-n / insert-one product open (sealed as structural).
- Runtime / bit-exact.

---

## 7. Verdict

ABI, spare/full CF, and both sealed callees covered by bytes + call sites. Product T open → **accept-with-gaps**.
