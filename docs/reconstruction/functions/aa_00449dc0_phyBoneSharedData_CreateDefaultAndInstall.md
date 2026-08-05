# Function record: phyBoneSharedData_CreateDefaultAndInstall

| Field | Value |
|---|---|
| **Stable ID** | `aa_00449dc0` |
| **Canonical name** | `phyBoneSharedData_CreateDefaultAndInstall` |
| **Ghidra name** | `FUN_00449dc0` |
| **Address** | `0x00449dc0` |
| **Body range** | `0x00449dc0`–`0x00449e72` (exclusive end; **178** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / phy (asset I/O) |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + layout sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md`, `reviews/B_aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` |
| **Last reviewed** | `2026-07-29` (W20-E) |

## Alias

- `FUN_00449dc0` (Ghidra)
- Residual: `Named_CalleeOf_Named_gfxBodyMassageMachine_00449dc0` (auto parent-seed — **misleading**)

## Purpose

**Allocate default phyBoneSharedData (0x90)** with identity hkQsTransform + identity bind 4x4 + null collision slot, **AddRef**, **Release** prior occupant of `*(EBX+4)`, install new pointer.

Call sites always set `EBX = bone+0xf0` so the installed field is **`bone+0xf4`** — the shared-data smart pointer used by BDAT unserialize and by `phyBone_CopySharedQsTransformToLocal`.

## Signature

```c
// EBX = container* (slot at +4); bare ret; void
void phyBoneSharedData_CreateDefaultAndInstall(void);
```

## Algorithm

See annotated + clean. Callees: `operator_new`; virtual `vtbl+4` (empty); virtual `vtbl+8` (release).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00449dc0_FUN_00449dc0.md`
- Annotated: `docs/reconstruction/raw/aa_00449dc0_FUN_00449dc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/phyBoneSharedData_CreateDefaultAndInstall.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00449dc0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00449dc0-0096de80-w20e-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `operator_new(0x90)`; vtbl+4 empty `FUN_0056f570`; vtbl+8 release `@0x00464890` |
| **Callers** | `phyBone_unserialize` (`0x0096e3b1`); `FUN_0096e1f0` (`0x0096e242`); `FUN_0095dc70` ×3 |

## Confidence

| Claim | Level |
|---|---|
| EBX container; install `*(EBX+4)` | **High** |
| Callers map slot to `bone+0xf4` | **High** |
| Size 0x90; identity qs + matrix | **High** |
| Refcount AddRef/Release | **High** |
| Bare ret; 178 B body | **High** |
| Product/PDB class/method spelling | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_0096de80` phyBone_CopySharedQsTransformToLocal
- `aa_0096e280` phyBone_unserialize
- `aa_00997540` phyBoneSharedData_unserialize
- `aa_00449d80` scalar deleting dtor (vtbl+0)
