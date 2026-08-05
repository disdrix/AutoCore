# Raw capture: FUN_004a7ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004a7ff0` |
| **Canonical name** | `FUN_004a7ff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004a7ff0(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    if ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 0) {
      iVar1 = (param_3 - iVar1) / 0x1c;
      goto LAB_004a8039;
    }
  }
  iVar1 = 0;
LAB_004a8039:
  FUN_004a7ad0(param_3,1,param_4);
  *param_2 = *(int *)(param_1 + 4) + iVar1 * 0x1c;
  return;
}
```
---

## W37-W re-verify append (2026-08-04)

| Field | Value |
|---|---|
| **Body** | `0x004a7ff0`–`0x004a8063` exclusive (**115 B** / `0x73`) |
| **Epilogue** | `C2 0C 00` (**RET 0x0C**) |
| **Classification** | worker (insert-one + iterator rebind) |
| **Tools** | `batch_decompile` + `get_function_by_address` + `get_function_callers` / `get_xrefs_to` + `get_function_callees` + `read_memory`. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw scaffold CF (2026-07-23) |
| **Callers (1)** | `FUN_004a8100` @ `0x004a817d` (wstring vector push_back slow path) |
| **Callees (1)** | `FUN_004a7ad0` / `StdVector_InsertN_BasicStringW` (W34-R) |

### Full body hex (115 B)

```
538b5c240c56578bf98b770485f6741e8b4f082bceb893244992f7e903d1c1fa048bc2c1e81f03c289442414750433f6eb178bcb2bceb893244992f7e903d1c1fa048bf2c1ee1f03f28b4c2418516a01538bcfe888faffff8b47048d14f5000000002bd65f8d0c908b44240c5e89085bc20c00
```

### Sealed CF (bytes win)

```
// __thiscall; ECX = vector<basic_string<wchar_t>>*
// stack: outIt*, where*, value*; RET 0x0C; void
begin = *(this+4)
if (begin != 0 && (end-begin)/0x1c != 0)
  index = (where - begin) / 0x1c   // magic 0x92492493
else
  index = 0
FUN_004a7ad0(where, count=1, value)   // thiscall ECX=this; may realloc
*outIt = *(this+4) + index * 0x1c     // rebind from post-insert begin
ret 0x0C
```

### Notes

- Element stride **0x1c** sealed by magic divide + `lea` scale (`esi*8 - esi` → `*7`, then `*4` → `*28`).
- Hardcoded **count=1** (`6A 01`).
- Index saved **before** insert-n so rebind survives grow/relocate.
- Parent `FUN_004a8100`: capacity-spare arm uses `FUN_004a74f0` fill-one at end; full arm calls this with `where=end`.
- Name: `StdVector_InsertOne_RebindIt_BasicStringW` (**Inferred**). Reject scaffold `Named_CalleeOf_*attachmentRe*`.
- Twin shape: `StdVector_InsertOne_RebindIt_Thiscall_Inferred` (`0x0040dbf0`, stride 4); RcElem28 twin `0x004612d0` (customcc).
