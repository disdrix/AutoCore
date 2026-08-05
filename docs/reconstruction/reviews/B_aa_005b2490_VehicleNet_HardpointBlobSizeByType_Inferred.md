# Review B (skeptical / adversarial): `aa_005b2490` VehicleNet_HardpointBlobSizeByType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2490` |
| **VA** | `0x005b2490` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b2490_VehicleNet_HardpointBlobSizeByType_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always 0xD8 | **Falsified** | 5 case groups |
| 2 | Malloc inside this unit | **Falsified** | size only; parent mallocs |
| 3 | Type at def+0 | **Falsified** | switch on **+0x38** |
| 4 | Null handle crashes | **Falsified** | resolve 0 → return 0 |
| 5 | Used by pack path | **Falsified** | unpack alloc only |

---

## 2. Surviving contract

```
size = table[resolve(handle)->type@+0x38] or 0
// 8/0x32→0xE0; 0xA→0x150; 0xC→0x188; 0x10/0x1C→0x158; else 0xD8
```

**Verdict:** **accept**
