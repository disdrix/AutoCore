# Raw capture: Client_RecvLoginResponse_Placeholder

| Field | Value |
|---|---|
| **Stable ID** | `aa_00822070` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00822070` |
| **Canonical name** | `Client_RecvLoginResponse_Placeholder` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvLoginResponse_Placeholder(undefined1 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009b02b6;
  local_c = ExceptionList;
  if (DAT_00d1b77c == 0) {
    return;
  }
  if (DAT_00d1b780 == (int *)0x0) {
    return;
  }
  if (*DAT_00d1b780 != DAT_00d1b77c) {
    return;
  }
  ExceptionList = &local_c;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
  local_4 = 0;
  FUN_0076c130("OnConnectionFailed: code:%d\n",param_1);
  piVar1 = *(int **)(DAT_00d1b77c + 0xa74);
  if (piVar1 == (int *)0x0) goto LAB_00822189;
  piVar2 = (int *)piVar1[0x164];
  if (piVar2 == (int *)0x0) {
LAB_00822170:
    if (DAT_00d1b1e4 != '\0') goto LAB_00822178;
  }
  else {
    if (DAT_00d1b1e4 == '\0') {
      *(undefined1 *)((int)piVar2 + 0x489) = 0;
      piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);
      piVar2[0x8b] = *piVar3;
      piVar2 = (int *)piVar1[0x165];
      *(undefined1 *)((int)piVar2 + 0x489) = 0;
      piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);
      piVar2[0x8b] = *piVar3;
      (**(code **)(*(int *)piVar1[0x159] + 0xd4))(1);
      (**(code **)(*(int *)piVar1[0x15b] + 0xd4))(1);
      FUN_007fdfb0(&DAT_00d1a840,"Failed to login!  Please try again in a moment.",0x4e24,1,0);
      goto LAB_00822170;
    }
LAB_00822178:
    DAT_00d1b1e4 = '\0';
  }
  (**(code **)(*piVar1 + 0x34c))();
LAB_00822189:
  FUN_007fc360();
  FUN_007fdfb0(&DAT_00d1a840,"Could not connect to the authentication server.",0xffffffff,1,0);
  local_4 = 0xffffffff;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
  ExceptionList = local_c;
  return;
}
```
