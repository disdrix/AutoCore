# Dual A/B report — `aa_009197a0` Client_FindFirstObjectInRadius (15f callers)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x009197a0`. Dual A/B + artifacts. Seal nearest-object **radius helper** semantics + **15f** call-site constant.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` (+ callers/callees/xrefs/assembly_context). No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009197a0` Client_FindFirstObjectInRadius | **accept-with-gaps** — **15f callers + first-in-radius CF sealed** |

---

## Sealed facts

1. **ABI:** single stack **`float radius`**, **`__stdcall`**, epilogue **`RET 4`**, return **`Object*`** in **EAX**.

2. **All three production callers** push imm **`0x41700000` = 15.0f** immediately before `CALL 0x009197a0`:
   - `Client_Input_PollBoundActions` @ `0x00927b2f` (Activate UseObject fallback)
   - `Client_RecvCompleteDynamicObjective` @ `0x0081002e` (near-player re-UseObject match)
   - `FUN_009210e0` @ `0x0092133d` (gather fallback)

3. **Algorithm (not true nearest):**
   - Player origin = `DAT_00d1b6d8` adj + **vtbl+0x1a0** float4 (xyz used).
   - **Prefer** auto-patrol waypoint (`DAT_00d1ad10` vector `+0x11c/+0x120` non-empty) via `Client_EvalAutoPatrolWaypoint`; if waypoint dist² **&lt;** radius² and TFID resolves → return that object (skip hash).
   - Else **VOG hash** `*(DAT_00d1b644+0xe8f4)` under TraversalLock (`+0x1d`): walk head `+0x14` / next `+0x20` / TFID* `+0xc`; optional predicate; `Object_ResolveFromTFID`; accept **first** with dist² **&lt;** radius² vs object **`+0x80/+0x84/+0x88`**.

4. **Distance:** 3D **squared** compare only (`radius*radius` vs sum of squared deltas). Boundary **strict** (`r² <= dist²` continues / rejects).

5. **`FUN_004e88e0`:** pure **3-float XYZ copy** from the float4 (not a basis transform).

6. **No packet** in this unit. UseObject `0x2072` / other sends belong to **callers**. Hash assert strings (`HashError:Traversal*`, `VOG_DEBUG_STOP`) are shared lock diagnostics — **not** the function’s product name.

7. **Name:** `Client_FindFirstObjectInRadius` (**INFERRED**). Task nickname “nearest-object radius helper” is acceptable only as informal; **falsify** min-distance “nearest.” Deprecate `Named_VOG_DEBUG_STOP_009197a0`.

---

## Gaps

1. Optional filter field decompiler-typed as `pTfid[1].dwCoidHi` + **vtable+0x64** predicate English/type.  
2. Hash walk order (bucket/insertion) when multiple objects lie inside 15f.  
3. Whether `Client_EvalAutoPatrolWaypoint` can emit AutoPatrol **0x20B3** as callee side-effect under its own gates.  
4. `FUN_009210e0` post-return use depth (parent residual).  
5. Runtime live confirmation; PDB/product symbol; bit-exact / diff.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_009197a0_Client_FindFirstObjectInRadius.md` |
| Review B | `docs/reconstruction/reviews/B_aa_009197a0_Client_FindFirstObjectInRadius.md` |
| Function record | `docs/reconstruction/functions/aa_009197a0_Client_FindFirstObjectInRadius.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_FindFirstObjectInRadius.cpp` |
| Raw (authoritative body) | `docs/reconstruction/raw/aa_009197a0_FUN_009197a0.md` |
| Annotated + residual | `docs/reconstruction/raw/aa_009197a0_FUN_009197a0.annotated.md` |
| Scratch | `tmp/a_009197a0.md` |
| This report | `docs/agents/task-dual-ab-009197a0-find-first-object-in-radius-report.md` |

Legacy scaffold (name superseded):  
`functions/aa_009197a0_FUN_009197a0.md`, `reconstructed-exact/FUN_009197a0.cpp`, `Named_VOG_DEBUG_STOP_009197a0.cpp`.

Related system map: `docs/reconstruction/systems/interaction-activation.md` (Activate path already cites `FUN_009197a0(15.0f)`).

---

## AutoCore impact

- Client Activate interact range helper is **15f** first-in-radius (with gather paths also 15f / select² 225) — **not** the click-hub **25f** gate.
- Server ObjectUse range (~30f) remains authority; this unit is **client pick only**.
- Do not implement as “nearest neighbor” min-heap; product may return a non-closest in-range object depending on hash order / patrol prefer.
- Re-UseObject after complete-dynamic-objective also uses this **15f** world scan when matching clone key.
