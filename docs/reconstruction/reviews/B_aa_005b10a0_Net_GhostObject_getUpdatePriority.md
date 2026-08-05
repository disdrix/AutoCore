# Review B (skeptical / adversarial): `aa_005b10a0` Net_GhostObject_getUpdatePriority

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b10a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005b10a0_Net_GhostObject_getUpdatePriority.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always returns fixed 0.5 | Falsified — distance formula |
| 2 | Ignores self relation | Falsified — returns 1.0 |
| 3 | Uses 3D full distance only | Falsified — XZ (x,z) pair |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Priority formula | High | Ghost bandwidth wrong |
| +0x50 object ptr | High | Null crash / always low prio |
| DAT constants | Medium | Scale error |

---

## 3. Cross-check against raw

```
getUpdatePriority(ghost, other, …, base):
  null+0x50 → base*k; self/parent/child/TFID → 1.0;
  else scale*(1 - dist/(range*…))*c + base*dt.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Ghost update scheduling weight for AutoCore scope/priority.
```

---

## 5. Open questions

1. Live-compare priorities for near vs far ghosts.

**Verdict:** **accept-with-gaps**
