# Raw capture: FUN_005ae2f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ae2f0` |
| **Canonical name** | `FUN_005ae2f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_005ae2f0(int param_1,undefined4 *param_2,char param_3,undefined4 *param_4,undefined4 param_5)

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
  if (0xcccccca < *(uint *)(param_1 + 8)) {
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
  piVar4 = (int *)FUN_005ae1c0(*(undefined4 *)(param_1 + 4),param_4,*(undefined4 *)(param_1 + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x20);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x20) = 1;
      *param_2 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[8] == '\0') {
LAB_005ae3f6:
        *(undefined1 *)(*piVar5 + 0x20) = 1;
        *(undefined1 *)(piVar6 + 8) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x20) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0050e9f0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x20) = 0;
        FUN_005a27f0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[8] == '\0') goto LAB_005ae3f6;
      if (piVar7 == (int *)*piVar2) {
        FUN_005a27f0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x20) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x20) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x21) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x20);
  } while( true );
}
```

## R12-034 live re-verify (2026-08-05)

| Field | Value |
|---|---|
| Tool | Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_xrefs_to` + `read_memory` (**no** `disassemble_bytes`) |
| Live decompile | **identical CF** to raw body above |
| Body | `0x005ae2f0`–`0x005ae4da` inclusive (**491** B / `0x1EB`) |
| Epilogue | `83 C4 50` / `C2 10 00` (`add esp,0x50; ret 0x10`) at `0x005ae4d7`–`0x005ae4da` |
| Size gate | `81 7F 08 CB CC CC 0C` = `cmp dword [edi+8], 0x0CCCCCCB`; `jb` continue → throw when `size >= 0xCCCCCCB` (equiv decomp `0xcccccca < size`) |
| Color / isnil | color tests `80 ?? 20 00`; isnil test `80 7A 21 00` (inline Lrotate path) |
| Pad | 5× `CC` then next function `FUN_005ae4e0` @ `0x005ae4e0` |
| Callees | `FUN_005ae1c0` (buynode node 0x24), `FUN_0050e9f0` Lrotate isnil21, `FUN_005a27f0` Rrotate isnil21 ×2, `_CxxThrowException`, `basic_string` / `exception` |
| Callers | **1** — `FUN_005aec50` only |
| Xrefs | **1** UNCONDITIONAL_CALL @ `0x005aecaf` in `FUN_005aec50` |
| ABI | `__thiscall` ECX=map; stack `(out**, addLeft, where*, value*)`; **RET 0x10** |
| Throw string | `"map/set<T> too long"`; ThrowInfo `DAT_00acc388` |
| SEH | `LAB_009a65a2` (same frame as peer Val12 insert `005ae4e0`) |
| Parent residual link | Listed residual of dualed Rrotate `0x005a27f0` (caller of that leaf); system skills-abilities |
| Buynode | `FUN_005ae1c0` `operator_new(0x24)`; value 5 dwords @+0x0C; color@+0x20; isnil@+0x21 |
| Sole parent shell | `FUN_005aec50` insert-or-find; composite int key at value dword0/1 vs node+0x0C/+0x10 |

Entry + size-gate hex (first 36 B):

```
64a1000000006aff68a2659a00506489250000000083ec44578bf9817f08cbcccc0c
```

Epilogue tail:

```
83c450c21000  ; add esp,0x50; ret 0x10
```

Full body hex (491 B, no pad):

```
64a1000000006aff68a2659a00506489250000000083ec44578bf9817f08cbcccc0c7259680c53a1008d4c2408ff15f8629c008d4c2420c744245000000000ff1560669c008d442404508d4c2430c644245401c744242428769c00ff15ec629c006888c3ac008d4c242451c644245800c744242834769c00e8f3590f008b5424648b470453568b7424686a00525056508bcfe839feffff8bc88b4704bb01000000015f083bf0894c246c75108948048b470489088b5704894a08eb22807c246400740d890e8b47043b3075128908eb0e894e088b47043b700875038948088b5104807a20008d41048bf10f85d8000000558b088b69048b55003bca75538b5508807a2000751b8b08885920885a208b108b4a04c64120008b108b7204e9920000003b7108750a8bf1568bcfe8d005f6ff8b46048858208b4e048b5104c64220008b46048b4804518bcfe8b243ffffeb63807a200074b03b31750a8bf1568bcfe89c43ffff8b46048858208b4e048b5104c64220008b46048b40048b48088b118950088b11807a210075038942048b50048951048b57043b42047505894a04eb0e8b50043b027504890aeb03894a0889018948048b4e04807920008d46040f842effffff8b4c24705d8b57048b42048858208b4424605e89088b4c244c5b5f64890d0000000083c450c21000
```

CALL targets (rel32 resolved):

| Site | Target |
|---|---|
| `0x005ae368` | `_CxxThrowException` `0x006a3d60` |
| `0x005ae382` | `FUN_005ae1c0` buynode |
| `0x005ae41b` | `FUN_0050e9f0` Lrotate isnil21 |
| `0x005ae439` | `FUN_005a27f0` Rrotate isnil21 |
| `0x005ae44f` | `FUN_005a27f0` Rrotate isnil21 |

Promoted name: **StdTree_InsertAndRebalance_Val20_Isnil21_Inferred** (MSVC `_Tree` always-insert + RB rebalance; node **0x24** / Val20 @+0x0C; color@+0x20; isnil@+0x21; max size gate `0xCCCCCCB`; shares isnil21 rotates with Val16 family; **not** Val12 peer `005ae4e0`).
