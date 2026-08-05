# Review A (reconstruction fidelity): `aa_00437b00` Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437b00` |
| **VA** | `0x00437b00`–`0x00437b57` (**88 B**) |
| **Canonical name** | `Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred` (was `FUN_00437b00`) |
| **Review date** | `2026-07-29` (W36-A) |
| **Reviewer role** | Reconstruction fidelity (map A peek/lookup/create/unserialize) |
| **Counterpart** | `reviews/B_aa_00437b00_Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.md` |
| **System** | arda2/storage — stoAbstractUnserializationFactory + stoChunkReader |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` + sample creator decompile + call-site `read_memory`. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: MapA W35-D, PeekChunkTag W19-R, map lookup W36-B unowned, MapB twin `0x00437c90` W36-C unowned.

---

## 1. Purpose

**Materialize and unserialize** the object for the **next peeked chunk tag** using factory **map A**:

1. `ESI = EDI` (chunk reader); `tag = stoChunkReader_PeekChunkTag()` (`FUN_0076a900`).
2. MapA GetInstance + NestedHash lookup (`FUN_0046c1b0`).
3. If node == `*(map+8)` sentinel → `obj = 0`; else `obj = creator()` at `node+0xc` (**0 stack args**).
4. `*param_1 = obj`.
5. If obj ≠ 0: thiscall vfunc slot 1 on `(obj+4)` with **EDI (reader)** as stack arg → return status.
6. Else return **`0xFFFFFFFF`**.

Does **not** register creators (that is `FUN_004449b0`) and does **not** use MapB.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00437b00_FUN_00437b00.md` (+ W36-A append) |
| Annotated | `docs/reconstruction/raw/aa_00437b00_FUN_00437b00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00437b00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00437b00_FUN_00437b00.md` |
| Named record | `docs/reconstruction/functions/aa_00437b00_Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.md` |
| Live Ghidra | decompile + full 88 B hex; body `00437b00`–`00437b57` |
| Sample creator | `FUN_00444d00` @ `0x00444d00` — `void→ptr`, `operator_new(0xC4)` + ctor |
| Caller | `FUN_00765740` 4 sites; `PUSH out; MOV EDI,reader; CALL; ADD ESP,4` |
| Peek | sealed `stoChunkReader_PeekChunkTag` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger, `disassemble_bytes`, unowned VA writes.

---

## 3. Signature

```c
// __cdecl; plain RET; caller ADD ESP,4
// EDI = stoChunkReader* (register)
// stack: void **out_object
// return: uint32 status, or 0xFFFFFFFF
uint32_t Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred(void **out);
```

| Item | Evidence |
|---|---|
| EDI reader | Prologue `MOV ESI,EDI` before Peek; later `PUSH EDI` to vfunc |
| Peek this=ESI | Matches PeekChunkTag ABI |
| Creator 0-arg | `FF 51 0C` no prior PUSH; sample creator void |
| Vfunc this=`obj+4` | `LEA ECX,[EAX+4]; MOV EDX,[EAX+4]; CALL [EDX+4]` |
| Fail `-1` | `OR EAX,0xFFFFFFFF` path |
| Body range | `00437b00`–`00437b57` |
| Xrefs | **4** sites / **1** caller function |

---

## 4. Control flow (sealed)

```
frame 8 + push ESI
ESI = EDI
tag = PeekChunkTag()
map = MapA(); lookup(tag) → node
map = MapA()
if node == *(map+8): obj = 0
else: obj = call [node+0xc]()
*out = obj
if obj == 0: return -1
this = obj+4; push reader; call vtbl[1]; return status
```

| Stage | Match |
|---|---|
| Peek then lookup | **Yes** |
| Sentinel miss → 0 | **Yes** — `JE` + `XOR EAX,EAX` |
| Creator call | **Yes** — `FF 51 0C` |
| Out store | **Yes** — `MOV [ECX],EAX` with ECX=`param_1` |
| Vfunc + reader arg | **Yes** — `PUSH EDI; FF 52 04` |
| Fail `-1` | **Yes** |

**Decompile corrections:** creator does **not** take tag; vfunc **does** take reader (EDI).

---

## 5. Machine bytes (`read_memory` @ `0x00437b00`, 88 B)

Hex:  
`83ec08568bf7e8f52d330089442404e82c1100008bf08d4c24048d442408e88d460300e8181100008b4c24083b48085e7405ff510ceb0233c085c08b4c240c8901740e8b50048d480457ff520483c408c383c8ff83c408c3`

Bytes win over decompiler on call ABIs. CF decisions match raw.

---

## 6. Naming

| Name | Status |
|---|---|
| `Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred` | **Accept** — MapA + Peek + create + unserialize |
| `Named_CalleeOf_Named_gfxBody_*` | **Reject** as product role (caller path only) |

---

## 7. Gaps

- Concrete C++ type of created object / full vtable (sample size 0xC4 only).
- Unowned NestedHash lookup internals.
- MapB twin `FUN_00437c90` semantics (not owned).
- Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — ABI, peek/lookup/create/unserialize CF, fail `-1`, and MapA binding sealed High. Gaps are object-type English and unowned map-op detail.
