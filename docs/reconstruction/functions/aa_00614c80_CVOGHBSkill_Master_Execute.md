# Function record: CVOGHBSkill_Master_Execute

| Field | Value |
|---|---|
| **Stable ID** | `aa_00614c80` |
| **Canonical name** | `CVOGHBSkill_Master_Execute` |
| **Ghidra name** | `FUN_00614c80` |
| **Address** | `0x00614c80`–`0x00614d87` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **RTTI** | `.?AVCVOGHBSkill_Master@@` (COL `0x00aadb2c`, type_info `0x00af28ac`) |
| **Vtbl** | `PTR_FUN_009d0e6c` +0x2c |
| **Catalog type id** | `3` (`SkillElementFactory_RegisterCatalog`) |
| **Object size** | `0x6c0` |
| **Completion status** | **Dual A/B sealed** R11-011 (2026-08-05) — **accept-with-gaps** |
| **Terminal** | **false** (runtime open) |

## Purpose

Master skill-element virtual execute: multi-target fan-out. For each non-sentinel 16-byte descriptor in the caller-supplied table (cap 100), resolve the object and start a child Master skill HB on the map HB list.

## Naming

| Layer | Name | Basis |
|---|---|---|
| Class | `CVOGHBSkill_Master` | RTTI **Confirmed** |
| Method | `Execute` | vtbl+0x2c convention (peer: SpawnEntities_Execute); product English open |
| Combined | `CVOGHBSkill_Master_Execute` | dual canonical |
| Retired scaffold product | (none beyond Ghidra `FUN_00614c80`) | |

## Signature

```c
uint32_t __thiscall CVOGHBSkill_Master_Execute(
    void *self /*ECX*/,
    void *skillOrSource,
    void *a2,
    int mapWorld,
    void *targetTable /* MasterTargetEntry[≤100], stride 0x10 */,
    void *a5,
    void *a6);
// ret 0x18; always returns 1
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ R11 append) | `docs/reconstruction/raw/aa_00614c80_FUN_00614c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00614c80_FUN_00614c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Master_Execute.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00614c80.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00614c80_FUN_00614c80.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00614c80_CVOGHBSkill_Master_Execute.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00614c80_CVOGHBSkill_Master_Execute.md` |
| Report | `docs/agents/task-dual-ab-00614c80-r11-report.md` |

## Gaps

- Product method English (PDB).
- Target-table producer / formal types.
- Resolve-context type at `map+0xe4e8`.
- Runtime / bit-exact / differential.
