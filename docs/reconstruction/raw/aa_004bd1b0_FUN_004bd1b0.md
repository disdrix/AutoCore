# Raw capture: FUN_004bd1b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bd1b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bd1b0` |
| **Canonical name** | `FUN_004bd1b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void * __thiscall FUN_004bd1b0(void *param_1,byte param_2)



{

  FUN_004bbc70();

  if ((param_2 & 1) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return param_1;

}
```

---

## W27-L live re-verify (2026-07-29) — APPEND ONLY

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W27-L |
| **Tools** | `decompile_function` + `read_memory` + `get_function_by_address` + `analyze_function_complete` + xrefs (**no** `disassemble_bytes`) |
| **Body** | `0x004bd1b0`–`0x004bd1cd` (**30 B / `0x1E`**); pad `CC CC` after last instruction |
| **Live decompile** | **≡** 2026-07-23 raw scaffold body (byte-identical CF) |
| **ABI** | `__thiscall`; ECX=`this`; stack flags byte; epilogue **`ret 4`** (`C2 04 00`); returns `this` in EAX |
| **Role** | MSVC **scalar-deleting destructor** for **COList** (`vtbl[0]` of `PTR_FUN_009cb448`) |
| **Callees** | `FUN_004bbc70` (`COList_Destructor`); `operator_delete` if `(flags & 1)` |
| **Xrefs** | DATA from `0x009cb448` (vtable slot 0) only |

### Machine bytes (`read_memory` full body)

```
004bd1b0  56 8B F1 E8 B8 EA FF FF F6 44 24 08 01 74 09 56
004bd1c0  E8 5D C6 FC FF 83 C4 04 8B C6 5E C2 04 00
```

| Decode (from bytes, not disasm tool) | Note |
|---|---|
| `56 8B F1` | push ESI; mov ESI, ECX (`this`) |
| `E8 B8 EA FF FF` | call `FUN_004bbc70` (`0x004bbc70`) |
| `F6 44 24 08 01` | test byte `[esp+8], 1` (flags after push) |
| `74 09` | jz skip delete |
| `56 E8 … 83 C4 04` | push ESI; `operator_delete`; add esp,4 |
| `8B C6 5E C2 04 00` | mov EAX,ESI; pop ESI; **ret 4** |

### Named clean

`COList_ScalarDeletingDestructor` — see function record + dual A/B.

