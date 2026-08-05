# Function record: Client_DebugDumpEntityCombatStats

| Field | Value |
|---|---|
| **Stable ID** | `aa_00955eb0` |
| **Canonical name** | `Client_DebugDumpEntityCombatStats` |
| **Address** | `0x00955eb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **String-renamed scaffold** - clean named twin + FUN_ retained; refine + dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00955eb0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_DebugDumpEntityCombatStats`

## Purpose

DEBUG dump of entity AI/skill state, armor, resists, owner skills.

## String evidence

`"AI: State(%d) SkillsInState(%d)" / "Skill:(%d) Level(%d)"`

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ __thiscall Client_DebugDumpEntityCombatStats(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00955eb0_FUN_00955eb0.md`
- Annotated: `docs/reconstruction/raw/aa_00955eb0_FUN_00955eb0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_DebugDumpEntityCombatStats.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00955eb0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
