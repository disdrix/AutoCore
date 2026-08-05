# Raw capture: FUN_008a0ed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0ed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008a0ed0` |
| **Canonical name** | `FUN_008a0ed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008a0ed0(int *param_1)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  
  if ((-1 < in_EAX) && (in_EAX < 10)) {
    param_1[0x143] = in_EAX;
    iVar1 = *(int *)(&DAT_00d1da38 + in_EAX * 4);
    piVar2 = param_1 + 399;
    iVar3 = 10;
    do {
      if ((*piVar2 != 0) &&
         (*(int *)(*piVar2 + 0x504) = param_1[0x143], *(char *)(*piVar2 + 0x4fc) != '\0')) {
        FUN_00826780(0);
      }
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_008a0e10(param_1);
    (**(code **)(*param_1 + 0x448))();
    if ((((iVar1 < 0) || (9 < iVar1)) || (iVar1 = param_1[iVar1 + 399], iVar1 == 0)) ||
       ((*(uint *)(iVar1 + 0x550) & *(uint *)(iVar1 + 0x554)) == 0xffffffff)) {
      FUN_008a0210(1);
    }
    else {
      FUN_00826780(1);
    }
    if (-1 < DAT_00d1a9fc) {
      if (param_1[DAT_00d1a9fc + 399] != 0) {
        (**(code **)(*(int *)param_1[DAT_00d1a9fc + 399] + 0x44c))(0);
      }
      DAT_00d1a9fc = -1;
    }
                    /* WARNING: Could not recover jumptable at 0x008a0fa7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x34c))();
    return;
  }
  return;
}
```

---

## Re-verify 2026-07-29 (append only)

- Tool: Ghidra `decompile_function` @ `0x008a0ed0` — body **byte-identical** to scaffold capture above.
- Dual A/B: `reviews/A_aa_008a0ed0_QuickBar_SelectPage_Inferred.md` / `B_*` ? **accept-with-gaps**.
- Inferred name: `QuickBar_SelectPage_Inferred` (page 0..9; not slot activate).
- Clean plate: `reconstructed-exact/QuickBar_SelectPage_Inferred.cpp`.
