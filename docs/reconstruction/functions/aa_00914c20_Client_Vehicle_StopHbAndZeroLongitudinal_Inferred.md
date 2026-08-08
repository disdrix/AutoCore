# Function record: Client_Vehicle_StopHbAndZeroLongitudinal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00914c20` |
| **Canonical name** | `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` |
| **Ghidra name** | `FUN_00914c20` |
| **Address** | `0x00914c20` |
| **Body** | `0x00914c20`–`0x00914c59` inclusive (**58 B** / `0x3A`); pad `CC` after |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` |
| **Completion status** | **Dual A/B sealed 2026-08-05 (MEGA-098)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred; Terminal **false**) |

## Alias

- Prior scaffold: `FUN_00914c20`
- No `Named_CalleeOf_*` scaffold present for this VA

## Purpose

Shared leaf for **stop heartbeat + zero longitudinal** under mode flag `DAT_00d1a860`:

1. Require `DAT_00d1a860 != 0` and non-null `*(client+0xc70)` (HB object).
2. Clear client latch `*(u8*)(client+0xa35) = 0`.
3. `CVOGHBBase_Stop` on that HB (thiscall ECX).
4. If game host `DAT_00d1b6d8` has vehicle at `+0x250`, `VehicleEntity_SetLongitudinalInput(vehicle, 0)`.

Does **not** engage handbrake, push axes, or write steer.

## Signature

```c
// Register-carried host in EAX. No stack args. Bare RET.
void Client_Vehicle_StopHbAndZeroLongitudinal_Inferred(void* host /* EAX */);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ MEGA-098 re-verify) | `docs/reconstruction/raw/aa_00914c20_FUN_00914c20.md` |
| Annotated | `docs/reconstruction/raw/aa_00914c20_FUN_00914c20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00914c20.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00914c20_Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00914c20_Client_Vehicle_StopHbAndZeroLongitudinal_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00914c20_FUN_00914c20.md` |
| Report | `docs/agents/task-dual-ab-00914c20-mega-098-report.md` |

## Callers / callees

**Callers (2):**

| Caller | Site | ABI setup |
|--------|------|-----------|
| `FUN_00914c60` | `0x00914ca5` | `MOV EAX,EDI` |
| `Client_InteractWorldClickHub` | `0x00925984` | `MOV EAX,EDI` (`8B C7`) |

**Callees:**

| Callee | VA | Role |
|--------|-----|------|
| `CVOGHBBase_Stop` | `0x005081d0` | dormant + OnEnd |
| `VehicleEntity_SetLongitudinalInput` | `0x004f5650` | thr axis = 0 |

## Related (not owned)

| Unit | VA | Note |
|------|-----|------|
| `Client_Vehicle_EngageHbAndPushAxes_Inferred` | `0x00915670` | opposite `DAT_00d1a860` polarity for Stop; HB=1+Push |
| `Client_InteractWorldClickHub` | `0x00925820` | caller + early **inline** of equivalent CF |
| `FUN_00914c60` | `0x00914c60` | residual sibling caller |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET / call graph | **High** (live dual) |
| Product English name | **Probable** structural → `_Inferred` |
| Runtime Confirmed | **Open** |
