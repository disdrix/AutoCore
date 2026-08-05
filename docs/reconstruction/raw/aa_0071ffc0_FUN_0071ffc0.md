# Raw capture: FUN_0071ffc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071ffc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071ffc0` |
| **Canonical name** | `FUN_0071ffc0` |
| **System** | client audio / `CSoundManager` |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0071ffc0(char *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int unaff_ESI;
  char *pcVar2;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_ESI + 0x170);
  EnterCriticalSection(lpCriticalSection);
  pcVar2 = *(char **)(unaff_ESI + 0x44);
  if (pcVar2 != *(char **)(unaff_ESI + 0x48)) {
    do {
      iVar1 = _stricmp(pcVar2,param_1);
      if (iVar1 == 0) {
        FUN_00480970(pcVar2 + 200,*(undefined4 *)(unaff_ESI + 0x48),pcVar2,param_1);
        *(int *)(unaff_ESI + 0x48) = *(int *)(unaff_ESI + 0x48) + -200;
        LeaveCriticalSection(lpCriticalSection);
        return;
      }
      pcVar2 = pcVar2 + 200;
    } while (pcVar2 != *(char **)(unaff_ESI + 0x48));
  }
  pcVar2 = *(char **)(unaff_ESI + 0x54);
  if (pcVar2 != *(char **)(unaff_ESI + 0x58)) {
    while (iVar1 = _stricmp(pcVar2,param_1), iVar1 != 0) {
      pcVar2 = pcVar2 + 200;
      if (pcVar2 == *(char **)(unaff_ESI + 0x58)) {
        LeaveCriticalSection(lpCriticalSection);
        return;
      }
    }
    FUN_00480970(pcVar2 + 200,*(undefined4 *)(unaff_ESI + 0x58),pcVar2,param_1);
    *(int *)(unaff_ESI + 0x58) = *(int *)(unaff_ESI + 0x58) + -200;
  }
  LeaveCriticalSection(lpCriticalSection);
  return;
}
```

---

## Reconfirm (2026-07-29, OWN-ONLY dual W16-L)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Live decompile** | ≡ body above (ESI object; CS `+0x170`; two `[begin,end)` ranges at `+0x44/+0x48` and `+0x54/+0x58`; stride **200**; `_stricmp` name; `FUN_00480970` erase; end `-= 200`) |
| **Bytes (entry)** | `53 55 8B 6C 24 0C 57 8D 9E 70 01 00 00 … C2 04 00` — stack name only, **`ret 4`**; `lea ebx,[esi+0x170]` (object in **ESI**) |
| **Callees** | `EnterCriticalSection`, `_stricmp` (cdecl), `FUN_00480970` (erase 0x32 dwords = 200 B), `LeaveCriticalSection` |
| **Callers** | `FUN_007203b0` @ `0x007203de` (`CSoundManager_MarkStopByName`, gated), `FUN_00721a80` @ `0x00721cf3` (music play fail cleanup) |

**Integrity:** raw body unchanged; this section only reconfirms live ≡ raw.
