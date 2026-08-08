# Review A (reconstruction fidelity): `aa_006ca890` SoftCastHitList_CoreFillAndRegister_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ca890` |
| **VA** | `0x006ca890`–`0x006ca93b` inclusive (**172 B** / `0xAC`) |
| **Canonical name** | `SoftCastHitList_CoreFillAndRegister_Inferred` |
| **Ghidra name** | `FUN_006ca890` |
| **Prior scaffold** | `FUN_006ca890` (2026-07-23 trio) |
| **Rejected misname** | free 5-arg cdecl; "always related"; "sort/compare"; product class without `_Inferred` |
| **Review date** | `2026-08-05` (MEGA-062 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_006ca890_SoftCastHitList_CoreFillAndRegister_Inferred.md` |
| **System** | interaction-activation (soft-cast hit list) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` + `get_function_by_address` + `get_assembly_context` (caller + hub). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Soft-cast hit-list **core fill + register**:

```text
SoftCastHitList_CoreFillAndRegister_Inferred(entry, manager, soft_desc, related, payload, backref)
  entry[+4]  = soft_desc
  entry[+0xC]= backref
  entry[+0x10]= 0
  entry[+8]  = related ? related+0x14 : 0
  if soft_desc[+0x20] == 0:
      entry[+0x44] = 0
  else if related == 0:
      entry[+0x44] = 0; entry[+0x40] = soft_desc[+0x24]
  else:
      entry[+0x44] = related+0x10; entry[+0x40] = soft_desc[+0x24]
  pack query {desc[0..0xC], flag=1, ext=desc+0x10, size=0x10, payload}
  manager->vtbl[+0x30](&query, entry, 0)
  RET 0x14
```

Sole retail caller: wrapper **`FUN_0055e1e0`** (local entry + vtbl `0x009d27a8`), from dualed **`Client_InteractWorldClickHub`** after hit-list init and before sort gate `0x0048a060`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-062 append) | `docs/reconstruction/raw/aa_006ca890_FUN_006ca890.md` |
| Annotated | `docs/reconstruction/raw/aa_006ca890_FUN_006ca890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_CoreFillAndRegister_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006ca890.cpp` |
| Function record | `docs/reconstruction/functions/aa_006ca890_FUN_006ca890.md` |
| Named record | `docs/reconstruction/functions/aa_006ca890_SoftCastHitList_CoreFillAndRegister_Inferred.md` |
| Live | decompile ≡ scaffold CF; body 172 B; `RET 0x14`; 1 CALL xref |
| Wrapper | `FUN_0055e1e0` disasm + assembly context @ `0x0055e215` |
| Hub | `Client_InteractWorldClickHub` call @ `0x00925c32` → sort @ `0x00925c3e` |
| Sibling dual | `SoftCastHitList_SortIfCountGt1_Inferred` (`aa_0048a060`, MEGA-116) |

---

## 3. Signature (sealed)

```c
// ECX = SoftCastHitEntry* this; 5 stack args; void; RET 0x14
void __thiscall SoftCastHitList_CoreFillAndRegister_Inferred(
    SoftCastHitEntry *this,
    void *manager,
    uint32_t *soft_desc,
    int related_obj_or_null,
    uint32_t query_payload,
    uint32_t hit_list_backref);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (`MOV EAX,ECX`; stores via `[EAX+…]`) | **Confirmed** |
| manager | **`[EBP+0x08]`** → vcall `[*manager + 0x30]` | **Confirmed** |
| soft_desc | **`[EBP+0x0C]`** | **Confirmed** |
| related | **`[EBP+0x10]`** (`TEST ESI,ESI`) | **Confirmed** |
| payload | **`[EBP+0x14]`** → query local | **Confirmed** |
| backref | **`[EBP+0x18]`** → entry `+0x0C` | **Confirmed** |
| cleanup | **`RET 0x14`** (`C2 14 00`) | **Confirmed** |
| return | void; no EAX contract | **Confirmed** |

**Note:** Parent decompile of `FUN_0055e1e0` omits local-entry `this`; assembly seals `LEA ECX,[ESP+0x14]` + vtbl `0x009d27a8`.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Frame align `AND ESP,~0xF` / `SUB ESP,0x2C` | **Yes** | **Confirmed** |
| Store soft_desc / backref / zero `+0x10` | **Yes** | **Confirmed** |
| related null → `+8=0` else `related+0x14` | **Yes** | **Confirmed** |
| flag@+0x20 clear → only `+0x44=0` | **Yes** | **Confirmed** |
| flag set + related null → `+0x44=0`, `+0x40=desc+0x24` | **Yes** | **Confirmed** |
| flag set + related → `+0x44=related+0x10`, `+0x40=desc+0x24` | **Yes** | **Confirmed** |
| Pack 4 header dwords + ext ptr + payload + `{1,0x10}` | **Yes** | **Confirmed** |
| Indirect CALL `[vtbl+0x30]` with `(&query, entry, 0)` | **Yes** | **Confirmed** |
| `POP ESI` / restore frame / `RET 0x14` | **Yes** | **Confirmed** |
| No direct `FUN_*` callees | **Yes** | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (entry fill + indirect register) |
| External callers | **1** — `FUN_0055e1e0` |
| Xref count | **1** UNCONDITIONAL_CALL @ `0x0055e215` |
| Callees | indirect manager `vtbl+0x30` only |
| Site role | soft-cast fill core under interact hub list path |

---

## 6. Naming gate

| Candidate | Gate |
|---|---|
| `SoftCastHitList_CoreFillAndRegister_Inferred` | **Pass** — matches partition hint + MEGA-116 chain plate; `_Inferred` (no PDB/string class name) |
| Product demangle without `_Inferred` | **Fail** — no string/RTTI for this body |
| `Named_CalleeOf_*` | **N/A** — no such scaffold for this VA |

---

## 7. Gaps (explicit)

- Product English for manager interface / vtbl slot `+0x30`.
- Full SoftCastHitEntry / vtbl `0x009d27a8` method map (writes only seal partial layout).
- Soft-desc field meanings (`+0x24`, query `1`/`0x10`).
- Wrapper `FUN_0055e1e0` not dual-owned here (evidence only).
- Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF, ABI (`thiscall` + `RET 0x14`), sole-caller chain, and entry/query field math are sealed against live decompile + assembly. Product English and runtime remain open → **accept-with-gaps**.
