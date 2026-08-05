# Review A (reconstruction fidelity): `aa_004111f0` MissionRuntimeStateBlob_Init

| Field | Value |
|---|---|
| **Stable ID** | `aa_004111f0` |
| **VA** | `0x004111f0`–`0x0041121b` |
| **Canonical name** | `FUN_004111f0` (Ghidra) |
| **Human / Probable name** | `MissionRuntimeStateBlob_Init` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004111f0_MissionRuntimeStateBlob_Init.md` |
| **System** | missions-progression (GiveMission path) |
| **Verdict** | **accept** (body sealed; field product English for blob slots Tentative) |

---

## 1. Purpose

Leaf **in-place initializer** for the **0x30-byte mission runtime state blob** allocated on the grant path in `CVOGReaction_GiveMission` (`0x005327c0`):

1. Caller does `operator_new(0x30)` then, on non-null, `MOV ECX, blob; CALL 0x004111f0`.
2. This unit writes **eleven dwords** (`+0x00` … `+0x28`) to **`0xFFFFFFFF`** and **byte `+0x2C`** to **`0`**.
3. **No callees, no globals, no branches.** Pure stores + `RET`.
4. **`EAX` is preserved as the blob pointer** (`MOV EAX,ECX` at entry; never overwritten) so the GiveMission decompile’s `local = (undefined4*)FUN_004111f0()` captures the same pointer via EAX even though Ghidra types the return as `void` / `undefined`.

Does **not** allocate, free, insert into hashes, or copy prior state — those remain in the parent (`operator_new`, `FUN_00538a40` prior copy of `0xC` dwords, `FUN_0053c660` bind on `char+0x530`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004111f0_FUN_004111f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004111f0_FUN_004111f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004111f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004111f0_FUN_004111f0.md` |
| Sole caller | `CVOGReaction_GiveMission` `0x005327c0` (xref call site `0x00532988`) |
| Parent dual | `reviews/A_aa_005327c0_CVOGReaction_GiveMission.md` |
| Live Ghidra | `decompile_function` `0x004111f0`; `analyze_function_complete`; `get_function_callers`; `get_function_xrefs`; `read_memory` 64 B @ entry |

---

## 3. Signature

```c
// ECX = blob base (MS thiscall / __fastcall first-arg register)
// EAX @ RET = same blob pointer (constructor-style; decompiler often shows void)
std::uint32_t* __fastcall MissionRuntimeStateBlob_Init(std::uint32_t* pBlob);
// Equivalent store surface if return ignored:
// void __fastcall FUN_004111f0(undefined4* param_1);
```

| Item | Evidence |
|---|---|
| Convention | Body uses **ECX only** as base; plain **`RET`** (no stack args) → **`__fastcall` / thiscall-style** single-register arg |
| Arg | `param_1` storage `register:ECX` (`analyze_function_complete`) |
| Return | Decompiler `void` / signature `undefined FUN_004111f0(void)` — **wrong for EAX**. Bytes: `MOV EAX,ECX` then only stores; **EAX still = pBlob at RET**. GiveMission assigns return → **High** that callers consume EAX |
| Leaf | `callees: []` |
| Body range | Entry `004111f0`, `RET` @ `0041121b`; `CC` pad then next function |

---

## 4. Control flow (sealed)

```
// no null check
*(uint8_t*)(pBlob + 0x2C) = 0;
for offsets in {0x20,0x24,0x28, 0x00,0x04,0x08,0x0C,0x10,0x14,0x18,0x1C}:
  *(uint32_t*)(pBlob + off) = 0xFFFFFFFF;
return pBlob;  // EAX
```

Store **order** (asm, not semantic): byte `+0x2C` first, then dwords `+0x20/+0x24/+0x28`, then `+0x00`…`+0x1C`. Order is not observable for correctness of final state (no intermediate reads).

**Not written by this unit:** bytes `+0x2D`…`+0x2F` (tail of the `0x30` allocation). Parent may later overwrite the full `0x30` via a `0xC`-dword prior-state copy.

