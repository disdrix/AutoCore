# Function record: Character_ComputeTinkerSuccessChance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521f20` |
| **Canonical name** | `Character_ComputeTinkerSuccessChance_Inferred` (**Inferred** — product field English open) |
| **Ghidra name** | `FUN_00521f20` |
| **Prior scaffold** | `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00521f20` (**retired**) |
| **Address** | `0x00521f20`–`0x00521fe7` inclusive (**200 B** / `0xC8`) |
| **Jump table** | data `0x00521fe8`–`0x00521ffb` (5× dword) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / tinker kit |
| **Parent dual / context** | partition parent `0x00521eb0` (`Item_GetTinkerSkillOrCap_Inferred`); UI caller `0x0085f660`; validate `0x00513c10` |
| **Agent** | R10-035 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

**Character-side tinker success-chance** worker:

```text
if character[+0x6b4] >= 1: return 1.0
need = item->vtbl[+0x8c]() + 1          // next slot index
if FUN_00521eb0(character) < need: return 0.0
base = {1→0.4, 2→0.35, 3→0.3, 4→0.25, 5→0.2}[need] else 0
term = (int16)(character[+0x59b] - 2*need + kit[+0xb0])
return term * 0.04 + base
```

Sole external caller formats percent after `× 100.0`.

## Signature

```c
// __thiscall: ECX = character; stack item*, kit*; float ST0; RET 8
float __thiscall Character_ComputeTinkerSuccessChance_Inferred(
    void *character, void *item, void *kit);
```

## Layout (fields touched)

| Object | Offset | Width | Role in this VA |
|---|---|---|---|
| character | **+0x6b4** | i32 | **read** — ≥1 bypass → 1.0 |
| character | **+0x59b** | u8 | **read** — linear term; also tier source via callee |
| item | vtbl **+0x8c** | vfunc | open slot count → need |
| kit | **+0xb0** | i16 | kit level in linear term |

## Call graph

| Role | Target |
|---|---|
| **Callers (1 site)** | `FUN_0085f660` @ `0x0085f6c1` (`MOV ECX,[DAT_00d1b6d8]` character; `PUSH kit; PUSH item`) |
| Callees | item `vtbl+0x8c`; `FUN_00521eb0` @ `0x00521f59` (`MOV ECX,EDI` character this) |
| Xrefs | 1 UNCONDITIONAL_CALL |

## Chain context (not dualled; evidence only)

```text
FUN_0085f660  tinker apply UI
  ├─ FUN_00513c10  Item_ValidateTinkerKitUse  → status
  └─ if status==4:
        FUN_00521f20  Character_ComputeTinkerSuccessChance_Inferred  [OWN R10-035]
          ├─ item vfunc +0x8c → slots / need
          └─ FUN_00521eb0  [parent dual 0x00521eb0]  // ECX=character this
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Character_ComputeTinkerSuccessChance_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00521f20.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00521f20.cpp`
- Raw: `docs/reconstruction/raw/aa_00521f20_FUN_00521f20.md`
- Annotated: `docs/reconstruction/raw/aa_00521f20_FUN_00521f20.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00521f20_Character_ComputeTinkerSuccessChance_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00521f20_Character_ComputeTinkerSuccessChance_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00521f20_FUN_00521f20.md`
- Report: `docs/agents/task-dual-ab-00521f20-r10-report.md`

## Confidence

| Claim | Level |
|---|---|
| Switch / table CF + float constants | **Confirmed** |
| ECX=character; item+kit stack; RET 8; ST0 | **Confirmed** |
| need = item slots+1; tier gate; formula | **Confirmed** |
| UI percent role via caller string | **High** |
| Product English for fields | **Inferred** |
| Runtime Confirmed | **Open** |
