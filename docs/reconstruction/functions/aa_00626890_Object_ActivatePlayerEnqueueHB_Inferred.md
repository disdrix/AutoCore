# Function record: Object_ActivatePlayerEnqueueHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626890` |
| **Canonical name** | `Object_ActivatePlayerEnqueueHB_Inferred` |
| **Ghidra name** | `FUN_00626890` |
| **Address** | `0x00626890`–`0x00626a46` (**438 B / `0x1B6`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / player bind / CVOGHB activate |
| **Completion status** | **Dual-sealed 2026-07-29 W27-F** — raw append + annotated + clean + A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Host vtable activate path: bind local player, apply TFID/phys mode rebind, set selected target, construct and start a CVOGHB action stored at `host+0x6c4`, always fire-tail via `FUN_00578b30`.

## Signature (sealed)

```c
// thiscall; SEH; plain RET; void
void Object_ActivatePlayerEnqueueHB_Inferred(int host);
```

## Control flow

See `aa_00626890_FUN_00626890.md` (same seal).

## Callers / callees

| Dir | Symbol | Notes |
|---|---|---|
| Caller | vtable `@ 0x009d1ba8` | no direct CALL xrefs |
| Callee | `Object_SetTFID_ApplyPhysMode_Rebind` | W26-F sealed; sole caller |
| Callee | `Object_SetSelectedTarget` / HB Start / Enqueue | named peers |
| Callee | `FUN_006264e0` | 0x2c action ctor (OPEN English) |

## Artifacts

- Raw / annotated / clean / twin / A/B — see twin FUN record.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / TFID / HB chain | **High** |
| Product name | **Inferred** |
| Runtime | **Open** |
