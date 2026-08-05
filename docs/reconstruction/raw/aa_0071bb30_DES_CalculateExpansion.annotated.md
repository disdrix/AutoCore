# Annotated low-level: DES_CalculateExpansion

| Field | Value |
|---|---|
| Stable ID | `aa_0071bb30` |
| VA | `0x0071bb30` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071bb30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall DES_CalculateExpansion(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *in_EAX;
  
  bVar1 = param_1[2];
  bVar2 = param_1[3];
  bVar3 = *param_1;
  bVar4 = param_1[1];
  *in_EAX = (char)bVar3 >> 1 & 0x7cU | (char)bVar3 >> 3 & 3U | bVar2 << 7;
  in_EAX[1] = (bVar3 * '\x04' | bVar3 & 1) * '\b' | (char)bVar4 >> 3 & 0x10U | (char)bVar4 >> 5 & 7U
  ;
  in_EAX[2] = ((bVar4 * '\x04' ^ bVar4) & 0x1f ^ bVar4 * '\x04') * '\x02' | (char)bVar1 >> 7 & 1U;
  in_EAX[3] = (char)bVar1 >> 1 & 0x7cU | (char)bVar1 >> 3 & 3U | bVar4 << 7;
  in_EAX[4] = (bVar1 * '\x04' | bVar1 & 1) * '\b' | (char)bVar2 >> 3 & 0x10U | (char)bVar2 >> 5 & 7U
  ;
  in_EAX[5] = ((bVar2 * '\x04' ^ bVar2) & 0x1f ^ bVar2 * '\x04') * '\x02' | (char)bVar3 >> 7 & 1U;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
