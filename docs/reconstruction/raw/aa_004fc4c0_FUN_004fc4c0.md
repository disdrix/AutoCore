# Raw capture: FUN_004fc4c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fc4c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fc4c0` |
| **Canonical name** | `FUN_004fc4c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004fc4c0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  uint uVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  pcVar7 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2d16;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x48) != 0) {
    pcVar8 = (char *)(param_1 + 0x4e0);
    ExceptionList = &local_c;
    *param_2 = '\0';
    pcVar2 = pcVar8;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar2 == (char *)(param_1 + 0x4e1)) {
      if (**(int **)(*(int *)(param_1 + 0x48) + 0xc0) != 0) {
        param_2 = (char *)0x0;
        FUN_0096f6e0("DiffuseTexture",&param_2);
        if (param_2 != (char *)0x0) {
          if (*(int *)((int)param_2 + 0x4c) == 0) {
            piVar3 = &DAT_00d1ed24;
          }
          else {
            piVar3 = (int *)(*(int *)((int)param_2 + 0x4c) + 4);
          }
          pcVar2 = (char *)*piVar3;
          if ((char *)*piVar3 == (char *)0x0) {
            pcVar2 = PTR_DAT_00afa2bc;
          }
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                    (local_44,pcVar2);
          local_4 = 0;
          uVar4 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                  ::find(local_44,".",0);
          if (uVar4 != *(uint *)npos_exref) {
            pbVar5 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )std::
                      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
                      substr(local_44,(uint)local_28,0);
            local_4._0_1_ = 1;
            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
            operator=(local_44,pbVar5);
            local_4 = (uint)local_4._1_3_ << 8;
            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
          }
          pcVar6 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                   ::c_str(local_44);
          pcVar2 = pcVar7;
          do {
            cVar1 = *pcVar6;
            *pcVar2 = cVar1;
            pcVar6 = pcVar6 + 1;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
          iVar9 = (int)pcVar8 - (int)pcVar7;
          do {
            cVar1 = *pcVar7;
            pcVar7[iVar9] = cVar1;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          local_4 = 0xffffffff;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);
          ExceptionList = local_c;
          return;
        }
      }
    }
    else {
      iVar9 = (int)param_2 - (int)pcVar8;
      do {
        cVar1 = *pcVar8;
        pcVar8[iVar9] = cVar1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
    }
  }
  ExceptionList = local_c;
  return;
}
```
