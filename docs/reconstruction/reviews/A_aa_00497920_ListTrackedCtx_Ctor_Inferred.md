# Review A (reconstruction fidelity): `aa_00497920` ListTrackedCtx_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497920` |
| **VA** | `0x00497920`–`0x0049799c` inclusive (**125 B** / `0x7D`) |
| **Canonical name** | `ListTrackedCtx_Ctor_Inferred` |
| **Ghidra name** | `FUN_00497920` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-P) |
| **Counterpart** | `reviews/B_aa_00497920_ListTrackedCtx_Ctor_Inferred.md` |
| **System** | Palantir env child / list-tracked ctx |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full body) + xrefs/callers + callee decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete thiscall constructor of the **0xC8** list-tracked context: flag/capacity/count init, zero slot bank, subobject at `+0xB8`, parent at `+0xC4`, publish `DAT_00b035cc`. Sole install path is PalantirEnv `+0x100`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-P append) | `docs/reconstruction/raw/aa_00497920_FUN_00497920.md` |
| Annotated | `docs/reconstruction/raw/aa_00497920_FUN_00497920.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ListTrackedCtx_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00497920.cpp` |
| Function records | `functions/aa_00497920_FUN_00497920.md`, `functions/aa_00497920_ListTrackedCtx_Ctor_Inferred.md` |
| Sole caller | `PalantirEnv_Ctor_Inferred` (`0x00492dd0`, W31-P) |
| Sibling | `Ctx_ClearListTrackedOwnedAtScaledXY` (`0x00497a30`, W31-D) |
| Live | decompile ≡ raw CF; `ret 4`; layout sealed by hex |

---

## 3. Signature (sealed)

```c
// ECX=self; stack parent; ret 4; EAX=self
uint8_t* __thiscall ListTrackedCtx_Ctor_Inferred(uint8_t* self, void* parent);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| parent | stack `[esp+4]` after setup; stored @`+0xC4` | **High** |
| return | EAX = self (`8B C6`) | **High** |
| epilogue | `C2 04 00` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH LAB_009a0dbe
FUN_00787520(this+0xB8)     // zero 3 dwords
*this = 1
*(this+4)=0; *(this+8)=0; *(this+0xC)=5; *(this+0x10)=0
FUN_00788db0(this+0x14, 0xA0)
*(this+0xB4)=0
*(this+0xC4)=parent
DAT_00b035cc = this
return this  // ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Object size 0xC8 | **Yes** (factory `new(200)`) | **High** |
| Field constants 1/0/5 | **Yes** (hex + decompile) | **High** |
| Zero bank 0xA0 @+0x14 | **Yes** | **High** |
| Parent @+0xC4 / global publish | **Yes** | **High** |
| Sole caller → env+0x100 | **Yes** | **High** |
| Body 125 B / ret 4 | **Yes** (`read_memory`) | **High** |

---

## 5. Gaps

- Product/PDB class demangle for 0xC8 ctx.
- Exact element type in +0x14 pointer bank.
- Who clears flag@+0 (ctor sets 1; `FUN_004be7d0` early-outs when non-zero).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals complete-ctor ABI, layout, sole factory, and global. Residual product English → **accept-with-gaps**.
