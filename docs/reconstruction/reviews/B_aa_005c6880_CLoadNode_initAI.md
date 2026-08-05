# Review B (skeptical / adversarial): `aa_005c6880` CLoadNode_initAI

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c6880_CLoadNode_initAI.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Skips HBAI entirely | Falsified — vtbl+0xc0 |
| 2 | Returns wait code 3 | Falsified — always 0 |
| 3 | Only vehicles | Falsified — creature gate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HBAI attach | High | NPC no AI |
| TFID gate | Medium | Wrong AI on props |

---

## 3. Cross-check against raw

```
_initAI: +0x64=0; host=vtbl+0x1d8; gate; host.vtbl+0xc0(en,-1); return 0.
```

---

## 4. Surviving contract for AutoCore

```
Client load-time AI attach; pairs with CVOGHBAI factory on server RE.
```

---

## 5. Open questions

1. Trace NPC spawn load through initAI.

**Verdict:** **accept-with-gaps**
