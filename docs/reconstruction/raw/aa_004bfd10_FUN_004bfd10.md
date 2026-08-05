# Raw capture: FUN_004bfd10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfd10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bfd10` |
| **Canonical name** | `FUN_004bfd10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004bfd10(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  
  uVar4 = 0;
  piVar3 = (int *)(param_1 + 8);
  do {
    if (piVar3[1] != 0) {
      piVar5 = *(int **)*piVar3;
      if (piVar5 != (int *)*piVar3) {
        do {
          puVar1 = (undefined4 *)piVar5[2];
          cVar2 = FUN_005c6720(param_2);
          if (cVar2 != '\0') {
            if (piVar5 == *(int **)(param_1 + 8 + uVar4 * 0xc)) {
              if (puVar1 != (undefined4 *)0x0) {
                (**(code **)*puVar1)(1);
              }
              return 1;
            }
            *(int *)piVar5[1] = *piVar5;
            *(int *)(*piVar5 + 4) = piVar5[1];
                    /* WARNING: Subroutine does not return */
            operator_delete(piVar5);
          }
          piVar5 = (int *)*piVar5;
        } while (piVar5 != (int *)*piVar3);
      }
    }
    uVar4 = uVar4 + 1;
    piVar3 = piVar3 + 3;
  } while (uVar4 < 9);
  return 0;
}
```

---

## W37-T re-verify append (2026-08-04)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `batch_decompile` + `read_memory` + `analyze_function_complete` + caller `get_assembly_context` |
| **Integrity** | Original raw body above preserved; this section is append-only |

### Live decompile

Matches original raw CF spine. **Correction:** Ghidra WARNING that `operator_delete` does not return is **false** — bytes continue with count--, payload scalar-deleting dtor, `mov al,1; ret 4`.

### Body bytes (146 B @ 0x004bfd10–0x004bfda1)

```
5153555657894c241033ed8d59088bff837b040074238b038b303bf0741b8bff8b7e088b442418508bcfe8e169100084c0751b8b363b3375e783c50183c30c83fd0972cc5f5e5d32c05b59c204008b5424108d4c6d003b748a088d5c8a04741c8b46048b0e89088b168b460456894204e89d9afcff83c404834308ff85ff74088b176a018bcfff125f5e5db0015b59c20400
```

### Machine notes

- Fail and success exits: `c2 04 00` (ret 4).
- 9 buckets × 0xC from `this+8`; match via `FUN_005c6720`.
- Pad `CC` then sibling `FUN_004bfdb0` @ `0x004bfdb0`.
- Role sealed: `TrackMgr_9CircList_UntrackObject_Inferred` (W37-T dual A+B **accept-with-gaps**).
