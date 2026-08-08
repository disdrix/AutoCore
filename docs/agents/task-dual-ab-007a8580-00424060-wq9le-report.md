# Dual A/B report — WQ9L-E OWN-ONLY (`0x007a8580`, `0x00424060`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-E**  
**Scope:** VAs `0x007a8580`, `0x00424060` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + RTTI COL. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-E**.  
**Work item:** WQ-009 depth-9 residual dual seal — **CNDUIWindow complete dtor** leaves (owned-object clear + nested CS-list DestroyAll).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007a8580` CNDUIWindow_ClearOwnedObject_Inferred | **accept-with-gaps** — CF/ABI/offsets/vtbl+0x44/set-pair sealed; product type of `+0x298` open |
| `aa_00424060` ObjectCsList_DestroyAll_Inferred | **accept** — CF/ABI/NoNode4/throw/product DestroyAll string/callers sealed; family demangle residual only |

Path A (fidelity): **accept-with-gaps** / **accept**.  
Path B (adversarial): complete-as-clear / always-delete-owned / free-list / merge-with-node4-clear / TextMarkup-only claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x007a8580` — sealed facts

1. **Body:** `0x007a8580`–`0x007a85df` inclusive (**96 B** / `0x60`); next prologue `FUN_007a85e0`.
2. **ABI:** **ECX** = this (`MOV ESI,ECX`); void; bare **`RET`** (`C3`).
3. **Semantics:** virtual **clear owned object** at `this+0x298`:
   - Guard: skip body if `+0x298 == 0` (still fall through to always-null).
   - If `+0x2B4` child non-null: scalar dtor **flags=0** (release, no free).
   - vcall `vtbl[+0x4C]()`; vcall `vtbl[+0x288]("")` (`DAT_00a1419b` empty string).
   - If ownership byte `+0xBC`: scalar-delete owned at `+0x298` **flags=1**; clear flag.
   - Always write `+0x298 = 0`.
4. **Vtbl:** CNDUIWindow primary `PTR_FUN_00a960ac` slot **+0x44** = this; slot **+0x40** = Set pair `FUN_007a85e0` (calls clear first).
5. **Owner RTTI:** COL on `00a960ac` → `.?AVCNDUIWindow@@` (parent dual).
6. **Callers (code):** `CNDUIWindow_CompleteDtor` / `FUN_007b5be0`; `FUN_0078ca80` (buffered complete). Many DATA vtbl installs.
7. **Name:** `CNDUIWindow_ClearOwnedObject_Inferred` (Ghidra `FUN_007a8580`). Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_007a8580` retired.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product English for object type stored at `+0x298`.  
- Product names for vtbl `+0x4C` / `+0x288`.  
- Set pair `007a85e0` residual dual (role sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007a8580_CNDUIWindow_ClearOwnedObject_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007a8580_CNDUIWindow_ClearOwnedObject_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007a8580_FUN_007a8580.md` |
| Annotated | `docs/reconstruction/raw/aa_007a8580_FUN_007a8580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_ClearOwnedObject_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007a8580.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_007a8580.cpp` |
| Function | `docs/reconstruction/functions/aa_007a8580_FUN_007a8580.md` |
| Function named | `docs/reconstruction/functions/aa_007a8580_CNDUIWindow_ClearOwnedObject_Inferred.md` |

---

## VA `0x00424060` — sealed facts

1. **Body:** `0x00424060`–`0x0042415a` inclusive (**251 B** / `0xFB`); next `FUN_00424160`.
2. **ABI:** **ECX** = list*; SEH `LAB_009bd790` + `__chkstk 0x1004`; void; bare **`RET`**.
3. **Semantics:** product **DestroyAll** for ObjectCsList-family:
   - `EnterCriticalSection(list+4)`.
   - If byte `list+0x28` set: LeaveCS; `_CxxThrowException(0x80070005)`.
   - While head `list+0x1C`: unlink `node->next` (`+8`); scalar dtor flags=1; **no** `node+4=0`.
   - Zero `+0x24` / `+0x20` / `+0x1C`; LeaveCS.
