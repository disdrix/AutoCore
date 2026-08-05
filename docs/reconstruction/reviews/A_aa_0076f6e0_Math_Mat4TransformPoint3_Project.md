# Review A (reconstruction fidelity): `aa_0076f6e0` Math_Mat4TransformPoint3_Project

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f6e0` |
| **VA** | `0x0076f6e0` |
| **Canonical name** | `Math_Mat4TransformPoint3_Project` (structural; product/PDB open) |
| **Ghidra name** | `FUN_0076f6e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0076f6e0_Math_Mat4TransformPoint3_Project.md` |
| **System** | graphics / math (point × matrix, optional divide-by-w) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Transform a **3D point** by a **4×4 matrix** (implicit `w=1`), then **perspective-divide** by output `w` when `w` is valid and not already ~1.

Register convention:

| Reg | Role |
|---|---|
| **EAX** | `const float* in` — xyz |
| **ESI** | `const float* m` — matrix (passed through to `FUN_0076f240`) |
| **EBX** | `float* out` — xyz |

Steps:

1. Build local `vec4 p = (in.x, in.y, in.z, 1.0)`.
2. `FUN_0076f240(&p)` → matrix×vec4 into same local (overwrites xyzw).
3. If `|p.w - 1| > eps` (**and** further stability gates):
   - Require `|p.w - 1| > max(|p.w|, |0.0|?)*eps` style via fabs compare, **and**
   - `p.w >= eps || p.w <= -eps` (reject near-zero w) — decompile: `_DAT_00a240ec <= local_14 || local_14 <= DAT_00aaa640`.
   - Then `inv = 1/p.w`; `out = p.xyz * inv`.
4. Else copy `out = p.xyz` (no divide).

**Does not** write `out.w`. Pure xyz projector helper.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076f6e0_FUN_0076f6e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076f6e0_FUN_0076f6e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0076f6e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076f6e0_FUN_0076f6e0.md` |
| Fresh decompile | Ghidra @ `0x0076f6e0` + callee `0x0076f240` |
| Bytes | `read_memory` — loads `*EAX`, `EAX[1]`, `EAX[2]`; stores `1.0` imm `0x3f800000`; `CALL FUN_0076f240`; FPU `|w-1|` vs `DAT_00a240ec` |
| Call site | `0x00972fbf`: `MOV ESI,EAX` (node after rebuild), `LEA EBX,[ESP+…]`, `MOV EAX,in`, `CALL 76f6e0` |
| Constants | `eps=1e-6` @ `0x00a240ec`; `-eps` @ `0x00aaa640`; double abs helper path loads `0x00aaa5f8` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = TransformPoint3 + conditional /w | **Confirmed** | body |
| EAX=in, ESI=matrix, EBX=out | **Confirmed** | decompile + `00972fbf` site |
| Always seeds w=1 before mul | **Confirmed** | `MOV [esp+…], 0x3f800000` |
| Callee only `FUN_0076f240` | **Confirmed** | analyze complete |
| Divide only when w meaningfully ≠ 1 and not ~0 | **Confirmed** | dual fabs gates |
| Product name | **Open** | structural |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Copy xyz; w=1 | Yes |
| Mat4 mul via `76f240` | Yes |
| Conditional perspective divide | Yes |
| Fallback copy xyz | Yes |

### Recovered CF

```c
// void Math_Mat4TransformPoint3_Project(void)
// EAX=in xyz*, ESI=m[16], EBX=out xyz*
float p[4] = { in[0], in[1], in[2], 1.f };
Math_Mat4MulVec4_AffineFast(p);   // ESI/EDI convention inside callee
if (fabs(p[3] - 1.f) > 1e-6f) {
  float scale = max(fabs(p[3]), /* fabs(0) path via DAT */ …);
  if (scale * 1e-6f < fabs(p[3] - 1.f) && (p[3] >= 1e-6f || p[3] <= -1e-6f)) {
    float inv = 1.f / p[3];
    out[0] = p[0]*inv; out[1] = p[1]*inv; out[2] = p[2]*inv;
    return;
  }
}
out[0] = p[0]; out[1] = p[1]; out[2] = p[2];
```

---

## 5. Callers (inventory; 18 xrefs)

| Caller | Role |
|---|---|
| `FUN_00972fa0` | If dirty bit → rebuild node matrix, then transform point |
| `FUN_00972970` / `FUN_00972a60` / `FUN_009732d0` | Gfx node point xforms |
| `FUN_00731d70` / `FUN_00749fd0` / `FUN_0074be40` / `FUN_0074c9c0` | Mesh / skin |
| `FUN_0075c500` / `FUN_0075c6e0` / `FUN_0075c7e0` | View / camera related |
| `FUN_00439a80` | Older gfx path |
| `FUN_0096b280` / `FUN_0096b470` / `FUN_009813a0` / `FUN_00997b90` | Client render helpers |

Shared primitive — **not** exclusive to one system.

---

## 6. Gaps

1. Product/PDB name.
2. Exact double-load role of `_DAT_00aaa5f8` (0.0 double) in max(|w|,…) — CF sealed, plate wording only.
3. Runtime capture.

**Verdict:** CF + register ABI + project-if-needed sealed. **accept-with-gaps.**
