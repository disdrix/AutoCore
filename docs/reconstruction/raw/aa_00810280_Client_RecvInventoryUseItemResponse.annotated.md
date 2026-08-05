# Annotated low-level: Client_RecvInventoryUseItemResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810280` |
| **VA** | `0x00810280` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | inventory-transfer |
| **Source raw** | `aa_00810280_Client_RecvInventoryUseItemResponse.md` |
| **Refine** | Human pass 2026-07-23 (named_hl keyword wave) |

This file is the **annotated** layer: packet/UI offsets, branch order, and decompiler corrections.

---

## 1. Purpose

S2C use-item response: either consume/update stack counts on resolved item, or run failure UI path. Refreshes open mission windows and optional crafting/use UI.

## 2. Corrected signature

```c
void Client_RecvInventoryUseItemResponse(int pGameState);  /* packet residual ESI */
```

## 3. Key offsets / packet fields

| Offset / symbol | Role |
|---|---|
| `pkt+0x08/+0x0c` | item TFID dwords |
| `pkt+0x10` | int count / result quantity |
| `pkt+0x14` | short written to item+0x180 (stack/uses) |
| `game+0xe98` | local character |
| `game+0x10b0` | optional UI dialog |
| `game+0x309c` | optional secondary UI |

## 4. Machine-level notes

- Requires local char game+0xe98 and char+0x250 non-null (in-world).
- If packet+0x10 count < 1: FUN_00571d80(item TFID) then fail UI FUN_007fee30 + FUN_00933310.
- Else FUN_00571010(item TFID) → vtable+0x260(count@+0x10); write short@item+0x180 from pkt+0x14.
- Always Client_RefreshOpenMissionUiWindows(pGameState).
- If game+0x309c non-null: vtable+4(0). If dialog game+0x10b0 visible: vtable+0x450(0).

## 5. Pseudocode (authoritative raw, retained)

```c
void Client_RecvInventoryUseItemResponse(int param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int unaff_ESI;

  

  if ((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(*(int *)(param_1 + 0xe98) + 0x250) != 0)) {

    if (*(int *)(unaff_ESI + 0x10) < 1) {

      iVar2 = FUN_00571d80(*(undefined4 *)(unaff_ESI + 8),*(undefined4 *)(unaff_ESI + 0xc),0);

      if (iVar2 != 0) {

        FUN_007fee30();

        FUN_00933310(param_1,1,0,0xffffffff,0xffffffff);

      }

    }

    else {

      piVar3 = (int *)FUN_00571010(*(undefined4 *)(unaff_ESI + 8),*(undefined4 *)(unaff_ESI + 0xc));

      if (piVar3 != (int *)0x0) {

        (**(code **)(*piVar3 + 0x260))(*(undefined4 *)(unaff_ESI + 0x10));

        *(undefined2 *)(piVar3 + 0x60) = *(undefined2 *)(unaff_ESI + 0x14);

      }

    }

    Client_RefreshOpenMissionUiWindows(param_1);

    if (*(int *)(param_1 + 0x309c) != 0) {

      (**(code **)(**(int **)(param_1 + 0x309c) + 4))(0);

    }

    piVar3 = *(int **)(param_1 + 0x10b0);

    if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x3d8))(), cVar1 != '\0')) {

      (**(code **)(*piVar3 + 0x450))(0);

    }

  }

  return;

}
```

## 6. Open questions

- Map FUN_00571d80 / FUN_00571010 to inventory lookup by TFID names.
