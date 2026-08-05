# Annotated low-level: Skill_ResolveTargetList (`aa_00550300`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00550300` |
| **VA** | `0x00550300` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_00550300_Skill_ResolveTargetList.md` (capture 2026-07-23) |
| **Related** | `Skill_GatherTargetsInArea` (`0x0058d330`), `CVOGReaction_CastSkillOnTarget` (`0x004d09a0`), `CVOGReaction_ResolveObjectTarget` |

This file is the **annotated** layer: widths, branch order, flag meanings, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Signature (working hypothesis)

```c
// MSVC thiscall: ECX = skill runtime
// Returns: number of TFIDs written into out list (0..100); may also set *outFlags.
int __thiscall Skill_ResolveTargetList(
    SkillRuntime* this,          // ECX — skill (flags +0x614 / +0x624, range fields, max targets +0xde)
    TFID_16*      outList,       // stack — 100-slot TFID array (filled with invalid first)
    void*         gatherCtx,     // stack — forwarded to Skill_GatherTargetsInArea (param_3)
    void*         pSourceObj,    // stack — caster/source object (vtbl +0x1a0 pos; range checks)
    uint          tfidLo,        // stack — primary target TFID dword 0
    uint          tfidHi,        // stack — primary target TFID dword 1
    /*char*/int   tfidGlobal,    // stack — low byte used as global/pad of TFID
    void*         unusedOrTail,  // stack — param_8 (unused in body surface)
    int*          pFallbackPos,  // stack — 16B position/TFID source when self/no-primary path
    uint*         outFlags);     // stack — bit1 = no target, bit2 = out of range (INFERRED)
```

| Formal (raw) | Width | Role (from body) | Confidence |
|---|---|---|---|
| `param_1` / `this` | ptr | Skill runtime | **High** (`+0x614`, `+0x624`, `+0xde`, range floats) |
| `param_2` | ptr | Out TFID list (100 × 16B) | **High** |
| `param_3` | 32 | Opaque forward to `Skill_GatherTargetsInArea` | **Tentative** |
| `param_4` | ptr | Source/caster object | **High** (vtbl + range helper) |
| `param_5`/`param_6`/`param_7` | TFID parts | Primary object target key | **High** |
| `param_8` | 32 | Unused in visible body | **Open** |
| `param_9` | ptr | Fallback position vector source (4 dwords) | **Probable** |
| `param_10` | ptr | Out flags OR'd | **High** |

**Callers (Ghidra xrefs, 2026-07-23):**

| Caller | VA | Role |
|---|---|---|
| `Client_Skill_ResolveCastTarget` | `0x0093b3a0` | Player cast TFID pick; maps outFlags → toasts / codes 0xd/0xe |
| `CVOGReaction_CastSkillOnTarget` | `0x004d09a0` | Reaction packer when no prebuilt list |
| `NPC_TryCastSkillFromSet` | `0x005d1280` | AI cast |

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `DAT_009d1ca8..cb4` fill loop | Invalid TFID sentinel (same pattern as other TFID invalids; exact equate to `g_abTfidInvalid_*` open) | **High** for role |
| `outFlags \|= 1` | “No usable primary target” when skill wants a target | **Probable** (plate INFERRED) |
| `outFlags \|= 2` | Range/LOS helper returned zero | **Probable** (plate INFERRED) |
| `(param_5 & param_6) == 0xffffffff && (char)param_7 == 0` | TFID is the invalid sentinel → `bHasPrimary=false` | **High** |
| `FUN_0054ff00` | Post-resolve filter/validate of primary object (null → no primary) | **Tentative** name |
| `FUN_0058c0a0` | Range/accuracy score (float10); `== g_flZero` → flag bit 2 | **Probable** |
| Object types `0x12` / `0x14` | Creature/character-like → optional vehicle remap via vtbl `+0x1d8` | **Probable** |
| `skill+0x624` bits | Targeting mode: bit0 multi/area top-up; bits `0x20` / `0x4000` force full area gather | **Probable** |
| `0xbf800000` | `-1.0f` radius/mode sentinel into Gather | **High** (IEEE float) |
| Return `local_32` | Final target count (char promoted to int) | **High** |

---

## 3. Control flow (ordered)

```text
1. Fill outList[0..99] with invalid TFID (DAT_009d1ca8..)
2. bHasPrimary = !(TFID is all-invalid)
3. obj = ResolveObjectTarget(tfid...) then FUN_0054ff00(obj, source, outFlags)
4. if obj == null:
     if skill+0x614 bit0 == 0:
       if bHasPrimary && !(skill+0x614 bit 0x20): outFlags|=1; return 0
     else:
       pFallbackPos = source.vtbl+0x1a0()   // self position provider
     copy 4 dwords from pFallbackPos → center (iStack_20..)
