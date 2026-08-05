# Raw capture: FUN_004bcc40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bcc40` |
| **Canonical name** | `FUN_004bcc40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void * __thiscall FUN_004bcc40(void *param_1,byte param_2)



{

  FUN_004bcbf0();

  if ((param_2 & 1) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_1);

  }

  return param_1;

}
```


---

## Live re-decompile (2026-07-29 W26-I)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `analyze_function_complete` |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body** | `0x004bcc40`–`0x004bcc5d` (**30 B** inclusive last byte of `RET 4`; pad `CC` after) |
| **Epilogue** | `8B C6 5E C2 04 00` (`MOV EAX,ESI; POP ESI; RET 4`) |
| **Classification** | worker / MSVC scalar deleting dtor |
| **Callees** | `FUN_004bcbf0` (`ThreadSafeObjectList_Dtor`), `operator_delete` |
| **Callers** | none direct (virtual via vtbl) |
| **Xrefs** | 1 data: `PTR_FUN_009cb368` slot0 → this VA (`read_memory` LE `40 CC 4B 00`) |
| **Integrity** | Live decompile ≡ 2026-07-23 raw body (identical CF) |

### Machine hex (full body)

```
568bf1e8a8fffffff644240801740956e8cdcbfcff83c4048bc65ec20400
```

### Sealed ABI

```
// __thiscall; ECX = this (ThreadSafeObjectList*); stack uint8_t flags; RET 4; EAX = this
// void *ThreadSafeObjectList_ScalarDeletingDtor(ThreadSafeObjectList *this, uint8_t flags)
// 1) ThreadSafeObjectList_Dtor(this)   // body FUN_004bcbf0
// 2) if (flags & 1) operator_delete(this)
// 3) return this
```

### Live decompile (identical to raw)

```c
void * __thiscall FUN_004bcc40(void *param_1,byte param_2)
{
  FUN_004bcbf0();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}
```

### Byte walk (`read_memory`)

```
004bcc40  56                 push esi
004bcc41  8B F1              mov  esi, ecx          ; this
004bcc43  E8 A8 FF FF FF     call FUN_004bcbf0      ; next-IP 004bcc48 + (−0x58) = 004bcbf0
004bcc48  F6 44 24 08 01     test byte [esp+8], 1   ; flags after push
004bcc4D  74 09              jz   no_free
004bcc4F  56                 push esi
004bcc50  E8 CD CB FC FF     call operator_delete
004bcc55  83 C4 04           add  esp, 4
no_free:
004bcc58  8B C6              mov  eax, esi
004bcc5A  5E                 pop  esi
004bcc5B  C2 04 00           ret  4
```
