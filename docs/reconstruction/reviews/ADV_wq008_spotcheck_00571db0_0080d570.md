# Independent adversarial spot-check — WQ8R-G dual `0x00571db0` + `0x0080d570`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** WQ8R-G dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ8R-G OWN pair (WQ-008 residual / inventory-transfer priority 94) |
| **Units** | `0x00571db0` `InventoryGrid_RemoveItemAtXY`; `0x0080d570` `Client_RecvOpenAvailableGadgetResponse` |
| **Tools** | Ghidra MCP `batch_decompile`, `read_memory`, `get_bulk_xrefs`, `get_function_callers`, `get_xrefs_to`; dual report + A/B + clean/raw read-through |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00571db0-0080d570-wq8rg-report.md` |
| `docs/reconstruction/reviews/A_aa_00571db0_InventoryGrid_RemoveItemAtXY.md` |
| `docs/reconstruction/reviews/B_aa_00571db0_InventoryGrid_RemoveItemAtXY.md` |
| `docs/reconstruction/reviews/A_aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` |
| `docs/reconstruction/reviews/B_aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` |

### Artifacts (both units)

| Kind | `aa_00571db0` | `aa_0080d570` |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00571db0_FUN_00571db0.md` | `docs/reconstruction/raw/aa_0080d570_FUN_0080d570.md` |
| Annotated | `…/aa_00571db0_FUN_00571db0.annotated.md` | `…/aa_0080d570_FUN_0080d570.annotated.md` |
| Clean named | `…/InventoryGrid_RemoveItemAtXY.cpp` | `…/Client_RecvOpenAvailableGadgetResponse.cpp` |
| Clean twin | `…/FUN_00571db0.cpp` | `…/FUN_0080d570.cpp` |
| Function named | `…/aa_00571db0_InventoryGrid_RemoveItemAtXY.md` | `…/aa_0080d570_Client_RecvOpenAvailableGadgetResponse.md` |

### Live Ghidra spot-checks

| Check | Result |
|---|---|
| `batch_decompile(0x00571db0,0x0080d570)` | Live CF ≡ dual sealed algorithms (XY→COID→Find→Remove(1,0); S2C open-gadget dual-find + success/fail) |
| `read_memory` 96 B @ `0x00571db0` | Full **94 B** body through dual `C2 08 00`; pad `CC`; hex matches A dual plate |
| `read_memory` 256 B @ `0x0080d570` | Prologue `8B 86 98 0E 00 00 81 EC 04 01 00 00`; cargo/locker ECX setup; dual Find calls |
| `read_memory` epilogue @ `0x0080d900` | `81 C4 04 01 00 00 C2 04 00` — frame **0x104**, **RET 4** |
| `read_memory` `DAT_00a7d1f0` | `6f 66 00 00` → `"of\0"` |
| `get_bulk_xrefs(0x00571db0)` | **[]** — **0** static callers |
| `get_function_callers(0x00571db0)` | “No callers found” |
| `get_xrefs_to(0x0080d570)` | **1** UNCONDITIONAL_CALL from `Client_PacketDispatch` @ `0x00815d1e` |
| `get_function_callers(0x0080d570)` | `Client_PacketDispatch` @ `0x00815710` |
| `get_bulk_xrefs` Find/Remove | In-body calls sealed: Find @ `0x00571df2`/`0x0080d5bc`/`0x0080d5db`; Remove @ `0x00571dfa` (+ gadget body sites) |
| Callee rel32 (bytes) | `E8` @ `0x00571df2` → `0x00571010`; @ `0x00571dfa` → `0x00571b80` |
| Dispatch call rel32 | `E8 4D 78 FF FF` @ `0x00815d1e` → `0x0080d570` |

---

## Unit A — `0x00571db0` InventoryGrid_RemoveItemAtXY

### Body / ABI seal (independent)

Full body hex (**94 B**, exclusive of trailing `CC`):

```
83ec08568bf18b4e0c8b4608894c24080fb64c24103bc87d3d8bd00fb6442414
895424048b560c3bc27d2b0fafd18b4e2803d08b04d18b4cd1046a006a015150
8bcee819f2ffff508bcee881fdffff5e83c408c2080033c05e83c408c20800
```

