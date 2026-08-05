# Annotated low-level: Skill_LookupActiveCastBinding

| Field | Value |
|---|---|
| Stable ID | `aa_00518cf0` |
| VA | `0x00518cf0` |
| System | skills-abilities |
| Date | 2026-07-23 (residual annotate `2026-07-29`) |

## Machine-level notes

- Source: raw capture for `aa_00518cf0` + live Ghidra re-decompile 2026-07-29.
- Prefer assembly/pcode when decompiler multi-arg-calls `FUN_00518c20` (unary getter noise).
- Dual residual: `reviews/a_00518cf0.md`, `A_aa_00518cf0_*`, `B_aa_00518cf0_*`.

## Recovered roles

| Item | Value | Conf |
|---|---|---|
| Formals | `(void *pOutTfid /* TFID16 */, int nSkillId)` stack + **ECX mapOwner** | **Confirmed** |
| ABI | `__stdcall` stack cleanup: **`ret 8`** both arms (`0x00518d3d`, `0x00518d65`) | **Confirmed** (body bytes) |
| Map get | `FUN_00518c20` → lazy shell @ owner `+0x68` | **Confirmed** |
| Find | `FUN_0051c150(map, &it, &nSkillId)`; key @ `node+0x10`; exact | **Confirmed** |
| End | `it == *(map+4)` (`_Myhead`) | **Confirmed** |
| Hit value | `node+0x18…+0x24` → out (TFID16) | **Confirmed** |
| Miss | `g_abTfidInvalid_9CDF88` @ `0x009cdf88` = `(-1,-1,0,0)` | **Confirmed** |
| `0x00a15870` | Twin invalid TFID for **callers**; **not** the map; body does not fill from it | **Confirmed** |
| Mutate | none | **Confirmed** |

## Pseudocode (annotated copy of raw + noise correction)

```c
/* Skill_LookupActiveCastBinding(outTfid, skillId)
   
   Fills 16-byte TFID from active-cast map for skillId, or invalid sentinel
   g_abTfidInvalid_9CDF88 (0x009cdf88) = (-1,-1,0,0) if unbound.
   NOTE: plate text also mentions DAT_00a15870 — that is a twin invalid TFID
   constant used by callers for compares, NOT the map and NOT this body's miss fill.
   Cast-again HB policy is caller-side when lookup equals invalid. */

void Skill_LookupActiveCastBinding(void *pOutTfid, int nSkillId)
{
  int pMap;
  int *piVar1;
  int pMapIt;
  int *pTmp;
  
  piVar1 = &nSkillId;
  pTmp = &pMapIt;
  // DECOMPILER NOISE: FUN_00518c20 is unary __fastcall(mapOwner).
  // Recovered: pMap = FUN_00518c20(mapOwner);  // sites 0x00518d00 / 0x00518d0e
  FUN_00518c20(pTmp, piVar1);
  // Recovered: FUN_0051c150(pMap, &pMapIt, &nSkillId);  // map find
  FUN_0051c150(pTmp, piVar1);
  pMap = FUN_00518c20();
  if (pMapIt != *(int *)(pMap + 4)) {
    // hit: node value TFID16
    *(undefined4 *)pOutTfid = *(undefined4 *)(pMapIt + 0x18);
    *(undefined4 *)((int)pOutTfid + 4) = *(undefined4 *)(pMapIt + 0x1c);
    *(undefined4 *)((int)pOutTfid + 8) = *(undefined4 *)(pMapIt + 0x20);
    *(undefined4 *)((int)pOutTfid + 0xc) = *(undefined4 *)(pMapIt + 0x24);
    return;
  }
  // miss: invalid TFID
  *(undefined4 *)pOutTfid = g_abTfidInvalid_9CDF88._0_4_;
  *(undefined4 *)((int)pOutTfid + 4) = g_abTfidInvalid_9CDF88._4_4_;
  *(undefined4 *)((int)pOutTfid + 8) = g_abTfidInvalid_9CDF88._8_4_;
  *(undefined4 *)((int)pOutTfid + 0xc) = g_abTfidInvalid_9CDF88._12_4_;
  return;
}
```

## Open questions

- Product type of map owner (`FUN_00518c20` this / `+0x68` host).
- Product name for `FUN_0051c150`.
- Runtime / bit-exact.
