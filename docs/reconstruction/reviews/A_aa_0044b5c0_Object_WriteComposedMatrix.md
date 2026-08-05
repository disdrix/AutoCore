# Review A (reconstruction fidelity): `aa_0044b5c0` Object_WriteComposedMatrix

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044b5c0` |
| **VA** | `0x0044b5c0`–`0x0044b60f` |
| **Canonical name** | `Object_WriteComposedMatrix` |
| **Ghidra name** | `FUN_0044b5c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-C) |
| **Counterpart** | `reviews/B_aa_0044b5c0_Object_WriteComposedMatrix.md` |
| **System** | graphics / xform |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; parent Bounds dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Resolve primary object matrix `@+0x40` (rebuild if dirty bit1), optionally refresh companion transform (dirty bit0), compose into caller `out` buffer; return `out`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044b5c0_FUN_0044b5c0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0044b5c0_FUN_0044b5c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_WriteComposedMatrix.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044b5c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044b5c0_FUN_0044b5c0.md` |
| Parent | `Bounds_AccumulateTransformedLocal` `0x0074c9c0` (xref `0x0074c9eb`) |
| Callees | `FUN_009730e0`, `FUN_00972e50`, `FUN_00412d40` (decomp read for roles) |
| Live | full 80 B hex; dual `C3`; `add esp,0x0C` after compose |

---

## 3. Signature (sealed)

```c
// cdecl ret; ECX primary; EDI companion; stack out; EAX=out
float* Object_WriteComposedMatrix(
    ObjectLike* primary,
    float* outMatrix,
    ObjectLike* companion);
```

| Formal | Source | Conf |
|---|---|---|
| primary | **ECX** | **High** |
| outMatrix | stack0 (`[esp+8]` after push ebx) | **High** |
| companion | **EDI** (not stack) | **High** |
| return | EAX = out | **High** |
| cleanup | caller (`ret` not `ret 4`) | **Confirmed** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if !(flags(primary+0xbc) bit1): matA = primary+0x40
else: matA = FUN_009730e0(primary)
if flags(companion+0xbc) bit0:
  c = FUN_00972e50(companion)
  FUN_00412d40(out, c, matA)
else:
  FUN_00412d40(out, companion, matA)
return out
```

| Stage | Match | Conf |
|---|---|---|
| bit1 → cached vs rebuild | **Yes** | **High** |
| bit0 → refresh companion | **Yes** | **High** |
| 3-arg compose both arms | **Yes** | **High** |
| EAX = out | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body 80 B hex sealed in raw append. Both paths end `mov eax,ebx; pop ebx; ret`.

---

## 6. Gaps

- Product English for ObjectLike / helper name.
- Exact multiply order inside `FUN_00412d80` (not owned).
- Whether companion base is matrix storage vs full object view into compose.
- Runtime / bit-exact open.

## Verdict rationale

Leaf-scale body fully byte-readable; ABI phantoms closed via EDI + parent dual; CF dual-ready for bounds port → **accept-with-gaps** (naming + callee math residual).
