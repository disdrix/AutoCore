# Review B (skeptical / adversarial): `aa_005d6c10` CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6c10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-T) |
| **Counterpart** | `reviews/A_aa_005d6c10_CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_005d6c10.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Slew thiscall uses HB as ECX | **Falsified** — bytes `MOV ECX,[ESI+0x24]` raw owner |
| 2 | Gate uses raw owner +0x24 | **Falsified** — gate is `pOwnerObject +0x18`; slew uses +0x24 |
| 3 | Period arg is −1000 sentinel | **Falsified** — push `[ESI+0x08]` (pulse 0x1e from ctor); sentinel is +0x0C path in Reschedule |
| 4 | True `__fastcall` with EDX out | **Falsified** — stack `pOutStatus`; EDX is decompiler phantom |
| 5 | Direct code callers | **Falsified** — virtual only via vtbl `009daef4` |
| 6 | Primary HBAI DoLogic | **Falsified** — secondary size-0x28 slew HB; different vtbl from ProfileType4 |
| 7 | void return | **Falsified** — returns `pOutStatus` in EAX (HB OnHeartBeat family) |
| 8 | Product plate sealed | **Overstated** — structural `_Inferred` from ctor sibling + slew callee |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 OnHeartBeat | **High** | ABI break |
| Slew ECX = raw +0x24 | **High** | Face wrong object |
| Gate +0x18 / period +0x08 | **High** | Miss ticks / wrong Δt |
| Vtbl 009daee8+0x0C | **High** | Wrong method install |
| Product class English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred(self, pOutStatus)
  if (*(self+0x18) != 0)
    CVOGCreature_SlewFacingYaw_Inferred(*(self+0x24), *(self+0x08))
  CVOGHBBase_RescheduleAfterFire(self, pOutStatus)
  return pOutStatus
```

Live decompile 2026-07-29 ≡ raw CF. Slew this-arg + convention residuals corrected by `read_memory`. Closes W28-K gap item “tick sibling not OWN”.

---

## 4. Surviving contract for AutoCore

```
// Secondary facing-slew HB tick (not primary HBAI DoLogic):
// - Install as vtbl+0x0C of class 009daee8 (size 0x28 HB)
// - If pOwnerObject set: slew(rawOwner@+0x24, periodMs@+0x08)
// - Always RescheduleAfterFire(self, pOutStatus); return pOutStatus
// - Do not pass HB as slew this; do not use sentinel -1000 as Δt
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/vtbl/slew site sealed; product English residual → **accept-with-gaps**.
