# Raw capture: FUN_007aec70

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aec70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aec70` |
| **Canonical name** | `FUN_007aec70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007aec70(int *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)param_1[0xa5];
  if (pvVar1 != (void *)0x0) {
    if (*(char *)((int)param_1 + 0xbb) != '\0') {
      FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    param_1[0xa5] = 0;
    *(undefined1 *)((int)param_1 + 0xbb) = 0;
    (**(code **)(*param_1 + 0x2b4))(&DAT_00a1419b);
  }
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  return;
}
```
## WQ9L-G re-verify (2026-08-05)

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual WQ9L-G |
| **Tools** | `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_callers` / xrefs + `get_assembly_context` (caller sites). **No** `disassemble_bytes`. |
| **Body** | `0x007aec70`–`0x007aecc3` inclusive (**84 B** / `0x54`); pad `CC` @ `0x007aecc4` |
| **ABI** | **ECX = this** (`8B F1`); bare **`RET`** (`C3`); void |
| **Classification** | worker (CNDUIWindow complete-dtor helper) |
| **Code caller** | `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` @ `0x007b5c83` (`MOV ECX,ESI; CALL`) |
| **DATA xrefs** | Many subclass vtbl slots (shared method pointer) — not additional code callers |
| **Callees** | `RefCountedPtr_Dtor_Inferred` (`FUN_0096efd0`), `operator_delete` |
| **False-noreturn** | Ghidra warns on `operator_delete`; epilogue continues (null + vcall + zero fields + RET) — sealed by hex |

### Live decompile (2026-08-05, matches original raw CF)

```c
void __fastcall FUN_007aec70(int *param_1)
{
  void *pvVar1;
  pvVar1 = (void *)param_1[0xa5];
  if (pvVar1 != (void *)0x0) {
    if (*(char *)((int)param_1 + 0xbb) != '\0') {
      FUN_0096efd0();
      /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    param_1[0xa5] = 0;
    *(undefined1 *)((int)param_1 + 0xbb) = 0;
    (**(code **)(*param_1 + 0x2b4))(&DAT_00a1419b);
  }
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  return;
}
```

### Byte-authority control flow (`read_memory` @ `0x007aec70`, 96 B)

```
PUSH EBX; PUSH ESI; MOV ESI,ECX; PUSH EDI
MOV EDI,[ESI+0x294]          ; owned shell*
XOR EBX,EBX
CMP EDI,EBX / JZ skip_owned
  CMP [ESI+0xBB],BL / JZ skip_dtor
    MOV ECX,EDI; CALL FUN_0096efd0   ; RefCountedPtr_Dtor on shell
    PUSH EDI; CALL operator_delete; ADD ESP,4
  MOV EAX,[ESI]; PUSH 0x00A1419B     ; empty C-string ""
  MOV ECX,ESI
  MOV [ESI+0x294],EBX; MOV [ESI+0xBB],BL
  CALL [EAX+0x2B4]                   ; this->vtbl[+0x2B4]("")
skip_owned:
POP EDI
MOV [ESI+0x29C],EBX; MOV [ESI+0x2A0],EBX
POP ESI; POP EBX; RET
```

### Full body hex (84 B)

```
53 56 8B F1 57 8B BE 94 02 00 00 33 DB 3B FB 74 33
38 9E BB 00 00 00 74 10 8B CF E8 40 03 1C 00 57 E8
8C AB CD FF 83 C4 04 8B 06 68 9B 41 A1 00 8B CE 89
9E 94 02 00 00 88 9E BB 00 00 00 FF 90 B4 02 00 00
5F 89 9E 9C 02 00 00 89 9E A0 02 00 00 5E 5B C3
```

### Offset map (this = CNDUIWindow*)

| Offset | Index | Role |
|---|---|---|
| `+0x294` | `[0xA5]` | heap shell\* (RefCountedPtr host); optional own |
| `+0xBB` | byte | ownership flag for `+0x294` |
| `+0x29C` | `[0xA7]` | always zeroed |
| `+0x2A0` | `[0xA8]` | always zeroed |
| vtbl `+0x2B4` | — | called with `DAT_00a1419b` (`""`) when shell was non-null |

### Notes

- `DAT_00a1419b` first byte `0x00` → empty C-string (shared empty literal; also used by `FUN_007a8580` vtbl+0x288 clear path).
- Scaffold alias `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aec70` is parent-path debug noise — **rejected** as product plate.
- Named seal: `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred`.
- Runtime / bit-exact / differential: **open**. Terminal: **false**.
