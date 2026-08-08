# Review B (skeptical / adversarial): `aa_00560c90` LthkWorld_GetPenetrations_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560c90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-024 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_00560c90_LthkWorld_GetPenetrations_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is VOG_DEBUG_STOP / spawn scaffold | Prior alias `Named_CalleeOf_*VOG_DEBUG_STOP*` | **Falsified** — body is penetration collect+dispatch; plate `LthkWorld::getPenetrations` |
| 2 | Is query-object base ctor (`005eb210`) | Partition parent adjacency | **Falsified** — no vtbl write; no triad construct; RET 0xC with 3 stack args |
| 3 | Is sphere-collect ctor (`005ebec0`) / sibling | Family bleed | **Falsified** — 420 B loop+dispatch; ctors are ~49 B straight-line |
| 4 | Is query sub-init (`00581190`) | Residual peer wave | **Falsified** — different VA/ABI/role |
| 5 | Is pure broadphase only (no narrowphase) | string `getPenetrations` alone | **Falsified** — second tag `Stnarrowphase` + type-matrix CALL |
| 6 | stdcall / bare RET / 0 stack args | decompiler noise | **Falsified** — frame + **`RET 0xC`** |
| 7 | Filter uses unaff_EBX as world | decompiler as written | **Falsified** — asm loads self from `[ESP+0x1c]` → `self+0xD0` |
| 8 | Dispatch is thiscall (no stack cleanup) | virtual CALL guess | **Falsified** — `ADD ESP,0x10` after pair CALL (cdecl) |
| 9 | Always frees stack buffer | free path always | **Falsified** — `TEST/JS` skips free when capacity high-bit set (`0x80000080` empty) |
| 10 | Many direct callers | inventory noise | **Falsified** — **2** UNCONDITIONAL_CALL only (`004ea350`, `005dae50`) |
| 11 | Product class fully sealed (drop `_Inferred`) | plate string overread | **Fails (open)** — method English High; class ownership of `self` still inferred |
| 12 | Runtime Confirmed | wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 0xC / 3 stack args / ECX=self | **High** | Corrupt every call site |
| Penetrations collect → filter → type dispatch | **High** | Wrong interaction pipeline |
| Plate strings + narrowphase tag | **High** | Misname unit |
| Distinct from query ctors / sub-init | **High** | Merge wrong types |
| `self+0xC4/+0xCC/+0xD0` field roles | **High** (offset) / **Med** (English) | Port field map |
| Dispatch matrix full product map | **Low–Med** | Handler table port only |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (assembly-corrected)
self = ECX → ESI → [ESP+0x1c]
query = [EBP+8] → EDI
user_ctx = [EBP+0xC]
dispatch = [EBP+0x10] → EBX; if null: EBX = self[+0xCC]

profiler_open("LthkWorld::getPenetrations")           // 0x009d2840
vcall(query->inner.vtbl[+0x18])(query[2]+0x20, dispatch[2], &ext12)
triad = { stack_buf, 0, 0x80000080 }
vcall(*(self+0xC4).vtbl[+0x24])(&out, &triad)         // broadphase fill
query_type = vcall(query->inner.vtbl[+0x14])()
profiler("Stnarrowphase")                              // 0x009d2830
for each cand in triad (count @ +4; stride 8; ptr-0x10):
  if cand == query: continue
  ok = vcall(*(self+0xD0)+8)(out_byte, query, cand)
  if ok && *cand != null:
    cand_type = vcall((*cand).vtbl[+0x14])()
    // cdecl:
    dispatch.vtbl[0x118c/4 + query_type*0x20 + cand_type](
        query, cand, dispatch, user_ctx)
    // ADD ESP, 0x10
profiler_close("lt")                                   // 0x009d282c
if triad.cap high-bit clear:
  (*DAT_00b05060)->vtbl[+0x14](begin, (cap&0x7fffffff)*8, 0x12)
// RET 0xC
```

Sibling contrast (evidence only; not OWN dual):

* `FUN_005eb210` — query base **ctor** (R11-008); builds object that later feeds this.
* `FUN_005ebec0` — sphere collect **ctor** (MEGA-070); parent then calls this for hits.
* `FUN_004ea350` — `CVOGPhysicsUtils::GetObjectsInArea` caller.
* `FUN_005dae50` — `CVOGHBRecreateObject::OnHeartBeat` caller.
* `FUN_00581190` / `FUN_005eb040` — residual construct helpers; not this VA.

Bytes seal (`read_memory` @ `0x00560e30`):

```text
5D C2 0C 00 CC CC CC …     ; POP EBP; RET 0xC; int3 pad
```

Entry / key immediates (`disassemble_function`):

```text
00560c9e  MOV ESI,ECX
00560cd6  MOV EBX,[ESI+0xCC]          ; default dispatch
00560d02  … MOV [ESP+0x48],0x80000080 ; triad cap
00560d20  CALL [EDX+0x24]             ; broadphase
00560dbf  CALL [EDX+ECX*4+0x118c]     ; type-pair dispatch
00560dc6  ADD ESP,0x10                ; cdecl cleanup
00560e31  RET 0xC
```

---

## 4. Surviving contract for AutoCore

```
LthkWorld_GetPenetrations_Inferred(self, query_obj, user_ctx, dispatch_table):
  if dispatch_table == null: dispatch_table = self.dispatchDefault(+0xCC)
  query_extents = shape_vcall(query_obj, +0x18, …)
  candidates = broadphase_vcall(self.collector(+0xC4), +0x24, triad)
  typeA = shape_type(query_obj)
  for cand in candidates:
    if cand == query_obj: continue
    if !pair_filter(self.filterHost(+0xD0), query_obj, cand): continue
    if cand.shape == null: continue
    typeB = shape_type(cand)
    cdecl dispatch_table.matrix[typeA][typeB](query, cand, dispatch, user_ctx)
  free_triad_if_heap(candidates)
  // thiscall, RET 0xC
```

**Do not:** merge with query/collect ctors; trust decompiler `unaff_EBX`; treat pair dispatch as thiscall; claim Runtime Confirmed; drop `_Inferred` without product class RTTI/plate for `self`.
