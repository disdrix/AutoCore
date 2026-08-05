# Dual A/B report — `aa_004c4070` Object_GetTargetAccuracyBase_Inferred

**Date:** 2026-07-29  
**Agent:** W17-O OWN-ONLY  
**Scope:** OWN ONLY VA `0x004c4070`. Dual A/B + artifacts. Seal clamp + vehicle thr.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c4070` Object_GetTargetAccuracyBase_Inferred | **accept** — **clamp(min(+0x13e,200)+(+0x146),250) vs thr(1/-100) sealed** |

---

## Sealed facts

1. **ABI:** `int __fastcall Object_GetTargetAccuracyBase_Inferred(void *self)` — **ECX = this**, **no stack args**, epilogue **`RET`**. Body **`0x004c4070`–`0x004c413d`**.

2. **Score:** `min( min(*(i16*)(this+0x13e), 200) + *(i16*)(this+0x146), 250 )`.

3. **Threshold:** multi-inheritance this-adjust then **`vtbl+0x1DC`**. Nonzero probe → thr **1**; zero → thr **-100** via `neg/sbb/and 0x65/add -100`.

4. **Return:** `max(score, thr)` (`if thr < score return score else thr`). Asm recomputes clamp / re-probes rather than CSE.

5. **Product use:** `Client_DebugDumpEntityCombatStats` feeds return into **`"TargetAccuracy:"`** **after** a separate level-band float formula — that formula is **outside** this unit.

6. **Siblings (context):** `0x004c41c0` same shape on `+0x142/+0x14a`; `0x004c4140` on `+0x140/+0x148` with floor 1, no thr.

7. **Name:** `Object_GetTargetAccuracyBase_Inferred` — English **INFERRED** from DebugDump string + role; field product names open.

---

## Gaps

1. Product English for `+0x13e` / `+0x146`.  
2. Product name of `vtbl+0x1DC` (object* vehicle probe).  
3. Whether dual probe call has side effects (exact vs modernized single call).  
4. Discarded-return call sites (e.g. NonCreatureCastAutoHit) — residual there.  
5. Runtime / bit-exact / differential — open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004c4070_Object_GetTargetAccuracyBase_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004c4070_Object_GetTargetAccuracyBase_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004c4070_Object_GetTargetAccuracyBase_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004c4070_FUN_004c4070.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_GetTargetAccuracyBase_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004c4070.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004c4070_FUN_004c4070.md` |
| Annotated | `docs/reconstruction/raw/aa_004c4070_FUN_004c4070.annotated.md` |
| Scratch | `tmp/a_004c4070.md` |
| This report | `docs/agents/task-dual-ab-004c4070-object-gettargetaccuracybase-report.md` |

---

## AutoCore impact

- Port as **int accuracy base** only — do not fold DebugDump level band into the helper.
- Vehicle-present floors low scores at **1**; non-vehicle thr **-100** almost always yields the clamp sum.
- Call sites that ignore the return must remain ignore — pure int helper, no FPU.
- Keep offsets `+0x13e` / `+0x146` until product attr map is sealed.
