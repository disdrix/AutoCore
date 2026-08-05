# Review A (reconstruction fidelity): `aa_004982d0` ListTrackedCtx_ClearResetCapacity10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004982d0` |
| **VA** | `0x004982d0`–`0x004982e2` inclusive (**19 B** / `0x13`) |
| **Canonical name** | `ListTrackedCtx_ClearResetCapacity10_Inferred` |
| **Ghidra name** | `FUN_004982d0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AD) |
| **Counterpart** | `reviews/B_aa_004982d0_ListTrackedCtx_ClearResetCapacity10_Inferred.md` |
| **System** | Palantir env child / list-tracked ctx |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full body + pads) + `get_xrefs_to` + caller site bytes + W33-R clear dual. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin thiscall wrapper over `ListTrackedCtx_ClearDestroyAndReset_Inferred`: after full clear-destroy-reset, set capacity field **`*(self+0xC) = 10`**, return **1**. Sole use from PalantirEnv init phases with **`ECX = env+0x100`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AD append) | `docs/reconstruction/raw/aa_004982d0_FUN_004982d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004982d0_FUN_004982d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ListTrackedCtx_ClearResetCapacity10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004982d0.cpp` |
| Function records | `functions/aa_004982d0_FUN_004982d0.md`, `functions/aa_004982d0_ListTrackedCtx_ClearResetCapacity10_Inferred.md` |
| Clear dual | W33-R `ListTrackedCtx_ClearDestroyAndReset_Inferred` |
| Live | body hex `56 8B F1 E8 A8 F9 FF FF C7 46 0C 0A 00 00 00 B0 01 5E C3` |

---

## 3. Signature (sealed)

```c
// ECX=self; bare RET; AL=1
uint8_t __thiscall ListTrackedCtx_ClearResetCapacity10_Inferred(uint8_t* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| return | AL=1 (`B0 01`) | **High** |
| epilogue | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ bytes)

```
ESI = ECX
FUN_00497c80()                 // thiscall clear-destroy-reset (ECX still self)
*(ESI + 0x0C) = 10
return 1                       // AL
```

| Stage | Match | Conf |
|---|---|---|
| Body 19 B / pad CC | **Yes** (`read_memory`) | **High** |
| Thiscall ECX | **Yes** | **High** |
| Call target 00497c80 | **Yes** (rel32 from `004982d8`) | **High** |
| Store capacity 10 @+0xC | **Yes** (`C7 46 0C 0A 00 00 00`) | **High** |
| Sole caller env+0x100 | **Yes** (`MOV ECX,[ESI+0x100]` @ `0048fe67`) | **High** |
| Wrapper classification | **Yes** (analyze) | **High** |

---

## 5. Gaps

- Product English for capacity constant **10**.
- Whether this path intentionally leaves dims +4/+8 at 0 (clear zeros them; sibling `004982f0` recomputes).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, 19-byte body, clear+capacity-10 composition, sole caller binding. Residual capacity English → **accept-with-gaps**.
