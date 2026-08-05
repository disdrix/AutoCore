# Raw capture: Client_RecvFailMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080b100` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0080b100` |
| **Canonical name** | `Client_RecvFailMission` |
| **Ghidra / prior name** | `FUN_0080b100` |
| **System** | missions-progression |
| **Opcode** | **0x20B2** FailMission (S2C apply; same opcode as C2S abandon send) |
| **Capture timestamp** | `2026-07-29` (promote + re-decompile confirm) |
| **Tool** | Ghidra MCP `batch_decompile` / `decompile` |
| **Integrity** | Prior scaffold raw at `aa_0080b100_FUN_0080b100.md`. This file is the promoted named capture. Append versioned sections only if body changes. |

---

## Dispatch site

`Client_PacketDispatch` (`0x00815710`) case `0x20b2` → `FUN_0080b100` / `Client_RecvFailMission`.

Sole Ghidra caller of this function: `Client_PacketDispatch`.

**Sealed 2026-07-29 (UF-012):**
- Sole xref: `From 00815d97 in Client_PacketDispatch [UNCONDITIONAL_CALL]`
- Call site image @ `0x00815d93`: `8b c6 8b cd e8 64 53 ff ff` → `MOV EAX,ESI; MOV ECX,EBP; CALL 0x0080b100`
- Body image: EDI=client; FailMission thiscall ECX=`*(EDI+0xe98)`; missionId=`*(EAX+0x10)`; then `FUN_005307e0` thiscall on same character

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0080b100(int param_1)

{
  char cVar1;
  int in_EAX;
  void *pvVar2;
  
  if (*(int *)(param_1 + 0xe98) != 0) {
    CVOGReaction_FailMission(*(undefined4 *)(in_EAX + 0x10));
    FUN_005307e0();
    if (*(int *)(param_1 + 0xe98) != 0) {
      pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(param_1 + 0xe98) + 0x548),
                                   *(uint *)(DAT_00d1ad10 + 0x10));
      if (pvVar2 == (void *)0x0) {
        FUN_0092fd00();
      }
    }
    if (*(int *)(param_1 + 0x107c) != 0) {
      cVar1 = (**(code **)(**(int **)(param_1 + 0x107c) + 0x3d8))();
      if (cVar1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0080b16d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(param_1 + 0x107c) + 0x448))();
        return;
      }
    }
  }
  return;
}
```

---

## Wire / packet notes

- Opcode **0x20B2**, sector size class **0x18** (C2S build at `Client_UiModalDispatch` case `0x4e46`; AutoCore `FailMissionPacket`).
- Mission id consumed at **`packet+0x10`** (`in_EAX + 0x10` in decompiler — packet pointer recovered as `in_EAX`).
- Character COID fields at `+0x08/+0x0C` are present on the wire but **not read** in this handler body (local character at `game+0xe98` is used instead).
- `CVOGReaction_FailMission` is `__thiscall`; character `this` is the object at `param_1+0xe98` (ECX binding elided by decompiler; only mission id stack arg shown).
