# Raw capture: __RTDynamicCast

| Field | Value |
|---|---|
| **Stable ID** | `aa_004898a4` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004898a4` |
| **Canonical name** | `__RTDynamicCast` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __RTDynamicCast(void)

{
                    /* WARNING: Could not recover jumptable at 0x004898a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __RTDynamicCast();
  return;
}
```

---

## R10-011 re-verify append (2026-08-05) — do not wipe prior raw

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual **R10-011** |
| **VA exclusive** | `0x004898a4` (`aa_004898a4`) |
| **System (partition)** | interaction-activation |
| **Parent dual (evidence only)** | `0x00938670` |
| **Tools** | Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs` + `get_function_callers` + `get_xrefs_from` + `get_bulk_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`. **No** Launcher. |
| **Classification** | **IAT thunk** (MSVC CRT `__RTDynamicCast`) |

### Live decompile (Ghidra, unchanged shape)

```c
void __RTDynamicCast(void)

{
                    /* WARNING: Could not recover jumptable at 0x004898a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __RTDynamicCast();
  return;
}
```

### analyze_function_complete (summary)

| Field | Value |
|---|---|
| name | `__RTDynamicCast` |
| address | `004898a4` |
| classification | **thunk** |
| is_thunk | **true** |
| body | `004898a4`–`004898a9` (**6 B**) |
| signature (Ghidra) | `undefined __RTDynamicCast(void)` — **wrong** (IAT jmp; real CRT is 5-arg cdecl) |
| callees | none (indirect via IAT) |
| xref_count (tool page) | ≥100 call sites |
| completeness | 45.0 (thunk profile; plate/comment residual) |

### Machine bytes (`read_memory` @ `0x004898a4`, 32 B window)

```
ff 25 48 66 9c 00 | ff 25 40 66 9c 00 | 83 3d 08 1a d2 00 | ...
```

| Range | Hex | Decode |
|---|---|---|
| `0x004898a4`–`0x004898a9` | `FF 25 48 66 9C 00` | `jmp dword ptr [0x009C6648]` — **OWN body** |
| next IAT slot | `FF 25 40 66 9C 00` | sibling import jmp (not owned) |

### IAT / external linkage

| Item | Value |
|---|---|
| IAT slot | `PTR___RTDynamicCast_009c6648` @ `0x009c6648` |
| xrefs_from entry | INDIRECTION → `0x009c6648`; COMPUTED_JUMP → `EXTERNAL:__RTDynamicCast` |
| bulk xrefs to IAT | from `0x004898a4` only (this thunk) |
| IAT dword snapshot | `0x006ea91e` (load-time resolved CRT impl; **not** dualled body) |

### Call-site ABI seal (sample; all show 5 pushes + `ADD ESP,0x14`)

| Site | Function | After-call cleanup |
|---|---|---|
| `0x009386d6` | `FUN_00938670` (parent) | `ADD ESP,0x14` |
| `0x00532e7b` | `CVOGCharacter_LevelUp` | `ADD ESP,0x14` |
| `0x004de84e` | `FUN_004de760` | `ADD ESP,0x14` |

Parent site arg order (stack bottom→top push order reversed at call):

```text
PUSH 0                  ; isReference = FALSE
PUSH &CVOGStore::RTTI_Type_Descriptor          ; @0x00af8e10 target
PUSH &CVOGClonedObjectBase::RTTI_Type_Descriptor ; @0x00afe0c8 src
PUSH 0                  ; VfDelta = 0
PUSH EAX                ; inptr from Object_ResolveFromTFID
CALL 0x004898a4         ; __RTDynamicCast IAT thunk
MOV EBX,EAX
ADD ESP,0x14
```

### MSVC CRT contract (library; not reconstructed body)

```c
// msvcr* export — implemented outside autoassault.exe
void* __cdecl __RTDynamicCast(
    void* inptr,
    long  VfDelta,
    void* srcType,     // TypeDescriptor*
    void* targetType,  // TypeDescriptor*
    int   isReference);
// returns adjusted pointer or NULL; throws on reference cast failure when isReference!=0
```

### Authority note

Decompiler recursive-call display is an artifact of IAT jmp recovery. **Authoritative unit body** is the 6-byte `FF 25` thunk only. CRT implementation lives in the linked MSVC runtime DLL via IAT.
