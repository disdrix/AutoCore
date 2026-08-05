# Raw capture: FUN_006caaa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006caaa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006caaa0` |
| **Canonical name** | `FUN_006caaa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall

FUN_006caaa0(int param_1,int *param_2,int *param_3,int *param_4,int param_5,undefined4 *param_6)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  char *pcVar5;

  int iVar6;

  undefined4 *puVar7;

  int *piVar8;

  int *piVar9;

  

  param_3 = param_2 + (int)param_3 * 2;

  piVar1 = param_4 + param_5 * 2;

  puVar7 = param_6;

  piVar8 = param_2;

  piVar9 = param_4;

  param_4 = piVar1;

  if (param_2 != param_3) {

    do {

      if (piVar9 == param_4) break;

      uVar2 = *(uint *)(*piVar8 + 4);

      uVar3 = *(uint *)(*piVar9 + 4);

      if ((uVar3 == uVar2) && (puVar7 = param_6, *(int *)(piVar9[1] + 4) == *(int *)(piVar8[1] + 4))

         ) {

        piVar8 = piVar8 + 2;

        piVar9 = piVar9 + 2;

      }

      else if ((uVar3 < uVar2) ||

              ((uVar3 == uVar2 && (*(uint *)(piVar9[1] + 4) < *(uint *)(piVar8[1] + 4))))) {

        (**(code **)(**(int **)(param_1 + (*(int *)(piVar9[1] + 8) + *(int *)(*piVar9 + 8) * 8) * 4)

                    + 8))(piVar9);

        piVar9 = piVar9 + 2;

      }

      else {

        if (*piVar8 == 0) {

          iVar6 = 0;

        }

        else {

          iVar6 = *piVar8 + -0x10;

        }

        if (piVar8[1] == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = piVar8[1] + -0x10;

        }

        pcVar5 = (char *)(**(code **)*puVar7)(&param_2,iVar6,iVar4);

        if (*pcVar5 != '\0') {

          (**(code **)(**(int **)(param_1 +

                                 (*(int *)(piVar8[1] + 8) + *(int *)(*piVar8 + 8) * 8) * 4) + 4))

                    (piVar8);

        }

        piVar8 = piVar8 + 2;

      }

    } while (piVar8 != param_3);

  }

  if (piVar8 < param_3) {

    do {

      if (*piVar8 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *piVar8 + -0x10;

      }

      if (piVar8[1] == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = piVar8[1] + -0x10;

      }

      pcVar5 = (char *)(**(code **)*puVar7)(&param_6,iVar6,iVar4);

      if (*pcVar5 != '\0') {

        (**(code **)(**(int **)(param_1 + (*(int *)(piVar8[1] + 8) + *(int *)(*piVar8 + 8) * 8) * 4)

                    + 4))(piVar8);

      }

      piVar8 = piVar8 + 2;

    } while (piVar8 < param_3);

  }

  if (piVar9 < param_4) {

    do {

      (**(code **)(**(int **)(param_1 + (*(int *)(piVar9[1] + 8) + *(int *)(*piVar9 + 8) * 8) * 4) +

                  8))(piVar9);

      piVar9 = piVar9 + 2;

    } while (piVar9 < param_4);

  }

  return;

}
```


---

## W27-N re-verify (2026-07-29) — live Ghidra seal

