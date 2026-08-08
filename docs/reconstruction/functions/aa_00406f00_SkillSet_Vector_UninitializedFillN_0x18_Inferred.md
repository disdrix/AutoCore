# Function record: SkillSet_Vector_UninitializedFillN_0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406f00` |
| **Canonical name** | `SkillSet_Vector_UninitializedFillN_0x18_Inferred` |
| **Ghidra symbol** | `FUN_00406f00` |
| **Address** | `0x00406f00`–`0x00406f1c` exclusive (**28 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / SkillSet vector |
| **Completion status** | **Dual sealed (WQ9G-F)** — accept-with-gaps; Terminal false |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **vector uninitialized_fill_n** for **0x18-byte** SkillSet entries: construct `n` copies of a prototype value at `dest`, return `dest + n*0x18`. Used by SkillSet vector insert/reallocate (`FUN_00412730`).

## Signature

```c
// EDI=dest, ESI=count, ECX=vector*, stack=const T* value; ret 4
NPCSkillSetEntry *SkillSet_Vector_UninitializedFillN_0x18_Inferred(
    void *vector, NPCSkillSetEntry *dest, unsigned count, const NPCSkillSetEntry *value);
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00406f00_FUN_00406f00.md`
- Annotated: `docs/reconstruction/raw/aa_00406f00_FUN_00406f00.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/SkillSet_Vector_UninitializedFillN_0x18_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00406f00.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_00406f00_FUN_00406f00.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller (1 fn, 2 sites) | `FUN_00412730` @ `0x0041287e`, `0x00412978` | SkillSet vector insert |
| Callee | `FUN_00412aa0` | fill loop |
| Nested | `FUN_00412b10` | 6-dword element construct |
| Related | `SkillSet_GetEntryCount` (`0x00402d80`) | dualed; same 0x18 stride |

## Confidence

| Claim | Level |
|---|---|
| Body 28 B + `ret 4` + `* 0x18` end pointer | **Confirmed** |
| EDI/ESI/stack ABI via call sites | **Confirmed** |
| SkillSet / NPCSkillSetEntry 0x18 family | **High** |
| Product / MSVC demangle | **Tentative** (`_Inferred`) |
