# Dual A/B report — WQ9R-I OWN-ONLY (`0x0051b310`, `0x0051b350`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ9R-I  
**Scope:** VAs `0x0051b310`, `0x0051b350` only. Trio + clean + dual A/B.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs/strings/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_residual_partition_map.md` → **WQ9R-I**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051b310` Object_ApplyMaterialBank_Inferred | **accept-with-gaps** — bank offsets/stride/vcall/callee args/vtable role sealed; product demangle + element layout open |
| `aa_0051b350` ServerCreateFromPacket | **accept-with-gaps** — product name + packet create CF/ABI/COID fields/remap traps sealed; call graph + fail-list types open |

**Role note (partition vs product):** Both VAs sit on the WQ-009 residual undualed list (skill-path neighborhood). Sealed roles are **not** skill-bank cast helpers:

| VA | Actual role |
|----|-------------|
| `0x0051b310` | Object **material bank → shader** commit (MatDiffuse/Ambient/Emissive via `FUN_005194f0`) |
| `0x0051b350` | **ServerCreateFromPacket** object factory from unpack stream |

---

## VA `0x0051b310` — sealed facts

1. **Body:** `0x0051b310`–`0x0051b34f` exclusive (**64 B** / `0x40`). Epilogue `ADD ESP,8` / `POP ESI` / `POP ECX` / **`C3`**.
2. **ABI:** **`__thiscall`/`__fastcall`**; ECX=`object*`; no stack formals; void. ECX preserved across body.
3. **Semantics:**
   - Material bank header at **`this+0x144`**; begin **`+0x148`**; end **`+0x14C`**; element stride **`0x10`** (`SAR 4`).
   - If begin null or count 0 → return.
   - `component = vtbl+0x1CC(this)`; require `component` and `*(component+8)` non-null.
   - `FUN_005194f0(*(component+8), this+0x144)` — commits bank to Mat* shader params (callee not owned).
4. **Classification:** worker **virtual method** (23 DATA vtable installs, e.g. `0x009ce3c8` → `0x0051b310`).
5. **Sibling (context only, not owned):** `FUN_0051b2a0` @ `0x0051b2a0` — **empty-bank fill** (inverted gate; `FUN_00519280`); adjacent vtbl slot before this method.
6. **Code callers:** `FUN_004c5510` @ `0x004c5524` (also has parallel mid-object bank path); site `0x004f3760` (no function bound at VA).
7. **Name:** `Object_ApplyMaterialBank_Inferred` (Ghidra `FUN_0051b310`). Product demangle open.
8. **Decompile ≡ raw CF**; offsets sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle.  
- Bank element (0x10) product layout — `FUN_005194f0` dual.  
- `vtbl+0x1CC` return type English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051b310_Object_ApplyMaterialBank_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051b310_Object_ApplyMaterialBank_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051b310_FUN_0051b310.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b310_FUN_0051b310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ApplyMaterialBank_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051b310.cpp` |
| Function | `docs/reconstruction/functions/aa_0051b310_FUN_0051b310.md` |
| Function named | `docs/reconstruction/functions/aa_0051b310_Object_ApplyMaterialBank_Inferred.md` |

---

## VA `0x0051b350` — sealed facts

1. **Body:** `0x0051b350`–`0x0051b54e` exclusive (**510 B** / `0x1FE`); pad **`CC`**.
2. **ABI:** free function; **stack0 = unpack stream\***; **stack1 = host\***; caller-clean (**bare RET**); returns **object\*** / **null** in EAX.
3. **Semantics (ServerCreateFromPacket):**
   - Profiler enter/leave zone **`"ServerCreateFromPacket"`** @ `0x009cee68`.
   - Unpack **CBID** (4 B) via `FUN_00787d40` thiscall on stream; **CBID == -1 → null**.
   - Unpack **COID** (8 B).
   - Optional remap: `Map_LowerBoundFindByIntKey(DAT_00b041fc+4, &it, &cbid)`; if `it != end` replace cbid from **`node+0x10`**, set remapped.
   - Factory `CVOGReaction_GiveItemByCbid`; fail log `"Invalid CBID allocated…"`.
   - `vtbl+8(cbid, host, 1)`; fail log `"Invalid CBID initified…"`.
   - Stamp **`obj+0x160/+0x164`** COID, **`+0x168 = 1`**.
   - `vtbl+0x20(coid_lo, coid_hi, 0, stream, 1)`; success → if remapped **`obj+0x17c |= 0x80`**, return obj.
   - COID fail: log `"Invalid COID initified: … (in ServerCreateFromPacket)"`; `FUN_0040fb90` list head; `vtbl+0x2B0` walk + scalar-delete; `FUN_00403430`; return null.
4. **Decompiler traps (sealed false):**
   - **`unaff_EDI`** as map 4th arg — **false** (BL flag; 2 stack args).
   - Unpack shown without stream this — ECX = stream.
   - `param_1`/`param_2` roles: stream is **arg0**, host is **arg1**.
5. **Classification:** worker (packet create factory). Related (not owned): `AllocateNewObjectFromCbid` (`0x004cf120`) — different success flag (`|= 0x10`) / no packet COID.
6. **Callers:** **none** recovered in Ghidra (indirect gap).
7. **Name:** **`ServerCreateFromPacket`** (product plates). Ghidra `FUN_0051b350`.
8. **Decompile ≡ raw CF**; traps corrected in clean via `read_memory`.

### Gaps

- Call site(s) / integration path.  
- Remap map product English.  
- Fail-path child-list node product types / whether object self is freed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051b350_ServerCreateFromPacket.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051b350_ServerCreateFromPacket.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051b350_FUN_0051b350.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b350_FUN_0051b350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ServerCreateFromPacket.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051b350.cpp` |
| Function | `docs/reconstruction/functions/aa_0051b350_FUN_0051b350.md` |
| Function named | `docs/reconstruction/functions/aa_0051b350_ServerCreateFromPacket.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051b310` | Port as **virtual** object method: if material bank non-empty, resolve gfx via `vtbl+0x1CC`, commit with bank header @ `+0x144` (begin/end @ `+0x148/+0x14C`, stride 0x10). Do **not** merge with empty fill `0051b2a0`. Not a skill cast. |
| `0051b350` | Port as **ServerCreateFromPacket(stream, host)**: unpack CBID/COID; optional CBID remap; GiveItemByCbid → vtbl+8 → stamp COID → vtbl+0x20; remap success sets `+0x17c` bit `0x80` only. Keep distinct from `AllocateNewObjectFromCbid` (`+0x17c \|= 0x10`). Ignore decompiler `unaff_EDI`. |
| Pair with | `FUN_005194f0` / `FUN_0051b2a0` / `FUN_00519280` (material family); `AllocateNewObjectFromCbid` / `CVOGReaction_GiveItemByCbid` / `Map_LowerBoundFindByIntKey` / `Object_SetCoidIdentity` (create family). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs/strings). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `ServerCreateFromPacket` from binary strings; material unit keeps `_Inferred`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
