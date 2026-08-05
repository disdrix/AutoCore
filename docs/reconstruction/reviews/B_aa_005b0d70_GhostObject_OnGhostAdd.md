# Review B (skeptical / adversarial): `aa_005b0d70` GhostObject_OnGhostAdd

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005b0d70_GhostObject_OnGhostAdd.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Can return 0 failure | Falsified — always 1 |
| 2 | Unpacks bitstream | Falsified — no BitStream |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x50 gate | High | Skip object notify |
| Spatial fallback | Medium | Wrong world insert |

---

## 3. Cross-check against raw

```
OnGhostAdd: +0x50? vtbl+0x2b8 : FUN_005a0b30(+0x40); return 1.
```

---

## 4. Surviving contract for AutoCore

```
Ghost add notify; pair with scope add on AutoCore connection.
```

---

## 5. Open questions

1. Trace one foreign ghost add live.

**Verdict:** **accept-with-gaps**
