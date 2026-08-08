# Function record: Skill_HB_ApplyHeatDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589bc0` |
| **Canonical name** | `Skill_HB_ApplyHeatDelta_Inferred` |
| **Ghidra name** | `FUN_00589bc0` |
| **Address** | `0x00589bc0`–`0x00589c69` inclusive (**170 B** / `0xAA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / Skill HB combat pools |
| **Completion status** | **Dual sealed** MEGA-005 (A+B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |
| **Naming** | `_Inferred` — role sealed by HB parent heat float@+0x114 + `Vehicle_AddHeat`; no product demangle on VA |

## Purpose

Apply a signed heat delta for skill hardpoint/heartbeat effects:

- RTTI-resolve target → vehicle (or creature→vehicle@+0x250).
- `amount ∈ [-1,1]` → percent of **max** heat (`+0x244`); else absolute.
- Sign: **positive amount heats**, **negative cools**.
- Gate: net/ghost at MI+0xA8 with byte `+0x7E` set.
- Mutate via `Vehicle_AddHeat` (thiscall); return actual `+0x150` delta.
- `source` arg ABI-present, unread.

## Signature (sealed)

```c
int __cdecl Skill_HB_ApplyHeatDelta_Inferred(
    void *sourceUnused,
    void *targetObj,
    float amount);
```

## Family / chain

```text
FUN_0061b6f0  Skill HB OnHeartBeat  [parent context]
  ├─ FUN_00589bc0  ApplyHeatDelta     [OWN MEGA-005]
  ├─ FUN_00589c70  ApplyHpDelta       [MEGA-006]
  ├─ FUN_00589d90  ApplyShieldPool    [MEGA-007]
  ├─ FUN_0058cc40  ApplyShortAndFloater [MEGA-008]
  └─ FUN_0058d8e0  ApplyMultiArgEffect  [MEGA-009]
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00589bc0_FUN_00589bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00589bc0_FUN_00589bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyHeatDelta_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00589bc0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00589bc0_Skill_HB_ApplyHeatDelta_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00589bc0_FUN_00589bc0.md` |
| Report | `docs/agents/task-dual-ab-00589bc0-mega-005-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / sign / percent / gate | **Confirmed** (assembly) |
| Name role (ApplyHeatDelta) | **High** |
| Product symbol English | **Inferred** |
| Runtime Confirmed | **Open** |
