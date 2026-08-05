# Raw capture: FUN_005d4fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4fd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d4fd0` |
| **Canonical name** | `FUN_005d4fd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005d4fd0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + param_1 + 0x6c);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x34);
  }
  uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + -0x3c + param_1) + 0x160))
                    (uVar2);
  FUN_007a4480(0xffffffff,"UnloadGraphics on %s (%d)",uVar2);
  FUN_005825d0();
                    /* WARNING: Could not recover jumptable at 0x005d5022. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + -0x40) + 4))();
  return;
}
```

---

## W37-AB re-verify (2026-08-04)

| Field | Value |
|---|---|
| **Tools** | `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw CF (identical) |
| **Body** | `0x005d4fd0`–`0x005d5025` exclusive (**85 B** / `0x55`); tail `FF 60 04`; pad `CC` |
| **Ghidra body** | `005d4fd0`–`005d5024` |
| **ABI** | `__thiscall` / Ghidra `__fastcall`; ECX = MI `this*`; void; **tail JMP** (not bare RET) |
| **String** | `"UnloadGraphics on %s (%d)"` @ `0x009dac54` (imm push `0x009dac54`) |
| **Semantics** | Log entry for unload-graphics: resolve name-id field via vbtable (`root+0x6c` → `+0x34` or `-1`); root `vtbl+0x160(nameId)` → log arg; `FUN_007a4480(-1, fmt, arg)`; `Object_UnloadGraphics_Inferred` (`FUN_005825d0`, W31-T); tail `JMP [*(this-0x40)+4]` with this-adjust `LEA ECX,[ESI-0x40]` |
| **Callees** | vcall `+0x160`, `FUN_007a4480`, `FUN_005825d0`, tail vfunc `+4` |
| **CODE callers** | none direct (DATA-only) |
| **DATA xrefs (8)** | vtable installs: `009ce7e0`, `009ceb30`, `009d4c90`, `009da6d8`, `009db8f0`, `009cbe40`, `009cd748`, `009cfd60` |
| **Classification** | worker (logged unload entry / chain) |
| **Name** | `Object_UnloadGraphics_Entry_Inferred` (**Inferred** from string + sole body caller of W31-T core) |

### Full body hex (85 B)

```
568bf18b46c48b48048d4431c48b80a800000085c0750583c8ffeb038b40348b56c48b4a048b5431c48d4c31c450ff9260010000506854ac9d006affe86ff41c0083c4108bcee8b5d5faff8b46c08d4ec05eff6004
```

### Byte seal (high points)

| Bytes | Meaning |
|-------|---------|
| `56 8B F1` | `PUSH ESI; MOV ESI, ECX` |
| `8B 46 C4` … `8B 80 A8 00 00 00` | load `*(vbtable-root + 0xA8)` ≡ decompiler `root+0x6c` path |
| `85 C0 75 05 83 C8 FF EB 03 8B 40 34` | null → `-1` else `*(ptr+0x34)` |
| `50 FF 92 60 01 00 00` | push id; `CALL [EDX+0x160]` thiscall |
| `50 68 54 AC 9D 00 6A FF E8 … 83 C4 10` | log: result, fmt `0x009dac54`, level `-1`; clean 0x10 (includes leftover vcall push) |
| `8B CE E8 B5 D5 FA FF` | `MOV ECX,ESI; CALL FUN_005825d0` |
| `8B 46 C0 8D 4E C0 5E FF 60 04` | `EAX=[ESI-0x40]; ECX=ESI-0x40; POP ESI; JMP [EAX+4]` |

### Residual

- Format string has `%s` and `%d` but only **one** intentional vararg after format (bytes). Second conversion residual / possible historical mismatch.
- Product English for `vtbl+0x160`, name field `+0x6c`/`+0x34`, and tail base `vtbl+4`.
