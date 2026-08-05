# Function record: AssPathList_ListBasenames_FilterPush_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009698a0` |
| **Canonical name** | `AssPathList_ListBasenames_FilterPush_Inferred` |
| **Prior scaffold** | `FUN_009698a0` |
| **Rejected misname** | scaffold `Named_CalleeOf_*` |
| **Address** | `0x009698a0`–`0x00969a4c` (**428 B** / `0x1AC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | asset path-list enumeration / filter collect |
| **Completion status** | **Dual reviewed** — trio + A/B **accept-with-gaps** (2026-07-29 W34-B) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

For each directory path in a string vector, append `"*.*"`, list basenames (`FUN_0076b3f0` / W33-C), resolve each basename to a handle via `FUN_00989e00` (this = `0x00d1eac8`), classify via virtual `classifier->vtbl[+0x10]`, and push matching handles into an **EDI** dword vector. Filter arg **0** accepts all classification results.

Thin stdcall wrapper @ `0x00996aa0` binds path list = `*DAT_00d1f1fc` (AssManager path vec from W31-E) and loads EDI from stack.

## Signature

```c
// stdcall; RET 0xC; EDI = out dword-vec shell* (implicit register formal)
// returns 0
uint32_t __stdcall AssPathList_ListBasenames_FilterPush_Inferred(
    StringVecShell* path_list,   // +4 begin, +8 end, stride 0x1c
    void* classifier,            // vtbl[+0x10](handle*, int* out_class)
    int type_filter);            // 0 = accept all
// EDI: PtrVecShell* out_ids  (+4 begin, +8 end, +0xc cap, stride 4)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009698a0_FUN_009698a0.md`
- Annotated: `docs/reconstruction/raw/aa_009698a0_FUN_009698a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPathList_ListBasenames_FilterPush_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_009698a0.cpp`
- Function scaffold: `docs/reconstruction/functions/aa_009698a0_FUN_009698a0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_009698a0_AssPathList_ListBasenames_FilterPush_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_009698a0_AssPathList_ListBasenames_FilterPush_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_009698a0.md`
- Report: `docs/agents/task-dual-ab-006874b0-009698a0-w34b-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callers | thin wrapper `0x00996aa0` only | sets EDI + `*DAT_00d1f1fc` |
| Callees | `FUN_00416490`, `FUN_0076b3f0`, `FUN_00989e00`, `FUN_00436ef0`, `FUN_0043bfb0`, string dtor, `operator_delete` | list + resolve + push |
| Pair with | W33-C `Fs_ListDirBasenames_Inferred`; W31-E Ass path vec; W33-F `StdString_OperatorPlus_Cstr` |

## Confidence

| Claim | Level |
|---|---|
| Outer path loop + `"*.*"` + list basenames | **Confirmed** |
| EDI out-vec ABI + RET 0xC | **Confirmed** (wrapper + body) |
| Filter gate `param_3==0 \|\| class_id==param_3` | **Confirmed** |
| Classifier product English / vtbl[+0x10] name | **Tentative** |
| `FUN_00989e00` product plate | **Tentative** (owned elsewhere) |
| Runtime / bit-exact | **Open** |
