# Function record: PodCopyConstruct_Elem0x138_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408880` |
| **Canonical name** | `PodCopyConstruct_Elem0x138_Inferred` |
| **Ghidra name** | `FUN_00408880` |
| **Address** | `0x00408880` |
| **Body range** | `0x00408880` – `0x004088ef` (**112 B** / `0x70`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / POD construct (Logic-UI event width **0x138**) |
| **Calling convention** | `__thiscall`; ECX=dest; stack `const void* src`; void; **`ret 4`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9H-I 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md` |
| **Dual B** | `reviews/B_aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-I) |

## Alias

- Ghidra: `FUN_00408880`
- Reject: tree/freelist/CNDHash naming — co-located near empty buynode `0x004088f0` but **not** a tree op
- Reject: chain-of-caller SendLogicUi scaffold plate

## Purpose

MSVC-style **POD copy-construct** of a **0x138-byte** element. Unrolled 14 dwords + `rep movsd` of 0x40 dwords from +0x38.

## Signature

```c
void __thiscall PodCopyConstruct_Elem0x138_Inferred(
    void* dest,          // ECX
    const void* src);    // Stack[0x4]
/* ret 4 */
```

## Behavioral summary

1. Copy dwords `src[0..13]` → `dest[0..13]` (0x38 bytes).
2. `rep movsd` 0x40 dwords from `src+0x38` → `dest+0x38` (0x100 bytes).
3. Total **0x138**; return void; clean one stack arg.

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none |
| **Callers** | `LogicUiEventQueue_InsertN` (`0x004076a0`, dualed W23-B); `FUN_0040a6e0` (placement if dest≠0; undualed) |
| **Consumers of width** | insert-N stride math `/0x138`; local buffer `local_164[312]` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00408880_FUN_00408880.md`
- Annotated: `docs/reconstruction/raw/aa_00408880_FUN_00408880.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PodCopyConstruct_Elem0x138_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00408880.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00408880_FUN_00408880.md`
- Report: `docs/agents/task-dual-ab-00408880-004088f0-wq9hi-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + width 0x138 + ret 4 | **High** |
| thiscall formals | **High** |
| Role = POD construct leaf | **High** |
| Product demangle / field map | **Inferred** |
| Runtime / bit-exact | **Open** |
