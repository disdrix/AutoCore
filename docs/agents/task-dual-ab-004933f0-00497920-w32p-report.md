# Dual A/B report — W32-P OWN `aa_004933f0` + `aa_00497920`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-P  
**Scope:** VAs `0x004933f0`, `0x00497920` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs/callers (+ callee decompiles). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-P).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004933f0` StdList_AllocSentinel_0xC_Inferred | **accept-with-gaps** — 0xC self-link factory/ABI/EAX return/body 26 B sealed; product third-dword + SEH twin rationale open |
| `aa_00497920` ListTrackedCtx_Ctor_Inferred | **accept-with-gaps** — 0xC8 complete ctor/ret 4/layout/sole factory/global sealed; product demangle + flag polarity + bank element type open |

---

## VA `0x004933f0` — sealed facts

1. **Body:** `0x004933f0`–`0x00493409` inclusive (**26 B** / `0x1A`); pad `CC` @ `0x0049340a+`.
2. **ABI:** no formals; bare **`C3`**; **EAX = node\*** (decompiler `void` **wrong**).
3. **Semantics:** `operator_new(0xC)`; if non-null `*node = node` (next); `*(node+4) = node` when `node+4 != 0` (prev); +8 untouched.
4. **Classification:** factory (analyze_function_complete labels wrapper due to sole callee `operator_new`).
5. **Callers / xrefs:** 20 named callers / 28 xrefs — always head + adjacent size=0 (e.g. PalantirEnv two heads; NDSpecialFX six heads).
6. **Callees:** `operator_new` only.
7. **Related:** SEH twin `StdList_AllocEmptySentinel_Inferred` (`0x0040fb90`); 0x18 sibling `StdList_AllocSentinel_0x18_Inferred` (`0x00457c60`).
8. **Name:** `StdList_AllocSentinel_0xC_Inferred` (Ghidra `FUN_004933f0`; **Inferred** structural). Reject scaffold audio-tab callee name.
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); body hex seals return path.

### Gaps

- Product payload of third dword @+8.  
- Why SEH and non-SEH 0xC factories both exist.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004933f0_StdList_AllocSentinel_0xC_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004933f0_StdList_AllocSentinel_0xC_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004933f0_FUN_004933f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004933f0_FUN_004933f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_AllocSentinel_0xC_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004933f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004933f0_FUN_004933f0.md` |
| Function named | `docs/reconstruction/functions/aa_004933f0_StdList_AllocSentinel_0xC_Inferred.md` |

---

## VA `0x00497920` — sealed facts

1. **Body:** `0x00497920`–`0x0049799c` inclusive (**125 B** / `0x7D`); pad `CC` @ `0x0049799d+`.
2. **ABI:** **`__thiscall`**; ECX = self; stack **parent**; epilogue **`C2 04 00`** (`ret 4`); returns **this**.
3. **Semantics:** complete ctor of **0xC8** ctx:
   - SEH `LAB_009a0dbe`.
   - `FUN_00787520(this+0xB8)` zeros 3 dwords.
   - `*this=1`; `+4/+8/+0x10/+0xB4=0`; `+0xC=5`; `FUN_00788db0(this+0x14, 0xA0)`.
   - `+0xC4 = parent`; **`DAT_00b035cc = this`**.
4. **Object size:** **0xC8** sealed by sole factory `operator_new(200)` in `PalantirEnv_Ctor` → env`+0x100`.
5. **Classification:** worker (complete ctor).
6. **Callers / xrefs:** **1** — `FUN_00492dd0` @ `0x0049307a`.
7. **Callees:** `FUN_00787520`; `FUN_00788db0` (memset-style zero → 1).
8. **Global:** WRITE `DAT_00b035cc`; READ `FUN_004be7d0` (flag@+0, count@+0x10, ptrs@+0x14).
9. **Related:** W31-D `Ctx_ClearListTrackedOwnedAtScaledXY` (`0x00497a30`) uses `*(ctx+0xC4)` parent → host `+0xE898`.
10. **Name:** `ListTrackedCtx_Ctor_Inferred` (Ghidra `FUN_00497920`; **Inferred** structural).
11. **Decompile ≡ raw CF**; ABI/bounds sealed by `read_memory`.

### Gaps

- Product class demangle / English.  
- Slot bank element type; flag@+0 polarity (ctor 1; reader early-outs on non-zero).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00497920_ListTrackedCtx_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00497920_ListTrackedCtx_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00497920_FUN_00497920.md` |
| Annotated | `docs/reconstruction/raw/aa_00497920_FUN_00497920.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ListTrackedCtx_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00497920.cpp` |
| Function | `docs/reconstruction/functions/aa_00497920_FUN_00497920.md` |
| Function named | `docs/reconstruction/functions/aa_00497920_ListTrackedCtx_Ctor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004933f0` | Port as **0xC sentinel factory**: `node = new(0xC); next=prev=self; return node`. Do **not** store size in the node — callers keep size separately. Prefer sharing with SEH twin only if both paths are required; do **not** invent product list type name beyond structural `StdList_*`. |
| `00497920` | Port as **complete ctor** of 0xC8 child: `ctx = Ctor(raw, parent)`. Must set flag/cap/count, zero bank, parent@`+0xC4`, publish process global, **ret 4**. Do **not** fold into PalantirEnv_Ctor. Keep zero helpers or inline equivalent. |
| Pair with | SEH sentinel `0x0040fb90`; 0x18 sentinel `0x00457c60`; PalantirEnv_Ctor `0x00492dd0` (W31-P); scaled clear `0x00497a30` (W31-D); global consumer `0x004be7d0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs / callers / callee decompiles). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Pattern: stdlist sentinel family + PalantirEnv child 0xC8 / ListTracked ctx.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
