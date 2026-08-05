# Review B (skeptical / adversarial): `CVOGReaction_BuildTextParams` @ `0x004e4870`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004e4870_CVOGReaction_BuildTextParams.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Builds final formatted UI string here | Falsified — only list insert |
| 2 | List head at this+0 | Falsified — +0x04 |
| 3 | Singly linked only | Falsified — bi-dir fix via **(node+4) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Head +0x04 list | High | Lost params |
| Insert order (after next) | High | Param order wrong |
| Payload meaning | Medium | Wrong toast args |

---

## 3. Cross-check against raw

```
pHead=*(this+4); node=insert(pHead, pHead->next, payload);
post(1); pHead->next=node; **(node+4)=node.
```

---

## 4. Surviving contract for AutoCore

```
BuildTextParams(listHost, payload):
  append/link param node under host+0x04
  later format/dialog walks list
  not ShowDialog itself
```

---

## 5. Open questions

1. Name FUN_004e29c0/29f0.
2. Payload taxonomy for mission toasts.

**Verdict:** **accept**
