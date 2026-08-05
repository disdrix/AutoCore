# Annotated low-level: FUN_008a0ed0 → QuickBar_SelectPage_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008a0ed0` |
| VA | `0x008a0ed0` |
| System | `skills-abilities` |
| Date | 2026-07-23 scaffold; **2026-07-29 dual re-verify** |

## Machine-level notes

- Source: raw capture for `aa_008a0ed0` (body unchanged 2026-07-29 re-decompile match).
- Dual name: `QuickBar_SelectPage_Inferred` (no product string; leave Ghidra FUN until registry).
- ABI: **ECX** = QB host; **EAX** = page index (phantom `in_EAX` in decomp).
- Prefer assembly only if decompiler conflicts; this unit CF is stable.

## Pseudocode (annotated)

```c
void __fastcall FUN_008a0ed0(int *param_1)  // host; page in EAX
{
  int iVar1;       // prevCol = DAT_00d1da38[page]
  int in_EAX;      // page index
  int *piVar2;     // walk host+399 column widget ptrs
  int iVar3;       // remaining = 10
  
  // Gate: only pages 0..9
  if ((-1 < in_EAX) && (in_EAX < 10)) {
    param_1[0x143] = in_EAX;                          // host+0x50c = current page
    iVar1 = *(int *)(&DAT_00d1da38 + in_EAX * 4);     // last selected column on this page
    piVar2 = param_1 + 399;                           // +0x63c
    iVar3 = 10;
    do {
      if ((*piVar2 != 0) &&
         // stamp page onto widget+0x504; if selected (+0x4fc) deactivate
         (*(int *)(*piVar2 + 0x504) = param_1[0x143], *(char *)(*piVar2 + 0x4fc) != '\0')) {
        FUN_00826780(0);                              // thiscall: this=*piVar2, activate=0
      }
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);

    FUN_008a0e10(param_1);                            // rebind from DAT_00d1da60[page*10+i]
    (**(code **)(*param_1 + 0x448))();                // host chrome refresh

    // Restore previous column if valid + non-empty; else auto-pick forward
    if ((((iVar1 < 0) || (9 < iVar1)) || (iVar1 = param_1[iVar1 + 399], iVar1 == 0)) ||
       ((*(uint *)(iVar1 + 0x550) & *(uint *)(iVar1 + 0x554)) == 0xffffffff)) {
      FUN_008a0210(1);                                // direction +1 auto-select
    }
    else {
      FUN_00826780(1);                                // this=iVar1, activate=1
    }

    // Clear residual hover/focus column
    if (-1 < DAT_00d1a9fc) {
      if (param_1[DAT_00d1a9fc + 399] != 0) {
        (**(code **)(*(int *)param_1[DAT_00d1a9fc + 399] + 0x44c))(0);
      }
      DAT_00d1a9fc = -1;
    }
    /* WARNING: Could not recover jumptable at 0x008a0fa7. Too many branches */
    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x34c))();                // host final layout/paint
    return;
  }
  return;
}
```

## Offsets / globals

| Symbol / off | Meaning (dual) |
|---|---|
| host `+0x50c` / `[0x143]` | Current page |
| host `+0x63c` / `[399]`×10 | Column widget pointers |
| `DAT_00d1da38[page]` | Last selected column on page |
| `DAT_00d1a9fc` | Hover column residual (−1 none) |
| widget `+0x4fc` | Selected flag |
| widget `+0x500` | Column index (source for d1da38 write on activate) |
| widget `+0x504` | Page stamp |
| widget `+0x550`/`+0x554` | Empty dual-dword mask |

## Callers (2026-07-29)

| Caller | Role |
|---|---|
| `Client_QuickBar_ActivateSlot` @ mode 1 | shift-QB page select |
| `FUN_008a0fb0` | page ± delta |
| `FUN_008a0fe0` | show/refresh path |
| `FUN_009114f0` | input bind next page |
| `Client_SkillTrainUiRequest_INFERRED` | post auto-map UI refresh |

## Open questions

1. Exact EAX handoff at each caller (decomp drops register math).
2. Product names for callees `FUN_008a0e10` / `FUN_00826780` / `FUN_008a0210`.
3. `DAT_00d1da60` vs `client+0x3220` ownership (out of unit).
4. Runtime page-switch capture; bit-for-bit.

## Dual verdict

**accept-with-gaps** — see `reviews/A_aa_008a0ed0_QuickBar_SelectPage_Inferred.md` / `B_*`.
