# Raw capture: FUN_004bb1c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb1c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bb1c0` |
| **Canonical name** | `FUN_004bb1c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004bb1c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(param_1,param_2,param_3);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x1e8))();
    return uVar2;
  }
  return 0;
}
```


---

## v2026-07-29 re-decompile + bytes (append) — W18-T dual seal

**Tool:** Ghidra MCP `decompile_function` `0x004bb1c0`; `analyze_function_complete`; `get_function_callers` / `get_function_callees`; `read_memory` length 64; call-site `read_memory` `0x004cdcc0`. **No** `disassemble_bytes`.

**Range / ABI:** body `004bb1c0`–`004bb1e9`; **`RET 0xC`** (three stack args); **ECX passthrough** into `CVOGReaction_ResolveObjectTarget` (callers load resolve ctx, typically `MOV ECX,[host+0xe4e8]`).

**Decompile (reconfirm):**

```c
undefined4 FUN_004bb1c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(param_1,param_2,param_3);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x1e8))();
    return uVar2;
  }
  return 0;
}
```

**Body bytes (hex, 42 B incl. both RET 0xC):**

```
8b44240c8b542408508b4424085250e89cfcffff85c0740d8b108bc8ff92e8010000c20c0033c0c20c00
```

**Decoded (seal aid; decompile primary):**

| VA | Bytes | Meaning |
|---|---|---|
| `004bb1c0` | `8B 44 24 0C` | `MOV EAX,[ESP+0xC]` param_3 (coidHi) |
| `004bb1c4` | `8B 54 24 08` | `MOV EDX,[ESP+8]` param_2 (coidLo) |
| `004bb1c8` | `50` | `PUSH EAX` coidHi |
| `004bb1c9` | `8B 44 24 08` | `MOV EAX,[ESP+8]` (= original param_1 / bGlobal after push) |
| `004bb1cd` | `52` | `PUSH EDX` coidLo |
| `004bb1ce` | `50` | `PUSH EAX` bGlobal |
| `004bb1cf` | `E8 9C FC FF FF` | `CALL CVOGReaction_ResolveObjectTarget` → `0x004bae70` |
| `004bb1d4` | `85 C0` | `TEST EAX,EAX` |
| `004bb1d6` | `74 0D` | `JZ` null → 0 |
| `004bb1d8` | `8B 10` | `MOV EDX,[EAX]` vtbl |
| `004bb1da` | `8B C8` | `MOV ECX,EAX` this=obj |
| `004bb1dc` | `FF 92 E8 01 00 00` | `CALL [EDX+0x1E8]` |
| `004bb1e2` | `C2 0C 00` | `RET 0xC` |
| `004bb1e5` | `33 C0` | `XOR EAX,EAX` |
| `004bb1e7` | `C2 0C 00` | `RET 0xC` |

**Call-site seal (`CVOGSectorMap_DoPlayerOnLoadTrigger` `0x004cdcc0`):**

```
MOV EAX,ECX
MOV EDX,[EAX+0xe7e4]     ; coidHi
MOV ECX,[EAX+0xe4e8]     ; resolve ctx into ECX
MOV EAX,[EAX+0xe7e0]     ; coidLo
PUSH EDX / PUSH EAX / PUSH 0
CALL FUN_004bb1c0
```

**Callers (9):** `CVOGSectorMap_DoPlayerOnLoadTrigger`, `CVOGSectorMap_DoCreatorLoadTrigger`, `Client_UpdateNpcInteractIcons`, `FUN_004cdc80`, `FUN_004d9b50` (`CVOGSectorMap_RemoveCharacter_Inferred`), `FUN_004dbef0`, `FUN_004dd940`, `FUN_005aca60`, `FUN_005accf0`.

**Xrefs (12):** includes the above plus sites inside those bodies.

**Callees:** `CVOGReaction_ResolveObjectTarget` (`0x004bae70`); indirect `vtbl+0x1e8`.

**Siblings:** `004bb010` blob+`+0x1d4`; `004bb070` `+0x1d8`; `004bb0a0` `+0x1dc`; `004bb950` resolve-only.
