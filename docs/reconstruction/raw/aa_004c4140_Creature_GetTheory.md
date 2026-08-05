# Raw capture: Creature_GetTheory

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4140` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c4140`–`0x004c41bb` |
| **Canonical name** | `Creature_GetTheory` |
| **Ghidra name** | `FUN_004c4140` |
| **System** | `skills-abilities` / character stats |
| **Capture timestamp** | `2026-07-29` (W17-I dual A/B) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Body matches scaffold `aa_004c4140_FUN_004c4140.md` (2026-07-23) |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_004c4140(int param_1)

{
  short sVar1;
  int iVar2;
  short sVar3;
  
  sVar1 = *(short *)(param_1 + 0x140);
  sVar3 = sVar1;
  if (199 < sVar1) {
    sVar3 = 200;
  }
  iVar2 = (int)*(short *)(param_1 + 0x148);
  if (sVar3 + iVar2 < 0xfa) {
    sVar3 = sVar1;
    if (199 < sVar1) {
      sVar3 = 200;
    }
    if (sVar3 + iVar2 < 2) {
      return 1;
    }
  }
  sVar3 = sVar1;
  if (199 < sVar1) {
    sVar3 = 200;
  }
  if (sVar3 + iVar2 < 0xfa) {
    if (199 < sVar1) {
      sVar1 = 200;
    }
    return sVar1 + iVar2;
  }
  return 0xfa;
}
```

## Entry / exit bytes (`read_memory`)

| Addr | Hex | Meaning |
|---|---|---|
| `0x004c4140` | `66 8B 81 40 01 00 00` | `mov ax,[ecx+0x140]` |
| mid | `66 3D C8 00` | `cmp ax, 200` |
| mid | `0F BF 89 48 01 00 00` | `movsx ecx,[ecx+0x148]` (reload bonus) |
| high | `B8 FA 00 00 00 C3` | `mov eax,250; ret` |
| low | `B8 01 00 00 00 C3` | `mov eax,1; ret` |
