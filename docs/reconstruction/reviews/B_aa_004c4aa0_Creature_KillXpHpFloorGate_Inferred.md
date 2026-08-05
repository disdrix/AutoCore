# Review B (skeptical / adversarial): `aa_004c4aa0` Creature_KillXpHpFloorGate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c4aa0_Creature_KillXpHpFloorGate_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Multi-caller utility | Single xref `004da8d8` | **Survives** as OnDeath-only |
| 2 | Scale is 0.5 | Bytes at `aaa6e0` are **0.1** double | **Falsified** 0.5 |
| 3 | Always returns full int max | Returns 0 or one byte flag | **Falsified** |
| 4 | `CONCAT31` high bytes meaningful | Caller compares as `char == 0` | **Survives** low-byte only |
| 5 | Is XP amount calculator | Gate only; XP mult uses `004c4b20` + template `+0x500` | **Falsified** as amount |

---

## 2. Live ≡ raw

Decompile CF sealed. Bias global name matches mission XP round pattern.

---

## 3. Surviving contract

```
// ECX=creature*
// if cur < round(max*0.1) → 0 else → (u8)this[+0x309]
```

**Verdict:** **accept-with-gaps**.
