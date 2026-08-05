# Function record: `SkillDefMap_GetGlobal`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054b480` |
| **Canonical name** | `SkillDefMap_GetGlobal` (structural) |
| **Ghidra name** | `FUN_0054b480` |
| **Address** | `0x0054b480` |
| **Body** | `0054b480`–`0054b493` (20 B through `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W18-C)** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Prior scaffold: `FUN_0054b480`
- Prior auto-alias: `Named_CalleeOf_Client_RecvSkillStatusEffect_0054b480`
- Related: `SkillDefMap_ExactFindByIntKey` (`aa_00418890`) consumes returned header
- **Not** `Skill_GetCategoryCooldownMap` (entity `+0x6c`)

## Purpose

Lazy-get global skill-definition map header at `DAT_00b04734`. If once-flag `DAT_00b04724` is zero, call `FUN_0054b2c0`, then return `&DAT_00b04734`.

## Signature

```c
SkillDefMapHeader * SkillDefMap_GetGlobal(void);
// leaf: pure ret; EAX = &DAT_00b04734
```

## Globals

| Symbol | Role |
|--------|------|
| `DAT_00b04724` | once-init byte |
| `DAT_00b04734` | map header (returned address) |
| `FUN_0054b2c0` | init loader |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0054b480_FUN_0054b480.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0054b480_FUN_0054b480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillDefMap_GetGlobal.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0054b480.cpp` |
| Prior named scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_RecvSkillStatusEffect_0054b480.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0054b480_SkillDefMap_GetGlobal.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0054b480_SkillDefMap_GetGlobal.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0054b480_FUN_0054b480.md` (superseded) |

## Callers / callees

**Callees:** `FUN_0054b2c0` (conditional)

**Callers (direct):**

| Symbol | VA |
|--------|-----|
| `Client_RecvSkillStatusEffect` | `0x00811170` |
| `FUN_005408f0` | `0x005408f0` |
| `FUN_00541aa0` | `0x00541aa0` |
| `FUN_00542790` | `0x00542790` |
| (site) | `0x0052a2ca` |

## Confidence

| Claim | Level |
|---|---|
| Lazy once-flag + return `&DAT_00b04734` | **Confirmed** |
| Leaf pure `ret` / 20 B body | **Confirmed** |
| Map is SkillDef global (not category CD) | **Confirmed** (vs GetCategoryCooldownMap + ExactFind consumers) |
| Product English / STL type name | **Open** |
