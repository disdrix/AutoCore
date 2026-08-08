# Review A (reconstruction fidelity): `aa_00560c90` LthkWorld_GetPenetrations_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560c90` |
| **VA** | `0x00560c90`–`0x00560e33` |
| **Canonical name (Ghidra)** | `FUN_00560c90` |
| **Proposed name** | `LthkWorld_GetPenetrations_Inferred` |
| **Review date** | `2026-08-05` (R12-024 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00560c90_LthkWorld_GetPenetrations_Inferred.md` |
| **System** | interaction-activation (partition parent `0x005eb210` query base ctor) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**thiscall** world **penetration / narrowphase collect-and-dispatch** entry named by embedded profiler string `LthkWorld::getPenetrations`:

1. Optional RDTSC profiler open tag `"LthkWorld::getPenetrations"`.
2. Resolve collision-dispatch table pointer (stack arg or `self+0xCC` default).
3. Build query extents via shape vcall `vtbl[+0x18]` on the query object.
4. Broadphase-collect candidates into a stack/heap triad buffer via world subobject `self+0xC4` vcall `vtbl[+0x24]` (capacity sentinel `0x80000080`).
5. Read query shape type id via `vtbl[+0x14]`.
6. Narrowphase loop (`"Stnarrowphase"`): for each candidate (8-byte stride, ptr at +4, −0x10 header adjust), skip self, pair-filter via `*(self+0xD0)+8` vcall, then **cdecl** type-pair dispatch through `dispatch_table.vtbl[0x118c + (typeA*0x20 + typeB)*4]`.
7. Profiler close tag `"lt"`; free heap triad buffer via global allocator `DAT_00b05060` when capacity high-bit clear.
8. **`RET 0xC`**.

Used by `GetObjectsInArea` sphere path and heartbeat recreate path to **collect hits / run pair handlers** — not a ctor and not the query-object base itself.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00560c90` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/locals/completeness; **no** primary `disassemble_bytes`) |
| Assembly | `disassemble_function` full body — ABI / loop / free / RET sealed |
| Bytes | `read_memory` @ `0x00560e30` — `5D C2 0C 00 CC…` (POP EBP; **RET 0xC**; pad) |
| Strings | `read_memory` @ `0x009d2840` / `0x009d2830` / `0x009d282c` |
| Callers / xrefs | `get_function_xrefs` — 2 UNCONDITIONAL_CALL |
| Call-site ABI | `get_assembly_context` on `004ea7e3`, `005daf65` |
| Parent chain | dualed `005eb210` / `005ebec0`; parent `004ea350` GetObjectsInArea |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00560c90` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of residual callees/vcall targets.

---

## 3. Signature

```c
void __thiscall LthkWorld_GetPenetrations_Inferred(
    void *self /* ECX */,
    void *query_obj /* stack [EBP+8] */,
    uint32_t user_ctx /* stack [EBP+0xC] */,
    void *dispatch_table /* stack [EBP+0x10]; null → self+0xCC */);
// RET 0xC; no meaningful EAX contract sealed (void path)
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX`; frame `PUSH EBP; MOV EBP,ESP; AND ESP,0xFFFFFFF0; SUB ESP,0x444` |
| Stack args | `[EBP+8]`→EDI query; `[EBP+0xC]` user_ctx; `[EBP+0x10]`→EBX dispatch |
| Null dispatch | `TEST EBX,EBX; JNZ …; MOV EBX,[ESI+0xCC]` |
| RET | **`RET 0xC`** (`C2 0C 00` @ `0x00560e31`) |
| Body size | **420 B** (`0x1A4`); pad `CC` from `0x00560e34` |
| Named callees | none (indirect vcalls only; analyze `classification=leaf`) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Profiler open `LthkWorld::getPenetrations` | **Yes** (string VA `0x009d2840`) |
| Default dispatch `self+0xCC` | **Yes** |
| Shape extents vcall `query.vtbl[+0x18]` | **Yes** |
| Triad init + broadphase `*(self+0xC4).vtbl[+0x24]` | **Yes** (`cap=0x80000080`) |
| Query type id `vtbl[+0x14]` | **Yes** |
| Narrowphase loop + self-skip | **Yes** |
| Pair filter via `*(self+0xD0)+8` (not unaff_EBX) | **Yes** — **assembly corrects decompiler** |
| Type-matrix cdecl dispatch `@ +0x118c` | **Yes** (`CALL [EDX+ECX*4+0x118c]; ADD ESP,0x10`) |
| Free via `DAT_00b05060` when cap high-bit clear | **Yes** |
| `RET 0xC` | **Yes** |

### Self fields touched (read)

| Off | Role |
|----:|------|
| `+0xC4` | broadphase collector object* (vcall +0x24) |
| `+0xCC` | default dispatch table* when arg null |
| `+0xD0` | pair-filter host* (`+8` subobject vcall) |

### Decompiler correction (required)

Live decompile shows `unaff_EBX` in the filter call. Assembly at `0x00560d84`–`0x00560d9b`:

```text
MOV ECX, [ESP+0x1c]     ; saved self (not unaff_EBX)
MOV EAX, [ECX+0xD0]
MOV EDX, [EAX+0x8]
LEA ECX, [EAX+0x8]
PUSH candidate; PUSH query; LEA out_byte; CALL [EDX]
```

Filter host is **`self+0xD0`**. Annotated/clean must use this, not `unaff_EBX`.

### Call sites

| Site | ECX / stack | Role |
|---|---|---|
| `0x004ea7e3` `FUN_004ea350` GetObjectsInArea | this = query+0xC path; 3 stack args | sphere/area **collect hits** after collect-ctor |
| `0x005daf65` `FUN_005dae50` HB recreate | this = phys+0xC; stack locals | pose/recreate **penetration** pass |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + thiscall + RET 0xC + 3 stack args | **High** | disasm + bytes + callers |
| Product method string `LthkWorld::getPenetrations` | **High** | embedded profiler plate |
| Broadphase → filter → type-matrix dispatch | **High** | loop + `0x118c` + cdecl cleanup |
| `unaff_EBX` is decompiler artifact | **High** | assembly uses saved self |
| Distinct from query base/collect ctors | **High** | different VA/role; no vtbl install |
| Full product class of `self` / dispatch matrix English | **Open** | `_Inferred`; offsets sealed, types not |
| Exact pair-filter / shape interface English | **Open** | residual vcall targets |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB class of `self` (LthkWorld vs VOG world wrapper) beyond method string.  
2. Exact `query_obj` / `dispatch_table` composite types and type-id range.  
3. Pair-filter object at `+0xD0` and broadphase at `+0xC4` residual duals.  
4. Full meaning of dispatch base `0x118c` and `type*0x20` stride.  
5. Runtime Confirmed / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/strings/callers/loop High; product class English + residual vcall types + runtime open.
