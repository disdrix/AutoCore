# Function record: ClientSpecialEvent_Respawn_TeardownAirlift

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979290` |
| **Canonical name** | `ClientSpecialEvent_Respawn_TeardownAirlift` |
| **Ghidra name** | `FUN_00979290` |
| **Address** | `0x00979290` |
| **Body range** | `0x00979290`–`0x009792ff` (112 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client special-event / respawn (INC airlift) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + EDI ABI + parent duals sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00979290_ClientSpecialEvent_Respawn_TeardownAirlift.md`, `reviews/B_aa_00979290_ClientSpecialEvent_Respawn_TeardownAirlift.md` (2026-07-29 W23-I) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00979290`
- Parent notes: “destroy/detach airlift visual”
- Sibling setup: `ClientSpecialEvent_Respawn_SetupAirlift` @ `0x00979310`

## Purpose

Shared **airlift teardown** used by Update (phase 4→5) and dtor:

```
if this+0x38:
  obj = ResolveTfIdVtbl1d4(this+0x28)
  if obj:
    obj.vtbl+0x1bc(0)
    *(obj+8 + 0x28) = this+0x68
    FUN_00560e90(obj+8)
    if this+4 == 0: Vehicle_ActivateEnterWorld(obj)
  this+0x38 = 0
```

## Signature

```c
// EDI = ClientSpecialEvent_Respawn* this
void ClientSpecialEvent_Respawn_TeardownAirlift(void /*EDI this*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00979290_FUN_00979290.md`
- Annotated: `docs/reconstruction/raw/aa_00979290_FUN_00979290.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ClientSpecialEvent_Respawn_TeardownAirlift.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00979290.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00979290_FUN_00979290.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004baa30-00979290-w23i-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x00979730` | `ClientSpecialEvent_Respawn_Update` |
| Caller | `0x00979c70` | `ClientSpecialEvent_Respawn_dtor` |
| Callee | `0x004bb010` | `Object_ResolveTfIdVtbl1d4_Inferred` |
| Callee | `0x00560e90` | phys refresh helper |
| Callee | `0x00503f30` | `Vehicle_ActivateEnterWorld` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| EDI this ABI | **High** |
| Gate `+0x38` + clear | **High** |
| Callers Update + dtor | **High** |
| vtbl `+0x1bc` product name | **Open** |
| Event `+0x04` / `+0x68` product names | **Tentative** |
| Runtime / differential | Open |
