# Raw capture: FUN_0043bdf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bdf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043bdf0` |
| **Canonical name** | `FUN_0043bdf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_0043bdf0(int param_1)

{
  undefined4 uVar1;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009bc89b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_0043c460();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  local_4 = 0;
  local_10 = *(undefined4 *)(param_1 + 8);
  FUN_004646e0(param_1 + 0x10,9,&local_10);
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(undefined4 *)(param_1 + 0x24) = 1;
  ExceptionList = local_c;
  return param_1;
}
```

---

## W34-E re-verify append (2026-07-29)

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs. **No** `disassemble_bytes`. No Launcher.

### Live decompile (2026-07-29)

```c
int FUN_0043bdf0(int param_1)
{
  undefined4 uVar1;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009bc89b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_0043c460();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  local_4 = 0;
  local_10 = *(undefined4 *)(param_1 + 8);
  FUN_004646e0(param_1 + 0x10,9,&local_10);
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(undefined4 *)(param_1 + 0x24) = 1;
  ExceptionList = local_c;
  return param_1;
}
```

**Match:** live decompile ≡ 2026-07-23 scaffold CF.

### Body bytes (`read_memory` 128 B @ `0x0043bdf0`)

- **Range:** `0x0043bdf0`–`0x0043be51` (**98 B** / `0x62`)
- **Epilog:** `83 C4 10` / `C2 04 00` (ADD ESP,0x10; RET 4)
- **Pad:** `CC` from `0x0043be52` then next function
- **Full hex:**
```
6aff689bc89b0064a100000000506489250000000051568b742418e85006000089460833c089460c8d4c240451894424148b46086a098d56105289442410e8ad8802008b4c2408b8010000008946208946248bc65e64890d0000000083c410c20400
```

### Bytes-backed facts

| Fact | Evidence |
|---|---|
| SEH | `push -1; push LAB_009bc89b; mov fs:[0]` |
| Stack self | `MOV ESI,[ESP+0x18]` after SEH + push ECX/ESI |
| Sentinel | `CALL FUN_0043c460` → `MOV [ESI+8],EAX`; `XOR EAX,EAX; MOV [ESI+0xC],EAX` |
| Fill temp | stack copy of sentinel before `FUN_004646e0` |
| Buckets | `LEA EDX,[ESI+0x10]; PUSH 9; CALL FUN_004646e0` (PtrVecShell_InitFill, W33-B) |
| Flags | `MOV EAX,1; MOV [ESI+0x20],EAX; MOV [ESI+0x24],EAX` |
| Return | `MOV EAX,ESI`; `RET 4` |

### Callees (owned only for shape notes)

| VA | Role |
|---|---|
| `FUN_0043c460` | `operator_new(0x14)` circular next/prev (unowned twin of CircularSentinel_Alloc0x28) |
| `FUN_004646e0` | `PtrVecShell_InitFill_Inferred` — 9 slots filled with sentinel* |

### Callers / xrefs

| From | Function | Role |
|---|---|---|
| `0x0075d499` | `FUN_0075d470` | NDResourceCache host: `DAT_00d1f050 = self`; bag at `self+0` then CS @ `+0x3c` |
| `0x0074d797` | `FUN_0074d750` | Nested at `self+0x34` after sibling bag `FUN_0044a0d0(self+0x0c)` |

### Inferred name

`NestedHash_Ctor_Sentinel0x14_Inferred` — structural (identical CF to W32-D `AssResolverA_NestedHash_Ctor` / W32-E `AssResolverCore_HeadBag_Ctor` with node size **0x14**). Reject scaffold `Named_CalleeOf_*`.
