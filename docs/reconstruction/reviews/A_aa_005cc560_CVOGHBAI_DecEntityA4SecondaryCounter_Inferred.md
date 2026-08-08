# Review A (reconstruction fidelity): `aa_005cc560` CVOGHBAI_DecEntityA4SecondaryCounter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc560` |
| **VA** | `0x005cc560`–`0x005cc5ad` |
| **Canonical name** | `CVOGHBAI_DecEntityA4SecondaryCounter_Inferred` |
| **Ghidra name** | `FUN_005cc560` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-093) |
| **Counterpart** | `reviews/B_aa_005cc560_CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.md` |
| **System** | input-drive-control / npc-ai / HBAI entity counters |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + RTTI |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

HBAI virtual leaf that releases one **secondary** occupancy/counter lane on the host entity’s `+0xA4` block after resolving a related object through **`vtbl+0x214`**, branched on **`related+0x250`**. Also the shared tail of Driver **axis-park** (`FUN_005d73a0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-093 append) | `docs/reconstruction/raw/aa_005cc560_FUN_005cc560.md` |
| Annotated | `docs/reconstruction/raw/aa_005cc560_FUN_005cc560.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005cc560.cpp` |
| Function | `docs/reconstruction/functions/aa_005cc560_FUN_005cc560.md` |
| Named record | `docs/reconstruction/functions/aa_005cc560_CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.md` |
| Live decompile | ≡ scaffold raw 2026-07-23 |
| Live bytes | 78 B body + `CC` pad; shared `RET` @ `0x005081e0` |
| Parent (evidence) | `FUN_005d73a0` Driver park → tail JMP |
| Sibling (evidence) | `FUN_005cc5b0` fuller A4 counter release |

---

## 3. Signature (sealed)

```c
// thiscall; 0 stack formals; plain RET via JMP 0x005081e0
void CVOGHBAI_DecEntityA4SecondaryCounter_Inferred(void *this);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → EDI | **High** |
| cleanup | `JMP 0x005081e0` → `C3` | **High** |
| stack args | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
entity = this+0x18
if entity == 0 → ret
if entity+0xA4 == 0 → ret
counters = entity+0xA4
related = entity->vtbl[+0x214]()   // thiscall ECX=entity
if related == 0 → ret
if related+0x250 == 0:
    counters[+0x18]--
else:
    counters[+0x1c]--
ret
```

| Stage | Match | Conf |
|---|---|---|
| ECX this | **Yes** `MOV EDI,ECX` | **High** |
| entity `+0x18` | **Yes** | **High** |
| counters `+0xA4` | **Yes** (`CMP [EAX+0xA4]`; decomp `[0x29]`) | **High** |
| `CALL [vtbl+0x214]` | **Yes** `FF 90 14 02 00 00` | **High** |
| branch `+0x250` | **Yes** `CMP [EAX+0x250],0` | **High** |
| dec `+0x18` / `+0x1c` | **Yes** ESI=`counters+0x10`; `[ESI+8]` / `[ESI+C]` | **High** |
| bare ret path | **Yes** shared `0x005081e0` | **High** |

---

## 5. Machine bytes (`read_memory`)

```
578bf98b471885c0743c83b8a40000000074338bc88b01568bb1a400000083c610
ff901402000085c0741a83b85002000000740d83460cff5e8bcf5fe93fbcf3ff
834608ff5e8bcf5fe932bcf3ff
```

Body **78 B** (`0x005cc560`–`0x005cc5ad`); pad `CC CC` before `FUN_005cc5b0`.

---

## 6. Callers / xrefs

| Kind | Evidence |
|---|---|
| Code | `FUN_005d73a0` @ `0x005d73e3` tail `JMP` (Driver park) |
| DATA | 5 vtables — CreatureBase / Character / Mine / Bot / WalkingCreatureTurreted |
| Callees | none direct (`analyze_function_complete` leaf) |

Parent park (not dualled): zero steer/longitudinal, handbrake 1, FollowVehicle fire weapons (0,0), push drive axes, then base counter release.

---

## 7. Gaps

- Product English for **`entity+0xA4`** counter block and secondary pair meaning.
- Product English for **`vtbl+0x214`** and **`related+0x250`**.
- Full MI vtable ordinal table across all HBAI subclasses (slot-after-OnHeartBeat sealed on CreatureBase dump; Driver replaces with park).
- Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF, ABI, offsets, callers, and Driver-park tail link are byte-sealed. Residual is product naming for counters/related fields → **accept-with-gaps**.
