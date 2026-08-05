# Raw capture: FUN_0099aef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099aef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0099aef0` |
| **Canonical name** | `FUN_0099aef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0099aef0(uint *param_1,uint param_2)

{
  ushort uVar1;
  byte bVar2;
  undefined4 in_EAX;
  
  bVar2 = (byte)(param_2 >> 8);
  switch(in_EAX) {
  case 0x15:
    *param_1 = param_2;
    return;
  case 0x16:
    *param_1 = param_2 | 0xff000000;
    return;
  case 0x17:
    *(ushort *)param_1 =
         ((param_2._2_1_ & 0xfff8) << 5 | (ushort)(bVar2 & 0xfc)) * 8 |
         (ushort)((byte)(param_2 >> 3) & 0x1f);
    return;
  default:
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effSurfaceFormat.cpp",
                   0x26d,3,"Unimplemented code reached");
    return;
  case 0x19:
    break;
  case 0x1a:
    *(ushort *)param_1 =
         (ushort)(((param_2 >> 0x18 & 0xf0) << 4 | (uint)(param_2._2_1_ & 0xf0)) << 4) |
         (ushort)(bVar2 & 0xf0 | (byte)(param_2 >> 4) & 0xf);
    return;
  }
  uVar1 = (ushort)((param_2 >> 0x10 & 0xf8) << 5);
  if ((char)(param_2 >> 0x18) == '\0') {
    *(ushort *)param_1 = (uVar1 | bVar2 & 0xf8) * 4 | (ushort)(byte)((byte)param_2 >> 3);
    return;
  }
  *(ushort *)param_1 = (uVar1 | bVar2 & 0xd8) * 4 | (ushort)(byte)((byte)param_2 >> 3 | 0x80);
  return;
}
```
