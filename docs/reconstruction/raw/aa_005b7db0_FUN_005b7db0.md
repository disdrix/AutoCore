# Raw capture: FUN_005b7db0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b7db0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b7db0` |
| **Canonical name** | `FUN_005b7db0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005b7db0(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}
```

---

## Re-verify (W31-L, 2026-07-29) — append only

**Tools:** `batch_decompile` / `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `get_function_xrefs`, `read_memory`. **No** `disassemble_bytes`.

| Check | Result |
|---|---|
| Live decompile CF | **≡ raw** zero-store set (+4,+8,+0xc,+0x14,+0x18,+0x1c,+0x24); no writes to +0/+0x10/+0x20 |
| Body bounds | `0x005b7db0`–`0x005b7dee` exclusive (**62 B** / `0x3E`); final bare **`C3`**; pad `CC`; next fn `FUN_005b7df0` @ `0x005b7df0` |
| ABI (bytes) | SEH frame `push -1; push LAB_009a6ad8; fs:[0]`; `mov eax, ecx`; `xor ecx,ecx`; seven `mov [eax+off], ecx`; SEH restore; `add esp, 0x10`; **`C3`**. **thiscall** ECX=elem; no stack formals; void |
| Xrefs | **1 DATA** @ `0x004942db` in `FUN_004941b0` (vector ctor registration, stride **0x28**, dtor `FUN_005b8000`) |
| Callees | none (leaf) |
| Classification | leaf (element default-ctor callback) |
| Name promote | `Elem0x28_DefaultCtor` — reject scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_005b7db0` |

**Body hex (full):**
`6A FF 68 D8 6A 9A 00 64 A1 00 00 00 00 50 64 89 25 00 00 00 00 51 8B C1 33 C9 89 48 04 89 48 08 89 48 0C 89 48 14 89 48 18 89 48 1C 89 48 24 8B 4C 24 04 64 89 0D 00 00 00 00 83 C4 10 C3`
