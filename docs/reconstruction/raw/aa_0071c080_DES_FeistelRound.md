# Raw capture: DES_FeistelRound

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071c080` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071c080` |
| **Canonical name** | `DES_FeistelRound` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void DES_FeistelRound(void)

{
  byte *unaff_EBX;
  byte *unaff_EDI;
  undefined4 local_4;
  
  DES_RoundFunctionF(&local_4);
  *unaff_EBX = unaff_EDI[4];
  unaff_EBX[1] = unaff_EDI[5];
  unaff_EBX[2] = unaff_EDI[6];
  unaff_EBX[3] = unaff_EDI[7];
  unaff_EBX[4] = *unaff_EDI ^ (byte)local_4;
  unaff_EBX[5] = unaff_EDI[1] ^ (byte)((uint)local_4 >> 8);
  unaff_EBX[6] = unaff_EDI[2] ^ (byte)((uint)local_4 >> 0x10);
  unaff_EBX[7] = unaff_EDI[3] ^ (byte)((uint)local_4 >> 0x18);
  return;
}
```
