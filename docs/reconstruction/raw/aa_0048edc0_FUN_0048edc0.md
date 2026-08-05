# Raw capture: FUN_0048edc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048edc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048edc0` |
| **Canonical name** | `FUN_0048edc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0048edc0(int param_1)

{
  int iVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a0802;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((*(int *)(*(int *)(param_1 + 0xdc) + 0x30) == 0) &&
     (ExceptionList = &local_c, iVar1 = FUN_0096d0b0(), iVar1 < 0)) {
    pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_0096a630(local_44);
    local_4 = 0;
    pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
             c_str(pbVar2);
    uVar4 = FUN_0076cec0(local_4c,
                         "Failure on ReCreate() of effTextureImpl %s for CVOGEnvironmentSector backbuffer copy"
                         ,pcVar3);
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp",0x3ef,5,
                   uVar4);
    local_4 = 0xffffffff;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);
  }
  if ((*(int *)(*(int *)(param_1 + 0xe0) + 0x30) == 0) && (iVar1 = FUN_0096d0b0(), iVar1 < 0)) {
    pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_0096a630(local_28);
    local_4 = 1;
    pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
             c_str(pbVar2);
    uVar4 = FUN_0076cec0(local_48,
                         "Failure on ReCreate() of effTextureImpl %s for CVOGEnvironmentSector small backbuffer copy"
                         ,pcVar3);
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp",0x3fa,5,
                   uVar4);
    local_4 = 0xffffffff;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
  }
  ExceptionList = local_c;
  return 0;
}
```
