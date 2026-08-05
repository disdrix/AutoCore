# Review B (skeptical / adversarial): `aa_007efb40` VehicleDb_LoadCloneBase

| Field | Value |
|---|---|
| **Stable ID** | `aa_007efb40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007efb40_VehicleDb_LoadCloneBase.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Clean body is authoritative CF | Falsified — decomp failed stub |
| 2 | sinVehicleFlags is ghost wire handbrake | Falsified — setup-only +0x5f0 |
| 3 | Runtime applyAction reads DB here | Falsified — load-time only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stub honesty | High | False confidence in empty body |
| sinVehicleFlags bind | High | Wrong steer/HB axle map |
| Missing column map | High | Descriptor builders drift |

---

## 3. Cross-check against raw

```
LoadCloneBase: DECOMP FAILED.
Verified external: sinVehicleFlags @ bind 0x7f32d1 → VehSpec+0x5f0;
rl* columns for susp/brake/steer/aero per setup-field-mapping.
No body CF to match.
```

---

## 4. Surviving contract for AutoCore

```
VehicleDb_LoadCloneBase is load-time clonebase fill:
  AutoCore uses DB/WAD already; do not invent runtime calls here.
  Setup flags +0x5f0 bits 0–3 → brake HB + steer axle maps.
```

---

## 5. Open questions

1. Asm recover bind block or re-run decompiler with options.
2. Diff COM vs vehicle recordset column sets.

**Verdict:** accept-with-gaps
