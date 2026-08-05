# Function record: PhysHost_MergeSortedPairList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560750` |
| **Canonical name** | `PhysHost_MergeSortedPairList_Inferred` |
| **Ghidra name** | `FUN_00560750` |
| **Address** | `0x00560750`–`0x00560a2c` (**733 B** / `0x2DD`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | phys host island merge — sorted pair list @ host+0x68 |
| **Completion status** | **Dual sealed** (W29-S 2026-07-29) — A/B accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_00560750`
- Prior scaffold: `Named_CalleeOf_..._CVO_00560750` (spawn-point chain noise; superseded)

## Purpose

Merge src host's sorted stride-16 pair list into dest's list during `PhysSim_MergeHosts`. Dual-key order; equal keys absorb via virtuals; rewrite dest array.

## Signature (machine)

```c
// EAX = dest list*; stack = src list*; void; plain ret
void PhysHost_MergeSortedPairList_Inferred(void* dest_list /*EAX*/, void* src_list /*stack*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00560750_FUN_00560750.md` (+ W29-S append)
- Annotated: `docs/reconstruction/raw/aa_00560750_FUN_00560750.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PhysHost_MergeSortedPairList_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00560750.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00560750_PhysHost_MergeSortedPairList_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00560750_PhysHost_MergeSortedPairList_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_00560a30` (`PhysSim_MergeHosts_Inferred`) |
| Callees | `0055f520`, `005b3300`, `DAT_00b05060` vcalls |

## Confidence

| Claim | Level |
|---|---|
| CF decompile ≡ live | **High** |
| EAX dest + stack src ABI | **High** |
| Dual-key merge + equal vcalls | **High** |
| Stride 0x10 record | **High** |
| Product English / PUSH EBP | **Medium / gap** |
| Runtime / bit-exact | **Open** |
