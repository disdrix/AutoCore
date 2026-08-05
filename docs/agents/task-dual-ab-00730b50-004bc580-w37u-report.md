# Dual A/B report — W37-U OWN `aa_00730b50` + `aa_004bc580`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-U  
**Scope:** VAs `0x00730b50`, `0x004bc580` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs/bulk xrefs + callee/sibling decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-U).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00730b50` PalToolHost_ChannelGeomUpload_Inferred | **accept-with-gaps** — 1492 B / RET8 / channel host offsets / VB 0x152 Lock 0x800 / gfxDeviceVB plate / sole dual-channel caller sealed; product host English + unowned helpers open |
| `aa_004bc580` List_RemoveAll | **accept** — 252 B / ECX host / CS drain / lock-throw 0x80070005 / product RemoveAll string / family with TraversalLock+IterateNext sealed; product class English residual only |

---

## VA `0x00730b50` — sealed facts

1. **Body:** `0x00730b50`–`0x00731123` (**1492 B** / `0x5D4`; pad `CC` ×12 then `FUN_00731130`).
2. **ABI:** stack **`host*`**, **`channelIndex`**; **`RET 8`** (`C2 08 00`); returns status in EAX (`0xFFFFFFFF` on VB create fail). **Not** ECX-thiscall.
3. **Semantics:** per-channel geometry upload for dual-channel PalTool host:
   - `eh_vector_constructor_iterator_` **3** streams of size **0x44** (ctor `FUN_00982040` / dtor `FUN_004579d0`); fill defaults from `g_flOne` + `DAT_00d1a6c0/c4/c8`, `DAT_00a10e78`, `DAT_00a0f718`, `DAT_00aaa8f4`, `DAT_00aaa7b8` + sentinels `0xff800000` / `0xff008000` / `0xff000080`; `FUN_00982100(3)` ×3.
   - Vert count `n = (end-begin)/0x24`; store `host[+4+ch*4]=(n/3)*3`, `host[+0xc+ch*4]=4`.
   - VB: `FUN_007478c0(0x152)` + `FUN_00414c20(n*3,…,8,0)`; Lock device vtbl **+0x2c** flag **0x800**; copy 3 streams; Unlock vtbl **+0x30** with plate `gfxDeviceVB.cpp` line **0xD3**.
   - Stride: via `*(host+0x34+ch*8)` material → child `+0x14` → flag `+0x10` → **0x10** else **0x20**.
   - IB/bind: `FUN_004451c0`, `FUN_00747390`, `FUN_00414c20`, `FUN_0044bbc0(..., host+0x24+ch*8, 0)`; cleanup.
4. **Host span:** requires slots through `+0x34+ch*8` (ch≤1 → ≥ `0x44`); matches W35-E / W36-J **0x44** host.
5. **Classification:** **worker** (per-channel post-material geom upload).
6. **Callers (1):** `FUN_00731130` @ `0x00731299` (ch=0), `0x007313ee` (ch=1) — W36-J `PalToolNoMap_Host0x44_DualChannelInit_Inferred`.
7. **Callees:** `eh_vector_*`, `FUN_00982100`, `FUN_007478c0`, `FUN_00414c20`, `FUN_00414b60`, `FUN_007467b0`, `vog_LogMessage`, `FUN_004451c0`, `FUN_00747390`, `FUN_0044bbc0`; Lock/Unlock virtuals.
8. **Name:** `PalToolHost_ChannelGeomUpload_Inferred` (Ghidra `FUN_00730b50`; **Inferred**). **Reject** scaffold `Named_gfxDeviceVB_00730b50` (string is unlock plate, not method identity).
9. **Family:** channel upload half of W36-J dual-channel init; sibling mesh upload W36-J `0x007300c0` (different host size 0x34).
10. **Decompile ≡ bytes** for RET8, channel offsets, 0x152/0x800/0x24/0x44×3, plate. Full hex omitted for size; range sealed by `get_function_by_address` + prologue/epilogue `read_memory`.

### Gaps

- Product/PDB English for 0x44 host class.  
- Exact 0x24 vertex packing / stream field map.  
- Unowned helper full contracts.  
- Clean structural (raw authoritative for full SEH).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00730b50_PalToolHost_ChannelGeomUpload_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00730b50_PalToolHost_ChannelGeomUpload_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00730b50_FUN_00730b50.md` |
| Annotated | `docs/reconstruction/raw/aa_00730b50_FUN_00730b50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalToolHost_ChannelGeomUpload_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00730b50.cpp` |
| Function | `docs/reconstruction/functions/aa_00730b50_FUN_00730b50.md` |
| Function named | `docs/reconstruction/functions/aa_00730b50_PalToolHost_ChannelGeomUpload_Inferred.md` |