5. else (primary object present):
     maybe remap creature/driver (types 0x12/0x14) to vehicle body
     range = FUN_0058c0a0(obj, source, skill range fields...)
     if range == 0: outFlags|=2; goto step-4 null path
     write primary TFID (obj+0x160.. as [0x58..0x5b] dwords) to outList[0]
     local_count = 1
     if obj flag bit → take nested position pointer; else copy obj+0x80.. position
6. mode = skill+0x624
   if !(mode & 0x20) && !(mode & 0x4000):
     if !(mode & 1): return local_count          // no area gather
     if maxTargets(+0xde) <= local_count: return
     // top-up gather for remaining slots
   else:
     // full area gather with -1.0f radius sentinel and mode-derived flags
7. local_count = Skill_GatherTargetsInArea(outList, local_count, ...)
8. return local_count
```

---

## 4. Side-effect order

1. **Stores** invalid TFIDs across entire out buffer (100 slots).
2. **Calls** `CVOGReaction_ResolveObjectTarget` → `FUN_0054ff00`.
3. On fail path may **OR** `*outFlags` bit 1 and early-return 0.
4. On range fail **OR** bit 2 then fall into no-primary path.
5. On success **stores** primary TFID into slot 0; builds center position on stack.
6. Conditionally **calls** `Skill_GatherTargetsInArea` (mutates out list, returns new count).
7. **No network I/O**. Pure local target list build.

---

## 5. Field map (touched)

| Offset | Object | Type | Role |
|---|---|---|---|
| `skill+0x614` | skill flags | u32 | bit0 self/fallback; bit `0x20` allow no-primary |
| `skill+0x624` | targeting mode | u32 | bit0 multi; bits `0x20`/`0x4000` area modes |
| `skill+0xde` | max targets | u8 | cap for gather |
| `skill+0x28/+0x2c/+0x34/+0x38` | range/radius params | float/i32 | into range helper / gather |
| `skill+0x60c/+0x610` | gather filters | ? | into GatherTargetsInArea |
| `skill+0x5e7` | flag byte | u8 | into range helper |
| obj `+0x58..+0x5b` (index) | object TFID dwords | 16B | primary target identity |
| obj type via `[0x2a]+0x38` | clonebase/type | i32 | `0x12`/`0x14` vehicle remap |

---

## 6. Relationship to eSkillResponses

This function does **not** return `eSkillResponses`. Caller `CVOGReaction_CastSkillOnTarget` maps:

| `*outFlags` | Mapped code (caller) |
|---:|---:|
| bit 2 set | `0x0D` (13 range) |
| bit 4 set | `0x0E` (14 wrong target) |
| other nonzero | collapsed formula → small code |

Do not attribute 13/14 as *this* function's return value.

---

## 7. Open questions

1. Exact identity of `FUN_0054ff00` / `FUN_0058c0a0`.
2. Whether `DAT_009d1ca8` is the same global as `g_abTfidInvalid_9CDF88` / `DAT_009cbf68`.
3. Full ABI of `Skill_GatherTargetsInArea` (15 args in this call).
4. Seal of `skill+0x624` targeting-mode bit names against WAD/enums.
5. Call-site arg packing from CastSkillOnTarget assembly (clean caller may have simplified formals).
