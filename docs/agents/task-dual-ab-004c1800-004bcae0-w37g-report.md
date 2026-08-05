# Dual A/B report — W37-G OWN `aa_004c1800` + `aa_004bcae0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-G  
**Scope:** VAs `0x004c1800`, `0x004bcae0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` → **W37-G**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c1800` ParticleFluidLiquidChild_Ctor_Inferred | **accept-with-gaps** — thiscall/RET4/0x40 layout/sentinel/host-link/DAT_00b03794/sole CreateLiquidChild caller sealed; product English + nested `FUN_004c17b0` residual |
| `aa_004bcae0` CNDHash_ReclaimToFreelist_009cb450 | **accept** — 95 B leaf reclaim; ECX hash; value@+8/next@+c/stamp `009cb358`/freelist@+0x20; sole FreeBuckets_009cb450 caller; twin slot split sealed |

---

## VA `0x004c1800` — sealed facts

1. **Body:** `0x004c1800`–`0x004c187d` inclusive (**126 B** / `0x7E`; pad `CC` then next). Epilogue **`C2 04 00`**. SEH `LAB_009a1aa2`.
2. **ABI:** **ECX=`this`**, stack **`phase*`**, returns **`this`**, **`RET 4`**.
3. **Semantics:** Ctor for **0x40** liquid-environment child installed at `phase+0xc4`:
   - `*this = phase`.
   - Empty list: `StdList_AllocSentinel_0xC_Inferred` (`FUN_004933f0`, W32-P) → **`this+0x08`**; size **`this+0x0C = 0`**.
   - Active flag **`this+0x10 = 0`** (parent CreateLiquidChild sets 1 after liquid init); dword **`+0x14 = 0`**.
   - Host-link subobject: **`FUN_004c17b0(this+0x18, this)`** — **bytes win** (`LEA ECX,[ESI+0x18]; PUSH ESI`); decompiler flattens to `FUN_004c17b0(param_1)`.
   - Zero **`+0x20`…`+0x3C`** (8 dwords).
   - Publish **`DAT_00b03794 = this`** (phase host peer global is `DAT_00b03790`).
4. **Classification:** worker.
5. **Callers (1):** `FUN_004c1960` (`ParticleFluidPhase_CreateLiquidChild_Inferred`, W34-O) @ `0x004c1995`.
6. **Callees:** `FUN_004933f0`, `FUN_004c17b0`.
7. **Name:** `ParticleFluidLiquidChild_Ctor_Inferred` (Ghidra `FUN_004c1800`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*Drive_NDRiver_fx_004c1800`.
8. **Decompile vs bytes:** CF matches; **bytes win** on `FUN_004c17b0` ECX target (`+0x18` subobject). Full hex: raw W37-G append.

### Gaps

