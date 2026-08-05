# Raw capture: FUN_0043ddf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ddf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043ddf0` |
| **Canonical name** | `FUN_0043ddf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0043ddf0(undefined4 *param_1,char param_2,undefined4 *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int unaff_EDI;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  undefined1 local_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009bc919;
  local_c = ExceptionList;
  if (0x15555553 < *(uint *)(unaff_EDI + 8)) {
    ExceptionList = &local_c;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
              (local_50,"map/set<T> too long");
    local_4 = 0;
    FUN_00401a40(local_50);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc388);
  }
  ExceptionList = &local_c;
  piVar3 = (int *)FUN_0043e380(*(undefined4 *)(unaff_EDI + 4),param_3,*(undefined4 *)(unaff_EDI + 4)
                               ,0);
  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 1;
  if (param_3 == *(undefined4 **)(unaff_EDI + 4)) {
    (*(undefined4 **)(unaff_EDI + 4))[1] = piVar3;
    **(undefined4 **)(unaff_EDI + 4) = piVar3;
    iVar4 = *(int *)(unaff_EDI + 4);
  }
  else {
    if (param_2 != '\0') {
      *param_3 = piVar3;
      if (param_3 == (undefined4 *)**(int **)(unaff_EDI + 4)) {
        **(int **)(unaff_EDI + 4) = (int)piVar3;
      }
      goto LAB_0043dea2;
    }
    param_3[2] = piVar3;
    iVar4 = *(int *)(unaff_EDI + 4);
    if (param_3 != *(undefined4 **)(iVar4 + 8)) goto LAB_0043dea2;
  }
  *(int **)(iVar4 + 8) = piVar3;
LAB_0043dea2:
  cVar1 = *(char *)(piVar3[1] + 0x18);
  piVar7 = piVar3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(unaff_EDI + 4) + 4) + 0x18) = 1;
      *param_1 = piVar3;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[6] == '\0') {
LAB_0043dec7:
        *(undefined1 *)(*piVar5 + 0x18) = 1;
        *(undefined1 *)(piVar6 + 6) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x18) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00446b10(unaff_EDI);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x18) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
        FUN_0040b910(unaff_EDI);
      }
    }
    else {
      if ((char)piVar6[6] == '\0') goto LAB_0043dec7;
      if (piVar7 == (int *)*piVar2) {
        FUN_0040b910(unaff_EDI);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x18) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
      FUN_00446b10(unaff_EDI);
    }
    cVar1 = *(char *)(piVar7[1] + 0x18);
  } while( true );
}
```