| Field | Value |
|---|---|
| **Agent** | W27-N OWN-ONLY dual |
| **Tools** | `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs (**no** `disassemble_bytes`) |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body** | `0x006caaa0`–`0x006cac19` inclusive (**378 / `0x17A` B**); pad `CC` after `ret 0x14` |
| **Prologue (read_memory)** | `51 8B 44 24 0C 53 55 8B 6C 24 20 56 8B 74 24 14 8B D9 ...` — `MOV EBX,ECX` (this); dual range end via `LEA reg,[base+count*8]` |
| **Epilogue (read_memory @ 0x006cac12)** | `5F 5E 5D 5B 59 C2 14 00` — pop EDI/ESI/EBP/EBX/ECX; **`ret 0x14`** (5 stack formals) |
| **ABI** | **thiscall**; ECX = handler-table base (`param_1`); 5 stack formals; void |
| **Classification** | worker (indirect vcalls only; no direct FUN_* callees) |
| **Callers (6)** | `FUN_0055fa40`, `FUN_0055fbf0`, `FUN_0055ff20`, `FUN_00560020`, `FUN_006297e0`, `FUN_00634450` (6 xrefs) |
| **Named role (INFERRED)** | `LinkPair_SortedDiffWalk_Inferred` |
| **Integrity** | Live decompile 2026-07-29 ≡ raw 2026-07-23 body (byte-identical CF text) |

### Live decompile (authoritative 2026-07-29)

```c
void __thiscall
FUN_006caaa0(int param_1,int *param_2,int *param_3,int *param_4,int param_5,undefined4 *param_6)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  
  param_3 = param_2 + (int)param_3 * 2;
  piVar1 = param_4 + param_5 * 2;
  puVar7 = param_6;
  piVar8 = param_2;
  piVar9 = param_4;
  param_4 = piVar1;
  if (param_2 != param_3) {
    do {
      if (piVar9 == param_4) break;
      uVar2 = *(uint *)(*piVar8 + 4);
      uVar3 = *(uint *)(*piVar9 + 4);
      if ((uVar3 == uVar2) && (puVar7 = param_6, *(int *)(piVar9[1] + 4) == *(int *)(piVar8[1] + 4))
         ) {
        piVar8 = piVar8 + 2;
        piVar9 = piVar9 + 2;
      }
      else if ((uVar3 < uVar2) ||
              ((uVar3 == uVar2 && (*(uint *)(piVar9[1] + 4) < *(uint *)(piVar8[1] + 4))))) {
        (**(code **)(**(int **)(param_1 + (*(int *)(piVar9[1] + 8) + *(int *)(*piVar9 + 8) * 8) * 4)
                    + 8))(piVar9);
        piVar9 = piVar9 + 2;
      }
      else {
        if (*piVar8 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *piVar8 + -0x10;
        }
        if (piVar8[1] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = piVar8[1] + -0x10;
        }
        pcVar5 = (char *)(**(code **)*puVar7)(&param_2,iVar6,iVar4);
        if (*pcVar5 != '\0') {
          (**(code **)(**(int **)(param_1 +
                                 (*(int *)(piVar8[1] + 8) + *(int *)(*piVar8 + 8) * 8) * 4) + 4))
                    (piVar8);
        }
        piVar8 = piVar8 + 2;
      }
    } while (piVar8 != param_3);
  }
  if (piVar8 < param_3) {
    do {
      if (*piVar8 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *piVar8 + -0x10;
      }
      if (piVar8[1] == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = piVar8[1] + -0x10;
      }
      pcVar5 = (char *)(**(code **)*puVar7)(&param_6,iVar6,iVar4);
      if (*pcVar5 != '\0') {
        (**(code **)(**(int **)(param_1 + (*(int *)(piVar8[1] + 8) + *(int *)(*piVar8 + 8) * 8) * 4)
                    + 4))(piVar8);
      }
      piVar8 = piVar8 + 2;
    } while (piVar8 < param_3);
  }
  if (piVar9 < param_4) {
    do {
      (**(code **)(**(int **)(param_1 + (*(int *)(piVar9[1] + 8) + *(int *)(*piVar9 + 8) * 8) * 4) +
                  8))(piVar9);
      piVar9 = piVar9 + 2;
    } while (piVar9 < param_4);
  }
  return;
}
```

### Sealed CF (structural)

Two sorted ranges of **8-byte pair entries** (`int[2]` / pointer pairs), advanced as `pi+2`:

| Case | Condition (keys at node+4, secondary at partner+4) | Action |
|---|---|---|
| Equal | primary equal AND secondary equal | advance both cursors |
| Right-only | right primary < left, or same primary and right secondary < left | handler-table vcall **+8** on right pair; advance right |
| Left-only | otherwise | optional predicate `(*param_6)[0](...)`; if non-zero, handler-table vcall **+4** on left pair; advance left |
| Left tail | left remaining after right exhausted | same left-only predicate + vcall+4 |
| Right tail | right remaining after left exhausted | vcall+8 only |

Handler index: `(partner.field8 + node.field8 * 8)` → dword index into `param_1` table → vtable base.

### Call-site role (OWN callers sealed elsewhere)

- `WorldObj_BindLinks_Inferred` / `WorldObj_UnbindLinks_Inferred` complex branch when `*(obj+0x40) != 0`.
- Simple twin path uses `FUN_006297e0` only (not this VA).
