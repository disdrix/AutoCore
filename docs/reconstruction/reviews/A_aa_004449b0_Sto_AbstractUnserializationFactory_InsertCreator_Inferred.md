# Review A (reconstruction fidelity): `aa_004449b0` Sto_AbstractUnserializationFactory_InsertCreator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004449b0` |
| **VA** | `0x004449b0`–`0x00444a35` (**134 B**) |
| **Canonical name** | `Sto_AbstractUnserializationFactory_InsertCreator_Inferred` (was `FUN_004449b0`) |
| **Review date** | `2026-07-29` (W36-A) |
| **Reviewer role** | Reconstruction fidelity (factory map A insert/bind creator) |
| **Counterpart** | `reviews/B_aa_004449b0_Sto_AbstractUnserializationFactory_InsertCreator_Inferred.md` |
| **System** | arda2/storage — stoAbstractUnserializationFactory |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` + wrapper `read_memory`. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: MapA getter W35-D `0x00438c40`, map ops `0x0046c1b0`/`0x0046bf90` (W36-B unowned), sibling insert `0x00444a40` (W36-C unowned).

---

## 1. Purpose

**Register a creator function** for a FourCC tag in process-wide UnserialFactory **map A**.

Flow:

1. Get MapA (`FUN_00438c40`); capture empty sentinel `*(map+8)`.
2. NestedHash **lookup** tag (`FUN_0046c1b0`, ESI=map, ECX=&tag, EAX=&node).
3. If node ≠ sentinel → `vog_LogMessage` duplicate warning (header plate + "Inserting duplicate creator tag to factory", line `0x24`, level 2).
4. Lookup again; if still sentinel → NestedHash **insert** `{tag, 0}` via `FUN_0046bf90` (EDI=map).
5. **Always** `*(node+0xc) = EBX` (creator fn\*).

Does **not** peek chunks, invoke creators, or touch MapB.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004449b0_FUN_004449b0.md` (+ W36-A append) |
| Annotated | `docs/reconstruction/raw/aa_004449b0_FUN_004449b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_AbstractUnserializationFactory_InsertCreator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004449b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004449b0_FUN_004449b0.md` |
| Named record | `docs/reconstruction/functions/aa_004449b0_Sto_AbstractUnserializationFactory_InsertCreator_Inferred.md` |
| Live Ghidra | decompile ≡ raw CF; body `004449b0`–`00444a35`; full 134 B hex |
| Wrappers | `FUN_004448b0/d0/f0` bytes: `MOV EBX, creator; PUSH tag; CALL` |
| Map getter | W35-D `Sto_UnserialFactoryMapA_GetInstance_Inferred` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`, writes to unowned VAs.

---

## 3. Signature

```c
// __cdecl — plain RET after ADD ESP,0x10; one stack arg (caller ADD ESP,4)
// EBX = creator fn* (register input; wrappers push/pop EBX)
void Sto_AbstractUnserializationFactory_InsertCreator_Inferred(uint32_t tag);
```

| Item | Evidence |
|---|---|
| Convention | Epilogue `POP EDI; MOV [EAX+0xC],EBX; POP ESI; ADD ESP,0x10; RET` |
| Stack param | `param_1` / `[esp+0x1c]` after frame = tag FourCC |
| EBX creator | Wrappers `BB xx xx xx 00` before CALL; store `89 58 0C` |
| Callees | `FUN_00438c40`, `FUN_0046c1b0`, `FUN_0046bf90`, `vog_LogMessage` |
| Body range | Entry `004449b0`, last insn `00444a35` |
| Xrefs | **3** call sites / **3** caller functions |

---

## 4. Control flow (sealed)

```
frame 0x10 + push ESI/EDI
map = MapA(); sentinel = *(map+8)
map = MapA(); lookup(tag) → node
if node != sentinel: vog_LogMessage(duplicate)
map = MapA(); lookup(tag) → node
if node == *(map+8): insert {tag,0} → node
*(node+0xc) = EBX
restore; ret
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| MapA GetInstance ×3 | **Yes** — rel calls to `0x00438c40` |
| Sentinel from `map+8` | **Yes** — `MOV EDI,[EAX+8]` / `CMP EAX,[ESI+8]` |
| Duplicate log strings | **Yes** — imm `00a9f7ac` / `00a9f774`, line `0x24`, level 2 |
| Insert only on miss | **Yes** — `JNE have_node` skips `FUN_0046bf90` |
| Always write creator | **Yes** — store after both paths |
| EBX not stack arg | **Yes** — no push of creator; `MOV [EAX+0xC],EBX` |

**Thread safety:** none claimed (map ops unprotected).

---

## 5. Machine bytes (`read_memory` @ `0x004449b0`, 134 B)

Hex:  
`83ec105657e88642ffff8b7808e87e42ffff8bf08d4c241c8d442408e8df770200397c2408741668acf7a9006a026a246874f7a900e8d623550083c410e84e42ffff8bf08d4c241c8d442408e8af7702008b4424083b460875238b44241c8d4c2408518d542414528bfe89442410c744241400000000e8657502008b005f89580c5e83c410c3`

Decompile ≡ CF. **Bytes refine** register/map-op ABI (`ESI`/`EDI`/`ECX`/`EAX` roles) beyond decompiler elision. **No conflict** on control decisions or string side effects.

---

## 6. Naming

| Name | Status |
|---|---|
| `Sto_AbstractUnserializationFactory_InsertCreator_Inferred` | **Accept** — plate string + insert/log + MapA + creator store |
| `Sto_AbstractUnserializationFactory` (registry) | Plate alias for unit; role is insert, not whole class |
| `Named_CalleeOf_*_Palantir_*` | **Reject** scaffold |

---

## 7. Gaps

- Unowned NestedHash map-op exact layouts (`FUN_0046c1b0`, `FUN_0046bf90`).
- Product English for tag domain A vs MapB sibling insert.
- Runtime / bit-exact / differential.
- Full creator catalog beyond three wrappers.

---

## 8. Verdict

**accept-with-gaps** — ABI, CF, strings, MapA binding, EBX creator store, and dual-path insert/update sealed High. Gaps are unowned map ops and product domain English, not body fidelity.
