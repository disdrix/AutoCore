# Raw capture: Weapon_CanFireHeatCheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056aca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0056aca0` |
| **Canonical name** | `Weapon_CanFireHeatCheck` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Weapon_CanFireHeatCheck — returns true if vehicle heat < MaxHeat (can fire).
   
   Resolves owner character → vehicle (+0x250), then:
     return vehicle.CurrentHeat(+0x150) < vehicle.MaxHeat(+0x244)
   
   Overheat lock: heat >= max blocks all weapon fire. */

bool __fastcall Weapon_CanFireHeatCheck(void *pWeapon)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pWeapon + 4) + 4) + 4 + (int)pWeapon) + 0x214
                      ))();
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1dc))();
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar1 + 0x250);
      goto compare_heat_to_max;
    }
  }
  iVar1 = 0;
compare_heat_to_max:
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 0x150) < *(int *)(iVar1 + 0x244);
  }
  return true;
}
```
