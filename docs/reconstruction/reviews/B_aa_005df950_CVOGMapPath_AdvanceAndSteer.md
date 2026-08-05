# Review B (skeptical / adversarial): `aa_005df950` CVOGMapPath_AdvanceAndSteer

| Field | Value |
|---|---|
| **Stable ID** | `aa_005df950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005df950_CVOGMapPath_AdvanceAndSteer.md` |
| **Verdict** | **accept-with-gaps** on CF; steer float residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always succeeds empty path | **Falsified — return 0 + log** |
| 2 | No accept radius | **Falsified — point[3] gate** |
| 3 | Never fires reactions | **Falsified — ResolveObjectTarget inside radius** |
| 4 | Finished full steer formula | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride 0x20 + index | High | OOB crash/skip |
| Accept radius gate | High | Spin at waypoint |
| Nearest on -1 index | High | Start mid-path wrong |
| Steer vtbl+0x2c4 | Tentative | Wrong aim vector |
| Reaction COID on accept | High | Miss path events |

---

## 3. Cross-check against raw

```
if no points log/0; if index OOB 0; if -1 nearest;
get point; outside radius steer; inside resolve/advance/wrap; write outs.
Clean ≡ raw CF outline; float residual.
```

---

## 4. Surviving contract for AutoCore

```
AdvanceAndSteer(path, pos, &index, aimOut, ..., &finished, ...):
  stride 0x20 points; accept radius at +0xc of point
  inside radius may fire reaction COID and advance
  reverse flag wraps; finished out for leash complete
  AutoCore NpcVehiclePathFollower design critical
  pair Waypoint_UpdateState + ReturnToNormalLocation
```

---

## 5. Open questions

1. Publish MapPath point struct.
2. Seal steer math vs driver axes.
3. Live path follow capture.
4. Dual A/B Waypoint_* if still missing.

**Verdict:** **accept-with-gaps** on CF; steer float residual
