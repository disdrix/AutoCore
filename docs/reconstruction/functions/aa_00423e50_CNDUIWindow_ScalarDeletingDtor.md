# Function record: CNDUIWindow_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423e50` |
| **Canonical name** | `CNDUIWindow_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00423e50` |
| **Address** | `0x00423e50` |
| **Body** | `0x00423e50`–`0x00423e6d` inclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities residual partition / UI **CNDUIWindow** scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** MEGA-139 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style **scalar-deleting destructor** for the class whose primary vtbl is `PTR_FUN_00a960ac`. RTTI seals product name **CNDUIWindow** (`.?AVCNDUIWindow@@` @ `0x00afe1b4`). Bound as `vtbl[0]`; dword @ `0x00a960ac` = `0x00423e50`. Always invokes complete body `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` (dualed WQ9K-F); if `(flags & 1)` frees the host with `operator_delete` @ `0x00489822`; returns `this`. Ctor twin `FUN_007b5dd0` installs the same vtbl.

## Signature

```c
// ECX = this. Stack flags. RET 4. Returns this*.
void* __thiscall CNDUIWindow_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Xrefs / callers | DATA vtbl[0] only (`0x00a960ac`); virtual dispatch from `delete` paths |
| Callees | `CNDUIWindow_CompleteDtor` (`FUN_007b5be0`), `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00423e50_FUN_00423e50.md`
- Annotated: `docs/reconstruction/raw/aa_00423e50_FUN_00423e50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWindow_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00423e50.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00423e50_CNDUIWindow_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00423e50_CNDUIWindow_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_00423e50_FUN_00423e50.md`
- Parent complete: `docs/reconstruction/functions/aa_007b5be0_CNDUIWindow_CompleteDtor.md`

## Confidence

| Claim | Level |
|---|---|
| Scalar-deleting role (optional free this) | **High** |
| ABI ECX + flags + RET 4 | **High** |
| Product RTTI name CNDUIWindow | **High** |
| vtbl[0] binding | **High** |
| Runtime | **Open** |
