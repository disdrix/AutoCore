# Independent adversarial spot-check — WQ8R-C dual `0x00570af0` + `0x005715d0`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** WQ8R-C dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ8R-C OWN pair (WQ-008 residual — grid inventory helpers) |
| **Units** | `0x00570af0` `InventoryGrid_MoveItemFootprint_Inferred`; `0x005715d0` `InventoryGrid_CanPlaceItem` |
| **Tools** | Ghidra MCP `batch_decompile`, `read_memory`, `get_function_callers`, `get_xrefs_to`; dual/report + clean artifact read-through |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00570af0-005715d0-wq8rc-report.md` |
| `docs/reconstruction/reviews/A_aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_005715d0_InventoryGrid_CanPlaceItem.md` |
| `docs/reconstruction/reviews/B_aa_005715d0_InventoryGrid_CanPlaceItem.md` |
| `docs/reconstruction/reviews/a_00570af0.md` |
| `docs/reconstruction/reviews/a_005715d0.md` |

### Artifacts (both units)

| Kind | `aa_00570af0` | `aa_005715d0` |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00570af0_FUN_00570af0.md` | `docs/reconstruction/raw/aa_005715d0_FUN_005715d0.md` |
| Annotated | `…/aa_00570af0_FUN_00570af0.annotated.md` | `…/aa_005715d0_FUN_005715d0.annotated.md` |
| Clean named | `…/InventoryGrid_MoveItemFootprint_Inferred.cpp` | `…/InventoryGrid_CanPlaceItem.cpp` |
| Clean twin | `…/FUN_00570af0.cpp` | `…/FUN_005715d0.cpp` |
| Function named | `…/aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` | `…/aa_005715d0_InventoryGrid_CanPlaceItem.md` |

### Live Ghidra spot-checks

| Check | Result |
|---|---|
| `batch_decompile(0x00570af0,0x005715d0)` | Live CF matches dual seals; stamp on Move still shows decompiler `unaff_retaddr` / `(byte)param_2` corruption (bytes override required) |
| `read_memory` prologue `0x00570af0` (64 B) | `83 EC 14 55 56 8B 74 24 20 85 F6 8B E9 … LEA [esp+local]; PUSH; … CALL → 0x00570840` |
| `read_memory` stamp core `0x00570c50`–`0x00570cef` | Index `IMUL` height×baseX + dy + originY; COID stores `item+0x160/+0x164` at `cells[idx*8]` |
| `read_memory` epilogue `0x00570cf0` | `… B0 01 5D 83 C4 14 C2 0C 00 CC…` — success AL=1, `RET 0x0C` |
| `read_memory` full body `0x005715d0` (80 B) | Prologue `PUSH ECX`; null path `XOR AL,AL; POP ECX; RET 0x10`; InvSize loads; `CALL 0x00570840`; `POP ECX; RET 0x10` |
| `get_function_callers` / `get_xrefs_to` `@0x00570af0` | **None** — orphan / indirect residual confirmed |
| `get_function_callers` `@0x005715d0` | `FUN_008012f0`, `FUN_00941b20`, `FUN_00952bc0`, `FUN_00955010` |
| `get_xrefs_to` `@0x005715d0` | **18** `UNCONDITIONAL_CALL` sites across those four parents |

---

## Unit A — `0x00570af0` InventoryGrid_MoveItemFootprint_Inferred

### Body / ABI seal (independent)

