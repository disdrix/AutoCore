# Raw capture: FUN_004bcbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcbf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bcbf0` |
| **Canonical name** | `FUN_004bcbf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bcbf0(undefined4 *param_1)



{

  undefined4 *puVar1;

  

  *param_1 = &PTR_FUN_009cb368;

  puVar1 = (undefined4 *)FUN_0040b020();

  while (puVar1 != (undefined4 *)0x0) {

    (**(code **)*puVar1)(1);

    puVar1 = (undefined4 *)FUN_0040b020();

  }

  param_1[3] = 0;

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 10));

  return;

}
```

---

## Append — dual A/B seal W25-C (2026-07-29)

| Field | Value |
|---|---|
| **Canonical name** | `ThreadSafeObjectList_Dtor` (structural; **Inferred** product English) |
| **Body** | `0x004bcbf0`–`0x004bcc31` (66 B; ends `ret` / `C3`) |
| **Tools** | `decompile_function`, `read_memory`, `get_function_by_address`, `analyze_function_complete`, callees/callers/xrefs |
| **Three-rep** | raw CF ≡ live decompile ≡ body bytes |
| **Dual verdict** | **accept** (A+B) |
| **No** | `disassemble_bytes`; Launcher; parent ledgers |

### Body bytes (`read_memory` @ `0x004bcbf0`, 66 B)

```
56                   push  esi
8B F1                mov   esi, ecx              ; this = list*
57                   push  edi
C7 06 68 B3 9C 00    mov   dword [esi], 0x009cb368  ; vtbl = PTR_FUN_009cb368
E8 21 E4 F4 FF       call  ThreadSafeObjectList_PopFront  ; 0x0040b020
85 C0                test  eax, eax
74 13                jz    drain_done
; loop:
8B 10                mov   edx, [eax]            ; payload vtbl
6A 01                push  1
8B C8                mov   ecx, eax
FF 12                call  [edx]                 ; payload->dtor(1)  (thiscall)
8B CE                mov   ecx, esi
E8 0E E4 F4 FF       call  PopFront              ; 0x0040b020
85 C0                test  eax, eax
75 ED                jnz   loop
drain_done:
8B 3D F0 61 9C 00    mov   edi, [DeleteCriticalSection]
8D 46 10             lea   eax, [esi+0x10]
50                   push  eax
C7 46 0C 00 00 00 00 mov   dword [esi+0x0C], 0   ; count = 0
FF D7                call  edi                   ; DeleteCS(inner +0x10)
83 C6 28             add   esi, 0x28
56                   push  esi
FF D7                call  edi                   ; DeleteCS(outer +0x28)
5F                   pop   edi
5E                   pop   esi
C3                   ret
```

Hex: `568bf157c70668b39c00e821e4f4ff85c074138b106a018bc8ff128bcee80ee4f4ff85c075ed8b3df0619c008d461050c7460c00000000ffd783c62856ffd75f5ec3`

### Sealed ABI / CF

- **`__thiscall` / `__fastcall`**: ECX = `ThreadSafeObjectList*`; no stack formals; epilogue **`ret`**.
- Install list vtbl `PTR_FUN_009cb368` (slot0 = scalar-deleting dtor `FUN_004bcc40` → this body).
- Drain: loop `payload = PopFront(this)` until NULL; for each payload call `(*payload->vtbl)(payload, 1)` (owned-object delete). Nodes already freed inside PopFront.
- Zero count at `+0x0C`; `DeleteCriticalSection` at **`+0x10`** (inner) then **`+0x28`** (outer).
- Layout matches sealed twin `aa_0040b020` ThreadSafeObjectList_PopFront.

### Call surface

| Direction | Targets |
|---|---|
| Callees | `FUN_0040b020` (PopFront), `DeleteCriticalSection` |
| Callers | `FUN_004bcc40` (scalar deleting dtor), `FUN_004d64d0`, `FUN_004bbc70`, `FUN_0058c850` (×2), SEH `Unwind@009a5750` |

### Reviews

- A: `docs/reconstruction/reviews/A_aa_004bcbf0_ThreadSafeObjectList_Dtor.md`
- B: `docs/reconstruction/reviews/B_aa_004bcbf0_ThreadSafeObjectList_Dtor.md`

