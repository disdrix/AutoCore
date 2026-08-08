# Dual A/B report — WQ9L-F OWN-ONLY (`0x00759de0`, `0x00797d70`)

**Date:** 2026-08-05  
**Agent:** Report-only dual summary **WQ9L-F-RPT** (sealed duals from OWN-ONLY **WQ9L-F**)  
**Scope:** VAs `0x00759de0`, `0x00797d70` only. Summarize existing dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers. No re-dual; no rewrite of sealed A/B.  
**Ghidra (seal tools used by WQ9L-F):** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + RTTI COL. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** WQ-009 residual dual seal — UI complete dtors in the **CNDUIWindow** teardown chain: **gfxUIWindow complete** + **owned text-layout complete**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00759de0` gfxUIWindow_CompleteDtor | **accept-with-gaps** — CF/ABI/ECX-this/bare RET/RTTI product name/children-assert/false-noreturn full body sealed; helper English open |
| `aa_00797d70` UiTextLayout_CompleteDtor_Inferred | **accept-with-gaps** — CF/ABI/stack-arg/RET4/offset map/no-host-free sealed; product demangle open → `_Inferred` |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): scalar/vector-as-complete / cdecl-this / free-host / false-noreturn truncation / CNDUIWindow-as-this-body / thiscall-on-layout claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00759de0` — sealed facts

1. **Body:** `0x00759de0`–`0x0075a143` inclusive (**868 B** / `0x364`).
2. **ABI:** **ECX** = this (`MOV ESI,ECX`); SEH `LAB_009b3156`; void; **bare `RET`** (`C3` @ `0x0075a0f4` after `ADD ESP,0x20`).
3. **Semantics:** MSVC **complete-object destructor** for **gfxUIWindow**:
   - Install primary vtbl `PTR_FUN_00a9f304` at `*this`.
   - Clear tree shells @ `+0x10` / `+0x04` / `+0xA4`; free vectors; release refcounted iface @ `+0x34`.
   - Optional `FUN_00756be0` if `+0x88`.
   - Children vector @ `+0x94`: assert (`gfxUIWindow.cpp:0x73` / `"Window deleted with children still attached!"`) + zero child `+0x88` + free.
   - EH residual: delete shell heads; nested mid-dtor vtbl `PTR_FUN_00a9db18` @ `+0x30`; shells again.
   - Does **not** free `this` (host free is scalar peer only).
4. **RTTI:** COL `@0x00a9f300` → type_info `0x00afe190` → `.?AVgfxUIWindow@@`. Product demangle sealed.
5. **Peers:** scalar-deleting `vtbl[0]` = `FUN_004401b0` (`0x004401b0`); super-base of `CNDUIWindow_CompleteDtor` (`0x007b5be0`).
6. **Callees:** tree erase helpers (`00440c90` / `00440ab0` / `00440d20` / `00441960` / `00441720`), `FUN_00988710`, `FUN_00756be0`, `FUN_0076d1b0`, `operator_delete`, assert/crash path.
7. **Callers:** `CNDUIWindow_CompleteDtor` / `FUN_007b5be0`, scalar `0x004401b0`, `FUN_00753db0`, `FUN_00968560`, EH unwinds.
8. **Name:** `gfxUIWindow_CompleteDtor` (Ghidra `FUN_00759de0`). Scaffold `Named_gfxUIWindow_00759de0` retired for dual.
9. **Decompile ≉ full body** (false-noreturn truncate at early `operator_delete`); **disasm + epilogue hex seal complete CF**.

### Gaps

- Product English for tree-shell / vector element types.  
- Exact second residual erase helper VA for shell `+0x04` (CF sealed as erase-all + delete head).  
- Helper duals (`FUN_00756be0`, erase family, `FUN_00988710`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00759de0_gfxUIWindow_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00759de0_gfxUIWindow_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00759de0_FUN_00759de0.md` |
| Annotated | `docs/reconstruction/raw/aa_00759de0_FUN_00759de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxUIWindow_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00759de0.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_gfxUIWindow_00759de0.cpp` |
| Function | `docs/reconstruction/functions/aa_00759de0_FUN_00759de0.md` |
| Function named | `docs/reconstruction/functions/aa_00759de0_gfxUIWindow_CompleteDtor.md` |

---

## VA `0x00797d70` — sealed facts

1. **Body:** `0x00797d70`–`0x00797e17` inclusive (**168 B** / `0xA8`).
2. **ABI:** **stack** arg = layout\* (`MOV ESI,[ESP+0x18]`); SEH `LAB_009add5a`; void; **`RET 4`** (`C2 04 00` @ `0x00797e16`).
3. **Semantics:** complete destructor of a **heap-owned text-layout block**:
   - Float metrics: `float@+0xA4 += float@+0xA8`; zero `+0xA8` (SSE `MOVSS`/`ADDSS`/`XORPS`).
   - Finalize: `EBX=layout`; `FUN_00797530(1)`.
   - Free buffer vector @ `+0x94` + null triple.
   - Tear 0x80-stride run vector @ `+0x80` via `FUN_004271c0` (`EBX=layout+0x80`).
   - Destroy embedded `wstring` @ `+0x0C`.
   - Does **not** free host — callers pair with `operator_delete` after return.
4. **RTTI / product demangle:** none on this helper → name **`_Inferred`**.
5. **Owner path:** `CNDUIWindow_CompleteDtor` frees owned layout at `+0x28C`: `FUN_00797d70(p); operator_delete(p)`.
6. **Callees:** `FUN_00797530`, `operator_delete` (vector buffer only), `FUN_004271c0`, `~basic_string<wchar_t>`.
7. **Callers:** `CNDUIWindow_CompleteDtor`, `FUN_007aff00`, many text-edit rebuild paths (~18 functions / 35 xrefs).
8. **Name:** `UiTextLayout_CompleteDtor_Inferred` (Ghidra `FUN_00797d70`). Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_00797d70` retired (debug string is parent path, not this body).
9. **Decompile ≡ raw CF** with noreturn warning; **epilogue hex seals `RET 4`**.

### Gaps

- Product demangle / exact class English (hence `_Inferred`).  
- Element type of 0x80-stride runs; metric semantics beyond “merge then zero delta”.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00797d70_FUN_00797d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00797d70_FUN_00797d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiTextLayout_CompleteDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00797d70.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_00797d70.cpp` |
| Function | `docs/reconstruction/functions/aa_00797d70_FUN_00797d70.md` |
| Function named | `docs/reconstruction/functions/aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
CNDUIWindow_CompleteDtor  FUN_007b5be0  [dualed WQ9K-F]
  ├─ owned text layout @ +0x28C:
  │     FUN_00797d70  UiTextLayout_CompleteDtor_Inferred  [OWN WQ9L-F]
  │     operator_delete(p)
  └─ super-base:
        FUN_00759de0  gfxUIWindow_CompleteDtor  [OWN WQ9L-F]
          ├─ vtbl PTR_FUN_00a9f304; scalar peer FUN_004401b0
          ├─ children assert @ +0x94
          └─ nested mid-dtor vtbl 00a9db18 @ +0x30

FUN_00797d70 also called from text-edit rebuild paths (FUN_007aff00, …)
  └─ callees: FUN_00797530(1), free +0x94, FUN_004271c0 @+0x80, ~wstring @+0x0C
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00759de0-00797d70-wq9lf-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00759de0` | Port as **gfxUIWindow complete dtor** only. **thiscall ECX**, bare **RET**, no `operator_delete(this)`. Install vtbl `00a9f304`; assert children @ `+0x94`; nested vtbl @ `+0x30`. Pair with scalar `004401b0` and derived `CNDUIWindow_CompleteDtor` `007b5be0`. |
| `00797d70` | Port as **owned text-layout complete dtor**. **stdcall 1-arg, RET 4**. Merge metrics `+0xA4/+0xA8`; finalize `00797530(1)`; free vectors; `~wstring`. Do **not** free host inside — callers `dtor(p); operator_delete(p)`. Keep distinct from gfxUIWindow thiscall complete. |
| Pair with | dualed `CNDUIWindow_CompleteDtor` `007b5be0` (WQ9K-F); residual helpers `00756be0` / erase family / `00797530` / `004271c0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY / report-only rules, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (UI gfxUIWindow + text-layout complete dtors)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- Report-only agent **WQ9L-F-RPT**: read sealed dual artifacts only; no re-dual; no parent ledger edits; no Launcher.  
- Seal tools (WQ9L-F): decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + RTTI COL. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA — verdicts **accept-with-gaps** both paths.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names; machine ABI corrections (thiscall bare RET for gfx; stdcall RET 4 for layout; no free-host either).  
- Odd behavior preserved: Ghidra false-noreturn truncates gfx complete body (full CF via disasm); layout finalize uses EBX-this convention; children assert path always runs when non-empty.  
- Product demangle sealed for `00759de0` (RTTI); `_Inferred` retained for `00797d70`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
