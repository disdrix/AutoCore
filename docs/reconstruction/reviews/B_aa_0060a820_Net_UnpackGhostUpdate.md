# Review B (skeptical / adversarial): `aa_0060a820` Net_UnpackGhostUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060a820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060a820_Net_UnpackGhostUpdate.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | This is VehicleNet_UnpackGhostVehicle | Falsified — distinct VA 0x0060a820 |
| 2 | Packs initial create stream | Falsified — unpack/read path only |
| 3 | Authoritative server sim | Falsified — client net unpack |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| BitStream read order | High | Desync / bad ghost state |
| Sibling split vs 005b17b0 / vehicle | High | Wrong port ownership |
| Full mask table | Medium | Partial combat fields |

---

## 3. Cross-check against raw

```
UnpackGhostUpdate(obj, stream, flags):
  BitStream_read* → field patch branches → ResolveObjectTarget helpers.
Clean ≡ raw CF; residual FUN names + mask ledger.
```

---

## 4. Surviving contract for AutoCore

```
Client ghost delta apply path for non-vehicle-specialized objects.
  AutoCore ghost receivers must preserve read order and sibling split.
```

---

## 5. Open questions

1. Map each GHOST mask bit to the branch that consumes it.
2. Live-diff one foreign vehicle + creature pack against this path.

**Verdict:** **accept-with-gaps**
