# Raw capture: DES_EncryptBlock8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071c1b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071c1b0` |
| **Canonical name** | `DES_EncryptBlock8` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void DES_EncryptBlock8(void)

{
  int iVar1;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined1 local_89;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined4 local_4;
  
                    /* Performs standard DES 64-bit block encryption on an 8-byte block. First
                       applies Initial Permutation (IP), then runs 16 Feistel rounds using the round
                       keys at 0x00d16e90, then swaps the halves of the result, and finally applies
                       the Final Permutation (FP / IP^-1) using the table at 0x00d12690. */
  DES_PermuteBlock();
  iVar1 = 0;
  do {
    DES_FeistelRound(iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  local_90 = (undefined1)local_4;
  local_8f = (undefined1)((uint)local_4 >> 8);
  local_8e = (undefined1)((uint)local_4 >> 0x10);
  local_8d = (undefined1)((uint)local_4 >> 0x18);
  local_8c = local_8;
  local_8b = local_7;
  local_8a = local_6;
  local_89 = local_5;
  DES_PermuteBlock(&local_90);
  return;
}
```
