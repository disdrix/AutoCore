# Review B (skeptical / adversarial): `aa_0051b2a0` Object_LazyFillMatColorVecFromMesh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b2a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9R-H) |
| **Counterpart** | `reviews/A_aa_0051b2a0_Object_LazyFillMatColorVecFromMesh_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Always rebuilds material bank | **Falsified** — early out when `(end-begin)>>4 != 0` |
| 2 | This is FUN_00519280 itself | **Falsified** — thin lazy gate + probe; strings live in callee |
| 3 | Identical to FUN_004c5480 | **Falsified** — 004c5480 **calls** this then may fill a **second** bank from a direct mesh pointer; dual-path wrapper |
| 4 | cdecl / no this | **Falsified** — ECX this; RET 0x10 cleans 4 stack dwords |
| 5 | Vector stride is 4 (pointer vector) | **Falsified** — `SAR 4` ⇒ 16-byte elements (float4-sized) |
| 6 | Skill-bank helper by body | **Overstated** — mesh/material graphics path; WQ-009 residual by partition only |
| 7 | Product English known | **Overstated** — `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty guard + RET 0x10 | **High** | Double-fill / wrong cleanup |
| this+0x144 bank layout | **High** | Wrong vector writes |
| FUN_00519280 material role | **High** | Mis-port colors |
| vtbl+0x1CC type | **Medium** | Wrong mesh accessor |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against FUN_004c5480

```
CALL Object_LazyFillMatColorVecFromMesh  ; bank A via vtbl+0x1CC
if meshB @ adjusted-this-0x27c:
  if bankB empty: FUN_00519280(meshB, bankB, colors)
```

Confirms this unit is the **primary lazy path** for the vtbl-probed mesh bank; caller may also fill a sibling bank. Do not fold 004c5480 into this VA.

---

## 4. Surviving contract for AutoCore

```
// Port as virtual method:
Object_LazyFillMatColorVecFromMesh_Inferred(self, c0, c1, c2, c3);
// No-op if vector at self+0x148 already has elements (stride 16).
// Else probe vtbl+0x1CC; require probe && probe+8; call FUN_00519280.
// Must RET 0x10 (stdcall-clean 4 dwords) when used as __thiscall+stack.
// Keep separate from FUN_004c5480 dual-bank wrapper and from FUN_00519280 body.
```

---

## 5. Verdict

Adversarial pass confirms A on guard, ABI, bank offsets, and separation from callee/wrapper. Product/probe-type residual → **accept-with-gaps**.
