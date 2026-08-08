# Function record: Skill_HB_ApplyShortAndFloater_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058cc40` |
| **Canonical name** | `Skill_HB_ApplyShortAndFloater_Inferred` |
| **Ghidra name** | `FUN_0058cc40` |
| **Address** | `0x0058cc40`–`0x0058cd54` inclusive (**277 B** / `0x115`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / Skill HB combat pools |
| **Completion status** | **Dual sealed** MEGA-008 (A+B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |
| **Naming** | `_Inferred` — role sealed by HB parent + short-field mutate + floater type 2; no product demangle on VA |

## Purpose

Apply a signed short-pool delta for skill hardpoint/heartbeat effects and show a combat floater:

- Resolve host (`vtbl+0x214`; prefer target, else source when target null).
- `amount ∈ [-1,1]` → percent of **max** short @ `+0x12e`; else absolute trunc.
- Sign: **positive amount increases** short @ `+0x12c`, **negative decreases** (set via vtbl `+0xAC`).
- Unconditionally enqueue combat floater **type 2** (`Client_EnqueueCombatFloater_INFERRED`, `this = *(target+0xA4)+0xE8A4`).
- Return applied short delta (`new - old`), or 0 if host unresolved.

## Signature (sealed)

```c
int __cdecl Skill_HB_ApplyShortAndFloater_Inferred(
    void *sourceOrNull,
    void *targetObj,
    float amount);
```

## Family / chain

```text
FUN_0061b6f0  Skill HB OnHeartBeat  [parent context]
  ├─ FUN_00589bc0  ApplyHeatDelta     [MEGA-005]
  ├─ FUN_00589c70  ApplyHpDelta       [MEGA-006]
  ├─ FUN_00589d90  ApplyShieldPool    [MEGA-007]
  ├─ FUN_0058cc40  ApplyShortAndFloater [OWN MEGA-008]
  └─ FUN_0058d8e0  ApplyMultiArgEffect  [MEGA-009]
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058cc40_FUN_0058cc40.md` |
| Annotated | `docs/reconstruction/raw/aa_0058cc40_FUN_0058cc40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyShortAndFloater_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0058cc40.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0058cc40_Skill_HB_ApplyShortAndFloater_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0058cc40_Skill_HB_ApplyShortAndFloater_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0058cc40_FUN_0058cc40.md` |
| Report | `docs/agents/task-dual-ab-0058cc40-mega-008-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / sign / floater type 2 | **Confirmed** |
| Name role (ApplyShortAndFloater) | **High** |
| Product symbol English | **Inferred** |
| Runtime Confirmed | **Open** |
