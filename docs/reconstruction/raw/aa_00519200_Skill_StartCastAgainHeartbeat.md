# Raw capture: Skill_StartCastAgainHeartbeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519200` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00519200` |
| **Canonical name** | `Skill_StartCastAgainHeartbeat` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_StartCastAgainHeartbeat(pOwnerCtx, pSkill, nChargeDelayMs)
   
   Parameters:
     pOwnerCtx       - character/owner context (thiscall ECX)
     pSkill          - skill runtime
     nChargeDelayMs  - charge delay passed to ctor
   
   Algorithm: new CVOGHBOKToCastAgain -> HeartbeatManager_Enqueue -> CVOGHBBase_Activate
   
   Called optimistically from Client_RequestCastSkill / QuickBar before 0x2030. */

void __thiscall
Skill_StartCastAgainHeartbeat(void *this,void *pOwnerCtx,void *pSkill,int nChargeDelayMs)

{
  void *this_00;
  CVOGHBBase *pAction;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a3651;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x28);
  pAction = (CVOGHBBase *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    pAction = CVOGHBOKToCastAgain_ctor(this_00,this,(int)pOwnerCtx);
  }
  local_4 = 0xffffffff;
  CVOGHBList_Enqueue(*(void **)(*(int *)((int)this + 0xa4) + 0xe4ec),pAction);
  CVOGHBBase_Start(pAction);
  ExceptionList = local_c;
  return;
}
```

---

## Versioned append — 2026-07-29 asm ABI seal (do not rewrite raw body above)

Authority for signature: machine code, not Ghidra plate formals.

| Fact | Evidence |
|------|----------|
| `RET 0x8` | epilogue `00519277` — 2 stack dwords only |
| Ctor call 3 stack args | `PUSH charge; PUSH skill; PUSH owner; CALL 0x0051e240` |
| Ctor `RET 0xC` | `0051e38b` — three stack dwords |
| Type **8** | ctor `MOV [ESI+0x1c], 0x8` |
| List | `MOV EAX,[EDI+0xa4]` / `MOV ECX,[EAX+0xe4ec]` / `Enqueue` / `Start` |

Corrected prototype:

```c
void __thiscall Skill_StartCastAgainHeartbeat(
    void* pOwnerEntity, void* pSkillRuntime, int nChargeDelayMs);
```

Dual quality refresh: `reviews/a_00519200.md`, A/B `reviews/A|B_aa_00519200_*`.

---

## Versioned append — 2026-07-29 residual strengthen (bytes + 6 xrefs)

| Fact | Evidence |
|------|----------|
| Body range | `00519200`–`00519279` |
| Null new still Enqueue/Start | `je` skips ctor only; merge always Enqueue/Start |
| 6 callers | xrefs: Apply, ClearCastBinding, LocalRange, QuickBar, RequestCast, Stance |
| Charge classes | +0x14 / 0 / packet+0x10 / skill+0x10 (LocalRange) |
| Tools | decompile + read_memory + xrefs + assembly_context (no disassemble_bytes) |
