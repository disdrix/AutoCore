# Annotated low-level: DES_CalculatePermutationP

| Field | Value |
|---|---|
| Stable ID | `aa_0071bc40` |
| VA | `0x0071bc40` |
| System | auth |
| Date | 2026-07-29 (dual A/B seal; supersedes 2026-07-23 FUN scaffold notes) |

## Machine-level notes

- Source: raw capture for `aa_0071bc40` + live Ghidra decompile 2026-07-29.
- Prefer assembly when decompiler conflicts — none observed this pass.
- DES **P-permutation** (32-bit after S-boxes → 32-bit): four precomputed byte→dword contrib LUTs, OR-accumulated.
- Calling convention (decompiler-derived):
  - **param_1** (stack): 4-byte input (S-box output from `DES_CalculateSBoxSubstitution`).
  - **EAX** (`in_EAX`): 4-byte output buffer for P(result).
  - Return: `in_EAX + 3` (pointer tail; caller uses buffer contents, not return as value).
- LUT bases (static BSS; filled at cipher init):
  | Bank | Base | Input byte | Role |
  |---|---|---|---|
  | 0 | `DAT_00d11658` | `param_1[0]` | P contrib from byte 0 |
  | 1 | `DAT_00d11a58` | `param_1[1]` | P contrib from byte 1 |
  | 2 | `DAT_00d11e58` | `param_1[2]` | P contrib from byte 2 |
  | 3 | `DAT_00d12258` | `param_1[3]` | P contrib from byte 3 |
- Per bank: entry size 4 B; index = `byte * 4`; OR entry bytes into `out[0..3]`.
- Sole caller: `DES_RoundFunctionF` (`0x0071bf70`) at `0x0071bff1`.

## Pseudocode (annotated copy of raw)

```c
byte * DES_CalculatePermutationP(byte *param_1)  // in: 4B S-box out

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  byte *in_EAX;  // out: 4B P-permuted
  
  // clear 32-bit result
  *in_EAX = 0;
  pbVar1 = in_EAX + 1;
  *pbVar1 = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;

  // bank0 @ DAT_00d11658 — input byte 0
  // note: (&DAT_00d11658 + bVar3) uses undefined4* scale ⇒ +4*bVar3
  bVar3 = *param_1;
  *in_EAX = *in_EAX | *(byte *)(&DAT_00d11658 + bVar3);
  iVar2 = (uint)bVar3 * 4;
  *pbVar1 = *pbVar1 | *(byte *)((int)&DAT_00d11658 + iVar2 + 1);
  in_EAX[2] = in_EAX[2] | *(byte *)((int)&DAT_00d11658 + iVar2 + 2);
  in_EAX[3] = in_EAX[3] | *(byte *)((int)&DAT_00d11658 + iVar2 + 3);

  // bank1 @ DAT_00d11a58 — input byte 1
  bVar3 = param_1[1];
  *in_EAX = *in_EAX | (&DAT_00d11a58)[(uint)bVar3 * 4];
  iVar2 = (uint)bVar3 * 4;
  *pbVar1 = *pbVar1 | (&DAT_00d11a59)[iVar2];
  in_EAX[2] = in_EAX[2] | (&DAT_00d11a5a)[iVar2];
  in_EAX[3] = in_EAX[3] | (&DAT_00d11a5b)[iVar2];

  // bank2 @ DAT_00d11e58 — input byte 2
  bVar3 = param_1[2];
  *in_EAX = *in_EAX | (&DAT_00d11e58)[(uint)bVar3 * 4];
  iVar2 = (uint)bVar3 * 4;
  *pbVar1 = *pbVar1 | (&DAT_00d11e59)[iVar2];
  in_EAX[2] = in_EAX[2] | (&DAT_00d11e5a)[iVar2];
  in_EAX[3] = in_EAX[3] | (&DAT_00d11e5b)[iVar2];

  // bank3 @ DAT_00d12258 — input byte 3
  bVar3 = param_1[3];
  *in_EAX = *in_EAX | (&DAT_00d12258)[(uint)bVar3 * 4];
  iVar2 = (uint)bVar3 * 4;
  *pbVar1 = *pbVar1 | (&DAT_00d12259)[iVar2];
  in_EAX[2] = in_EAX[2] | (&DAT_00d1225a)[iVar2];
  in_EAX[3] = in_EAX[3] | (&DAT_00d1225b)[iVar2];

  return in_EAX + 3;
}
```

## Open questions

- Map four banks back to classic DES P-bit table (FIPS 46-3 Table 4) once LUTs filled at init.
- Confirm builder (`FUN_0071bdd0` / `FUN_0071b5a0`) which bank is which.
- Bit-exact / FIPS known-answer vector deferred (no Launcher; tables empty offline).
