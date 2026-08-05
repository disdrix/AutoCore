# Raw capture: FUN_0068aee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068aee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068aee0` |
| **Canonical name** | `FUN_0068aee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0068aee0(int param_1,uint *param_2)

{
  void *pvVar1;
  int iVar2;
  float10 fVar3;
  int local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_a0 [40];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_78 [28];
  undefined1 local_5c [40];
  undefined1 local_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009aa2bf;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 4) = 0;
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
  }
  local_4 = 0xffffffff;
  *(void **)(param_1 + 0x54) = pvVar1;
  iVar2 = FUN_00699ee0();
  while( true ) {
    local_c8 = 0;
    local_bc = 0.0;
    local_c0 = 0.0;
    local_c4 = 0.0;
    local_b0 = 0.0;
    local_b4 = 0.0;
    local_b8 = 0.0;
    if (iVar2 == 0x2ee2) {
      iVar2 = 0;
    }
    else if (iVar2 == 0x2ee3) {
      iVar2 = 1;
    }
    else {
      if (iVar2 != 0x2ee4) {
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &local_c8,"malformed collision object info");
        local_4 = 1;
        FUN_006874b0(&local_c8,0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_a0,(ThrowInfo *)&DAT_00ac9e00);
      }
      iVar2 = 2;
    }
    local_c8 = iVar2;
    fVar3 = (float10)FUN_00699ed0();
    local_ac = (float)fVar3;
    fVar3 = (float10)FUN_00699ed0();
    local_a8 = (float)fVar3;
    fVar3 = (float10)FUN_00699ed0();
    local_c4 = -local_ac;
    local_bc = local_a8;
    local_c0 = (float)fVar3;
    if (iVar2 == 0) {
      fVar3 = (float10)FUN_00699ed0();
      local_b8 = (float)fVar3;
    }
    else if (iVar2 == 1) {
      fVar3 = (float10)FUN_00699ed0();
      local_b8 = (float)fVar3;
      fVar3 = (float10)FUN_00699ed0();
      local_b4 = (float)fVar3;
    }
    else {
      if (iVar2 != 2) {
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  (local_a0,"unknown collision object type");
        local_4 = 2;
        FUN_006874b0(local_a0,0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_5c,(ThrowInfo *)&DAT_00ac9e00);
      }
      fVar3 = (float10)FUN_00699ed0();
      local_b8 = (float)fVar3;
      fVar3 = (float10)FUN_00699ed0();
      local_b4 = (float)fVar3;
      fVar3 = (float10)FUN_00699ed0();
      local_b0 = (float)fVar3;
    }
    FUN_0068ae50(&local_c8);
    if ((param_2[2] == 0) || (param_2[3] - param_2[2] <= *param_2)) break;
    iVar2 = FUN_00699ee0();
    if (iVar2 == 0x2ee1) {
      ExceptionList = local_c;
      return;
    }
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            (local_78,"premature end of file reached parsing collision object info");
  local_4 = 3;
  FUN_006874b0(local_78,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);
}
```
