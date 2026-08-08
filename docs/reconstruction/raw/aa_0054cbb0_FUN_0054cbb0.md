
# Raw capture: FUN_0054cbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0054cbb0` |
| **Canonical name** | `FUN_0054cbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_0054cbb0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a43fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x6f0);
  local_4 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00578830();
    *puVar1 = &PTR_FUN_009d1ba4;
    puVar2 = puVar1;
  }
  ExceptionList = local_c;
  return puVar2;
}
```

---

## R12-023 re-verify append (2026-08-05) — OWN-ONLY dual seal

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_xrefs_to` + `get_function_callers` + `read_memory` (body + vtbl slot + factory dword). **No** `disassemble_bytes`. No Launcher.

### Live decompile ≡ scaffold raw CF

Live decompile at `0x0054cbb0` matches the 2026-07-23 body above byte-for-byte in control flow: SEH → `operator_new(0x6f0)` → null guard → `FUN_00578830` (thiscall ECX=alloc) → `*p = PTR_FUN_009d1ba4` → return p-or-null.

### Body bounds + ABI (read_memory)

| Item | Value |
|---|---|
| Start | `0x0054cbb0` |
| Terminal RET | `0x0054cc02` (`C3`) |
| Inclusive size | **83 B** / `0x53` |
| Pad | `CC` from `0x0054cc03` through `0x0054cc0f` |
| Next leaf | `0x0054cc10` (`0F 57 C0 …`) |
| Stack args | **none** |
| Cleanup | bare **`RET`** (`C3`) — cdecl / no this at entry |
| Return | **EAX** = object* or null |

Body hex (`read_memory` 96 B @ `0x0054cbb0`, first 83 significant):

```text
6a ff 68 fb 43 9a 00 64 a1 00 00 00 00 50 64 89 25 00 00 00 00
51 56 68 f0 06 00 00 e8 .. .. .. .. 8b f0 83 c4 04 89 74 24 04
33 c0 3b f0 89 44 24 10 74 0f 8b ce e8 45 bc 02 00
c7 06 a4 1b 9d 00 8b c6 8b 4c 24 08 5e 64 89 0d 00 00 00 00
83 c4 10 c3
```

### Relative calls / immediates (from body)

| next-IP | Encoding | Target / imm | Meaning |
|---|---|---|---|
| `0x0054cbd1` | `E8` + rel | CRT `operator_new` | heap alloc |
| after | `68 F0 06 00 00` | **`0x6f0`** | object size |
| `0x0054cbeb` | `E8 45 BC 02 00` | **`0x00578830`** | `CVOGHBSkillBase_DefaultCtor` (dualed W23-S) |
| `0x0054cbeb` store | `C7 06 A4 1B 9D 00` | **`0x009d1ba4`** | PossessCreature subclass vtbl |
| `0x0054cc02` | `C3` | bare ret | no stack cleanup of args |

### Xrefs / callers

| Kind | Result |
|---|---|
| Code CALL callers | **0** (`get_function_callers` empty) |
| DATA xref to entry | **1** — dword @ **`0x009d1bec`** = `B0 CB 54 00` → `0x0054cbb0` |
| Vtbl region | `PTR_FUN_009d1ba4` @ `0x009d1ba4`; factory slot at `+0x48` (`0x009d1bec`) |

### Class / size chain (evidence only; non-OWN)

- Parent dual R11-021 `CVOGHBSkill_PossessCreature_ctor` (`0x00626240`): RTTI Confirmed `.?AVCVOGHBSkill_PossessCreature@@`; size **0x6f0**; same vtbl **0x009d1ba4**.
- Callee `0x00578830` = dualed `CVOGHBSkillBase_DefaultCtor` (installs base vtbl `0x009d3fdc` then this factory overwrites with subclass).
- Distinct from full-arg ctor path (`operator_new` + `FUN_00626240` at site `0x006263ab`).

### Named inference (this dual)

`CVOGHBSkill_PossessCreature_DefaultFactory_Inferred` — class via parent RTTI Confirmed + vtbl/size match; role DefaultFactory from new+default-base+subclass-vtbl pattern (no full-arg ctor, no creature bind). **Not** Runtime Confirmed.

