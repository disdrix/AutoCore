# Raw capture: FUN_004cba00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cba00` |
| **Canonical name** | `FUN_004cba00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cba00(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004cb4b0(param_3);
  if (iVar1 != *(int *)(param_1 + 4)) {
    if ((*(int *)(iVar1 + 0x14) <= (int)param_3[1]) &&
       ((*(int *)(iVar1 + 0x14) < (int)param_3[1] || (*(uint *)(iVar1 + 0x10) <= *param_3)))) {
      *param_2 = iVar1;
      return;
    }
  }
  *param_2 = *(int *)(param_1 + 4);
  return;
}
```

---

## WQ9G-G re-verify (2026-08-04)

| Field | Value |
|---|---|
| **Agent** | WQ9G-G OWN-ONLY |
| **Tools** | `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context` |
| **No** | `disassemble_bytes`; Launcher; parent ledgers |
| **Live decompile** | ≡ scaffold body (2026-07-23) for CF |
| **Named** | `StdMap_Find_Tfid_Isnil29_Inferred` |

### Body / ABI (bytes)

- **Range:** `0x004cba00`–`0x004cba51` inclusive (**82 B** / `0x52`); pad `CC`.
- **ABI:** MSVC **`__thiscall`**: ECX = map host (`head@+4`); stack `Node** outIt`, `const KeyU32I32* pKey`; epilogue **`RET 8`** (`C2 08 00`) both exits; `*outIt` written; EAX left as `outIt` after write.
- **Full body hex:**
```
51 56 57 8B 7C 24 14 57 8B F1 E8 A1 FA FF FF 8B 76 04 3B C6 89 44 24 14 74 23
8B 4F 04 3B 48 14 7C 1B 7F 07 8B 17 3B 50 10 72 12 8D 44 24 14 8B 08 8B 44 24 10
5F 89 08 5E 59 C2 08 00 8D 44 24 08 89 74 24 08 8B 08 8B 44 24 10 5F 89 08 5E 59
C2 08 00
```

### Semantics (decompile ≡ equality gate bytes)

1. `lb = StdMap_LowerBound_Tfid_Isnil29(this, pKey)` (`FUN_004cb4b0`, RET 4).
2. If `lb == head` → `*outIt = head` (end / miss).
3. Else if `!(pKey < lb.key)` with hi@+0x14 signed then lo@+0x10 unsigned → `*outIt = lb` (hit).
4. Else `*outIt = head` (miss after lower_bound non-end).

Equality is lower_bound + `node.key <= key` (MSVC `_Tree::find` shape). **No** insert/erase/mutate.

### Callers / xrefs (5 UNCONDITIONAL_CALL)

| Site | Parent | Notes |
|---|---|---|
| `0x004ea5d4` | `FUN_004ea350` | map shell via `...+0x164` embed; out stack |
| `0x004ea8bc` | `FUN_004ea350` | same family |
| `0x004eab3d` | `FUN_004ea350` | same family |
| `0x0080757b` | `FUN_00807550` | `LEA ESI,[host+0x244]`; key TFID `@+0x160`; then payload `@node+0x20` |
| `0x005dd84d` | (inline / parent of site) | find then may `CALL 0x004cc400` insert path |

Ghidra callers list: `FUN_004ea350`, `FUN_00807550` (+ site `0x005dd84d`).

### Callee

- Sole: `StdMap_LowerBound_Tfid_Isnil29` (`0x004cb4b0`, dualed W31-N).
