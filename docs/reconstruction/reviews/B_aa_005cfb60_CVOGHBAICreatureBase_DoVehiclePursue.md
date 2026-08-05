# Review B (skeptical / adversarial): `aa_005cfb60` CVOGHBAICreatureBase_DoVehiclePursue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cfb60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005cfb60_CVOGHBAICreatureBase_DoVehiclePursue.md` |
| **Verdict** | **accept-with-gaps** on CF outline; **needs-more-evidence** on FPU helpers |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Foot-only (no vehicle) | **Falsified — vehicle +0x250 path** |
| 2 | Ignores air offset | **Falsified — +0xb0 branch** |
| 3 | Always direct vector | **Falsified — speed-threshold heading path** |
| 4 | Finished bit-exact FPU | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Target/vehicle slots | High | No pursue / crash |
| Ground vs air offset | High | Wrong aim height |
| Dir clamp constant | Tentative | Spin / overshoot |
| vtbl+0x4c dest apply | High | Stuck immobile |

---

## 3. Cross-check against raw

```
vehicle=owner+0x250; target=this[6]+0xa0;
if !alive: bail paths;
aim pos; offset ground/air; normalize; clamp DAT_009da864;
if speed ok: heading+matrix else direct;
apply vtbl+0x4c.
Clean preserves CF; helpers open.
```

---

## 4. Surviving contract for AutoCore

```
DoVehiclePursue(hbai):
  steer vehicle toward combat target aim point
  used by Driver combat when path leash not handling
  geometry independent of FireWeapons (which always runs)
Server NPC drive should approximate dest/heading; full FPU optional.
```

---

## 5. Open questions

1. Name heading/matrix helpers via decompile.
2. Cross-check DecideHeading interaction.
3. Live combat chase axes log.

**Verdict:** **accept-with-gaps** on CF outline; **needs-more-evidence** on FPU helpers
