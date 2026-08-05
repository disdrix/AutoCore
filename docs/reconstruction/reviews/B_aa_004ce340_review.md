# Review B (skeptical / adversarial): `aa_004ce340` CVOGCharacter_WeaponAllowsKillXpBonus

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce340` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Verdict** | **needs-more-evidence** (on naming / object identity); body gate is solid |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Name means “weapon allows kill XP bonus” | **Falsified as description of body** — no weapon lookup; only `+0x100` and `+0xac` |
| 2 | Gate is Character-specific | **Unproven** — offsets do not appear on XP.md Character field map (`+0x730` etc.) |
| 3 | Used only for kill-path spree | **Falsified** — xrefs: `AddExperience`, `HasCompletedMission`, `GiveMission`, `Vehicle_RecalcCombatPools`, others |
| 4 | `this+0xa0 != 0` is meaningful | **Weak** — LEA of valid object field is never null; likely dead / stylistic check |
| 5 | Returns “bool-ish int” with upper bits | **Overstated in raw** — listing clears to AL only; upper EAX undefined |

---

## 2. What survives attack

- Exact three conditions for AL=1 from 11-instruction body.
- Call-site set is multi-system (mission dual-hash + kill XP + vehicle).
- Treat as **mode / eligibility flag**, not weapon code, until producers of `+0x100` / `+0xac` are mapped.

---

## 3. Required evidence for stronger accept

1. Type recovery of ECX object at primary call sites (who loads ECX before `CALL 0x004ce340`).
2. Writers of `+0x100` and `+0xac` (what sets mode 2).
3. Runtime CE: toggle fields, confirm AddExperience spree scale and HasCompletedMission hash policy.

---

## 4. Risk if AutoCore trusts the retail name

Server code that keys “weapon equipped → XP bonus” from this name will be **wrong**. Implement only the boolean field test once the host object is identified, or bypass client gate entirely and apply server policy.
