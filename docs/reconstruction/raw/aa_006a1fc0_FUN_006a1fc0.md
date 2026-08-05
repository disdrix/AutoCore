# Raw capture: FUN_006a1fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a1fc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a1fc0` |
| **Canonical name** | `FUN_006a1fc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_006a1fc0(int *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  float10 fVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_78 [28];
  undefined1 local_5c [40];
  undefined1 local_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ab2c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x74);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_006a1cf0();
  }
  local_4 = 0xffffffff;
  iVar3 = FUN_00699ee0();
  if (iVar3 == 0x3f8) {
    iVar3 = FUN_00699ee0();
    do {
      switch(iVar3) {
      case 6000:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x14];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x14] = pvVar4;
        }
        break;
      case 0x1771:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x15];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x15] = pvVar4;
        }
        break;
      case 0x1772:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x16];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x16] = pvVar4;
        }
        break;
      case 0x1773:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x17];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x17] = pvVar4;
        }
        break;
      case 0x1774:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x18];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x18] = pvVar4;
        }
        break;
      case 0x1775:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x19];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x19] = pvVar4;
        }
        break;
      case 0x1776:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x1a];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x1a] = pvVar4;
        }
        break;
      case 0x1777:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x1b];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x1b] = pvVar4;
        }
        break;
      case 0x1778:
        uVar5 = FUN_00699ee0();
        *puVar2 = uVar5;
        break;
      case 0x1779:
        uVar5 = FUN_00699ee0();
        puVar2[1] = uVar5;
        break;
      case 0x177a:
        fVar6 = (float10)FUN_00699ed0();
        puVar2[2] = (float)fVar6;
        break;
      case 0x177b:
        fVar6 = (float10)FUN_00699ed0();
        puVar2[3] = (float)fVar6;
        break;
      case 0x177c:
        fVar6 = (float10)FUN_00699ed0();
        puVar2[4] = (float)fVar6;
        break;
      case 0x177d:
        fVar6 = (float10)FUN_00699ed0();
        puVar2[5] = (float)fVar6;
        break;
      case 0x177e:
        fVar6 = (float10)FUN_00699ed0();
        puVar2[6] = (float)fVar6;
        break;
      case 0x177f:
        iVar3 = *param_1;
        *param_1 = iVar3 + 1;
        *(bool *)(puVar2 + 7) = *(char *)(param_1[2] + iVar3) != '\0';
        break;
      case 0x1780:
        iVar3 = *param_1;
        *param_1 = iVar3 + 1;
        *(bool *)((int)puVar2 + 0x1d) = *(char *)(param_1[2] + iVar3) != '\0';
        break;
      case 0x1781:
        pvVar4 = (void *)FUN_006902a0();
        pvVar1 = (void *)puVar2[0x1c];
        if (pvVar1 != pvVar4) {
          if (pvVar1 != (void *)0x0) {
            FUN_006a1100();
                    /* WARNING: Subroutine does not return */
            operator_delete(pvVar1);
          }
          puVar2[0x1c] = pvVar4;
        }
        break;
      default:
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_94,"malformed general branch information");
        local_4 = 2;
        FUN_006874b0(local_94,0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);
      }
      iVar3 = FUN_00699ee0();
    } while (iVar3 != 0x3f9);
    ExceptionList = local_c;
    return puVar2;
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (local_78,"malformed branch data");
  local_4 = 1;
  FUN_006874b0(local_78,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_5c,(ThrowInfo *)&DAT_00ac9e00);
}
```
