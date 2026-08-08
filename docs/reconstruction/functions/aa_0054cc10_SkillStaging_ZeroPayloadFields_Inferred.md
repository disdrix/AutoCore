# Function record: SkillStaging_ZeroPayloadFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cc10` |
| **Canonical name** | `SkillStaging_ZeroPayloadFields_Inferred` |
| **Ghidra name** | `FUN_0054cc10` |
| **Address** | `0x0054cc10`–`0x0054d43f` (2096 B / `0x830`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Partition** | `WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-038** |
| **Dual start** | 2686 |
| **Partition parent dual** | `0x0054cbb0` (adjacency; PossessCreature DefaultFactory) |
| **Semantic caller** | `0x0054a290` `SkillDef_InstallLoadedRecord` |
| **Completion status** | **Dual A/B sealed (R13-038)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Leaf bulk-zero of skill-staging payload fields **`this+0x28` … `this+0x534`** inclusive (`0x144` dwords). Used as prep before skill-def install packs flags into a stack staging buffer of size **`0x538`** (`0x14e` dwords). Does not clear the first `0x28` bytes of the object.

## Signature (image-sealed)

```c
// thiscall: ECX = self; 0 stack args; bare RET; void
void __fastcall SkillStaging_ZeroPayloadFields_Inferred(void *self);
```

## Artifacts

- Raw (+ re-verify append): `docs/reconstruction/raw/aa_0054cc10_FUN_0054cc10.md`
- Annotated: `docs/reconstruction/raw/aa_0054cc10_FUN_0054cc10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/SkillStaging_ZeroPayloadFields_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0054cc10.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0054cc10_SkillStaging_ZeroPayloadFields_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0054cc10_SkillStaging_ZeroPayloadFields_Inferred.md`
- Report: `docs/agents/task-dual-ab-0054cc10-r13-report.md`
- Scaffold record: `docs/reconstruction/functions/aa_0054cc10_FUN_0054cc10.md`

## Callers / callees

| Direction | Address / name | Notes |
|---|---|---|
| Code CALL | `0x0054a2d1` in `FUN_0054a290` | sole UNCONDITIONAL_CALL; `LEA ECX,[ESP+0x1a0]` |
| DATA | *(none)* | 0 DATA xrefs |
| Callees | *(none)* | leaf |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| ABI thiscall / 0 args / bare RET / void | **High** |
| Field range `+0x28`..`+0x534` / `0x144` dwords | **High** |
| Sole direct caller install staging | **High** |
| Role English "SkillStaging ZeroPayloadFields" | **Inferred** |
| Per-slot product field names | **Open** |
| Runtime | Open |
