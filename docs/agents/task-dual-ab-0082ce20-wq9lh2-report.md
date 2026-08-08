# Dual A/B report — WQ9L-H2 OWN-ONLY (`0x0082ce20`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-H2**  
**Scope:** VA `0x0082ce20` only. Dual A/B + trio raw/annotated/clean + function records.  
**Sibling:** `0x00415e90` (`StdList_Clear_ESI`) is **ALREADY DUAL** — READ-only for CVOGMenu / CNDUIDialog dtor context; **not** rewritten.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + `batch_decompile` (callees/parents). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** WQ-009 depth-9 residual dual seal — WQ9L-H residual (`WAVE_2026-08-05_wq009_depth9_partition_map.md`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082ce20` CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred | **accept-with-gaps** |

Path A (fidelity): CF/ABI/+0x534/nested-list ECX/notify vtbl[+0xbc]/scalar-delete sealed; product stamp/value_type open → **accept-with-gaps**.  
Path B (adversarial): complete-dtor-merge / hard-abort / host-recreate-merge / free-this / entry-not-entry+8 / 2-arg-iterate / sibling-alias claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Scaffold status (pre-H2)

| Artifact | Pre-H2 | H2 action |
|---|---|---|
| Raw capture | present (2026-07-23) + WQ9L-H re-verify | **Appended** WQ9L-H2 re-verify (body end refined) |
| Annotated | present (WQ9L-H) | kept; still accurate |
| Clean named cpp | present | kept (meaningful names; nested ECX restored) |
| FUN twin include | present | kept |
| Named function record | present (claimed dual sealed) | **Updated** — A/B + H2 report paths real |
| FUN function record | present | **Updated** |
| Review A | **missing** (claimed only) | **Created** |
| Review B | **missing** (claimed only) | **Created** |
| Combined H report | missing | H2 report is this file (single-VA OWN) |

---

## VA `0x0082ce20` — sealed facts

1. **Body:** `0x0082ce20`–`0x0082cf28` exclusive (**264 B** / `0x108`); **RET** @ `0x0082cf27`; pad `CC`. (Prior half-open end `0x0082cf27` / 263 B was off-by-one on RET.)
2. **ABI:** **ECX** = CVOGMenu\* this (`MOV EBP,ECX`); `SUB ESP,8` locals; void; bare **`RET`**.
3. **Semantics:**
   - Early-out if owned hash\* @ **`this+0x534`** is null.
   - Soft-assert TraversalLock @ **hash+0x1d** (`HashError:TraversalLock…` / `VOG_DEBUG_STOP`); force lock = 1.
   - Ordered walk: first node @ **hash+0x14**, successor @ **node+0x14**, entry\* @ **node+8**.
   - Per entry: nested locked list shell @ **entry+8**:
     - `FUN_004294f0` (EnterCS @ list+4; flag @ list+0x28)
     - `FUN_004113b0` iterate (ECX=&iter_state; stack list + out\*); while ret==0 notify **menu vtbl[+0xbc](value)**
     - if flag: clear + `LeaveCriticalSection`
     - `FUN_00410d60` scalar-delete owned chain @ list+0x1c
   - Unlock hash TraversalLock; **scalar-delete** hash (`(**vtbl)(1)`); null `this+0x534`.
4. **Callers (code):**
   - `CVOGMenu_CompleteDtor` `FUN_0082d540` @ `0x0082d56b` (primary complete path)
   - `FUN_0082f130` @ `0x0082f168` (pre-notifies three slots via +0xbc, then this helper, then vtbl[+0x3ac])
5. **Xrefs:** 2 code + 7 data (vtbl exposure: `00a733bc`, `00a72cc4`, `00a720e4`, `00a71b7c`, `00a71644`, `00a70f9c`, `00a70974`).
6. **Callees:** `FUN_007a4480`, `FUN_004294f0`, `FUN_004113b0`, `LeaveCriticalSection`, `FUN_00410d60`, hash scalar-delete.
7. **Name:** `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` (Ghidra `FUN_0082ce20`). Product class sealed via parent RTTI; hash stamp / value_type open → `_Inferred`.
8. **Decompile ≡ raw CF**; nested-list ECX + iterate ABI sealed via `read_memory` + callee decompiles (decompiler elides ECX for `004113b0` / bare `004294f0`/`00410d60`).

### Gaps

- Product English for hash value_type / menu vtbl[+0xbc] notify method.  
- Exact CNDHash stamp / RTTI of object @ +0x534.  
- Nested list element type destroyed by `FUN_00410d60`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082ce20_CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082ce20_CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ H2 re-verify) | `docs/reconstruction/raw/aa_0082ce20_FUN_0082ce20.md` |
| Annotated | `docs/reconstruction/raw/aa_0082ce20_FUN_0082ce20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082ce20.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_0082ce20_FUN_0082ce20.md` |
| Function named | `docs/reconstruction/functions/aa_0082ce20_CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.md` |
| Scaffold named (legacy) | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_0082ce20.cpp` (string-only scaffold; not canonical) |

---

## Chain context (not dualled here; evidence only)

```text
CVOGMenu_CompleteDtor  FUN_0082d540  [dualed WQ9K-G]
  ├─ *this = PTR_FUN_00a72f6c          // CVOGMenu vtbl
  ├─ FUN_0082ce20  CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred  [OWN WQ9L-H2]
  │     ├─ FUN_004294f0   nested list TraversalLock
  │     ├─ FUN_004113b0   nested list iterate-next
  │     ├─ menu vtbl[+0xbc](value)     notify
  │     ├─ LeaveCriticalSection
  │     ├─ FUN_00410d60   nested list destroy owned chain
  │     └─ hash vtbl[0](1)            scalar-delete owned hash @ this+0x534
  └─ FUN_00792c20  CNDUIDialog_CompleteDtor  [dualed]
        └─ (among others) StdList_Clear_ESI @ 0x00415e90  [dualed WQ9L-H — sibling READ-only]

FUN_0082f130  [not dualled]
  ├─ vtbl[+0xbc](this+0x574 / +0x578 / +0x57c) ×3
  ├─ FUN_0082ce20  [OWN WQ9L-H2]
  └─ tail-jmp vtbl[+0x3ac]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082ce20-wq9lh2-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082ce20` | Port as **CVOGMenu-owned CNDHash teardown** at **`this+0x534`**: traversal-lock → ordered walk → per-entry nested-list lock/notify(+0xbc)/destroy → scalar-delete hash → null slot. **ECX thiscall**, void, bare RET. Soft lock logs only. |
| Do not | Free CVOGMenu this; merge with host recreate teardown; treat as full complete dtor; invent value_type / notify English; alias with `StdList_Clear_ESI`. |
| Pair with | dualed `CVOGMenu_CompleteDtor` `0082d540`; dualed `CNDUIDialog_CompleteDtor` `00792c20`; residual callees `004294f0` / `004113b0` / `00410d60` if deeper seal needed. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` row  
- `NAMING_REGISTRY.md` entry + rename-history line  
- `systems/skills-abilities.md` residual table (depth-9)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK  
