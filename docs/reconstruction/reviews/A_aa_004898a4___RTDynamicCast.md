# Review A (reconstruction fidelity): `aa_004898a4` __RTDynamicCast

| Field | Value |
|---|---|
| **Stable ID** | `aa_004898a4` |
| **VA** | `0x004898a4`–`0x004898a9` (**6 B**) |
| **Canonical name** | `__RTDynamicCast` |
| **Ghidra name** | `__RTDynamicCast` (IAT/import symbol; not `FUN_*`) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R10-011) |
| **Counterpart** | `reviews/B_aa_004898a4___RTDynamicCast.md` |
| **System** | interaction-activation (partition); CRT cross-cutting |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `get_xrefs_from` + `get_bulk_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

In-image **import trampoline** for the MSVC CRT RTTI helper `__RTDynamicCast` (C++ `dynamic_cast` support). The autoassault.exe unit is only:

```text
jmp dword ptr [PTR___RTDynamicCast_009c6648]   ; FF 25 48 66 9C 00
```

Cast graph walking, vf-adjust, and failure behavior live in the linked CRT DLL, not in this 6-byte body.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R10-011 append) | `docs/reconstruction/raw/aa_004898a4___RTDynamicCast.md` |
| Annotated | `docs/reconstruction/raw/aa_004898a4___RTDynamicCast.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/__RTDynamicCast.cpp` |
| Function records | `functions/aa_004898a4___RTDynamicCast.md`, `functions/aa_004898a4_FUN_004898a4.md` |
| Parent call site (evidence) | `FUN_00938670` @ `0x00938670` / call `0x009386d6` |
| Peer sites | `CVOGCharacter_LevelUp` `0x00532e7b`; `FUN_004de760` `0x004de84e` |

---

## 3. Signature (sealed at call sites)

```c
// cdecl; 5 stack args; caller cleans ADD ESP,0x14; result in EAX
void* __cdecl __RTDynamicCast(
    void* inptr,
    long  VfDelta,
    void* srcType,      // TypeDescriptor*
    void* targetType,   // TypeDescriptor*
    int   isReference);
```

| Formal | Source | Conf |
|---|---|---|
| 5 stack args | 5×`PUSH` before `CALL 0x004898a4` at parent + peers | **High** |
| cdecl cleanup | `ADD ESP,0x14` immediately after CALL (multiple sites) | **High** |
| return pointer / NULL | `MOV EBX,EAX` / `TEST EBX,EBX` / `JZ` at parent | **High** |
| name | Ghidra import `__RTDynamicCast` + IAT `PTR___RTDynamicCast_*` | **High** |
| Ghidra `void(void)` proto | decompiler artifact of IAT jmp | **reject as authority** |

---

## 4. Control flow / machine

| Stage | Match | Conf |
|---|---|---|
| Body length 6 B | `get_function_by_address` `004898a4`–`004898a9` | **High** |
| `FF 25` IAT jmp | `read_memory` @ entry | **High** |
| IAT slot `0x009C6648` | bytes + `get_xrefs_from` INDIRECTION | **High** |
| External CRT symbol | COMPUTED_JUMP → `EXTERNAL:__RTDynamicCast` | **High** |
| No in-image callees | `analyze_function_complete` callees=[] | **High** |
| Classification thunk | tool `is_thunk=true` | **High** |

No loops, no locals, no game-side branches in OWN body.

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **CRT IAT thunk** (not product method) |
| Code callers | **100+** (tool page; skills/UI/inventory/missions/interaction) |
| Parent (partition) | `0x00938670` — store-object TFID resolve + cast to `CVOGStore` |
| Product rename | **Not required** — MSVC export name is correct; **no** `_Inferred` |

---

## 6. Gaps

1. CRT DLL implementation body / version — external residual.
2. Full TypeDescriptor pair census across all call sites — open.
3. Ghidra stored prototype still `void(void)` — tooling residual.
4. Runtime / bit-exact / differential — open (Terminal false).

---

## 8. Verdict

Thunk identity, IAT linkage, cdecl 5-arg ABI, and CRT name sealed against live Ghidra. Residual external CRT + full caller census + runtime → **accept-with-gaps**.
