# Raw capture: FUN_004fabc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fabc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fabc0` |
| **Canonical name** | `FUN_004fabc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __thiscall FUN_004fabc0(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_2 == (int *)0x0) {
    return 8;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  param_2[0x5f] = param_2[0x5f] | 0x10;
  FUN_00512670();
  if (((uint)param_2[0x5f] >> 0x13 & 1) != 0) {
    return 9;
  }
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0xf6) != '\0')) {
    return 0xf;
  }
  uVar5 = 0;
  uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0,1);
  cVar2 = FUN_00514390(uVar3,uVar5);
  if (cVar2 != '\0') {
    switch(*(undefined4 *)(param_2[0x2a] + 0x38)) {
    case 6:
      uVar3 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                              &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0,
                              param_3);
      uVar4 = FUN_004f6940(uVar3,param_3);
      return uVar4;
    default:
      return 8;
    case 8:
    case 0x32:
      return 0xc;
    case 10:
      uVar3 = (**(code **)(*param_2 + 500))(param_3);
      uVar4 = FUN_004f6840(uVar3,param_3);
      return uVar4;
    case 0xc:
      uVar3 = (**(code **)(*param_2 + 0x1e0))(param_3);
      uVar4 = FUN_004f65e0(uVar3,param_3);
      return uVar4;
    case 0xe:
      goto switchD_004fac7b_caseD_e;
    case 0x10:
      uVar3 = (**(code **)(*param_2 + 0x1f0))(param_3);
      uVar4 = FUN_004f6890(uVar3,param_3);
      return uVar4;
    case 0x1c:
      uVar3 = (**(code **)(*param_2 + 0x1f8))(param_3);
      uVar4 = FUN_004f67e0(uVar3,param_3);
      return uVar4;
    }
  }
  return 6;
switchD_004fac7b_caseD_e:
  cVar2 = FUN_004ce5f0(param_1);
  if (cVar2 == '\0') {
    return 1;
  }
  cVar2 = FUN_004f6560();
  return -(uint)(cVar2 != '\0') & 0xe;
}
```

---

## Live re-decompile (2026-07-29 W17-E dual)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Integrity** | Append-only; body below ≡ authoritative 2026-07-23 raw |
| **Canonical (dual)** | `Character_TryEquipItem` — Broken gate code **9** / flag **`\|0x10`** sealed |
| **Body** | `0x004fabc0` … `0x004fad57` (`ret 8` / `c2 08 00`) |

```c
uint __thiscall FUN_004fabc0(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_2 == (int *)0x0) {
    return 8;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  param_2[0x5f] = param_2[0x5f] | 0x10;
  FUN_00512670();
  if (((uint)param_2[0x5f] >> 0x13 & 1) != 0) {
    return 9;
  }
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0xf6) != '\0')) {
    return 0xf;
  }
  uVar5 = 0;
  uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0,1);
  cVar2 = FUN_00514390(uVar3,uVar5);
  if (cVar2 != '\0') {
    switch(*(undefined4 *)(param_2[0x2a] + 0x38)) {
    case 6:
      uVar3 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                              &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0,
                              param_3);
      uVar4 = FUN_004f6940(uVar3,param_3);
      return uVar4;
    default:
      return 8;
    case 8:
    case 0x32:
      return 0xc;
    case 10:
      uVar3 = (**(code **)(*param_2 + 500))(param_3);
      uVar4 = FUN_004f6840(uVar3,param_3);
      return uVar4;
    case 0xc:
      uVar3 = (**(code **)(*param_2 + 0x1e0))(param_3);
      uVar4 = FUN_004f65e0(uVar3,param_3);
      return uVar4;
    case 0xe:
      goto switchD_004fac7b_caseD_e;
    case 0x10:
      uVar3 = (**(code **)(*param_2 + 0x1f0))(param_3);
      uVar4 = FUN_004f6890(uVar3,param_3);
      return uVar4;
    case 0x1c:
      uVar3 = (**(code **)(*param_2 + 0x1f8))(param_3);
      uVar4 = FUN_004f67e0(uVar3,param_3);
      return uVar4;
    }
  }
  return 6;
switchD_004fac7b_caseD_e:
  cVar2 = FUN_004ce5f0(param_1);
  if (cVar2 == '\0') {
    return 1;
  }
  cVar2 = FUN_004f6560();
  return -(uint)(cVar2 != '\0') & 0xe;
}
```

### Bytes (`read_memory` @ `0x004fabc0` + continuation + tables)

Prologue / gates:

```
56 8b 74 24 08 85 f6 57 8b f9 75 0a 5f b8 08 00 00 00 5e c2 08 00
53 8b 5c 24 14 85 db 74 06 c7 03 00 00 00 00
83 8e 7c 01 00 00 10          ; or dword [esi+0x17c], 0x10
8b ce e8 7d 7a 01 00          ; call FUN_00512670  (004FABEE → 00512670)
8b 86 7c 01 00 00 c1 e8 13 a8 01  ; (flags>>19)&1  = ItemFlag_Broken
74 0b 5b 5f b8 09 00 00 00 5e c2 08 00   ; return 9 if Broken
... b8 0f 00 00 00 ... c2 08 00         ; return 0xf (session +0xf6)
... b8 06 00 00 00 ... c2 08 00         ; return 6 (precheck fail)
```

Switch tables (in body through `0x004fad57`):

| Table | VA | Role |
|-------|-----|------|
| Jump dwords | `0x004fad58` | 8 targets for indices 0..7 |
| Index bytes | `0x004fad78` | map `(type-6)` → jump index; **7** = default |

Sealed case map (`*(item[0x2a]+0x38)` = clonebase type):

| Type | Jump idx | Target | Effect |
|-----:|---------:|--------|--------|
| 6 | 0 | `0x004FACE6` | RTDynamicCast → `FUN_004f6940` |
| 8, 0x32 | 1 | `0x004FAD42` | **return 0xc** |
| 10 | 2 | `0x004FACB4` | vtbl `+0x1f4` → `FUN_004f6840` |
| 0xc | 3 | `0x004FAC82` | vtbl `+0x1e0` → `FUN_004f65e0` |
| 0xe | 4 | `0x004FAD0C` | vehicle path `FUN_004ce5f0` / `FUN_004f6560` |
| 0x10 | 5 | `0x004FACCD` | vtbl `+0x1f0` → `FUN_004f6890` |
| 0x1c | 6 | `0x004FAC9B` | vtbl `+0x1f8` → `FUN_004f67e0` |
| other (idx 7) | 7 | `0x004FAD4D` | **return 8** |

- Imm flag OR: `83 8e 7c 01 00 00 10` → **`item+0x17c \|= 0x10`**
- Broken test: `c1 e8 13` + `a8 01` → bit **19** / mask **`0x80000`**
- Stack cleanup: **`c2 08 00`** → **`ret 8`** (two stack args: item, optional out)
