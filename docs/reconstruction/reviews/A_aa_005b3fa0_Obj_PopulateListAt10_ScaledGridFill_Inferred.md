# Review A (reconstruction fidelity): `aa_005b3fa0` Obj_PopulateListAt10_ScaledGridFill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3fa0` |
| **VA** | `0x005b3fa0`–`0x005b4255` (**693 B**) |
| **Canonical name** | `Obj_PopulateListAt10_ScaledGridFill_Inferred` (was `FUN_005b3fa0`) |
| **Review date** | `2026-08-04` (W37-L) |
| **Reviewer role** | Reconstruction fidelity (host list populate / scaled grid fill) |
| **Counterpart** | `reviews/B_aa_005b3fa0_Obj_PopulateListAt10_ScaledGridFill_Inferred.md` |
| **System** | host object / list populate worker |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers + context callees. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: W30-O ctor pair, `FUN_005b4470`/`FUN_005b43d0`, `FUN_004cd8f0` host path.

---

## 1. Purpose

**Populate** the empty list shell at `this+0x10` with a rectangular grid of nodes scaled by a float factor, after storing dimension floats on the 0x30 host. Requires non-null context for path/lock. Returns success status.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b3fa0_FUN_005b3fa0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3fa0_FUN_005b3fa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_PopulateListAt10_ScaledGridFill_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b3fa0.cpp` |
| Function records | `functions/aa_005b3fa0_*.md` |
| Live Ghidra | decompile ≡ CF; body end `005b4255`; full hex; `DAT_00a0f298` = 0.5f |
| Prior | W30-O `aa_005b3f60` / `aa_005b4260` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`, writes to unowned VAs.

---

## 3. Signature

```c
// __thiscall — ECX = this; five stack args; ret 0x14
uint32_t Obj_PopulateListAt10_ScaledGridFill_Inferred(
    void *self,
    float dim_a, float dim_b, float dim_c,
    float scale, void *ctx);
```

| Item | Evidence |
|---|---|
| Convention | Epilogue `MOV AL,1` / `XOR AL,AL` + `RET 0x14` |
| Null gate | `TEST ESI,ESI` on `[ebp+0x18]` early `JZ` → return 0 |
| Float swap | `movss` from `[ebp+8]/[ebp+0x10]/[ebp+0xC]` → `+0x20/+0x24/+0x28` |
| List base | `ADD EBX,0x10` before insert helpers |
| Body range | Entry `005b3fa0`, exclusive end `005b4255` |
| Xrefs | **2** call sites / **2** caller functions |

---

## 4. Control flow (sealed)

```
SEH prolog (LAB_009a684b)
ESI = ctx; EBX = this
if ctx == 0: return 0
store floats (+0x20/+0x24/+0x28/+0x2c=0)
FUN_004f1e20(1,1) [ECX=ctx]
stack body ctor FUN_00764030
path = FUN_004eb1c0; status = FUN_00764830(path)
if status < 0: teardown; FUN_00763f60; return 0
compute extents; half * 0.5f; nx/ny = ROUND(dim*scale)
nested loops: build payload; FUN_005b4470; FUN_005b43d0(1); link
FUN_004eb010; return 1
```

---

## 5. Confirmations

1. Pairs with W30-O empty list ctor — same host size 0x30 / list at +0x10.  
2. Live path is ctor + this populate (`FUN_004cd8f0`), not dead convenience ctor alone.  
3. Status returns are real (not void).  
4. Half-step constant is **0.5f** from `read_memory` on `DAT_00a0f298`.

---

## 6. Residual gaps

1. Product class English.  
2. Node payload field English.  
3. Exact locked-rect float offsets for extent math (owned by unowned callees).  
4. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — CF, ABI, float store order, list insert role, and 1/0 status sealed by decompile + bytes. Product naming and payload English remain open.
