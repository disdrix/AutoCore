# Review B (skeptical / adversarial): `aa_008092a0` Client_RecvGroupReactionCall

| Field | Value |
|---|---|
| **Stable ID** | `aa_008092a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008092a0_Client_RecvGroupReactionCall.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on opcode + entry field names |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always fires every entry | **Falsified — TFID mismatch / null resolve skips** |
| 2 | Variable and reaction both always run | **Falsified — mutually exclusive on @+0xc** |
| 3 | Soft-pedal 500ms is client-enforced | **Falsified as body claim — server policy note only** |
| 4 | Finished field map | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride 0x28 + count@+4 | High | Misaligned batch |
| SetVariable vs fire polarity of @+0xc | High | Wrong map vars vs FX |
| vcall +0x2c0 is fire | Probable | Wrong reaction hook |
| Opcode | Tentative | Dead handler |

---

## 3. Cross-check against raw

```
for i in 0..count-1:
  e = pkt + i*0x28
  if e+0xc var-flag: CVOGMap_SetVariable(id@+0x10,val@+0x14,0)
  else if fire allowed by TFID filters:
    rxn = resolve(0, +0x10,+0x14); obj = ResolveTFID(+0x18); rxn->vcall+0x2c0(obj)
Clean matches.
```

---

## 4. Surviving contract for AutoCore

```
On S2C GroupReactionCall:
  for each packed entry: SetVariable OR fire reaction on resolved object
  respect TFID filters vs local character/vehicle
Do not invent client-side 500ms soft-pedal in this function.
```

---

## 5. Open questions

1. Dispatch opcode seal.
2. Full LogicStateChange struct names.
3. Runtime group-reaction capture after dialog.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on opcode + entry field names
