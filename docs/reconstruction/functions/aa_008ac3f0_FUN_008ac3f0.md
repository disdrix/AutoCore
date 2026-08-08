# Function record: FUN_008ac3f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac3f0` |
| **Canonical name** | `FUN_008ac3f0` (Ghidra) |
| **Meaningful name** | `Client_NpcMissionDialogHost_Ctor_Inferred` |
| **Address** | `0x008ac3f0`–`0x008ac53f` (**336 B** / `0x150`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | Stack `this*`; body uses **EDI**; **`RET 4`**; **EAX = this** |
| **Completion status** | **Dual A/B sealed** (MEGA-107 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `Client_NpcMissionDialogHost_Ctor_Inferred` (preferred)
- `Mission_i_d_npc_xml_008ac3f0` (**retired** string scaffold)

## Purpose

NPC mission dialog **host constructor**: base NDUI ctor, install vtable `0x00a4a51c`, default layout fields, zero mission-dialog pack, load `i_d_npc.xml`, build response buttons, virtual post-init. Hosted at **`client+0x1058`** after `operator_new(0x748)`.

## Signature

```c
// Stack this*; RET 4; EAX = this
int* FUN_008ac3f0(int* param_1);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ac3f0_FUN_008ac3f0.md`
- Annotated: `docs/reconstruction/raw/aa_008ac3f0_FUN_008ac3f0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialogHost_Ctor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_008ac3f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md`
- Named record: `docs/reconstruction/functions/aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md`
- Report: `docs/agents/task-dual-ab-008ac3f0-mega-107-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_0093e7e0` @ `0x0093f420` |
| Callees | `FUN_0087b890`, `FUN_008ab0a0`, `NDUIWindow_ReloadInterface` (`0x00792980`), `FUN_008ac110`, virtual `FUN_00791dc0` via `vtbl+0x34C` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / vtable / string | **High** |
| Host slot `client+0x1058` / size `0x748` | **High** |
| Parameter product English | **Inferred** |
| Runtime / bit-exact | Open |
