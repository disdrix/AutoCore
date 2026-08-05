# Review A (reconstruction fidelity): `aa_0055e490` PhysSim_RemoveTrackedObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e490` |
| **VA** | `0x0055e490` |
| **Canonical name** | `PhysSim_RemoveTrackedObject` (inferred) |
| **Ghidra symbol** | `FUN_0055e490` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0055e490_PhysSim_RemoveTrackedObject.md` |
| **System** | `physics` (sim-context list bookkeeping) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

World / sim-context helper: **swap-remove** a tracked object pointer from a growable ptr array at `this+0x108` (count `this+0x10c`). On hit: decrement a **refcount short** at `obj+6`; if refcount reaches **0**, call object vtbl delete (`(*obj->vtbl)(1)`).

Primary (and sole dual-known) caller is `CVOGPhysics_PrepareReady` (`0x005070d0`):  
`FUN_0055e490(world=*(phys+8), arg=phys)` — always invoked when `phys+8≠0`, **before** optional host activate. When `phys` is not present in the list the scan is a pure no-op (common on hot paths).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0055e490_FUN_0055e490.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_0055e490_FUN_0055e490.annotated.md` | Scaffold |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0055e490.cpp` | CF ≡ raw |
| Named alias | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_TeleportTarget_0055e490.cpp` | Prior scaffold |
| Function record | `docs/reconstruction/functions/aa_0055e490_FUN_0055e490.md` | Scaffold |
| Live decompile | Ghidra MCP `0x0055e490` | **≡ raw** |
| Live `read_memory` | entry + loop | List at `+0x108` / count `+0x10c` sealed |
| Caller ABI | `0x005070d0` dual + bytes | `push phys; call` with ECX=world |
| Parent dual | `reviews/A_aa_005070d0_CVOGPhysics_PrepareReady.md` | Interface sealed |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX = world/sim context; stack arg = object ptr; `ret 4` | **High** | PrepareReady asm: ECX=world, push phys |
| Array base `*(this+0x108)`, count `*(this+0x10c)` | **High** | Decompile + entry bytes `cmp [esi+0x10c]` |
| Linear scan for pointer equality to arg | **High** | Outer + inner re-find index |
| Swap-remove: `count--; array[i]=array[count]` | **High** | Classic unordered remove |
| Refcount `*(i16*)(arg+6)--`; if 0 → `(*arg->vtbl)(1)` | **High** | Scalar destroy with `1` |
| No-op when arg not in list | **High** | No match → fall through return |
| Called from PrepareReady as (world, phys) | **High** | Sole Ghidra caller of this VA |
| English “deferred / pending list” product name | **Probable** | Role sealed; type names open |
| Whether arg is always `CVOGPhysics*` vs host | **Probable** | PrepareReady passes phys; other xrefs none |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Early exit if count ≤ 0 | Yes |
| Outer index walk `i = 0..count-1` | Yes |
| On `array[i] == arg`: re-scan for index `j` (or −1) | Yes |
| `count--; array[j] = array[count]` | Yes |
| `*(short*)(arg+6)--`; if 0 call dtor-with-delete | Yes |
| Continue outer loop against updated count | Yes |
| No invent insert / activate | Yes |

### Authoritative contract

```c
// PhysSim_RemoveTrackedObject (Probable)
// thiscall ECX = sim/world*; stack: void* obj; RET 4
void __thiscall PhysSim_RemoveTrackedObject(void *world, void *obj)
{
  void **arr = *(void ***)((char*)world + 0x108);
  int n = *(int*)((char*)world + 0x10c);
  for (int i = 0; i < n; ++i) {
    if (arr[i] != obj) continue;
    int j = index_of(arr, n, obj);   // re-find (decomp CF)
    if (j < 0) j = -1;               // decomp path if re-find fails
    --n;
    *(int*)((char*)world + 0x10c) = n;
    arr[j] = arr[n];                 // swap-remove
    short *rc = (short*)((char*)obj + 6);
    if (--*rc == 0)
      (*(void(__thiscall**)(void*,int))*obj)(obj, 1);  // scalar deleting dtor
  }
}
```

### PrepareReady call site (sealed)

```text
005070d3  mov  ecx, [esi+8]     ; world
005070d6  test ecx, ecx
005070d8  jz   ret
005070da  push esi              ; phys
005070db  call FUN_0055e490     ; thiscall ECX=world
```

---

## 5. Layout

### World / sim (`this`)

| Offset | Role |
|-------:|------|
| `+0x108` | `void**` tracked object array |
| `+0x10c` | `int` count |

### Tracked object (`arg`)

| Offset | Role |
|-------:|------|
| `+0` | vtbl (delete via slot 0 with arg `1`) |
| `+6` | `int16` refcount |

---

## 6. Gaps / open

1. Exact C++ type of world object and of tracked entries (always phys? other types?).
2. Who **inserts** into `+0x108` (producer dual open).
3. Why PrepareReady always calls remove before activate (defer-list drain vs always-safe no-op).
4. Outer-loop-after-swap-remove skip/edge cases (classic swap-remove iteration hazard).
5. Product / PDB name; runtime hit-rate on vehicle tick.

**Verdict:** **accept-with-gaps** — **list CF + refcount dtor + PrepareReady ABI** sealed; package incomplete on type names, insert producers, runtime.
