# Function record: RPC_rpcMsgGuaranteedOrdered_Execute

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2a50` |
| **Canonical name** | `RPC_rpcMsgGuaranteedOrdered_Execute` |
| **Address** | `0x005a2a50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | network-tnl-rpc |
| **Completion status** | **Reviewed dual A/B 2026-07-29** — body sealed; vtable class labels residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not required for pure type gate) |
| **Dual A** | `docs/reconstruction/reviews/A_aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` |
| **Dual B** | `docs/reconstruction/reviews/B_aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` |
| **Agent report** | `docs/agents/task-dual-ab-005a2a50-rpc-guaranteedordered-execute-report.md` |

## Purpose

TNL RPCEvent **Execute / CheckClassType**: return true iff the object is a **`TNLConnection`** via MSVC `__RTDynamicCast` from **`TNL::Object`**. Shared Execute slot body for all six `TNLConnection` message RPC NetEvent vtables (Guaranteed / GuaranteedOrdered / NonGuaranteed × plain/fragmented). Does not handle reliability, packing, or payload dispatch.

## Signature (sealed)

```c
/* stdcall, 1 stack arg, ret 4 */
bool RPC_rpcMsgGuaranteedOrdered_Execute(void /*TNL::Object*/ *obj);
```

Equivalent AutoCore:

```csharp
public override bool CheckClassType(object obj) { return (obj as TNLConnection) != null; }
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md`
- Annotated: `docs/reconstruction/raw/aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/RPC_rpcMsgGuaranteedOrdered_Execute.cpp`

## Callers / callees

| Direction | Detail |
|---|---|
| Code callers | **None** |
| DATA xrefs (Execute slots) | `0x009d7c84`, `0x009d7cb4`, `0x009d7ce4`, `0x009d7d14`, `0x009d7d44`, `0x009d7d74` (stride 0x30) |
| Callees | `__RTDynamicCast` only |

## Constants

| VA | Role |
|---|---|
| `0x00b00ba4` | `TNL::Object` RTTI TypeDescriptor (string `.?AVObject@TNL@@`) |
| `0x00af3a48` | `TNLConnection` RTTI TypeDescriptor (string `.?AVTNLConnection@@`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow / body bytes | **High** (sealed) |
| CheckClassType semantics | **High** (sealed) |
| ABI stdcall + bool | **High** (sealed) |
| Shared across 6 RPC event vtbls | **High** (sealed) |
| Per-slot class product names | Medium / residual |
| Symbol name = Ordered-only | **False** (name scaffold only) |
