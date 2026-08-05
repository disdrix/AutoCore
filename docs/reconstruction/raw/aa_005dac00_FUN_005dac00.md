# Raw capture: FUN_005dac00

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dac00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dac00` |
| **Canonical name** | `FUN_005dac00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005dac00(int param_1)

{
  byte *pbVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    piVar4 = (int *)__RTDynamicCast(*(int *)(param_1 + 0x18),0,
                                    &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                    &CVOGPhysicsBase::RTTI_Type_Descriptor,0);
    if ((piVar4 != (int *)0x0) && (piVar4[2] != 0)) {
      FUN_004bcda0(*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x160),
                   *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x164),0);
      (**(code **)(**(int **)(param_1 + 0x18) + 0x2a4))
                (*(undefined4 *)((*(int **)(param_1 + 0x18))[0x29] + 0xe4e8));
      puVar5 = (undefined4 *)
               __RTDynamicCast(*(undefined4 *)(param_1 + 0x18),0,
                               &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                               &CVOGGraphicsBase::RTTI_Type_Descriptor,0);
      (**(code **)(*(int *)(*(int *)(puVar5[1] + 4) + 4 + (int)puVar5) + 0xfc))();
      FUN_004e88e0(&uStack_20,*(int *)(puVar5[1] + 4) + 0x84 + (int)puVar5);
      FUN_004e87d0(&uStack_14,*(int *)(puVar5[1] + 4) + 0x94 + (int)puVar5);
      (**(code **)*puVar5)
                (1,uStack_20,uStack_1c,uStack_18,uStack_14,uStack_10,uStack_c,uStack_8,
                 *(undefined1 *)((int)puVar5 + 0xd));
      (**(code **)(*(int *)((int)puVar5 + *(int *)(puVar5[1] + 4) + 4) + 0xb8))
                (*(undefined4 *)((int)puVar5 + *(int *)(puVar5[1] + 4) + 0xbc));
      (**(code **)(*(int *)(*(int *)(puVar5[1] + 4) + 4 + (int)puVar5) + 0x100))();
      (**(code **)(*piVar4 + 0x10))();
      FUN_00560e90(piVar4[2],1);
      pbVar1 = (byte *)(*(int *)(piVar4[1] + 4) + 0x181 + (int)piVar4);
      *pbVar1 = *pbVar1 & 0xfe;
      cVar3 = FUN_00418d10();
      if (cVar3 == '\0') {
        FUN_0053d970(0);
      }
      CVOGPhysics_ApplyImpulseVector(&DAT_00bc5670);
      FUN_0040d040(&DAT_00bc5670);
      iVar2 = *(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4);
      uVar6 = (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x244))();
      (**(code **)(iVar2 + 0x240))(uVar6);
      iVar2 = *(int *)(*(int *)(*(int *)(piVar4[1] + 4) + 0xac + (int)piVar4) + 0x38);
      if ((iVar2 != 0x12) && (iVar2 != 0x14)) {
        FUN_00516a00(1);
      }
      FUN_004cd540((int)piVar4 + *(int *)(piVar4[1] + 4) + 4,1);
    }
  }
  return;
}
```

---

## W22-J dual seal append (2026-07-29)

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W22-J |
| **Tool** | Ghidra MCP `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_xrefs` + `audit_globals_in_function` |
| **Disallowed** | `disassemble_bytes` (not used) |
| **Live decompile** | ≡ original raw body (same CF) |
| **Body range** | `0x005dac00`–`0x005dae45` (inclusive RET @ `0x005dae45`; 582 B) |
| **ABI** | MSVC `__thiscall` / `__fastcall` (ECX = this); plain `RET` (`C3`); void |
| **Canonical name** | `CVOGHBRecreateObject_RecreateOwner_Inferred` |
| **Ghidra name** | `FUN_005dac00` |
| **System** | combat / world-object lifecycle (recreate HB) |

### Callers (xrefs, sealed)

| Site | Function | Role |
|---|---|---|
| `0x005dafba` | `CVOGHBRecreateObject_OnHeartBeat` (`FUN_005dae50`) | recreate path when transform helper `local_12c == 0` |
| `0x004cd50c` | `FUN_004cd4e0` | after RTTI to `CVOGHBRecreateObject`; if `*flag != 0` |

### Callees (analyze_function_complete)

`__RTDynamicCast`, `FUN_004bcda0`, `FUN_004e88e0`, `FUN_004e87d0`, `FUN_00560e90`, `FUN_00418d10`, `FUN_0053d970` (`Object_SetPhysBodyTypeIfNotReady_Inferred`), `CVOGPhysics_ApplyImpulseVector`, `FUN_0040d040`, `FUN_00516a00`, `FUN_004cd540` + multiple owner/phys/gfx vcalls (`vtbl+0x2a4`, `+0xfc`, `*vtbl`, `+0xb8`, `+0x100`, phys `+0x10`, `+0x244`/`+0x240`).

### Machine notes (`read_memory`)

- Prologue: `83 EC 20 53 56 8B F1` — `sub esp,0x20; push ebx; push esi; mov esi,ecx`.
- Epilogue: `5F 5E 5B 83 C4 20 C3` — `pop edi/esi/ebx; add esp,0x20; ret`.
- RTTI: `CVOGClonedObjectBase` → `CVOGPhysicsBase` (`0x00af8e10`/`0x00af8dd0`); then → `CVOGGraphicsBase` (`0x00af8df0`).
- Impulse zero vec: `DAT_00bc5670` (12+ B BSS zero; live `read_memory` all zeros).
- Flag clear: `*(byte*)(phys_layout + 0x181) &= ~1` (`& 0xFE`).
- Body-type skip: if type at linked `+0x38` is **not** `0x12` and **not** `0x14` → `FUN_00516a00(1)`.
- Soft phys: if `FUN_00418d10()==0` → `FUN_0053d970(0)` (request type 1 when soft-not-ready).

### This / fields

| Offset | Role | Conf |
|---|---|---|
| `this+0x18` | owner object (`pOwnerObject`) | **High** (HB family) |
| owner `+0x160/+0x164` | args to `FUN_004bcda0` | Medium |
| owner `+0xa4` chain → `+0xe4e8` | vcall `+0x2a4` arg | Medium |
| phys `piVar4[2]` (`+0x8`) | phys body host; required non-null | **High** |
| phys flag `+0x181` bit0 | cleared before impulse | **High** |

