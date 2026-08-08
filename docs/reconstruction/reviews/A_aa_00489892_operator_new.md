# Review A (reconstruction fidelity): `aa_00489892` `operator_new`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489892` |
| **VA** | `0x00489892` |
| **Canonical name** | `operator_new` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00489892_operator_new.md` |
| **System** | inventory-transfer (parent dual); unit itself **CRT IAT** |
| **Wave** | R10-002 residual dual |
| **Live tools** | Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs/callers. **No** `disassemble_bytes` primary |
| **Verdict** | **accept** (CRT IAT thunk sealed; not game logic) |

---

## 1. Purpose

MSVC C++ scalar `operator new` **import trampoline**. The unit is a **6-byte IAT jump** into the CRT heap allocator. Every `operator_new(N)` call site in the client eventually lands here (or a sibling array form). Parent residual link: cargo inventory factory `Vehicle_CreateCargoInventoryFromPageCount` (`0x004f3a30`).

Ghidra: name `operator_new`, classification **thunk**, prototype `void * __cdecl operator_new(uint)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00489892_FUN_00489892.md` (+ R10-002 append) |
| Annotated | `docs/reconstruction/raw/aa_00489892_FUN_00489892.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/operator_new.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00489892.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00489892_FUN_00489892.md` |
| Function named | `docs/reconstruction/functions/aa_00489892_operator_new.md` |
| Live disasm | `JMP dword ptr [0x009c6664]` |
| IAT slot | `PTR_operator_new_009c6664` → image dword `0x006ea8a2` at capture |

---

## 3. Seal: body bytes (Confirmed)

`read_memory` / `disassemble_function` @ `0x00489892`:

```
00489892  FF 25 64 66 9C 00    JMP dword ptr [0x009c6664]
; next thunk @ 00489898
```

Hex: `ff2564669c00`

| Claim | Evidence | Conf |
|---|---|---|
| Body size **6 bytes** | single JMP [imm32] | **Confirmed** |
| No prologue / no `ret` in unit | pure indirection | **Confirmed** |
| IAT at `0x009c6664` | displacement in opcode | **Confirmed** |
| External `operator_new` | `get_xrefs_from` COMPUTED_JUMP | **Confirmed** |
| `__cdecl` | Ghidra signature + call sites push size then CALL | **High** |
| Name not `_Inferred` | PE/CRT import symbol | **Confirmed** |
| Clean ≡ bytes (modeled) | JMP through named IAT pointer | **High** |
| Decompiler recursive call is artifact | JMP-as-call modeling | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name `operator_new` | **Confirmed** | Ghidra import / PE |
| Signature `void* __cdecl operator_new(size_t)` | **High** | formal is size in bytes |
| IAT trampoline only | **Confirmed** | 6 B body |
| Not AutoAssault game code | **Confirmed** | CRT cluster |
| OOM throws `bad_alloc` vs null | **Open** | DLL implementation |
| Port needed for server | **N/A as game unit** | use host `new` / allocator |
| xref scale ~3519 | **High** | Ghidra function search |

---

## 5. Callers (sample)

Hundreds–thousands of sites. Named samples from live callers window: `CVOGReaction_GiveItemByCbid`, `Vehicle_CreateCargoInventoryFromPageCount`, `Client_SendInventoryAddItem`, `CVOGMission_AddActiveObjective`, `Skill_GetCategoryCooldownMap`, `CloneBase_LoadWadFile`, plus bulk `FUN_*` tree/list buynode factories (`FUN_00401f40`, `FUN_00403560`, `FUN_00418700`, …).

All treat this as **scalar heap alloc** — not domain-specific.

---

## 6. Gaps

1. CRT DLL body (throw vs null-new, debug heap hooks) — out of unit.
2. Runtime IAT rebinding after load.
3. Secondary thunk `0x00685b20` same name — not this OWN VA.
4. Runtime / bit-exact / differential deferred.

**Verdict:** **accept** — sealed CRT IAT thunk; dual complete for OWN unit.
