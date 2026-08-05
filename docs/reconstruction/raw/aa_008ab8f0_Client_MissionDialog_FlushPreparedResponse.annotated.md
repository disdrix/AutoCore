# Annotated low-level: Client_MissionDialog_FlushPreparedResponse (`aa_008ab8f0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab8f0` |
| **VA** | `0x008ab8f0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |

## 1. Corrected signature

```c
// thiscall: ECX = mission dialog UI object
void __thiscall Client_MissionDialog_FlushPreparedResponse(MissionDialogUi* this);
```

| Name | Width | Role |
|---|---|---|
| `this` / `param_1` | 32-bit ptr | Mission dialog UI |
| `param_1[0x194]` | **u32** | Same as `*(u32*)(this + 0x650)` — prepared packet opcode head |
| send size | **0x20** | Immediate |

## 2. Decompiler corrections

| Decompiler | Correction | Confidence |
|---|---|---|
| `param_1[0x194]` | `*(u32*)(dialog + 0x650)` | **High** (asm) |
| `g_pSectorNetConnection_INFERRED` | `DAT_00d1b4b8` | **High** (asm) |
| Send is "optional cleanup" | **Primary C2S 0x206E flush** when opcode prepared | **High** |
| No opcode literal in body | Opcode pre-written by Prepare as **0x206E** | **High** |

## 3. Side-effect order

1. If prepared opcode non-zero and connection non-null → sector send **0x20** bytes from `+0x650`.
2. Optional reward-cursor UI hide if `DAT_00d1d8dc` visible and matches reward COID slots.
3. `FUN_008aa320` cleanup helper.
4. Vtable `+0x3ac` on dialog.
5. `FUN_00792490` base teardown.

## 4. Relationship to HandleButton

HandleButton **never** calls `Client_SendSectorPacket` with 0x206E. It fills `+0x654..` then returns; dialog teardown invokes this flush (vtable).

## 5. Open residual

- Precise event that dispatches the vtable slot.
- Whether failed prepare / cancel paths clear `+0x650` before flush.
