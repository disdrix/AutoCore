# Function record: SkillSet_Vector_UninitializedCopy_0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a600` |
| **Canonical name** | `SkillSet_Vector_UninitializedCopy_0x18_Inferred` |
| **Ghidra symbol** | `FUN_0040a600` |
| **Address** | `0x0040a600`–`0x0040a664` inclusive (**101 B** / `0x65`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL SkillSet vector |
| **Completion status** | **Dual sealed (MEGA-055)** — accept-with-gaps; Terminal false |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | **accept-with-gaps** / **accept-with-gaps** |

## Purpose

MSVC-style **vector uninitialized_copy** (`_Ucopy`) for **0x18-byte** SkillSet entries: construct/copy `n` elements from `[src_first, src_end)` into `dest` via `FUN_00412b10`, return `dest + n*0x18`. SEH-framed. Used by SkillSet vector insert/reallocate (`FUN_00412730`).

## Signature

```c
// ECX=src_end; stack src_first, dest; EAX=dest_end; RET (cdecl; callers ADD ESP,0x10)
NPCSkillSetEntry *SkillSet_Vector_UninitializedCopy_0x18_Inferred(
    NPCSkillSetEntry *src_end,
    NPCSkillSetEntry *src_first,
    NPCSkillSetEntry *dest);
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0040a600_FUN_0040a600.md`
- Annotated: `docs/reconstruction/raw/aa_0040a600_FUN_0040a600.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/SkillSet_Vector_UninitializedCopy_0x18_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0040a600.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040a600_SkillSet_Vector_UninitializedCopy_0x18_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040a600_SkillSet_Vector_UninitializedCopy_0x18_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_0040a600_FUN_0040a600.md`
- Report: `docs/agents/task-dual-ab-0040a600-mega-055-report.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller (2 sites) | `FUN_00412730` @ `0x00412946`, `0x004129ad` | SkillSet vector insert |
| Caller (1 site) | `FUN_00412a80` @ `0x00412a90` | trampoline RET 8 |
| Callee | `FUN_00412b10` | 6-dword / 0x18 element copy |
| Related | `SkillSet_GetEntryCount` (`0x00402d80`) | dualed; same stride |
| Related | `SkillSet_Vector_UninitializedFillN_0x18_Inferred` (`0x00406f00`) | dualed fill sibling |
| Related | `SkillSet_UninitializedCopy_0x18` (`0x00442b00`) | leaf twin; do not merge ABI |

## Confidence

| Claim | Level |
|---|---|
| Body 101 B + `RET` cdecl + `* 0x18` end pointer | **Confirmed** |
| ECX/stack ABI via disasm + call sites | **Confirmed** |
| SkillSet / NPCSkillSetEntry 0x18 family | **High** |
| Product / MSVC demangle | **Tentative** (`_Inferred`) |

## Retired names

- `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_0040a600` — chain-of-caller only; wrong parent seed.
