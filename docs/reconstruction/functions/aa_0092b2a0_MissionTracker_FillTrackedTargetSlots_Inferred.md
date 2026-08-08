# Function record: MissionTracker_FillTrackedTargetSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092b2a0` |
| **Canonical name** | `MissionTracker_FillTrackedTargetSlots_Inferred` |
| **Address** | `0x0092b2a0`–`0x0092bf5b` (**3260 B** / `0xCBC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer partition (parent dual `0x0092af80`); MissionTracker secondary fill |
| **Completion status** | **Dual A/B complete** (R12-008 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (static seal only; never Runtime Confirmed) |

## Alias

- Ghidra: `FUN_0092b2a0`
- FUN record: `aa_0092b2a0_FUN_0092b2a0.md`

## Purpose

On MissionTracker secondary path (sole caller `MissionTracker_RefreshTrackedTargets_Inferred` after primary `0x0092af80` miss):

1. Seed 4 nearest-slots with **FLT_MAX** distances.
2. If CBID lists `host+0x54` / `host+0x80` non-empty: scan world mission tree, level-band + CBID match, distSq rank into top-4 (via temp map + level-delta promotion).
3. Else if race list `host+0xAC` non-empty: scan CS-list key **0x36**, race/type gates, insert when distSq ≥ **10000**.
4. Emit up to 4 `0x20` nodes (TFID_16 @ `obj+0x164` + pos @ `+0x84/88/8c`) onto vector begin `host+0x11C`.
5. On any emit: `host+0x08 = 1`, return **AL=1**; else **AL=0**.

## Signature

```c
// stdcall stack (host, origin); RET 8; AL = bool
// Not ECX-thiscall.
uint8_t MissionTracker_FillTrackedTargetSlots_Inferred(void* host, float* origin);
```

## Host offsets (sealed)

| Off | Role |
|---|---|
| `+0x00` | `Client*` |
| `+0x06` | byte → optional `FUN_0092b1c0` |
| `+0x08` | success/dirty byte set **1** on fill |
| `+0x54` / `+0x58…` | CBID list A count / entries |
| `+0x80` / `+0x84…` | CBID list B count / entries |
| `+0xAC` / `+0xB0…` / `+0xD8…` | race count / race ids / type filters |
| `+0x108` / `+0x10C` | level min / max (−1 = open) |
| `+0x11C` / `+0x120` / `+0x124` | vector begin / end / capacity (base addr `+0x118`) |

## Artifacts

- Raw (+ R12-008): `docs/reconstruction/raw/aa_0092b2a0_FUN_0092b2a0.md`
- Annotated: `docs/reconstruction/raw/aa_0092b2a0_FUN_0092b2a0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/MissionTracker_FillTrackedTargetSlots_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0092b2a0.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_0092b2a0_MissionTracker_FillTrackedTargetSlots_Inferred.md`, `B_aa_0092b2a0_…`
- Report: `docs/agents/task-dual-ab-0092b2a0-r12-report.md`

## Callers / callees

| Direction | Addr | Name |
|---|---|---|
| Caller (1) | `0x0092bf60` @ `0x0092c058` | `MissionTracker_RefreshTrackedTargets_Inferred` |
| Callee | residuals | `0092b1c0`, `00929c60`, map/list helpers, `00419880` |
| Callee | dualed | `Object_GetRootRaceId`, `CVOGCharacter_WeaponAllowsKillXpBonus` |

## Confidence

| Claim | Level |
|---|---|
| Body + ABI + sole caller | **High / Sealed** |
| Top-4 emit + TFID `+0x164` + flag `+0x08` | **High / Sealed** |
| Product class English | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
