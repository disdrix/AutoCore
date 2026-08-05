# Dual A/B report — `aa_004e96e0` Math_CopyFloat4_Inferred

**Date:** 2026-07-29  
**Agent:** W17-O OWN-ONLY  
**Scope:** OWN ONLY VA `0x004e96e0`. Dual A/B + artifacts. Seal full float4 SSE copy.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e96e0` Math_CopyFloat4_Inferred | **accept** — **54-byte SSE float4 copy + cdecl/EAX=dst sealed** |

---

## Sealed facts

1. **ABI:** `float *Math_CopyFloat4_Inferred(float *dst, const float *src)` — **cdecl** stack args `[ebp+8]`/`[ebp+0xC]`, epilogue **`RET`**. Body **`0x004e96e0`–`0x004e9715`** (54 bytes).

2. **Algorithm:** load src.w,x,y,z via `movss`; store dst.x,y,z,w; **EAX = dst*** at ret.

3. **Full W from src:** unlike sibling `0x004e9530` (dirty stack W), this unit reads **`[src+0xC]`**.

4. **Leaf:** no callees, no globals, no branches.

5. **Not** normalize / quat / transform — pure component copy.

6. **Name:** `Math_CopyFloat4_Inferred` — product English **INFERRED** (no string in unit). Parent-seed alias `Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_004e96e0` is incomplete (12+ callers).

---

## Gaps

1. Product/PDB English confirmation.  
2. Runtime / bit-exact / differential — open.  
3. Exhaustive caller catalog beyond analyze sample.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004e96e0_Math_CopyFloat4_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e96e0_Math_CopyFloat4_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004e96e0_Math_CopyFloat4_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004e96e0_FUN_004e96e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_CopyFloat4_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004e96e0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004e96e0_FUN_004e96e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e96e0_FUN_004e96e0.annotated.md` |
| Scratch | `tmp/a_004e96e0.md` |
| This report | `docs/agents/task-dual-ab-004e96e0-math-copyfloat4-report.md` |

---

## AutoCore impact

- Port as **trivial float4 memcpy / component assign** returning dst.
- Prefer this helper when source is full float4/orient/quat; use `004e9530` only for float3→float4 dirty-W pack when matching client.
- No combat or vehicle logic in this leaf.
