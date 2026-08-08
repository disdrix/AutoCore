# Raw capture: FUN_007aff00

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aff00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aff00` |
| **Canonical name** | `FUN_007aff00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007aff00(int param_1)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0x20c) != 0) {
    pvVar1 = *(void **)(param_1 + 0x28c);
    if (pvVar1 != (void *)0x0) {
      FUN_00797d70(pvVar1);
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *(undefined4 *)(param_1 + 0x28c) = 0;
  }
  FUN_00424060();
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  return;
}
```
## WQ9L-G re-verify (2026-08-05)

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual WQ9L-G |
| **Tools** | `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Body** | `0x007aff00`–`0x007aff51` inclusive (**82 B** / `0x52`); pad `CC` @ `0x007aff52` |
| **ABI** | **ECX = this** (`8B F1`); bare **`RET`** (`C3`); void |
| **Classification** | worker (CNDUIWindow complete-dtor helper) |
| **Code caller** | `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` @ `0x007b5c8a` (`MOV ECX,ESI; CALL`) |
| **DATA xrefs** | Many subclass vtbl slots (shared method pointer) |
| **Callees** | `UiTextLayout_CompleteDtor_Inferred` (`FUN_00797d70`, stdcall/`RET 4`), `operator_delete`, `FUN_00424060` (thiscall on nested `this+0x1E8`) |
| **False-noreturn** | Ghidra warns on `operator_delete`; body continues (null, nested clear, zero fields, RET) — sealed by hex |

### Live decompile (2026-08-05) — CF with decompiler ABI gap

```c
void __fastcall FUN_007aff00(int param_1)
{
  void *pvVar1;
  if (*(int *)(param_1 + 0x20c) != 0) {
    pvVar1 = *(void **)(param_1 + 0x28c);
    if (pvVar1 != (void *)0x0) {
      FUN_00797d70(pvVar1);
      /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *(undefined4 *)(param_1 + 0x28c) = 0;
  }
  FUN_00424060();   /* decompiler dropped LEA ECX,[this+0x1E8] */
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;  /* 300 == 0x12C */
  return;
}
```

### Byte-authority control flow (`read_memory` @ `0x007aff00`, 96 B)

```
PUSH ESI; MOV ESI,ECX
CMP dword [ESI+0x20C],0 / JBE skip_layout   ; enter only when +0x20C != 0
  PUSH EDI
  MOV EDI,[ESI+0x28C]
  TEST EDI,EDI / JZ after_free
    PUSH EDI; CALL FUN_00797d70            ; stdcall layout complete (RET 4)
    PUSH EDI; CALL operator_delete; ADD ESP,4
  MOV dword [ESI+0x28C],0
  POP EDI
skip_layout:
LEA ECX,[ESI+0x1E8]; CALL FUN_00424060     ; nested CS-list clear (thiscall)
MOV dword [ESI+0x128],0
MOV dword [ESI+0x12C],0
POP ESI; RET
```

### Full body hex (82 B)

```
56 8B F1 83 BE 0C 02 00 00 00 76 25 57 8B BE 8C 02
00 00 85 FF 74 0F 57 E8 53 7E FE FF 57 E8 FF 98 CD
FF 83 C4 04 C7 86 8C 02 00 00 00 00 00 00 5F 8D 8E
E8 01 00 00 E8 24 41 C7 FF C7 86 28 01 00 00 00 00
00 00 C7 86 2C 01 00 00 00 00 00 00 5E C3
```

### Offset map (this = CNDUIWindow*)

| Offset | Role |
|---|---|
| `+0x20C` | gate: non-zero → free owned text layout at `+0x28C` |
| `+0x28C` | owned `UiTextLayout*` (same slot parent complete may free again if still set) |
| `+0x1E8` | nested CS-guarded list object (arg to `FUN_00424060`) |
| `+0x128` | always zeroed |
| `+0x12C` | always zeroed (decompiler decimal `300`) |

### Notes

- Decompiler showed bare `FUN_00424060()`; bytes seal **`LEA ECX,[ESI+0x1E8]`** before the call.
- Parent `CNDUIWindow_CompleteDtor` may free `+0x28C` again after return — safe when this path already nulled; when gate `+0x20C==0` this helper skips free and parent owns the release.
- Parent later restamps nested vtbls @ `+0x1E8` and calls `FUN_00424060` again + `DeleteCriticalSection`.
- Scaffold alias `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00` **rejected**.
- Named seal: `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred`.
- Runtime / bit-exact / differential: **open**. Terminal: **false**.
