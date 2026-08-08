# Function record: RunElem_WStringDtor_Plus0C_Trampoline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00426f70` |
| **Canonical name** | `RunElem_WStringDtor_Plus0C_Trampoline_Inferred` |
| **Ghidra name** | `FUN_00426f70` |
| **Address** | `0x00426f70`–`0x00426f78` inclusive (**9 B** / `0x9`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / UI text-layout container |
| **Partition** | R10-026 (`WAVE_2026-08-05_r10_residual_partition_map`) |
| **Parent owner** | `StdVector_DestroyRuns_0x80_Inferred` `0x004271c0` |
| **Completion status** | **Dual sealed** — Path A/B **accept** |
| **Terminal** | **false** (no runtime Confirmed) |

## Purpose

Destroy the embedded `basic_string<wchar_t>` at **element+0x0C** via MSVC IAT. Not a full element destructor — only the member string. Callers walk 0x80-stride element arrays (destroy-runs / destroy-range) and SEH unwind frames.

## Signature

```c
// ECX = RunElem0x80*; void; tail-JMP IAT ~basic_string<wchar_t>
void __fastcall RunElem_WStringDtor_Plus0C_Trampoline_Inferred(void* elem /* ECX */);
```

## Why `_Inferred`

No RTTI / product demangle on this trampoline. "RunElem" is structural inference from dualed parent vector tidy for UiTextLayout `+0x80` 0x80-stride elements. Offset +0x0C and wstring type are **High** confidence from bytes + IAT symbol.

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00426f70_FUN_00426f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00426f70_FUN_00426f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RunElem_WStringDtor_Plus0C_Trampoline_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00426f70.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00426f70_FUN_00426f70.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00426f70_RunElem_WStringDtor_Plus0C_Trampoline_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00426f70_RunElem_WStringDtor_Plus0C_Trampoline_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00426f70-r10-report.md` |

## Related (not dualled here)

| VA | Role |
|---|---|
| `0x004271c0` | parent vector destroy-runs stride 0x80 — dualed MEGA-128 |
| `0x00427590` | destroy-range stride 0x80 (caller) |
| `0x00427040` | JMP thunk → parent tidy |
| `0x00797d70` | UiTextLayout complete dtor — grandparent |
| `0x009c62ac` | IAT `PTR_~basic_string<wchar_t,...>` |
