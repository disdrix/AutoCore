# Review A (reconstruction fidelity): `aa_00611690` CVOGObjectiveRequirement_Collect_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611690` |
| **VA** | `0x00611690` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_ctor` |
| **Prior scaffold** | `FUN_00611690` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md` |
| **System** | `missions-progression` (inventory-transfer Collect bridge consumers) |
| **Verdict** | **accept-with-gaps** — **RequirementType = 2 sealed**; pure ctor / no runtime eval |

---

## 1. Purpose

MSVC **`__thiscall` constructor** for RTTI class `CVOGObjectiveRequirement_Collect`:

1. Call shared objective-requirement base ctor `FUN_00637da0(parent)`.
2. Install Collect vtable `PTR_FUN_009e12c4` (`0x009e12c4`).
3. Write **RequirementType dword = 2** at `this+0x0c`.
4. Zero / `-1`-sentinel remaining Collect fields (CBID, NumToCollect, drop %, pads).
5. Return `this` in **EAX**.

No virtual dispatch, no inventory count, no packet I/O. XML field fill is a later method (`0x00611a00`); live progress is Eval/SlotAction/Action.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00611690_FUN_00611690.md` (+ 2026-07-29 residual) |
| Annotated | `docs/reconstruction/raw/aa_00611690_FUN_00611690.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Collect_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00611690_CVOGObjectiveRequirement_Collect_ctor.md` |
| Live decompile | Ghidra `decompile_function` `0x00611690`, base `0x00637da0`, sibling Deliver ctor `0x00610bc0` |
| Live bytes | Ghidra `read_memory` body `0x00611690`..+~100; vtable `0x009e12c4`; RTTI string `0x00afe9ac` |
| Call-site asm | Ghidra `get_assembly_context` @ `00547308` / `00547337` (factory `FUN_00547050`) |
| Type string | `read_memory` `0x009d0b34` = UTF-16 `"collect"` |
| Xrefs | sole UNCONDITIONAL_CALL `0x00547337` in `FUN_00547050` |
| Registry / chain | `NAMING_REGISTRY` Collect rows; `CHAIN_2026-07-29_inventory_collect.md` |
| Sibling contrast | Deliver ctor type **3** @ `0x00610bc0` |

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| `this` in **ECX** → **ESI** | `8B F1` after push |
| Stack arg `parent` (4 B) | `8B 44 24 04` / `PUSH EAX` into base |
| Epilogue **`RET 4`** | bytes `C2 04 00` |
| Return `this*` in **EAX** | `8B C6` before `POP ESI` |
| Convention | MSVC **`__thiscall`**, one stack dword |

```c
void* __thiscall CVOGObjectiveRequirement_Collect_ctor(
    void* this,      // ECX
    void* parent);   // stack0 — forwarded to base (+0x04)
