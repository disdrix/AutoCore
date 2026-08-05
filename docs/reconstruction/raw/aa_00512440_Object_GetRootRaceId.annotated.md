# Annotated low-level: Object_GetRootRaceId

| Field | Value |
|---|---|
| Stable ID | `aa_00512440` |
| VA | `0x00512440` – `0x0051245f` |
| System | object / faction |
| Date | 2026-07-29 (dual A/B refresh) |

## Machine-level notes

- Source: raw capture for `aa_00512440` + live Ghidra decompile/read_memory/pcode 2026-07-29.
- Prefer assembly when decompiler conflicts — **no conflict** here.
- Leaf: no calls.
- Companion writer at `0x00512460` (not this unit).

## Byte decode (authoritative)

```
00512440  8B 81 AC 00 00 00   mov  eax, dword ptr [ecx+0ACh]  ; owner
00512446  85 C0               test eax, eax
00512448  74 12               jz   0051245c                   ; no owner → root=ecx
0051244A  8D 9B 00 00 00 00   lea  ebx, [ebx+0]               ; nop align
00512450  8B C8               mov  ecx, eax                   ; advance
00512452  8B 81 AC 00 00 00   mov  eax, dword ptr [ecx+0ACh]
00512458  85 C0               test eax, eax
0051245A  75 F4               jnz  00512450
0051245C  8B 41 10            mov  eax, dword ptr [ecx+10h]    ; race/faction
0051245F  C3                  ret
```

## Field map

| Offset | Width | Role |
|---|---|---|
| `+0xAC` | ptr32 | Owner / parent object (null = root) |
| `+0x10` | s32 | Race / faction id (`RACE_ID_INFERRED`) |

## Pseudocode (annotated copy of raw)

```c
/* ClonedObject_GetRootRaceId — walk owner chain (+0xAC) to the root object,
   return race id at root+0x10.

   Used by VehicleCombatPoolAction_ctor to pick 3000 vs 5000 ms period
   (race ids 0/1/2 → 3000 ms). */

RACE_ID_INFERRED __fastcall Object_GetRootRaceId(void *pObject)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)((int)pObject + 0xac);
  while (pvVar1 = pvVar2, pvVar1 != (void *)0x0) {
    pObject = pvVar1;
    pvVar2 = *(void **)((int)pvVar1 + 0xac);
  }
  return *(RACE_ID_INFERRED *)((int)pObject + 0x10);
}
```

## Open questions

- Product C++ member names for `+0xAC` / `+0x10`.
- Complete faction id table (beyond Human/Biomek/Tribe and −1/−100).
- Cycle behavior on corrupt owner graphs.
