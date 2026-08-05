# Annotated low-level: Skill_ClearActiveCastCounterAndQueueId

| Field | Value |
|---|---|
| Stable ID | `aa_00517b90` |
| VA | `0x00517b90` |
| System | skills-abilities |
| Date | 2026-07-29 residual (prior 2026-07-23) |

## Machine-level notes

- Source: raw capture for `aa_00517b90` + full function disassembly 2026-07-29.
- **ABI sealed:** ECX = owner `this` (`MOV ESI,ECX`); stack `nSkillId`; `RET 4`. Ghidra may still label `__stdcall`.
- **Counter:** `slot+0x10` compared to **1** (`JC` if &lt;1); then **decrement**, not force-clear.
- **+0xC:** written **0** only when post-dec counter is 0.
- **Queue path:** `LEA`/`PUSH` `&nSkillId`; third `FUN_005169c0(this)`; `MOV ECX,EAX`; `CALL Skill_QueueDeferredCastId` — queue **this** is the **0x14 slot**, not outer owner.
- **Return:** BL latched 0/1 → AL. Known callers ignore AL (side-effect only).
- Pair: `FUN_005169c0` leave-FUN (lazy `this+0x64` → 0x14); `Skill_QueueDeferredCastId` ring push.
- Prefer asm when decompiler third-call args conflict.

## Pseudocode (asm-corrected)

```c
/* Skill_ClearActiveCastCounterAndQueueId(this, nSkillId)
   thiscall: ECX = owner with FUN_005169c0 lazy slot at +0x64
   - if slot+0x10 >= 1: decrement; if hits 0 clear slot+0xC; ret_flag = 1
   - always Skill_QueueDeferredCastId(slot, &nSkillId)
   - return ret_flag (1 if counter was live)
*/

char __thiscall Skill_ClearActiveCastCounterAndQueueId(void *this, int nSkillId)
{
  char wasLive;
  void *slot;
  int counter;

  wasLive = 0;
  slot = FUN_005169c0(this);                 /* ECX = this */
  if (*(int *)((char *)slot + 0x10) >= 1) {
    slot = FUN_005169c0(this);
    counter = *(int *)((char *)slot + 0x10);
    if (counter != 0) {
      counter = counter - 1;
      *(int *)((char *)slot + 0x10) = counter;
      if (counter == 0) {
        *(int *)((char *)slot + 0xc) = 0;
      }
    }
    wasLive = 1;
  }
  /* PUSH &nSkillId; ECX = this */
  slot = FUN_005169c0(this);
  Skill_QueueDeferredCastId(slot, &nSkillId); /* thiscall: ECX = slot */
  return wasLive;
}
```

## Open questions

- Product type of outer `this`; PDB names for slot +0xC / ring fields.
- Sites that **increment** +0x10.
- Runtime verification.
