# Function record: Skill_GatherTargetsInArea

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d330` |
| **Canonical name** | `Skill_GatherTargetsInArea` |
| **Address** | `0x0058d330` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined clean** + dual residual **mode table CF sealed** (2026-07-29 strengthen); English mode names INFERRED; runtime open |

---

## 1. Summary

Area / chain multi-target collection (**INFERRED** name). Spatial-queries nearby objects (`FUN_004ea350`), filters by gather mode (`param_8`), validates candidates (`FUN_0058a810`), appends TFID entries (stride `0x10`) to `param_1`, terminates with invalid TFID sentinel (`DAT_009d4d28..`). Optional distance-sort path (`param_14`).

---

## 2. Signature (decomp order)

```c
void Skill_GatherTargetsInArea(
    int outTfidList, int startIndex, uint32_t queryArg, int* pSource,
    uint32_t* pOrigin, uint32_t rangeArg, int maxTargets, int gatherMode,
    uint32_t filterA, char chainRefresh, char allowSelfMode1,
    uint32_t filterB, uint32_t filterC, char sortByDistance, uint32_t scoreArg);
```

- **15** stack args; callers clean with `ADD ESP,0x3c`.
- Skill cast path (`Skill_ResolveTargetList`): `gatherMode = skill+0x60c`, `filterA = skill+0x610`, `chainRefresh = (skill+0x624>>14)&1`, `allowSelfMode1 = (skill+0x624>>5)&1`, `filterB=1`, `sort=0`. Also called from `NPC_TryCastSkillFromSet`.

---

## 3. Behavior outline

1. Init sort tree (`FUN_0058d9c0`), copy origin, get source handle (`vtbl+0x1c8`)
2. Build transform (`FUN_004e8a40`); spatial query with mode-derived flags
3. Pass 1: filter hits (modes 6/7/10 and `+0xd4`/`+0xdc` object gates) into candidate vector
4. Pass 2: `FUN_0058a810` + self-skip rules; either direct TFID append or distance sort insert
5. Cap at 99 targets or `maxTargets` countdown
6. Write invalid TFID terminator; free query/cand/sort resources

---

## 4. Gather mode table (`param_8`) — CF sealed 2026-07-29

Full evidence: `reviews/a_0058d330.md`. Duals: A/B accept-with-gaps.

### Query flags → `FUN_004ea350`

| Mode | Flags |
|---:|---:|
| 1, 2 | `0x11` |
| 7 | `10` (`0x0a`) |
| else | `1` |

### Pass-1 (prefer-nonzero primary for 7/10)

| Mode | Rule |
|---:|---|
| 7 | `vtbl+0x1dc()` nonzero → entity slot; else `+0xd4`/`+0xdc` |
| 10 | `vtbl+0x198()` nonzero → entity slot; else link path |
| 6 | `+0xdc` only |
| else | `+0xd4` else `+0xdc` |

### Accept roles (INFERRED English; CF High)

| Mode | INFERRED role | Highlights |
|---:|---|---|
| 0 | Self / related-owner | `+0x214`; self OK |
| 1 | Ally / non-hostile | `+0x298==0`; query `0x11`; self if `param_11`; literal `FUN_0061fdf0` |
| 2 | Hostile / enemy | `+0x298!=0`; query `0x11`; Drive/Interact/UI literals |
| 3 | Living interact | types Vehicle/Creature/Character only |
| 4 | Same related TFID | dual `+0x214` match |
| 6 | `+0xdc`-only broadphase | skip `+0xd4`; helper default accept |
| 7 | Type-filtered special | query `10`; `+0x1dc` prefer; callers often `filterA=0x14` (living types bypass exact filterA) |
| 8 | Unfiltered | early accept in helper; PollBound literal |
| 9 | Type-3 or hostile | `ObjectGraphicsPhysics` or `+0x298` |
| 10 | Dead / corpse-like | allows `+0x198!=0` |
| 0xb | Same vehicle/crew | `+0x210` / `FUN_005749d0`; self OK |
| unlisted | Default | query `1`; pass-1 default; helper `return 1` after commons |

### Self-allow (post-helper)

`mode∈{0,0xb}` or `(mode==1 && allowSelfMode1)`.

### Helper notes (xref `FUN_0058a810`, not owned)

- Mode 8 early-accept; common gates: non-null, not identity self, dead reject unless mode 10, primary TFID dedupe vs `outList` base, filterB/`FUN_005134e0`, bit10 vs mode3/filterC.
- Types `0xe`/`0x12`/`0x14`: special pos remap; **filterA exact match bypassed**.
- Mode switch: 2,1,0xb,0,3,4,9 special; else `return 1`.

---

## 5. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_0058d330_Skill_GatherTargetsInArea.*` |
| Clean | `reconstructed-exact/Skill_GatherTargetsInArea.cpp` |
| Dual A/B | `reviews/A_aa_0058d330_*`, `reviews/B_aa_0058d330_*` |
| Residual scratch | `reviews/a_0058d330.md` |
| Topic | `docs/topic-extractions/skill-cast.md` |
| Upstream skill list | `aa_00550300_Skill_ResolveTargetList` |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Function boundary | High (named) |
| Control flow | High (decompiler; labels structured) |
| Param meanings | Probable / High for mode CF |
| Mode enum **behavior** | **High** (sealed residual) |
| Mode enum **PDB names** | INFERRED / open |
| Overall | **Human-refined; mode CF sealed; runtime open** |

---

## 7. Open questions

1. Retail names for gather-mode integers (behavior sealed).
2. Name `FUN_0058a810` / spatial query helpers (out of ownership).
3. Mode-7 + `filterA=0x14` product intent vs CF (Character-only remains INFERRED).
4. SEH / exception paths — clean simplifies ExceptionList handling.
5. Runtime / bit-exact / image diff.
