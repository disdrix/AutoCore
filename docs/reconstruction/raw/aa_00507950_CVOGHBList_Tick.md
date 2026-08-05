# Raw capture: CVOGHBList_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507950` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00507950` |
| **Canonical name** | `CVOGHBList_Tick` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBList_Tick — advance HB list using g_dwClientTickMs.
   
   If nForcedDeltaMsOrNull==0: g_dwClientTickMs=GetTickCount(); else add delta.
   For each active HB call vtable TryFire; if status & 0x10 (Remove) destroy/pop.
   Then promote pending queue under critical section. */

void __thiscall CVOGHBList_Tick(void *this,int nForcedDeltaMsOrNull)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (nForcedDeltaMsOrNull == 0) {
    g_dwClientTickMs = GetTickCount();
  }
  else {
    g_dwClientTickMs = g_dwClientTickMs + nForcedDeltaMsOrNull;
  }
  iVar4 = 0;
  if (0 < *(int *)((int)this + 0x20)) {
    do {
      piVar1 = *(int **)(*(int *)((int)this + 0x1c) + iVar4 * 4);
      pbVar3 = (byte *)(**(code **)(*piVar1 + 8))(&nForcedDeltaMsOrNull);
      if ((*pbVar3 & 0x10) == 0) {
        iVar4 = iVar4 + 1;
      }
      else {
        EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
        *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + -1;
        *(undefined4 *)(*(int *)((int)this + 0x1c) + iVar4 * 4) =
             *(undefined4 *)(*(int *)((int)this + 0x1c) + *(int *)((int)this + 0x20) * 4);
        if ((char)piVar1[8] == '\0') {
          (**(code **)(*piVar1 + 0x18))(1,1);
        }
        piVar1[1] = piVar1[1] + 1;
        (**(code **)*piVar1)(1);
        LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
      }
    } while (iVar4 < *(int *)((int)this + 0x20));
  }
  lpCriticalSection = (LPCRITICAL_SECTION)((int)this + 4);
  nForcedDeltaMsOrNull = (int)lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  iVar4 = 0;
  if (0 < *(int *)((int)this + 0x2c)) {
    do {
      iVar2 = *(int *)((int)this + 0x28);
      if (*(uint *)((int)this + 0x20) == (*(uint *)((int)this + 0x24) & 0x7fffffff)) {
        FUN_005b3370((int *)((int)this + 0x1c),4);
      }
      *(undefined4 *)(*(int *)((int)this + 0x1c) + *(int *)((int)this + 0x20) * 4) =
           *(undefined4 *)(iVar2 + iVar4 * 4);
      *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + 1;
      iVar4 = iVar4 + 1;
      lpCriticalSection = (LPCRITICAL_SECTION)nForcedDeltaMsOrNull;
    } while (iVar4 < *(int *)((int)this + 0x2c));
  }
  *(undefined4 *)((int)this + 0x2c) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return;
}
```

---

## Re-verify 2026-07-29 (append only)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` `0x00507950` |
| **Integrity** | Body above unchanged; CF **identical** to live decompile |
| **Callers** | `FUN_0093e010` @ `0093e084`, `FUN_0094b520` @ `0094b62b` -- both `Tick(*(void**)(client+0xd38), 0)` |
| **Callees cross-check** | Enqueue `0x005078f0`, TryFire `0x005082c0`, grow `FUN_005b3370`, ctor `CVOGHBList_ctor` |
| **Global** | `g_dwClientTickMs` @ `0x00b041cc` (`read_memory` ok) |
| **Dual A/B** | Strengthened; promote-pending residual **closed** |
