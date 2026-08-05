# Review B (skeptical / adversarial): `aa_005b3110` VehicleNet_SkillsHBNodeVector_Push_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3110` |
| **VA** | `0x005b3110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b3110_VehicleNet_SkillsHBNodeVector_Push_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Linked-list insert | **Falsified** | contiguous vector begin/end/cap |
| 2 | Element size 0x18 (HB node full) | **Falsified** | stride **0xC** |
| 3 | Always reallocates | **Falsified** | fast path when room remains |
| 4 | Writes BitStream | **Falsified** | collector only; pack is later |
| 5 | Shared with hardpoint alloc | **Falsified** | sole caller PackOwnerSkillsHB |

---

## 2. Surviving contract

```
Push(vec, item):
  if room: place-construct at end; end += 12
  else: grow-insert helper
```

**Verdict:** **accept-with-gaps**
