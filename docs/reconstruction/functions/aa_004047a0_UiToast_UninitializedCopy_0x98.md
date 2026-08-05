# Function record: UiToast_UninitializedCopy_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_004047a0` |
| **Canonical name** | `UiToast_UninitializedCopy_0x98` |
| **Ghidra name** | `FUN_004047a0` |
| **Address** | `0x004047a0` |
| **Body range** | `0x004047a0`–`0x0040480b` (108 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + stride sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004047a0_UiToast_UninitializedCopy_0x98.md`, `reviews/B_aa_004047a0_UiToast_UninitializedCopy_0x98.md` (2026-07-29 W22-H) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004047a0`
- Scaffold: `Named_CalleeOf_…_004047a0`
- Twin pattern: `UiToast_UninitializedFillN_0x98` @ `0x00404130` (fill-N)

## Purpose

MSVC-style **`uninitialized_copy`** for toast elements of stride **`0x98`**:

```
for (src = begin; src != end; src += 0x98) {
  UiToast_PodCopyElement_0x98(dst, src);
  dst += 0x98;
}
return dst;
```

Sole known parent thunk: `FUN_00404510` (vector member → free helper).

## Signature

```c
void *UiToast_UninitializedCopy_0x98(void *src_begin, void *src_end, void *dst, void *unused_opt);
// cdecl; returns dst end
```

## Algorithm

1. SEH register (noop path).
2. While `src_begin != src_end`: PodCopyElement; advance both by `0x98`.
3. Return final `dst`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004047a0_FUN_004047a0.md`
- Annotated: `docs/reconstruction/raw/aa_004047a0_FUN_004047a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UiToast_UninitializedCopy_0x98.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_004047a0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004047a0_FUN_004047a0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004047a0-005911b0-w22h-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00404710` | `UiToast_PodCopyElement_0x98` |
| Caller | `0x00404510` | toast-vector thiscall thunk |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Stride **0x98** | **High** |
| cdecl plain `ret` | **High** |
| Toast family membership | **High** (callee dual + parent chain) |
| Product name | **Open** |
| Runtime / differential | Open |
