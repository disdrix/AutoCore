# Raw capture: FUN_0043fdf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043fdf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043fdf0` |
| **Canonical name** | `FUN_0043fdf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_0043fdf0(int param_1)

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
  uVar1 = FUN_004933f0();
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

## Re-verify append — W34-F (2026-07-29)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `batch_decompile` + `analyze_function_complete` + `read_memory` |
| **Disallowed** | `disassemble_bytes` (not used) |
| **Decompile CF** | **Unchanged** vs 2026-07-23 scaffold |
| **Body** | `0x0043fdf0`–`0x0043fe51` inclusive (**98 B** / `0x62`); pad `CC` then next |
| **ABI (bytes)** | stack `self*` @ `[esp+0x18]` after SEH/pushes → ESI; **`RET 4`** (`C2 04 00`); returns **self** (`MOV EAX,ESI`) |
| **SEH** | `LAB_009bc89b` (same handler plate as AssResolverCore twin `FUN_00469db0`) |
| **Callees** | `FUN_004933f0` / `StdList_AllocSentinel_0xC_Inferred` (W32-P); `FUN_004646e0` / `PtrVecShell_InitFill_Inferred` (W33-B) |
| **Callers (3)** | `FUN_0074e380` @ `0x0074e3ba` (`self+0x14` / float*+5 in 0x40 outer); `FUN_0096eec0` @ `0x0096eeea` (whole object base); `FUN_00996bc0` @ `0x00996c02` (`param_1+10` dwords = +0x28) |
| **Family** | Structural twin of `AssResolverA_NestedHash_Ctor_Inferred` (`0x00423cf0`, 98 B) with sentinel node **0x0C** instead of **0x28** |

### Full body hex (98 B)

```
6aff689bc89b0064a100000000506489250000000051568b742418e8e035050089460833c089460c8d4c240451894424148b46086a098d56105289442410e8ad4802008b4c2408b8010000008946208946248bc65e64890d0000000083c410c20400
```

### Layout written

| Off | Value |
|---|---|
| +0x00 / +0x04 | unwritten |
| +0x08 | sentinel* from `StdList_AllocSentinel_0xC` |
| +0x0c | size `0` |
| +0x10 | shell base → `PtrVecShell_InitFill` count **9**, fill = sentinel |
| +0x20 / +0x24 | flags `1` / `1` |

### Name

`NestedHash_Ctor_Sentinel0xC_Inferred` (**Inferred** structural; multi-host). Reject scaffold `Named_CalleeOf_*`.
