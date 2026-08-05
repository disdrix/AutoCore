# Review B (skeptical / adversarial): `aa_005b13f0` VehicleNet_PackSkillHBEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b13f0` |
| **VA** | `0x005b13f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b13f0_VehicleNet_PackSkillHBEntry_Inferred.md` |
| **Evidence** | Live decompile; sole caller PackOwnerSkillsHB |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Bulk memcpy of whole record | **Falsified** | Structured ints + optional flags + tail |
| 2 | Same as identity block `0x005b1290` | **Falsified** | Different wire; parent is skills HB only |
| 3 | Always packs both identity triples | **Falsified** | Each gated by writeFlag(differs) |
| 4 | Tail always 0 bits | **Falsified** | `param_4*8 - 0x1c0` can be positive |
| 5 | Multiple pack callers | **Falsified** | only `0x005b2830` |
| 6 | Writes thr/steer/pose | **Falsified** | skills entry only |

---

## 2. Surviving contract

```
PackSkillHBEntry(ghostCtx, rec, size, flagCtx):
  writeInt14(rec.c) writeInt8(rec.e) writeInt8(rec.kind)
  if flag(flagCtx):
    write32×2; maybe identityA; flag; int10; maybe identityB
  writeBits(size*8 - 0x1c0, rec+0x38)
```

**Verdict:** **accept-with-gaps**
