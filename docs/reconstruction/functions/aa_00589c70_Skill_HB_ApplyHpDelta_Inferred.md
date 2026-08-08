# Function record: Skill_HB_ApplyHpDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589c70` |
| **Canonical name** | `Skill_HB_ApplyHpDelta_Inferred` |
| **Ghidra name** | `FUN_00589c70` |
| **Address** | `0x00589c70`–`0x00589d80` inclusive (**273 B** / `0x111`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / Skill HB combat pools |
| **Completion status** | **Dual sealed** MEGA-006 (A+B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |
| **Naming** | `_Inferred` — role sealed by HB parent + HP apply path; no product demangle on VA |

## Purpose

Apply a signed HP delta for skill hardpoint/heartbeat effects:

- Resolve entity (`vtbl+0x19C` adjustor, fallback `+0xAC`).
- `amount ∈ [-1,1]` → percent of **max** HP; else absolute.
- Sign: **positive amount heals**, **negative damages** (pipeline uses `HP -= deltaInt` with `deltaInt = -trunc(amount)`).
- `allowKill==0` clamps applied delta to leave 1 HP (return uses unclamped projection).
- Mutate + floater via `FUN_004d7e30` (`this = entity+0xA4`).

## Signature (sealed)

```c
int __cdecl Skill_HB_ApplyHpDelta_Inferred(
    void *sourceOrNull,
    void *targetObj,
    float amount,
    char allowKill);
```

## Family / chain

```text
FUN_0061b6f0  Skill HB OnHeartBeat  [parent context]
  ├─ FUN_00589bc0  ApplyHeatDelta     [MEGA-005]
  ├─ FUN_00589c70  ApplyHpDelta       [OWN MEGA-006]
  ├─ FUN_00589d90  ApplyShieldPool    [MEGA-007]
  ├─ FUN_0058cc40  ApplyShortAndFloater [MEGA-008]
  └─ FUN_0058d8e0  ApplyMultiArgEffect  [MEGA-009]
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00589c70_FUN_00589c70.md` |
| Annotated | `docs/reconstruction/raw/aa_00589c70_FUN_00589c70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyHpDelta_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00589c70.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00589c70_Skill_HB_ApplyHpDelta_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00589c70_Skill_HB_ApplyHpDelta_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00589c70_FUN_00589c70.md` |
| Report | `docs/agents/task-dual-ab-00589c70-mega-006-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / sign / floor | **Confirmed** |
| Name role (ApplyHpDelta) | **High** |
| Product symbol English | **Inferred** |
| Runtime Confirmed | **Open** |
