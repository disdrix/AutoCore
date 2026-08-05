# Raw capture: DES_CalculatePermutationP

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bc40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071bc40` |
| **Canonical name** | `DES_CalculatePermutationP` |
| **System** | auth |
| **Capture timestamp** | `2026-07-23` (scaffold); live seal `2026-07-29` |
| **Tool** | Ghidra MCP `batch_decompile` / `decompile_function` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
byte * DES_CalculatePermutationP(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  byte *in_EAX;
  
  *in_EAX = 0;
  pbVar1 = in_EAX + 1;
  *pbVar1 = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  bVar3 = *param_1;
  *in_EAX = *in_EAX | *(byte *)(&DAT_00d11658 + bVar3);
  iVar2 = (uint)bVar3 * 4;
  *pbVar1 = *pbVar1 | *(byte *)((int)&DAT_00d11658 + iVar2 + 1);
  in_EAX[2] = in_EAX[2] | *(byte *)((int)&DAT_00d11658 + iVar2 + 2);
  in_EAX[3] = in_EAX[3] | *(byte *)((int)&DAT_00d11658 + iVar2 + 3);
  bVar3 = param_1[1];
  *in_EAX = *in_EAX | (&DAT_00d11a58)[(uint)bVar3 * 4];
  iVar2 = (uint)bVar3 * 4;
  *pbVar1 = *pbVar1 | (&DAT_00d11a59)[iVar2];
  in_EAX[2] = in_EAX[2] | (&DAT_00d11a5a)[iVar2];
  in_EAX[3] = in_EAX[3] | (&DAT_00d11a5b)[iVar2];
  bVar3 = param_1[2];
  *in_EAX = *in_EAX | (&DAT_00d11e58)[(uint)bVar3 * 4];
  iVar2 = (uint)bVar3 * 4;
  *pbVar1 = *pbVar1 | (&DAT_00d11e59)[iVar2];
  in_EAX[2] = in_EAX[2] | (&DAT_00d11e5a)[iVar2];
  in_EAX[3] = in_EAX[3] | (&DAT_00d11e5b)[iVar2];
  bVar3 = param_1[3];
  *in_EAX = *in_EAX | (&DAT_00d12258)[(uint)bVar3 * 4];
  iVar2 = (uint)bVar3 * 4;
  *pbVar1 = *pbVar1 | (&DAT_00d12259)[iVar2];
  in_EAX[2] = in_EAX[2] | (&DAT_00d1225a)[iVar2];
  in_EAX[3] = in_EAX[3] | (&DAT_00d1225b)[iVar2];
  return in_EAX + 3;
}
```

---

## Live re-decompile (2026-07-29) — dual A/B seal

Ghidra MCP `decompile_function` @ `0x0071bc40` (autoassault.exe): **byte-identical** to authoritative body above (name already `DES_CalculatePermutationP`).

| Check | Result |
|---|---|
| Zero out[0..3] via EAX | match |
| Bank0 `DAT_00d11658` OR contrib from param_1[0] | match |
| Bank1 `DAT_00d11a58..5b` from param_1[1] | match |
| Bank2 `DAT_00d11e58..5b` from param_1[2] | match |
| Bank3 `DAT_00d12258..5b` from param_1[3] | match |
| return `in_EAX + 3` | match |

### Supporting evidence (OWN VA only)

- **Xrefs:** sole caller `DES_RoundFunctionF` @ call site `0x0071bff1` (after `DES_CalculateSBoxSubstitution(&local_10)`).
- **Callees:** none (leaf).
- **`read_memory`** @ `DAT_00d11658` / `d11a58` / `d11e58` / `d12258` (64 B each): **all zero** in static image — tables are **runtime-filled** by init (`DES_InitializeCipher` → `FUN_0071bdd0` / `FUN_0071b5a0` path; not dualled here).
- Bank spacing: `0x400` (1024) = 256 entries × 4 bytes per bank.
- Bank0 byte0 index uses Ghidra `undefined4*` pointer scale: `&DAT_00d11658 + bVar3` ≡ base + `bVar3*4` (same as banks 1–3 `[(uint)b*4]`).
