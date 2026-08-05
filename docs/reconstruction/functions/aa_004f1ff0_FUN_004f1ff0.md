# Function record: FUN_004f1ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1ff0` |
| **Canonical name** | `Object_CollectAllGraphicsPreloads` (see named record) |
| **Ghidra name** | `FUN_004f1ff0` |
| **Address** | `0x004f1ff0` |
| **Body** | `0x004f1ff0`–`0x004f2531` exclusive (**1345 B** / `0x541`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object graphics preload collection |
| **Completion status** | **Dual-reviewed** W32-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Canonical: `Object_CollectAllGraphicsPreloads` (plate `"CollectAllGraphicsPreloads"`)
- Prior: `Named_CollectAllGraphicsPreloads`
- Rejected: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004f1ff0`

## Signature (sealed)

```c
// ECX = object host*; stack: param_2; RET 0x4; void
void __thiscall Object_CollectAllGraphicsPreloads(void* self, uint32_t param_2);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f1ff0_FUN_004f1ff0.md`
- Annotated: `docs/reconstruction/raw/aa_004f1ff0_FUN_004f1ff0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_CollectAllGraphicsPreloads.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004f1ff0.cpp`
- Named record: `docs/reconstruction/functions/aa_004f1ff0_Object_CollectAllGraphicsPreloads.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_004f1ff0_Object_CollectAllGraphicsPreloads.md` / `B_…`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004f2540` @ `0x004f25e6`; `FUN_004f26e0` @ `0x004f273e` |
| Callees | `FUN_0076cf00`/`FUN_0076cef0`, `FUN_007b6a20`/`FUN_007b6730`, `FUN_00989e00`, `FUN_0043d670`, `FUN_00404d70`, `FUN_004f1e20`, `FUN_004eb010`, `FUN_004eb3b0`, `FUN_004a04f0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompile ≡ live | **High** |
| ABI thiscall + RET 0x4 | **High** |
| Plate string product name | **High** |
| Suffix string constants | **High** |
| Type/kind product English | **Low** |
