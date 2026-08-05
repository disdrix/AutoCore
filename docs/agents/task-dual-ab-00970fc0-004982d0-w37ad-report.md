# Dual A/B report — W37-AD OWN `aa_00970fc0` + `aa_004982d0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-AD  
**Scope:** VAs `0x00970fc0`, `0x004982d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + `get_xrefs_to` (+ callee decompiles / caller-site bytes). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-AD).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00970fc0` AssPreloader_DrainAcRingToTree_Inferred | **accept-with-gaps** — EAX host / 101 B / ring+0xAC / tree+0xDC / flag branch / value=1 sealed; product method + fail-helper English open |
| `aa_004982d0` ListTrackedCtx_ClearResetCapacity10_Inferred | **accept-with-gaps** — thiscall / 19 B / clear + capacity 10 / AL=1 / sole env+0x100 caller sealed; capacity product English open |

---

## VA `0x00970fc0` — sealed facts

1. **Body:** `0x00970fc0`–`0x00971024` inclusive (**101 B** / `0x65`; pad `CC` @ `0x00971025+`).
2. **ABI:** host in **EAX** (`MOV EBX,EAX`); no stack formals; bare **`RET`**; void. Decompiler `void FUN_00970fc0(void)` incomplete.
3. **Semantics:**
   - Zero local `{u32 key, u8 flag}` via `FUN_0043d6f0`.
   - **ESI = host+0xAC** locked ring; pop via `FUN_0043e850` (EDI=out, AL success).
   - First miss → return.
   - First hit: **`ADD EBX,0xDC` once** → membership tree **host+0xDC**.
   - Loop: if **flag==0** → `FUN_0043d770` (EAX=tree, ECX=key\*); else `FUN_0043d700` find-or-insert → **`*value = 1`**.
   - Pop until empty.
4. **Classification:** worker (drain/process).
5. **Callers (2):** `FUN_00971280` @ `0x009712b2` (W32-J TryPreloadChildAssets…); `FUN_00972140` @ `0x00972182` (W32-K PreloadWorkerLoop). Both `MOV EAX,host`.
6. **Callees:** `FUN_0043d6f0`, `FUN_0043e850`, `FUN_0043d700`, `FUN_0043d770`.
7. **Related rings:** pushers use **+0xAC** with `{key,1}` seed (W33-O) and `{key,0}` side (W36-D) — matches flag branch.
8. **Name:** `AssPreloader_DrainAcRingToTree_Inferred` (Ghidra `FUN_00970fc0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_assPreloader_00970fc0`.
9. **Decompile ≡ raw CF skeleton**; bytes supersede host/ring/tree ABI.  
   Full hex: `558bec83e4f883ec0c53568bd8578d442410e819c7acff8db3ac0000008d7c2410e86ad8acff84c0743481c3dc000000807c2414008d4c2410740f8bfbe8fec6acffc70001000000eb078bc3e85fc7acff8d7c2410e836d8acff84c075d25f5e5b8be55dc3`

### Gaps

- Product/PDB method English.  
- Nested duals: ring pop / find-or-insert / fail helper product roles (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00970fc0_AssPreloader_DrainAcRingToTree_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00970fc0_AssPreloader_DrainAcRingToTree_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00970fc0_FUN_00970fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00970fc0_FUN_00970fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_DrainAcRingToTree_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970fc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00970fc0_FUN_00970fc0.md` |
| Function named | `docs/reconstruction/functions/aa_00970fc0_AssPreloader_DrainAcRingToTree_Inferred.md` |

---

## VA `0x004982d0` — sealed facts

1. **Body:** `0x004982d0`–`0x004982e2` inclusive (**19 B** / `0x13`; pad `CC` @ `0x004982e3+`).
2. **ABI:** **__thiscall**; ECX=self; bare **`C3`**; **AL=1** (`B0 01`).
3. **Semantics:**
   - `ESI = ECX`.
   - `CALL FUN_00497c80` — `ListTrackedCtx_ClearDestroyAndReset_Inferred` (W33-R); ECX still self.
   - `*(self+0xC) = 10` — re-seed capacity after clear zeroed +0xC.
   - Return 1.
4. **Classification:** wrapper.
5. **Callers (1):** `FUN_0048fc90` @ `0x0048fe6d` — `MOV ECX,[ESI+0x100]; CALL` (PalantirEnv init / Drive_NDRiver_fx path). Self = **env+0x100** ListTrackedCtx child, not env root.
6. **Callees:** `FUN_00497c80` only.
7. **Siblings (context, not owned):** `FUN_004982f0` (clear + capacity 10 + recompute dims); `FUN_00498260` (clear + free +0xB4).
8. **Name:** `ListTrackedCtx_ClearResetCapacity10_Inferred` (Ghidra `FUN_004982d0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_004982d0`.
9. **Decompile ≡ raw CF**; bytes seal thiscall/order/constant.  
   Full hex: `568bf1e8a8f9ffffc7460c0a000000b0015ec3`

### Gaps

- Product English for capacity constant **10**.  
- Intent of leaving dims +4/+8 at 0 on this thin path (sibling recomputes).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004982d0_ListTrackedCtx_ClearResetCapacity10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004982d0_ListTrackedCtx_ClearResetCapacity10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004982d0_FUN_004982d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004982d0_FUN_004982d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ListTrackedCtx_ClearResetCapacity10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004982d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004982d0_FUN_004982d0.md` |
| Function named | `docs/reconstruction/functions/aa_004982d0_ListTrackedCtx_ClearResetCapacity10_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00970fc0` | Port as **AssPreloader drain** with **host in EAX** (not ECX thiscall). Pop **host+0xAC** until empty; success flag → find-or-insert **host+0xDC** value **1**; fail flag → `FUN_0043d770`. Do **not** skip before W32-J/W32-K loops that assume a drained ring. Do **not** confuse +0xAC with +0x4C / +0x7C rings. |
| `004982d0` | Port as **ListTrackedCtx clear + capacity 10**: thiscall, return 1, call W33-R clear first, then `*(+0xC)=10`. Caller binds **env+0x100**. Do **not** recompute dims here; do **not** treat as FX loader. |
| Shared | Unrelated systems (AssPreloader vs ListTrackedCtx); co-owned only by W37-AD partition. No shared state. |
| Types | Avoid bare `undefined4` in clean (`uint32_t` / `uint8_t` / `PodU32U8`). |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00971280` | TryPreloadChildAssets… — caller of drain (W32-J) |
| `0x00972140` | PreloadWorkerLoop — caller of drain (W32-K) |
| `0x0043e850` | Locked ring pop (ESI=ring, EDI=out) |
| `0x0043d700` | Tree find-or-insert (ECX=key\*, EDI=tree) |
| `0x0043d770` | Fail-path helper (sole caller = this drain) |
| `0x00497c80` | ListTrackedCtx clear-destroy-reset (W33-R) |
| `0x0048fc90` | Sole caller of capacity-10 wrapper |
| `0x004982f0` | Clear + capacity 10 + dim recompute sibling |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory (+ xrefs / callee decompiles / caller-site bytes). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W37-AD sections).  
- No invented product plates; `_Inferred` names from AssPreloader / ListTrackedCtx sealed families.  
- Rejected scaffold callee-of / Drive_NDRiver product aliases.  
- Avoided bare `undefined4` in clean (`uint8_t` / `uint32_t` / structs).  
- Terminal coverage claim: **false** (no runtime/diff/bit-exact Confirmed).
