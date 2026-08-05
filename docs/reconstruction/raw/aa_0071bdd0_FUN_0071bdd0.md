# Raw capture: FUN_0071bdd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bdd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071bdd0` |
| **Canonical name** | `FUN_0071bdd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0071bdd0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  
  iVar3 = 0;
  pbVar4 = &DAT_00d12e91;
  do {
    uVar5 = 2;
    do {
      uVar1 = uVar5 - 2;
      pbVar4[-1] = (&DAT_00afcb88)
                   [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                    (((int)(uVar1 & 0x3f) >> 4 & 2U) + iVar3) * 0x10] & 0xf |
                   (&DAT_00afcb48)
                   [((int)uVar1 >> 7 & 0xfU) +
                    (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      uVar1 = uVar5 - 1;
      *pbVar4 = (&DAT_00afcb88)
                [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                 (((int)(uVar1 & 0x3f) >> 4 & 2U | uVar1 & 1) + iVar3) * 0x10] & 0xf |
                (&DAT_00afcb48)
                [((int)uVar1 >> 7 & 0xfU) +
                 (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      pbVar4[1] = (&DAT_00afcb88)
                  [((int)(uVar5 & 0x3f) >> 1 & 0xfU) +
                   (((int)(uVar5 & 0x3f) >> 4 & 2U) + iVar3) * 0x10] & 0xf |
                  (&DAT_00afcb48)
                  [((int)uVar5 >> 7 & 0xfU) +
                   (((int)uVar5 >> 10 & 2U | (int)uVar5 >> 6 & 1U) + iVar3) * 0x10] << 4;
      uVar1 = uVar5 + 1;
      pbVar4[2] = (&DAT_00afcb88)
                  [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                   (((int)(uVar1 & 0x3f) >> 4 & 2U | uVar1 & 1) + iVar3) * 0x10] & 0xf |
                  (&DAT_00afcb48)
                  [((int)uVar1 >> 7 & 0xfU) +
                   (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      iVar2 = uVar5 + 2;
      pbVar4 = pbVar4 + 4;
      uVar5 = uVar5 + 4;
    } while (iVar2 < 0x1000);
    iVar3 = iVar3 + 8;
  } while ((int)pbVar4 < 0xd16e91);
  return;
}
```

---

## Live re-decompile (2026-07-29) — dual A/B seal (W19-P)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Canonical name (sealed)** | `DES_BuildSBoxLookupTables` |
| **Integrity** | Body ≡ 2026-07-23 raw; bytes seal entry prolog + outer/inner bounds |

### Live pseudocode

```c
void FUN_0071bdd0(void)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  
  iVar3 = 0;
  pbVar4 = &DAT_00d12e91;
  do {
    uVar5 = 2;
    do {
      uVar1 = uVar5 - 2;
      pbVar4[-1] = (&DAT_00afcb88)
                   [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                    (((int)(uVar1 & 0x3f) >> 4 & 2U) + iVar3) * 0x10] & 0xf |
                   (&DAT_00afcb48)
                   [((int)uVar1 >> 7 & 0xfU) +
                    (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      uVar1 = uVar5 - 1;
      *pbVar4 = (&DAT_00afcb88)
                [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                 (((int)(uVar1 & 0x3f) >> 4 & 2U | uVar1 & 1) + iVar3) * 0x10] & 0xf |
                (&DAT_00afcb48)
                [((int)uVar1 >> 7 & 0xfU) +
                 (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      pbVar4[1] = (&DAT_00afcb88)
                  [((int)(uVar5 & 0x3f) >> 1 & 0xfU) +
                   (((int)(uVar5 & 0x3f) >> 4 & 2U) + iVar3) * 0x10] & 0xf |
                  (&DAT_00afcb48)
                  [((int)uVar5 >> 7 & 0xfU) +
                   (((int)uVar5 >> 10 & 2U | (int)uVar5 >> 6 & 1U) + iVar3) * 0x10] << 4;
      uVar1 = uVar5 + 1;
      pbVar4[2] = (&DAT_00afcb88)
                  [((int)(uVar1 & 0x3f) >> 1 & 0xfU) +
                   (((int)(uVar1 & 0x3f) >> 4 & 2U | uVar1 & 1) + iVar3) * 0x10] & 0xf |
                  (&DAT_00afcb48)
                  [((int)uVar1 >> 7 & 0xfU) +
                   (((int)uVar1 >> 10 & 2U | (int)uVar1 >> 6 & 1U) + iVar3) * 0x10] << 4;
      iVar2 = uVar5 + 2;
      pbVar4 = pbVar4 + 4;
      uVar5 = uVar5 + 4;
    } while (iVar2 < 0x1000);
    iVar3 = iVar3 + 8;
  } while ((int)pbVar4 < 0xd16e91);
  return;
}
```

### Live bytes @ entry `0x0071bdd0` (prolog + loop seed)

```
0071bdd0  53                 push ebx
0071bdd1  55                 push ebp
0071bdd2  56                 push esi
0071bdd3  57                 push edi
0071bdd4  33 d2              xor  edx, edx          ; iVar3 bank base = 0
0071bdd6  bd 91 2e d1 00     mov  ebp, 0x00d12e91   ; write cursor (out-1 style)
...
0071bf64  5f                 pop  edi
0071bf65  5e                 pop  esi
0071bf66  5d                 pop  ebp
0071bf67  5b                 pop  ebx
0071bf68  c3                 ret
0071bf69  cc cc cc           int3 pad
```

Outer end check: `cmp ebp, 0x00d16e91` / `jl` — four banks of **0x1000** bytes:
`DAT_00d12e90` .. `DAT_00d15e90` (consumer bases for `DES_CalculateSBoxSubstitution`).

### Constants / tables (read_memory)

| Symbol | VA | Role |
|--------|-----|------|
| `DAT_00afcb48` | `0x00afcb48` | FIPS DES S-box nibble table (S1 starts `0e 04 0d 01 02 0f 0b 08...`; full **512** bytes S1..S8) |
| `DAT_00afcb88` | `0x00afcb88` | Alias into same table at **+0x40** (S2 start `0f 01 08 0e...`) used as second index base |
| `DAT_00d12e90` | `0x00d12e90` | Output LUT bank 0 (BSS; image zeros until init) |
| end exclusive | `0x00d16e91` | After bank 3 (`d12e90+0x4000`) |

### Sole caller

| Site | Function |
|------|----------|
| `0x0071c06b` | `DES_InitializeCipher` — after `DES_KeySchedule`, before `FUN_0071b5a0` |

