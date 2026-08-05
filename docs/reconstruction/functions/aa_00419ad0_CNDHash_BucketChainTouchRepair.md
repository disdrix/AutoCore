# Function record: CNDHash_BucketChainTouchRepair

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419ad0` |
| **Canonical name** | `CNDHash_BucketChainTouchRepair` |
| **Ghidra name** | `FUN_00419ad0` |
| **Address** | `0x00419ad0` |
| **Body range** | `0x00419ad0`–`0x00419b30` (exclusive end; **96** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash u64-bucket integrity |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + string sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00419ad0_CNDHash_BucketChainTouchRepair.md`, `reviews/B_aa_00419ad0_CNDHash_BucketChainTouchRepair.md` |
| **Last reviewed** | `2026-07-29` (W19-D) |

## Alias

- `FUN_00419ad0` (Ghidra)
- `Util_HashListError_Repair` (NAMING_REGISTRY / plate string)
- `HashList_IntegrityWalkRepair_u64Bucket` (descriptive)
- Residual: `Named_CalleeOf_Named_VOG_DEBUG_STOP_00419ad0` (auto parent-seed — **misleading**)

## Purpose

**Integrity walk + optional cycle repair** on a CNDHash **bucket** singly-linked chain (`head@+4`, `touch@node+8`, `next@node+0x10`):

1. Empty head → return.
2. Walk: stamp touch=1; follow next.
3. Null next → clear all touches (healthy).
4. Next already touched → log `"HashListError: Went to node we already touched! Attempting repair!"`, sever `prev->next=0`, clear touches.

Always called after u64 bucket insert/unlink in this family. Does not free nodes or touch ordered list.

## Signature

```c
// EDI = bucket header*; bare ret; void
void CNDHash_BucketChainTouchRepair(void);
```

## Algorithm

See annotated + clean. Sole callee: `FUN_007a4480` (log).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00419ad0_FUN_00419ad0.md`
- Annotated: `docs/reconstruction/raw/aa_00419ad0_FUN_00419ad0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_BucketChainTouchRepair.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00419ad0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00419ad0-0076cef0-w19d-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_007a4480` only |
| **Callers** | `CNDHash_Insert_u64` (`FUN_00413920`), `CNDHash_BucketUnlinkByU64Key` (`FUN_00419b80` ×2), `FUN_00419620` |

## Confidence

| Claim | Level |
|---|---|
| EDI = bucket; head at +4 | **High** |
| Touch byte `node+8`; next `node+0x10` | **High** |
| Cycle log + sever + clear marks | **High** |
| Bare ret; no free | **High** |
| Distinct layout from `aa_00537d30` | **High** |
| Product/PDB symbol | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_00419b80` CNDHash_BucketUnlinkByU64Key (always calls this)
- `aa_00419b40` CNDHash_BucketFindNodeByU64Key
- `aa_00413920` CNDHash_Insert_u64
- `aa_00537d30` HashList_IntegrityWalkRepair_Inferred (clone, different node offsets / ECX)
