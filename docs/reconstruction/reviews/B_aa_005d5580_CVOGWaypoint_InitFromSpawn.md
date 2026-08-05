# Review B (skeptical / adversarial): `aa_005d5580` CVOGWaypoint_InitFromSpawn

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d5580_CVOGWaypoint_InitFromSpawn.md` |
| **Verdict** | **accept** (CF clear) |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runs full path follow | **Falsified — field init only** |
| 2 | Always starts state 0 | **Falsified — param_6 selects 0 or 2** |
| 3 | Patrol not stored | **Falsified — +0x4c = param_5** |
| 4 | No MapPath COID | **Falsified — +0x40/+0x44 written** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Path COID + patrol layout | High | Broken leash/path attach |
| State 0 vs 2 on init | High | FSM starts wrong handler |
| Pose zero until UpdateState | High | Stale pose if never updated |
| param_7 flag bits | Tentative | Miss reverse/road bits |

---

## 3. Cross-check against raw

```
+0x51=0; path ids=-1; +0x50 = param_6?2:0; zero pose;
write path COIDs + flag + patrol; return.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
InitFromSpawn(wp, pathLo, pathHi, extra, patrolDist, startStateSel, flags):
  waypoint field seed for spawn AI
  +0x4c patrol; +0x40.. path COID; +0x50 FSM 0 or 2
  pair UpdateState + MapPath_AdvanceAndSteer + ReturnToNormalLocation
  AutoCore: Vehicle.PatrolDistance + MapPathCoid on create/ghost
```

---

## 5. Open questions

1. Name param_7 bitfields (+0x51).
2. Confirm CreateCreature arg packing from spawn +0xa0/+0x7c.
3. Document when param_6 is true (start in state 2).

**Verdict:** **accept** (CF clear)
