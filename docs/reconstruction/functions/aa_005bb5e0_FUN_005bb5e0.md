# Function record: FUN_005bb5e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bb5e0` |
| **Canonical name** | `FUN_005bb5e0` |
| **Preferred inferred** | `ObjectMotion_SlotListTick_Inferred` |
| **Address** | `0x005bb5e0` |
| **Body span** | `005bb5e0`–`005bb666` (134 B / `0x86`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction slot list |
| **Completion status** | **dual-sealed** 2026-07-29 W27-D |
| **Dual A/B** | `reviews/A_aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md`, `reviews/B_aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md` |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Preferred: `ObjectMotion_SlotListTick_Inferred`
- **Rejected:** `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_005bb5e0`

## Purpose

Walk motion host list `+0xA24`, tick slots via `ObjectMotion_SlotTick_Inferred`, remove on 0 (unlink + delete + count--), return remaining count.

## Signature (decompiler-derived)

```c
undefined4 __thiscall FUN_005bb5e0(int param_1, undefined4 *param_2, undefined4 param_3);
// ret 8; EAX = *(host+0xA28)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005bb5e0_FUN_005bb5e0.md`
- Annotated: `docs/reconstruction/raw/aa_005bb5e0_FUN_005bb5e0.annotated.md`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005bb5e0.cpp`
- Named: `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotListTick_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `0x004b8ed0` @ `0x004b9103` | HostTick; ECX = `+0x1E0` payload |
| Callee | `0x004b4620` | SlotTick (sole dualed outer caller) |
| Callee | `0x005be2b0` | payload teardown on remove |
| Callee | `operator_delete` | list node free |

## Confidence

| Claim | Level |
|---|---|
| Control flow (walk/tick/unlink) | **High** |
| ABI ret 8 | **Confirmed** |
| Count-- on remove (bytes) | **Confirmed** |
| Product name | **Inferred** |
| Runtime | **Open** |
