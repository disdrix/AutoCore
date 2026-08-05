# Review B (skeptical / adversarial): `aa_007258a0` CSoundManager_TryQueueProximitySound_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007258a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007258a0_CSoundManager_TryQueueProximitySound_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always plays regardless of distance | | **Falsified** — outside radius (and non-zero pos) returns 0 |
| 2 | 3D full distance (incl Y) for radius | | **Falsified** — radius uses **X and Z only** (`+0x220`, `+0x228` vs `pos[0]`, `pos[2]`) |
| 3 | Zero vector fails | | **Falsified** — `len<=g_flZero` **passes** into resolve/queue |
| 4 | Disabled manager still queues | | **Falsified** — `this+600==0` → 0 |
| 5 | Types 0xC/0xD always blocked | | **Falsified** — only when `FUN_00722b80` returns non-zero |
| 6 | Same as `00723120` alloc path | | **Falsified** — this clones resolved path into list at `+0x310`; that path is `new(0x150)` |
| 7 | Returns sound pointer | | **Falsified** — bool 0/1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Enable `+0x258` | **High** | Silent no-audio |
| XZ radius `desc+0x114` | **High** | Wrong hear distance |
| Zero-pos always-in | **High** | Missing forced play |
| Clone field map | **High** (offsets) | Corrupt slot |
| Types 0xC/0xD meaning | **Medium** | Wrong exclusivity |

---

## 3. Cross-check against raw

```text
if (this+600 == 0) return 0
if type in {12,13} and FUN_00722b80(...): return 0
if len(pos)<=0 OR xzDist2 <= r*r:
  src = FUN_007249c0(desc, DAT_00d1a614)
  if !src: return 0
  dest = alloc; strncpy; copy fields; FUN_00480350(this+0x310); return 1
return 0
```

---

## 4. Surviving contract for AutoCore

```
bool TryQueueProximitySound(manager, fxDesc, worldPos):
  require manager.enabled
  require not busy if type is 0xC/0xD
  require (pos is zero OR listener XZ within fxDesc.radius)
  resolve file; clone slot; enqueue at manager+0x310
  return success
```

**Port tests:**

* Outside radius with non-zero pos → false, no enqueue.
* Manager disabled → false.

---

## 5. Open questions

1. `FUN_00722b80` dual (channel exclusivity?).
2. Whether `+0x220/+0x228` are camera or player.

**Verdict:** **accept-with-gaps**
