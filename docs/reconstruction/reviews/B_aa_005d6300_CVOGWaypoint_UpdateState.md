# Review B (skeptical / adversarial): `aa_005d6300` CVOGWaypoint_UpdateState

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6300` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d6300_CVOGWaypoint_UpdateState.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on handler semantics |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Contains full path steer math | **Falsified — dispatch shell only** |
| 2 | No state byte | **Falsified — +0x50 switch** |
| 3 | States 0–3 all named | **Overstated — FUN_* residual** |
| 4 | Always runs all four handlers | **Falsified — single case** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x50 four-way dispatch | High | Wrong AI mode |
| Handler call order/identity | High | Broken path/leash |
| Handler body contracts | Tentative | Pose/advance wrong |
| Default invalid state silence | Tentative | Stuck waypoint |

---

## 3. Cross-check against raw

```
scope; switch(+0x50) call one of four FUN_005d*; unscope; return.
Clean ≡ raw CF; handler bodies not inlined.
```

---

## 4. Surviving contract for AutoCore

```
UpdateState(wp):
  FSM dispatch on +0x50 → four handlers
  pair InitFromSpawn (seeds 0 or 2) + ReturnToNormalLocation + AdvanceAndSteer
  AutoCore path follower must mirror state semantics once handlers named
  shell alone insufficient for bit-exact path pose
```

---

## 5. Open questions

1. Dual-review / rename FUN_005d5750, 005d5960, 005d5cc0, 005d5680.
2. Trace state transitions and pose writes.
3. Live capture +0x50 during patrol vs return-home.
4. Link +0x52 flag usage.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on handler semantics