| Claim | Independent result |
|---|---|
| Range `0x00570af0`–`0x00570cfb` (~523–524 B) + `CC` pad | **Confirmed** (`C2 0C 00` ends body; pad `CC`) |
| **thiscall** grid in `ECX` (`MOV EBP, ECX`) | **Confirmed** (`8B E9` after item load) |
| Stack: `item*`, `originX`, `originY` — **3** dwords / `RET 0x0C` | **Confirmed** (`C2 0C 00`; prologue `MOV ESI,[ESP+0x20]` item) |
| Null item → 0 | **Confirmed** (`TEST ESI` / early return path) |
| InvSize from `item+0xa8` → `+0x3c` → u8 `+0x406/+0x407` | **Confirmed** (loads before CanPlace) |
| CanPlace `0x00570840` with **local** conflictOut | **Confirmed** (`LEA ECX,[ESP+local]; PUSH`; `E8` rel → `0x00570840`) |
| Clear old footprint at vtbl `+0x250/+0x254` GetX/GetY to `0xFFFFFFFF` pairs | **Confirmed** (decompile + clear loop index `height*x+y`, `*8` stores) |
| `vtbl+0x24c(originX, originY)` set origin | **Confirmed** (`FF 90 4C 02 00 00` after clear) |
| Stamp full InvSize rect with COID `item+0x160/+0x164` | **Confirmed** (byte stamp core; see formula table) |
| Index family `height * x + y` / `height*(ox+dx)+(oy+dy)` | **Confirmed** (`8B 55 0C` / `0F AF 54 24 18` / `03 D0` / `03 54 24 1C`) |
| Optional `FUN_00512670(*(grid+0x24))` when non-null | **Confirmed** (`MOV ECX,[EBP+0x24]; TEST; CALL 0x00512670`) |
| Dirty `*(grid+0x21)=1`; return 1 | **Confirmed** (`C6 45 21 01` / `B0 01`) |
| Ghidra callers / xrefs | **Confirmed empty** |

### Stamp formula (byte-sealed, independent)

Live stamp inner (from `read_memory` @ `0x00570c50+` / `0x00570ca0+`):

```text
// setup per dx:
//   [esp+0x18] = originX + dx
//   [esp+0x1c] = originY
// inner dy:
//   EDX = *(grid+0x0c)              ; height
//   IMUL EDX, [esp+0x18]            ; * (originX+dx)
//   ADD EDX, EAX                    ; + dy
//   ADD EDX, [esp+0x1c]             ; + originY
//   EBX = [item+0x160]; [cells+EDX*8] = EBX
//   EBX = [item+0x164]; [cells+EDX*8+4] = EBX
```

| Opcode evidence | Role | Dual A/B |
|---|---|---|
| `8B 55 0C` | height from `grid+0x0c` | **OK** |
| `0F AF 54 24 18` | × `(originX+dx)` | **OK** |
| `03 D0` / `03 54 24 1C` | + dy + originY | **OK** |
| `8B 9E 60 01 00 00` / `…64 01 00 00` | COID lo/hi | **OK** |
| `89 1C D7` / `89 5C D7 04` | 8-byte cell stores | **OK** |

**Decompiler stamp is not retail:** live decompile still emits `unaff_retaddr` / `(byte)param_2` in the stamp index. Dual correctly rejects that and documents bytes-override. Clean named reconstruction uses `height * (originX + dx) + (originY + dy)` — **matches bytes**.

### Adversarial attacks (Move)

| # | Attack | Result |
|---|---|---|
| 1 | Function is first-time Place (type reject / qty / list bind) | **Fails** — clear current origin, re-stamp only; no Place-class gates |
| 2 | Decompiler stamp formula is portable | **Fails** — `unaff_*` vs sealed `ox+dx` / `oy+dy` |
| 3 | CanPlace uses null conflictOut (overlap move impossible) | **Fails** — local LEA buffer pushed (same-COID tolerance path) |
| 4 | `RET 0x10` / four stack args | **Fails** — `C2 0C 00` |
| 5 | Cells are 4-byte entries | **Fails** — stores at `*8` and `+4` |
| 6 | Index is row-major `y*width+x` | **Fails** — `height*x+y` family |
| 7 | Has sealed direct callers | **Fails** — zero Ghidra xrefs (gap correctly owned) |
| 8 | Ready for bit-exact complete | **Fails** — runtime/diff open (dual gap) |
| 9 | Product PDB name final | **Fails** — `_Inferred` hygiene sound |
| 10 | Clean ports decompiler stamp as-is | **Fails** — clean uses byte formula |

