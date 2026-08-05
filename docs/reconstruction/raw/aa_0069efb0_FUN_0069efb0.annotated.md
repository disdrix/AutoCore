# Annotated low-level: FUN_0069efb0

| Field | Value |
|---|---|
| Stable ID | `aa_0069efb0` |
| VA | `0x0069efb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0069efb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0069efb0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  undefined4 *puVar5;
  int iVar6;
  float10 fVar7;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_13c [28];
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_fc [76];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_b0 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_78 [28];
  undefined1 local_5c [40];
  undefined1 local_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009aaf86;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00699ee0();
  do {
    if (iVar1 < 0xbbe) {
      if (iVar1 != 0xbbd) {
        if (iVar1 < 0xbbb) {
          if (iVar1 == 0xbba) {
            fVar7 = (float10)FUN_00699ed0();
            *(float *)(param_1 + 0x24) = (float)fVar7;
          }
          else if (iVar1 == 0x3f1) {
            FUN_00699ee0();
            iVar1 = FUN_00699ee0();
            FUN_00698980();
            FUN_0069e8d0();
            FUN_0069eed0(iVar1);
            iVar6 = 0;
            if (0 < iVar1) {
              do {
                FUN_0069e8d0();
                local_4 = 0;
                FUN_00699ee0();
                iVar3 = FUN_00699ee0();
                do {
                  switch(iVar3) {
                  case 4000:
                    *param_2 = *param_2 + 1;
                    break;
                  case 0xfa1:
                    FUN_00699fb0();
                    break;
                  case 0xfa2:
                    FUN_00699ed0();
                    break;
                  case 0xfa3:
                    FUN_00699f00();
                    FUN_00685ee0();
                    local_4._0_1_ = 1;
                    std::
                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                    operator=(local_13c,local_fc);
                    local_4._0_1_ = 0;
                    std::
                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              (local_fc);
                    pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              *)FUN_00685f40();
                    local_4._0_1_ = 2;
                    std::
                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                    operator=(local_13c,pbVar4);
                    local_4 = (uint)local_4._1_3_ << 8;
                    std::
                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              (local_94);
                    break;
                  case 0xfa4:
                    puVar5 = (undefined4 *)FUN_00699fb0();
                    local_120 = *puVar5;
                    local_11c = puVar5[1];
                    local_118 = puVar5[2];
                    break;
                  case 0xfa5:
                    puVar5 = (undefined4 *)FUN_00699fb0();
                    local_114 = *puVar5;
                    local_110 = puVar5[1];
                    local_10c = puVar5[2];
                    break;
                  case 0xfa6:
                    puVar5 = (undefined4 *)FUN_00699fb0();
                    local_108 = *puVar5;
                    local_104 = puVar5[1];
                    local_100 = puVar5[2];
                    break;
                  case 0xfa7:
                    FUN_00699ed0();
                    break;
                  default:
                    std::
                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              (local_b0,"malformed single leaf information");
                    local_4 = CONCAT31(local_4._1_3_,3);
                    FUN_006874b0();
                    /* WARNING: Subroutine does not return */
                    _CxxThrowException(local_5c,(ThrowInfo *)&DAT_00ac9e00);
                  }
                  iVar3 = FUN_00699ee0();
                } while (iVar3 != 0x3f0);
                FUN_00697300();
                local_4 = 0xffffffff;
                std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          (local_13c);
                iVar6 = iVar6 + 1;
              } while (iVar6 < iVar1);
            }
            FUN_00699ee0();
          }
          else if (iVar1 == 3000) {
            fVar7 = (float10)FUN_00699ed0();
            *(float *)(param_1 + 0x20) = (float)fVar7;
          }
          else {
            if (iVar1 != 0xbb9) goto switchD_0069f28a_default;
            uVar2 = FUN_00699ee0();
            *(undefined4 *)(param_1 + 0x28) = uVar2;
          }
          goto LAB_0069f2ce;
        }
        if (iVar1 == 0xbbb) goto switchD_0069f28a_caseD_bbe;
        if (iVar1 != 0xbbc) goto switchD_0069f28a_default;
      }
      FUN_00699ed0();
    }
    else {
      switch(iVar1) {
      case 0xbbe:
switchD_0069f28a_caseD_bbe:
        *param_2 = *param_2 + 1;
        break;
      case 0xbbf:
        fVar7 = (float10)FUN_00699ed0();
        *(float *)(param_1 + 0x1c) = (float)fVar7;
        break;
      case 0xbc0:
        uVar2 = FUN_00699ee0();
        *(undefined4 *)(param_1 + 8) = uVar2;
        break;
      case 0xbc1:
        iVar1 = *param_2;
        *param_2 = iVar1 + 1;
        *(bool *)param_1 = *(char *)(param_2[2] + iVar1) != '\0';
        break;
      case 0xbc2:
        fVar7 = (float10)FUN_00699ed0();
        *(float *)(param_1 + 4) = (float)fVar7;
        break;
      default:
switchD_0069f28a_default:
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_78,"malformed general leaf information");
        local_4 = 4;
        FUN_006874b0();
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);
      }
    }
LAB_0069f2ce:
    iVar1 = FUN_00699ee0();
    if (iVar1 == 0x3ed) {
      ExceptionList = local_c;
      return;
    }
  } while( true );
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
