# Raw capture: CVOGHBBase_TryFire

| Field | Value |
|---|---|
| **Stable ID** | `aa_005082c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005082c0` |
| **Canonical name** | `CVOGHBBase_TryFire` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBBase_TryFire — decide if virtual OnHeartBeat runs this frame.

   

   Parameters:

     pThis (ECX): CVOGHBBase*  [typed via __fastcall; true ABI is thiscall]

     pOutStatus (stack+4): EHBStatus out — Continue=0, Inactive=2, Remove=0x10

   

   Algorithm:

     if cStopped: *out = Remove (g_dwTimedActionDefaultPeriodMs=16)

     if nPeriodMs == -1000: fall through to Continue

     else if (g_dwClientTickMs - dwLastFireTickMs) > nPeriodMs OR clock wrap:

       if fDormant: *out = Inactive (2)  // Start() clears fDormant

       else: vtable[3] OnHeartBeat; dwLastFireTickMs = g_dwClientTickMs

     else: *out = Continue (0)

   

   Returns: pOutStatus

   

   NOTE: 16 is Remove status bit for CVOGHBList_Tick, NOT combat-pool period.

   Combat pool nPeriodMs is 3000/5000 from CVOGHBRegeneration_ctor. */



uint * __fastcall CVOGHBBase_TryFire(CVOGHBBase *pThis,uint *pOutStatus)



{

  uint uVar1;

  uint *puVar2;

  uint *unaff_retaddr;

  uint *in_stack_00000004;

  CVOGHBBase *pThisForVCall;

  

  if (pThis->cStopped != '\0') {

    *in_stack_00000004 = g_dwTimedActionDefaultPeriodMs;

    return in_stack_00000004;

  }

  if (pThis->nPeriodMs != 0xfffffc18) {

    if (((uint)pThis->nPeriodMs < g_dwClientTickMs - pThis->dwLastFireTickMs) ||

       (g_dwClientTickMs < pThis->dwLastFireTickMs)) {

      if (pThis->fDormant != false) {

        *in_stack_00000004 = g_dwHBStatusInactive;

        return in_stack_00000004;

      }

      pThisForVCall = pThis;

      puVar2 = (uint *)(**(code **)((int)pThis->pVTable + 0xc))(&pThisForVCall);

      uVar1 = *puVar2;

      pThis->dwLastFireTickMs = g_dwClientTickMs;

      *unaff_retaddr = uVar1;

      return unaff_retaddr;

    }

  }

  *in_stack_00000004 = g_dwHBStatusContinue;

  return in_stack_00000004;

}
```

---

## Append: machine seal 2026-07-29 (do not alter body above)

Live Ghidra read_memory @ 0x005082c0 (body through ret 4 @ 0x00508347).

Key machine facts:
- Period field: this+0x08 (8B 4E 08)
- -1000 branch: jz to Continue (no OnHeartBeat)
- cStopped +0x20 / fDormant +0x21
- Stamp +0x14 from g_dwClientTickMs after fire
- Remove dword 0x00af19e8=16; Inactive 0x00af19e4=2; Continue 0x00b041d0=0
- ABI: thiscall + stack out; ret 4

Plate equating -1000 with combat-pool always ready is semantic debt: pool puts -1000 at +0x0C (Reschedule) and real period at +0x08. See dual A/B 2026-07-29.
