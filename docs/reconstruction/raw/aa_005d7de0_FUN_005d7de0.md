# Raw capture: FUN_005d7de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d7de0` |
| **Canonical name** | `FUN_005d7de0` |
| **System** | npc-ai / HBAI / profile-type-4 |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005d7de0(undefined4 *param_1,undefined4 param_2)

{
  FUN_005d1990(param_2);
  *param_1 = &PTR_FUN_009db08c;
  return param_1;
}
```

---

## Re-verify append — 2026-07-29 W28-K

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`. |
| **Live decompile** | ≡ 2026-07-23 raw body (chain base `FUN_005d1990`, install `PTR_FUN_009db08c`, return this) |
| **Body** | `0x005d7de0`–`0x005d7df8` (**25 B** / `0x19`; `RET 4`; pad `CC`) |
| **Xrefs** | Sole code call site inside `FUN_004c9430` @ `0x004c9556` (factory profile type **4**) |
| **Callees** | `FUN_005d1990` only (mid-size HBAI base ctor; not OWN this wave) |
| **Factory size** | `new(0xC0)` case 4 of `Object_EnsurePrimaryHBAI_FromAIProfile` (sealed W27-I) |

### Bytes (`read_memory` @ `0x005d7de0`)

```
8B 44 24 04    mov eax, [esp+4]     ; pOwner
56             push esi
50             push eax             ; stack arg for base
8B F1          mov esi, ecx         ; this
E8 A3 9B FF FF call FUN_005d1990    ; thiscall ECX=this, stack=owner
C7 06 8C B0 9D 00  mov dword [esi], 009db08c
8B C6          mov eax, esi
5E             pop esi
C2 04 00       ret 4
```

### Vtbl `PTR_FUN_009db08c`

- Installed as sole post-base write of this unit.
- Sealed DoLogic sibling `CVOGHBAI_ProfileType4_DoLogic_Inferred` @ `0x005d7ca0` lives at **vtbl+0x50** = DATA `0x009db0dc` (`read_memory` dword = `0x005d7ca0`).

### ABI seal

- **thiscall** ECX = HBAI object; stack owner pointer; **`RET 4`**; returns `this`.
- No SEH frame in this thin leaf (SEH owned by base `FUN_005d1990`).
