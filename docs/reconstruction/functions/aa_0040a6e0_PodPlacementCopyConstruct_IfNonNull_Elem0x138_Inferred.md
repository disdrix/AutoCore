# Function record: PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a6e0` |
| **Canonical name** | `PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred` |
| **Ghidra name** | `FUN_0040a6e0` |
| **Address** | `0x0040a6e0` |
| **Body range** | `0x0040a6e0` – `0x0040a729` exclusive (**74 B** / `0x4A`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / POD placement (Logic-UI event width **0x138**) |
| **Calling convention** | cdecl formals; bare **`ret`**; parent cleans 8 bytes |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9I-D 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_0040a6e0_PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.md` |
| **Dual B** | `reviews/B_aa_0040a6e0_PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9I-D) |

## Alias

- Ghidra: `FUN_0040a6e0`
- Reject: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_SendLogicUi_0040a6e0` (scaffold plate)
- Reject: tree/freelist/CNDHash naming — neighborhood only

## Purpose

Null-checked **placement / uninitialized copy-construct** of one **0x138-byte** POD element. Forwards to dualed leaf `PodCopyConstruct_Elem0x138_Inferred` when dest ≠ 0.

## Signature

```c
// cdecl; bare ret
void PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred(
    void* dest,          // Stack[0x4]
    const void* src);    // Stack[0x8]
```

## Behavioral summary

1. Install SEH frame (`LAB_009bdcb1`); scope = 0.
2. If `dest == 0`: skip construct.
3. Else: thiscall `PodCopyConstruct_Elem0x138_Inferred(dest, src)` (`0x00408880`, RET 4).
4. Uninstall SEH; `ADD ESP,0x10`; bare `ret`.

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `PodCopyConstruct_Elem0x138_Inferred` (`0x00408880`, dualed WQ9H-I) |
| **Callers** | Sole: `FUN_00409f10` @ `0x00409f1a` (stdcall RET8 trampoline) |
| **Upstream** | `FUN_00409cc0` ConstructN fill; `FUN_0040a4a0` uninit-copy range — both stride **0x138** |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0040a6e0_FUN_0040a6e0.md`
- Annotated: `docs/reconstruction/raw/aa_0040a6e0_FUN_0040a6e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_0040a6e0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0040a6e0_FUN_0040a6e0.md`
- Report: `docs/agents/task-dual-ab-0040a6e0-007fe640-wq9id-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + null gate + SEH | **High** |
| cdecl formals / bare ret | **High** |
| Width 0x138 via dualed leaf + parent stride | **High** |
| Role = placement construct helper | **High** |
| Product event field map | **Inferred / open** |
| Runtime / bit-exact | **Open** |