// RET 4
```

### 3.2 RequirementType = **2** — **SEALED**

| Fact | Evidence | Confidence |
|---|---|---|
| `*(uint32*)(this+0x0c) = 2` | `C7 46 0C 02 00 00 00` | **High / Confirmed** |
| Decompiler `param_1[3] = 2` | dword index 3 → byte `+0x0c` | **High** |
| Factory branch UTF-16 `"collect"` | string @ `0x009d0b34` before alloc/ctor | **High** |
| RTTI | `.?AVCVOGObjectiveRequirement_Collect@@` @ `0x00afe9ac` | **High** |
| Contrast Deliver | Deliver ctor writes `param_1[3] = 3` | **High** |

**Seal claim (type=2):** Collect is requirement type code **2**. Not Deliver (3), not KillAggregate factory siblings.

### 3.3 Vtable — **SEALED**

| Fact | Evidence |
|---|---|
| `*this = 0x009e12c4` | `C7 06 C4 12 9E 00` after base vtable install |
| Known slots (LE dwords @ `0x009e12c4`) | `+0x04` → `0x00611f20` Action; `+0x10` → `0x00611940` Eval; `+0x18` → `0x006124b0` SlotAction; `+0x48` → `0x00611a00` XML family |

### 3.4 Base ctor `FUN_00637da0` — **SEALED** (minimal)

```c
// 0x00637da0
*this = &PTR_LAB_009e3bac;   // base requirement vtable (then overwritten)
this[1] = parent;            // +0x04
```

Base vtable LE head @ `0x009e3bac`: `0x00637f00`, stub cluster.

### 3.5 Factory alloc size **0x68** — **SEALED**

Sole production call path inside objective-requirement factory `FUN_00547050`:

```text
; type name match "collect" @ 0x009d0b34 (wide)
PUSH 0x68
CALL 0x00489892          ; operator new / pool alloc
...
MOV ECX, EAX             ; this = allocation
PUSH [objective slot]    ; parent from def+0x13c[index]
CALL 0x00611690          ; @ 0x00547337
```

Object footprint **104** bytes matches last init at `+0x64` (within `0x68`).

### 3.6 Field init map (body bytes) — **SEALED**

Order: base → `+0x10=-1` → vtable Collect → `+0x0c=2` → zeros / `-1` pads → `movss +0x48=0.0f`.

| Off | Init | Semantic (sealed / prior chain) | Confidence |
|----:|------|----------------------------------|------------|
| `+0x00` | Collect vtable | `PTR_FUN_009e12c4` | **High** |
| `+0x04` | `parent` | base stores stack arg | **High** |
| `+0x08` | **not written** | leftover / base residual | **Open** (gap) |
| `+0x0c` | **2** | **RequirementType Collect** | **High** |
| `+0x10` | `0xFFFFFFFF` | item CBID sentinel (XML fills; Eval uses) | **High** |
| `+0x14` | `0` | NumToCollect (XML; Eval divisor) | **High** |
| `+0x18` | `u8 0` | flag/pad | **Probable** |
| `+0x19` | `u8 0` | flag/pad | **Probable** |
| `+0x1c` | `0` | dword zero | **High** (store) |
| `+0x20`..`+0x44` | `0xFFFFFFFF` ×9 | TFID/id pads (product names open) | **High** (init value) |
| `+0x48` | **0.0f** (`movss` xmm0) | OptionalDropPercent (XML/chain) | **High** |
| `+0x50`,`+0x54`,`+0x5c`,`+0x60`,`+0x64` | `0xFFFFFFFF` | more sentinel dwords | **High** (init) |
| `+0x58` | `u8 0` | flag/pad | **Probable** |

**Decompiler note:** `param_1[0x12] = 0` is implemented as **`movss [esi+0x48], xmm0`**, not a dword store — float zero for drop percent.

### 3.7 Non-goals of this unit — **SEALED**

| Not this function | Owner |
|---|---|
| CBID / NumToCollect product load | DeserializeXml `0x00611a00` |
| Progress fraction | Eval `0x00611940` |
| Journal `"have / need"` | SlotAction `0x006124b0` |
| Kill-loot / inventory event | Action `0x00611f20` |
| Cargo count | `InventoryGrid_CountItemsByCbid` `0x005711c0` |

---

## 4. Confidence summary

| Claim | Level |
|---|---|
| Type code **2** at `+0x0c` | **High / Confirmed** |
| Vtable `0x009e12c4` | **High / Confirmed** |
| Class Collect (RTTI + wide `"collect"`) | **High** |
| `__thiscall` + `RET 4` + return this | **High / Confirmed** |
| Alloc size `0x68` at sole factory site | **High** |
| CBID `+0x10` init −1; Num `+0x14` init 0; drop% `+0x48` 0.0f | **High** |
| English names of every −1 pad dword | **Open** |
| `+0x08` meaning / zeroing policy | **Open** |
| Runtime / bit-exact | **Open** |

---

## 5. Gaps (carried to report)

1. Product names for `+0x20`..`+0x44` and tail sentinel fields.  
2. Whether allocator zeros `+0x08` (ctor leaves it untouched).  
3. Full factory type-string table beyond collect/deliver/kill_aggregate (parent residual).  
4. Base class formal product name for `FUN_00637da0` / `PTR_LAB_009e3bac`.  
5. Runtime construction under live mission GLM load.
