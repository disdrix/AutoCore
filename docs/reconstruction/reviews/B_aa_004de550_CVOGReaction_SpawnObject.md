# Review B (skeptical / adversarial): `aa_004de550` CVOGReaction_SpawnObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004de550_CVOGReaction_SpawnObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Creates clonebase from scratch by CBID only | **Overstated** |
| 2 | Always returns 0 on bit12 | **Falsified** |
| 3 | Repair station uses full init chain | **Falsified** |
| 4 | Clean invents network send | **Falsified** |
| 5 | Server-only function | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Resolve + spawn CF | High | Missing world objects |
| Type 0x36 branch | High | Repair station broken |
| Flag bits | Probable | Wrong visibility/state |
| Vtable slot names | Tentative | Wrong init order assumptions |

---

## 3. Cross-check against raw

```
obj = resolve(id, inst)+0xc
if !obj: return 0
if !alive(+0x214): log/flag; maybe early 1
set flags; vcall +0x2a4(spawnParams)
if type!=0x36: init chain else repair path
return 1
```

Clean preserves this control-flow spine from the authoritative decompile.

---

## 4. Surviving contract for AutoCore

```
SpawnObject(reactionCtx, objectId, instanceId) -> 1/0
  client-side bring-up of resolved world object
  type 0x36 (repair) special-cased
  not a full server entity factory
```

---

## 5. Open questions

1. objectId/instanceId packing.
2. Relationship to RemoveObject inverse.
3. ctx+0x100 flag forcing bit4.
4. Live mission spawn reactions.

**Verdict:** accept-with-gaps. Treat unresolved FUN_* / vtable slots as open.
