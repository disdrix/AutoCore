# Review A (reconstruction fidelity): `aa_00536920` CVOGCharacter_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536920` |
| **VA** | `0x00536920` |
| **Canonical name** | `CVOGCharacter_ctor` (product English open; Ghidra `FUN_00536920`) |
| **Inferred role** | MSVC most-derived constructor for the large character / mission-item object (~`0xF30` heap) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + structure seal) |
| **Counterpart** | `reviews/B_aa_00536920_CVOGCharacter_ctor.md` |
| **System** | missions-progression / character runtime / inventory factory type `0x14` |
| **Dual status** | **Present — sealed 2026-07-29** (structure + hash map shell; not every field English) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` constructor: `CVOGCharacter* Ctor(this, int mostDerivedFlag)`.

1. MSVC EH registration (`ExceptionList`, state machine `local_4`).
2. If `mostDerivedFlag != 0`: install dual-base cookies `param_1[1]=DAT_009d0004`, `param_1[0x11]=DAT_009cfffc`; call `FUN_00518940` (base init).
3. `FUN_004c9aa0(0)` — parent / creature-ish base ctor (also used by consumable type `0x12`).
4. Install primary / secondary / adjusted vtbls: `PTR_LAB_009cfd94`, `009cfd58`, dual-base slot `*(this+vbtable)+4 → 009cfa94`, complete-object adjust `-0xd9c`.
5. Zero / default large character field run (flags, TFID-ish `-1` slots, quats from `DAT_009cee98` family, `g_flOne` scales, `GetTickCount` stamp).
6. Construct empty **maps/trees**:
   - Mission staging RB map head via `FUN_00538270` → `param_1[0x143]` (**char+0x50c**), isnil `+0x49`, size `param_1[0x144]=0` (**+0x510**); map shell **char+0x508** (sealed by staging duals).
   - Additional tree heads `FUN_005ae2b0`, `FUN_00439770`, list `FUN_0040fb90`.
7. Heap-construct **nine CNDHash** objects (`operator_new(0x34)` + inline field init + AllocBuckets twin) and store pointers on character (see table).
8. `FUN_0052d8b0(0, -1)` — clear mission staging tree (map-only, all keys).
9. Fill TFID pair arrays / quick slots with `0xFFFFFFFF` / zeros; copy globals `DAT_00b045f0..fc`.
10. `FUN_00520c20` / `FUN_00520ce0` post-inits; one-shot `FUN_00536150` if `DAT_00b04598==0`.
11. Return `this`.

### Factory / call sites (live xrefs)

| Site | Pattern |
|---|---|
| `CVOGReaction_GiveItemByCbid` type **`0x14`** | `operator_new(0xF30)`; `push 1; mov ecx,mem; call` — plate “Mission item” |
| `FUN_00854d20` / `FUN_00855810` | Same `new` + `push 1` ctor |
| `FUN_008fa9f0` | **In-place** `lea ecx,[esi+0x510]; push 1; call` — embedded subobject |

All observed sites pass **mostDerivedFlag = 1**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00536920_FUN_00536920.md` |
| Annotated | `docs/reconstruction/raw/aa_00536920_FUN_00536920.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00536920.cpp` |
| Function record | `docs/reconstruction/functions/aa_00536920_FUN_00536920.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00536920` (2026-07-29) ≡ raw 2026-07-23 |
| Entry image | `read_memory` @ `0x00536920` — EH prolog, `cmp [esp+…],ebx` mostDerived gate |
| Xrefs | `get_function_xrefs` / `get_function_callers` |
| Call-site asm | `get_assembly_context` on 4 call sites |
| Related duals | staging clear `0052d8b0`, AllocBuckets twins, Recreate `00539d70/dd0/e30`, GiveItemByCbid |

**Not performed:** `disassemble_bytes`, Launcher, full line-by-line field English dictionary, binary diff.

---

## 3. Sealed CNDHash pointer slots (from ctor)

| Dword idx | Char offset | Object vtbl | log2 bits | Init size | AllocBuckets | Later Recreate |
|---:|---:|---|---:|---:|---|---|
| `0x14c` | **`+0x530`** | `009cfa7c` | 4 | `0x10` | `00537b50` | `00539dd0` |
| `0x14d` | **`+0x534`** | `009cfa64` | 8 | `0x100` | `00537a10` | `00539d70` |
| `0x14e` | **`+0x538`** | `009cfa4c` | 8 | `0x100` | `005378d0` | (vtbl path) |
| `0x14f` | **`+0x53c`** | `009cfa4c` | 8 | `0x100` | `005378d0` | (vtbl path) |
| `0x150` | **`+0x540`** | `009cfa4c` | 4 | `0x10` | `005378d0` | (vtbl path) |
| `0x151` | **`+0x544`** | `009cfa4c` | 4 | `0x10` | `005378d0` | (vtbl path) |
| `0x152` | **`+0x548`** | `009cfa58` | 4 | `0x10` | `00537970` | (vtbl path) |
| `0x157` | **`+0x55c`** | `009cfa88` | 2 | `4` | `00537bf0` | `00539e30` |
| `0x1bc` | **`+0x6f0`** | `009cfa70` | 4 | `0x10` | `00537ab0` | (none found) |

System-map English (where claimed): completed `+0x538`, instance-completed `+0x53c`, active `+0x540`, pending objectives `+0x55c`. Remaining slots product-English **Open**.

Mission staging map shell: **`+0x508`** (head `+0x50c`, size `+0x510`) — cross-sealed by `aa_0052c700` / `aa_0052d8b0` / `aa_00539cb0`.

---

## 4. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| Ctor returns `this` | Final `return param_1` | **High** |
| mostDerivedFlag stack arg | Call sites `push 1`; body `if (param_2!=0)` | **High** |
| Heap size **`0xF30`** for type `0x14` | GiveItemByCbid `operator_new(0xF30)` | **High** |
| Dual-base adjust **`-0xd9c`** | Store `vbptr_off + this` complete-object | **High** |
| Nine hash inits + AllocBuckets twins | Body block `operator_new(0x34)` ×9 | **High** |
| Staging clear at end of hash block | `FUN_0052d8b0(0,-1)` dual | **High** |
| Layout offsets match mission system map | Table vs `missions-progression.md` | **High** (mapped slots) |
| Every zeroed field product name | Large residual | **Open** |
| Class product string / RTTI | Not recovered this pass | **Open** |
| Runtime construct capture | Not run | **Open** |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| EH / mostDerived / base / vtbl install | **Yes** |
| Map heads + hash factories + staging clear | **Yes** |
| TFID loops / post-init / one-shot | **Yes** |
| Return this | **Yes** |
| No invent of GiveMission / packet apply | **Yes** |

---

## 6. Gaps

1. Full field dictionary (~hundreds of stores) — not dual-named.
2. Exact product class name (CVOGCharacter vs mission-item subclass) — behavioral layout matches Character mission hashes; factory type `0x14` also uses this ctor.
3. Semantics of hashes `+0x530`, `+0x534`, `+0x544`, `+0x548`, `+0x6f0` beyond pointer install.
4. `FUN_00518940` / `FUN_004c9aa0` / `FUN_00520c20` / `FUN_00520ce0` / `FUN_00536150` not re-dualed here.
5. Bit-exact / runtime.

**Verdict:** **accept-with-gaps** — ctor role, ABI, heap size, dual-base, staging map shell, and CNDHash pointer/bits/AllocBuckets map sealed High.
