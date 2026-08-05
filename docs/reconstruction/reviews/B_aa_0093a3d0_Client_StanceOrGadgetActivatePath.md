# Review B (skeptical / adversarial): `Client_StanceOrGadgetActivatePath` @ `0x0093a3d0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093a3d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0093a3d0_Client_StanceOrGadgetActivatePath.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Normal 0x2030 cast only | Weak — stance/gadget/cast-again family |
| 2 | Ignores rank 0 skills | Supported — checks +0x5f6!=0 |
| 3 | Fully documented port-ready | Overstated — INFERRED |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slots 0..2 at char+0xd58 | High | Wrong stance skill |
| Cast-again heartbeat path | High | Broken stance toggle |
| INFERRED completeness | Tentative | Missing branches |

---

## 3. Cross-check against raw

```
StanceOrGadgetActivatePath:
  slot 0..2 → skill from char+0xd58;
  resolve via vtbl+0x234; require +0x5f6;
  cast-again / failure message helpers;
  INFERRED — finish walk before port.
```

---

## 4. Surviving contract for AutoCore

```
StanceOrGadgetActivatePath:
  client stance/gadget activate; related 0x20bb cast-again;
  do not treat as fully sealed.
```

---

## 5. Open questions

1. Finish full decompile walk + opcode confirm.
2. Cross-check skill-cast topic extraction.

**Verdict:** **accept-with-gaps**