| Claim | Independent result |
|---|---|
| Range half-open `0x00571db0`–`0x00571e0e` (**94 B**) + `CC` pad | **Confirmed** (`read_memory`) |
| `__thiscall` grid in ECX | **Confirmed** — `56 8B F1` (`PUSH ESI; MOV ESI,ECX`) |
| Stack args: byte `x`, byte `y`; **`RET 8`** | **Confirmed** — dual `C2 08 00`; `MOVZX` from `[esp+0x10]` / `[esp+0x14]` after local frame |
| Width `@+0x08`, height `@+0x0c` | **Confirmed** — `8B 46 08` / `8B 4E 0C` (and re-load height for imul) |
| Bounds: signed compare after movzx | **Confirmed** — `3B C8 7D …` / `3B C2 7D …` fail → `XOR EAX,EAX` |
| `index = height * x + y` | **Confirmed** — `0F AF D1` (`IMUL EDX,ECX`) then `03 D0` add y |
| Cells `@+0x28`, stride **8** | **Confirmed** — `8B 4E 28`; `8B 04 D1` / `8B 4C D1 04` |
| qty=**1**, forceFull=**0** | **Confirmed** — `6A 00 6A 01` **before** Find; survive Find’s `RET 8` for Remove’s stack |
| Find `0x00571010` then Remove `0x00571b80` | **Confirmed** — rel32 decode + bulk xrefs from `0x00571df2` / `0x00571dfa` |
| OOB → EAX=0, no callee | **Confirmed** — fail epilogue `33 C0 5E 83 C4 08 C2 08 00` |
| Static callers | **Confirmed 0** — bulk xrefs empty; callers API empty |
| Live decompile ≡ raw 2026-07-23 CF | **Confirmed** — bounds → `height*x+y` → Find → Remove(1,0) → else 0 |
| Clean named ≡ sealed CF | **Confirmed** — `InventoryGrid_RemoveItemAtXY.cpp` matches |

### Adversarial attacks (RemoveItemAtXY)

| # | Attack | Result |
|---|---|---|
| 1 | This is FindItemByCoid itself | **Fails** — cell load + Find + Remove wrapper |
| 2 | Row-major with width as stride | **Fails** — stride is **height** (`+0x0c`); first arg bound by width |
| 3 | Always fully removes footprint | **Fails** — `forceFull=0` → RemoveItem peel may leave cells (sealed sibling) |
| 4 | Directly clears cells to `-1` | **Fails** — no clear loop; Remove owns unstamp |
| 5 | `RET 0x0C` / three stack args | **Fails** — `RET 8` / two stack slots |
| 6 | cdecl free function | **Fails** — thiscall `MOV ESI,ECX` |
| 7 | Many static callers / hot manager | **Fails** — **0** CALL xrefs |
| 8 | Product/PDB name known | **Fails** — Inferred only |
| 9 | Bit-exact / runtime complete | **Fails** — dual correctly leaves open |
| 10 | Empty-cell path proven here | **Fails** — depends on Find→null→Remove gates (sibling duals) |

### Soft niggle (not sealed-claim failure)

- Clean header comment “OOB **or missing stamp** path returns null **without calling remove**” over-states: in-bounds empty COID still calls Find then Remove; only OOB skips both. Body CF in clean is still correct (always Find→Remove when in-bounds).

### Unit A dual quality

**PASS** — keep **`accept-with-gaps`**.

Sealed CF/ABI/index/callee/forceFull=0 and zero-caller honesty all re-verified. Gaps dual already flags (product name, callers, empty-cell, runtime) remain fair.

---

## Unit B — `0x0080d570` Client_RecvOpenAvailableGadgetResponse

### Body / ABI / wire seal (independent)

