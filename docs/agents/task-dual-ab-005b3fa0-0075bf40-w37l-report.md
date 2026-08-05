# Dual A/B report — W37-L OWN `aa_005b3fa0` + `aa_0075bf40`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-L  
**Scope:** VAs `0x005b3fa0`, `0x0075bf40` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `decompile_function` + `batch_decompile` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + context-only callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-L).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005b3fa0` Obj_PopulateListAt10_ScaledGridFill_Inferred | **accept-with-gaps** — thiscall `ret 0x14`, param_6 gate, F4 store, surface lock + gfxBody load, nested scaled grid list fill, success `1` / fail `0` sealed; product class + node payload English open |
| `aa_0075bf40` GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred | **accept-with-gaps** — thiscall `ret 4`, optional `"DiffuseTexture"` lookup + clear, store `+0x148`, dirty `+0x129=1`, return `0` sealed; product meaning of packed color open |

---

## VA `0x005b3fa0` — sealed facts

1. **Body:** `0x005b3fa0`–`0x005b4255` exclusive (**693 B** / `0x2B5`). Final **`C2 14 00`** (`ret 0x14`); pad `CC`. SEH handler `LAB_009a684b`.
2. **ABI:** **thiscall** — **ECX = this** (0x30 host from W30-O); **five** stack args; returns **status in AL/EAX** (`1` success / `0` fail); callee cleans **20** B.
3. **Stack args (EBP frame after prolog):**
   | Slot | Decomp name | Bytes role |
   |------|-------------|------------|
   | `[ebp+8]` | param_2 | `movss` → `this+0x20` (float) |
   | `[ebp+0xC]` | param_3 | `movss` → `this+0x28` (float) |
   | `[ebp+0x10]` | param_4 | `movss` → `this+0x24` (float) — **middle swap** vs param order |
   | `[ebp+0x14]` | param_5 | **float scale** — multiplies stored extents before `ROUND` |
   | `[ebp+0x18]` | param_6 | **context object\*** — null gate; `this` for `FUN_004f1e20` |
4. **Semantics:**
   - If `param_6 == 0`: restore SEH, **`xor al,al`**, `ret 0x14` → **0**.
   - Else: store three floats + **zero** `this+0x2c` (`xorps`/`movss`).
   - `FUN_004f1e20(1,1)` with **ECX = param_6** (critical-section acquire / ensure-loaded path).
   - Stack-construct body via `FUN_00764030`; path from context via `FUN_004eb1c0`; lock asset `FUN_00764830` (plate `gfxBody.cpp`). Fail if return **&lt; 0**.
   - On hit: extent deltas from locked rect floats; **`DAT_00a0f298 = 0.5f`** half-step; `ROUND(this+0x20 * scale)` × `ROUND(this+0x28 * scale)` nested loops.
   - Inner: build 0x20-ish node payload (pos floats + flags/`param_4`); `FUN_005b4470` (`operator_new(0x30)` node); `FUN_005b43d0(1)` size bump on list at **`this+0x10`**; link head/prev.
   - Success: `FUN_004eb010` teardown, return **1**. Fail: teardown + `FUN_00763f60`, return **0**.
5. **List layout (pairs W30-O ctor):** base `this+0x10`, head `+0x14`, size `+0x18`. Node size **0x30** (`FUN_005b4470`).
6. **Classification:** worker (populate grid list after empty ctor).
7. **Callers (2):** `FUN_004cd8f0` @ `0x004cd97a` (live: `new(0x30)` + `FUN_005b3f60` then this); `FUN_005b4260` @ `0x005b42cc` (convenience ctor, **zero live callers** per W30-O).
8. **Callees:** `FUN_004f1e20`, `FUN_00764030`, `FUN_004eb1c0`, `FUN_00764830`, `FUN_00763f60`, `FUN_005b4470`, `FUN_005b43d0`, `FUN_004eb010`.
9. **Name:** `Obj_PopulateListAt10_ScaledGridFill_Inferred` (Ghidra `FUN_005b3fa0`; **Inferred**). No product plate. Continues W30-O structural family.
10. **Decompile ≡ CF** for gate/store/loops/returns; bytes seal float swap (`+0x20←arg0`, `+0x24←arg2`, `+0x28←arg1`), `ret 0x14`, and list base `ADD EBX,0x10`.  
    Full body hex (`read_memory` @ `0x005b3fa0`, 693 B):

```
558bec83e4f06aff684b689a0064a100000000506489250000000081ecc801000053568b751885f68bd957895c244c0f8483000000f30f104508f30f114320f30f104510f30f114324f30f10450c6a01f30f1143280f57c06a018bcef30f11432ce81adef3ff8d8c2480000000e81e001b008d442428508bcec78424e001000000000000e89771f3ff508d8c2484000000e8fa071b0085c07d378bcee8cf6ff3ff8d8c2480000000c78424dc010000ffffffffe808ff1a0032c08b8c24d401000064890d000000005f5e5b8be55dc21400f30f108424a4000000f30f5c842498000000f30f1144241cf30f108424ac000000f30f5c8424a0000000f30f1144242cd944241cdb5c2428d944242cdb5c2444f30f590598f2a0008d8c2480000000f30f11442418f30f11442448c78424dc010000ffffffffe884fe1a00f30f104c2418f30f1044241cf30f105320f30f590598f2a000f30f114c2438f30f104d14f30f59d1f30f11442430f30f11542414d9442414db5c2418f30f105328f30f59d1f30f11542414d9442414db5c242033c039442418894424140f8ef6000000eb0ff30f10442430eb078da42400000000837c242000c7442424000000000f8ea80000008b54247c83c9fff30f11442450f30f10451083c8ffc644247800894c24648b4c2478f30f114424540f57c0f30f1144245c89442460894c24688954246c83c3108b73048b4e04f30f104424388d4424505051568bcbf30f11442464e8ad0200006a018bcb8bf8e8020200008b44242403442444f30f104424383b442420f30f5844242c897e048b5704893af30f11442438894424247ca9f30f104424308b4424148b75188b5c244c03442428f30f5844241c3b442418f30f11442430f30f10442448f30f11442438894424140f8c0cffffff8bcee8d46df3ff8b8c24d40100005f5eb00164890d000000005b8be55dc21400
```

### Gaps

- Product English class name for the 0x30 host (still open since W30-O).  
- Exact node payload field English (pos / flags / `param_4` role).  
- Unowned callees internals (`FUN_004f1e20`, gfxBody lock, node buy).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b3fa0_Obj_PopulateListAt10_ScaledGridFill_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b3fa0_Obj_PopulateListAt10_ScaledGridFill_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b3fa0_FUN_005b3fa0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3fa0_FUN_005b3fa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_PopulateListAt10_ScaledGridFill_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b3fa0.cpp` |
| Function | `docs/reconstruction/functions/aa_005b3fa0_FUN_005b3fa0.md` |
| Function named | `docs/reconstruction/functions/aa_005b3fa0_Obj_PopulateListAt10_ScaledGridFill_Inferred.md` |

