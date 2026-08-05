# Review B (skeptical / adversarial): `aa_004f3630` VehicleEntity_SetFlag_109

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f3630_VehicleEntity_SetFlag_109.md` |
| **Verdict** | **accept-with-gaps** — CF sealed; meaning open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is handbrake | Falsified — different offset |
| 2 | Complex logic | Falsified — one store |
| 3 | Named semantic sealed | Overstated — offset name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store at +0x109 | High | Wrong byte |
| Flag purpose | Tentative | Misuse in port |

---

## 3. Cross-check against raw

```
*(u8*)(entity+0x109) = flag;
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetFlag_109(entity, flag):
  opaque u8 at +0x109; seal name via xrefs before product use
  low AutoCore priority until consumers known
```

---

## 5. Open questions

1. Xref map for +0x109 readers.
2. Ghost pack / create packet inclusion?

**Verdict:** **accept-with-gaps** — CF sealed; meaning open
