# Annotated low-level: Client_SendSectorPacket

| Field | Value |
|---|---|
| Stable ID | `aa_00807460` |
| VA | `0x00807460` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00807460`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_SendSectorPacket — send a sector game packet via connection vtable +0x18.
   
   __thiscall this = game state (uses this+0xc78 connection).
   Stack: size (short), buffer pointer.
   EAX bits influence reliability flags: ~(EAX>>2)&2.
   
   Call sites include AutoPatrol (0x20B3 size 0x18) and FailMission C2S (0x20B2 size 0x18). */

undefined4 __thiscall Client_SendSectorPacket(void *this,short size,void *buffer)

{
  uint in_EAX;
  
  if (*(int *)((int)this + 0xc78) != 0) {
    (**(code **)(**(int **)((int)this + 0xc78) + 0x18))
              (0xffffffff,buffer,(int)size,~(in_EAX >> 2) & 2);
  }
  return 0;
}
```

## Open questions

- ~~Confirm calling convention and full signature against callers.~~ Residual 2026-07-29: `__thiscall(this, short size, void* buffer)` + live-in `EAX`; see `reviews/a_00807460.md`.
- Recover original PDB name for connection vtbl+0x18; confirm `client+0xc78` ≡ `DAT_00d1b4b8` (sibling residual).
- Runtime / bit-exact still open.

## Dual residual (2026-07-29, strengthen pass)

- Flag `~(EAX>>2)&2` ∈ {0,2}; TNL `RPCGuaranteedOrdered=0` / `RPCUnguaranteed=2` (`RPCEvent.cs`).
- Skill `RequestCastSkill` @ `0x00941883` and interact `InteractClickPickTarget` @ `0x00924fc0`: **`EAX=8` → flags 0**.
- Expanded census (≥40 of 67 xrefs): lit 8 / EBP under `CMP==8` / `CMP EAX,8` — all Ordered.
- Null `+0xc78` = intentional silent drop; return always 0.
- Open: exhaustive 67-site bit3; `client+0xc78` ≡ `DAT_00d1b4b8`; vtbl+0x18 PDB name; runtime.

