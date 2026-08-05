# Function record: FUN_004bfd10 / TrackMgr_9CircList_UntrackObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfd10` |
| **Canonical name** | `TrackMgr_9CircList_UntrackObject_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004bfd10` |
| **Address** | `0x004bfd10` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Client object/graphics track manager (host `+0xE914`) |
| **Completion status** | **Dual sealed (A+B)** — W37-T 2026-08-04 (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold seed: `Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_004bfd10` (**reject**).
- Named record: `aa_004bfd10_TrackMgr_9CircList_UntrackObject_Inferred.md`

## Purpose

Remove matching payload from manager’s 9 circular list buckets; free node; owning-delete payload; return bool. Used by `Object_UnloadGraphics_Inferred` first.

## Signature (machine-sealed)

```c
uint8_t __thiscall FUN_004bfd10(void *manager, void *object);
// ret 4; body 146 B @ 0x004bfd10–0x004bfda1
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bfd10_FUN_004bfd10.md`
- Annotated: `docs/reconstruction/raw/aa_004bfd10_FUN_004bfd10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004bfd10.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/TrackMgr_9CircList_UntrackObject_Inferred.cpp`
- Review A/B: `docs/reconstruction/reviews/{A,B}_aa_004bfd10_TrackMgr_9CircList_UntrackObject_Inferred.md`
- Report: `docs/agents/task-dual-ab-00410420-004bfd10-w37t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x005c6720` | Match predicate |
| Callee | `operator_delete` + payload `vtbl[0](1)` | Free node + payload |
| Caller | `0x005825d0` | `Object_UnloadGraphics_Inferred` |
| Callers | `00854d20`, `00855810`, `00856380`, `008d80c0` | Teardown |

## Confidence

| Claim | Level |
|---|---|
| 9-bucket CF + ret 4 | **Confirmed** |
| Post-delete path (bytes win vs decompiler) | **Confirmed** |
| Product manager English | **Open** |
