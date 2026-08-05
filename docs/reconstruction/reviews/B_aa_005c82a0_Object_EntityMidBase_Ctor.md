# Review B (skeptical / adversarial): `aa_005c82a0` Object_EntityMidBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c82a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-K) |
| **Counterpart** | `reviews/A_aa_005c82a0_Object_EntityMidBase_Ctor.md` |
| **Scratch** | `tmp/a_005c82a0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a GiveItem helper | **Falsified** — 6 callers incl. CVOGCreature + Vehicle ctors |
| 2 | Decompiler void / unknown ABI | **Overstated** — `RET 4`, ECX=this, EAX=this sealed |
| 3 | Name is retail `CVOG*` | **Overstated** — evidence name; Ghidra still `FUN_005c82a0`; no RTTI sealed |
| 4 | Always constructs SharedBase | **Falsified** — only when mostDerivedFlag≠0; derived ctors pass 0 |
| 5 | Adjustor -0x10c is creature-sized | **Partial** — this class's adjustor; creature uses -0x4fc at its layer |
| 6 | +0xE4=500 is range meters | **Open** — imm sealed; semantic English open |
| 7 | Parent is SharedBase directly | **Falsified** — parent is `FUN_005d4830`; SharedBase only dual-base embed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| mostDerived + SharedBase +0x110 | **High** | Broken MI layout |
| Parent FUN_005d4830(0) | **High** | Wrong base chain |
| Vtbl install + -0x10c | **High** | vcall crash |
| ABI RET 4 | **High** | Stack smash |
| Creature/Vehicle parent role | **High** | Misplaced type |
| Product English | **Medium** | Naming only |
| Field semantics | **Open** | Port comments only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
self=ECX; flag=stack0
if flag: cookies; SharedBase(self+0x110)
FUN_005d4830(self,0)
*self / +0x40 vtbls; vb adjustor -0x10c
defaults +0xD0..+0xF8 (500 @ +0xE4)
RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean plate preserves CF; names role only.

---

## 4. Surviving contract for AutoCore

```
// Entity mid-base (creature/vehicle parent layer)
Object_EntityMidBase_Ctor(obj, mostDerivedFlag)
// when mostDerived: Object_SharedBase lives at obj+0x110
// vb adjustor -0x10c is class-specific (not creature -0x4fc)
// do not invent product class name without RTTI
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/chain; product English + field dictionary remain open → **accept-with-gaps**.