### Soft niggles (not sealed-claim failures)

1. **Body length wording:** dual says `0x00570af0`–`0x00570cfb` (~523 B). Inclusive byte count through final `00` of `C2 0C 00` is **524** (`0x20C`). Boundary VAs are correct; length is off-by-one depending on inclusive/exclusive convention — cosmetic.
2. **`FUN_00512670` owner type** when `grid+0x24` is the this-arg remains unlabeled (dual open gap).
3. **No runtime multi-cell move dump** — residual only; does not break CF/index seal.

### Unit A dual quality

**PASS** — keep **`accept-with-gaps`**.

Sealed CF (CanPlace gate → clear → SetPos → stamp → optional owner helper → dirty → 1), ABI (thiscall + 3 stack / `RET 0x0C`), and index family are independently confirmed. Gaps dual already flags (no callers, product English, runtime, bit-exact) remain fair residuals. Do **not** port decompiler stamp.

---

## Unit B — `0x005715d0` InventoryGrid_CanPlaceItem

### Body / ABI seal (independent)

Full body hex (77 B exclusive of trailing `CC`; ends `C2 10 00` @ `0x0057161a`–`0x0057161c`):

```text
51 8B 44 24 08 85 C0 75 06 32 C0 59 C2 10 00
8B 80 A8 00 00 00 8B 40 3C
8A 90 07 04 00 00 8A 80 06 04 00 00
… push conflictOut, originY, originX, sizeY, sizeX …
E8 26 F2 FF FF          ; → 0x00570840 InventoryGrid_CanPlace
59 C2 10 00
```

| Claim | Independent result |
|---|---|
| Range `0x005715d0`–`0x0057161d` (~78 B leaf) | **Confirmed** (body through `RET 0x10` + `CC` pad) |
| **thiscall** grid in `ECX` | **Confirmed** (`PUSH ECX` save; restored for CanPlace this) |
| Stack: `item*`, `originX`, `originY`, `conflictOut*` — **4** dwords / `RET 0x10` | **Confirmed** (`C2 10 00`) |
| Null item → 0 without CanPlace | **Confirmed** |
| InvSize u8 `blob+0x406/+0x407` via `item+0xa8`→`+0x3c` | **Confirmed** |
| Sole callee `InventoryGrid_CanPlace` `0x00570840` | **Confirmed** (`E8` rel from `0x0057161a` → `0x00570840`) |
| No cell stamp/clear/bind | **Confirmed** (no stores to `grid+0x28` cells) |
| Callers multi-site equip/probe | **Confirmed** (18 xrefs; four parent functions as dual sample) |

### Decompiler note (independent)

Live `batch_decompile` presents `FUN_005715d0` as **non-thiscall** with `param_1 = item` and omits explicit grid this on the CanPlace call. **Bytes** (`PUSH ECX` / restore into CanPlace this) seal thiscall. Dual A/B correctly override display with ABI truth.

### Adversarial attacks (CanPlaceItem)

| # | Attack | Result |
|---|---|---|
| 1 | Function places / stamps the item | **Fails** — only CanPlace; no cell stores |
| 2 | First stack arg is the grid | **Fails** — item (null-checked; `+0xa8`); grid is ECX |
| 3 | cdecl / no this | **Fails** — `PUSH ECX` + CanPlace thiscall |
| 4 | Sizes are stack args | **Fails** — loaded from clonebase `+0x406/+0x407` |
| 5 | Same as FindFreeForItem | **Fails** — no first-fit / outs |
| 6 | Same as MoveItemFootprint | **Fails** — no clear/stamp |
| 7 | `RET 0x0C` three args | **Fails** — `C2 10 00` |
| 8 | No callers | **Fails** — 18 UNCONDITIONAL_CALL xrefs |
| 9 | PDB name sealed product English | **Fail** — probable English only (non-blocking) |
| 10 | Bit-exact complete | **Fail** — open policy; leaf does not need it for accept |

