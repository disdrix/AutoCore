# Review A (reconstruction fidelity): `aa_00437c90` Sto_UnserialFactoryMapB_LookupInvoke_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437c90` |
| **VA** | `0x00437c90`–`0x00437cce` (**63 B**) |
| **Canonical name** | `Sto_UnserialFactoryMapB_LookupInvoke_Inferred` (was `FUN_00437c90`) |
| **Review date** | `2026-07-29` (W36-C) |
| **Reviewer role** | Reconstruction fidelity (map B lookup + invoke) |
| **Counterpart** | `reviews/B_aa_00437c90_Sto_UnserialFactoryMapB_LookupInvoke_Inferred.md` |
| **System** | arda2/storage — stoAbstractUnserializationFactory map B |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers`. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: PeekChunkTag, MapB GetInstance W35-D, find W36-B, MapA lookup W36-A (not owned).

---

## 1. Purpose

**Lookup + invoke creator** on NestedHash **map B**:

1. Entry **EAX = stoChunkReader*** → ESI.
2. `tag = PeekChunkTag()` (`FUN_0076a900`).
3. Find tag in MapB (`FUN_00438ca0` + `FUN_0046c1b0`).
4. If node ≠ sentinel: restore ESI=reader; **`CALL [node+0xC]`**; return EAX.
5. Else return **0**.

Complements insert twin `0x00444a40` (writes the same `+0xC` slot).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00437c90_FUN_00437c90.md` (+ W36-C append) |
| Annotated | `docs/reconstruction/raw/aa_00437c90_FUN_00437c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Sto_UnserialFactoryMapB_LookupInvoke_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00437c90.cpp` |
| Function record | `docs/reconstruction/functions/aa_00437c90_FUN_00437c90.md` |
| Named record | `docs/reconstruction/functions/aa_00437c90_Sto_UnserialFactoryMapB_LookupInvoke_Inferred.md` |
| Live Ghidra | decompile CF ≡ raw; body `00437c90`–`00437cce`; full 63 B hex |
| Callers | `FUN_00765740` @ `0x00765cce` (1 site) |

---

## 3. Signature

```c
// entry EAX = stoChunkReader*; no stack args; returns void* or 0
void* Sto_UnserialFactoryMapB_LookupInvoke_Inferred(void);
```

| Item | Evidence |
|---|---|
| Entry formal | Prologue `MOV ESI,EAX` then Peek uses ESI |
| Convention | `SUB ESP,8` / dual `ADD ESP,8; RET` |
| Callees | Peek, MapB×2, find |
| Body range | Entry `00437c90`, last insn `00437cce` |
| Xrefs | **1** call site / **1** caller |

---

## 4. Control flow (sealed)

```
ESI = EAX (reader)
tag = PeekChunkTag()
bag = MapB_Get(); node = Find(bag, tag)
bag = MapB_Get()
if node == bag.sentinel: return 0
POP ESI (reader); CALL [node+0xC]; return EAX
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| MapB only | **Yes** — calls → `00438ca0` |
| Miss → 0 | **Yes** — `XOR EAX,EAX` |
| Hit → indirect call +0xC | **Yes** — `FF 51 0C` |
| Stack push of tag before call | **No** — gap vs decompiler `(tag)` |

---

## 5. Machine bytes (`read_memory` @ `0x00437c90`, 63 B)

Hex (63 B):  
`83ec08568bf0e8652c330089442404e8fc0f00008bf08d4c24048d442408e8fd440300e8e80f00008b4c24083b48085e7407ff510c83c408c333c083c408c3`

Decompile ≡ bytes for sealed CF. **Creator formal list open.**

---

## 6. Gaps

- Creator calling convention (decompiler tag-arg vs bare CALL; ESI=reader available).
- MapA twin `FUN_00437b00` is **not** body-identical (extra out-param/vcall) — do not conflate.
- Sole caller product English.
- Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — peek/find/miss-0/invoke site + map B sealed; creator ABI residual.
