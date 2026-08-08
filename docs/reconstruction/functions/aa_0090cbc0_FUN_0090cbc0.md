# Function record: FUN_0090cbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090cbc0` |
| **Canonical name** | `FUN_0090cbc0` |
| **Named alias** | `MedalUI_RefreshPagedAchievementSlots_Inferred` |
| **Address** | `0x0090cbc0`–`0x0090cdfe` (**575 B** / `0x23F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Partition** | MEGA-063 — Post-force-complete medal UI refresh |
| **Completion status** | **Dual sealed** (A/B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Alias

| Name | Status |
|---|---|
| `MedalUI_RefreshPagedAchievementSlots_Inferred` | **canonical proposed** |
| `Named_VOG_DEBUG_STOP_0090cbc0` | **retired** (string misname) |

## Purpose

Rebuild the paged medal/achievement button grid on the MedalUI host after mission force-complete and other UI refresh paths: prep-clear 24 slots, count medals, page/scrollbar math, fill slots from vector then hash via apply helper.

## Signature (sealed)

```c
// Retail ABI: EAX = MedalUI host*; void; bare RET
void FUN_0090cbc0(void);
```

## Artifacts

- Raw (+ MEGA-063 re-verify): `docs/reconstruction/raw/aa_0090cbc0_FUN_0090cbc0.md`
- Annotated: `docs/reconstruction/raw/aa_0090cbc0_FUN_0090cbc0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/MedalUI_RefreshPagedAchievementSlots_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0090cbc0.cpp`
- Named record: `docs/reconstruction/functions/aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md`
- Report: `docs/agents/task-dual-ab-0090cbc0-mega-063-report.md`

## Callers / callees

| Direction | Value |
|---|---|
| Callers (6 xrefs) | `Client_RecvCompleteDynamicObjective`, `FUN_0080ce50` (JMP), `FUN_0090d0d0`, `FUN_00946c00`, `0090ce73`, `00952bb1` |
| Callees | `FUN_0090c700`, `FUN_0090c810`, `FUN_0051a0e0`, `FUN_0090c9a0`, `FUN_007a4480` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ disasm | **High** |
| EAX-host ABI / bare RET | **High** |
| Medal UI refresh role | **High** |
| Product class English | **Low** / Tentative |
