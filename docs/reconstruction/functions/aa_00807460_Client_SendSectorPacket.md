# Function record: Client_SendSectorPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00807460` |
| **Canonical name** | `Client_SendSectorPacket` |
| **Address** | `0x00807460` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-sector` |
| **Completion status** | **Human-refined plate** — dual residual strengthened 2026-07-29 (flag + null drop + skill/interact EAX=8); runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Xref count** | 67 (Ghidra unconditional CALL) |

## Purpose

C2S sector send via `client+0xc78` connection vtbl `+0x18`.  
Reliability flags from live-in **EAX**: `~(EAX>>2)&2` ∈ {0,2} ⇔ `(EAX&8)?0:2`.  
**TNL** (`RPCEvent.cs`): 0=`RPCGuaranteedOrdered`, 1=`RPCGuaranteed`, 2=`RPCUnguaranteed`.  
Canonical callers set **`EAX=8` → flags 0 (GuaranteedOrdered)**. Null conn = intentional silent drop; always returns 0.

Primary dual-residual owners:

| Path | Caller | Site | Size | Notes |
|------|--------|------|-----:|-------|
| Skill | `Client_RequestCastSkill` | `0x00941883` | 0x28 | opcode `0x2030`; `MOV EAX,8` |
| Interact | `Client_InteractClickPickTarget` | `0x00924fc0` | 0x10 | class-4 stack packet; this=`DAT_00d1a840` |

## Signature (decompiler-derived + asm)

```c
/* Client_SendSectorPacket — send a sector game packet via connection vtable +0x18.
   __thiscall this = client/game state (slot +0xc78).
   Stack: size (short), buffer pointer. Callee cleans 8 bytes (RET 8).
   Register: EAX bit3 (value 8) selects GuaranteedOrdered (flags 0) vs Unguaranteed (flags 2).
   Always returns 0 (including null-conn silent drop).
*/
undefined4 __thiscall Client_SendSectorPacket(void *this, short size, void *buffer);
```

Live body (sealed):

```text
if (*(this+0xc78) != 0)
  (*conn)->vtbl[+0x18](0xffffffff, buffer, (int)size, ~(EAX>>2)&2);
return 0;
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00807460_Client_SendSectorPacket.md`
- Annotated: `docs/reconstruction/raw/aa_00807460_Client_SendSectorPacket.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendSectorPacket.cpp`
- Dual residual: `docs/reconstruction/reviews/a_00807460.md`
- Reviews: `A_aa_00807460_Client_SendSectorPacket.md`, `B_aa_00807460_Client_SendSectorPacket.md`

## Callers / callees

**Callers (partial; Ghidra 67):**  
`Client_RequestCastSkill`, `Client_InteractClickPickTarget`, `Client_SendRespawnInSector`, `Client_EvalAutoPatrolWaypoint`, `Client_MissionDialogHandleButton`, inventory grab/drop/unequip/drop-to-grid, SkillTrain UI, many FUN_* C2S packers.

**Callee:** indirect `*(**(this+0xc78) + 0x18)` only (no other direct calls).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + asm + live bytes | **High** |
| Flag algebra + TNL enum map | **High** (dual residual 2026-07-29 strengthen) |
| Skill + interact EAX=8 → GuaranteedOrdered | **High** |
| Null conn silent drop intentional | **High** |
| Exhaustive all-67 bit3 | **Probable** (rare UI open) |
| Parameter semantic names | Probable |
| Types / vtbl method PDB name | Tentative |
