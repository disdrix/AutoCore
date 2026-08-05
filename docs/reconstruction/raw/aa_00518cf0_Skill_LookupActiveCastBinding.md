# Raw capture: Skill_LookupActiveCastBinding

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518cf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00518cf0` |
| **Canonical name** | `Skill_LookupActiveCastBinding` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_LookupActiveCastBinding(outTfid, skillId)
   
   Fills 16-byte TFID from active-cast map for skillId, or invalid sentinel
   DAT_009cdf88 / DAT_00a15870 (-1,-1,0,0) if unbound.
   Cast-again HB only starts when lookup equals invalid sentinel (no prior bind). */

void Skill_LookupActiveCastBinding(void *pOutTfid,int nSkillId)

{
  int pMap;
  int *piVar1;
  int pMapIt;
  int *pTmp;
  
  piVar1 = &nSkillId;
  pTmp = &pMapIt;
  FUN_00518c20(pTmp,piVar1);
  FUN_0051c150(pTmp,piVar1);
  pMap = FUN_00518c20();
  if (pMapIt != *(int *)(pMap + 4)) {
    *(undefined4 *)pOutTfid = *(undefined4 *)(pMapIt + 0x18);
    *(undefined4 *)((int)pOutTfid + 4) = *(undefined4 *)(pMapIt + 0x1c);
    *(undefined4 *)((int)pOutTfid + 8) = *(undefined4 *)(pMapIt + 0x20);
    *(undefined4 *)((int)pOutTfid + 0xc) = *(undefined4 *)(pMapIt + 0x24);
    return;
  }
  *(undefined4 *)pOutTfid = g_abTfidInvalid_9CDF88._0_4_;
  *(undefined4 *)((int)pOutTfid + 4) = g_abTfidInvalid_9CDF88._4_4_;
  *(undefined4 *)((int)pOutTfid + 8) = g_abTfidInvalid_9CDF88._8_4_;
  *(undefined4 *)((int)pOutTfid + 0xc) = g_abTfidInvalid_9CDF88._12_4_;
  return;
}
```
