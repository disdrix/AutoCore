# Review A (reconstruction fidelity): `aa_00497a30` Ctx_ClearListTrackedOwnedAtScaledXY_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497a30` |
| **VA** | `0x00497a30`–`0x00497ab8` inclusive (**137 B** / `0x89`) |
| **Canonical name** | `Ctx_ClearListTrackedOwnedAtScaledXY_Inferred` |
| **Ghidra name** | `FUN_00497a30` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-D) |
| **Counterpart** | `reviews/B_aa_00497a30_Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.md` |
| **System** | ctx → host grid single-cell owned@+0x24 clear |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (body + DAT floats) + `get_xrefs_to`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

From a context object, resolve the `Class_009c7a1c`-shaped host, convert stack XY units by `scale*0.0625` into one grid cell, and destroy/free/null the owned `ListTrackedObj*` at `elem+0x24`. Returns 1.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-D append) | `docs/reconstruction/raw/aa_00497a30_FUN_00497a30.md` |
| Annotated | `docs/reconstruction/raw/aa_00497a30_FUN_00497a30.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00497a30.cpp` |
| Function records | `functions/aa_00497a30_FUN_00497a30.md`, `functions/aa_00497a30_Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.md` |
| Owned dtor | `ListTrackedObj_CompleteDtor` (`aa_004be2a0`, W30-P) |
| Scale peer | `Host_RebuildElem0x28ArrayFromMap_Inferred` (`aa_004941b0`, W30-Q) |
| Live | decompile ≡ raw; body 137 B; `ret 8`; floats sealed |

---

## 3. Signature (sealed)

```c
// ECX=ctx; stack xUnits, yUnits; ret 8; returns 1
uint32_t __thiscall Ctx_ClearListTrackedOwnedAtScaledXY_Inferred(
    void* ctx, uint32_t xUnits, uint32_t yUnits);
```

| Formal | Source | Conf |
|---|---|---|
| ctx | ECX | **High** |
| xUnits | stack arg0 (`param_2`) | **High** (x-like; col) |
| yUnits | stack arg1 (`param_3`) | **High** (y-like; row) |
| return | EAX = 1 | **High** |
| cleanup | `ret 8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
host = *(*(ctx+0xC4)+0xE898)
arr  = *(host+0x28); dimX = *(host+4)
div  = fistp(DAT_00aefa50 * DAT_00a14000)  // RC chop; decompiler ROUND
index = (yUnits/div)*dimX + (xUnits/div)
elem = arr + index*0x28
owned = *(elem+0x24)
if owned:
  FUN_004be2a0(owned)
  operator_delete(owned)
*(elem+0x24) = 0
EAX = 1; ret 8
```

| Stage | Match | Conf |
|---|---|---|
| Host path +0xC4→+0xE898 | **Yes** | **High** |
| Float product / div | **Yes** (`read_memory` 32.0f * 0.0625f) | **High** |
| Index formula / stride | **Yes** | **High** |
| Dtor + delete + null + ret 1 | **Yes** (false noreturn ignored) | **High** |
| Body size / `C2 08 00` | **Yes** | **High** |

---

## 5. Gaps

- Product English for ctx / `+0xC4` child / coordinate units.
- Static callers (orphan xref DB).
- Whether `ROUND` vs chop differs for non-integer products (product is exact 2.0/4.0 for sealed scales).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, host path, scale math, and owned teardown. Residual product English + orphan graph → **accept-with-gaps**.
