# Review B (skeptical / adversarial): `aa_005d4050` VehiclePhys_SetModeHelper_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4050` |
| **VA** | `0x005d4050` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005d4050_VehiclePhys_SetModeHelper_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always rebuilds helper | **Falsified** | early-out when vtbl+0x1c id already equals mode |
| 2 | Mode is free integer switch with many cases | **Falsified** | only cases **1** and **2** mutate; else return |
| 3 | Mode 1 heap-allocates | **Falsified** | installs static `PTR_PTR_00af4f88` |
| 4 | Mode 2 uses same singleton | **Falsified** | factory alloc + `FUN_0063f400` |
| 5 | Field is on entity+0x1a0 holder | **Falsified** | writes `this+0x54`; create/destroy pair uses phys object |
| 6 | createVehicleAction sets mode 2 | **Falsified** | plate/call is mode **1** |

---

## 2. Surviving contract

```
SetModeHelper(phys, mode):
  if phys.helper && helper.GetModeId() == mode: return
  if mode == 1: Release(helper); phys.helper = STATIC_MODE1
  elif mode == 2: newH = CtorMode2(...); swap Release/AddRef into phys.helper
  else: return
```

**Verdict:** **accept-with-gaps**
