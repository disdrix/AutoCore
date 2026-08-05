# Review B (skeptical / adversarial): `aa_004d37f0` CVOGReaction_TransferMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d37f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d37f0_CVOGReaction_TransferMap.md` |
| **Verdict** | **accept-with-gaps** —  on gate CF; **needs-more-evidence** on FUN_004025e0 |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Unconditionally transfers | **Falsified** |
| 2 | Works without local +0x7e | **Falsified** |
| 3 | Ignores in-flight +0x4f4 | **Falsified** |
| 4 | Implements full zone load | **Overstated** |
| 5 | Same as TeleportTarget | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate CF | High | Spurious transfers |
| Busy flag | High | Double transfer |
| Callee semantics | Tentative | Wrong destination |
| FUN_004025e0 reality | Tentative | No-op misread |

---

## 3. Cross-check against raw

```
if local(+0x7e) and entity and resolve(+0x210) and !busy(+0x4f4)
   and FUN_004d2ac0(...):
     busy=1; FUN_004025e0(...)
return
```

Clean preserves this control-flow spine from the authoritative decompile.

---

## 4. Surviving contract for AutoCore

```
TransferMap(ctx, entity, destArg)
  client gate for map transfer; sets busy flag; delegates work
  not a pose teleport
```

---

## 5. Open questions

1. Confirm FUN_004025e0 is a real call site.
2. Map id source (reaction params vs entity).
3. Relation to sector handoff packets.

**Verdict:** accept-with-gaps. Treat unresolved FUN_* / vtable slots as open.
