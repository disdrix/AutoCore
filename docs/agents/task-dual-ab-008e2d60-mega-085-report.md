# Dual A/B report — MEGA-085 OWN-ONLY (`0x008e2d60`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-085**  
**Scope:** VA `0x008e2d60` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `force_decompile` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-085 residual dual seal — inventory-transfer craft host **reset recipe panel** (hint `UI_CraftHost_ResetRecipePanel`); parent context `0x008e5990`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008e2d60` Client_UI_CraftHost_ResetRecipePanel_Inferred | **accept-with-gaps** — CF/ABI/RET4/5×5 layout/TFID-invalidate/vtbl-only sealed; host RTTI + vtbl English + 2nd caller body open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall-host / cdecl / mission-refresh scaffold / C2S craft / jumptable / +0x7cc-mutate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008e2d60` — sealed facts

1. **Body:** `0x008e2d60`–`0x008e2e5e` inclusive (**255 B** / `0xFF`).
2. **ABI:** **stdcall** stack `void* host`; **`RET 4`**. Prologue loads host via `MOV ESI,[ESP+0x14]` after 4 pushes. **Not** thiscall (ECX = per-widget this only).
3. **Semantics:** craft host **recipe panel reset**:
   - Nested loops **5×5** over cells at `host+0x5b8` (widgets) / `host+0x680` (TFID pairs) / owned objects at cellBase+`0x64` (`host+0x61c` family).
   - Per cell: optional scalar-deleting dtor `vtbl[0](1)`; clear owned; TFID → `0xFFFFFFFF/0xFFFFFFFF`; `vtbl+0x2bc` query → optional `vtbl+0x58`; `vtbl+0xcc(0)`; `vtbl+0x34c`.
   - Per row (`host+0x534`): peer at `+0x1c` and primary `vtbl+4(0)`.
   - Footer `host+0x748`: `vtbl+0xd4(0)` + `vtbl+0x34c`; optional `+0x768` `vtbl+4(0)`; optional `+0x76c` **tail** `JMP [vtbl+4]` with stack arg rewritten to 0.
4. **Callees:** none direct (analyze leaf) — **indirect vtbl only**.
5. **Callers / xrefs (2 UNCONDITIONAL_CALL):**
   - `FUN_008e5990` @ `0x008e59df` — bind/rebuild always resets after stamping `host+0x7cc`.
   - Undeffed body ~`0x008e6390` @ `0x008e63dc` — float accumulate on `host+0x7e4` then reset + refresh helpers.
6. **Name:** `Client_UI_CraftHost_ResetRecipePanel_Inferred` (Ghidra `FUN_008e2d60`). **Reject** `Named_CalleeOf_*Cli_008e2d60` scaffold.
7. **Decompile ≡ force** for CF; ABI/tail sealed via `disassemble_function` + `read_memory` + call-site context.  
   Prologue hex (64 B): `515355568b742414578dae340500008dbe8006000081c6b8050000c744241005000000bb050000008b4e6485c974068b016a01ff108b0ec7466400000000c707ffffffffc74704ffffffff8b11ff92bc020000`

### Gaps

- Product RTTI / English class name of craft host.  
- Vtbl slot English (`+0x2bc`, `+0x58`, `+0xcc`, `+0x34c`, `+0xd4`, `+4`).  
- Second caller function undeffed in Ghidra (gap `0x008e6387`–`0x008e648f`).  
- Parent `FUN_008e5990` residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008e2d60_Client_UI_CraftHost_ResetRecipePanel_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008e2d60_Client_UI_CraftHost_ResetRecipePanel_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008e2d60_FUN_008e2d60.md` |
| Annotated | `docs/reconstruction/raw/aa_008e2d60_FUN_008e2d60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_ResetRecipePanel_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008e2d60.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008e2d60.cpp` |
| Function | `docs/reconstruction/functions/aa_008e2d60_FUN_008e2d60.md` |
| Function named | `docs/reconstruction/functions/aa_008e2d60_Client_UI_CraftHost_ResetRecipePanel_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_008e5ce0  Client_UI_CraftHost_BindObjectByTfid_Inferred  [dualed WQ8R-H]
  └─ FUN_008e5990  bind/clear host selection  [residual MEGA-032 hint]
        ├─ store host+0x7cc = object*
        ├─ FUN_008e2d60  Client_UI_CraftHost_ResetRecipePanel_Inferred  [OWN MEGA-085]
        └─ rebuild name chrome / recipe slots / FUN_008e55e0 / FUN_008e47d0 …

~0x008e6390  undeffed float-gate body  [not dualled]
  └─ FUN_008e2d60  [OWN MEGA-085] then FUN_008e55e0 / FUN_008e41b0 / FUN_008e2f40 / FUN_008e5e00
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008e2d60-mega-085-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008e2d60` | Port as **stdcall** craft-host **recipe panel reset**: arg0=host*, **RET 4**. Walk fixed **5×5** cells; invalidate TFIDs to both-half `0xFFFFFFFF`; destroy owned cell objects; hide/refresh widgets via vtbl offsets (not invented English). Optional footer widgets at `+0x768`/`+0x76c`. |
| Do **not** | Treat as thiscall; treat as mission UI refresh; invent C2S craft packets; merge with bind `008e5ce0` / `008e5990`. |
| Pair with | dualed TFID bind `008e5ce0`; residual host bind `008e5990`; residual panel refresh `008e5e00`. |

| Symbol / offset | Role |
|-----------------|------|
| `host+0x534` | Row widget ptr array ×5 |
| `host+0x5b8` | Cell widget ptr array ×25 |
| `host+0x61c` | Owned object* array ×25 |
| `host+0x680` | Cell TFID pairs ×25 |
| `host+0x748` | Footer chrome |
| `host+0x768` / `+0x76c` | Optional chrome |
| `host+0x7cc` | Bound object* (parent only; not touched here) |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (inventory-transfer craft UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x008e2d60`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + force_decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine twin + retired Named_CalleeOf plate.  
- Odd behavior preserved: decompiler jumptable warning is false (true tail JMP); no host thiscall.  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
