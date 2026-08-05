# Raw capture: FUN_004cb3e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb3e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cb3e0` |
| **Canonical name** | `FUN_004cb3e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cb3e0(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x240) = *param_2;
  *(undefined4 *)(param_1 + 0x244) = param_2[1];
  *(undefined4 *)(param_1 + 0x248) = param_2[2];
  *(undefined4 *)(param_1 + 0x24c) = param_2[3];
  return;
}
```

---

## Re-verify append (2026-07-29 OWN-ONLY dual)

| Check | Result |
|---|---|
| Live `decompile_function` @ `0x004cb3e0` | **≡** body above |
| `read_memory` body | four `mov` to `ecx+0x240..0x24c` + `c2 04 00` |
| Ghidra body range | `004cb3e0`–`004cb409` |
| Callers | `004c3a40`@`004c3aa6`, `005cd3b0`@`005ce8a3` |
| Dual A/B | `reviews/A_aa_004cb3e0_CVOGObject_StoreLocalPosition4_Inferred.md` + `B_*` |

Integrity: raw body above **not overwritten**; this section append-only.
