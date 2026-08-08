# Dual A/B report — R10-002 OWN `aa_00489892` (`operator_new`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual R10-002  
**Scope:** VA `0x00489892` only. Live re-verify + dual A/B + artifacts.  
**Excluded:** parent ledgers; other VAs; Launcher; `disassemble_bytes` primary; invent product names; wipe raw.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_xrefs_from` + callers/xrefs + completeness.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md`  
**Parent dual:** `0x004f3a30` `Vehicle_CreateCargoInventoryFromPageCount`  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00489892` `operator_new` | **accept** — sealed 6-byte CRT IAT thunk; Confirmed import name; not game logic |

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00489892_operator_new.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00489892_operator_new.md` | **accept** |

---

## VA `0x00489892` — sealed facts

1. **Body:** `0x00489892`–`0x00489897` inclusive (**6 B**): `FF 25 64 66 9C 00`.
2. **Disasm:** `JMP dword ptr [0x009c6664]` → `PTR_operator_new_009c6664`.
3. **IAT slot (capture):** dword `0x006ea8a2` at `0x009c6664`; external symbol `operator_new`.
4. **ABI:** `__cdecl`; formal = allocation size (`uint` / `size_t`); return `void*` via CRT (EAX).
5. **Classification:** **thunk** (IAT import trampoline). Completeness profile: thunk.
6. **Name:** `operator_new` — **Confirmed** PE/CRT import. **Not** `_Inferred`. **Reject** inventing game product names.
7. **Scale:** Ghidra `xref_count` **~3519** (universal scalar heap entry).
8. **Decompile:** models recursive `operator_new` call + jumptable warning — **bytes win** (pure JMP).
9. **Siblings (not owned):** `operator_delete[]` `0x0048981c`, `operator_delete` `0x00489822`, `operator_new[]` `0x00489834`. Secondary same-named thunk `0x00685b20` (1 xref) — **different VA**.
10. **Parent residual role:** cargo inventory path allocates via this thunk; unit itself is CRT, not inventory business logic.

### Gaps

- CRT DLL body (OOM throw vs null, debug hooks).  
- Runtime IAT rebinding.  
- Bit-exact / differential deferred.  
- Secondary thunk `0x00685b20` not dualed here.

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00489892_FUN_00489892.md` |
| Annotated | `docs/reconstruction/raw/aa_00489892_FUN_00489892.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/operator_new.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00489892.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00489892_FUN_00489892.md` |
| Function named | `docs/reconstruction/functions/aa_00489892_operator_new.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00489892_operator_new.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00489892_operator_new.md` |
| Report | `docs/agents/task-dual-ab-00489892-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00489892` | **Do not port as game code.** Call sites already dualed with explicit sizes should use host `operator new` / pool allocators. Preserve null-deref-on-OOM parity where retail call sites omit null checks after `operator_new`. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004f3a30` | Parent dual — cargo InventoryGrid alloc uses this thunk |
| `0x00489822` | `operator_delete` sibling IAT |
| `0x00489834` | `operator_new[]` sibling IAT |
| `0x009c6664` | IAT slot `PTR_operator_new` |

Closes R10-002 OWN unit: **CRT scalar `operator_new` IAT trampoline**.

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_complete + read_memory + xrefs/callers + function disasm. **No** `disassemble_bytes` primary.  
- Dual A (fidelity) + B (adversarial) both **accept**.  
- Scaffold raw body preserved; R10-002 re-verify **appended** only.  
- No invented product names; CRT symbol retained.  
- Terminal coverage: **false**.
