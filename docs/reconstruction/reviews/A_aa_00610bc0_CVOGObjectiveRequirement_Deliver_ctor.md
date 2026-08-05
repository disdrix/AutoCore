# Review A: `aa_00610bc0` Deliver requirement ctor

| Field | Value |
|---|---|
| **Review date** | `2026-07-29` |
| **Verdict** | **accept-with-gaps** |
| **Stable ID** | `aa_00610bc0` |
| **Address** | `0x00610bc0` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_ctor` |
| **Owner** | dual residual only (no WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG) |

## Inspected

- Ghidra `decompile_function` / `force_decompile` @ `0x00610bc0` (identical body both passes)
- Ghidra `read_memory` body `0x00610bc0`..`0x00610bf8` (+ trailing `CC`)
- Base ctor `FUN_00637da0` @ `0x00637da0` (vtable `PTR_LAB_009e3bac`, owner at `+0x4`)
- Deliver vtable `PTR_FUN_009e0f24` (`read_memory` 12 slots)
- RTTI string `".?AVCVOGObjectiveRequirement_Deliver@@"` @ `0x00afe97c`
- XML plate strings: `Requirement type="deliver"`, `NumToDeliver`, `CBIDItem`, `GiveItemAtStart`
- Sibling duals: CargoReady `aa_00610f20`, OnInventoryEvent `aa_00611290` (consume ctor defaults)
- Contrast Collect ctor `0x00611690` (type **2**, vtable `009e12c4`)
- Xrefs: sole code caller `FUN_00547050` @ `0x00547385` (requirement factory switch)
- Chain: `CHAIN_2026-07-29_inventory_collect.md` (Deliver ≠ Collect)

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

## Confirmed

| Claim | Confidence | Evidence |
|---|---|---|
| **Thiscall ctor** returns `this` in EAX; stack arg cleaned with **`RET 4`** | **High** | asm end: `mov eax,esi; pop esi; ret 4` |
| Base init via `FUN_00637da0(owner)` | **High** | first call; base sets `*this = 009e3bac`, `this[1]=param_2` |
| Vtable overwrite to **`PTR_FUN_009e0f24`** | **High** | `mov dword [esi], 0x009e0f24` after base |
| **Requirement type code = 3** at `this+0x0c` | **Sealed High** | `mov dword [esi+0x0c], 3`; Collect is type **2** |
| Class identity **Deliver** | **Sealed High** | RTTI `CVOGObjectiveRequirement_Deliver` + XML `type="deliver"` + type **3** |
| Default **`+0x20..+0x23 = 1`** (four consecutive bytes) | **Sealed High** | `mov al,1` then four `mov [esi+20..23], al` |
| **`+0x23` default = 1** (require-count / enforce-qty) | **Sealed High** | same store; consumers `0x00610f20` / `0x00611290` treat `==0` as qty bypass |
| `+0x10` CBIDItem default **−1** | **High** | `or ecx,-1; mov [esi+0x10], ecx` |
| `+0x14` NumToDeliver default **0** | **High** | `mov dword [esi+0x14], 0` |
| `+0x18` TargetNPCCBID / match key default **−1** | **High** | `mov [esi+0x18], ecx` |
| `+0x1c` ContinentID default **−1** | **High** | `mov [esi+0x1c], ecx` |
| `+0x20` GiveItemAtStart default **1** | **High** | ctor byte + XML tag `GiveItemAtStart` (sibling GetFlags) |
| `+0x21` TakeItemAtEnd default **1** | **High** | ctor byte + sibling field map |
| `+0x22` NPCTargetCompletes default **1** | **High** | ctor byte + OnInventoryEvent toast gate |
| Not Collect | **Sealed High** | type 3 / vtable `009e0f24` vs Collect type 2 / `009e12c4` |

## Seal focus (task)

### Type code **3**

```text
c7 46 0c 03 00 00 00    mov dword ptr [esi+0Ch], 3
```

| Claim | Status |
|-------|--------|
| Deliver requirement enum value is **3** | **Sealed High** |
| Distinct from Collect **2** | **Sealed High** |

### `+0x23` default **1**

```text
b0 01                   mov al, 1
…                       ; also writes +0x20/+0x21/+0x22
88 46 23                mov [esi+23h], al
```

| Claim | Status |
|-------|--------|
| Ctor default `*(uint8*)(this+0x23) = 1` | **Sealed High** |
| Semantic (from consumers): non-zero = enforce `need ≤ count`; **0** = bypass qty | **Sealed High** (sibling duals) |
| Authorship later: XML may force **0** when `CBIDItem == -1` | **High** (unserialize residual; not this body) |

## Gaps (remaining)

- Original PDB may include extra decoration; RTTI class name is sealed — method name `…_ctor` is standard plate
- Factory `FUN_00547050` full type-string switch map (only call site sealed; switch body decompiler-broken / unreachable-heavy)
- Exact English for `+0x23` (inferred `bRequireItemCount` / require-count) — **not** a free-standing XML tag
- Base layout: progress slot at `+0x08` **not** written by this ctor (left for base/XML path)
- Runtime / bit-exact / image diff (policy)

## Verdict

**accept-with-gaps** — **type=3** and **`+0x23` default=1** sealed High from image + decompile; class Deliver sealed via RTTI/XML/type; residual gaps are factory enum dump, PDB plate, runtime only.
