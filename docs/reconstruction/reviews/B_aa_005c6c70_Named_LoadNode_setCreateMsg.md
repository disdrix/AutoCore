# Review B (skeptical / adversarial): `aa_005c6c70` Named_LoadNode_setCreateMsg

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c6c70_Named_LoadNode_setCreateMsg.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Physics stage _initPhysics | Falsified — setCreateMsg ingress |
| 2 | Only 0x2012 handled | Falsified — multi-case switch |
| 3 | Ignores unknown opcodes silently | Falsified — log+delete |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode→size map | High | Buffer overrun |
| +0x6c ownership | High | Leak / double free |
| 0x2013 AI flag path | Medium | AI never attaches |

---

## 3. Cross-check against raw

```
setCreateMsg(node, msg, ...):
  switch opcode: alloc/copy into +0x6c; 0x2013→recalcInitAI; default log.
Clean ≡ raw CF; residual cases.
```

---

## 4. Surviving contract for AutoCore

```
Load-node create-msg bind. AutoCore client load must accept 0x2012
  SimpleObject layout matching CreateSimpleObject_Serialize.
```

---

## 5. Open questions

1. Trace one character create through setCreateMsg → initPostCreateMsg.

**Verdict:** **accept-with-gaps**
