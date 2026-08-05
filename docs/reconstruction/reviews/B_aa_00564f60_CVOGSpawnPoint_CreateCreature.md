# Review B (skeptical / adversarial): `aa_00564f60` CVOGSpawnPoint_CreateCreature

| Field | Value |
|---|---|
| **Stable ID** | `aa_00564f60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00564f60_CVOGSpawnPoint_CreateCreature.md` |
| **Verdict** | **accept-with-gaps** on CF; height details **cross-check docs** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Spawns vehicles of any type | **Falsified — type 0x12 required** |
| 2 | Always new instance | **Falsified — cache at +0x1c0** |
| 3 | Ignores terrain height for NPCs | **Falsified — special height path** |
| 4 | Finished height port without docs | **Overstated — use NPC_SPAWN_HEIGHT.md** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type 0x12 gate | High | Wrong spawn class |
| Cache reuse vs regen | High | Stale CBID |
| Height offsets | High | Buried/floating NPC |

---

## 3. Cross-check against raw

```
template=lookup(cbid); if !type0x12 fail;
create or reuse cached; unique id; waypoint init; place with height rules; AI hooks
Clean CF matches plate AutoCore notes.
```

---

## 4. Surviving contract for AutoCore

```
On static NPC spawn:
  template type 0x12 only
  reuse spawn+0x1c0 when CBID matches else regenerate
  apply documented height: ray Y+3 + flying (if bit4 clear) + foot +0x120 when Speed|flag|IsNPC
See Documentation/NPC_SPAWN_HEIGHT.md / SpawnPoint.ApplyStaticNpcSpawnHeight.
```

---

## 5. Open questions

1. Remainder of function after waypoint init full seal.
2. Runtime spawn height differential.

**Verdict:** **accept-with-gaps** on CF; height details **cross-check docs**
