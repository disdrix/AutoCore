# Raw capture: CVOGCharacter_IsAreaExplored

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b310` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052b310` |
| **Canonical name** | `CVOGCharacter_IsAreaExplored` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* thiscall on CVOGCharacter: is explored-area bit set?
   Looks up USContinentUnlocked hash at this+0x534; tests ExploredBits bit (areaId-1).
   Area ids valid 1..32. */

bool __thiscall CVOGCharacter_IsAreaExplored(void *this,int continentId,char areaId)

{
  void *pvVar1;
  
  if (('\0' < areaId) && (areaId < '!')) {
    pvVar1 = CNDHash_LookupByKey(*(void **)((int)this + 0x534),continentId);
    if (pvVar1 != (void *)0x0) {
      return (*(uint *)((int)pvVar1 + 8) & 1 << (areaId - 1U & 0x1f)) != 0;
    }
  }
  return false;
}
```
