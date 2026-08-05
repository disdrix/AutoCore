# Dual A/B report — W37-I OWN `aa_00968a50` + `aa_0099c1c0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-I  
**Scope:** VAs `0x00968a50`, `0x0099c1c0` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` / `get_assembly_context` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` → **W37-I**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00968a50` GfxBufferedView_Ctor_Inferred | **accept-with-gaps** — ECX this / 0x198 / derived vtbl / timer+list CF sealed; timer/flag product English open |
| `aa_0099c1c0` CNDAssetStringTable_LoadFromStream_Inferred | **accept-with-gaps** — RET4 stream ABI / null→0 / sole Unserialize wrapper sealed; full host layout open |

---

## VA `0x00968a50` — sealed facts

1. **Body:** `0x00968a50`–`0x00968b14` inclusive (**197 B** / `0xC5`); pad `CC`.
2. **ABI:** **ECX=`GfxBufferedView*`**; **0** stack formals; returns **this**; SEH `LAB_009b3023`; epilogue **`ADD ESP,0x14; RET`**.
3. **Semantics:** Product **gfxBufferedView** complete ctor (`…\graphics\gfxBufferedView.cpp` plates at vtbl):
   - `GfxView_Ctor_Inferred` (`FUN_0075ceb0`) base **0x150**.
   - Derived vtbl `PTR_FUN_00aa22a8`.
   - Timer subobject at **`+0x150`**: `FUN_0076c500(period=1000)` then `FUN_0076c4d0` (decompiler omits this-adjust; bytes `EDI=this+0x150`).
   - Defaults: `+0x180/+0x184 = 1`; floats `+0x188/+0x18c = 0`; bytes `+0x190/+0x191 = 0`; dword `+0x194 = 0`.
   - Always register `this` into global `std::list` (`*DAT_00d1ee30` head; `StdList_Incsize(1, list@0x00d1ee2c)`).
4. **Object size:** factories allocate **`0x198`** before call (not plain 0x150 GfxView).
5. **Classification:** worker (ctor).
6. **Callers (4):** `FUN_004c0a90` @ `0x004c0ae5` (`phase+0x9c`); `FUN_0055ca90` @ `0x0055cae5` (`+0x90`); `FUN_005b3420` @ `0x005b3466` (`+0x158`); `FUN_0078c780` @ `0x0078c80c` (`+0x2a4`). Pattern: `new(0x198); MOV ECX,eax; CALL`.
7. **Callees:** `FUN_0075ceb0`, `FUN_0076c500`, `FUN_0076c4d0`, `FUN_006759b0`, `FUN_0043fe60` (`StdList_Incsize`).
8. **Name:** `GfxBufferedView_Ctor_Inferred` (Ghidra `FUN_00968a50`; class **product-sealed**, method English structural). **Reject** scaffold `Named_CalleeOf_*_Drive_NDRiver_fx_00968a50`.
9. **Decompile ≡ raw CF**; bytes seal timer this-adjust + float zeros + Incsize regs.  
   Full hex: `6aff6823309b0064a100000000506489250000000083ec0853568bf15789742410e83a44dfff33db8dbe50010000895c241c68e80300008bcfc706a822aa00e86c3ae0ff8bcfc7473001000000c7473401000000e8273ae0ff0f57c0f30f118688010000f30f11868c010000889e90010000889e91010000899e94010000a130eed1008b388b57048d4c240c51525789742418e8c8ced0ffb901000000ba2ceed1008bd8e86773adff8b4c2414895f048b430489185f8bc65e5b64890d0000000083c414c3`

### Gaps

- Timer period / `+0x180/+0x184` product English.  
- Full derived field map past ctor zeros.  
- Global list domain English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00968a50_GfxBufferedView_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00968a50_GfxBufferedView_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ W37-I) | `docs/reconstruction/raw/aa_00968a50_FUN_00968a50.md` |
| Annotated | `docs/reconstruction/raw/aa_00968a50_FUN_00968a50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBufferedView_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00968a50.cpp` |
| Function | `docs/reconstruction/functions/aa_00968a50_FUN_00968a50.md` |
| Function named | `docs/reconstruction/functions/aa_00968a50_GfxBufferedView_Ctor_Inferred.md` |

---

## VA `0x0099c1c0` — sealed facts

1. **Body:** `0x0099c1c0`–`0x0099c29b` inclusive (**220 B** / `0xDC`); pad `CC`.
2. **ABI:** stack formal **`StreamReader* stream`**; cleanup **`RET 4`** (`C2 04 00`); returns **AL** bool; SEH `LAB_009b13f2`; epilogue **`ADD ESP,0xA8; RET 4`**.
3. **Semantics:** Temporary-host loader for product **`CNDAssetStringTable::Unserialize`**:
   - `stream == 0` → **AL=0** (no host).
   - Else: `FUN_00989cf0` (ResourceCache-family ctor) + host vtbl `PTR_FUN_00a983b4` + zero vector triple.
   - `FUN_00989ef0`: **EDI=cache**, **ECX=0x4000**, stack flag **1** (`ResourceCache_SetField10AndConfigure_Inferred`, W31-F).
   - `AL = FUN_0099bba0(host, scratch, stream)` (`CNDAssetStringTable_Unserialize`, W34-J plate).
   - If vec non-null: `FUN_00426ed0` + `operator_delete` (Ghidra false-noreturn; epilogue continues).
   - `FUN_00989c10` dtor; return AL.
4. **Classification:** worker (loader wrapper).
5. **Callers (1):** `FUN_004d73c0` @ `0x004d74d7` — only when `*(host+0x8c) ∈ (0x30,0x34)`; RAII `FUN_0099c140(0)` / `FUN_0099c130`.
6. **Callees:** `FUN_00989cf0`, `FUN_00989ef0`, `FUN_0099bba0`, `FUN_00426ed0`, `operator_delete`, `FUN_00989c10`.
7. **Name:** `CNDAssetStringTable_LoadFromStream_Inferred` (Ghidra `FUN_0099c1c0`; **Inferred** wrapper; Unserialize is product plate).
8. **Decompile ≡ raw CF**; bytes seal RET4 + configure constants + sole Unserialize call.  
   Full hex: `64a1000000006aff68f2139b00506489250000000081ec9c000000538b9c24b00000005633f63bde750732c0e992000000578d44242450e8f4dafeffc7442420b483a90089b424b00000008974241089742414897424186a01b9004000008d7c2428c68424b400000001e8c1dcfeff538d4c2410518d54242852e861f9ffff8b7c24103bfe8ad8741a8b44241c8b4c241450518bc7e876aca8ff57e8c2d5aeff83c40c8d542424c78424b0000000ffffffff52c7442424b483a900e890d9feff8ac35f8b8c24a40000005e5b64890d0000000081c4a8000000c20400`

### Gaps

- Full host `CNDAssetStringTable` field map (vector vs cache placement).  
- Configure `0x4000` / flag `1` product English.  
- Caller stage-window English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0099c1c0_CNDAssetStringTable_LoadFromStream_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0099c1c0_CNDAssetStringTable_LoadFromStream_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ W37-I) | `docs/reconstruction/raw/aa_0099c1c0_FUN_0099c1c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0099c1c0_FUN_0099c1c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDAssetStringTable_LoadFromStream_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0099c1c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0099c1c0_FUN_0099c1c0.md` |
| Function named | `docs/reconstruction/functions/aa_0099c1c0_CNDAssetStringTable_LoadFromStream_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00968a50` | Port as **gfxBufferedView complete ctor** on pre-alloc **0x198**: call GfxView base, install derived vtbl, init/start timer at **`+0x150`** (period **1000**), apply sealed defaults, **always** list-register, return this. Callers configure near/far/FX **after**. Do **not** treat as plain 0x150 GfxView or as Palantir-env 0x198 (`00492dd0`). |
| `0099c1c0` | Port as **temp-host Unserialize wrapper**: null stream → false; build host; configure cache **field10=0x4000 / flag=1** (EDI-this helper); call `CNDAssetStringTable_Unserialize`; destroy host; return AL. Do **not** inline pyramid/string parse. Do **not** trust Ghidra noreturn on delete. |
| Shared | Units are **unrelated** domains (graphics buffered view vs CND string table). No shared types. Both close prior dual gaps that named these as unresolved nested callees (W34-N fluid child; W34-J Unserialize caller). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + caller assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W37-I sections).  
- Product class for `00968a50` from vtbl-adjacent plates; wrapper name for `0099c1c0` from sole Unserialize call + CF.  
- Rejected scaffold NDRiver callee-of product role for `00968a50`.  
- Avoided bare `undefined4` in clean (`uint32_t` / structs).
