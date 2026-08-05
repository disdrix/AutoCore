# Raw capture: CVOGHBBase_RescheduleAfterFire

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508350` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00508350` |
| **Canonical name** | `CVOGHBBase_RescheduleAfterFire` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBBase_RescheduleAfterFire — next list delay after OnHeartBeat.
   
   Parameters:
     pThis (ECX): CVOGHBBase* [typed via __fastcall; true ABI thiscall]
     pOutNextDelayMs (stack+4): out delay ms
   
   Algorithm:
     if nPeriodSentinel==-1000 (combat pool): *out=0 (g_dwHBStatusContinue)
     else decrement nPeriodCounter; if still >0 *out=0
     else *out=g_dwTimedActionDefaultPeriodMs (16)
   
   Returns: void via out-param
   
   Combat pool interval is TryFire vs nPeriodMs, not this 16ms default. */

void __fastcall CVOGHBBase_RescheduleAfterFire(CVOGHBBase *pThis,uint *pOutNextDelayMs)

{
  uint *in_stack_00000004;
  
  if (pThis->nPeriodSentinel == -1000) {
    *in_stack_00000004 = g_dwHBStatusContinue;
    return;
  }
  pThis->nPeriodCounter = pThis->nPeriodCounter + -1;
  if (0 < pThis->nPeriodCounter) {
    *in_stack_00000004 = g_dwHBStatusContinue;
    return;
  }
  *in_stack_00000004 = g_dwTimedActionDefaultPeriodMs;
  return;
}
```
