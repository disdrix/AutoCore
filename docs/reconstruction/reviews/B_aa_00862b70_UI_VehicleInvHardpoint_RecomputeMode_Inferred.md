# Review B (skeptical / adversarial): `aa_00862b70` UI_VehicleInvHardpoint_RecomputeMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862b70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00862b70_UI_VehicleInvHardpoint_RecomputeMode_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Frees/destroys widget | Only writes mode + optional vfuncs | **Falsified** |
| 2 | Always calls redraw | Only if mode changed | **Falsified** |
| 3 | Works with no local player host | Early-out if `DAT_00d1b6d8==0` | **Falsified** |
| 4 | Mode 2 means error | Mode 2 when probe returns **0** | **Falsified** |
| 5 | Is the full sheet rebuild | Rebuild is sibling `0087d810` | **Falsified** |
| 6 | Standard thiscall ECX=widget | Widget in **EAX** | **Falsified** |

---

## 2. Surviving contract

```
// EAX=hardpointWidget*, EDI=vehicleOrNull
// if !g_localPlayer: return
// mode = 0 if !vehicle
//      else if !typeGate || !ctx+0x250 || equipProbe!=0: 1
//      else 2
// if mode != old(+0x520): vtbl+0x3b4(); vtbl+0x34c()
```

**Verdict:** **accept-with-gaps**.