| Claim | Independent result |
|---|---|
| Frame `SUB ESP,0x104`; epilogue `ADD ESP,0x104; RET 4` | **Confirmed** — entry `81 EC 04 01 00 00`; epilogue @ `0x0080d90d` `81 C4 04 01 00 00 C2 04 00` |
| Body ~933 B (`0x0080d570`→`0x0080d915` half-open) | **Confirmed** — last insn ends `C2 04 00` @ `0x0080d913`–`0x0080d915` |
| ESI = client context | **Confirmed** — entry `8B 86 98 0E 00 00` (`[ESI+0xE98]`); dispatch site `56 8B F5` before call |
| Gates: char + cargo host `@char+0x250` | **Confirmed** — `TEST EAX`; `CMP DWORD [EAX+0x250],0` early exits |
| Packet COID `@+0x10/14` | **Confirmed** — `8B 45 10` / `8B 55 14` before Find |
| Kit id `@+0x18/1c` | **Confirmed** — loads before `ResolveObjectTarget` |
| Success `@+0x2c`, reason `@+0x28`, cat `@+0x2d` | **Confirmed** — decompile + `80 7D 2C 00` / switch on `[EBP+0x28]` |
| Dual-grid Find (cargo then locker) | **Confirmed** (bytes below) — decompiler collapses this to identical Find pair |
| Sole static caller = PacketDispatch @ `0x00815d1e` | **Confirmed** — xref + rel32 → `0x0080d570` |
| Wire opcode **`0x20A8`** OpenAvailableGadgetResponse | **Confirmed** — `Client_PacketDispatch.cpp` case `0x20a8` + comment |
| Fail reasons 1–4 + catastrophic path | **Confirmed** — decompile switch + product strings |
| Success open-slot++ via vtbl `+0x8c`/`+0x90` | **Confirmed** — decompile |
| Kit cast vtbl `+0x200` | **Confirmed** — `FF 92 00 02 00 00` |
| SFX `tinker_success` / `tinker_fail` | **Confirmed** — decompile string immediates |
| `DAT_00a7d1f0` = `"of"` | **Confirmed** — `read_memory` |
| Post path: kit Contains/Remove residual + `FUN_00933310` + refresh | **Confirmed** at CF level; kit-host MI expression residual (dual already flags) |
| Live decompile high-level CF ≡ raw | **Confirmed** |

### Dual-grid this-ptr (bytes win over decompiler)

Independent decode of entry path (`read_memory` @ `0x0080d5a0`):

```
; cargo Find
mov eax, [esi+0xe98]          ; character
mov ecx, [eax+0x250]          ; cargo host
mov eax, [ebp+0x10]           ; coid lo
mov ecx, [ecx+0x2b0]          ; grid* = *(host+0x2b0)   ; MOV not LEA
push edx / push eax
call 0x00571010               ; @ 0x0080d5bc

; if EDI==0 → locker Find
mov ecx, [esi+0xe98]
mov eax, [ebp+0x10]
mov ecx, [ecx+0xcbc]          ; grid* = *(char+0xcbc)
push / call 0x00571010        ; @ 0x0080d5db
```

Matches sealed DropResponse inventoryType **1** / **3** forms in `Client_RecvInventoryDropResponse.cpp` (pointer loads, not embedded LEA). Decompiler’s identical double-Find is a known false collapse — dual B correctly attacks it.

### Adversarial attacks (OpenAvailableGadgetResponse)

| # | Attack | Result |
|---|---|---|
| 1 | Two Find calls share same `this` | **Fails** — cargo `*(host+0x2b0)` then locker `*(char+0xcbc)` |
| 2 | Generic drop/add handler | **Fails** — tinker/gadget strings + 0x20A8 label |
| 3 | `unaff_ESI` is junk | **Fails** — dispatch custom ABI; `[ESI+0xE98]` character |
| 4 | Success destroys kit in success branch only | **Fails** — kit remove is shared post path; success mainly open-slot++ + toast/SFX |
| 5 | Fail reason 4 always destroys item | **Fails** — only when `pkt[+0x2d]` catastrophic |
| 6 | Many callers | **Fails** — sole PacketDispatch xref |
| 7 | Scaffold string-name is product symbol | **Fails** — dispatch label is authoritative |
| 8 | Full kit-host MI / sprintf packing sealed | **Fails** — dual residual stands |
| 9 | Bit-exact / runtime complete | **Fails** — open |

### Soft niggles (not sealed-claim failures)

