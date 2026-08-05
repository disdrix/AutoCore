# Raw capture: FUN_005ccff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ccff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ccff0` |
| **Canonical name** | `FUN_005ccff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005ccff0(int param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_18;
  undefined4 uStack_14;
  TFID_16 local_10;
  
  iVar4 = *(int *)(param_1 + 100);
  local_10.dwCoidLo = *(uint *)(iVar4 + 0x228);
  local_10.dwCoidHi = *(uint *)(iVar4 + 0x22c);
  local_10._8_4_ = *(undefined4 *)(iVar4 + 0x230);
  local_10._12_4_ = *(undefined4 *)(iVar4 + 0x234);
  piVar3 = Object_ResolveFromTFID(&local_10);
  if (piVar3 == (int *)0x0) {
    FUN_004c3c80(0);
    return;
  }
  if ((piVar3[0x28] == 0) ||
     (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +
                                   *(int *)(param_1 + 100)) + 0x298))(piVar3[0x28]), cVar2 == '\0'))
  {
    iVar4 = *(int *)(param_1 + 100);
    if ((*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa4 + iVar4) != 0) &&
       (iVar4 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa4 + iVar4) + 0x214))
                          (), iVar4 != 0)) {
      iVar4 = *(int *)(param_1 + 100);
      iVar4 = FUN_004c8970(*(undefined4 *)(iVar4 + 0x228),*(undefined4 *)(iVar4 + 0x22c),
                           *(undefined4 *)(iVar4 + 0x230),*(undefined4 *)(iVar4 + 0x234));
      if (iVar4 != 0) {
        return;
      }
    }
    uStack_14 = 0;
    iVar4 = (**(code **)(*piVar3 + 0x19c))();
    iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xb4 + iVar4);
    FUN_004294f0();
    iVar5 = FUN_004022a0(&uStack_14,&iStack_18);
    while (iVar5 == 0) {
      if (*(int *)(iStack_18 + 0x1c) == 2) {
        iVar6 = __RTDynamicCast(iStack_18,0,&CVOGHBBase::RTTI_Type_Descriptor,
                                &CVOGHBLinkedDeath::RTTI_Type_Descriptor,0);
        iVar5 = *(int *)(iVar6 + 0x24);
        if ((((iVar5 != 0) && (*(char *)(iVar6 + 0x20) == '\0')) &&
            (*(char *)(iVar5 + 0x20) == '\0')) &&
           (((piVar1 = *(int **)(iVar5 + 0x18), piVar1 != (int *)0x0 &&
             (iVar5 = (**(code **)(*piVar1 + 0x214))(), iVar5 != 0)) &&
            (cVar2 = (**(code **)(*piVar1 + 0x298))(piVar3), cVar2 != '\0')))) {
          if (*(char *)(iVar4 + 0x28) != '\0') {
            *(undefined1 *)(iVar4 + 0x28) = 0;
            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));
          }
          iVar4 = (**(code **)(*piVar1 + 0x19c))();
          if (iVar4 != 0) {
            iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;
          }
          FUN_005172d0(iVar4);
          return;
        }
      }
      iVar5 = FUN_004022a0(&uStack_14,&iStack_18);
    }
    if (*(char *)(iVar4 + 0x28) != '\0') {
      *(undefined1 *)(iVar4 + 0x28) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));
    }
  }
  else {
    iVar4 = (**(code **)(*(int *)piVar3[0x28] + 0x1c8))();
    if (iVar4 != 0) {
      FUN_005172d0(piVar3[0x28]);
      return;
    }
  }
  return;
}
```
## Re-verify (W29-L OWN dual) — 2026-07-29

| Field | Value |
|---|---|
| **Tools** | `decompile_function` / `batch_decompile` + `read_memory` + `get_function_by_address` + xrefs. **No** `disassemble_bytes` |
| **Body** | `0x005ccff0`–`0x005cd220` exclusive (**560 B / 0x230**). Ghidra listed end `005cd21f`. Next fn `FUN_005cd220` |
| **ABI** | **thiscall** ECX = HBAI; `sub esp,0x18` + save ebx/ebp/esi/edi; plain **`ret`** (`C3`) after `add esp,0x18` — **0** stack formals |
| **Owner** | `this+0x64` → owner object; TFID block `owner+0x228`..`+0x234` (16 B) |
| **Resolve** | Rebuild resolve-manager ECX (`MI +0xA8` / `+0xE4E8`); `Object_ResolveFromTFID` @ `0x004bb950` |
| **Fail path** | `Object_SetMode278_SelectFromTFID228_Inferred(owner, 0)` @ `0x004c3c80` then return |
| **Direct promote** | Candidate `resolved+0xA0` (`[0x28]`); owner MI `vtbl+0x298(candidate)`; candidate `vtbl+0x1c8()` non-zero → `Object_SetSelectedTarget` @ `0x005172d0` |
| **LinkedDeath walk** | On miss: optional `FUN_004c8970(TFID)` gate via owner `+0xA4`/`vtbl+0x214`; iterate resolved `vtbl+0x19c` → list `+0xB4` via `FUN_004294f0` + `LockedList_TryAdvanceIterator` (`0x004022a0`); type `+0x1c==2` → `__RTDynamicCast` `CVOGHBBase`→`CVOGHBLinkedDeath`; partner `+0x24` / flags `+0x20`; partner `vtbl+0x214` + `vtbl+0x298(resolved)`; then SetSelectedTarget to partner entity |
| **Caller (1)** | `CVOGHBAICreatureBase_OnHeartBeat` @ `0x005d0704` (engage path when no target or mode==1) |
| **Name** | `CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred` |

### Call targets sealed from relative CALL bytes

| Site | Target |
|---|---|
| resolve | `0x004bb950` Object_ResolveFromTFID |
| promote | `0x005172d0` Object_SetSelectedTarget |
| mode0 | `0x004c3c80` Object_SetMode278… |
| early TFID helper | `0x004c8970` |
| list prep | `0x004294f0` |
| list iter | `0x004022a0` LockedList_TryAdvanceIterator |
| RTTI cast | MSVC `__RTDynamicCast` |
