# Review B (skeptical / adversarial): `aa_00531c80` CVOGReaction_UnlockContinentObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531c80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00531c80_CVOGReaction_UnlockContinentObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Unlocks map objects (type 32) | **Falsified** |
| 2 | Always sends UI packet | **Falsified** |
| 3 | Re-insert always | **Falsified** |
| 4 | Server-side continent gate | **Overstated** |
| 5 | Clean invents fog 0x205B decode | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hash insert CF | High | Lost continent unlocks |
| Idempotency | High | Duplicate UI spam |
| Local notify condition | Probable | Missing fog UI |
| continentId meaning | Tentative | Wrong map region |

---

## 3. Cross-check against raw

```
probe hash(char+0x534, continentId)
if found && node+8: return
alloc node; insert; maybe UI opcode 0x2a if local player
```

Clean preserves this control-flow spine from the authoritative decompile.

---

## 4. Surviving contract for AutoCore

```
UnlockContinentObject(character, continentId)
  ensure continentId present in char+0x534 unlock hash
  notify local UI once on new insert
  not the same as GroupReaction UnlockContObj (map object)
```

---

## 5. Open questions

1. Exact packet 0x2a payload.
2. RelockContinentObject inverse semantics.
3. Interaction with mission objective +0x120 unlock calls.
4. Live fog unlock capture.

**Verdict:** accept-with-gaps. Treat unresolved FUN_* / vtable slots as open.
