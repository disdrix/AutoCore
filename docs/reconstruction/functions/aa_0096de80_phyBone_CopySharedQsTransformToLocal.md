# Function record: phyBone_CopySharedQsTransformToLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096de80` |
| **Canonical name** | `phyBone_CopySharedQsTransformToLocal` |
| **Ghidra name** | `FUN_0096de80` |
| **Address** | `0x0096de80` |
| **Body range** | `0x0096de80`–`0x0096dedd` (exclusive end; **93** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / phy (asset I/O) |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + copy map sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0096de80_phyBone_CopySharedQsTransformToLocal.md`, `reviews/B_aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` |
| **Last reviewed** | `2026-07-29` (W20-E) |

## Alias

- `FUN_0096de80` (Ghidra)
- Residual: `Named_CalleeOf_Named_gfxBodyMassageMachine_0096de80` (auto parent-seed — **misleading**)

## Purpose

**Copy shared hkQsTransform** (10 floats: quat4 + trans3 + scale3) from `*(bone+0xf4)` into bone locals at `+0x04..+0x28`, then set **`bone+0x140 = 0xffffffff`**.

Called immediately after BDAT `phyBoneSharedData_unserialize` so local bone transform mirrors shared root transform. Does not copy bind matrix or collision shape.

## Signature

```c
// EAX = phyBone* this; bare ret; void; leaf
void phyBone_CopySharedQsTransformToLocal(void);
```

## Algorithm

See annotated + clean. **No callees.**

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0096de80_FUN_0096de80.md`
- Annotated: `docs/reconstruction/raw/aa_0096de80_FUN_0096de80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/phyBone_CopySharedQsTransformToLocal.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0096de80.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00449dc0-0096de80-w20e-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers** | `phyBone_unserialize` (`0x0096e3cc`, `MOV EAX,ESI`); `FUN_0095dc70` (`0x0095e232`, `MOV EAX,EBP`) |

## Confidence

| Claim | Level |
|---|---|
| EAX = bone; shared at +0xf4 | **High** |
| 10-float copy map (+0xc→+4) | **High** |
| `+0x140 = -1` write | **High** |
| No bind/collision copy | **High** |
| Bare ret; 93 B body | **High** |
| English of +0x140 sentinel | Open |
| Product/PDB spelling | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_00449dc0` phyBoneSharedData_CreateDefaultAndInstall
- `aa_0096e280` phyBone_unserialize
- `aa_00997540` phyBoneSharedData_unserialize
