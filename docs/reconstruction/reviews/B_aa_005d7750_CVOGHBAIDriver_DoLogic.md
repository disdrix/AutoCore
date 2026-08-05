# Review B (skeptical / adversarial): `aa_005d7750` CVOGHBAIDriver_DoLogic

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7750` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d7750_CVOGHBAIDriver_DoLogic.md` |
| **Verdict** | **accept-with-gaps** on outer CF; **needs-more-evidence** on full combat tail |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | FireWeapons only in combat | **Falsified — always called** |
| 2 | Pursue always when target exists | **Falsified — idle uses ReturnToNormalLocation first; pursue if leash false** |
| 3 | Server owns this tick | **Overstated — client sim; server needs separate AI** |
| 4 | Finished exact FPU/profile map | **Overstated — large residual** |
| 5 | Only 2 states | **Falsified — 0/1/2** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x26c state machine | High | Stuck idle / never combat |
| FireWeapons always | High | Silent NPCs or always-shoot |
| Path this[0x2f] gate | High | No AI if path missing |
| Engage timers | Tentative | Wrong promote timing |

---

## 3. Cross-check against raw

```
if !path this[0x2f]: return;
load profile;
switch owner+0x26c:
  0 idle: cast0, slot timer, target→2 else leash ReturnToNormalLocation
  1 engage: timers, cast1, promote 2 or drop 0
  2 combat: pursue + skills
always FireWeapons(mayFire).
Clean preserves CF; large body residual.
```

---

## 4. Surviving contract for AutoCore

```
Driver_DoLogic:
  3-state machine on AiCombatState (owner+0x26c)
  idle: path/leash preferred; promote to combat if target
  combat pursue only when ReturnToNormalLocation returns false (no path handle)
  FireWeapons ALWAYS — decouple weapons from drive
Server: write AiCombatState on ghost; do not expect client DoLogic alone for authority.
```

---

## 5. Open questions

1. Seal this[] index map to struct fields.
2. Cross-check ReturnToNormalLocation bool vs pursue gate in combat branch.
3. Name FUN_00540890 profile resolver.
4. Live DR path combat capture.

**Verdict:** **accept-with-gaps** on outer CF; **needs-more-evidence** on full combat tail
