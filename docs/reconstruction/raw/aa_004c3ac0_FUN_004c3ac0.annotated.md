# Annotated low-level: CVOGObject_GetActivePositionPtr_Inferred (`aa_004c3ac0`)

| Field | Value |
|---|---|
| Stable ID | `aa_004c3ac0` |
| VA | `0x004c3ac0` |
| Body | `0x004c3ac0`–`0x004c3aef` (48 bytes) |
| Canonical name | `CVOGObject_GetActivePositionPtr_Inferred` |
| Ghidra name | `FUN_004c3ac0` |
| System | object pose / input-drive-control (position consumers) |
| Date | `2026-07-29` (dual A/B seal W20-O; prior scaffold 2026-07-23) |
| Tools | `decompile_function` + `read_memory` only |

---

## Machine-level notes

- **ABI:** single object in **ECX**; return pointer in **EAX**; bare **`ret`**. Ghidra labels `__fastcall`; same register shape as MSVC thiscall with no stack args.
- **Role:** resolve which **vec4-ish position block** is currently active for the object.
- **typeOff:** `*(*(this+4)+4)` — standard CVOG multi-inheritance type offset.
- **Gate byte:** `*(u8*)(this + typeOff + 0xb8) & 7`. Zero low bits → local override at **`this+0x240`**.
- **Phys path:** if `*(this+8) != 0`, return `*( *(this+8) + 0x3c ) + 0xb0` (pointer arithmetic: dword at phys+0x3c is base, then +0xb0).
- **Embed path:** `this + typeOff + 0x84`.
- **Leaf:** no callees.
- **Sibling writer:** `FUN_004c3a40` gated-writes four floats into `this+0x240..+0x24c` when `(flags & 0xC7)==0`.
- **Mask contrast:** reader uses **`7`**; writer uses **`0xC7`**. When low bits clear, local slot is both the selected read source and writable under the wider write mask.

## Byte-accurate pseudocode

```c
/* CVOGObject_GetActivePositionPtr_Inferred
   float* __fastcall (Object *self);  // ECX=self, bare RET
*/

float *CVOGObject_GetActivePositionPtr_Inferred(Object *self)
{
  int typeOff = *(*(int **)(self + 4) + 1); /* *(*(self+4)+4) */

  if ((*(uint8_t *)((uint8_t *)self + typeOff + 0xb8) & 7) == 0)
    return (float *)((uint8_t *)self + 0x240);          /* local override */

  void *phys = *(void **)((uint8_t *)self + 8);
  if (phys != 0) {
    uint8_t *base = *(uint8_t **)((uint8_t *)phys + 0x3c);
    return (float *)(base + 0xb0);                      /* phys world pos */
  }

  return (float *)((uint8_t *)self + typeOff + 0x84);   /* embedded pose */
}
```

## Ghidra raw (authoritative for CF)

```c
int __fastcall FUN_004c3ac0(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  if ((*(byte *)(iVar1 + 0xb8 + param_1) & 7) == 0) {
    return param_1 + 0x240;
  }
  if (*(int *)(param_1 + 8) != 0) {
    return *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;
  }
  return iVar1 + param_1 + 0x84;
}
```

## Callers (context)

`FUN_005cd3b0` ×2, `FUN_005cedf0` ×2, `FUN_005d2800`, `FUN_0060a230`, `FUN_009190d0` — pose / motion consumers (not dualed here).

## Open questions

- Product/PDB English for method and for `+0xb8` flag bits.
- Exact type of object at `this+8` and object at `*(phys+0x3c)` (Havok RB vs game wrapper).
- Whether returned block is always 3 or 4 floats (writer stores 4 at +0x240).
- Runtime / bit-exact differential — open.
