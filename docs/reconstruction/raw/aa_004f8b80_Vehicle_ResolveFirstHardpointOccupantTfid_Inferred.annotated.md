# Annotated low-level: Vehicle_ResolveFirstHardpointOccupantTfid_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004f8b80` |
| VA | `0x004f8b80` |
| Canonical name | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` |
| Prior | `FUN_004f8b80` |
| System | skills-abilities |
| Date | 2026-07-29 (walk strengthen) |

## Machine-level notes

- **Sole caller:** `Client_Skill_ResolveCastTarget` when `outFlags&4` and `skill+0x614 & 8`.
- Failure path in caller uses string **`"No enemies found."`** (combat/alt-target role, not method name).
- **Table:** `table = *(vehicle+0x260)`; for `ebp = 0; ebp < 0xc; ebp += 4` → **3** slot pointers (`mov esi, [ecx+ebp]`).
- **Table identity:** **weapon hardpoints** — sealed by `FUN_004fe110` `"Tried to equip same weapon %d"` + `Vehicle_AttachWeapon` / `Vehicle_IsAnyWeaponFiring`. Physics airStab walks the **same** table (not a separate stabilizer array).
- Per slot: `vtbl+0x40` truthy; list at **`slot+0x13c`**; non-empty **`list+0x24`** (unsigned); `FUN_004294f0` traversal lock; `FUN_004022a0` next.
- **Occupant:** `obj = *(listValue + 4)` then return **`obj + 0x160`** (TFID*). Extra `+4` vs some sibling list walks that use listValue as object.
- Else **`&DAT_009cd0f8`**: bytes `FFFFFFFF FFFFFFFF 00000000 00000000` (all-ones coid pair).
- **Name `_Inferred`:** method English not string-sealed; table “weapon” is Confirmed.

## Pseudocode (annotated, asm-faithful)

```c
uint32_t * __fastcall Vehicle_ResolveFirstHardpointOccupantTfid_Inferred(int vehicle)
{
  int *table = *(int **)(vehicle + 0x260);   // weapon hardpoint ptr[3]
  for (int off = 0; off < 0xc; off += 4) {
    int *slot = *(int **)((char *)table + off);
    if (!slot) continue;
    if (!(**(char(**)())(*slot + 0x40))()) continue;  // vtbl+0x40
    int *list = *(int **)((char *)slot + 0x13c);       // slot[0x4f]
    if (!list || *(unsigned *)((char *)list + 0x24) == 0) continue;

    int cursor = 0, listValue = 0;
    List_TraversalLock(list);                 // FUN_004294f0
    int done = List_Next(list, &cursor, &listValue);  // FUN_004022a0
    while (done == 0) {
      int obj = *(int *)(listValue + 4);
      if (obj != 0) {
        List_UnlockIfHeld(list);              // +0x28 / CS at +4
        return (uint32_t *)(obj + 0x160);
      }
      done = List_Next(list, &cursor, &listValue);
    }
    List_UnlockIfHeld(list);
  }
  return &DAT_009cd0f8;
}
```

## Open questions

- Product method symbol (keep `_Inferred`).
- `vtbl+0x40` product name.
- Typed name of list element where occupant is at `+4`.
