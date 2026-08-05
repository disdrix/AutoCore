# Raw capture: FUN_005ae4e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae4e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ae4e0` |
| **Canonical name** | `FUN_005ae4e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall

FUN_005ae4e0(int param_1,undefined4 *param_2,char param_3,undefined4 *param_4,undefined4 param_5)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  undefined **local_34 [3];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  undefined1 *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a65a2;

  local_c = ExceptionList;

  if (0x15555553 < *(uint *)(param_1 + 8)) {

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_50,"map/set<T> too long");

    local_4 = 0;

    exception::exception((exception *)local_34);

    local_4._0_1_ = 1;

    local_34[0] = &PTR_FUN_009c7628;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,local_50);

    local_4 = (uint)local_4._1_3_ << 8;

    local_34[0] = &PTR_FUN_009c7634;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc388);

  }

  ExceptionList = &local_c;

  piVar4 = (int *)FUN_005ae220(*(undefined4 *)(param_1 + 4),param_4,*(undefined4 *)(param_1 + 4),

                               param_5,0);

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;

  if (param_4 == *(undefined4 **)(param_1 + 4)) {

    (*(undefined4 **)(param_1 + 4))[1] = piVar4;

    **(undefined4 **)(param_1 + 4) = piVar4;

    *(int **)(*(int *)(param_1 + 4) + 8) = piVar4;

  }

  else if (param_3 == '\0') {

    param_4[2] = piVar4;

    if (param_4 == *(undefined4 **)(*(int *)(param_1 + 4) + 8)) {

      *(int **)(*(int *)(param_1 + 4) + 8) = piVar4;

    }

  }

  else {

    *param_4 = piVar4;

    if (param_4 == (undefined4 *)**(int **)(param_1 + 4)) {

      **(int **)(param_1 + 4) = (int)piVar4;

    }

  }

  cVar1 = *(char *)(piVar4[1] + 0x18);

  piVar7 = piVar4;

  do {

    if (cVar1 != '\0') {

      *(undefined1 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x18) = 1;

      *param_2 = piVar4;

      ExceptionList = local_c;

      return;

    }

    piVar5 = piVar7 + 1;

    piVar2 = (int *)*piVar5;

    piVar6 = *(int **)piVar2[1];

    if (piVar2 == piVar6) {

      piVar6 = (int *)((undefined4 *)piVar2[1])[2];

      if ((char)piVar6[6] == '\0') {

LAB_005ae5e6:

        *(undefined1 *)(*piVar5 + 0x18) = 1;

        *(undefined1 *)(piVar6 + 6) = 1;

        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x18) = 0;

        piVar7 = *(int **)(*piVar5 + 4);

      }

      else {

        if (piVar7 == (int *)piVar2[2]) {

          FUN_00573170(piVar2);

          piVar7 = piVar2;

        }

        *(undefined1 *)(piVar7[1] + 0x18) = 1;

        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;

        FUN_00418c10(*(undefined4 *)(piVar7[1] + 4));

      }

    }

    else {

      if ((char)piVar6[6] == '\0') goto LAB_005ae5e6;

      if (piVar7 == (int *)*piVar2) {

        FUN_00418c10(piVar2);

        piVar7 = piVar2;

      }

      *(undefined1 *)(piVar7[1] + 0x18) = 1;

      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;

      iVar3 = *(int *)(piVar7[1] + 4);

      piVar2 = *(int **)(iVar3 + 8);

      *(int *)(iVar3 + 8) = *piVar2;

      if (*(char *)(*piVar2 + 0x19) == '\0') {

        *(int *)(*piVar2 + 4) = iVar3;

      }

      piVar2[1] = *(int *)(iVar3 + 4);

      if (iVar3 == *(int *)(*(int *)(param_1 + 4) + 4)) {

        *(int **)(*(int *)(param_1 + 4) + 4) = piVar2;

      }

      else {

        piVar6 = *(int **)(iVar3 + 4);

        if (iVar3 == *piVar6) {

          *piVar6 = (int)piVar2;

        }

        else {

          piVar6[2] = (int)piVar2;

        }

      }

      *piVar2 = iVar3;

      *(int **)(iVar3 + 4) = piVar2;

    }

    cVar1 = *(char *)(piVar7[1] + 0x18);

  } while( true );

}
```

---

## W27-T live re-verify (2026-07-29)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP decompile_function + read_memory + analyze_function_complete + get_function_by_address |
| **disassemble_bytes** | **not used** |
| **Live decompile** | **equiv** body above (control flow identity) |
| **Body range** | `0x005ae4e0`–`0x005ae6ca` exclusive (**490** B / `0x1EA`) |
| **Prologue (24 B)** | `64a1000000006aff68a2659a00506489250000000083ec44` |
| **Entry + size gate (32 B)** | `64a1000000006aff68a2659a00506489250000000083ec44578bf9817f085455` |
| **Epilogue tail** | `83c450c21000` = add esp,0x50; ret 0x10 then cc pad |
| **SEH** | `LAB_009a65a2` |
| **thiscall** | mov edi,ecx then cmp dword [edi+8], 0x15555553 |
| **Throw** | string map/set too long via _CxxThrowException(..., DAT_00acc388) |
| **Callees** | FUN_005ae220 (StdTree_Buynode_Val12), FUN_00573170 (Lrotate), FUN_00418c10 (Rrotate), basic_string, exception, _CxxThrowException |
| **Callers** | FUN_005aed20 only (xrefs 005aed79, 005aedb0) |
| **Peer clone** | Map_TreeInsertAndRebalance_Val12 @ 0x0051c1c0 (same size/algorithm/max; different SEH + sole caller) |
| **Canonical name (inferred)** | StdTree_InsertAndRebalance_Val12 |
