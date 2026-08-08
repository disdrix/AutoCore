# Review A (reconstruction fidelity): `aa_00402410` StdList_CopyCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402410` |
| **VA** | `0x00402410`–`0x00402495` inclusive (**134 B** / `0x86`) |
| **Canonical name** | `StdList_CopyCtor_Inferred` |
| **Ghidra name** | `FUN_00402410` |
| **Rejected misname** | mission/reaction helper; empty default ctor; assign-op in place; vector ctor; thiscall ECX-this |
| **Review date** | `2026-08-05` (R10-019 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00402410_StdList_CopyCtor_Inferred.md` |
| **System** | shared MSVC `std::list` (partition seed: missions-progression / parent `0x004023f0`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Copy-construct helper for an MSVC circular `std::list` object:

```text
StdList_CopyCtor_Inferred(dest, src) -> dest
  dest._Myhead = StdList_AllocEmptySentinel_Inferred()   // 0x0040fb90
  dest._Mysize = 0
  FUN_00404490(dest, *dest._Myhead, *src._Myhead, src._Myhead)
    // insert [src.begin(), src.end()) before dest.end()
  return dest
```

Sibling of dualed empty default ctor `StdList_DefaultCtor_Inferred` (`0x004023f0`) — same head/size empty init, plus range insert.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ original raw CF (SEH → alloc → head@+4 → size@+8=0 → 00404490 → return dest) |
| Full body | `disassemble_function` + `read_memory` 134 B through `RET 0x8` |
| Callee sentinel | dualed `StdList_AllocEmptySentinel_Inferred` `0x0040fb90` |
| Range insert | residual `FUN_00404490` → `FUN_00404560` → `FUN_004040f0` |
| Sibling default | dualed `StdList_DefaultCtor_Inferred` `0x004023f0` (MEGA-052) |
| Pair destroy | dualed `StdList_Destroy_FreeHead_Inferred` `0x00403430` |
| Callers | `FUN_00955010` ×8 UNCONDITIONAL_CALL |

---

## 3. Signature (sealed)

```c
// [EBP+8]=dest, [EBP+0xC]=src; EAX=dest; RET 8
void* /*list**/ __stdcall StdList_CopyCtor_Inferred(void* /*list**/ dest, void* /*list**/ src);
```

| Formal | Source | Conf |
|---|---|---|
| dest | `[EBP+0x8]` → ESI | **Confirmed** |
| src | `[EBP+0xC]` | **Confirmed** |
| ECX this | not used on entry | **Confirmed** (not thiscall) |
| return | EAX = dest | **Confirmed** |
| cleanup | `RET 0x8` (`C2 08 00`) | **Confirmed** |
| head store | `MOV [ESI+4], EAX` after alloc | **Confirmed** |
| size store | `MOV [ESI+8], 0` | **Confirmed** |
| insert call | `CALL 0x00404490` with 4 stack args | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH frame `LAB_009bd220` | PUSH −1 / PUSH handler / FS:0 | **Confirmed** |
| Load dest | `MOV ESI, [EBP+8]` | **Confirmed** |
| Alloc empty sentinel | `CALL 0x0040fb90` | **Confirmed** |
| `_Myhead = EAX` | dword store +4 | **Confirmed** |
| `_Mysize = 0` | imm0 store +8 | **Confirmed** |
| SEH state → 0 | after empty init | **Confirmed** |
| Load src head / begin | `[src+4]`, then `[_Myhead]` | **Confirmed** |
| where = dest head next | empty ⇒ sentinel | **Confirmed** |
| Range insert | PUSH end, begin, where, dest; CALL 00404490 | **Confirmed** |
| Return dest | `MOV EAX,ESI` + SEH restore | **Confirmed** |
| Stdcall cleanup | `RET 0x8` | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker / list copy-construct helper |
| UNCONDITIONAL_CALL | **8** — all `FUN_00955010` |
| DATA (ctor ptr) | **0** |
| Callees | `FUN_0040fb90`, `FUN_00404490` |
| Object layout | **0xC** fields +4/+8 match default-ctor sibling |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Empty-init identical to dualed default ctor sibling | **Yes** |
| Dualed sentinel alloc `0040fb90` | **Yes** |
| Range insert of all source nodes (not empty-only) | **Yes** |
| Head@+4 size@+8 | **Yes** |
| Product English / RTTI / decorated name | **No** → `_Inferred` |
| Domain mission strings in body | **No** |

**Decision:** promote **`StdList_CopyCtor_Inferred`**. Retire scaffold-only `FUN_00402410` as sole canonical for port docs (keep Ghidra twin path).

---

## 7. Gaps

- Element type `T` (caller-site; residual insert chain).
- Unwritten `list+0` (allocator / container_base).
- Insert chain `00404490`/`00404560`/`004040f0` not dualed in this OWN unit.
- Runtime / bit-exact / differential (no Launcher).
- Stdcall 2-arg shape vs textbook thiscall copy-ctor decoration — bytes sealed; decoration residual.

---

## 8. Verdict

**accept-with-gaps** — CF/ABI/RET8/head@+4/size@+8/empty-init+range-insert copy sealed; `T` + insert-chain dual + runtime open.
