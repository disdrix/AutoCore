# Review A (reconstruction fidelity): `aa_00513770` Item_IsWantedByStore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513770` |
| **VA** | `0x00513770` |
| **Canonical name** | `Item_IsWantedByStore_Inferred` |
| **Prior names** | `FUN_00513770`, `Named_CalleeOf_Client_UI_InventoryDropToGrid_00513770` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — drop/item store-want helper) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00513770_Item_IsWantedByStore_Inferred.md` |
| **Residual scratch** | `reviews/a_00513770.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Predicate leaf:** does the store/vendor path accept this **item instance**?

```text
// thiscall Item* this (ECX)
clonebase = *(this + 0xA8)
if (*(clonebase + 0x3C) == 0)
    FUN_004f1e20(clonebase, /*loadName*/0, /*force*/1)   // ensure def loaded
def = *(clonebase + 0x3C)
if (def == 0) return 1            // permissive when still unloaded
return (*(int32*)(def + 0x3B4) == 1)   // bool AL
```

No mutation of item qty/grid. Sole side effect is optional **ensure-load** of the clonebase def via `FUN_004f1e20` when `*(clonebase+0x3C)` is null.

**Calling convention:** MSVC `__thiscall` — item in `ECX`; **no stack args**; plain `RET` (no `RET n`).

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX) | inventory / held `Item*` | all 7 call sites `MOV ECX, <item>` then `CALL` |
| AL | `bool` store-wants | `SETZ AL` / early `MOV AL,1` |

**Return polarity (sealed by toast):**

