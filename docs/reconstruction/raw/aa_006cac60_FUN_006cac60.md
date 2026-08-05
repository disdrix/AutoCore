# Raw capture: FUN_006cac60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cac60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cac60` |
| **Canonical name** | `FUN_006cac60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006cac60(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  do {
    iVar7 = param_2 + param_3 >> 1;
    iVar1 = *(int *)(param_1 + iVar7 * 8);
    iVar7 = *(int *)(param_1 + 4 + iVar7 * 8);
    iVar6 = param_3;
    iVar8 = param_2;
    do {
      uVar2 = *(uint *)(iVar1 + 4);
      while ((uVar3 = *(uint *)(*(int *)(param_1 + iVar8 * 8) + 4), uVar3 < uVar2 ||
             ((uVar3 == uVar2 &&
              (*(uint *)(*(int *)(param_1 + 4 + iVar8 * 8) + 4) < *(uint *)(iVar7 + 4)))))) {
        iVar8 = iVar8 + 1;
      }
      while ((uVar3 = *(uint *)(*(int *)(param_1 + iVar6 * 8) + 4), uVar2 < uVar3 ||
             ((uVar2 == uVar3 &&
              (*(uint *)(iVar7 + 4) < *(uint *)(*(int *)(param_1 + 4 + iVar6 * 8) + 4)))))) {
        iVar6 = iVar6 + -1;
      }
      if (iVar6 < iVar8) break;
      if (iVar6 != iVar8) {
        uVar4 = *(undefined4 *)(param_1 + iVar6 * 8);
        uVar5 = *(undefined4 *)(param_1 + 4 + iVar6 * 8);
        *(undefined4 *)(param_1 + iVar6 * 8) = *(undefined4 *)(param_1 + iVar8 * 8);
        *(undefined4 *)(param_1 + 4 + iVar6 * 8) = *(undefined4 *)(param_1 + 4 + iVar8 * 8);
        *(undefined4 *)(param_1 + iVar8 * 8) = uVar4;
        *(undefined4 *)(param_1 + 4 + iVar8 * 8) = uVar5;
      }
      iVar6 = iVar6 + -1;
      iVar8 = iVar8 + 1;
    } while (iVar8 <= iVar6);
    if (param_2 < iVar6) {
      FUN_006cac60(param_1,param_2,iVar6,param_4);
    }
    param_2 = iVar8;
    if (param_3 <= iVar8) {
      return;
    }
  } while( true );
}
```
## W29-Q re-verify (2026-07-29) — append only

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W29-Q |
| **Tools** | `decompile_function`, `get_function_by_address`, `get_function_callers/callees`, `get_xrefs_to`, `get_function_signature`, `read_memory` (**no** `disassemble_bytes`) |
| **Live decompile** | ≡ raw 2026-07-23 |
| **Body** | `0x006cac60`–`0x006cad2f` exclusive (**207** B / `0xCF`); pad `CC` after plain `ret` |
| **Prologue** | `push ebp; mov ebp,esp; and esp,0xfffffff0; sub esp,0x14` (16-byte stack align) |
| **Epilogue** | `pop edi; pop esi; pop ebx; mov esp,ebp; pop ebp; ret` (cdecl) |
| **ABI** | **`__cdecl`**; `(LinkPair8* array, int lo, int hi, unused)`; void; plain **`ret`**; callee cleans nothing (`add esp,0x10` at call sites) |
| **Callees** | self only (`FUN_006cac60` recursive left partition) |
| **Callers (2 / 2 xrefs)** | `FUN_006cad30` LinkPair_CanonAndSort @ `006cad76`; self @ `006cad11` |
| **Signature metrics** | 84 insns, 21 BB, 1 call (self), complexity 13 |
| **Stride** | 8 bytes (two pointers) |
| **Compare** | dual-key unsigned: primary `*(uint*)(pair.a + 4)`, secondary `*(uint*)(pair.b + 4)` |
| **Inferred name** | `LinkPair_QuickSort_DualKey_Inferred` |
| **Full body hex (207 B)** | `558bec83e4f083ec148b451053568b7508578b7d0c8d0c07d1f98b14ce8b5cce0489542410895c2414eb058b5c2414908b4c24108b51048b0cfe8b49043bca721375148b4cfe048b49043b4b040f92c184c9740347ebe08b0cc68b49043bd1721375188b4cc6048b5b043b59040f92c184c974078b5c241448ebdc3bc77c24741c8b1cfe8b0cc68b54c604891cc68b5cfe04895cc604890cfe8954fe0448473bf87e888b4d0c3bc87d0f8b551452505156e84affffff83c4108b45103bf87d08897d0ce94affffff5f5e5b8be55dc3` |

### Semantics seal

1. Classic dual-partition quicksort over inclusive `[lo, hi]` on array of 8-byte pairs.
2. Pivot = mid index `(lo+hi)>>1`; hold pivot pair pointers `(pivotA, pivotB)`.
3. Advance `i` while pair[i] **<** pivot (primary key4, then secondary key4); retreat `j` while pivot **<** pair[j]; swap full 8-byte pairs when `i <= j`.
4. Recurse left: if `lo < j` call `FUN_006cac60(array, lo, j, unused)`.
5. Right partition via outer-loop tail: set `lo = i`; if `hi <= i` return; else continue (no right recurse).
6. **`param_4` unused** in body (passed through from CanonAndSort low-byte-cleared count; dead arg).

### Context

Nested qsort of `LinkPair_CanonAndSort_Inferred` (W28-Q). Prep for sorted dual-range merge (`006caaa0`) and pair-list commit (`006297e0`). Closes nested residual left open by W28-Q.
