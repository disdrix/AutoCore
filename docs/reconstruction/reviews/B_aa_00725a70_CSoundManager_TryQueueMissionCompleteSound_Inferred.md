# Review B (skeptical / adversarial): `aa_00725a70` CSoundManager_TryQueueMissionCompleteSound_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00725a70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00725a70_CSoundManager_TryQueueMissionCompleteSound_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as TryQueueProximity (`007258a0`) | | **Falsified** — no 0xC/0xD busy gate; fixed radius; hardcoded fields |
| 2 | Uses descriptor radius `+0x114` | | **Falsified** — compares against `DAT_00aaa880=10000` |
| 3 | Full 3D radius (includes Y) | | **Falsified** — radius uses X/Z only; Y only in zero-length test |
| 4 | `+0x110` is int threat default | | **Falsified** — `movss` from `DAT_00aaa6e8` = **20.0f** |
| 5 | Type is char `'2'` only | | **Partial** — store is **dword 0x32**; high bytes zero |
| 6 | Always queues | | **Falsified** — enable + distance + resolve gates return 0 |
| 7 | Multiple callers | | **Falsified** — single xref `FUN_004b0f80` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fixed 10000 dist² | **High** | Wrong hear distance for mission SFX |
| Hardcoded type 0x32 | **High** | Wrong mixer / channel routing |
| Mission-complete naming | **Medium-High** | Name only; CF still sealed |
| Null freelist path | **Medium** | Crash if pop fails |

---

## 3. Surviving contract for AutoCore

```
bool TryQueueMissionCompleteSound(manager, pathKey, worldPos):
  require manager.enabled (+0x258)
  require (||pos||==0 OR xzDist2(listener, pos) <= 10000)
  path = ResolveSoundPath(pathKey)
  require path
  slot = PopAndInit()
  slot.path = path
  slot.type = 0x32; slot.tfid = -1
  slot.p110 = 20; slot.radius = 100; slot.p11c = 1
  Enqueue(manager+0x310, slot)
  return true
```

**Port tests:**

* Disabled manager → false.
* Non-zero pos outside r=100 XZ → false.
* Zero pos with valid path → true (independent of listener).

---

## 4. Open questions

1. Why ABS on already-squared sum (compiler artifact; port as `dist2 > 10000`).
2. Whether `param_2` is always a C-string path or a thin descriptor beginning with path.

**Verdict:** **accept-with-gaps**
