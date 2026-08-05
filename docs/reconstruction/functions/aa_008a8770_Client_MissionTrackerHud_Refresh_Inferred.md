# Function record: Client_MissionTrackerHud_Refresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a8770` |
| **Canonical name** | `Client_MissionTrackerHud_Refresh_Inferred` |
| **Ghidra name** | `FUN_008a8770` |
| **Address** | `0x008a8770`–`0x008a9618` |
| **Size** | 3752 bytes (`0xEA8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / mission-tracker HUD chrome |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W20-F)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Status |
|---|---|
| `FUN_008a8770` | Ghidra scaffold |
| `Mission_Look_in_your_Mission_Inventory` / `*_008a8770` | **Superseded** — one instruction-string branch only |

## Purpose

Refresh mission-tracker HUD chrome: objective title, instruction caption (inventory / journal / Go to / minimap hints), icon materials, optional range string. Host in ECX. **No** sector packet builders.

## Signature

```c
void __thiscall Client_MissionTrackerHud_Refresh_Inferred(void *host);
// ECX = host; ret 0
// Host widgets: +0x688 title, +0x694 instruction, +0x690 icon
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008a8770_FUN_008a8770.md`
- Annotated: `docs/reconstruction/raw/aa_008a8770_FUN_008a8770.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_MissionTrackerHud_Refresh_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_008a8770.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008a8770_Client_MissionTrackerHud_Refresh_Inferred.md`

## Callers / callees

- **Callers:** DATA slot `0x00a4b55c` only (no CODE xrefs).
- **Callees (sample):** `CNDHash_LookupByKey`, `Client_EvalAutoPatrolWaypoint`, `TFID_EqualsObjectId`, `FUN_0052b420`, `FUN_005710c0`, `FUN_007a6de0`, `FUN_008a8040`, `FUN_008a8660`, `FUN_0092c810`, `FUN_009700f0`, `sprintf`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompiler | **High / Confirmed** |
| ABI ECX host + body range | **Confirmed** |
| Chrome-only (no net send) | **High** |
| Product class/method English | **Inferred** |
| Widget product types | **Tentative** |
