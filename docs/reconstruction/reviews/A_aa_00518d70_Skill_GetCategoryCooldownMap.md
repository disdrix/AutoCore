# Review A (reconstruction fidelity): `aa_00518d70` Skill_GetCategoryCooldownMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518d70` |
| **VA** | `0x00518d70` |
| **Canonical name** | `Skill_GetCategoryCooldownMap` |
| **Review date** | `2026-07-29` (residual strengthen; prior scaffold `2026-07-23`) |
| **Reviewer role** | Reconstruction fidelity / dual residual |
| **Counterpart** | `reviews/B_aa_00518d70_Skill_GetCategoryCooldownMap.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** on CF + layout; owner **product class** residual |

---

## 1. Purpose

Lazy-get the **category cooldown** map pointer stored at map-owner **`+0x6c`**. If null, allocate a **0xC** map header, build an empty red-black-style head via **`FUN_005ae2b0`** (`operator_new(0x1c)` node), self-link L/P/R, set size **0**, store at `+0x6c`, and return it. Thin accessor — **no** category key math, duration math, or erase here.

Used by insert / remaining / cast-again / status-effect abort paths that all share the same host slot.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra MCP `decompile_function` @ `0x00518d70` |
| Bytes | `read_memory` @ `0x00518d70` length 128 — CF matches decompile |
| Plate | `Skill_GetCategoryCooldownMap(pMapOwner)` — map at `+0x6c`; VERIFIED lazy std::map-style |
| Globals | `audit_globals_in_function` → SEH only (`ExceptionList`, `LAB_009a3612`); **no** product string |
| Callees | `operator_new(0xc)`, `FUN_005ae2b0` |
| Callers / xrefs | 4 functions / **8** UNCONDITIONAL_CALL sites (below) |
| Twin | `FUN_00518c20` @ `0x00518c20` slot **`+0x68`** (leave-FUN; different node factory) |
| Related duals | `a_0051e240.md` (map host = **owner**, not skill); Insert / Remaining / CategoryCooldownMap_Insert |
| Raw / clean | `docs/reconstruction/raw/aa_00518d70_Skill_GetCategoryCooldownMap.md`, `reconstructed-exact/Skill_GetCategoryCooldownMap.cpp` |

---

## 3. Sealed control flow (Confirmed)

```c
void * __fastcall Skill_GetCategoryCooldownMap(void *pMapOwner)  // ECX = owner
{
  // SEH: ExceptionList / LAB_009a3612
  if (*(int *)((int)pMapOwner + 0x6c) == 0) {
    void *hdr = operator_new(0xc);
    if (hdr == 0) {
      hdr = 0;
    } else {
      void *head = FUN_005ae2b0();           // operator_new(0x1c) sentinel
      *(void **)((int)hdr + 4) = head;       // _Myhead
      *(uint8_t *)((int)head + 0x19) = 1;    // is_nil / head flag
      // self-link parent (+4), left (+0), right (+8) of head
      *(void **)((int)head + 4) = head;
      *(void **)head = head;
      *(void **)((int)head + 8) = head;
      *(uint32_t *)((int)hdr + 8) = 0;       // size
    }
    *(void **)((int)pMapOwner + 0x6c) = hdr; // store even on OOM (null)
  }
  return *(void **)((int)pMapOwner + 0x6c);
}
```

| Stage | Match decompile | Match bytes |
|---|---|---|
| `mov ebx,ecx`; `cmp [ebx+0x6c],0` | Yes | Yes (`83 7b 6c 00`) |
| `push 0xc` / `operator_new` | Yes | Yes |
| OOM → ESI=0 then store | Yes | `33 f6` / `89 73 6c` |
| `FUN_005ae2b0` → head; `[esi+4]=eax` | Yes | Yes |
| `mov byte ptr [eax+0x19],1` | Yes | `c6 40 19 01` |
| Self-link L/P/R; `[esi+8]=0` | Yes | Yes |
| `ret` (no stack pop of args) | Yes | `c3` — unary ECX |

**Calling convention:** `__fastcall` / thiscall-style unary (ECX = map owner). No `RET n`.

---

## 4. Sealed layouts (from this body + sealed consumers)

### Map header (`operator_new(0xc)`)

| Off | Field | Evidence |
|---|---|---|
| +0 | unused / allocator pad (not written here) | body only writes +4, +8 |
| +4 | head node (`_Myhead`) | store return of `FUN_005ae2b0` |
| +8 | size (`_Mysize`) | forced `0` on create; LocalCast twin reads `+8` for non-empty |

### Head / node factory `FUN_005ae2b0` (`0x005ae2b0`)

| Fact | Detail | Conf |
|---|---|---|
| Alloc | `operator_new(0x1c)` | **Confirmed** (callee decompile) |
| Init | zeros L/P/R-ish dwords; `*(+0x18)=1`, `*(+0x19)=0` then parent sets `+0x19=1` | **Confirmed** |
| Role | empty-tree sentinel only — not a value node | **High** |

### Value node fields (from Insert / GetRemaining — not this body)

| Off | Field | Consumer |
|---|---|---|
| +0 / +4 / +8 | left / parent / right | tree walk in `Skill_CategoryCooldownMap_Insert` |
| +0xc | **key** = categoryId (`int`) | Insert compares `node[3]` |
| +0x10 | **startTick** | `Skill_GetCategoryCooldownRemaining` |
| +0x14 | **durationMs** | same |
| +0x18 | color (byte) | factory |
| +0x19 | is_nil (byte) | head flag; walk terminator |

Node size **0x1c** matches factory; value payload fits category key + start + duration after tree links.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Map pointer at owner **`+0x6c`** | **Confirmed** | plate + body + bytes |
| Lazy alloc when null | **Confirmed** | |
| Header **0xC**; head via **`FUN_005ae2b0` (0x1c)**; size **+8=0** | **Confirmed** | body + callee |
| Self-linked empty head; flag **`+0x19=1`** | **Confirmed** | |
| No per-category / remaining / insert logic in this VA | **Confirmed** | accessor only |
| Name `Skill_GetCategoryCooldownMap` already product-placed | **Confirmed** | plate + symbol |
| No product string / RTTI on **this** body | **Confirmed** | audit globals SEH-only |
| Structural twin of `FUN_00518c20` @ **`+0x68`** | **High** | same 0xC shell; different factory (`FUN_0058d9c0` / flag +0x29 / node 0x30) |
| Map host is **cast owner entity**, not skill runtime | **High** | `a_0051e240`: ECX=EDI=owner; RecvSkillStatusEffect uses character this-adjust expr → same slot |
| Product C++ class name of owner | **Open** | residual |
| Exact MSVC `std::map<K,V>` template args | **High structure / Medium name** | pattern sealed; template spelling open |
| `FUN_005ae2b0` product name | **Open** | residual node factory |

---

## 6. Xrefs (8 sites / 4 functions)

```
0x00518e1c  Skill_InsertCategoryCooldown
0x00519168  Skill_GetCategoryCooldownRemaining
0x00519176  Skill_GetCategoryCooldownRemaining
0x005191a2  Skill_GetCategoryCooldownRemaining
0x0051e35a  CVOGHBOKToCastAgain_ctor
0x00811333  Client_RecvSkillStatusEffect   ; error path: abort CD / erase category
0x008116e9  Client_RecvSkillStatusEffect   ; item-skill category path
0x00811705  Client_RecvSkillStatusEffect
```

| Caller | Use of return |
|---|---|
| `Skill_InsertCategoryCooldown` | Get map → `Skill_CategoryCooldownMap_Insert` with `{key, g_dwClientTickMs, durationMs}` |
| `Skill_GetCategoryCooldownRemaining` | Lookup / deadline / erase-if-expired (`FUN_00418b80` / `FUN_004188e0`) |
| `CVOGHBOKToCastAgain_ctor` | If `skill+0x5e8 != -1`, insert category with duration `HB+0x8` on **owner** map |
| `Client_RecvSkillStatusEffect` | Error abort + item-skill paths: map on **local character** (this-adjust from `pClientCtx+0xe98`) |

**Not** exclusive to LocalCastValidate. **Not** a global singleton — always `this+0x6c`.

---

## 7. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| SEH frame | Yes |
| Null check `+0x6c` | Yes |
| `operator_new(0xc)` + OOM null store | Yes |
| `FUN_005ae2b0` head + self-links + size 0 | Yes |
| Store / restore ExceptionList / return `+0x6c` | Yes |
| No invented CD values | Yes |

---

## 8. Gaps / open

1. **Product type** of object owning `+0x68` / `+0x6c` pair (character vs skill-subsystem object) — behavioral host = cast **owner**; C++ class name unsealed.
2. Product name for **`FUN_005ae2b0`** (category-map node / head factory).
3. Whether header `+0` holds allocator state (unwritten on create path).
4. Runtime / bit-exact image diff — open per matrix policy.
5. Decompiler may show `Skill_GetCategoryCooldownMap(skill)` at some call sites; **asm dual** for cast-again sealed **owner** (`a_0051e240`). Treat decomp ECX fusion as noise unless re-proven.

**Verdict:** **accept** (CF + layout sealed). Owner **class name** and `FUN_005ae2b0` name remain residual — not blockers for the getter contract.
