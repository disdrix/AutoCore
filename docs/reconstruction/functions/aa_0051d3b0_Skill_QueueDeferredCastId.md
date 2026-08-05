# Function record: Skill_QueueDeferredCastId

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d3b0` |
| **Canonical name** | `Skill_QueueDeferredCastId` |
| **Address** | `0x0051d3b0` |
| **Body** | `0x0051d3b0`–`0x0051d424` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual residual sealed 2026-07-29** — CF/ABI/layout High; product deque typename open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Push one **uint32 skill id** onto the cast-slot’s deferred ring (MSVC **`deque`-shaped** container: map of 0x10 blocks, 4 dwords each). Called only from `Skill_ClearActiveCastCounterAndQueueId` with **slot** as `this` (not the outer owner).

## Signature (asm-sealed)

```c
/* thiscall: ECX = slot (0x14 block from FUN_005169c0); stack pSkillId; RET 4 */
void __thiscall Skill_QueueDeferredCastId(void *pSlot, uint32_t *pSkillId);
```

| Param | Storage | Role |
|---|---|---|
| `pSlot` | ECX | Cast/busy slot: map/off/size at +4/+8/+0xC/+0x10 |
| `pSkillId` | Stack `[ESP+4]` at entry (after ret) | Pointer to dword written into ring |
| return | void | — |

## Authoritative body (asm 2026-07-29)

```asm
; 0x0051d3b0
PUSH ESI
MOV  ESI, ECX                 ; this = slot
MOV  EAX, [ESI+0x10]          ; size
MOV  ECX, [ESI+0x0C]          ; off
ADD  ECX, EAX                 ; off+size
TEST CL, 3
JNZ  compute                  ; not block boundary → no grow
ADD  EAX, 4
SHR  EAX, 2                   ; (size+4)>>2
CMP  [ESI+0x08], EAX          ; mapsize
JA   compute                  ; mapsize > needed → no grow
PUSH 1
MOV  ECX, ESI
CALL FUN_0051c3b0             ; grow map
compute:
MOV  EAX, [ESI+0x08]          ; mapsize
PUSH EBX
PUSH EDI
MOV  EDI, [ESI+0x0C]
ADD  EDI, [ESI+0x10]          ; linear = off+size
MOV  EBX, EDI
SHR  EBX, 2                   ; block
CMP  EAX, EBX
JA   have_block
SUB  EBX, EAX                 ; block -= mapsize (one wrap)
have_block:
MOV  EDX, [ESI+0x04]          ; map
CMP  dword ptr [EDX+EBX*4], 0
JNZ  have_ptr
PUSH 0x10
CALL operator_new
MOV  ECX, [ESI+0x04]
ADD  ESP, 4
MOV  [ECX+EBX*4], EAX
have_ptr:
MOV  EDX, [ESI+0x04]
MOV  EAX, [EDX+EBX*4]
AND  EDI, 3
LEA  EAX, [EAX+EDI*4]         ; &block[sub]
TEST EAX, EAX
POP  EDI
POP  EBX
JZ   inc_size
MOV  ECX, [ESP+0x08]          ; pSkillId (after PUSH ESI still on stack)
MOV  EDX, [ECX]
MOV  [EAX], EDX               ; *elem = *pSkillId
inc_size:
ADD  dword ptr [ESI+0x10], 1
POP  ESI
RET  4
```

### Behavioral summary

| Step | Behavior | Confidence |
|---|---|---|
| Grow gate | `(off+size)&3==0` && `mapsize <= (size+4)>>2` → `FUN_0051c3b0(this,1)` | **Confirmed** |
| Index | `linear=off+size`; `block=linear>>2` with optional `−mapsize` | **Confirmed** |
| Block | if null, `operator_new(0x10)` into map[block] | **Confirmed** |
| Store | one dword at `block[(linear&3)]` if ptr non-null | **Confirmed** |
| Size | always `+0x10 += 1` | **Confirmed** |

## Slot layout

| Off | Size | Role | Confidence |
|---:|---:|---|---|
| +0x0 | 4 | unused in this body | Confirmed unused |
| +0x4 | 4 | map (`T**` / block pointers) | **Confirmed** |
| +0x8 | 4 | mapsize (block slots) | **Confirmed** |
| +0xC | 4 | off / head element index | **Confirmed** |
| +0x10 | 4 | size; also busy ≠0 in LocalCastValidate | **Confirmed** |

Block payload: **4× uint32** (0x10 bytes).

Lazy zero of +4/+8/+0xC/+0x10: **`FUN_005169c0`** on first alloc of the 0x14 slot.

## Callers / callees

### Callees

| Symbol | VA | Role |
|---|---|---|
| `FUN_0051c3b0` | `0x0051c3b0` | Map grow (deque realloc); overflow → `FUN_0051b5f0` `"deque<T> too long"` |
| `operator_new` | CRT | 0x10-byte block |

### Callers (1 xref)

| Caller | Call site | Notes |
|---|---|---|
| `Skill_ClearActiveCastCounterAndQueueId` | `0x00517bd4` | `PUSH &nSkillId`; slot from `FUN_005169c0`; ECX=slot |

## Related (not this body)

| Symbol | Relation |
|---|---|
| `FUN_005169c0` | Lazy-get 0x14 slot @ owner+0x64 |
| `Skill_ClearActiveCastCounterAndQueueId` | Sole producer of queue pushes |
| `Skill_LocalCastValidate` | Reads `slot+0x10≠0` → eSkillResponses **6** |
| `FUN_0051b5f0` | Throws `"deque<T> too long"` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051d3b0_Skill_QueueDeferredCastId.md`
- Annotated: `docs/reconstruction/raw/aa_0051d3b0_Skill_QueueDeferredCastId.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_QueueDeferredCastId.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_0051d3b0_Skill_QueueDeferredCastId.md`, `B_aa_0051d3b0_Skill_QueueDeferredCastId.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / offsets / dword element | **Confirmed** (asm + decompile + pcode) |
| Grow predicate `(size+4)>>2` | **Confirmed** |
| Sole caller Clear | **Confirmed** |
| MSVC deque-shaped container | **High** (string on grow overflow) |
| Product typename `std::deque<…>` | Open / INFERRED |
| OOM path (new fails, size still++) | Tentative residual |