---

## 5. Machine bytes (`read_memory` @ `0x004111f0`, 44 B body)

```
8B C1          MOV  EAX, ECX           ; pBlob → EAX (return prep)
83 C9 FF       OR   ECX, 0xFFFFFFFF    ; ECX = -1 (broadcast fill)
C6 40 2C 00    MOV  BYTE PTR [EAX+0x2C], 0
89 48 20       MOV  [EAX+0x20], ECX
89 48 24       MOV  [EAX+0x24], ECX
89 48 28       MOV  [EAX+0x28], ECX
8B D0          MOV  EDX, EAX
89 0A          MOV  [EDX], ECX         ; +0x00
89 4A 04       MOV  [EDX+0x04], ECX
89 4A 08       MOV  [EDX+0x08], ECX
89 4A 0C       MOV  [EDX+0x0C], ECX
89 4A 10       MOV  [EDX+0x10], ECX
89 4A 14       MOV  [EDX+0x14], ECX
89 4A 18       MOV  [EDX+0x18], ECX
89 4A 1C       MOV  [EDX+0x1C], ECX
C3             RET
```

Hex (body): `8bc183c9ffc6402c008948208948248948288bd0890a894a04894a08894a0c894a10894a14894a18894a1cc3`

Decompile store set ≡ bytes. **No conflict.** Decompiler only mis-states return type and elides “returns this”.

---

## 6. Blob layout after init (machine surface)

| Offset | Width | Value written | Notes |
|---|---|---|---|
| `+0x00` … `+0x28` | 11 × `uint32` | `0xFFFFFFFF` | Sentinel fill |
| `+0x2C` | `uint8` | `0` | Cleared flag/byte (product meaning open) |
| `+0x2D` … `+0x2F` | 3 B | **unchanged** | Outside this unit’s stores |

Parent call pattern (context only, not re-owned):

```
pv = operator_new(0x30);
if (!pv) blob = 0;
else blob = MissionRuntimeStateBlob_Init(pv);  // ECX=pv; EAX→blob
// optional: copy 0xC dwords from prior node+0x18 over blob
// FUN_0053c660(*def, blob, 0)  // ECX = char+0x530
```

---

## 7. Param / local renames (evidence only)

| Raw | Clean / dual | Evidence |
|---|---|---|
| `param_1` | `pBlob` / `pStateBlob` | Sole pointer written; `operator_new(0x30)` result from sole caller |
| (return void) | `return pBlob` | `MOV EAX,ECX` + GiveMission assigns return |

No other locals. No DAT_*. No FUN_* callees.

---

## 8. Control flow: clean ≡ raw

| Stage | Raw | Clean match? |
|---|---|---|
| Clear byte `+0x2C` | Yes | **Yes** |
| Fill dwords `+0x20/+0x24/+0x28` | Yes | **Yes** |
| Fill dwords `+0x00`…`+0x1C` | Yes | **Yes** |
| No branches / no callees | Yes | **Yes** |
| Return pointer in EAX documented | Raw `void` | **Clean documents return** (behavior-preserving; matches bytes + caller) |

**Result:** Store CF sealed. Clean may type return as pointer without inventing stores.

---

## 9. Gaps / open questions

1. **Product English** for each dword slot and for byte `+0x2C` (Tentative — needs consumers of the `+0x530` blob, not this unit).
2. Whether any non-GiveMission caller ever existed historically — **current image: sole xref `0x00532988`**.
3. Runtime / bit-exact image vs loaded EXE: open (leaf pure stores — low risk).
4. Ghidra signature still `undefined FUN_004111f0(void)` — rename/retype optional tooling debt.

---

## Verdict

**accept** — leaf sentinel init of the GiveMission **0x30** state blob is High CF from decompile + bytes. Return-in-EAX is High from asm + sole caller use. Field-level product names remain Tentative outside this unit’s scope.
