# Function record: StringVec_PushFront_EnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_00969830` |
| **Canonical name** | `StringVec_PushFront_EnsureTrailingDirSep` (**Inferred** structural) |
| **Ghidra name** | `FUN_00969830` |
| **Address** | `0x00969830` |
| **Body** | `0x00969830`–`0x00969897` exclusive (**103 B** / `0x67`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assManager / `StringVecShell` (`DAT_00d1f1fc`) |
| **Completion status** | **Dual-reviewed** W31-E — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Ensure the input path ends with a directory separator (`/`, unless already ends with `:`, `/`, or `\`), then insert that string at the **front** of the global string vector `*DAT_00d1f1fc` (element size `0x1c`).

## Signature

```c
// ESI = StringVecShell*; stack path*; RET 4; void
void StringVec_PushFront_EnsureTrailingDirSep(StringVecShell* self /*ESI*/,
                                              const void* path /*stack*/);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `AssManager_InitPrecompileAndResolvers` (`FUN_007b75b0`) ×2 |
| Callees | `FUN_009694e0`, `FUN_00430310` → `FUN_004306b0`, IAT `~basic_string` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00969830_FUN_00969830.md`
- Annotated: `docs/reconstruction/raw/aa_00969830_FUN_00969830.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StringVec_PushFront_EnsureTrailingDirSep.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00969830.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00969830_StringVec_PushFront_EnsureTrailingDirSep.md`
- Review B: `docs/reconstruction/reviews/B_aa_00969830_StringVec_PushFront_EnsureTrailingDirSep.md`
- Scaffold record: `docs/reconstruction/functions/aa_00969830_FUN_00969830.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ESI = `*DAT_00d1f1fc` | **High** (call-site bytes) |
| Front insert (pos = begin) | **High** |
| Trailing-sep normalize shape | **High** (via `FUN_009694e0` decompile) |
| Product list English / demangle | **Low** |
