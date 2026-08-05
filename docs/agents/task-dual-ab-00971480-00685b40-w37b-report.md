# Dual A/B report — W37-B OWN `aa_00971480` + `aa_00685b40`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-B  
**Scope:** VAs `0x00971480`, `0x00685b40` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/callees/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-B).  
**Terminal coverage claim:** **false** (agent reports never claim terminal bar complete).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00971480` AssPreloader_DrainSuccessResultsAndTally_Inferred | **accept-with-gaps** — stack host / RET 4 / 439 B / success-vec drain+tally+dup-log sealed; pair/key product residual |
| `aa_00685b40` StdRuntimeError_CtorFromString_Inferred | **accept-with-gaps** — thiscall / RET 4 / 83 B / exception+string@+0xc + vtbl `009ea778` sealed; runtime_error plate Inferred |

---

## VA `0x00971480` — sealed facts

1. **Body:** `0x00971480`–`0x00971637` exclusive (**439 B** / `0x1B7`; pad `CC`). Ghidra plate end `00971636` inclusive — epilogue **`C2 04 00`**.
2. **ABI:** **stack host\*** (`[ebp+8]`→EBX); **not** thiscall; **`RET 0x4`**; void. SEH `LAB_009afdf1`.
3. **Semantics:** AssPreloader success-result drain (`assPreloader.cpp` strings Confirmed):
   - Loop: `FUN_0043e750` pop-front on **ESI=`host+0x4c`** (stride-8 success GuardedVector; W32-K host map).
   - Cache find: `HashMap_FindIterator` (`0044e8c0`, W21-N) on **`host+0x110`**.
   - If it==end (`cache+8`) **or** payload@`+0xc` null: time (`0076c330`); tree slot (`0043d570`, EDI=`host+0x10`); store `{obj,time}`; ext bucket (`00970910` `.geo/.dds/.ogg/.xml/OTHER`); size via **`vt[+0x1c]`**; add to **`host+0xe8+b*4`** / count **`host+0xfc+b*4`**.
   - Else: format `"PRELOAD: preloaded already loaded asset %s"` → `vog_LogMessage(...:0xd3)`; destroy temp string; scalar-delete obj `(*vtbl)(1)`.
   - If **`DAT_00d1f618`**: walk tree from `host+0x14`, log `"%d\t\t%s\n"` @ line `0xe8`, advance `00457cc0`; clear flag.
4. **Classification:** **worker**.
5. **Callers (3):**  
   - `AssPreloader_IsKeyTrackedRecursive_Inferred` `00971900` @ `0097191d` (W31-K)  
   - `AssPreloader_IsKeyTreeReady_Inferred` `00971a20` @ `00971a41` (W36-E)  
   - `NDResourceCache_LookupOrCreate` `0075dba0` @ `0075dbc8` when `cache+0x6c` non-null  
6. **Callees:** `0043e750`, `0044e8c0`, `0076c330`, `0043d570`, `00970910`, `0096a630`, `0076cec0`, `vog_LogMessage`, `~basic_string`, `00457cc0`.
7. **Name:** `AssPreloader_DrainSuccessResultsAndTally_Inferred` (Ghidra `FUN_00971480`; **Inferred** method English). **Reject** scaffold `Named_assPreloader_00971480` as product method plate (path Confirmed).
8. **Decompile ≡ bytes** for major CF; **bytes win** on RET 4, stack host, body size.  
   Full hex: raw W37-B append (439 B).

### Gaps

- Pop-pair / hash-key product type.  
- Nested dual free: `0043e750`, `00970910`, `0043d570`, `00457cc0`.  
- Dump-path `vt[+0x1c](name)` arity oddness vs tally path (preserved).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00971480_AssPreloader_DrainSuccessResultsAndTally_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00971480_AssPreloader_DrainSuccessResultsAndTally_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00971480_FUN_00971480.md` |
| Annotated | `docs/reconstruction/raw/aa_00971480_FUN_00971480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_DrainSuccessResultsAndTally_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971480.cpp` |
| Function | `docs/reconstruction/functions/aa_00971480_FUN_00971480.md` |
| Function named | `docs/reconstruction/functions/aa_00971480_AssPreloader_DrainSuccessResultsAndTally_Inferred.md` |

---

