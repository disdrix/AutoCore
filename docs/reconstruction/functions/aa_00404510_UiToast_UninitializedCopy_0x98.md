# Function record: UiToast_UninitializedCopy_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404510` |
| **Canonical name** | `UiToast_UninitializedCopy_0x98` |
| **Ghidra name** | `FUN_00404510` |
| **Address** | `0x00404510` |
| **Body range** | `0x00404510`–`0x0040452f` (32 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; trampoline + stride via callee sealed; worker dual residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00404510_UiToast_UninitializedCopy_0x98.md`, `reviews/B_aa_00404510_UiToast_UninitializedCopy_0x98.md` (2026-07-29 W22-G) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00404510`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404510` (legacy scaffold)
- Structural: MSVC-style `uninitialized_copy` trampoline for toast POD **0x98**
- Twin: `CombatFloater_UninitializedCopy_0x38_Inferred` @ `0x004044c0`

## Purpose

Thin **relocate / uninitialized_copy** wrapper for UI toast POD elements (stride **0x98**):

1. Forward `(srcBegin, srcEnd, dst)` to `FUN_004047a0`.
2. Worker loops `p += 0x98`, `UiToast_PodCopyElement_0x98` (`FUN_00404710`) each element, returns advanced `dst`.

Sole known parent: `UiToastVector_InsertN` (`0x00403980`) — four call sites on realloc relocate and in-place shift. Distinct from fill-n `UiToast_UninitializedFillN_0x98` (`0x00404130`).

## Signature

```c
void *UiToast_UninitializedCopy_0x98(void *srcBegin, void *srcEnd, void *dst);
// ret 0x0C (3 stack args); ECX phantom-pushed into worker only
```

## Algorithm

```
// this VA:
return FUN_004047a0(srcBegin, srcEnd, dst);

// worker FUN_004047a0 (not dual-owned here):
for (p = srcBegin; p != srcEnd; p += 0x98) {
  UiToast_PodCopyElement_0x98(dst, p);  // 0x26 dwords
  dst += 0x98;
}
return dst;
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00404510_FUN_00404510.md`
- Annotated: `docs/reconstruction/raw/aa_00404510_FUN_00404510.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UiToast_UninitializedCopy_0x98.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00404510.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00404510_FUN_00404510.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004048c0-00404510-w22g-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x004047a0` | toast range copy +0x98 (scaffold dual residual) |
| Nested | `0x00404710` | `UiToast_PodCopyElement_0x98` |
| Caller | `0x00403980` | `UiToastVector_InsertN` (×4 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Sole callee `FUN_004047a0` | **High** |
| Element stride **0x98** (via worker) | **High** |
| `ret 0x0C` / three stack args | **High** |
| Role = toast range relocate (not fill-n) | **High** |
| Exact formal names / product symbol | **Inferred / Open** |
| Worker `004047a0` dual | Residual (out of OWN) |
| Runtime / differential | Open |
