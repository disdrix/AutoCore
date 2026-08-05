# Review A (reconstruction fidelity): `aa_009729d0` Math_Mat4TransformDirection3_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009729d0` |
| **VA** | `0x009729d0` |
| **Canonical name (Ghidra)** | `FUN_009729d0` |
| **Proposed name** | `Math_Mat4TransformDirection3_Inferred` (**High** role; product name open) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_009729d0_Math_Mat4TransformDirection3_Inferred.md` |
| **System** | graphics / math (direction × matrix) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Transform a **3D direction** (implicit **w = 0**) by a **4×4 matrix**, writing **xyz** back to the same buffer. Sibling of point transform (`Math_Mat4TransformPoint3_Project` `0x0076f6e0`, which seeds **w = 1**).

Callee: sealed `Math_Mat4MulVec4_AffineFast` `0x0076f240` (affine fast path skips translation when w≈0).

### Control flow (summary)

1. Load `v.xyz` from `param_1` into aligned local `vec4`.
2. Set `v.w = 0`.
3. Call `FUN_0076f240(&local)` with register convention:
   * **ESI** = matrix (caller-owned; not a stack formal of this wrapper)
   * **EDI** = input vec4 (local)
   * stack/out = local (overwrite)
4. Store `local.xyz` back to `param_1` (**w not written**).

**Not** perspective divide. **Not** point transform (no translation under affine matrix). **Not** normalize (callers often normalize first — e.g. unproject).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x009729d0` + callee `0x0076f240` |
| Entry bytes | `read_memory` @ `0x009729d0` — stack align; `mov ebx,[ebp+8]`; `movss` load xyz; `lea` local; call path |
| Callee dual | `A\|B_aa_0076f240_Math_Mat4MulVec4_AffineFast` |
| Point sibling | `A_aa_0076f6e0_Math_Mat4TransformPoint3_Project` (w=1) |
| Caller dual | `A_aa_0075c340_GfxView_UnprojectScreenToWorldRay_Inferred` — **TransformDirection** after Normalize |
| Callers | `get_function_callers` → `0075c340`, `007a0900` (+ more via limit) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_009729d0` |
| Function record | `docs/reconstruction/functions/aa_009729d0_FUN_009729d0.md` |

**This pass:** live decompile; callee dual; entry bytes; unproject cite. **Not performed:** Launcher, ledgers.

---

## 3. Signature

```c
// Stack: direction xyz in/out.
// Register: ESI = const float m[16]  (caller-preloaded; MSVC custom like sibling helpers)
void Math_Mat4TransformDirection3_Inferred(float dir[3] /* EDI/local via stack formal */);
// Recovered:
//   float tmp[4] = { dir[0], dir[1], dir[2], 0.f };
//   Math_Mat4MulVec4_AffineFast(tmp);  // ESI=m, EDI=tmp
//   dir[0]=tmp[0]; dir[1]=tmp[1]; dir[2]=tmp[2];
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `Math_Mat4MulVec4_AffineFast` `0x0076f240` | Mat4×vec4; w≈0 → linear (no T) |

| Caller | Role |
|---|---|
| `GfxView_UnprojectScreenToWorldRay_Inferred` `0x0075c340` | World-space ray direction |
| `FUN_007a0900` | Gfx transform path |
| (others) | Skin/object direction sites listed under callee dual |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Copy xyz; seed w=0 | Yes |
| Single callee `0076f240` | Yes |
| Write back xyz only | Yes |
| No normalize / no /w | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = TransformDirection3 (w=0) | **Confirmed** | body vs point sibling w=1 |
| Callee affine path drops translation for w=0 | **Confirmed** | callee dual |
| ESI = matrix at call | **High** | same family as `0076f6e0` / `0076f240` convention |
| Stack formal = dir xyz in/out | **Confirmed** | `mov ebx,[ebp+8]` |
| Product name | **Open** | structural; unproject dual already says TransformDirection |
| In-place only (no separate out) | **High** | single buffer |

---

## 7. Gaps / open

1. Product/PDB name.
2. Full caller inventory beyond first page of xrefs.
3. Document all register clobbers for safe re-exports.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — direction transform CF sealed vs point sibling.
