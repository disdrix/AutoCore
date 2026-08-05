# Review B (skeptical / adversarial): `aa_0064da90` hkDefaultAerodynamics_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064da90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064da90_hkDefaultAerodynamics_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runs aero forces | Falsified — construction only; update is 0x64dae0 |
| 2 | Base constructs the descriptor blob | Falsified — base inits this; desc is stack source for copy |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Descriptor field order | High | Swapped drag/lift |
| thiscall base ECX | High | Broken object |

---

## 3. Cross-check against raw

```
aero.ctor(this,desc): base(this); vtbl; copy desc[0..7]→this+0x30; return this;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Aerodynamics component construction for Vehicle_buildHavokVehicleFramework.
```

---

## 5. Open questions

1. Pair with aero update dual (already present).

**Verdict:** accept-with-gaps
