# Raw capture: FUN_004c7bd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c7bd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c7bd0` |
| **Canonical name** | `FUN_004c7bd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c7bd0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined1 local_20 [28];
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_004e8a40(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30,&local_40);
    iVar4 = _finite((double)local_40);
    if (iVar4 != 0) {
      iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1);
      if (((iVar4 == 0) || ((*(uint *)(iVar4 + 0x17c) >> 5 & 1) == 0)) ||
         (iVar4 = __RTDynamicCast(iVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                  &CVOGPhysicsBase::RTTI_Type_Descriptor,0),
         *(int *)(iVar4 + 8) == 0)) {
        local_24 = *(undefined4 *)(param_1 + 0x114);
        if (((*(uint *)(param_1 + 0x108) & *(uint *)(param_1 + 0x10c)) == 0xffffffff) &&
           ((char)*(undefined4 *)(param_1 + 0x110) == '\0')) {
          return;
        }
        pfVar5 = (float *)FUN_004e9530(&local_30,
                                       *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8
                                                        + param_1) + 0xe894) + 0x11c);
        local_30 = *pfVar5;
        local_28 = pfVar5[2];
      }
      else {
        __RTDynamicCast(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1),0,
                        &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                        &CVOGPhysicsBase::RTTI_Type_Descriptor,0);
        pfVar5 = (float *)FUN_00404c90();
        local_30 = local_40 + *pfVar5;
        local_28 = local_38 + pfVar5[2];
      }
      iVar4 = *(int *)(param_1 + 8);
      if (iVar4 == 0) {
        pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);
      }
      else {
        pfVar5 = (float *)(*(int *)(iVar4 + 0x3c) + 0xb0);
      }
      local_30 = local_30 - *pfVar5;
      local_28 = local_28 - pfVar5[2];
      fVar8 = local_28 * local_28 + local_30 * local_30;
      if (DAT_009cb8d4 < SQRT(fVar8)) {
        if (fVar8 == 0.0) {
          local_2c = 0.0;
        }
        else {
          local_2c = g_flOne / SQRT(fVar8);
        }
        local_28 = local_28 * local_2c;
        local_48 = *(float *)(param_1 + 0x11c);
        local_30 = local_2c * local_30;
        local_2c = local_2c * 0.0;
        fVar6 = (float10)FUN_0040d0a0();
        fVar8 = (float)fVar6;
        if (iVar4 == 0) {
          iVar4 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1;
        }
        else {
          iVar4 = *(int *)(iVar4 + 0x3c) + 0x30;
        }
        FUN_004e8ad0(iVar4,local_20);
        if (local_38 * 0.0 + local_3c * 0.0 + local_40 < 0.0) {
          fVar8 = DAT_00aaa7dc - fVar8;
        }
        local_48 = fVar8 + local_48;
        if (DAT_00aaa7dc < local_48) {
          local_48 = local_48 - DAT_00aaa7dc;
        }
        if (local_48 < 0.0) {
          local_48 = local_48 + DAT_00aaa7dc;
        }
        fVar6 = (float10)fsin((float10)local_48);
        fVar1 = (float)fVar6;
        fVar6 = (float10)fcos((float10)local_48);
        fVar2 = (float)fVar6;
        fVar7 = fVar2 * fVar2 + fVar1 * fVar1;
        if (fVar7 == 0.0) {
          fVar7 = 0.0;
        }
        else {
          fVar7 = g_flOne / SQRT(fVar7);
        }
        fVar9 = fVar2 * fVar7 * local_28 + fVar7 * 0.0 * local_2c + fVar7 * fVar1 * local_30;
        if (fVar9 < (float)_DAT_009cbab8) {
          fVar3 = (float)param_2;
          if (param_2 < 0) {
            fVar3 = fVar3 + _DAT_00aaa5dc;
          }
          fVar9 = (g_flOne - fVar9) * fVar3 * g_flMsToSeconds_Inferred * _DAT_009cbab0;
          if (0.0 <= local_28 * fVar7 * fVar1 - fVar2 * fVar7 * local_30) {
            fVar9 = local_48 - fVar9;
          }
          else {
            fVar9 = fVar9 + local_48;
          }
          fVar9 = fVar9 - fVar8;
          if (DAT_00aaa7dc < fVar9) {
            fVar9 = fVar9 - DAT_00aaa7dc;
          }
          if (fVar9 < 0.0) {
            fVar9 = fVar9 + DAT_00aaa7dc;
          }
          *(float *)(param_1 + 0x11c) = fVar9;
        }
      }
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
| **Body range** | `0x004c7bd0`–`0x004c7fc1` (inclusive `RET 4`; size **1010** B / `0x3F2`) |
| **ABI** | MSVC `__thiscall`; `ECX` = creature/object*; stack `int deltaMs`; epilogue **`RET 4`** (`C2 04 00`); void |
| **Canonical name** | `CVOGCreature_SlewFacingYaw_Inferred` |
| **Ghidra name** | `FUN_004c7bd0` |
| **System** | creature / facing / aim |

### Callers (xrefs, sealed)

| Site | Function | Role |
|---|---|---|
| `0x004c8e49` | `CVOGCreature_SetupGraphics` | initial / setup slew |
| `0x005d6bf7` | `FUN_005d6b80` (HB ctor; zeroes target `+0x11c`, pushes period `0x1e`) | ctor initial update |
| `0x005d6c21` | `FUN_005d6c10` (HB tick; passes `nPeriodMs`) | periodic slew |

### Callees

`FUN_004e8a40`, `_finite`, `__RTDynamicCast`, `FUN_004e9530`, `FUN_00404c90`, `FUN_0040d0a0` (`Math_AcosClamped`), `FUN_004e8ad0` (`Quat_ExtractRight_Inferred` family), CRT `fsin`/`fcos`/`SQRT`.

### Constants (`read_memory`)

| Symbol | VA | Bytes | Value |
|---|---|---|---|
| `DAT_009cb8d4` | `0x009cb8d4` | `00 00 00 34` | **1.1920929e-7f** (dist epsilon) |
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0f** |
| `DAT_00aaa7dc` | `0x00aaa7dc` | `da 0f c9 40` | **≈6.283185f** (`2π`) |
| `DAT_00aaa668` | `0x00aaa668` | `00 00 80 bf` | **-1.0f** |
| `_DAT_009cbab8` | `0x009cbab8` | `2b 87 16 d9 ce f7 ef 3f` | double **0.999** (align threshold) |
| `_DAT_009cbab0` | `0x009cbab0` | `9a 99 19 41` | **9.6f** (yaw rate scale) |
| `g_flMsToSeconds_Inferred` | `0x00a0f72c` | `6f 12 83 3a` | **≈0.001f** |
| `_DAT_00aaa5dc` | `0x00aaa5dc` | `00 00 80 4f` | **4294967296.0f** (`2^32` uint→float bias) |

### Machine notes

- Prologue: `55 8B EC 83 E4 F0 83 EC 38 56 8B F1` — frame + 16-byte align + `mov esi,ecx`.
- Epilogue: `5F 5E 8B E5 5D C2 04 00` — `ret 4`.
- Writes **only** `*(float*)(this+0x11c)` (facing/yaw radians residual).
- Early outs: `this+8==0`; non-finite pose X; invalid aim TFID mask (`(+0x108)&(+0x10c)==~0` and `+0x110` low byte 0); horizontal dist ≤ epsilon; alignment ≥ 0.999.
- `param_2` treated as signed int then float; if `<0` add `2^32` before rate (unsigned ms reinterpret).

### This / fields

| Offset | Role | Conf |
|---|---|---|
| `this+0x08` | graphics/phys host ptr (required) | **High** |
| `this+0x11c` | facing yaw float (read/write) | **High** |
| `this+0x108/10c/110/114` | aim target id / validity | **Medium** |
| host `+0x3c+0x30` | pose extract via `FUN_004e8a40` | **High** |
| host `+0x3c+0xb0` | self position for delta | **High** |

