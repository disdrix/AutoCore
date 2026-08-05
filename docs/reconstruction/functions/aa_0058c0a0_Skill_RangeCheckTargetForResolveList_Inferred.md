# Function record: Skill_RangeCheckTargetForResolveList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c0a0` |
| **Canonical name** | `Skill_RangeCheckTargetForResolveList_Inferred` |
| **Prior** | `FUN_0058c0a0` / `Named_CalleeOf_Skill_ResolveTargetList_0058c0a0` |
| **Address** | `0x0058c0a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **Probable** — sole caller `Skill_ResolveTargetList`; return `g_flZero` drives `*outFlags \|= 2` |
| **Status** | Human-refined + dual A/B **accept**; dual residual **return0→outFlags bit2 sealed** (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Range helper for resolve-list building, invoked **after** `Skill_FilterTargetForResolveList_Inferred`. Measures (or auto-passes) target distance against skill min/max band (`+0x2c` / `+0x28`). Returns `g_flZero` on fail so the caller can OR **outFlags bit 2** (range → eSkillResponses `0x0D` at CastSkillOnTarget).

## Signature (decompiler + call site)

```c
float10 Skill_RangeCheckTargetForResolveList_Inferred(
    int *pTarget,       // post-filter / post vehicle-remap object
    int *pSource,       // caster (ResolveTargetList param_4)
    float flRangeMin,   // skill+0x2c
    float flRangeMax,   // skill+0x28
    uint32_t skillArg34,// skill+0x34
    char skillFlag5e7); // skill+0x5e7
```

## Return contract

| Return | Meaning | Caller action |
|--------|---------|---------------|
| `g_flZero` | out of range / hard fail | `*outFlags \|= 2` @ `005504d1`; no-primary fallthrough |
| measured `dist` in `[min,max]` | in band | write primary TFID |
| `g_flOne` | auto-pass (self/parent/same vehicle/no phys) | write primary TFID |

## Dual residual seal: return0 → outFlags bit2 (2026-07-29)

| Layer | Evidence | Conf |
|-------|----------|------|
| Producer returns | Only `g_flOne` / measured / `g_flZero`; **no** outFlags formal | **Confirmed** decomp |
| Sole call site | `0x00550416` in `Skill_ResolveTargetList` only | **Confirmed** callers+xrefs |
| Compare | `FLD [g_flZero=0x00a0f518]` + `FUCOMIP` + `TEST AH,0x44` / `JNP` | **Confirmed** asm |
| OR | `005504d1: OR dword [EAX], 0x2` with `EAX = [EBP+0x28]` outFlags* | **Confirmed** asm |
| Constants | `g_flZero` → `00 00 00 00`; `g_flOne` @ `0x00a0f2a0` → `00 00 80 3f` | **Confirmed** `read_memory` |
| Chain ownership | Bit2 writer in ResolveTargetList = this zero only; bits 4/8/0x10 = Filter | **Confirmed** |

```text
this → float10 zero?
  yes → ResolveTargetList *outFlags |= 2 → LAB_005504d7 (no primary TFID)
  no  → copy TFID slots; optional Gather
```

**Does not** write bits 1 / 4 / 8 / 0x10.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0058c0a0_FUN_0058c0a0.md` (+ rename append)
- Annotated: `docs/reconstruction/raw/aa_0058c0a0_Skill_RangeCheckTargetForResolveList_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_RangeCheckTargetForResolveList_Inferred.cpp`
- Dual: `reviews/A|B_aa_0058c0a0_Skill_RangeCheckTargetForResolveList_Inferred.md`
- Scratch: `reviews/a_0058c0a0.md`

## Callers / callees

| Direction | Symbol | Addr |
|-----------|--------|------|
| Caller (sole) | `Skill_ResolveTargetList` | `0x00550300` (call @ `0x00550416`) |
| Callee | `FUN_00404a20`, `FUN_004e8a40`, `FUN_00404c90`, `FUN_004cb590`, `FUN_004e9aa0`, `FUN_004f70f0`, `FUN_00567ce0` | various |

## Confidence

| Claim | Level |
|---|---|
| Sole caller ResolveTargetList | **Confirmed** |
| Bit2 OR driven by return==0 (decomp + asm) | **Confirmed** |
| skill+0x2c min / +0x28 max band | **Confirmed** |
| Product original name | **Inferred** (`_Inferred`) |
| Full vtbl / FUN_004e9aa0 geometry | Partial |

## Gaps (non-blocking)

| Item | Blocks bit2? |
|------|:---:|
| `FUN_004e9aa0` product name / LOS vs distance | No |
| skill `+0x28/+0x2c/+0x34/+0x5e7` English | No |
| Vtbl `+0x1c8/+0x214/+0x1d4/+0x1d8/+0x210` product names | No |
| Original PDB symbol | No |
| Runtime / bit-exact / image diff | No |