| AL | Caller meaning |
|----|----------------|
| **0** | reject — UI string **"The store does not want that item."** (`0x00A52924`) |
| **1** | proceed (sell packet / credit path / further trade checks) |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00513770_FUN_00513770.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_00513770_FUN_00513770.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_IsWantedByStore_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00513770_Item_IsWantedByStore_Inferred.md` |
| Live decompile | Ghidra `decompile_function` `0x00513770` (2026-07-29) ≡ raw body |
| Live bytes | `read_memory` `0x00513770` length 52 — ends `setz al; ret` |
| Callers / xrefs | `get_function_callers` + `get_function_xrefs` (7 call sites / 3 named parents) |
| Call-site ECX | `get_assembly_context` on all 7 sites |
| Toast string | `read_memory` `0x00A52924` → ASCII `"The store does not want that item."` |
| Sibling price | live decompile `FUN_005142a0` @ `0x005142a0` (same gate + value) |
| Clonebase layout | dual A/B `aa_0040abf0` Item_CanAcceptStackQty (`+0xA8` / `+0x38` / `+0x3C`) |
| Drop parent | dual A/B `aa_00860a50` Client_UI_InventoryDropToGrid (type-4 store path) |

**Not performed:** `disassemble_bytes`, Launcher, live process memory, bit-exact image diff, Ghidra rename.

---

## 3. Control flow: clean ≡ raw ≡ live bytes

| Stage | Match |
|---|---|
| `ESI = ECX` (this preserve) | **Yes** — `push esi; mov esi, ecx` |
| `ECX = *(this+0xA8)` clonebase | **Yes** — `mov ecx, [esi+0xa8]` |
| Null-def test `*(clonebase+0x3C)==0` | **Yes** — `cmp dword [ecx+0x3c],0` / `jnz` |
| Ensure-load `FUN_004f1e20(clonebase, 0, 1)` | **Yes** — `push 1; push 0; call` with ECX still clonebase |
| Reload `def = *(*(this+0xA8)+0x3C)` | **Yes** — `mov eax,[esi+0xa8]; mov eax,[eax+0x3c]` |
| Null def → `AL=1` return | **Yes** — `test eax,eax` / `jz` → `mov al,1; ret` |
| Else `AL = (*(def+0x3B4)==1)` | **Yes** — `cmp dword [eax+0x3b4],1` / `setz al; ret` |
| No stack args / plain `RET` | **Yes** |
| Decompiler `CONCAT31` is bool-width noise | **Yes** — only AL written |

### 3.1 Live body (hex → CF) — **SEALED**

```
00513770  56                 push  esi
00513771  8B F1              mov   esi, ecx              ; this Item*
00513773  8B 8E A8 00 00 00  mov   ecx, [esi+0xA8]       ; clonebase*
00513779  83 79 3C 00        cmp   dword [ecx+0x3C], 0
0051377d  75 09              jnz   short after_ensure
0051377f  6A 01              push  1                     ; param_3
00513781  6A 00              push  0                     ; param_2
00513783  E8 98 E6 FD FF     call  FUN_004f1e20          ; thiscall ECX=clonebase
00513788  8B 86 A8 00 00 00  mov   eax, [esi+0xA8]
0051378e  8B 40 3C           mov   eax, [eax+0x3C]       ; def*
00513791  85 C0              test  eax, eax
00513793  5E                 pop   esi
00513794  75 03              jnz   short cmp_flag
00513796  B0 01              mov   al, 1                 ; null def → true
00513798  C3                 ret
00513799  83 B8 B4 03 00 00 01  cmp dword [eax+0x3B4], 1
005137a0  0F 94 C0           setz  al
005137a3  C3                 ret
```

`read_memory` hex:  
`56 8b f1 8b 8e a8 00 00 00 83 79 3c 00 75 09 6a 01 6a 00 e8 98 e6 fd ff 8b 86 a8 00 00 00 8b 40 3c 85 c0 5e 75 03 b0 01 c3 83 b8 b4 03 00 00 01 0f 94 c0 c3`

### 3.2 Decompiler noise — **SEALED as artifact**

| Display | Reality |
|---------|---------|
| `__fastcall FUN_00513770(int param_1)` | **`__thiscall`** — ECX this; `param_1` is ESI/this |
| `FUN_004f1e20(0,1)` free call | **thiscall** — ECX = clonebase; stack `(0,1)` = `(param_2, param_3)` |
| `CONCAT31(..., flag==1)` return | **bool AL only** (`setz` / `mov al,1`) |
| `analyze_function_complete` signature `void` | **Ignore** — RET leaves AL; decompiler also shows `undefined4` |

---

## 4. Offsets (body-backed only)

| Path | Width | Role | Cross-seal |
|------|-------|------|------------|
| `item+0xA8` | ptr | clonebase host | **High** — same as `Item_CanAcceptStackQty` |
| `clonebase+0x3C` | ptr | definition blob* (nullable) | **High** — stack max path loads def from here |
| `def+0x3B4` | i32 | store-want flag; **must equal 1** | **High** CF; English product name **Open** |
| (related, not this unit) `clonebase+0x38` | i32 | item class type | Drop parent type-4 store path |
| (related) `def+0x4BE` | u8 | customized / non-tradable | Drop parent trade gate (sibling field) |

---

## 5. Callers (complete xref seal — 7 sites)

| Site | Parent (when named) | ECX | Polarity use |
|------|---------------------|-----|--------------|
| `0x00860C6E` | `Client_UI_InventoryDropToGrid` | held item via vtbl `+0x3AC` | type-4 store: `AL==0` → toast `0x00A52924` |
| `0x008613C1` | (UI sell sibling) | item in ESI | same: `AL==0` → toast path `0x00A52924` |
| `0x008903A8` | (UI sell sibling) | item | same reject toast pattern |
| `0x008B8F56` | (trade UI) | `*(client+0xCD0)` item | `AL==0` → skip; then `def+0x4BE` customized |
| `0x0090960C` | (trade UI twin) | `*(client+0xCD0)` item | same pattern as `0x008B8F56` |
| `0x00587984` | `FUN_00587970` | item (ESI) | `AL!=0` then price `FUN_005142a0` + `AddCredits` |
| `0x00942602` | `FUN_00942530` | list item (ESI) | `AL!=0` then build C2S **`0x2027`** size `0x40` sell packet |

**Sibling:** `FUN_005142a0` @ `0x005142a0` — same ensure + **inverse** gate (`def && *(def+0x3B4)!=1` → return **0** price), then sell-value math. Confirms `+0x3B4==1` is the vendor-buy eligibility bit, not a random constant.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + bool return | **High** | live bytes |
| ECX = `Item*`; `+0xA8` clonebase | **High** | layout family + all sites |
| Ensure-load only when def null | **High** | branch |
| Null def after ensure → true | **High** | `mov al,1` |
| `*(def+0x3B4)==1` required when def present | **High** | `setz` |
| Toast polarity (0 = store rejects) | **High** | string + DropToGrid |
| Product English name of field `+0x3B4` | **Tentative** | inferred “store wants” |
| `FUN_004f1e20` full product name | **Open** | role: ensure def / name path |
| Runtime / bit-exact | **Open** | deferred |

---

## 7. Gaps / open

1. Product / PDB name for this VA and for def field `+0x3B4`.
2. Full dual of `FUN_004f1e20` (ensure-load) and `FUN_005142a0` (sell value) — out of OWN scope.
3. Exact class English for clonebase host at `item+0xA8` (layout offsets sealed).
4. Runtime: sell item with `+0x3B4≠1` must hit toast; null-def edge rare.

**Verdict:** **accept-with-gaps.** Predicate CF + offsets + toast polarity sealed for AutoCore store-drop gates; name carries `_Inferred`.
