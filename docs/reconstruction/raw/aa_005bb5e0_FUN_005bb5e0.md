# Raw capture: FUN_005bb5e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bb5e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bb5e0` |
| **Canonical name** | `FUN_005bb5e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 __thiscall FUN_005bb5e0(int param_1,undefined4 *param_2,undefined4 param_3)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int *piVar4;

  

  _DAT_00af3f68 = *param_2;

  piVar3 = (int *)**(int **)(param_1 + 0xa24);

  if (piVar3 != *(int **)(param_1 + 0xa24)) {

    do {

      iVar1 = piVar3[2];

      cVar2 = FUN_004b4620(param_3,*param_2);

      if (cVar2 == '\0') {

        FUN_005be2b0(iVar1);

        piVar4 = (int *)*piVar3;

        if (piVar3 != *(int **)(param_1 + 0xa24)) {

          *(int **)piVar3[1] = piVar4;

          *(int *)(*piVar3 + 4) = piVar3[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar3);

        }

      }

      else {

        piVar4 = (int *)*piVar3;

      }

      piVar3 = piVar4;

    } while (piVar4 != *(int **)(param_1 + 0xa24));

  }

  return *(undefined4 *)(param_1 + 0xa28);

}
```

---

## Re-verify append — 2026-07-29 W27-D

| Field | Value |
|---|---|
| **Tool** | Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes` |
| **Live decompile ≡ raw CF** | **Yes** walk/tick/unlink skeleton; **gap** post-delete count (bytes seal) |
| **Body** | `0x005bb5e0`–`0x005bb666` (**134 B / `0x86`**); pad `CC` after RET |
| **Classification** | **worker** |
| **Caller (1)** | `FUN_004b8ed0` (`NDSpecialFX_HostTick_Inferred`) @ `0x004b9103` — ECX = list`+0x1E0` payload; stack `(dt*, host+0x2C)` |
| **Callees** | `FUN_004b4620` (`ObjectMotion_SlotTick_Inferred` W26-H), `FUN_005be2b0`, `operator_delete` |
| **ABI** | `__thiscall` ECX = motion host; 2 stack formals; epilogue **`ret 8`** (`C2 08 00`); EAX = host`+0xA28` |
| **Entry** | `55 8B 6C 24 08 F3 0F 10 45 00 56 57 8B F9 8B 87 24 0A 00 00 … F3 0F 11 05 68 3F AF 00` |
| **Exit** | `8B 87 28 0A 00 00 5F 5E 5D C2 08 00` + `CC` pad |
| **Global** | `DAT_00af3f68` ← `*param_2` float; image default `3DCCCCCD` ≈ **0.1** |
| **Role name** | `ObjectMotion_SlotListTick_Inferred` (structural). **Reject** scaffold `Named_CalleeOf_…_005bb5e0`. |

### Control-flow (sealed + byte correction)

1. `DAT_00af3f68 = *(float*)param_2`.
2. Walk circular list host`+0xA24`.
3. payload=`node[2]`; `c = FUN_004b4620(param_3, *param_2)` with ECX=payload (SlotTick flag+dt, ret 8).
4. If `c==0`: `FUN_005be2b0(payload)`; if node≠sentinel unlink; `operator_delete(node)` **returns**; **`*(host+0xA28)--`** (`83 87 28 0A 00 00 FF` — **omitted by decompiler** due to false noreturn).
5. Else advance next.
6. Return `*(host+0xA28)`.

### Notes

- Sole dualed outer caller of SlotTick.
- HostTick only after `FUN_005bc3c0` keeps parent `+0x1E0` child.
- Port must decrement `+0xA28` on remove.
