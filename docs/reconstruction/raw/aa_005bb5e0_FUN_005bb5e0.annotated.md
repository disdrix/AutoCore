# Annotated low-level: FUN_005bb5e0 / ObjectMotion_SlotListTick_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005bb5e0` |
| VA | `0x005bb5e0`–`0x005bb666` (134 B / `0x86`) |
| System | client object motion / reaction slot list |
| Date | 2026-07-29 W27-D |
| Preferred name | `ObjectMotion_SlotListTick_Inferred` |
| Ghidra name | `FUN_005bb5e0` |

## Machine-level notes

- `__thiscall` ECX = motion host (HostTick sets ECX = FX list`+0x1E0` payload).
- Stack: `param_2` = float* dt; `param_3` = flag (FX host`+0x2C`); **`ret 8`**.
- `movss` stores dt into `DAT_00af3f68` before walk.
- Sole dualed caller of `ObjectMotion_SlotTick_Inferred` @ `0x005bb611`.
- **Decompiler gap:** false noreturn on `operator_delete` drops `*(host+0xA28)--`. Bytes: `83 87 28 0A 00 00 FF`.

## Pseudocode (live + byte correction)

```c
uint32_t __thiscall FUN_005bb5e0(int param_1, uint32_t *param_2, uint32_t param_3)
{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;

  _DAT_00af3f68 = *param_2; /* float store */
  piVar3 = (int *)**(int **)(param_1 + 0xa24);
  if (piVar3 != *(int **)(param_1 + 0xa24)) {
    do {
      iVar1 = piVar3[2];
      cVar2 = FUN_004b4620(param_3, *param_2); /* ECX=iVar1 */
      if (cVar2 == '\0') {
        FUN_005be2b0(iVar1);
        piVar4 = (int *)*piVar3;
        if (piVar3 != *(int **)(param_1 + 0xa24)) {
          *(int **)piVar3[1] = piVar4;
          *(int *)(*piVar3 + 4) = piVar3[1];
          operator_delete(piVar3); /* RETURNS */
          *(int *)(param_1 + 0xa28) = *(int *)(param_1 + 0xa28) - 1; /* BYTE SEALED */
        }
      }
      else {
        piVar4 = (int *)*piVar3;
      }
      piVar3 = piVar4;
    } while (piVar4 != *(int **)(param_1 + 0xa24));
  }
  return *(uint32_t *)(param_1 + 0xa28);
}
```

## Offset map

| Offset | Role |
|---|---|
| `+0xA24` | Circular slot list head |
| `+0xA28` | Count (return; -- on remove) |

## Open questions

- Product class of motion host.
- Dual of `FUN_005be2b0` teardown (not OWN).
