# Function record: TrackMgr_9CircList_UntrackObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfd10` |
| **Canonical name** | `TrackMgr_9CircList_UntrackObject_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004bfd10` |
| **Address** | `0x004bfd10` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Client object/graphics track manager (host field `+0xE914`) |
| **Completion status** | **Dual sealed (A+B)** — W37-T 2026-08-04 (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold seed: `Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_004bfd10` (**reject**).
- Structural: `TrackMgr_9CircList_UntrackObject_Inferred` — remove matching payload from 9 circular list buckets.

## Purpose

Untrack an object from a manager that stores entries in **nine** circular doubly-linked lists (`this+8`, stride `0xC`):

1. For each non-empty bucket, walk `head->next … head`.
2. Match payload via `FUN_005c6720(payload, object)`.
3. Unlink node, `operator_delete(node)`, `count--`, scalar-deleting dtor on payload.
4. Return **1** if removed, **0** if not found.

Used first by `Object_UnloadGraphics_Inferred` (`0x005825d0`) with manager at host`+0xE914`.

## Signature (machine-sealed)

```c
uint8_t __thiscall FUN_004bfd10(
    void *this,    // ECX = track manager
    void *object   // stack+4 — object to match
);
// ret 4; AL = 1 removed / 0 not found
// body 0x004bfd10–0x004bfda1 (146 B)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bfd10_FUN_004bfd10.md`
- Annotated: `docs/reconstruction/raw/aa_004bfd10_FUN_004bfd10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/TrackMgr_9CircList_UntrackObject_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bfd10.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004bfd10_TrackMgr_9CircList_UntrackObject_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bfd10_TrackMgr_9CircList_UntrackObject_Inferred.md`
- Report: `docs/agents/task-dual-ab-00410420-004bfd10-w37t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x005c6720` | Payload↔object identity/TFID match |
| Callee | `operator_delete` | Free list node shell |
| Callee | payload `vtbl[0](1)` | Scalar-deleting dtor |
| Sibling | `0x004bfdb0` | Same walk; set `payload+0x51` on match |
| Caller | `0x005825d0` | `Object_UnloadGraphics_Inferred` (W31-T) |
| Caller | `0x00854d20`, `0x00855810`, `0x00856380`, `0x008d80c0` | Object teardown paths |

## Confidence

| Claim | Level |
|---|---|
| 9-bucket circular walk | **Confirmed** |
| `__thiscall` + `ret 4` + bool AL | **Confirmed** |
| Unlink + free + count-- + payload dtor | **Confirmed** |
| Decompiler noreturn-delete is wrong | **Confirmed** |
| Role = manager untrack by match | **High** |
| Product manager/payload names | **Open** |
