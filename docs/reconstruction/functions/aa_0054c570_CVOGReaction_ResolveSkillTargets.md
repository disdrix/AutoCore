# Function record: CVOGReaction_ResolveSkillTargets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054c570` |
| **Canonical name** | `CVOGReaction_ResolveSkillTargets` |
| **Address** | `0x0054c570` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | `__cdecl` (2 stack args; caller `ADD ESP,8`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual sealed 2026-07-29** — CF/ABI High; name misnomer noted |

---

## 1. Summary

Looks up skill **definition** by skill ID in global map at `DAT_00b04734`. If found (node ≠ `DAT_00b04738` end sentinel), allocates a **0x630**-byte runtime, runs ctor `FUN_0054f3c0`, copies **0x18c dwords** from `node+0x10`, stores rank at **`+0x5f6`** via `Skill_SetRankAndReevaluate`, returns the buffer. Returns **null on map miss**.

**Naming note:** Despite “ResolveSkillTargets”, this clones skill **runtime/template** data and applies rank — not a TFID target list. Target lists are `Skill_ResolveTargetList` / `Skill_GatherTargetsInArea`.

---

## 2. Signature

```c
// __cdecl — asm-sealed 2026-07-29
uint32_t* __cdecl CVOGReaction_ResolveSkillTargets(int skillId, int rankPacked);
// rankPacked used as uint16 → skill runtime +0x5f6
// returns new 0x630 buffer or null (lookup miss)
// unaff_DI is NOT an argument (decomp artifact)
```

---

## 3. Behavior (exact outline)

1. SEH frame install
2. If `DAT_00b04724 == 0`: `FUN_0054b2c0()` skill-table init
3. `FUN_00418890` find on map object **`DAT_00b04734`** with key = skillId
4. If node == `DAT_00b04738` (end sentinel): return null
5. Else:
   - `operator_new(0x630)`
   - `FUN_0054f3c0` with ECX = allocation (ctor)
   - `REP MOVSD` 0x18c dwords from `node+0x10` → buffer
   - `Skill_SetRankAndReevaluate(buffer, rankPacked)` — thiscall, one stack arg, `RET 4`
   - return buffer

---

## 4. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_0054c570_CVOGReaction_ResolveSkillTargets.*` |
| Clean | `reconstructed-exact/CVOGReaction_ResolveSkillTargets.cpp` |
| Dual A/B | `reviews/A|B_aa_0054c570_CVOGReaction_ResolveSkillTargets.md` |
| Scratch | `tmp/a_0054c570.md` |

### Notable callers

| Caller | Role with return |
|---|---|
| `Skill_EnsureLoadedInTree` | miss → materialize → tree insert (`FUN_0051e6d0`) |
| `Skill_ApplyStatusEffectLocal` | item flag path; delete after use |
| Outpost cast helpers | materialize → validate/cast → delete |
| `Client_RecvSkillStatusEffect` | item materialize path |

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Control flow / sizes / ABI | **High** (asm 2026-07-29) |
| Null = map miss | **High** |
| Rank via stack arg1 → +0x5f6 | **High** |
| Symbol name accuracy | Probable mismatch (materialize, not targets) |
| Map/ctor product names | Tentative (FUN_*) |
| Overall | **Human-refined + dual residual; runtime open** |

---

## 6. Open questions

1. True retail name.
2. Full type of 0x630 runtime object.
3. Product names for `FUN_00418890` / `FUN_0054f3c0` / `FUN_0054b2c0`.
