# Raw capture: FUN_005a2ea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2ea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a2ea0` |
| **Canonical name** | `FUN_005a2ea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x005a2fc0) */
/* WARNING: Removing unreachable block (ram,0x005a2fd0) */
/* WARNING: Removing unreachable block (ram,0x005a2fd9) */
/* WARNING: Removing unreachable block (ram,0x005a2fdc) */
/* WARNING: Removing unreachable block (ram,0x005a2fcc) */
/* WARNING: Removing unreachable block (ram,0x005a2fea) */
/* WARNING: Removing unreachable block (ram,0x005a2ff7) */
/* WARNING: Removing unreachable block (ram,0x005a3002) */
/* WARNING: Removing unreachable block (ram,0x005a2ffe) */
/* WARNING: Removing unreachable block (ram,0x005a2ff2) */
/* WARNING: Removing unreachable block (ram,0x005a3005) */

void __thiscall FUN_005a2ea0(int param_1,undefined4 param_2,int *param_3)

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
  puStack_8 = &LAB_009a6342;
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
LAB_005a30d2:
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
            goto LAB_005a30d2;
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

## R12-030 re-verify (2026-08-05) — OWN-ONLY dual

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `disassemble_function` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

### Live ≡ raw CF

Live decompile 2026-08-05 matches raw 2026-07-23 for throw / successor prep / splice / RB. Decompiler still marks `operator_delete` as noreturn and omits size-- / `*outIt` / `ret 8` — **bytes seal** those.

### Body / ABI (bytes)

| Item | Value |
|---|---|
| Entry | `0x005a2ea0` |
| Inclusive end | `0x005a3155` (`C2 08 00`) |
| Exclusive end / pad | `0x005a3156` (`CC`…) |
| Size | **694 B** / `0x2B6` |
| ABI | `__thiscall` ECX=map; stack `outIt**`, `node*`; **`ret 8`** |
| this | `MOV EBP, ECX` @ `005a2ec1` |
| isnil test | `CMP byte ptr [EAX+0x21], 0` (`80 78 21 00`) |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| ThrowInfo | `DAT_00acc34c` |
| SEH | `LAB_009a6342` |
| Ghidra listed body | `005a2ea0`–`005a3126` (truncated by false noreturn on delete) |

**Entry hex (80 B):**
```
64a1000000006aff6842639a00508b4424146489250000000083ec4880782100558be9745968f052a1008d4c240cff15f8629c008d4c2424c744245400000000ff1560669c008d442408508d4c2434c6
```

**Epilogue hex (`005a311d`–`ret 8`):**
```
8b44241050e8fb66eeff8b450883c40485c05f5e5b760683c0ff8945088b4c24608b44245c89088b4c244c5d64890d0000000083c454c20800
```

Decoded epilogue:
1. `PUSH [ESP+0x10]` / `CALL operator_delete` (`0x00489822`) — free erased node
2. `MOV EAX, [EBP+8]` — map size
3. `ADD ESP,4` / `TEST EAX,EAX` / `POP EDI,ESI,EBX`
4. `JBE skip` / `ADD EAX,-1` / `MOV [EBP+8],EAX` — **size--** if size>0
5. `MOV ECX,[ESP+0x60]` / `MOV EAX,[ESP+0x5c]` / `MOV [EAX],ECX` — **`*outIt = successor`**
6. SEH teardown / `ADD ESP,0x54` / **`RET 8`**

### Callers / xrefs (2 UNCONDITIONAL_CALL)

| Site | Enclosing | Context |
|---|---|---|
| `005a38ff` | `FUN_005a3860` | EraseRange shell: `PUSH node` / `LEA outIt` / `MOV ECX,EDI` / `CALL`; parent `RET 0xC` |
| `005a052b` | orphan body (Ghidra no function; ~`005a04d0`–`005a053d`, DATA xref `009d7f0c`) | `PUSH` / `LEA` / `MOV ECX,EDI` / `CALL`; parent `RET 4` |

### Callees

| VA | Role |
|---|---|
| `FUN_004e12c0` | isnil21 successor / iterator++ (`__fastcall` ECX=`Node**`) |
| `FUN_004cb2c0` | min / leftmost isnil21 |
| `FUN_00421a60` | max / rightmost isnil21 |
| `FUN_0050e9f0` | Lrotate isnil21 (dualed) |
| `FUN_005a27f0` | Rrotate isnil21 (parent dual R11-007) |
| `operator_delete` | free node only (no value dtor in this body) |
| STL throw | `basic_string` / `exception` / `_CxxThrowException` |

### Layout (sealed)

| Off | Field |
|---|---|
| map+4 | head* |
| map+8 | size (uint32) |
| node+0 | left* |
| node+4 | parent* |
| node+8 | right* |
| node+0x20 | color (0 red / 1 black); also `param_3[8]` as dword color lane |
| node+0x21 | isnil |
| node size | **0x28** (Val16 family) |

### Clone family (do not merge VAs)

Same CF class as dualed `00405650` (660 B), `004e3e70` (694 B isomorphic reloc clone), residual peers `0059d300` / `005a3500` / … — shared rotates `0050e9f0`/`005a27f0`.

### Inferred name

`StdTree_EraseAndRebalance_Isnil21_Inferred` — product demangle open → `_Inferred`. Not Runtime Confirmed.
