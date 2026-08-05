# Review B (skeptical / adversarial): `aa_005b1290` VehicleNet_PackOwnerIdentityBlock

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b1290` |
| **VA** | `0x005b1290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b1290_VehicleNet_PackOwnerIdentityBlock.md` |
| **Evidence** | Live decompile + body bytes; parent PackUpdate dual; callees |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Same as `FUN_005b2830` (skills HB pack) | **Falsified** | No HB walk, no critical section; straight identity writes |
| 2 | Free function with race-id input | **Falsified** | thiscall ghost + stream stack; race is **output** |
| 3 | Writes skills list | **Falsified** | TFID/flag/CBID/metric/race only |
| 4 | Negative vfunc value written raw | **Falsified** | Clamped to 0 when &lt; 0 |
| 5 | Always writes second race | **Falsified** | Zeroed when equal to root race |
| 6 | Clean diverges from raw | **Falsified** | ≡ live |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wire order + widths | **High** | Unpack desync on initial ghost |
| Separation from `0x005b2830` | **High** | Mis-port skills path |
| Field English | **Tentative** | Wrong product labels |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
PackOwnerIdentity(ghost, stream):
  writeBits64(entity.tfid)
  writeFlag(entity.tfidGlobal)
  writeInt20(cbid-ish)
  writeInt18(max(0, vfunc244()))
  writeBits16(rootRace)
  writeBits16(vfunc290() == rootRace ? 0 : vfunc290())
```

**Verdict:** **accept-with-gaps**
