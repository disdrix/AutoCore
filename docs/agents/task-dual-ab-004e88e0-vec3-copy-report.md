# Dual A/B report — `aa_004e88e0` Vec3_Copy

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x004e88e0`. Dual A/B + artifacts. Seal pure float3 XYZ copy.  
**Agent:** W17-B  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e88e0` Vec3_Copy | **accept** — **37-byte SSE movss float3 copy sealed** |

---

## Sealed facts

1. **ABI:** `void __cdecl Vec3_Copy(float *dst, float const *src)` — stack `[esp+4]=dst`, `[esp+8]=src`, bare **`RET`**.

2. **Body:** `0x004e88e0`–`0x004e8904` (**37 bytes**).

3. **Algorithm:** load `src[0..2]` via `movss`, store `dst[0..2]` via `movss`. **No** fourth component (`+0xC` / W untouched).

4. **Leaf:** no callees, no arithmetic, not a basis transform.

5. **Name:** `Vec3_Copy` — role-sealed **INFERRED** (no product string in body). Ghidra: `FUN_004e88e0`.

6. **Callers:** 30+ (pose/FX/entity/UI); e.g. turret aim, respawn special-event, NPC interact icons, FindFirstObjectInRadius waypoint XYZ.

---

## Gaps

1. Product/PDB English symbol.  
2. Runtime / bit-exact / differential — open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004e88e0_Vec3_Copy.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e88e0_Vec3_Copy.md` |
| Function record | `docs/reconstruction/functions/aa_004e88e0_FUN_004e88e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vec3_Copy.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_004e88e0.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_004e88e0_FUN_004e88e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e88e0_FUN_004e88e0.annotated.md` |
| Scratch | `tmp/a_004e88e0.md` |
| This report | `docs/agents/task-dual-ab-004e88e0-vec3-copy-report.md` |

---

## AutoCore impact

- Port as trivial XYZ memcpy of three floats (or three assignments).  
- Do **not** copy W when source is float4.  
- Safe leaf for position extracts from float4-aligned object fields.
