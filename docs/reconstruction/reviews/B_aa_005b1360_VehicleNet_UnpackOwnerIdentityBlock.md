# Review B (skeptical / adversarial): `aa_005b1360` VehicleNet_UnpackOwnerIdentityBlock

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b1360` |
| **VA** | `0x005b1360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b1360_VehicleNet_UnpackOwnerIdentityBlock.md` |
| **Evidence** | Live decompile + body bytes; pack twin; parent UnpackGhost; callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Same as `FUN_005b2690` (skills HB unpack) | **Falsified** | No count loop; fixed 6 fields only |
| 2 | Writes entity layout like pack sources (+0x160 TFID) | **Falsified** | Dest uses +0x90 TFID / +0x04 / +0x14 seed layout |
| 3 | True `short` first formal | **Falsified** | Slot reused for 16-bit race reads |
| 4 | Applies pack race equal-collapse | **Falsified** | Always stores both 16b fields as read |
| 5 | Clean diverges from raw | **Falsified** | ≡ live |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wire order + widths | **High** | Ghost identity desync |
| Separation from `0x005b2690` | **High** | Mis-port skills path |
| Dest English labels | **Tentative** | Wrong product names |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
UnpackOwnerIdentity(stream, dest):
  readBits64 → dest.tfid@+0x90
  readFlag → dest@+0x98
  readInt20 → dest@+0x04
  readInt18 → dest@+0x14
  readBits16 → dest@+0x1c
  readBits16 → dest@+0x20
```

**Verdict:** **accept-with-gaps**