4. **Product string:** `"List Error!  DestroyAll Call Stack:\n%s\n"` @ `0x00a33af0` (SEH catch) + `"VOG_DEBUG_STOP"`.
5. **Twin:** CF-identical to `ObjectCsList_ClearDestroyNoNode4_Inferred` (`0x0051bc90`); opposite of node+4-clear twin `0x0051b8a0`.
6. **UI nest:** CNDUIWindow `+0x1E8` dual-phase vtbls `00a964b8`/`00a964ac` → RTTI `CNDDoubleListPtr` / `CNDDoubleList` of `STextMarkup@CNDUIWindow`; then this ×2 + `DeleteCriticalSection(+0x1EC)`.
7. **Callers:** 22 code / 38 xrefs — list complete/scalar family, `CNDUIWindow_CompleteDtor`, `FUN_007aff00`, etc.
8. **Name:** `ObjectCsList_DestroyAll_Inferred` (Ghidra `FUN_00424060`). Scaffold retired.
9. **Decompile ≡ raw CF**; layout sealed via disasm + twin family.

### Gaps

- Shared base demangle for all ObjectCsList clones (UI specialization sealed).  
- Exhaustive non-dtor caller audit.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00424060_ObjectCsList_DestroyAll_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00424060_ObjectCsList_DestroyAll_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00424060_FUN_00424060.md` |
| Annotated | `docs/reconstruction/raw/aa_00424060_FUN_00424060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectCsList_DestroyAll_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00424060.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_00424060.cpp` |
| Function | `docs/reconstruction/functions/aa_00424060_FUN_00424060.md` |
| Function named | `docs/reconstruction/functions/aa_00424060_ObjectCsList_DestroyAll_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CNDUIWindow_CompleteDtor  (0x007b5be0)  [dualed WQ9K-F]
  ├─ FUN_007a8580  CNDUIWindow_ClearOwnedObject_Inferred   [OWN WQ9L-E]
  ├─ FUN_007aec70  (residual peer free helper)
  ├─ FUN_007aff00  (residual; also calls 00424060)
  ├─ free strings / owned ptrs
  ├─ nested @+0x1E8:
  │    vtbl 00a964b8 → FUN_00424060  ObjectCsList_DestroyAll_Inferred  [OWN WQ9L-E]
  │    vtbl 00a964ac → FUN_00424060  (again)
  │    DeleteCriticalSection(+0x1EC)
  └─ FUN_00759de0  gfxUIWindow_CompleteDtor  [dualed WQ9L-F READ]

CNDUIWndBuffered complete (0x0078ca80)
  └─ FUN_007a8580  (shared clear)

ObjectCsList family twins (do not merge):
  0x0051b8a0  ClearDestroy (node+4=0)         [dualed]
  0x0051bc90  ClearDestroyNoNode4             [dualed]
  0x00424060  DestroyAll (NoNode4 clone)      [OWN WQ9L-E]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-007a8580-00424060-wq9le-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007a8580` | Port as **CNDUIWindow clear-owned-object** virtual: **ECX=this**, bare RET. Slot vtbl+0x44. Guard `+0x298`; child `+0x2B4` flags=0; own flag `+0xBC` → delete flags=1; always null `+0x298`. Pair with Set `007a85e0`. Call from complete free chain before deeper helpers. |
| `00424060` | Port as **ObjectCsList DestroyAll** (NoNode4): **ECX=list**, EnterCS(+4), throw if `+0x28`, drain head `+0x1C` next@+8 scalar-delete(1), zero counts, LeaveCS. **Do not** clear node+4; **do not** free list/DeleteCS here. Twin of `0051bc90`; do not merge with `0051b8a0`. Nested UI list @ CNDUIWindow+0x1E8 dual-calls then DeleteCS. |
| Pair with | dualed `CNDUIWindow_CompleteDtor` `007b5be0`; dualed `gfxUIWindow_CompleteDtor` `00759de0`; dualed ObjectCsList twins `0051b8a0`/`0051bc90`; residual set `007a85e0`, helpers `007aec70`/`007aff00`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md` row  
- `NAMING_REGISTRY.md` entry + rename-history line  
- `systems/skills-abilities.md` residual table entry (depth-9 section)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK  

**No parent ledger edits performed by WQ9L-E.**
