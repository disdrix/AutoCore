# Review B (skeptical / adversarial): `aa_0040d3f0` Math_Vec3NearlyEqual_AbsRel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d3f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-A) |
| **Counterpart** | `reviews/A_aa_0040d3f0_Math_Vec3NearlyEqual_AbsRel.md` |
| **Scratch** | `tmp/a_0040d3f0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure cdecl with all args on stack | **Falsified** — decompiler `unaff_ESI`/`unaff_EDI`; call site LEA into ESI/EDI; body `RET 8` only cleans 8 B |
| 2 | This is a length/distance compare | **Falsified** — three independent scalar nearness calls; no sqrt/dot |
| 3 | Compares only x,y (2D) | **Falsified** — loads +0/+4/+8 (3 components) |
| 4 | thiscall / ECX object | **Falsified** — ESI/EDI pointers; no ECX this |
| 5 | Returns float / void | **Falsified** — `XOR EAX,EAX` / `MOV EAX,1` then `RET 8` |
| 6 | Product name is retail string | **Overstated** — no string xref; name inferred |
| 7 | ESI is b and EDI is a (swapped) | **Partially careful** — leaf call order is `( *edi, *esi, … )` so first leaf formal is EDI component; C rename uses a=ESI, b=EDI consistently with that order |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-component short-circuit CF | **High** | Wrong equality gate |
| ESI/EDI + RET 8 ABI | **High** | Port ABI break |
| abs+rel via leaf | **High** | Wrong tolerance math |
| Product English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
ESI=a, EDI=b
push absTol; push relTol; CALL
for i in 0,1,2:
  if !NearlyEqual(b[i], a[i], rel, abs): EAX=0; RET 8
EAX=1; RET 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Caller `0x0090f625` confirms LEA ESI/EDI + dual `0x358637BD` pushes.

---

## 4. Surviving contract for AutoCore

```
// Port with portable C signature (register ABI is MSVC custom):
near = Math_Vec3NearlyEqual_AbsRel(a, b, relTol, absTol)
// true iff all 3 components pass Math_FloatNearlyEqual_AbsRel
// common client eps ~1e-6 (0x358637BD) for both tols
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/semantics sealed; product name residual only → **accept**.
