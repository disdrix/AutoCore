# Review A (reconstruction fidelity): `aa_0044b440` Xform_SetScaleXYZ_DetectUniform_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044b440` |
| **VA** | `0x0044b440`–`0x0044b4EF` exclusive (**175 B**) |
| **Canonical name** | `Xform_SetScaleXYZ_DetectUniform_Inferred` (was `FUN_0044b440`) |
| **Review date** | `2026-08-04` (W37-R) |
| **Reviewer role** | Reconstruction fidelity (xform scale triple setter) |
| **Counterpart** | `reviews/B_aa_0044b440_Xform_SetScaleXYZ_DetectUniform_Inferred.md` |
| **System** | gfx / xform-matrix subobject |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `get_xrefs_to` + `read_memory` (full body + eps). Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: `CVOGEnvironmentReflect_ctor` (W32-T), `FUN_005a75f0`, `FUN_0096b280`.

---

## 1. Purpose

**Set a float triple** (scale XYZ) on a matrix/xform subobject **only when changed**:

1. Compare stack `(x,y,z)` to `this+0x9C/A0/A4` (exact float equality).
2. Unchanged → return (no revision bump).
3. Changed → store triple; `this+0xBC = −1`.
4. If `|x−y| ≤ eps` and `|x−z| ≤ eps` (`eps = DAT_00aaa620` ≈ **1e-5**): `+0xB8=0`, `+0xB4++`.
5. Else: `+0xB4++`, `+0xB8=1`.

Leaf — no callees.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044b440_FUN_0044b440.md` (+ W37-R append) |
| Annotated | `docs/reconstruction/raw/aa_0044b440_FUN_0044b440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Xform_SetScaleXYZ_DetectUniform_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044b440.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044b440_FUN_0044b440.md` |
| Named record | `docs/reconstruction/functions/aa_0044b440_Xform_SetScaleXYZ_DetectUniform_Inferred.md` |
| Live Ghidra | decompile ≡ raw CF; full 175 B hex |
| Caller | `CVOGEnvironmentReflect_ctor` stamps `(1,−1,1)` on `this+0x90` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
void __thiscall Xform_SetScaleXYZ_DetectUniform_Inferred(
    void* this, float x, float y, float z); // RET 0x0C
```

| Item | Evidence |
|---|---|
| Convention | ECX this; stack 3 floats; epilogue `RET 0x0C` |
| Leaf | no CALL in body |
| Body range | `0044b440`–`0044b4EF` exclusive (**175 B**) |
| Xrefs | **4** sites / **3** caller functions |

---

## 4. Control flow (sealed)

```
load x,y,z from stack
if x==sx && y==sy && z==sz: ret
sx,sy,sz = x,y,z
cache(+0xBC) = -1
if |sx-sy|<=eps && |sx-sz|<=eps:
  uniform(+0xB8)=0; rev++ ; ret
rev++; uniform=1; ret
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| Early-out equality | **Yes** — UCOMISS chain |
| Cache invalidate −1 | **Yes** — `C7 81 BC 00 00 00 FF FF FF FF` |
| eps load | **Yes** — `D9 05 20 A6 AA 00` |
| Dual return paths | **Yes** — two `RET 0x0C` |
| Revision always on change | **Yes** — both branches `INC [+0xB4]` |

---

## 5. Machine bytes

Full 175 B hex in raw W37-R append.

`DAT_00aaa620` = `ac c5 27 37` ≈ **1e-5**.

---

## 6. Gaps

- Product demangle of xform subobject / `FUN_00972cc0` matrix type.
- Consumers of uniform flag / revision / cache token.
- Whether English is always “scale” vs generic float3 (callers use scale-like stamps).
- Runtime / bit-exact / differential.

## 7. Verdict

**accept-with-gaps** — leaf CF, offsets, eps, and thiscall ABI sealed; product type English open.
