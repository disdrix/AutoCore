# Raw capture: FUN_004cb2c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb2c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cb2c0` |
| **Canonical name** | `FUN_004cb2c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004cb2c0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x21);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x21);
  }
  return;
}
```

---

## R13-002 re-verify (2026-08-05) — append only

**Tools:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

### Body bytes (`read_memory` @ `0x004cb2c0`, 28 B)

```text
8b 44 24 04 8b 08 80 79 21 00 75 0e 8d 64 24 00 8b c1 8b 08 80 79 21 00 74 f6 c3 cc
```

- Inclusive body: `0x004cb2c0`–`0x004cb2da` (**27 B** / `0x1b`); `CC` pad after.
- Listing (`disassemble_function`):
  ```text
  004cb2c0  MOV EAX,dword ptr [ESP + 0x4]  ; node = stack arg
  004cb2c4  MOV ECX,dword ptr [EAX]        ; left = node->left
  004cb2c6  CMP byte ptr [ECX + 0x21],0x0  ; isnil @ +0x21
  004cb2ca  JNZ 0x004cb2da                 ; left isnil → return EAX=node
  004cb2cc  LEA ESP,[ESP]                  ; MSVC align nop
  004cb2d0  MOV EAX,ECX                    ; node = left
  004cb2d2  MOV ECX,dword ptr [EAX]
  004cb2d4  CMP byte ptr [ECX + 0x21],0x0
  004cb2d8  JZ  0x004cb2d0                 ; while left non-nil
  004cb2da  RET                            ; EAX = leftmost non-nil
  ```
- ABI: stack arg `node*` @ `[ESP+4]`; returns leftmost in **EAX**; bare **`RET`** (`C3`). Caller cleans (`ADD ESP,4`). Not thiscall / not EAX-in ABI.
- isnil every guard **`+0x21`** (`80 79 21 00`).
- Decompiler `void` is wrong for return — call sites seal EAX out via `MOV [EBX],EAX`.

### Call sites (7 UNCONDITIONAL_CALL) — all same plate

| Site | Function | After CALL |
|---|---|---|
| `0x0040571a` | `FUN_00405650` (parent erase isnil21) | `ADD ESP,4` / `MOV [EBX],EAX` |
| `0x004e3f5f` | `FUN_004e3e70` | same |
| `0x00511cec` | `FUN_00511c00` | same |
| `0x0059d3ec` | `FUN_0059d300` | same |
| `0x005a2f8f` | `FUN_005a2ea0` | same |
| `0x005a467c` | `FUN_005a4590` | same |
| `0x005ae7bf` | `FUN_005ae6d0` | same |

Uniform plate: `PUSH EDI; CALL 0x004cb2c0; ADD ESP,4; MOV [EBX],EAX` with surrounding `CMP byte ptr [EDI+0x21],0` (isnil21 family).

### Live decompile

Walk-left while `!isnil(+0x21)` matches bytes; return-in-EAX requires override via call site + listing (decomp void).

### Named role

`StdTree_Min_Isnil21_Inferred` — family twin of `StdTree_Min_Isnil29` @ `0x0051b5d0` (stack ABI) and `StdTree_Min_Isnil31` @ `0x00409160` (EAX ABI). Max peer residual `FUN_00421a60` (R13-001). Parent dual `StdTree_EraseAndRebalance_Isnil21_Inferred` @ `0x00405650` (R12-009).