---

## VA `0x004bc580` — sealed facts

1. **Body:** `0x004bc580`–`0x004bc67b` (**252 B** / `0xFC`; pad `CC`).
2. **ABI:** **ECX = list host** (`8B F1`); bare **`RET`** (`C3`); void. Decompiler `__fastcall` matches.
3. **Semantics:** CS-guarded list **RemoveAll**:
   - `EnterCriticalSection(host+4)`.
   - If `*(char*)(host+0x28) != 0` (TraversalLock held): Leave CS; throw **`0x80070005`** (`E_ACCESSDENIED`) via `_CxxThrowException` + `DAT_00acc430`.
   - Drain head `host+0x1c`: node vtbl@0 / field@+4 / next@+8; unlink; clear field; **scalar deleting dtor** `(*vtbl)(node, 1)`.
   - Zero `host+0x24`, `+0x20`, `+0x1c`; Leave CS.
   - SEH landing (not main CF): chkstk **0x1004** family stack + product string **`"List Error!  RemoveAll Call Stack:\n%s\n"`** @ `0x00a467ec` + `VOG_DEBUG_STOP`.
4. **Classification:** **worker** (list clear/destroy).
5. **Callers (9 sites / 6 functions):**
   - `FUN_004bbeb0` Host_ResetHashQueuesVectors ×3 (`*(this+0x1c/20/24)` as separate list hosts)
   - `CVOGReaction_RemoveObject` ×1
   - `FUN_00570f50` thin re-empty ×1
   - `FUN_00570f70` ×1
   - `FUN_00572360` InventoryGrid_RePlaceItems ×1
   - `FUN_00572730` InventoryGrid_SortAndRepack ×2
6. **Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `_CxxThrowException`, `__chkstk`; node vtbl[0].
7. **Name:** `List_RemoveAll` (Ghidra `FUN_004bc580`; role **High** from product string). **Reject** scaffold `Named_CalleeOf_CVOGReaction_RemoveObject_004bc580`. Family with registry `List_TraversalLock` (`0x004294f0`) and `List_IterateNext` (`0x004022a0`).
8. **Decompile ≡ bytes** for ECX/CS/drain/throw/zero/RET. Full 252 B hex in raw W37-U append.

### Gaps

- Product C++ class of list host / node payload.  
- Exact roles of `+0x20`/`+0x24` beyond cleared-with-head (drain walks only `+0x1c`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bc580_List_RemoveAll.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004bc580_List_RemoveAll.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bc580_FUN_004bc580.md` |
| Annotated | `docs/reconstruction/raw/aa_004bc580_FUN_004bc580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/List_RemoveAll.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bc580.cpp` |
| Function | `docs/reconstruction/functions/aa_004bc580_FUN_004bc580.md` |
| Function named | `docs/reconstruction/functions/aa_004bc580_List_RemoveAll.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00730b50` | Port as **stdcall** per-channel geom upload on **0x44** PalTool host: args `(host, ch)`; **`RET 8`**. Counts at **`+4+ch*4`** / flag **`+0xc+ch*4=4`**; material **`+0x34+ch*8`**; resource slot **`+0x24+ch*8`**. VB fmt **0x152**, Lock **0x800**, elem **0x24**, streams **0x44×3**. Pair with W36-J dual-channel init (calls ch=0 then ch=1) and W35-E slot5 `new(0x44)`. Do **not** model as thiscall or as a bare gfxDeviceVB API. Prefer raw decompile for full SEH. |
| `004bc580` | Port as **ECX** list **RemoveAll**: CS @ **`+4`**, head @ **`+0x1c`**, lock flag @ **`+0x28`**. If locked → **`0x80070005`** throw (same family as TraversalLock). Drain via scalar dtor `(vtbl[0])(node,1)`; zero **`+0x1c/+0x20/+0x24`**. Pair with `List_TraversalLock` / `List_IterateNext`. Inventory paths pass grid-embedded list (probable embed @ grid+0x2c). Do **not** treat as reaction-only helper. |

Shared: co-owned only by W37-U partition assignment; **different subsystems** (PalTool channel GPU upload vs CS-guarded client list). No shared types or call edge between the two VAs.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + sibling/callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural where needed; product string used for `List_RemoveAll`.  
- Rejected bare scaffold plates for both units.  
- Avoided claiming terminal coverage or parent dual-count updates.
