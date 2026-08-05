# Review B (skeptical / adversarial): `aa_0073e1e0` EffEffect_CreateAndLoad_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073e1e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-Q) |
| **Counterpart** | `reviews/A_aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + callee decompile context (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | thiscall ECX=manager | **Falsified** — all three args stack; **`ret 0xc`**; manager only becomes ECX for register callee |
| 2 | Returns status code in EAX | **Falsified** — EAX = object* / null; status via out-param |
| 3 | On fail leaks shell | **Falsified** — `vtbl[0](1)` scalar deleting dtor |
| 4 | Decompiler `FUN_007533e0(obj,0)` complete ABI | **Falsified** — **ECX=path** from bytes |
| 5 | Same as slot bind `FUN_009701d0` | **Falsified** — loader only; bind adds refcount swap |
| 6 | Scaffold `Named_CalleeOf_gfxSubPhaseMap` dual-ready | **Falsified** — reject long alias |
| 7 | Uses `operator_new` | **Falsified** — freelist `FUN_00457040` / `DAT_00d21970` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `ret 0xc` / 3 stack args | **High** | stack smash under BindByPath |
| Null on fail + status out | **High** | callers OR-accumulate status wrong |
| Path/manager ECX routing | **High** | wrong load/register this |
| Product English | Medium | naming only |
| Freelist block 0x30 | **High** | slab chain step in `FUN_00457040` |

---

## 3. Cross-check against raw + bytes

```
obj = freelist_pop(DAT_00d21970)
if obj: init vtbl/zeros/0xFFFF
status = Load(path=ECX, obj, flag=0)
*outStatus = status
if status < 0:
  if obj: dtor(obj,1)
  return null
Register(manager=ECX, obj)
return obj
ret 0xc
```

Clean must **not** treat this as thiscall on manager, return status in EAX, or skip fail-path destroy.

---

## 4. Surviving contract for AutoCore

```csharp
// Create effect shell, load by path/token under manager; null on fail.
Effect? CreateAndLoad(EffectManager mgr, PathToken path, out int status)
{
    var obj = EffectFreelist.Alloc(); // DAT_00d21970 pool
    obj?.InitDefaultVtbl();
    status = EffectResource.Load(path, obj, flag: 0);
    if (status < 0) {
        obj?.Destroy(free: true);
        return null;
    }
    mgr.Register(obj);
    return obj;
}
```

Server ports that skip manager register, free with `delete` instead of vtbl dtor, or return status as the primary result will diverge from `EffEffectSlot_BindByPath` and Phase map loaders.
