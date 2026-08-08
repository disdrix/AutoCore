# Dual A/B report — MEGA-123 OWN-ONLY (`0x00988710`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-123**  
**Scope:** VA `0x00988710` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/xrefs + multi-span `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-123**.  
**Work item:** residual dual seal — helper of dualed **gfxUIWindow_CompleteDtor** (`0x00759de0`): **UI owned-block complete-before-delete**.  
**Hint:** `UiOwnedBlock_CompleteBeforeDelete`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00988710` UiOwnedBlock_CompleteBeforeDelete_Inferred | **accept-with-gaps** — CF/ABI/ECX-this/bare RET/no-host-free/false-noreturn full body/18-xref caller pattern sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): scalar-free-host / stdcall-RET4 / decompile-complete / isnil31-merge / skill-HB-misname / dual-member-release claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00988710` — sealed facts

1. **Body:** `0x00988710`–`0x0098879e` inclusive (**143 B** / `0x8F`); pad `CC` @ `0x0098879f`.  
   Ghidra listed body end `00988784` is **false-noreturn truncated**; epilogue hex seals continuation.
2. **ABI:** **ECX** = this (`MOV EDI,ECX`); SEH `LAB_009ad7cd`; void; **bare `RET`** (`C3` @ `0x0098879e`).
3. **Semantics:** MSVC **complete destructor** of a **heap-owned UI block**:
   - Release refcounted iface @ `+0x0C` (refcount @ iface+4; destroy `vtbl[+8]` when 0); null slot.
   - EH residual second release of the **same** slot (state 0).
   - Tree erase-all via `FUN_0044f3c0` with **EDI=this** (head @ `+0x04`, size @ `+0x08`, isnil@node **+0x25**).
   - `operator_delete(head)` then null head/size.
   - Does **not** free `this` (host free is caller-side only).
4. **Classification:** worker.
5. **Callees:** `FUN_0044f3c0` (tree erase), `operator_delete` @ `0x00489822` (sentinel only).
6. **Callers:** **5** functions / **18** UNCONDITIONAL_CALL — universal pattern `complete(block); operator_delete(block);`:
   - `FUN_00759de0` gfxUIWindow_CompleteDtor @ `0x00759efb` / `0x00759f1b` (slots `+0xB0` / `+0xB4`)
   - `FUN_00586ac0` (4 sites; slots `+0x20/+0x28/+0x30/+0x38`)
   - `FUN_004c0e90` (4 sites; same)
   - `FUN_0055cdf0` (4 sites; slots `[0..3]`)
   - `FUN_0055d750` (4 sites; slots `[0..3]`)
7. **Ctor twin:** `FUN_009886d0` installs empty tree (isnil@+0x25) + null iface — same layout.
8. **RTTI / product demangle:** none on this helper → name **`_Inferred`**.
9. **Name:** `UiOwnedBlock_CompleteBeforeDelete_Inferred` (Ghidra `FUN_00988710`). Scaffold `Named_CalleeOf_Named_gfxUIWindow_00988710` **retired**.
10. **Decompile ≉ full body** (false-noreturn at head delete); **disasm + epilogue hex seal complete CF**.

### Gaps

- Product demangle / exact class English (hence `_Inferred`).  
- Tree key/value element type (isnil@+0x25 family).  
- Exact iface type at `+0x0C`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00988710_UiOwnedBlock_CompleteBeforeDelete_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00988710_UiOwnedBlock_CompleteBeforeDelete_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00988710_FUN_00988710.md` |
| Annotated | `docs/reconstruction/raw/aa_00988710_FUN_00988710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiOwnedBlock_CompleteBeforeDelete_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00988710.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00988710.cpp` |
| Function | `docs/reconstruction/functions/aa_00988710_FUN_00988710.md` |
| Function named | `docs/reconstruction/functions/aa_00988710_UiOwnedBlock_CompleteBeforeDelete_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00759de0  gfxUIWindow_CompleteDtor  [dualed WQ9L-F accept-with-gaps]
  ├─ … tree shells / children assert …
  ├─ slot +0xB0: FUN_00988710; operator_delete  [OWN MEGA-123]
  └─ slot +0xB4: FUN_00988710; operator_delete  [OWN MEGA-123]

FUN_00988710  UiOwnedBlock_CompleteBeforeDelete_Inferred  [OWN MEGA-123]
  ├─ release iface @ +0x0C
  ├─ FUN_0044f3c0  tree erase isnil25  [residual]
  └─ operator_delete(head)

FUN_009886d0  ctor twin (empty tree + null iface)  [residual]
FUN_00586ac0 / FUN_004c0e90 / FUN_0055cdf0 / FUN_0055d750
  └─ same complete-then-delete of owned blocks  [callers; not dualled]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00988710-mega-123-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00988710` | Port as **complete dtor** of a small owned UI block (tree head/size + refcounted iface). **ECX thiscall**, **bare RET**, void. Free **head only** inside; callers free host. Keep distinct from host scalar dtors and from `UiTextLayout_CompleteDtor_Inferred` (`RET 4`). |
| Pair with | dualed `gfxUIWindow_CompleteDtor` `00759de0`; residual ctor twin `009886d0`; residual erase `0044f3c0`; caller teardown helpers `00586ac0` / `004c0e90` / `0055cdf0` / `0055d750`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (UI / gfxUIWindow owned-block — not skill-HB-specific despite partition bucket)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00988710`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; twin `FUN_00988710.cpp` retained; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: false-noreturn ignored; EH double-release residual; host free external.  
- Product demangle open → `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
