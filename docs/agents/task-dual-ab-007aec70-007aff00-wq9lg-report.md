# Dual A/B report — WQ9L-G OWN-ONLY (`0x007aec70`, `0x007aff00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-G**  
**Scope:** VAs `0x007aec70`, `0x007aff00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** WQ-009 residual dual seal — CNDUIWindow complete-dtor chain helpers.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007aec70` CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred | **accept-with-gaps** — CF/ABI/ECX-this/bare RET/owned-flag gate/empty-string vcall/always-zero sealed; product English open |
| `aa_007aff00` CNDUIWindow_ReleaseTextLayoutAndNested_Inferred | **accept-with-gaps** — CF/ABI/gate/`+0x28C` layout free/nested LEA thiscall/zeros sealed; product English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): complete-dtor-as-this / scalar / always-delete / wrong nested this / scaffold product plate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x007aec70` — sealed facts

1. **Body:** `0x007aec70`–`0x007aecc3` inclusive (**84 B** / `0x54`; pad `CC` @ `0x007aecc4`).
2. **ABI:** **ECX** = this (`MOV ESI,ECX`); void; **bare `RET`** (`C3`).
3. **Semantics:** partial teardown helper of **CNDUIWindow**:
   - Load shell\* @ `+0x294`.
   - If non-null and ownership flag `@+0xBB`: `RefCountedPtr_Dtor_Inferred` (`FUN_0096efd0`) on shell, then `operator_delete(shell)`.
   - If shell was non-null: null shell + flag; call `this->vtbl[+0x2B4]("")` with `DAT_00a1419b` (empty C-string).
   - Always zero `+0x29C` and `+0x2A0`.
   - Does **not** free `this`.
4. **Classification:** worker.
5. **Callers:** code — `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` @ `0x007b5c83` (`MOV ECX,ESI`); DATA — many subclass vtbl slots.
6. **Callees:** `FUN_0096efd0`, `operator_delete`.
7. **Name:** `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` (Ghidra `FUN_007aec70`; **Inferred**). Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aec70` **rejected**.
8. **Decompile ≡ bytes** for CF; false-noreturn on `operator_delete` ignored (epilogue hex).  
   Full hex: raw WQ9L-G append (84 B).

### Gaps

- Product English for `vtbl[+0x2B4]` and shell type beyond RefCountedPtr entry.  
- Semantic names for `+0x29C` / `+0x2A0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007aec70_CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007aec70_CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007aec70_FUN_007aec70.md` |
| Annotated | `docs/reconstruction/raw/aa_007aec70_FUN_007aec70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007aec70.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_007aec70.cpp` |
| Function | `docs/reconstruction/functions/aa_007aec70_FUN_007aec70.md` |
| Function named | `docs/reconstruction/functions/aa_007aec70_CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.md` |

---

## VA `0x007aff00` — sealed facts

1. **Body:** `0x007aff00`–`0x007aff51` inclusive (**82 B** / `0x52`; pad `CC` @ `0x007aff52`).
2. **ABI:** **ECX** = this (`MOV ESI,ECX`); void; **bare `RET`** (`C3`).
3. **Semantics:** partial teardown helper of **CNDUIWindow**:
   - If gate `+0x20C != 0`: free owned text layout @ `+0x28C` via `UiTextLayout_CompleteDtor_Inferred` (`FUN_00797d70`, stdcall/`RET 4`) + `operator_delete`; null slot.
   - Always: `FUN_00424060(this+0x1E8)` — nested CS-guarded list clear (**LEA ECX** sealed; decompiler dropped it).
   - Always: zero `+0x128` and `+0x12C`.
   - Does **not** free `this`; does **not** `DeleteCriticalSection` (parent later).
4. **Classification:** worker.
5. **Callers:** code — `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` @ `0x007b5c8a`; DATA — many subclass vtbl slots.
6. **Callees:** `FUN_00797d70`, `operator_delete`, `FUN_00424060`.
7. **Name:** `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` (Ghidra `FUN_007aff00`; **Inferred**). Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00` **rejected**.
8. **Decompile ≉ nested this** (bare call); **bytes seal LEA**. False-noreturn ignored.  
   Full hex: raw WQ9L-G append (82 B).

### Gaps

- Product English for gate `+0x20C` and zeros `+0x128`/`+0x12C`.  
- Nested object class @ `+0x1E8` (parent uses vtbls `00a964b8`/`00a964ac`).  
- Why layout free is gated here vs parent’s later unconditional free of same slot.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007aff00_CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007aff00_CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007aff00_FUN_007aff00.md` |
| Annotated | `docs/reconstruction/raw/aa_007aff00_FUN_007aff00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007aff00.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00.cpp` |
| Function | `docs/reconstruction/functions/aa_007aff00_FUN_007aff00.md` |
| Function named | `docs/reconstruction/functions/aa_007aff00_CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
CNDUIWindow_CompleteDtor  FUN_007b5be0  [dualed WQ9K-F]
  ├─ FUN_007a8580                         [WQ9L-E residual]
  ├─ FUN_007aec70  ReleaseOwnedRefPtrAt294_ClearText  [OWN WQ9L-G]
  │     └─ RefCountedPtr_Dtor_Inferred (0096efd0) + operator_delete
  │     └─ vtbl[+0x2B4]("")
  ├─ FUN_007aff00  ReleaseTextLayoutAndNested         [OWN WQ9L-G]
  │     ├─ (gate +0x20C) UiTextLayout_CompleteDtor_Inferred (00797d70) [WQ9L-F]
  │     └─ FUN_00424060(this+0x1E8)
  ├─ free +0x28C again if still set (00797d70 + delete)
  ├─ nested vtbl restamp + FUN_00424060 + DeleteCriticalSection
  └─ super-base FUN_00759de0 gfxUIWindow_CompleteDtor [WQ9L-F]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007aec70` | Port as **partial CNDUIWindow teardown** only: optional owned RefCountedPtr shell free @`+0x294` (flag `+0xBB`), clear text via `vtbl[+0x2B4]("")`, zero `+0x29C`/`+0x2A0`. **thiscall ECX**, bare **RET**, no free of host. |
| `007aff00` | Port as **partial CNDUIWindow teardown** only: gated layout free @`+0x28C`, nested clear `FUN_00424060(this+0x1E8)`, zero `+0x128`/`+0x12C`. Do **not** DeleteCriticalSection here. Parent may free layout again and re-clear nested. |
| Pair with | dualed `CNDUIWindow_CompleteDtor` `007b5be0`; `UiTextLayout_CompleteDtor_Inferred` `00797d70`; `RefCountedPtr_Dtor_Inferred` `0096efd0`; residual `007a8580` / `00424060`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs + caller assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Rejected VOG_DEBUG_STOP scaffold aliases for both VAs.  
- Closed decompiler gap: nested `LEA ECX,[ESI+0x1E8]` before `FUN_00424060`.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-007aec70-007aff00-wq9lg-report.md` |

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history
- `systems/skills-abilities.md` residual table (depth-9)
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK
