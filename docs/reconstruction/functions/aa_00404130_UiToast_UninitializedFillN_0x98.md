# Function record: UiToast_UninitializedFillN_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404130` |
| **Canonical name** | `UiToast_UninitializedFillN_0x98` |
| **Ghidra name** | `FUN_00404130` |
| **Address** | `0x00404130` |
| **Body range** | `0x00404130`–`0x0040415f` (48 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + stride sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00404130_UiToast_UninitializedFillN_0x98.md`, `reviews/B_aa_00404130_UiToast_UninitializedFillN_0x98.md` (2026-07-29 W20-G) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00404130`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404130` (legacy scaffold)
- Structural: fill-n wrapper — ConstructN then `return dst + n*0x98`
- Twin: `CombatFloater_UninitializedFillN_0x38` @ `0x00402ea0`

## Purpose

**Uninitialized fill-N** for UI toast POD elements (stride **0x98**):

1. Call `UiToast_ConstructN_0x98` (`FUN_00404670`) to stamp `count` copies of template `src` at `dst`.
2. Return **end** pointer `dst + count * 0x98`.

Sole known parent: `UiToastVector_InsertN` (`0x00403980`) on realloc and in-place insert hole fills.

## Signature

```c
void *UiToast_UninitializedFillN_0x98(void *dst, int count, const void *src);
// ret 0x0C (3 stack args); ECX unused for result (may be phantom-pushed)
```

## Algorithm

```
UiToast_ConstructN_0x98(dst, count, src);
return dst + count * 0x98;
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00404130_FUN_00404130.md`
- Annotated: `docs/reconstruction/raw/aa_00404130_FUN_00404130.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UiToast_UninitializedFillN_0x98.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00404130.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00404130_FUN_00404130.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00418130-00404130-w20g-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00404670` | `UiToast_ConstructN_0x98` |
| Caller | `0x00403980` | `UiToastVector_InsertN` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Stride **0x98** end arithmetic | **High** |
| Callee = sealed ConstructN | **High** |
| `ret 0x0C` / three stack args | **High** |
| Role = toast fill-n (not grow) | **High** |
| Product English symbol | **Inferred / Open** |
| Runtime / differential | Open |