---

## VA `0x0075bf40` — sealed facts

1. **Body:** `0x0075bf40`–`0x0075bf95` exclusive (**85 B** / `0x55`). Final **`C2 04 00`** (`ret 4`); pad `CC`.
2. **ABI:** **thiscall** — **ECX = GfxView\***; one stack arg (**packed color** `uint32`); returns **`0`** in EAX (`xor eax,eax`); callee cleans **4** B.
3. **Semantics:**
   - `EDI = this`.
   - If `*(this+0x134) == 0`: local index = **`-1`**.
   - Else: `ESI = this+0x134`; `FUN_00752370(thiscall on *+0x134, &index, "DiffuseTexture")` — string at **`0x00a9ede4`**.
   - If `index >= 0`: `FUN_00970060(index, 0)` (ESI still `this+0x134` for helper).
   - **`*(this+0x148) = color`**; **`*(uint8*)(this+0x129) = 1`** (dirty).
   - Return **0**.
4. **Decompile gap:** claims `local_4 = param_1` on non-null path — **bytes false**; only lookup or `-1`. CF after that matches.
5. **Classification:** worker (GfxView diffuse color set + clear DiffuseTexture bind).
6. **Callers (8):** `FUN_004c0a90` (pass `0x808080` after SetNear/SetFar on new GfxView), `FUN_004c1960` (`0`), `FUN_0055ca90`, `FUN_00586a40`, `FUN_005b3420`, `FUN_005b36f0`, `FUN_0078c780`, `FUN_0084b890`. **11** xref sites.
7. **Callees:** `FUN_00752370`, `FUN_00970060`.
8. **Name:** `GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred` (Ghidra `FUN_0075bf40`; **Inferred**). String `"DiffuseTexture"` + color store + dirty flag; not Confirmed product plate.
9. **Decompile ≡ CF** for offsets/return; bytes seal ABI + no bogus `local_4=this`.  
    Full body hex (`read_memory` @ `0x0075bf40`, 85 B):

```
5156578bf98b8f3401000085c98db7340100008d442408740d68e4eda90050e80c64ffffeb08c7442408ffffffff8b0085c07c086a0050e8e44021008b4c2410898f48010000c68729010000015f33c05e59c20400
```

### Gaps

- Product English for packed format of `+0x148` (RGB vs ARGB; channel order).  
- Exact semantics of `FUN_00970060(index,0)` (clear/release bind — role sealed by call pattern, not bit-exact).  
- Full GfxView layout beyond `+0x129` / `+0x134` / `+0x148`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075bf40_GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075bf40_GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075bf40_FUN_0075bf40.md` |
| Annotated | `docs/reconstruction/raw/aa_0075bf40_FUN_0075bf40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075bf40.cpp` |
| Function | `docs/reconstruction/functions/aa_0075bf40_FUN_0075bf40.md` |
| Function named | `docs/reconstruction/functions/aa_0075bf40_GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005b3fa0` | Port as **populate** after empty list ctor (`005b3f60`): require non-null context object; store floats with **arg0→+0x20, arg2→+0x24, arg1→+0x28, +0x2c=0**; scale arg multiplies extents; nested `ROUND` loops insert **0x30** list nodes at `+0x10`; return **1/0**. Preserve `ret 0x14`. Prefer live split path (ctor then populate) over dead convenience ctor. |
| `0075bf40` | Port as **GfxView color set**: if effect at `+0x134`, resolve `"DiffuseTexture"` index and clear bind (arg `0`); always write `+0x148` and dirty `+0x129`. Return **0**. Preserve `ret 4`. Call sites pass packed RGB (e.g. `0x808080`, `0`). |
| Shared | Unrelated domains (host grid list vs GfxView material). No shared state. Do not invent product class for `005b3fa0`. Terminal coverage **false**. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + context callees. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- `_Inferred` names; no invented product plates.  
- Avoided bare `undefined4` in clean (`uint32_t` / `float` / typed outs).  
- Related prior: W30-O (`005b3f60`/`005b4260`), W34-N/O (GfxView init callers of `0075bf40`).
