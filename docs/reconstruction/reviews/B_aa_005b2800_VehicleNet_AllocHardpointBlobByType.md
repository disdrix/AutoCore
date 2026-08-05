# Review B (skeptical / adversarial): `aa_005b2800` VehicleNet_AllocHardpointBlobByType

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2800` |
| **VA** | `0x005b2800` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b2800_VehicleNet_AllocHardpointBlobByType.md` |
| **Evidence** | Live decompile + `FUN_005b2490`; UnpackGhostVehicle |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Zero-fills buffer | **Falsified** | `malloc` only |
| 2 | size 0 still mallocs | **Falsified** | signed `> 0` gate |
| 3 | embeds type switch in this VA | **Falsified** | switch is `0x005b2490` |
| 4 | frees prior buffer | **Falsified** | no free |
| 5 | Clean ≠ raw | **Falsified** | ≡ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| out-size + conditional malloc | **High** | hardpoint OOB |
| size table correctness | **High** | wrong blob stride |
| product type names | **Low** | naming only |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
AllocHardpointBlobByType(defHandle, outSize):
  n = SizeByCloneType(defHandle)   // 0 / 0xD8 / 0xE0 / 0x150 / 0x158 / 0x188
  *outSize = n
  return n > 0 ? malloc(n) : null
```

**Verdict:** **accept-with-gaps**
