# Review B (skeptical / adversarial): `aa_005d6b80` CVOGHB_SlewFacingYaw_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6b80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-K) |
| **Counterpart** | `reviews/A_aa_005d6b80_CVOGHB_SlewFacingYaw_ctor_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_005d6b80.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Primary HBAI ctor / size 0xB0–0xC0 | **Falsified** — factory `new(0x28)` secondary when def`+0x4e8==1` |
| 2 | Slew thiscall uses HB as ECX | **Falsified** — bytes load ECX from `self+0x24` (raw owner) |
| 3 | Zero `+0x11c` is dword store only | **Weakened** — `xorps`/`movss` float zero (same write site as slew) |
| 4 | Period 0x1e is SetPeriodAndCounter arg | **Falsified** — SetPeriod gets **−1000**; **0x1e** written to `+0x08` and used as slew Δt |
| 5 | Many callers | **Falsified** — sole code xref `004c9648` |
| 6 | Product plate name sealed | **Overstated** — structural `_Inferred` from slew callee + factory role only |
| 7 | cdecl / no stack free | **Falsified** — `RET 4` |
| 8 | Same class as ProfileType4 HBAI | **Falsified** — different vtbl `009daee8` vs `009db08c`; different size |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 SEH ctor | **High** | ABI break |
| vtbl `009daee8` | **High** | Wrong tick method |
| pulse `+0x08=0x1e` | **High** | Wrong re-slew rate |
| slew ECX = raw owner | **High** | Face wrong object |
| secondary factory path only | **High** | Mis-wire as primary HBAI |
| Product class English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall CVOGHB_SlewFacingYaw_ctor_Inferred(self, pOwnerRaw)
  CVOGHBBase_ctor(self)
  *self = 009daee8
  *(self+8) = 0x1e
  SetPeriodAndCounter(self, -1000, true)
  *(self+0x24) = pOwnerRaw
  AttachOwnerObject(self, MI_adjust(pOwnerRaw))
  *(float*)(pOwnerRaw+0x11c) = 0
  CVOGCreature_SlewFacingYaw_Inferred(pOwnerRaw, 0x1e)  // ECX=owner
  return self
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Slew this-arg residual corrected by `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// Secondary facing-slew HB (not primary HBAI):
// - Allocate 0x28 when def+0x4e8==1 after primary attach
// - Period pulse field +0x08 = 30ms; schedule sentinel -1000
// - Attach owner; zero owner facing +0x11c; one immediate slew(Δt=30)
// - Tick sibling re-slews then RescheduleAfterFire (005d6c10; not this unit)
// - Do not substitute Regeneration or type-4 HBAI ctor
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/factory/slew site sealed; product English residual → **accept-with-gaps**.