## VA `0x00685b40` — sealed facts

1. **Body:** `0x00685b40`–`0x00685b93` exclusive (**83 B** / `0x53`; pad `CC`). Epilogue **`83 C4 10 C2 04 00`**.
2. **ABI:** **`__thiscall`** ECX=`this`→ESI; stack **`const basic_string*`**; **`RET 0x4`**; returns **`this`**. SEH `LAB_009a9fd9`.
3. **Semantics:** Intermediate exception+string ctor:
   - `exception::exception(this)` (IAT)
   - `*this = &PTR_FUN_009ea778` — vtbl `{FUN_00685c00 scalar-dtor, 0x004018e0 what()-SSO}`
   - `basic_string::basic_string(this+0x0c, msg)` copy-ctor
   - return this
4. **Classification:** **worker** (base ctor; throw is caller-side).
5. **Callers (1):** `IdvFileError_Ctor_MsgBracketErrno` (`006874b0` @ `00687591`, W34-B **accept**) — after message assemble; then final vtbl `PTR_FUN_009ead64`.
6. **Related:** dtor `00685ba0`; scalar-dtor `00685c00`; catchables IdvFileError → **runtime_error** → exception (size **0x28**); RTTI `.?AVruntime_error@std@@` @ `0x00af5460` (W34-B).
7. **Name:** `StdRuntimeError_CtorFromString_Inferred` (Ghidra `FUN_00685b40`; **Inferred**). Prior informal W34-B `BaseExceptionString_Ctor`. **Reject** scaffold `Named_CalleeOf_*`.
8. **Decompile ≡ bytes** for CF; **bytes win** on RET 4, ECX this, string @ +0x0c.  
   Full hex: raw W37-B append (83 B).

### Gaps

- Independent COL/RTTI seal of `009ea778` → runtime_error (layout+catchable Inferred).  
- Exact exception subobject fields +4..+0xb.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00685b40_StdRuntimeError_CtorFromString_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00685b40_StdRuntimeError_CtorFromString_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00685b40_FUN_00685b40.md` |
| Annotated | `docs/reconstruction/raw/aa_00685b40_FUN_00685b40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdRuntimeError_CtorFromString_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00685b40.cpp` |
| Function | `docs/reconstruction/functions/aa_00685b40_FUN_00685b40.md` |
| Function named | `docs/reconstruction/functions/aa_00685b40_StdRuntimeError_CtorFromString_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00971480` | Port as **AssPreloader success drain**: **stack host**, **RET 4**, **not** thiscall. Drain **`host+0x4c`** (not pending `+0x1c`). Callers always invoke **before** membership/ready checks and on cache lookup when preloader linked. Preserve already-loaded log path + optional `DAT_00d1f618` dump. |
| `00685b40` | Port as **runtime_error-layout base ctor**: **ECX=this**, stack **string\***, **RET 4**, returns this. Order fixed: `exception` → vtbl `009ea778` → string@`+0x0c`. IdvFileError **must** call this then overwrite vtbl with `009ead64`. Do **not** throw inside. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0044e8c0` | HashMap_FindIterator (W21-N) |
| `0x00971900` | AssPreloader_IsKeyTrackedRecursive — caller of drain |
| `0x00971a20` | AssPreloader_IsKeyTreeReady — caller of drain |
| `0x00972140` | AssPreloader_PreloadWorkerLoop — produces `@+0x4c` |
| `0x0075dba0` | NDResourceCache_LookupOrCreate — conditional drain |
| `0x006874b0` | IdvFileError_Ctor_MsgBracketErrno (W34-B) — sole caller of `00685b40` |
| `0x00685ba0` / `0x00685c00` | matching dtor / scalar-dtor for intermediate vtbl |
| `0x004018e0` | shared `what()`-style SSO |

Pair is **co-partition only** (W37-B); subsystems differ (AssPreloader vs CRT/Idv exception base).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + analyze_function_complete + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates beyond assPreloader path strings + runtime_error catchable hierarchy; method/type English **`_Inferred`**.  
- Avoided bare `undefined4` as sole clean surface (`uint32_t` / explicit host notes).  
- Odd behavior preserved (dump-path size call arity; intermediate vtbl before Idv overwrite).  
- **Terminal coverage:** false.
