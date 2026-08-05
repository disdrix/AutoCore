# Function record: Path_MakeFxcInterned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00965600` |
| **Canonical name** | `Path_MakeFxcInterned_Inferred` |
| **Ghidra name** | `FUN_00965600` |
| **Address** | `0x00965600` |
| **Body** | `0x00965600`–`0x00965742` inclusive (**323 B** / `0x143`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Client effects / path → interned `.fxc` string handle |
| **Completion status** | **Dual sealed (W38-AF)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `Path_MakeFxcInterned_Inferred`
- Reject: `Named_CalleeOf_Named_effDeviceEffect_00965600`

## Purpose

1. Read c_str from path object (`*pathObj` as `char*`; null → `""`).
2. Empty → `*out = DAT_00d1ed24`; return out.
3. Else build temp string; `rfind('.')`; no-dot append `.fxc`, else `substr(0,pos)+.fxc`.
4. Intern via `FUN_00989e00(this=0x00d1eac8, out, c_str)`.
5. Return out pointer (`__cdecl`, caller `ADD ESP,8`).

## Signature

```c
void** __cdecl Path_MakeFxcInterned_Inferred(void** outHandle, /* path with char* at +0 */ void* pathObj);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00965600_FUN_00965600.md`
- Annotated: `docs/reconstruction/raw/aa_00965600_FUN_00965600.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Path_MakeFxcInterned_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00965600.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00965600_Path_MakeFxcInterned_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00965600_Path_MakeFxcInterned_Inferred.md`
- Report: `docs/agents/task-dual-ab-00965600-004a05c0-w38af-report.md`

## Callers / callees

| **Callers** | `FUN_009701d0` (W37-Q EffEffectSlot_BindByPath), `FUN_00751da0` |
| **Callees** | `basic_string` ops; `FUN_00989e00` (string intern mgr `0x00d1eac8`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow / `.fxc` policy | **Confirmed** |
| cdecl + intern this | **Confirmed** |
| Product English / handle demangle | **Open** |
