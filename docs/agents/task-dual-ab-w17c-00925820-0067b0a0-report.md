# Dual A/B report — W17-C OWN `aa_00925820` + `aa_0067b0a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W17-C  
**Scope:** OWN VAs only: `0x00925820`, `0x0067b0a0`.  
**Excluded:** Parent ledgers (`WORK_QUEUE` / `RESUME` / `ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER`); Launcher.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Structural name | Verdict |
|------|-----------------|---------|
| `aa_0067b0a0` | `Net_SockaddrIn_Init` | **accept** — 49 B thiscall leaf; AF_INET + htons + raw addr sealed |
| `aa_00925820` | `Client_InteractWorldClickHub` | **accept-with-gaps** — stage CF + 100f/20f + ItemPickup/select clear sealed; English/runtime residual |

---

## `aa_0067b0a0` — sealed facts

1. **ABI:** `__thiscall` — `ECX = out*`, stack `(addr:u32, port:u16)`, **`ret 8`**.
2. **Algorithm:** zero 16 B → family **2** → `[+4]=addr` (no htonl) → `[+2]=htons(port)` → return this.
3. **Callee:** Winsock `htons` via IAT `0x009c6830`.
4. **Direct callers (2):** `Net_SockaddrIn_InitInvalid` `0x0046e280`; `FUN_00681950` `0x00681950`.
5. **Name:** structural sibling of sealed `Net_SockaddrIn_InitInvalid`. Product type English **Open**.

---

## `aa_00925820` — sealed facts

1. **ABI:** `__thiscall` client*, stack `(param_2, packedMouse)`, **`ret 8`**. Mouse: lo=sx, hi=sy (signed).
2. **Body:** `00925820`–`00925d59` (1338 B). Virtual install DATA `@ 0x00a2f420` only.
3. **Early gate:** body runs unless `(mode==6 && +0x493==0 && *(DAT_00d1b644+0xf5)==0)`.
4. **Stages:** mouse vtbls `+0x430/+0x428` → optional Stop + longInput(0) → selected `+0x37C` → dead/UI gates → alt `FUN_0091a350` **or** destroy modal (`char+0xcd0`) **or** ray/gather.
5. **Constants:** ray scale **`DAT_00aaa7ac` = 100.0f**; gather radius **20.0f**; mode **6** into `FUN_0058cd60`.
6. **Outcomes:** hit-list → ForPick select / ForInteract + `Client_SendUseObject_IfInteractable`; valid TFID → `Client_SendItemPickup` + clear `select[0x1d6]` + `FUN_0093e120(0)`.
7. **Not** `Client_InteractClickPickTarget` (no 25f unconditional `SendUseObject` path in this body).

---

## Gaps

### `aa_0067b0a0`

1. Product/TNL English type name.  
2. Dual of `FUN_00681950` (out of OWN).  
3. Runtime golden.

### `aa_00925820`

1. Product English: mode 6, `DAT_00d1a860`, flags, vtbl slots.  
2. Duals of `FUN_0093e120` / `FUN_0091a350` / soft-cast helpers (not OWN).  
3. Live UI routing: when this vtbl fires vs ClickPickTarget.  
4. Runtime / bit-exact.

---

## Files

### `aa_0067b0a0` `Net_SockaddrIn_Init`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0067b0a0_Net_SockaddrIn_Init.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0067b0a0_Net_SockaddrIn_Init.md` |
| Function record | `docs/reconstruction/functions/aa_0067b0a0_Net_SockaddrIn_Init.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0067b0a0_FUN_0067b0a0.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/Net_SockaddrIn_Init.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0067b0a0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0067b0a0_FUN_0067b0a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0067b0a0_FUN_0067b0a0.annotated.md` |

### `aa_00925820` `Client_InteractWorldClickHub`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00925820_Client_InteractWorldClickHub.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00925820_Client_InteractWorldClickHub.md` |
| Function record | `docs/reconstruction/functions/aa_00925820_Client_InteractWorldClickHub.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00925820_FUN_00925820.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InteractWorldClickHub.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00925820.cpp` |
| Raw | `docs/reconstruction/raw/aa_00925820_FUN_00925820.md` |
| Annotated | `docs/reconstruction/raw/aa_00925820_FUN_00925820.annotated.md` |

### This report

`docs/agents/task-dual-ab-w17c-00925820-0067b0a0-report.md`

---

## Tools used (both VAs)

- `ghidra-mcp__decompile_function`
- `ghidra-mcp__read_memory`
- `ghidra-mcp__get_function_by_address`
- `ghidra-mcp__get_function_callees` / `get_function_xrefs` / `get_xrefs_to` as needed  
- **Never** `disassemble_bytes`  
- **Never** Launcher
