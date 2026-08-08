# Raw capture: FUN_004cbb60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbb60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cbb60` |
| **Canonical name** | `FUN_004cbb60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_004cbb60(int param_1,undefined4 *param_2,char param_3,undefined4 *param_4,undefined4 param_5)

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
  puStack_8 = &LAB_009a1e42;
  local_c = ExceptionList;
  if (0xaaaaaa8 < *(uint *)(param_1 + 8)) {
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
  piVar4 = (int *)FUN_005a2de0(*(undefined4 *)(param_1 + 4),param_4,*(undefined4 *)(param_1 + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x28);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x28) = 1;
      *param_2 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[10] == '\0') {
LAB_004cbc66:
        *(undefined1 *)(*piVar5 + 0x28) = 1;
        *(undefined1 *)(piVar6 + 10) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x28) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004192a0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x28) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x28) = 0;
        FUN_004192f0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[10] == '\0') goto LAB_004cbc66;
      if (piVar7 == (int *)*piVar2) {
        FUN_004192f0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x28) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x28) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x29) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x28);
  } while( true );
}
```
---

## Re-verify append — 2026-08-04 WQ9E-E (OWN-ONLY dual)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`. |
| **Live decompile** | **≡ raw CF** (RB fixup loop + Lrotate call + inlined Rrotate side); `*outIt` on black-root exit sealed |
| **Body** | `0x004cbb60`–`0x004cbd4b` exclusive (**491 B** / `0x1EB`); Ghidra lists end `0x004cbd4a`; terminal **`C2 10 00`**; pad `CC` |
| **ABI (bytes)** | **`__thiscall`**; ECX = map shell*; stack `Node** outIt`, `char addLeft`, `Node* where`, `Val24* value`; **RET 0x10** |
| **Semantics** | MSVC `_Tree` **always-insert + RB rebalance** for **isnil@+0x29** nodes: |
| | 1. if `size > 0xAAAAAA8` → throw `"map/set<T> too long"` / `DAT_00acc388` |
| | 2. `FUN_005a2de0(head, where, head, value, color=0)` — buynode **0x30**, copies **6 dwords** value @ node+0x10..+0x27, color@+0x28, isnil=0 @+0x29 |
| | 3. `size++`; link left/right of `where` (or empty-tree triple extremum); update leftmost/rightmost |
| | 4. while parent red: uncle recolor or L/R rotate (`FUN_004192a0` / `FUN_004192f0`; one Lrotate path inlined in decompile) |
| | 5. root black; `*outIt = newNode`; return |
| **Max-size constant** | `0xAAAAAA8` — matches ~`(size_t)-1 / 0x18` family (24-byte value) |
| **Callers (3 funcs / 11 xrefs)** | `FUN_004cbe20` (2), `FUN_004cbee0` (2), `FUN_004cc220` (7) |
| **Callees** | `FUN_005a2de0` (buynode), `FUN_004192a0` (Lrotate isnil29), `FUN_004192f0` (Rrotate isnil29), throw path |
| **Twins / peers** | Val12 insert `StdTree_InsertAndRebalance_Val12` @ `0x005ae4e0` (isnil@+0x19, max `0x15555553`); erase twin OWN `0x004cb740` |
| **Named** | `StdTree_InsertAndRebalance_Isnil29_Inferred` |
| **Prior alias** | `Named_CalleeOf_…_CVOGHBAIBase_GetTargetFromAggro_004cbb60` — **narrow** |
| **Terminal** | false |

### Entry hex (32 B)

```
64a1000000006aff68421e9a00506489250000000083ec44578bf9817f08a9aa
```

(`81 7F 08 A9 AA AA 0A` → `cmp dword [edi+8], 0x0AAAAAA9` shape; decompile uses `0xaaaaaa8 < size`)

### Exit hex (RET 16 + pad)

```
83c450c21000cccccccccc
```