### Caller graph (independent sample)

| Parent | Sites (xrefs) | Dual sample |
|---|---|---|
| `FUN_008012f0` | 2 (`0x0080139c`, `0x00801532`) | **OK** |
| `FUN_00941b20` (`Client_ConfirmEquipOrCustomizeItem`) | 1 (`0x00941c56`) | **OK** |
| `FUN_00952bc0` | 3 | **OK** |
| `FUN_00955010` | 12 | **OK** |
| **Total** | **18** | Dual said “sample / 18 xrefs” — **matches** |

### Soft niggle

- Dual product name `InventoryGrid_CanPlaceItem` without `_Inferred` is **probable** from role + callers, not PDB-sealed. Accept still correct for leaf CF/ABI; naming residual is docs-only.

### Unit B dual quality

**PASS** — keep **`accept`**.

Leaf InvSize→CanPlace wrapper, ABI (thiscall + 4 stack / `RET 0x10`), and multi-site caller role are independently confirmed. No adversarial hole in the sealed contract.

---

## Cross-unit consistency

| Topic | Independent |
|---|---|
| Shared InvSize path `item+0xa8` → `+0x3c` → `+0x406/+0x407` | **Both** — same clonebase footprint source |
| Shared CanPlace `0x00570840` | **Both** — Move with local conflictOut; CanPlaceItem pass-through (often null from callers) |
| Shared index family with Place/Remove/CanPlace | **Move stamp/clear sealed**; CanPlaceItem inherits via callee |
| Role split | Move **mutates** footprint; CanPlaceItem **probe only** — dual distinction holds |
| Clean vs decompiler | Move clean correctly overrides stamp corruption; CanPlaceItem clean matches CF |

---

## Confirmations

1. WQ8R-C dual A/B + report seals for both VAs are **faithful** to live decompile + `read_memory`.
2. Move: clear-before-SetPos-before-stamp order, local conflictOut, `height*x+y` index, `RET 0x0C` — **confirmed**.
3. CanPlaceItem: pure wrapper, `RET 0x10`, 18 call sites — **confirmed**.
4. Decompiler hazards dual documents (Move stamp `unaff_*`; CanPlaceItem non-thiscall display) are **real and correctly rejected**.
5. Clean named sources match byte-sealed semantics (Move does not port `unaff_*`).

---

## Gaps (remain open — dual already owns)

| Gap | Unit | Blocks accept? |
|---|---|---|
| No Ghidra direct callers (orphan / indirect) | Move | No (`accept-with-gaps`) |
| Product/PDB English | Both | No |
| Runtime multi-cell overlapping-move dump | Move | No |
| Runtime non-null conflictOut via CanPlaceItem wrapper | CanPlaceItem | No |
| `FUN_00512670` exact owner type label | Move | No |
| Bit-exact / differential | Both | No (policy) |

---

## Pass / fail

| Unit | Dual verdict | ADV result |
|---|---|---|
| `0x00570af0` InventoryGrid_MoveItemFootprint_Inferred | **accept-with-gaps** | **PASS** — retain **accept-with-gaps** |
| `0x005715d0` InventoryGrid_CanPlaceItem | **accept** | **PASS** — retain **accept** |

### Overall

**PASS** — WQ8R-C dual seals hold under independent Ghidra `batch_decompile` + `read_memory` + caller/xref verification. No sealed-claim failure requiring dual rewrite or verdict downgrade.

---

## Process notes

- Independent ADV verifier; **not** WQ8R-C author.
- Tools: `batch_decompile`, `read_memory`, `get_function_callers`, `get_xrefs_to` only for RE; **no** `disassemble_bytes`.
- **No** parent ledger / WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG edits.
- Output: `docs/reconstruction/reviews/ADV_wq008_spotcheck_00570af0_005715d0.md` (this file).