- Product/PDB demangle English for 0x40 liquid child / `DAT_00b03794`.  
- Full semantic map of zeroed `+0x20..+0x3C` (activate path later uses `+0x38`).  
- Nested `FUN_004c17b0` ownership / list insert into phase host (unowned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c1800_ParticleFluidLiquidChild_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c1800_ParticleFluidLiquidChild_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c1800_FUN_004c1800.md` |
| Annotated | `docs/reconstruction/raw/aa_004c1800_FUN_004c1800.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidLiquidChild_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c1800.cpp` |
| Function | `docs/reconstruction/functions/aa_004c1800_FUN_004c1800.md` |
| Function named | `docs/reconstruction/functions/aa_004c1800_ParticleFluidLiquidChild_Ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004c1800.md` |

---

## VA `0x004bcae0` — sealed facts

1. **Body:** `0x004bcae0`–`0x004bcb3e` inclusive (**95 B** / `0x5F`; pad `CC` then next). Bare **`C3`**.
2. **ABI:** **ECX=`hash*`** (`MOV EBX,ECX`); bare **RET**; void.
3. **Semantics:** CNDHash **owning reclaim → freelist** for family **`009cb450`** (tableC):
   - Loop `i = 0 … *(hash+0x08)` **inclusive** (mask).
   - Chain head at `(*(hash+0x10))[i] + 4`.
   - Per node: stamp **`PTR_FUN_009cb358`**; if value **`node+0x08`** non-null → **`(*vtbl)(1)`**; null value; push node to freelist **`hash+0x20`** (`*node = freelist; freelist = node`); next = **`node+0x0C`**.
   - Clear bucket head after chain drain.
4. **Classification:** leaf (no static callees; virtual delete only).
5. **Callers (1):** `FUN_004bcc60` (`CNDHash_FreeBuckets_009cb450`, W31-M) @ `0x004bcc6a`.
6. **Callees:** none static.
7. **Name:** `CNDHash_ReclaimToFreelist_009cb450` (Ghidra `FUN_004bcae0`). **Reject** scaffold `Named_CalleeOf_*VOG_DEBUG_STOP_004bcae0`. **Do not** substitute twin `FUN_004e2bd0` (W37-J: value@`+0xC`, next@`+0x10`, stamp `009cb360`).
8. **Decompile ≡ raw CF**; node slots + freelist push sealed by bytes. Full hex: raw W37-G append.

### Gaps

- Product/PDB English for value type destroyed via vtbl(1).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bcae0_FUN_004bcae0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcae0_FUN_004bcae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimToFreelist_009cb450.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bcae0.cpp` |
| Function | `docs/reconstruction/functions/aa_004bcae0_FUN_004bcae0.md` |
| Function named | `docs/reconstruction/functions/aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md` |
| Scratch | `docs/reconstruction/tmp/a_004bcae0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c1800` | Port as **liquid-child ctor**: **ECX=this**, stack **phase\***, returns this, **`RET 4`**, object **0x40**. Parent phase @ `+0`; empty 0xC list sentinel @ `+0x08`/`+0x0C`; active `+0x10=0`; host-link subobject ctor on **`+0x18`** (`FUN_004c17b0`); zero `+0x20..+0x3C`; publish `DAT_00b03794`. Do **not** treat as phase ctor (`004c0640`) or liquid filter init (`004c0fe0`). Do **not** invent NDRiver product plate. Nested host-link stays free. |
| `004bcae0` | Port as **tableC reclaim-to-freelist**: **ECX=hash**, bare RET. Loop `0…mask` incl.; destroy values @ **`node+0x08`** via vtbl(1); freelist push **`hash+0x20`**; stamp **`009cb358`**. Do **not** free slab/table/freelist heap here (FreeBuckets parent). Do **not** use twin `004e2bd0` node map (value@`+0xC` / next@`+0x10` / stamp `009cb360`). |
| Shared | Closes W37-G OWN pair: **CreateLiquidChild nested ctor residual** + **FreeBuckets_009cb450 reclaim residual**. Not algorithmically related beyond wave co-ownership. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004c1960` | `ParticleFluidPhase_CreateLiquidChild_Inferred` (W34-O) — sole caller of `004c1800` |
| `0x004c2080` | `ParticleFluidPhase_Init_Inferred` (W33-S) |
| `0x004c0640` | `ParticleFluidPhase_Ctor_Inferred` (W34-M) — publishes `DAT_00b03790` |
| `0x004933f0` | `StdList_AllocSentinel_0xC_Inferred` (W32-P) |
| `0x004c17b0` | host-link subobject ctor @ child `+0x18` |
| `0x004c0fe0` | liquid filter/RT init after ctor (W37-F) |
| `0x004bcc60` | `CNDHash_FreeBuckets_009cb450` (W31-M) — sole caller of `004bcae0` |
| `0x004e2bd0` | twin reclaim family `009cb45c` (W37-J) |
| `0x004bcca0` | FreeBuckets twin (W31-M) |
| `0x00413ea0` | older-family `CNDHash_ReleaseNodesToFreelist_Inferred` |

Closes W37-G OWN pair: liquid-child ctor under CreateLiquidChild + tableC reclaim under FreeBuckets_009cb450.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names / stamp-qualified family ids only.  
- Rejected Named_CalleeOf / NDRiver / VOG_DEBUG_STOP aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit node/hash layouts).  
- Twin reclaim `004e2bd0` deliberately not dualed here (W37-J owns it).
