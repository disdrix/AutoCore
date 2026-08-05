# Function record: Host_ResetHashQueuesVectors_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbeb0` |
| **Canonical name** | `Host_ResetHashQueuesVectors_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_004bbeb0` |
| **Address** | `0x004bbeb0` |
| **Body** | `0x004bbeb0`–`0x004bbf18` exclusive (**104 B** / `0x68`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host reset: CNDHash Recreate + locked-queue drain + dword vector clear |
| **Completion status** | **Dual-reviewed** W31-N — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Reset a host object's table state: recreate CNDHash tableC (`009cb450`, log2=5) via pointer at `+0x18`, drain three locked-list hosts at `+0x1c/+0x20/+0x24`, clear three embedded dword vectors at `+0x48/+0x28/+0x38`, then optionally call/tail-call `vtbl[+4]` on ifaces at `+0x04/+0x08` gated by flags `+0x0c/+0x0d`.

## Signature

```c
// ECX = host. Bare RET. void.
void __fastcall Host_ResetHashQueuesVectors_Inferred(Host_ResetTables* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004d98f0` @ `0x004d9a61`; `FUN_00943b80` @ `0x00943d72` |
| Callees | `CNDHash_Recreate_009cb450` (`0x004bcce0`), `FUN_004bc580`×3, `FUN_00410420`×3; conditional vtbl[+4] |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bbeb0_FUN_004bbeb0.md`
- Annotated: `docs/reconstruction/raw/aa_004bbeb0_FUN_004bbeb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host_ResetHashQueuesVectors_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004bbeb0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_004bbeb0_FUN_004bbeb0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + bare RET | **High** |
| Per-callee ECX targets (hash/queues/vectors) | **High** (bytes) |
| Tail JMP on flag+0x0d | **High** |
| Recreate log2=5 always | **High** |
| Product host class English | **Low** |
| Queue/vector domain English | **Low** |

## Rejected plates

- `Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_004bbeb0` (scaffold chain; no product evidence).
