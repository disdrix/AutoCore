# Annotated low-level: Vehicle_DeactivateHardpointWeapons_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004f4eb0` |
| VA | `0x004f4eb0`–`0x004f4efe` (78 B exclusive end) |
| Ghidra | `FUN_004f4eb0` |
| Canonical | `Vehicle_DeactivateHardpointWeapons_Inferred` |
| System | combat / vehicle hardpoint weapons |
| Date | 2026-07-29 (W24-Q dual seal) |

## Machine-level notes

- Source: raw capture + W24-Q live Ghidra `decompile_function` + `read_memory`.
- Convention: **MSVC thiscall/fastcall** — vehicle* in **ECX**; **no stack args**; plain **`ret`**.
- `vehicle+0x260` → pointer to **3-slot** hardpoint weapon table (stride 4, span **0xC**).
- Per non-null weapon: clear fire pair (`0x0056a260(0)`), clear suppress (`0x0056b400(0)`), `vtbl+0x18(0)`.
- Sole caller `FUN_005252f0` loads ECX from **character/session+0x250** (current vehicle) at vehicle-switch.
- Sibling `FUN_004f4f00` is the **activate** twin (not owned): same table loop, fire clear, then `vtbl+0x18(1)` or full activate path.
- Do not confuse with fire-all (`0x004f50d0`) which uses the same table to **fire**.

## Pseudocode (role-annotated)

```c
// Vehicle_DeactivateHardpointWeapons_Inferred
// thiscall: ECX = vehicle*
void __fastcall Vehicle_DeactivateHardpointWeapons_Inferred(VehicleEntity* vehicle /* ECX */)
{
  int slotOff = 0; // 0,4,8
  do {
    WeaponHardpoint* w = *(WeaponHardpoint**)(*(uint8_t**)((uint8_t*)vehicle + 0x260) + slotOff);
    // actually: *(int*)(slotOff + *(int*)(vehicle+0x260))
    if (w != nullptr) {
      Weapon_SetFireFlagPair_Inferred(w, 0);     // +0xC7/+0xC8 = 0
      Weapon_SetSuppressFlag_Cb_Inferred(w, 0);  // +0xCB = 0 (+ TacArc mesh path)
      // vfunc slot +0x18 with arg 0 — deactivate / disable presentation
      (*(void (__thiscall **)(WeaponHardpoint*, int))(*(int*)w + 0x18))(w, 0);
    }
    slotOff += 4;
  } while (slotOff < 0xC); // 3 slots
}
```

## Sealed facts

1. Body 78 B; `ret` (not `ret N`).
2. Exactly **3** hardpoint slots under `+0x260`.
3. Both fire-pair and suppress cleared to **0** before vfunc deactivate.
4. Caller ECX = `*(session+0x250)`.

## Open questions

1. Product English for `vtbl+0x18` (deactivate vs set-active(0)).
2. Exact C++ type of vehicle vs character host for `+0x250`.
3. Runtime / bit-exact package.
