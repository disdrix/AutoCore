# Function record: AssPackManager_OpenPackFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984ee0` |
| **Canonical name** | `AssPackManager_OpenPackFile_Inferred` |
| **Ghidra name** | `FUN_00984ee0` |
| **Address** | `0x00984ee0`–`0x00985006` (**295 B** / `0x127`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir assets / assPackManager |
| **Wave** | W31-H OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Classification** | worker |

## Purpose

Open a pack file path under optional manager critical section: construct 0x44 pack object, open via nested I/O helper, push into manager vector at +0x28; log Opening/FAILED/SUCCESS from `assPackManager.cpp`.

## Signature (sealed)

```c
// EBX = AssPackManager* self
// ECX = const char* path
// stack char flag (0/1 → pack+0x40)
// RET 4; int 0 / -1
int AssPackManager_OpenPackFile_Inferred(const char* path /*ECX*/, char flag /*stack*/,
                                         AssPackManager* self /*EBX*/);
```

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `AssManager_InitPrecompileAndResolvers_Inferred` | `0x007b75b0` | batch caller (W30-D) |
| Pack ctor `FUN_00719970` | `0x00719970` | nested (not OWN) |
| Pack open `FUN_0071a9d0` | `0x0071a9d0` | nested (not OWN) |
| Vector push `FUN_004406e0` | `0x004406e0` | nested (not OWN) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00984ee0_FUN_00984ee0.md`
- Annotated: `docs/reconstruction/raw/aa_00984ee0_FUN_00984ee0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPackManager_OpenPackFile_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00984ee0.cpp`
- Legacy: `docs/reconstruction/reconstructed-exact/Named_assPackManager_00984ee0.cpp`
- Function FUN: `docs/reconstruction/functions/aa_00984ee0_FUN_00984ee0.md`
- A: `docs/reconstruction/reviews/A_aa_00984ee0_AssPackManager_OpenPackFile_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_00984ee0_AssPackManager_OpenPackFile_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_00984ee0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow | **High** |
| ABI EBX/ECX/stack/RET4 | **High** |
| CS +0x38 / gate +0x50 / vector +0x28 | **High** |
| Nested open product English | **Med** |
| Runtime / bit-exact | **Open** |
