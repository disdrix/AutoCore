# Review A (reconstruction fidelity): `aa_005d1d20` Math_QuatExtractForwardZ_OutFirst_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1d20` |
| **VA** | `0x005d1d20`–`0x005d1d93` (116 B) |
| **Canonical name** | `Math_QuatExtractForwardZ_OutFirst_Inferred` |
| **Ghidra name** | `FUN_005d1d20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-J) |
| **Counterpart** | `reviews/B_aa_005d1d20_Math_QuatExtractForwardZ_OutFirst_Inferred.md` |
| **System** | math / quat basis extract |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (body + consts) + callers |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf helper: from unit quaternion **`q = (x,y,z,w)`** write the chassis / pose **forward (+Z)** world direction as homogeneous `float[4]` with **W=0**.

Closed form (unit quat → rotation-matrix **column 2**):

```
out.x = 2*(z*x + y*w)
out.y = 2*(z*y - x*w)
out.z = 1 - 2*(x² + y²)
out.w = 0
```

**Arg order:** `(out, quat)` — reverse of sealed `Math_QuatExtractForwardZ` @ `0x004e8a40` which is `(quat, out)`. Algebra is identical.

**Not this unit:** right/up extractors; normalize; finite check (`0x005d6870` is a separate gate used beside this in aim-offset).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d1d20_FUN_005d1d20.md` (+ W27-J live append) |
| Annotated | `docs/reconstruction/raw/aa_005d1d20_FUN_005d1d20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005d1d20.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/Math_QuatExtractForwardZ_OutFirst_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_005d1d20_FUN_005d1d20.md` |
| Sibling dual | `reviews/A_aa_004e8a40_Math_QuatExtractForwardZ.md` |
| Live | decompile ≡ raw CF; body ends `C3`; consts re-read |

---

## 3. Signature (sealed)

```c
void Math_QuatExtractForwardZ_OutFirst_Inferred(float *out /* param_1 */, float *quat_xyzw /* param_2 */);
// __cdecl, bare RET
```

| Claim | Conf |
|---|---|
| `param_1` = out, `param_2` = quat | **High** — stores only through `[esp+4]` reload; loads from `[esp+8]` |
| cdecl / bare RET | **High** — hex ends `C3`; no `RET imm` |
| XYZW indices | **High** — `*q,q[1],q[2],q[3]` as x,y,z,w |
| Leaf | **High** — no call/jmp out |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| Load TWO from `0x00a10e74` | **Yes** | **High** |
| Load ONE from `0x00a0f2a0` | **Yes** | **High** |
| `out[1] = (z*y - w*x)*TWO` | **Yes** | **High** |
| `out[0] = (w*y + z*x)*TWO` | **Yes** | **High** |
| `out[2] = ONE - (x*x+y*y)*TWO` | **Yes** | **High** |
| `out[3] = 0` | **Yes** | **High** |
| No branches | **Yes** | **High** |

Store order (Y, then X, then Z, then W) matches decompile; values match closed form.

---

## 5. Constants (`read_memory`)

| Symbol (Ghidra) | Addr | LE bytes | float32 | Role |
|---|---|---|---:|---|
| `g_flLevelUpUiBase_Inferred` | `0x00a10e74` | `00 00 00 40` | **2.0** | quat factor 2 |
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** | diagonal term |

UI name on the 2.0 pool is a **misnomer** here (shared constant pool).

---

## 6. Callers

| Site | Parent | Role |
|---|---|---|
| `0x005cf312` | `FUN_005cedf0` / CVOGHBAI_UpdateAimOffset | pose orient → forward for aim-offset build |

Sole xref this pass. Drive/control stack uses sibling `0x004e8a40` instead.

---

## 7. Gaps

- Product/PDB symbol — open (**Inferred**).
- Runtime golden (identity / 90° yaw) — optional; algebra sealed vs `0x004e8a40`.
- Bit-exact vs retail image — deferred.

**Verdict:** **accept**
