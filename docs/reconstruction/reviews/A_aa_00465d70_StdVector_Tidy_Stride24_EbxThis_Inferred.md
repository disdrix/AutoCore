# Review A (reconstruction fidelity): `aa_00465d70` StdVector_Tidy_Stride24_EbxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00465d70` |
| **VA** | `0x00465d70`–`0x00465db0` exclusive (**64 B** / `0x40`) |
| **Canonical name** | `StdVector_Tidy_Stride24_EbxThis_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00465d70` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-R) |
| **Counterpart** | `reviews/B_aa_00465d70_StdVector_Tidy_Stride24_EbxThis_Inferred.md` |
| **System** | container / vector tidy |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 64 B) + xrefs + callee decompile `FUN_00481d80` + caller site W37-N. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

EBX-this **vector tidy** for elements of stride **0x24**:

1. If begin null → zero begin/end/cap and return.
2. Else for each elem in `[begin,end)`: `FUN_00481d80` (ESI=elem) frees nested buffer @+0x18.
3. `operator_delete(begin)`; zero triple; return.

Used by Palantir nested owned-element complete dtor at `elem+0x70C` (W37-N).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-R append) | `docs/reconstruction/raw/aa_00465d70_FUN_00465d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00465d70_FUN_00465d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Tidy_Stride24_EbxThis_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00465d70.cpp` |
| Function | `docs/reconstruction/functions/aa_00465d70_FUN_00465d70.md` |
| Named | `docs/reconstruction/functions/aa_00465d70_StdVector_Tidy_Stride24_EbxThis_Inferred.md` |
| Caller dual | W37-N `aa_00735390` PalantirSub10_OwnedElem_CompleteDtor |
| Live | decompile + 64 B hex + thunk JMP + FUN_00481d80 |

---

## 3. Signature (sealed)

```c
// EBX = vector*; void; RET (C3)
void StdVector_Tidy_Stride24_EbxThis_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| vector* | EBX (`unaff_EBX`; caller LEA EBX) | **High** |
| cleanup | `C3` | **High** |
| ECX thiscall | **not used** | **High** |

---

## 4. Control flow (bytes authority)

```
ESI=[EBX+4]
if ESI==0: zero +4/+8/+0xC; RET
EDI=[EBX+8]
while ESI!=EDI: CALL FUN_00481d80; ESI+=0x24
operator_delete([EBX+4]); zero +4/+8/+0xC; RET
```

| Stage | Match | Conf |
|---|---|---|
| Body 64 B | Yes | **High** |
| Stride `ADD ESI,0x24` | Yes | **High** |
| Post-delete zero triple | Yes (decompiler missed) | **High** |
| Thunk `00465c30` → here | Yes | **High** |
| Sole CALL from 007353cd | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00735390` @ `0x007353cd`; thunk `0x00465c30` |
| Callees | `FUN_00481d80`; `operator_delete` |

---

## 6. Gaps

1. Product element type English for 0x24 payload.  
2. Full dual of `FUN_00481d80` (unowned; ESI-this nested free sealed by decompile).  
3. Runtime / bit-exact / differential.

---

## 7. Verdict rationale

Full 64 B hex seals ABI, stride, destroy loop, free, and zero. Caller site matches W37-N plate. Residual gaps are naming only → **accept**.
