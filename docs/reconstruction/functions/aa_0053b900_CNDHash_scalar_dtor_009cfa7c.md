# Function record: CNDHash_scalar_dtor_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b900` |
| **Canonical name** | `CNDHash_scalar_dtor_009cfa7c` (**Inferred**) |
| **Ghidra name** | `FUN_0053b900` |
| **Address** | `0x0053b900` |
| **Body range** | `0x0053b900`–`0x0053b91d` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; scalar CF + vtbl[0] sealed; product mangled name open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md`, `reviews/B_aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md` |
| **Last reviewed** | `2026-07-29` (W25-H) |

## Alias

- `FUN_0053b900` (Ghidra / scaffold)
- Scalar deleting dtor of `CNDHash_Dtor_009cfa7c` / `PTR_FUN_009cfa7c`

## Purpose

MSVC scalar-deleting destructor (**vtbl[0]** of `0x009cfa7c`): invoke owning body dtor `FUN_0053b920`, optionally `operator_delete(this)` when `flags&1`, return `this` with **`ret 4`**.

## Signature

```c
// Machine: __thiscall, ECX=this, stack flags, ret 4; EAX=this
// Ghidra: void * __thiscall FUN_0053b900(void *param_1, byte param_2)
void *__thiscall CNDHash_scalar_dtor_009cfa7c(void *thisHash, unsigned char flags);
```

## Object / vtbl

| Item | Value | Conf |
|---|---|---|
| Vtbl | `PTR_FUN_009cfa7c` @ `0x009cfa7c` | **High** |
| Slot 0 | `0x0053b900` | **High** |
| Body dtor | `FUN_0053b920` / `CNDHash_Dtor_009cfa7c` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053b900_FUN_0053b900.md` (+ W25-H append)
- Annotated: `docs/reconstruction/raw/aa_0053b900_FUN_0053b900.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_scalar_dtor_009cfa7c.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0053b900.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0053b900_FUN_0053b900.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0053e510-0053b900-w25h-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Dispatch** | vtbl `0x009cfa7c`[0] only (DATA xref; no direct CALL sites) |
| **Callees** | `FUN_0053b920` (body), `operator_delete` |

## Confidence

| Claim | Level |
|---|---|
| Scalar dtor CF + ret 4 + flags&1 | **High** |
| vtbl[0] of `009cfa7c` | **High** |
| Always runs owning body dtor first | **High** |
| Product mangled name | **Open** |
| Runtime / bit-exact | Open |

## Related

- `aa_0053b920` CNDHash_Dtor_009cfa7c (W24-M)
- `aa_0059c8a0` FreelistSlabVector_dtor (W24-M)
- Sibling pattern: `aa_00537d10` CNDHashNode_NonOwning_scalar_dtor_Inferred
