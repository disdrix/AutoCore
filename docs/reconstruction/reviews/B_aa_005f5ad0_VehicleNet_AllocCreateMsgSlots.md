# Review B (skeptical / adversarial): `aa_005f5ad0` VehicleNet_AllocCreateMsgSlots

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f5ad0` |
| **VA** | `0x005f5ad0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005f5ad0_VehicleNet_AllocCreateMsgSlots.md` |
| **Evidence** | Live decompile; setCreateMsg size/opcode twins; UnpackGhostVehicle |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always writes only `this+0x5c` | **Falsified** | param_2≠0 uses +0x60 |
| 2 | 0x2013 path size is 0xD8 | **Falsified** | 0x930 (0x24C dwords) |
| 3 | operator_delete never returns | **Falsified** | normal free; CF continues |
| 4 | Fills full create payload fields | **Falsified** | template stamps only (opcodes/−1/ones) |
| 5 | Has non-UnpackGhost callers | **Falsified** | 3 xrefs all UnpackGhostVehicle |
| 6 | Clean diverges | **Falsified** | ≡ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Branch sizes + opcodes | **High** | corrupt create templates |
| Slot offset 0x5c/0x60 | **High** | wrong host field |
| Nested vehicle sub-opcodes | **High** | partial layout error |
| Product English for 0x201D | **Medium** | name only |
| Pre-zero dead stores | **High** | no runtime impact |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
AllocCreateMsgSlots(host, useOwnerSlot, isCharLarge):
  if !useOwnerSlot:
    replace host+0x5c with zeroed 0xD78, * = 0x201D (+ nested stamps)
  else if isCharLarge:
    replace host+0x60 with zeroed 0x930, * = 0x2013
  else:
    replace host+0x60 with zeroed 0x1A8, * = 0x2015 (+ bit +0x129)
```

**Verdict:** **accept-with-gaps**
