# Function record: Skill_ResolveTargetList

| Field | Value |
|---|---|
| **Stable ID** | `aa_00550300` |
| **Canonical name** | `Skill_ResolveTargetList` |
| **Address** | `0x00550300` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (this = skill runtime) |
| **Return type** | `int` (target count, 0..100) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual strengthen 2026-07-29** — Filter/RangeCheck sole-caller linked; outFlags bits **1/2** sealed this body; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

---

## 1. Summary

Build a TFID list for casting: wipe 100 slots to invalid, resolve optional primary object, **filter** via `Skill_FilterTargetForResolveList_Inferred` (`0x0054ff00`), **range-check** via `Skill_RangeCheckTargetForResolveList_Inferred` (`0x0058c0a0`), write primary TFID, optionally top-up / full area gather via `Skill_GatherTargetsInArea` (`0x0058d330`).

**outFlags ownership (dual residual sealed 2026-07-29):**

| Bit | Writer | Condition | Primary consumer map |
|----:|--------|-----------|----------------------|
| **1** | **this body** (`LAB_005504d7`) | No usable primary: filter null **or** post-OOR fallthrough; `+0x614&1==0`; `bHasPrimary`; `+0x614&0x20==0` (Ground clear) | ResolveCastTarget → `"Nothing is targeted."` (or related if Self) |
| **2** | **this body** (post RangeCheck) | `RangeCheck == g_flZero` | ResolveCastTarget / FormatFailure → code **0xd** `"Target out of range."` |
| **4** | **Filter only** | Fallthrough reject | → code **0xe** (wrong target type family) |
| **8** | **Filter only** | Hostile/alive gate | → FormatFailure code **3** |
| **0x10** | **Filter only** | Type not in `{0xe,0x12,0x14}` | Present; ResolveCastTarget does not special-case alone |

Does **not** return `eSkillResponses`. Does **not** call `Skill_ValidateTargetForSkill`. RangeCheck has **no** outFlags formal — only produces the zero signal for bit2.

**Dual-bit note:** OOR path sets bit2 then jumps to no-primary, which may also set bit1. `Client_Skill_ResolveCastTarget` tests bit2 **first**.

---

## 2. Signature

```c
int __thiscall Skill_ResolveTargetList(
    void* thisSkill,       // skill runtime
    int*  outList,         // 100 × TFID_16
    void* gatherCtx,
    void* pSourceObj,
    uint  tfidLo, uint tfidHi, uint tfidGlobal,
    uint  unused,
    int*  pFallbackPos,
    uint* outFlags);
```

---

## 3. Behavior (exact outline)

1. Fill `outList[0..99]` with invalid TFID (`DAT_009d1ca8..` ≡ `g_abTfidInvalid_A15870` bytes `ff…ff 00…00`).
2. `bHasPrimary = !((tfidLo & tfidHi) == 0xffffffff && (char)tfidGlobal == 0)`.
3. `CVOGReaction_ResolveObjectTarget` → **Filter** (thiscall skill; may OR 4/8/0x10).
4. Null primary → maybe `outFlags|=1` and return 0, else self-pos fallback (`+0x614` bit0) or continue without fail (Ground `0x20`).
5. Object present → vehicle remap for types `0x12`/`0x14`; **RangeCheck** (`+0x2c` min, `+0x28` max, `+0x34`, `+0x5e7`); zero → `outFlags|=2` then no-primary path.
6. Write primary TFID to slot 0; count=1; build center position.
7. If `skill+0x624` needs multi/area: `Skill_GatherTargetsInArea`.
8. Return final count.

---

## 4. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_00550300_Skill_ResolveTargetList.*` |
| Clean | `reconstructed-exact/Skill_ResolveTargetList.cpp` |
| Dual residual scratch | `reviews/a_00550300.md` |
| Reviews | `reviews/A\|B_aa_00550300_*` |
| Linked filter | `aa_0054ff00` `Skill_FilterTargetForResolveList_Inferred` (sole caller = this) |
| Linked range | `aa_0058c0a0` `Skill_RangeCheckTargetForResolveList_Inferred` (sole caller = this) |
| Callers | `Client_Skill_ResolveCastTarget` `0x0093b3a0`; `CVOGReaction_CastSkillOnTarget` `0x004d09a0`; `NPC_TryCastSkillFromSet` `0x005d1280` |
| Callee gather | `Skill_GatherTargetsInArea` `0x0058d330` |
| Topic | `docs/topic-extractions/skill-cast.md` |

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Function boundary | High |
| Control flow | High (decompiler + 2026-07-29 re-decompile) |
| outFlags bit1/bit2 writers | **Confirmed** (this body only) |
| outFlags bit4/8/0x10 writers | **Confirmed** (Filter sole writer in chain) |
| Filter / RangeCheck sole-caller link | **Confirmed** (`get_function_callers`) |
| Bit2 UX English | **High** (`Target out of range.` via 0xd) |
| Bit1 UX English | **High** string (`Nothing is targeted.`); product flag name Probable |
| `+0x614` Self/Ally/Enemy/Minion/Ground | **High** (FormatTargetFilterTooltip strings) |
| Targeting mode `+0x624` English | Tentative / open |
| Gather ABI product names | Tentative |
| Overall | **Human-refined; dual residual sealed; runtime open** |

---

## 6. Open questions

1. ~~Identity of `FUN_0054ff00`~~ **Closed:** `Skill_FilterTargetForResolveList_Inferred`.
2. ~~Identity of `FUN_0058c0a0`~~ **Closed role:** `Skill_RangeCheckTargetForResolveList_Inferred` (product name still inferred).
3. ~~Invalid-TFID global vs other sentinels~~ **Closed:** same 16-byte pattern as `g_abTfidInvalid_A15870` / `DAT_009cbf68`.
4. ~~outFlags bits 1/2 exclusive writers + dual-bit interaction~~ **Closed** (this residual strengthen).
5. Full `skill+0x624` enum English seal.
6. Assembly seal of call packing from CastSkillOnTarget (static packing matches formals; live optional).
7. Live multi-target cast capture / Gather ABI product names.
