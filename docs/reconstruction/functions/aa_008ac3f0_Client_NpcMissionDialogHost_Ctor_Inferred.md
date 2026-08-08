# Function record: Client_NpcMissionDialogHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac3f0` |
| **Canonical name** | `Client_NpcMissionDialogHost_Ctor_Inferred` |
| **Prior FUN_ name** | `FUN_008ac3f0` |
| **Address** | `0x008ac3f0`–`0x008ac53f` (**336 B** / `0x150`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | Stack `this*`; **EDI** working this; **`RET 4`**; **EAX = this** |
| **Completion status** | **Dual A/B sealed** (MEGA-107 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_008ac3f0` | Ghidra machine name |
| `Mission_i_d_npc_xml_008ac3f0` | **Retired** (string-only scaffold) |
| `Client_NpcMissionDialogHost_Ctor_Inferred` | **Preferred** (`_Inferred` — product PDB open) |

## Purpose

Construct the **client NPC mission dialog host** later referenced as `client+0x1058` (dialog table index **10** from `+0x1030`). This is the object whose vtable **`0x00a4a51c`** carries:

| Vtbl offset | Target | Role |
|---|---|---|
| `+0x34C` | `FUN_00791dc0` | post-XML virtual (called at end of this ctor) |
| `+0x43C` | `Client_BuildNpcMissionDialogWidgets` | full widget tree / `+0x650` zero |
| `+0x440` | `Client_MissionDialog_FlushPreparedResponse` | C2S 0x206E send site |

Ctor itself: base `FUN_0087b890(self,0)` → install vtbl → default transform/columns/mode → `FUN_008ab0a0` field pack → load **`i_d_npc.xml`** → `UI_MissionDialog_BuildResponseButtons_Inferred` → virtual `+0x34C`.

## Signature

```c
// Stack this*; RET 4; EAX = this
NpcMissionDialogHost* Client_NpcMissionDialogHost_Ctor_Inferred(
    NpcMissionDialogHost* self);
```

## Object / allocation

| Item | Value |
|---|---|
| Alloc size | **`0x748`** (`operator_new` in `FUN_0093e7e0`) |
| Host field | **`client+0x1058`** |
| Table index | `(0x1058 - 0x1030) / 4 = 10` |
| Vtable | **`0x00a4a51c`** |
| Skin XML | **`i_d_npc.xml`** @ `0x00a4b0e0` |

## Key field defaults (this ctor)

| Offset | Value | Notes |
|---|---|---|
| `+0x000` | vtbl `0x00a4a51c` | class |
| `+0x4FC` | `0x0C` | chrome / type id |
| `+0x500` | `1` | flag |
| `+0x584..+0x5B0` | 3×`(0,0,0,1)` f32 | UI basis (`g_flOne`) |
| `+0x63C` | `1` | layout flag |
| `+0x640` | `1` | response **columns** |
| `+0x648` | `0` | layout **mode** |
| `+0x580` | byte `0` | also cleared in BuildWidgets |

## Call graph

| Role | Symbol | Address |
|---|---|---|
| Sole caller | `FUN_0093e7e0` | call site `0x0093f420` |
| Base ctor | `FUN_0087b890` | `0x0087b890` |
| Field zero pack | `FUN_008ab0a0` | `0x008ab0a0` |
| Reload skin | `NDUIWindow_ReloadInterface` | `0x00792980` |
| Response strip | `UI_MissionDialog_BuildResponseButtons_Inferred` | `0x008ac110` |
| Post-XML virtual | `FUN_00791dc0` | via `vtbl+0x34C` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Body envelope / CF | **High** | live decompile ≡ raw; 1 BB |
| ABI stack-this / RET 4 | **High** | `read_memory` prologue/epilogue |
| Vtable + string | **High** | imm + memory |
| Host slot / alloc size | **High** | caller decompile + prior Flush seal |
| Columns/mode defaults | **High** | bytes + peer dual `008ac110` |
| Product class English | **Inferred** | no PDB |
| Virtual `00791dc0` body | Open (not OWN) | slot sealed only |
| Runtime / bit-exact | Open | no Launcher |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ac3f0_FUN_008ac3f0.md`
- Annotated: `docs/reconstruction/raw/aa_008ac3f0_FUN_008ac3f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialogHost_Ctor_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008ac3f0.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md`, `B_aa_008ac3f0_…`
- FUN record: `docs/reconstruction/functions/aa_008ac3f0_FUN_008ac3f0.md`
- Report: `docs/agents/task-dual-ab-008ac3f0-mega-107-report.md`

## Open questions

- Product / PDB class name for `0x00a4a51c`.
- Semantics of `FUN_00791dc0` and full `FUN_008ab0a0` field English (non-OWN).
- Runtime lifetime vs HideMissionDialogIfOpen on `client+0x107c`.
