# Function record: Client_Skill_ResolveCastTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093b3a0` |
| **Canonical name** | `Client_Skill_ResolveCastTarget` |
| **Address** | `0x0093b3a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual closed (2026-07-29)** — hardpoint plate strengthened; runtime/diff still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Player-side cast-target resolver. Runs `Skill_ResolveTargetList`, dispatches on `outFlags`, falls back to related-entity TFID or `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` (local vehicle/entity at `char+0x250`), optional sticky active-bind silent gate, failure toasts when `bReportFailure`.

## Signature (decompiler-derived)

```c
// client object in EAX (in_EAX); stdcall 5 formals (RET 0x14)
void Client_Skill_ResolveCastTarget(
    byte *pOutTfid,
    int pSkill,
    undefined4 *pSeedTfid,
    undefined4 pAimOrContext,
    char bReportFailure);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0093b3a0_Client_Skill_ResolveCastTarget.md`
- Annotated: `docs/reconstruction/raw/aa_0093b3a0_Client_Skill_ResolveCastTarget.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_Skill_ResolveCastTarget.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0093b3a0_Client_Skill_ResolveCastTarget.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0093b3a0_Client_Skill_ResolveCastTarget.md`
- Scratch: `docs/reconstruction/reviews/a_0093b3a0.md` (twin `tmp/a_0093b3a0.md`)

## Callers / callees

| Direction | Symbol | VA | Notes |
|---|---|---|---|
| Caller | `Client_RequestCastSkill` | `0x00941590` | primary cast path |
| Caller | `Client_QuickBarActivateSkillSlot` | `0x00921b50` | quick-bar |
| Caller | `FUN_00829190`, `FUN_00941d50` | — | secondary; open |
| Callee | `Skill_ResolveTargetList` | `0x00550300` | list + outFlags |
| Callee | `Skill_FilterTargetForResolveList_Inferred` | `0x0054ff00` | via list; ORs bits 4/8/0x10 |
| Callee | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` | `0x004f8b80` | was `FUN_004f8b80`; **sole caller = this** |
| Callee | `Skill_LookupActiveCastBinding` | `0x00518cf0` | sticky gate |
| Callee | `TFID_EqualsObjectId` | `0x00404aa0` | hardpoint / list validity |
| Callee | `TFID_NotEquals` | — | sticky present? |
| Callee | `Skill_FormatFailureMessage` | `0x0054fa20` | eSkillResponses strings |

## Dual residual close (2026-07-29)

| Residual | Resolution | Confidence |
|---|---|---|
| `FUN_004f8b80` identity | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` | **Confirmed** (rename + sole-caller dual) |
| Hardpoint ECX this | `*(localChar + 0x250)` @ `0x0093b570`/`0x0093b576` | **Confirmed** |
| Hardpoint reload plate | EDI/EBP/EBX/`[ESP+0x24]` from `*EAX` @ `0x0093b581`+ | **Confirmed** |
| Empty helper vs invalid TFID | `DAT_009cd0f8` **content ≡** `g_abTfidInvalid_A15870` (16B) | **Confirmed** (`read_memory`) |
| Related before hardpoint | bit4: skill`&2` then skill`&8` | **Confirmed** |
| outFlags bit4/8 writers | `Skill_FilterTargetForResolveList_Inferred` | **Confirmed** |
| `pA` / `unaffReg` on active-bind | `activeBindScratch` (`local_750`) | **Confirmed** (asm + sibling) |
| Sticky writes binding TFID? | **No** — silent invalid via listOut regs | **Confirmed** (asm) |
| Runtime / diff | still open | — |

## Hardpoint path (sealed consumer contract)

```
outFlags&4 && !(skill+0x614&2) && (skill+0x614&8):
  ECX = *(*(client+0xe98) + 0x250)
  pTfid = Vehicle_ResolveFirstHardpointOccupantTfid_Inferred()   // __fastcall ECX
  reload write_seed regs from *pTfid
  if TFID_EqualsObjectId(reloaded, g_abTfidInvalid) == 0:
      write_seed
  else if bReportFailure && !on-foot:
      toast "No enemies found." (channel 0x18)
  write_invalid
```

Helper body (owned by `aa_004f8b80`): walk `*(vehicle+0x260)[0..2]`; first live object TFID `@+0x160`; else `&DAT_009cd0f8`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + asm plate | **High / Confirmed** |
| Parameter semantic names | High (callers) |
| outFlags consume map | **High** (writers sealed) |
| Active-bind first arg | **Confirmed** |
| Hardpoint this + reload + sentinel content | **Confirmed** |
| Hardpoint product table word | **Probable / `_Inferred`** (callee dual) |
| Types | Tentative |
