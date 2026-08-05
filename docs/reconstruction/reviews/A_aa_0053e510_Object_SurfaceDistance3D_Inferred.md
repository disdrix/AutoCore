# Review A (reconstruction fidelity): `aa_0053e510` Object_SurfaceDistance3D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e510` |
| **VA** | `0x0053e510`–`0x0053e5ad` |
| **Canonical name** | `Object_SurfaceDistance3D_Inferred` |
| **Ghidra name** | `FUN_0053e510` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-H) |
| **Counterpart** | `reviews/B_aa_0053e510_Object_SurfaceDistance3D_Inferred.md` |
| **System** | shared-object-pose / AI-range |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` entry/tail + `get_function_by_address` + `get_bulk_xrefs` + `get_function_callers`; cross-check `aa_00404c90` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf math helper: **surface-to-surface 3D distance** between two objects = Euclidean distance between world positions minus each object's float radius at `+0x34`. Position resolve inlined (physics `rb+0xb0` or entity `+0x84`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053e510_FUN_0053e510.md` (+ W25-H append) |
| Annotated | `docs/reconstruction/raw/aa_0053e510_FUN_0053e510.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_SurfaceDistance3D_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0053e510.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053e510_Object_SurfaceDistance3D_Inferred.md` |
| Live | decompile `0x0053e510`; `read_memory` 128 B + tail; bulk xrefs |
| Sibling | `aa_00404c90` Object_GetWorldPositionPtr |

---

## 3. Signature

```c
// Ghidra: float10 __thiscall FUN_0053e510(int param_1, int param_2)
// Bytes:  prolog uses ECX; load other from [ebp+8]; fsqrt; fsub radii; ret 4
float10 __thiscall Object_SurfaceDistance3D_Inferred(int objA /*ECX*/, int objB /*stack*/);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=A | `mov eax,[ecx+8]` | **High** |
| stack B | `mov edx,[ebp+8]` | **High** |
| ret 4 | `C2 04 00` | **High** |
| float10 / ST0 return | fsqrt path; consumers compare float | **High** |

---

## 4. Control flow (sealed)

```
SurfaceDistance3D(A, B):
  posA = WorldPosPtr(A)   // dual path
  posB = WorldPosPtr(B)
  return sqrt(dx^2+dy^2+dz^2) - A.radius - B.radius
```

| Stage | Match | Conf |
|---|---|---|
| Dual pos resolve A | **Yes** | **High** |
| Dual pos resolve B | **Yes** | **High** |
| 3-component Euclidean | **Yes** | **High** |
| Subtract both +0x34 | **Yes** (`D8 61 34` / `D8 62 34`) | **High** |
| No external CALL | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Decode |
|---|---|
| Entry | align prolog; gate `this+8` |
| Phys path | `*(phys+0x3c)+0xB0` |
| Fallback | lea `adj + this + 0x84` |
| Tail | `fsqrt`; fsub `[ecx+0x34]`; fsub `[edx+0x34]`; leave; ret 4 |

**No `disassemble_bytes` used.**

---

## 6. Call surface

11+ unconditional CALL sites including AI pursue/fire and interact-objective paths (full table in raw W25-H append). Callees: none.

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI + 3D surface distance CF | **High** |
| Pos paths ≡ `00404c90` | **High** |
| `+0x34` as subtracted radius | **High** (role) |
| Product name | **Open** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product mangled / English symbol.
2. Product English for `+0x34` (collision vs selection radius).
3. Consumer handling of negative (overlap) results.
4. Live float differential.

**Verdict:** **accept-with-gaps** — math + pose resolve sealed; naming product-open.
