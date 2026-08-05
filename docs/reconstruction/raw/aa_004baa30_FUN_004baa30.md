# Raw capture: FUN_004baa30

| Field | Value |
|---|---|
| **Stable ID** | `aa_004baa30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004baa30` |
| **Canonical name** | `FUN_004baa30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x004bab50) */
/* WARNING: Removing unreachable block (ram,0x004bab60) */
/* WARNING: Removing unreachable block (ram,0x004bab69) */
/* WARNING: Removing unreachable block (ram,0x004bab6c) */
/* WARNING: Removing unreachable block (ram,0x004bab5c) */
/* WARNING: Removing unreachable block (ram,0x004bab7a) */
/* WARNING: Removing unreachable block (ram,0x004bab87) */
/* WARNING: Removing unreachable block (ram,0x004bab92) */
/* WARNING: Removing unreachable block (ram,0x004bab8e) */
/* WARNING: Removing unreachable block (ram,0x004bab82) */
/* WARNING: Removing unreachable block (ram,0x004bab95) */

void __thiscall FUN_004baa30(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];
  undefined **local_34 [3];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a16a2;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_3 + 0x15) != '\0') {
    ExceptionList = &pvStack_c;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
              (local_50,"invalid map/set<T> iterator");
    local_4 = 0;
    exception::exception((exception *)local_34);
    local_4._0_1_ = 1;
    local_34[0] = &PTR_FUN_009c7628;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28,local_50);
    local_4 = (uint)local_4._1_3_ << 8;
    local_34[0] = &PTR_FUN_009c7640;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc34c);
  }
  ExceptionList = &pvStack_c;
  FUN_00673070();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    if (*(char *)(param_3[2] + 0x15) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_3) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  if ((int *)*puVar1 == param_3) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      piVar3 = (int *)FUN_004e12a0(piVar6);
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (*(int **)(iVar2 + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      uVar4 = FUN_00421b70(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_3[5] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[5] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_004e22d0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(*piVar5 + 0x14) != '\x01') || (*(char *)(piVar5[2] + 0x14) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x14) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x14) = 1;
                *(undefined1 *)(piVar5 + 5) = 0;
                FUN_006753b0(piVar5);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 5) = (char)piVar3[5];
              *(undefined1 *)(piVar3 + 5) = 1;
              *(undefined1 *)(piVar5[2] + 0x14) = 1;
              FUN_004e22d0(piVar3);
              break;
            }
LAB_004bac62:
            *(undefined1 *)(piVar5 + 5) = 0;
          }
        }
        else {
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_006753b0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(piVar5[2] + 0x14) == '\x01') && (*(char *)(*piVar5 + 0x14) == '\x01'))
            goto LAB_004bac62;
            if (*(char *)(*piVar5 + 0x14) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x14) = 1;
              *(undefined1 *)(piVar5 + 5) = 0;
              FUN_004e22d0(piVar5);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 5) = (char)piVar3[5];
            *(undefined1 *)(piVar3 + 5) = 1;
            *(undefined1 *)(*piVar5 + 0x14) = 1;
            FUN_006753b0(piVar3);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 5) = 1;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(param_3);
}
```
# Live dual seal append (W23-I, 2026-07-29)

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + callers. **No** `disassemble_bytes`. No Launcher.

| Field | Value |
|---|---|
| Ghidra listed body | `0x004baa30`–`0x004bacb6` (truncated by false noreturn on `operator_delete`) |
| **Sealed body** | `0x004baa30`–`0x004bace5` (**694 B / `0x2B6`**) through `ret 8` |
| ABI | **`__thiscall`** ECX = map facade*; 2 stack formals; epilogue **`ret 8`** (`C2 08 00`) |
| Formals | `this` (map: head* `@+4`, size `@+8`); stack out-it* + node* |
| Nil gate | `node+0x15` isnil → throw `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| Role | MSVC **`_Tree::erase(iterator)`** — unlink node, RB rebalance, `operator_delete`, size--, write out-it |
| Color / isnil | color byte at `node+0x14` / dword `node[5]`; isnil at `+0x15` |
| Callees | `FUN_00673070` (pre-delete iterator advance), `FUN_004e12a0` (leftmost), `FUN_00421b70` (rightmost), `FUN_004e22d0` / `FUN_006753b0` (rotations), `operator_delete`, `_CxxThrowException` |
| Caller (1) | `FUN_004bacf0` = sealed `StdMap_EraseRange_Inferred` (partial-range loop) |
| Name | `StdMap_EraseIterator_Inferred` (Ghidra `FUN_004baa30`) |

### Decompiler hazards sealed by bytes

1. Ghidra body end stops at `operator_delete` call (`004bacb2`–`004bacb6`) because delete is marked noreturn — **false**. Epilogue continues: size-- if `map+8 > 0`, `*out_it` write, SEH restore, **`ret 8`**.
2. Unreachable-block warnings (`004bab50`..) are dead SEH/color paths — CF of erase is intact.
3. Live decompile CF of nil-throw + rebalance loop **matches** scaffold raw body.

### Key entry / exit bytes (`read_memory`)

```
004baa30: 64 a1 00 00 00 00  6a ff  68 a2 16 9a 00  50
          8b 44 24 14  64 89 25 00 00 00 00  83 ec 48
          80 78 15 00  55  8b e9  74 59           ; isnil? / this=ebp / jz ok
          68 f0 52 a1 00                           ; push "invalid map/set<T> iterator"
...
004bacb1: 50  e8 .. .. .. ..                      ; push node; call operator_delete
004bacb7: 8b 45 08  83 c4 04  85 c0  5f 5e 5b
          76 06  83 c0 ff  89 45 08               ; size-- if size>0
          ...  83 c4 54  c2 08 00                 ; ret 8
```

### Call-site seal (parent `004bacf0` @ `0x004bad8f`)

```
push node; lea/push &first; mov ecx, map; call FUN_004baa30
```
