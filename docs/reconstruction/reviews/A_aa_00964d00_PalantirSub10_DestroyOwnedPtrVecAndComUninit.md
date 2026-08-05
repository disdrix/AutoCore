# Review A (reconstruction fidelity): `aa_00964d00` PalantirSub10_DestroyOwnedPtrVecAndComUninit

| Field | Value |
|---|---|
| **Stable ID** | `aa_00964d00` |
| **VA** | `0x00964d00`–`0x00964DAA` exclusive (**170 B**) |
| **Canonical name** | `PalantirSub10_DestroyOwnedPtrVecAndComUninit` |
| **Ghidra name** | `FUN_00964d00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-J) |
| **Counterpart** | `reviews/B_aa_00964d00_PalantirSub10_DestroyOwnedPtrVecAndComUninit.md` |
| **System** | client / Palantir nested subobject at `host+0x10` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 170 B) + caller assembly context + IAT `CoUninitialize`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy the embedded Palantir+0x10 subobject: walk owned-pointer vector, complete-dtor + free each element (`FUN_00735390` + `operator_delete`), free buffer, zero triad, Release COM at +0x10, `CoUninitialize`, zero triad again.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-J append) | `docs/reconstruction/raw/aa_00964d00_FUN_00964d00.md` |
| Annotated | `docs/reconstruction/raw/aa_00964d00_FUN_00964d00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirSub10_DestroyOwnedPtrVecAndComUninit.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00964d00.cpp` |
| Function records | `functions/aa_00964d00_FUN_00964d00.md`, `functions/aa_00964d00_PalantirSub10_DestroyOwnedPtrVecAndComUninit.md` |
| Parent | `Palantir_CompleteDtor` W34-K (`aa_00754320`) |
| Live | decompile + 170 B hex + 3 call sites |

---

## 3. Signature (sealed)

```c
// stdcall; RET 4; void
void __stdcall PalantirSub10_DestroyOwnedPtrVecAndComUninit(PalantirSub10* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | stack (`MOV ESI,[ESP+0x1C]` after SEH/pushes) | **High** |
| cleanup | `C2 04 00` RET 4 | **High** |
| thiscall | **no** (no ECX load of self) | **High** |

---

## 4. Control flow (bytes authority)

```
// SEH LAB_009ab766
ESI = stack self
for (EDI = begin; EDI != end; EDI += 4):
  if *EDI: FUN_00735390(*EDI); operator_delete(*EDI)
if begin: operator_delete(begin)
begin=end=cap=0
if com: Release(com)   // vtbl+8
com=0
CoUninitialize()       // IAT 0x009c697c
// dead second free
begin=end=cap=0
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Element loop stride 4 | `ADD EDI,4` | **High** |
| Free buffer if non-null | `CMP` / `JZ` skip | **High** |
| Always zero + Release + CoUninit | fall-through after free | **High** |
| stdcall RET 4 | `C2 04 00` | **High** |
| Nest under Palantir | callers push `host+0x10` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (170 B) — see raw W35-J append.

Entry: `64 A1 00 00 00 00 6A FF 68 66 B7 9A 00 …`  
Epilogue: `… 83 C4 0C C2 04 00`  
Pad: `CC` from `0x00964DAA`; next region @ `0x00964DB0`.

**Decompile ≢ bytes:** inverted null-check around free/zero/Release/CoUninit; false `operator_delete` noreturn; implied cdecl. **Bytes win** (stdcall; free-if-non-null then always COM teardown).

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00754320` @ `0x0075438a`; Unwind `@009afcf6`, `@009afd32` |
| Callees | `FUN_00735390`, `operator_delete`, `CoUninitialize` |

---

## 7. Gaps

1. Element product type / dual for `FUN_00735390` (strings + COM@+0x48 observed only).  
2. Semantics of unused `self+0x00`.  
3. Matching ctor / `CoInitialize*` balance dual.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

ABI, vector destroy, COM Release, and `CoUninitialize` sealed by full-body hex + callers; element product plate open → **accept-with-gaps**.