1. **Clean grid this-ptr form:** `Client_RecvOpenAvailableGadgetResponse.cpp` writes LEA-style `cargoHost + 0x2b0` / `character + 0xcbc`. Image uses **MOV** loads `*(host+0x2b0)` / `*(char+0xcbc)` (same as DropResponse clean). Offsets and cargo→locker order remain correct; prefer DropResponse form for port.
2. **Annotated / dual prose `+` notation** sometimes omits the outer `*` (reads as embedded base). Intent matches DropResponse; bytes are authoritative.
3. **Catastrophic double-Contains / Remove this** still residual in decompiler (dual B residual #1) — do not over-seal when porting.
4. **Success sprintf** vararg packing incomplete in decompiler/clean — dual already residual.

### Unit B dual quality

**PASS** — keep **`accept-with-gaps`**.

Opcode, sole caller, dual-grid find (bytes), success/fail CF, fail enum, and residual kit-host/sprintf honesty all re-verified. Soft clean LEA-vs-MOV notation is documentation hygiene, not a dual sealed-claim error.

---

## Cross-unit / process seal

| Dimension | Assessment |
|---|---|
| Dual A (fidelity) + B (adversarial) per VA | Present; B tables attack high-risk false specializations |
| Bytes / call sites win over decompiler phantoms | Yes — dual-grid this; forceFull stack trick; ESI client |
| Report AutoCore port notes | Sound (height*x+y + forceFull=0; S2C 0x20A8 cargo→locker + fail 1–4) |
| Terminal coverage honesty | Sound (runtime/bit-exact open; no Launcher) |
| OWN-ONLY / no parent ledger (claimed) | Outside rewrite scope of this verifier; no ledger edits performed |
| No `disassemble_bytes` | Observed (this ADV used decompile + read_memory + xrefs only) |

### Confirmed report sealed facts (both)

All dual report “sealed facts” tables for both VAs re-verified against live decompile + `read_memory` + xrefs. **No factual sealed-claim errors** on CF/ABI/wire/callees/callers.

---

## Residual gaps (honest; dual already flags)

1. Product/PDB name for `00571db0` (Inferred).  
2. Zero static callers for `00571db0` — dead vs data-only vs unanalyzed call style.  
3. Empty-cell (`-1,-1`) path depends on Find/Remove siblings.  
4. Kit inventory host MI expression for final RemoveItem (`0080d570`).  
5. Success sprintf full vararg packing.  
6. Full packet size / unused fields for 0x20A8.  
7. Whether open-slot counter++ is client presentation only vs mirrored server state.  
8. Runtime / bit-exact / differential.  
9. Soft: clean `0080d570` LEA-style grid this vs image MOV (prefer DropResponse form).

---

## Dual quality verdict (not bare LGTM)

### `aa_00571db0` — **PASS** (`accept-with-gaps` stands)

Strengths:

- 94 B body fully re-read; thiscall, `RET 8`, `height*x+y`, cells `+0x28`/stride 8, Find→Remove(1,0) stack trick sealed.  
- B correctly falsifies full-remove, row-major width stride, many-callers, and bit-exact completeness.  
- Zero-caller honesty preserved.

Defects on sealed claims: **none**.

### `aa_0080d570` — **PASS** (`accept-with-gaps` stands)

Strengths:

- Opcode **0x20A8**, sole PacketDispatch caller, frame/`RET 4`, ESI client, dual-grid cargo→locker Find sealed against bytes.  
- B correctly elevates dual-grid over decompiler collapse and keeps kit-host/sprintf residual.  
- Fail enum 1–4 + catastrophic gating re-confirmed in live decompile.

Defects on sealed claims: **none** (soft clean LEA notation only).

---

## Summary

| VA | Dual quality | Verdict retention | Action |
|----|--------------|-------------------|--------|
| `0x00571db0` | **PASS** | keep **accept-with-gaps** | none required |
| `0x0080d570` | **PASS** | keep **accept-with-gaps** | optional clean hygiene: MOV grid this like DropResponse |

**ADV artifact written:**

- `docs/reconstruction/reviews/ADV_wq008_spotcheck_00571db0_0080d570.md` (this file)
