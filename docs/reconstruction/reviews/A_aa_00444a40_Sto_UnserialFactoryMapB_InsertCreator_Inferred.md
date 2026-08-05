# Review A (reconstruction fidelity): `aa_00444a40` Sto_UnserialFactoryMapB_InsertCreator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444a40` |
| **VA** | `0x00444a40`–`0x00444ac5` (**134 B**) |
| **Canonical name** | `Sto_UnserialFactoryMapB_InsertCreator_Inferred` (was `FUN_00444a40`) |
| **Review date** | `2026-07-29` (W36-C) |
| **Reviewer role** | Reconstruction fidelity (map B creator insert) |
| **Counterpart** | `reviews/B_aa_00444a40_Sto_UnserialFactoryMapB_InsertCreator_Inferred.md` |
| **System** | arda2/storage — stoAbstractUnserializationFactory map B |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers`. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: MapB GetInstance W35-D, map ops W36-B, MapA insert twin W36-A (not owned).

---

## 1. Purpose

**Insert / bind creator** into NestedHash **map B** (`FUN_00438ca0` → `DAT_00d1fcec`):

1. Load sentinel from `*(GetInstance()+8)`.
2. Find stack **tag**; if present → log `"Inserting duplicate creator tag to factory"` (header `stoAbstractUnserializationFactory.h`, line `0x24`, severity `2`).
3. Find again; if missing → insert pair `{tag, 0}` via `FUN_0046bf90`.
4. Always write **EBX** (creator fn ptr) to **`node+0x0C`**.

Does **not** own map storage construction (MapB getter / NestedHash ctor).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00444a40_FUN_00444a40.md` (+ W36-C append) |
| Annotated | `docs/reconstruction/raw/aa_00444a40_FUN_00444a40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_InsertCreator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00444a40.cpp` |
| Function record | `docs/reconstruction/functions/aa_00444a40_FUN_00444a40.md` |
| Named record | `docs/reconstruction/functions/aa_00444a40_Sto_UnserialFactoryMapB_InsertCreator_Inferred.md` |
| Live Ghidra | decompile ≡ raw CF; body `00444a40`–`00444ac5`; full 134 B hex |
| Callers | `FUN_00444910` DSDL `0x4C445344`; `FUN_00444930` AADL `0x4C444141` |
| Strings | `0x00a9f774` header; `0x00a9f7ac` dup message |

---

## 3. Signature

```c
// cdecl stack tag; EBX = creator_fn* (register formal); void
void Sto_UnserialFactoryMapB_InsertCreator_Inferred(uint32_t tag);
```

| Item | Evidence |
|---|---|
| Convention | `SUB ESP,0x10` / `ADD ESP,0x10; RET`; tag at `[ESP+0x1C]` after frame |
| EBX formal | Final `MOV [EAX+0xC], EBX` |
| Callees | MapB×3, find×2, insert×1, vog_LogMessage |
| Body range | Entry `00444a40`, last insn `00444ac5` |
| Xrefs | **2** call sites / **2** caller functions |

---

## 4. Control flow (sealed)

```
sentinel = *(MapB_Get()+8)
node = Find(MapB_Get(), tag)
if node != sentinel: LogDuplicate
node = Find(MapB_Get(), tag)
if node == sentinel: node = Insert({tag,0})
*(node+0xC) = EBX
return
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| MapB only (not MapA) | **Yes** — all three calls → `00438ca0` |
| Dup log immediates | **Yes** — hdr, line 0x24, sev 2, msg |
| Insert only on miss | **Yes** |
| Always bind EBX @ +0xC | **Yes** |
| Twin of MapA insert shape | **Yes** (context `004449b0`) |

---

## 5. Machine bytes (`read_memory` @ `0x00444a40`, 134 B)

Hex (134 B):  
`83ec105657e85642ffff8b7808e84e42ffff8bf08d4c241c8d442408e84f770200397c2408741668acf7a9006a026a246874f7a900e84623550083c410e81e42ffff8bf08d4c241c8d442408e81f7702008b4424083b460875238b44241c8d4c2408518d542414528bfe89442410c744241400000000e8d57402008b005f89580c5e83c410c3`

Decompile ≡ bytes for sealed claims. **No conflict.**

---

## 6. Gaps

- Creator function prototype (EBX target).
- Full MapB tag catalog (only DSDL/AADL wrappers sealed here).
- Unowned `FUN_0046c1b0` / `FUN_0046bf90`.
- Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — insert/bind CF, map B exclusivity, strings, EBX@+0xC, callers sealed; creator type open.
