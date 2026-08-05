# Raw capture: CVOGReaction_ResolveSkillTargets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054c570` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0054c570` |
| **Canonical name** | `CVOGReaction_ResolveSkillTargets` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Resolve targets for a skill effect.
   
   Parameters:
   pSkillData - Skill data buffer pointer
   uSkillID - Skill ID to resolve
   
   Returns: Pointer to resolved target buffer (0x630 bytes), or null if already resolved
   
   Algorithm:
   1. Check DAT_00b04724 flag, init via FUN_0054b2c0 if not set
   2. Lookup skill data via FUN_00418890
   3. If *result != DAT_00b04738 (not cached):
      - Allocate 0x630 bytes
      - Get write pointer via FUN_0054f3c0
      - Copy 0x18c dwords from result+0x10 to write pointer
      - Call FUN_005535a0 with uSkillID
      - Return write pointer
   4. Else: return null (already cached) */

undefined4 * __cdecl CVOGReaction_ResolveSkillTargets(void *pSkillData,void *uSkillID)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *this;
  undefined4 *puVar4;
  short unaff_DI;
  undefined4 *puVar5;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* // Check DAT_00b04724 flag, init if needed */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a4637;
                    /* // Lookup skill data via FUN_00418890 */
  local_c = ExceptionList;
  this = (undefined4 *)0x0;
                    /* // If not cached (*result != DAT_00b04738): allocate 0x630 bytes */
  ExceptionList = &local_c;
  if (DAT_00b04724 == '\0') {
    ExceptionList = &local_c;
    FUN_0054b2c0();
  }
                    /* // Copy 0x18c dwords from source+0x10 to destination */
  piVar2 = (int *)FUN_00418890(local_10,&pSkillData);
  iVar1 = *piVar2;
  if (iVar1 != DAT_00b04738) {
    pSkillData = operator_new(0x630);
    local_4 = 0;
    if (pSkillData != (void *)0x0) {
      this = (undefined4 *)FUN_0054f3c0();
    }
    puVar4 = (undefined4 *)(iVar1 + 0x10);
    puVar5 = this;
    for (iVar3 = 0x18c; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    local_4 = 0xffffffff;
    Skill_SetRankAndReevaluate(this,uSkillID,unaff_DI);
    ExceptionList = local_c;
    return this;
  }
  ExceptionList = local_c;
  return (undefined4 *)0x0;
}
```

---

## Re-verify append (2026-07-29) — dual residual asm seal

**Tool:** Ghidra MCP `disassemble_function` @ `0x0054c570`, `0x005535a0`; caller asm contexts.

| Claim | Result |
|---|---|
| Plate "null if already resolved/cached" | **Superseded:** null = map **miss** (`node == DAT_00b04738` end sentinel) |
| `unaff_DI` third rank arg | **Falsified:** SetRank is thiscall + one stack arg (`RET 4`); EDI is REP MOVSD dest only |
| Map this | **Sealed:** `MOV ECX,0xb04734` before `FUN_00418890` |
| Rank path | **Sealed:** push stack arg1 → `Skill_SetRankAndReevaluate` stores word at `+0x5f6` |
| Copy | **Sealed:** `ADD ESI,0x10`; `MOV ECX,0x18c`; `REP MOVSD` |

Do not overwrite the authoritative decompile body above; this section only corrects plate semantics.
