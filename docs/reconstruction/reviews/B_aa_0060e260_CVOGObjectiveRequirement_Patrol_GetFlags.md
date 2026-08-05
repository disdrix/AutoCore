# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Patrol_GetFlags` @ `0x0060e260`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060e260_CVOGObjectiveRequirement_Patrol_GetFlags.md` |
| **Verdict** | **accept-with-gaps on dump offsets; rename recommended** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns flag bitfield | **Falsified — void fprintf dump** |
| 2 | GetFlags is accurate name | **Overstated — SerializeXml-like** |
| 3 | Laps value sealed | **Overstated — decompiler omitted arg** |
| 4 | Target pairs are COID only 32-bit | **Partial — prints *puVar1; second dword may be high half** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| XML field offsets | High | Wrong GLM mirror |
| Laps offset | Tentative | Wrong lap config |
| Tool-only vs runtime call | Medium | Dead code assumption |

---

## 3. Surviving contract for AutoCore

```
Patrol_DumpXml(req, FILE*):
  write AutoComplete/Fail + distances, ContinentCBID, GenericTargetCOID[count], Laps
```

---

## 4. Open questions

1. Recover Laps fprintf source offset.
2. Rename candidate: Patrol_SerializeXml / DumpRequirement.

**Verdict:** accept-with-gaps on dump offsets; rename recommended.
