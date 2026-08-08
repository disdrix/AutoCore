# Function record: StdVector_DestroyRuns_0x80_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004271c0` |
| **Canonical name** | `StdVector_DestroyRuns_0x80_Inferred` |
| **Ghidra name** | `FUN_004271c0` |
| **Address** | `0x004271c0`–`0x00427204` inclusive (**69 B** / `0x45`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / UI text-layout container |
| **Partition** | MEGA-128 (`WAVE_2026-08-05_mega_residual_partition_map`) |
| **Parent owner** | `UiTextLayout_CompleteDtor_Inferred` `0x00797d70` (vector @ `+0x80`) |
| **Completion status** | **Dual sealed** — Path A/B **accept** |
| **Terminal** | **false** (no runtime Confirmed) |

## Purpose

Destroy all 0x80-stride elements in a standard three-pointer vector shell (begin/end/cap @ +4/+8/+0xC), free the buffer, and null the triple. Per-element work is only `~basic_string<wchar_t>` at offset +0x0C via trampoline `FUN_00426f70`.

## Signature

```c
// EBX = Vec80Shell*; void; bare RET
void StdVector_DestroyRuns_0x80_Inferred(void);
```

## Why `_Inferred`

No RTTI / product demangle on this helper. "Runs" is structural inference from sole caller placing the shell at text-layout `+0x80` (glyph/run vector in WQ9L-F dual). Element field English beyond `wstring@+0xC` remains open.

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004271c0_FUN_004271c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004271c0_FUN_004271c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRuns_0x80_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004271c0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_004271c0_FUN_004271c0.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_004271c0_StdVector_DestroyRuns_0x80_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_004271c0_StdVector_DestroyRuns_0x80_Inferred.md` |
| Report | `docs/agents/task-dual-ab-004271c0-mega-128-report.md` |

## Related (not dualled here)

| VA | Role |
|---|---|
| `0x00797d70` | UiTextLayout complete dtor — sole CALL |
| `0x00427040` | JMP thunk |
| `0x00426f70` | elem `~wstring` trampoline |
| `0x00465d70` | twin pattern tidy stride 0x24 (dualed W38-R) |
