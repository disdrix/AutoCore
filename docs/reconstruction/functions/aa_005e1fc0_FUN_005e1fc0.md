# Function record: FUN_005e1fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1fc0` |
| **Canonical name** | `Object_FwriteColorFields_Inferred` |
| **Ghidra name** | `FUN_005e1fc0` |
| **Address** | `0x005e1fc0`–`0x005e203c` (124 B / `0x7C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object stream serialize (color extension) |
| **Completion status** | **Dual complete (W29-J)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

FILE-stream serialize extension: base object writer, then raw `+0x170` and two packed float4 colors at `+0x174` / `+0x184`.

## Signature (sealed)

```c
void __thiscall Object_FwriteColorFields_Inferred(Object *self, FILE *stream);
// epilogue: ret 4
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_005e1fc0_Object_FwriteColorFields_Inferred.md`
- Raw: `docs/reconstruction/raw/aa_005e1fc0_FUN_005e1fc0.md`
- Annotated: `docs/reconstruction/raw/aa_005e1fc0_FUN_005e1fc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_FwriteColorFields_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005e1fc0.cpp`
- A: `docs/reconstruction/reviews/A_aa_005e1fc0_Object_FwriteColorFields_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_005e1fc0_Object_FwriteColorFields_Inferred.md`
- Report: `docs/agents/task-dual-ab-005e1fc0-008e4430-w29j-report.md`

## Callers / callees

| | |
|---|---|
| Callees | `thunk_FUN_005a61d0`, `fwrite`, `FUN_00973820` ×2 |
| Code callers | none |
| Data | vtable `@ 0x009dc8e8` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **Confirmed** |
| Field offsets | **Confirmed** |
| Product class name | Open |
| Types beyond stream layout | Tentative |
