# Annotated low-level: Client_UI_InventorySheet_RemoveByCoid (`FUN_0085fcc0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0085fcc0` |
| VA | `0x0085fcc0` |
| System | `inventory-transfer` (UI sheet) |
| Date | 2026-07-23 (scaffold); dual strengthen 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_0085fcc0` + live `read_memory` / re-decompile 2026-07-29.
- Prefer assembly/bytes when decompiler conflicts (`unaff_ESI`, dword indices).
- **ABI:** ESI = inventory sheet host; stdcall `coidLo`, `coidHi`; **`ret 8`**.
- Dual: `reviews/A_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md` + B counterpart.

## Entry / epilogue (bytes)

```text
push ecx / push edi
mov edi, [esi+0x570]          ; hash host; jz soft return
; push &local, coidHi, coidLo; local=0
call FUN_00413a60             ; EDI = hash; out widget*
; if widget: vtbl+0x3ac → cookie; FUN_007fbb70(DAT_00d1a840, cookie)
; sheet vtbl+0xbc(widget); [esi+0x500]--
pop edi / pop ecx / ret 8
```

## Offsets

| Site | Role |
|------|------|
| `sheet+0x570` (`[0x15c]`) | COID hash table* |
| `sheet+0x500` (`[0x140]`) | tracked count |
| `item+0x160/+0x164` | COID lo/hi (callers / `FUN_0085fd20`) |
| widget vtbl `+0x3ac` | cookie for selection clear |
| sheet vtbl `+0xbc` | detach widget |
| `DAT_00d1a840` | selection host for `FUN_007fbb70` |

## Pseudocode (annotated; register roles recovered)

```c
// ESI = InventorySheetHost*
// __stdcall (ret 8)
void Client_UI_InventorySheet_RemoveByCoid(uint32_t coidLo, uint32_t coidHi)
{
  int *widget;
  int *hash = *(int **)((char *)ESI + 0x570);  /* decompiler: unaff_ESI[0x15c] */

  if (hash == 0)
    return;

  widget = 0;
  /* EDI = hash for FUN_00413a60 */
  FUN_00413a60(coidLo, coidHi, &widget);       /* hash remove + out widget* */

  if (widget != 0) {
    int cookie = (*(int (**)(void))(*widget + 0x3ac))(); /* thiscall ECX=widget */
    /* EAX = DAT_00d1a840, EDX = cookie */
    FUN_007fbb70(/* selection host */, cookie);
    (*(void (**)(int *))(*ESI + 0xbc))(widget); /* sheet detach */
    *(int *)((char *)ESI + 0x500) -= 1;         /* unaff_ESI[0x140]-- */
  }
}
```

## Open questions

- Product names for widget `+0x3ac` and sheet `+0xbc` (detach vs destroy).
- Type of `DAT_00d1a840` / selectee at `+0x309c`.
- Runtime: hash membership + count after equip/sell with open sheet UI.
