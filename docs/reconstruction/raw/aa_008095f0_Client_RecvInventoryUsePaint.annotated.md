# Annotated low-level: Client_RecvInventoryUsePaint

| Field | Value |
|---|---|
| **Stable ID** | `aa_008095f0` |
| **VA** | `0x008095f0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | inventory-transfer |
| **Source raw** | `aa_008095f0_Client_RecvInventoryUsePaint.md` |
| **Refine** | Human pass 2026-07-23 (named_hl keyword wave) |

This file is the **annotated** layer: packet/UI offsets, branch order, and decompiler corrections.

---

## 1. Purpose

S2C apply vehicle paint / color from inventory-use path. Resolves target TFID, requires clone type 0x0E (vehicle), then applies paint channel helpers and optional local refresh.

## 2. Corrected signature

```c
void Client_RecvInventoryUsePaint(int pGameState);  /* packet base residual in EDI */
```

## 3. Key offsets / packet fields

| Offset / symbol | Role |
|---|---|
| `pkt+0x10` | target TFID (16-byte) |
| `pkt+0x20` | paint/color byte argument |
| `pkt+0x21` | paint mode: 0 or 1 selects apply helper |
| `obj.vtbl+0x1d4` | body/handle getter |
| `clone+0x38` | type; 0x0E = vehicle |
| `char+0xcd0` | local vehicle object ptr compare |

## 4. Machine-level notes

- Object_ResolveFromTFID(packet+0x10); require clone type field +0x38 == 0x0E.
- vtable+0x1d4 must return non-null body/handle before paint apply.
- packet+0x21 selects paint path: 0 → FUN_004faaf0, 1 → FUN_004fab40 (color byte @+0x20).
- If resolved object is local vehicle at char+0xcd0, FUN_0051f4e0(0) refresh.
- Always FUN_004fcd80(0) on success path.

## 5. Pseudocode (authoritative raw, retained)

```c
void Client_RecvInventoryUsePaint(int param_1)



{

  int *piVar1;

  int iVar2;

  int unaff_EDI;

  

  piVar1 = Object_ResolveFromTFID((TFID_16 *)(unaff_EDI + 0x10));

  if (((piVar1 != (int *)0x0) && (*(int *)(piVar1[0x2a] + 0x38) == 0xe)) &&

     (iVar2 = (**(code **)(*piVar1 + 0x1d4))(), iVar2 != 0)) {

    if (*(char *)(unaff_EDI + 0x21) == '\0') {

      FUN_004faaf0(*(undefined1 *)(unaff_EDI + 0x20));

    }

    else if (*(char *)(unaff_EDI + 0x21) == '\x01') {

      FUN_004fab40(*(undefined1 *)(unaff_EDI + 0x20));

    }

    if (piVar1 == *(int **)(*(int *)(param_1 + 0xe98) + 0xcd0)) {

      FUN_0051f4e0(0);

    }

    FUN_004fcd80(0);

  }

  return;

}
```

## 6. Open questions

- Name FUN_004faaf0 / FUN_004fab40 paint apply helpers from plate comments if available.
