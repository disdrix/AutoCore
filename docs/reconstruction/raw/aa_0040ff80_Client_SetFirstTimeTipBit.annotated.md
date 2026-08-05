# Annotated low-level: Client_SetFirstTimeTipBit

| Field | Value |
|---|---|
| Stable ID | `aa_0040ff80` |
| VA | `0x0040ff80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040ff80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* OR tip bit into FirstTimeFlags at character+0xD30.
   AL = tip id; EDX/param_2 = character object.
   Only for tip id < 0x80: flags[id>>5] |= 1<<(id&0x1f). */

void __fastcall Client_SetFirstTimeTipBit(undefined4 param_1,int param_2)

{
  uint *puVar1;
  byte in_AL;
  
  if (in_AL < 0x80) {
    puVar1 = (uint *)(param_2 + 0xd30 + (uint)(in_AL >> 5) * 4);
    *puVar1 = *puVar1 | 1 << (in_AL & 0x1f);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
