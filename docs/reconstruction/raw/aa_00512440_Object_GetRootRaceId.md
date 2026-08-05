# Raw capture: Object_GetRootRaceId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512440` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00512440` |
| **Canonical name** | `Object_GetRootRaceId` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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

---

## Versioned addendum 2026-07-29 (Dual A/B — do not alter body above)

| Item | Value |
|---|---|
| Live re-decompile | Matches raw body |
| `read_memory` @ `00512440` (32 B) | `8B81AC00000085C074128D9B000000008BC88B81AC00000085C075F48B4110C3` |
| Body end | `0x0051245F` (`ret`) |
| Sibling | `0x00512460` chain writer of `+0x10` |
| Callers | 38 xrefs; leaf (`callees: []`) |
| Enum (`RACE_ID_INFERRED`) | HUMAN=0, BIOMEK=1, TRIBE=2 (size 4) |
| Dual verdict | accept-with-gaps (A+B) |
