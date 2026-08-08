# Raw capture: FUN_005ae6d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae6d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ae6d0` |
| **Canonical name** | `FUN_005ae6d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x005ae7f0) */
/* WARNING: Removing unreachable block (ram,0x005ae800) */
/* WARNING: Removing unreachable block (ram,0x005ae809) */
/* WARNING: Removing unreachable block (ram,0x005ae80c) */
/* WARNING: Removing unreachable block (ram,0x005ae7fc) */
/* WARNING: Removing unreachable block (ram,0x005ae81a) */
/* WARNING: Removing unreachable block (ram,0x005ae827) */
/* WARNING: Removing unreachable block (ram,0x005ae832) */
/* WARNING: Removing unreachable block (ram,0x005ae82e) */
/* WARNING: Removing unreachable block (ram,0x005ae822) */
/* WARNING: Removing unreachable block (ram,0x005ae835) */

void __thiscall FUN_005ae6d0(int param_1,undefined4 param_2,int *param_3)

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
  puStack_8 = &LAB_009a65a2;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_3 + 0x21) != '\0') {
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
  FUN_004e12c0();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
    if (*(char *)(param_3[2] + 0x21) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      piVar3 = (int *)FUN_004cb2c0(piVar6);
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (*(int **)(iVar2 + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      uVar4 = FUN_00421a60(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_3[8] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[8] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_0050e9f0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(*piVar5 + 0x20) != '\x01') || (*(char *)(piVar5[2] + 0x20) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x20) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x20) = 1;
                *(undefined1 *)(piVar5 + 8) = 0;
                FUN_005a27f0(piVar5);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 8) = (char)piVar3[8];
              *(undefined1 *)(piVar3 + 8) = 1;
              *(undefined1 *)(piVar5[2] + 0x20) = 1;
              FUN_0050e9f0(piVar3);
              break;
            }
LAB_005ae902:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        else {
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_005a27f0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(piVar5[2] + 0x20) == '\x01') && (*(char *)(*piVar5 + 0x20) == '\x01'))
            goto LAB_005ae902;
            if (*(char *)(*piVar5 + 0x20) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x20) = 1;
              *(undefined1 *)(piVar5 + 8) = 0;
              FUN_0050e9f0(piVar5);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 8) = (char)piVar3[8];
            *(undefined1 *)(piVar3 + 8) = 1;
            *(undefined1 *)(*piVar5 + 0x20) = 1;
            FUN_005a27f0(piVar3);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(param_3);
}
```


---

## R12-035 re-verify (2026-08-05 OWN-ONLY dual)

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

### Live decompile

Live `decompile_function` @ `0x005ae6d0` **=** raw CF above (throw / unlink / rebalance / `operator_delete`). Decompiler marks epilogue + two-child splice blocks as unreachable / false noreturn — **bytes seal the missing tail**.

### Body / ABI (`read_memory`)

| Item | Evidence |
|---|---|
| Entry | SEH `64 A1 … 6A FF 68 A2 65 9A 00` (`LAB_009a65a2`); `MOV EBP,ECX` thiscall |
| isnil test | `80 78 21 00` @ entry (`cmp byte [node+0x21], 0`) |
| Throw string | `0x00a152f0` = `"invalid map/set<T> iterator"` |
| ThrowInfo | `DAT_00acc34c` |
| Color | `+0x20` (`param_3[8]` / `[n+0x20]`) |
| isnil | `+0x21` |
| Epilogue | `operator_delete` ? `test size; jbe; add eax,-1; size--` ? `*outIt = succ` ? `add esp,0x54; ret 8` |
| RET | `C2 08 00` @ `0x005ae983` |
| Inclusive end | `0x005ae985`; exclusive `0x005ae986`; `CC` pad to `0x005ae98f`; next `FUN_005ae990` @ `0x005ae990` |
| Body size | **694 B** / `0x2B6` (`0x005ae6d0`–`0x005ae986` exclusive) |

Epilogue tail hex (from `0x005ae94d`):

```
8b44241050e8cbaeedff8b450883c40485c05f5e5b760683c0ff8945088b4c24608b44245c89088b4c244c5d64890d0000000083c454c20800
```

### Callers / xrefs

| Kind | Value |
|---|---|
| Callers | `FUN_005af2e0` only |
| Xrefs | 1 UNCONDITIONAL_CALL @ `0x005af37f` |
| Call site | `MOV ECX,EDI` then `CALL 0x005ae6d0` (thiscall ECX=map sealed) |

### Callees

| Addr / name | Role |
|---|---|
| `FUN_004e12c0` | in-order successor / iterator++ (isnil@+0x21) |
| `FUN_004cb2c0` | leftmost / min (isnil@+0x21) |
| `FUN_00421a60` | rightmost / max (isnil@+0x21) |
| `FUN_0050e9f0` | Lrotate isnil21 (R10-030 dualed) |
| `FUN_005a27f0` | Rrotate isnil21 (R11-007 dualed; parent dual) |
| `basic_string` / `exception` / `_CxxThrowException` | nil-iterator throw plate |
| `operator_delete` | free erased node |

### Inferred name

`StdTree_EraseAndRebalance_Isnil21_Inferred` — MSVC `_Tree` single-node erase + RB rebalance for **isnil@+0x21 / color@+0x20 / node 0x28 / Val16** family (peer buynode `00408990`, insert `00407200`, rotates `0050e9f0`/`005a27f0`).
