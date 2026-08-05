# Review B (skeptical / adversarial): `aa_0056aca0` Weapon_CanFireHeatCheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056aca0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0056aca0_Weapon_CanFireHeatCheck.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Blocks when heat == 0 | Falsified — only heat>=max |
| 2 | Writes heat | Falsified — pure check |
| 3 | Uses weapon local heat field only | Falsified — vehicle pools |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Offsets +0x150/+0x244 | High | Wrong overheat |
| Null→true | Medium | NPC fire edge |

---

## 3. Cross-check against raw

```
CanFireHeatCheck(wpn): veh=owner.vehicle; return !veh || heat<max.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Authoritative client overheat gate before shot costs.
  AutoCore should mirror heat<max before apply cost.
```

---

## 5. Open questions

1. Test heat==max-1 allow; heat==max deny.

**Verdict:** **accept**
