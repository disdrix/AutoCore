# Review B (skeptical / adversarial): `aa_004cdd20` CVOGSectorMap_DoCreatorLoadTrigger

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cdd20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004cdd20_CVOGSectorMap_DoCreatorLoadTrigger.md` |
| **Verdict** | **accept-with-gaps** on CF; once-semantics High |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Fires every character add | **Falsified — +0x74 once + caller condition** |
| 2 | Shares player TFID fields | **Falsified — E7E8/EC** |
| 3 | No timestamp | **Falsified — +0x6C write** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Once flag +0x74 | High | Repeat creator missions |
| Creator TFID pair | High | Wrong instance hook |
| Caller count condition | High | Never/too-early fire |

---

## 3. Cross-check against raw

```
if +0x74: return;
+0x74=1; +0x6C=GetTickCount();
lookup TFID E7E8/E7EC; fire +0x114.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
DoCreatorLoadTrigger(sectorMap):
  once per map instance (+0x74); stamp time; fire creator TFID reaction
  not a substitute for per-player on-load
  pair with AddCharacter count condition for first eligible add
```

---

## 5. Open questions

1. Who resets +0x74 on map unload.
2. Asset naming for creator load trigger COID.

**Verdict:** **accept-with-gaps** on CF; once-semantics High
