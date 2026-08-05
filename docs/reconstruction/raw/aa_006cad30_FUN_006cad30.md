# Raw capture: FUN_006cad30

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cad30` |
| **Canonical name** | `FUN_006cad30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006cad30(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_2;
  if (param_2 != 0) {
    iVar4 = 0;
    if (0 < (int)param_2) {
      do {
        iVar1 = *(int *)(param_1 + 4 + iVar4 * 8);
        iVar2 = *(int *)(param_1 + iVar4 * 8);
        if (*(uint *)(iVar1 + 4) < *(uint *)(iVar2 + 4)) {
          *(int *)(param_1 + iVar4 * 8) = iVar1;
          *(int *)(param_1 + 4 + iVar4 * 8) = iVar2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)param_2);
    }
    param_2 = param_2 & 0xffffff00;
    if (1 < (int)uVar3) {
      FUN_006cac60(param_1,0,uVar3 - 1,param_2);
    }
  }
  return;
}
```

---

## W28-Q re-verify (2026-07-29) — append only

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W28-Q |
| **Tools** | `decompile_function`, `get_function_by_address`, `get_function_callers/callees/xrefs`, `get_function_signature`, `read_memory` (**no** `disassemble_bytes`) |
| **Live decompile** | ≡ raw 2026-07-23 |
| **Body** | `0x006cad30`–`0x006cad7f` exclusive (**79** B / `0x4F`) |
| **Epilogue** | `add esp,0x10` (clean qsort args) + `pop edi` + plain **`ret`** (cdecl) |
| **ABI** | **`__cdecl`**; `(pairArray*, count)`; void; plain `ret` |
| **Callees** | `FUN_006cac60` only (quicksort of 8-byte pairs) |
| **Callers (4 / 6 xrefs)** | `FUN_006297e0` ×2, `FUN_00634450` ×2, `FUN_0055ff20` ×1, `FUN_00560020` ×1 |
| **Signature metrics** | 35 insns, 10 BB, 1 call, complexity 6 |
| **Stride** | 8 bytes per element (two pointers) |
| **Key** | `*(uint*)(ptr + 4)` on each pointed object |
| **Inferred name** | `LinkPair_CanonAndSort_Inferred` |
| **Full body hex (79 B)** | `578b7c240c85ff74458b4c240833c085ff7e1f53568b54c1048b34c18b5e043b5a0476078914c18974c104403bc77ce55e5b83ff01c644240c007e128b44240c504f576a0051e8e5feffff83c4105fc3` |

### Semantics seal

1. If `count == 0` → return.
2. For `i in [0, count)`: pair = `(a,b)` at `array[i*8]`; if `b->key4 < a->key4`, swap → **canonicalize** within-pair order so first key ≤ second key (unsigned).
3. Zero low byte of stack count (`mov byte [esp+count], 0` ≡ `count & 0xffffff00`); unused 4th arg to qsort.
4. If original `count > 1` → `FUN_006cac60(array, 0, count-1, count_lo_cleared)` — dual-key quicksort on `(first+4, second+4)`.

### Context

Prep for sorted dual-range merge (`FUN_006caaa0` LinkPair_SortedDiffWalk) and pair-list commit (`FUN_006297e0` Phys_CommitPairListStorage). Callers dual-invoke on list A and list B.
