# Function record: Skill_ClearActiveCastCounterAndQueueId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517b90` |
| **Canonical name** | `Skill_ClearActiveCastCounterAndQueueId` |
| **Address** | `0x00517b90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual residual sealed 2026-07-29** — CF/ABI/offsets High; product field names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Busy/cast-slot release helper: **decrement** active-cast counter on the lazy 0x14 slot (`FUN_005169c0`), zero **slot+0xC** when the counter reaches 0, **always** enqueue `nSkillId` on that slot’s deferred ring (`Skill_QueueDeferredCastId`), return whether the counter was live.

## Signature (asm-sealed)

```c
/* thiscall-shaped: ECX = owner (lazy ptr at +0x64); stack nSkillId; RET 4
   Ghidra may label __stdcall — ECX still required. */
char __thiscall Skill_ClearActiveCastCounterAndQueueId(void *this, int nSkillId);
```

| Param | Storage | Role |
|---|---|---|
| `this` | ECX | Owner of `*(this+0x64)` busy/cast slot |
| `nSkillId` | Stack `[ESP+4]` after push frame | Skill id pushed to deferred queue |
| return | AL | `1` if `slot+0x10 >= 1` at entry, else `0` |

## Authoritative body (asm 2026-07-29)

```asm
; 0x00517b90
PUSH EBX / PUSH ESI
MOV ESI, ECX                 ; this
XOR EBX, EBX                 ; BL = 0
CALL FUN_005169c0            ; ECX = this → EAX = slot
CMP dword ptr [EAX+0x10], 1
JC  skip_dec                 ; counter < 1
MOV ECX, ESI
CALL FUN_005169c0
MOV ECX, [EAX+0x10]
CMP ECX, EBX
JZ  set_live
ADD ECX, -1
CMP ECX, EBX
MOV [EAX+0x10], ECX
JNZ set_live
MOV [EAX+0xC], EBX           ; clear queue-id when count hits 0
set_live:
MOV BL, 1
skip_dec:
MOV EAX, [ESP+0xC]           ; nSkillId
LEA ECX, [ESP+0xC]
PUSH ECX                     ; &nSkillId
MOV ECX, ESI
MOV [ESP+0x10], EAX          ; rewrite skill id slot
CALL FUN_005169c0            ; EAX = slot
MOV ECX, EAX                 ; Queue this = slot
CALL Skill_QueueDeferredCastId
POP ESI
MOV AL, BL
POP EBX
RET 4
```

### Behavioral summary

| Step | Behavior | Confidence |
|---|---|---|
| Lazy slot | `FUN_005169c0(this)` ×3 | **Confirmed** |
| Gate | enter dec path iff `+0x10 >= 1` | **Confirmed** |
| Counter | `+0x10--` (not force 0) | **Confirmed** |
| On zero | `+0xC = 0` | **Confirmed** |
| Queue | always `Skill_QueueDeferredCastId(slot, &nSkillId)` | **Confirmed** |
| Return | was-live bool in AL | **Confirmed** |

## Slot layout (shared with `FUN_005169c0` / LocalCastValidate)

| Off | Size | Role | Confidence |
|---:|---:|---|---|
| +0x0 | ? | unused in this body | open |
| +0x4 | 4 | ring base (QueueDeferred) | High (callee) |
| +0x8 | 4 | ring capacity (QueueDeferred) | High (callee) |
| +0xC | 4 | cleared when counter→0; also ring index (QueueDeferred) | High CF / name INFERRED |
| +0x10 | 4 | busy/active-cast **refcount**; LocalCastValidate ≠0 → eSkillResponses **6** | **High** |

Outer owner: lazy pointer at **`this+0x64`** (decimal 100). Product type of owner **not sealed**.

## Callers / callees

### Callees

| Symbol | VA | Role |
|---|---|---|
| `FUN_005169c0` | `0x005169c0` | Lazy-get 0x14 slot @ owner+0x64 (**leave-FUN**) |
| `Skill_QueueDeferredCastId` | `0x0051d3b0` | Push skill id into slot ring |

### Callers (4 xrefs)

| Caller | Call site | ECX / arg notes | Uses return? |
|---|---|---|---|
| `Skill_ApplyStatusEffectLocal` | `0x0051ac5e` | `MOV ECX,ESI`; `PUSH` skillId from packet | **No** (JMP after) |
| `Client_QuickBarActivateSkillSlot` | `0x00921cdf` | `LEA ECX,[…+4]`; `PUSH` skillId (`+0x5fc`) | **No** → then skill `+0x61c` |
| `Client_RequestCastSkill` | `0x0094170d` | same pattern | **No** → then skill `+0x61c` / StartCastAgain |
| `Client_StanceOrGadgetActivatePath` | `0x0093a501` | same pattern | **No** → then `+0x61c` |

Decompiler “`AND Clear(…)`” on cast-again paths is **sequencing/side-effect**, not AL-gated StartCastAgain.

## Related (not this body)

| Symbol | Relation |
|---|---|
| `Skill_LocalCastValidate` | reads same `+0x10` for busy |
| `Skill_ClearCastBindingAndMaybeRestartCd` | active-cast **map** clear / CD restart — sibling |
| `Skill_StartCastAgainHeartbeat` | client cast-again HB after Clear side effects + `+0x61c==0` |
| `Skill_LookupActiveCastBinding` | map lookup (invalid binding often co-gated) |
| `FUN_0052c780` | other `FUN_005169c0` consumer (cast-flag clear path) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.md`
- Annotated: `docs/reconstruction/raw/aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_ClearActiveCastCounterAndQueueId.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.md`, `B_aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.md`
- Residual scratch: `docs/reconstruction/reviews/a_00517b90.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow / dec / +0xC / always queue | **Confirmed** (asm + decompile) |
| thiscall ECX + RET 4 | **Confirmed** |
| Return was-live AL | **Confirmed** |
| Callers ignore return (4/4) | **Confirmed** (xref asm) |
| Parameter name `nSkillId` | **High** (callers push skill id / `+0x5fc`) |
| Product names for +0xC / owner type | Tentative / INFERRED |
| Who increments +0x10 | Open (out of unit) |
