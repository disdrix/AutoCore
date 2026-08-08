# Review B (skeptical / adversarial): `aa_00538ab0` DisciplineDefMap_ExactFindByIntKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538ab0` |
| **VA** | `0x00538ab0` |
| **Canonical name** | `DisciplineDefMap_ExactFindByIntKey_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-037 OWN-ONLY dual B; dual start 2686) |
| **Counterpart** | `reviews/A_aa_00538ab0_DisciplineDefMap_ExactFindByIntKey_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure `lower_bound` success on first ≥ key | Post-check requires `cand.key <= *key` after lower-bound walk | **Falsified** as open lower_bound — **exact find** |
| 2 | Same helper as SkillDefMap find `0x00418890` | Nil **`+0x20d`** vs **`+0x641`**; this unit inlines walk (no `00418c70`) | **Falsified** merge |
| 3 | Same as nearby `0x00538a40` Map_FindByIntKey | Nil `+0x49` / key `+0x10` vs nil `+0x20d` / key `+0x0C` | **Falsified** — different geometry despite VA proximity |
| 4 | Hash / linear scan | Ordered tree left/right + isnil stops | **Falsified** |
| 5 | Mutates map / inserts on miss | Body only stores `*pOut`; callees empty | **Falsified** |
| 6 | Returns payload blob / DisciplineDef value | Returns **node\*** (or end); payload is `node+0x10` for callers | **Falsified** value-return |
| 7 | `__cdecl` like parent try-copy | Dual **`RET 8`** + ECX map; parent is bare RET + stack key/out | **Falsified** cdecl-on-find |
| 8 | Three stack formals | Bytes end **`ret 8`** (two stack args) | **Falsified** |
| 9 | Only callee of try-copy | **9** callers / **9** xrefs including prereq + train helpers | **Falsified** exclusive-caller |
| 10 | VOG / SkillDefMap / resource-balance identity | Distinct header `0x00b045b0`, nil, payload vs `0x00b04734` / char `+0x584` | **Falsified** |
| 11 | Scaffold `Named_CalleeOf_…VOG_DEBUG_STOP` is product role | Xref-only scaffold; no VOG_DEBUG_STOP in body | **Agree** retire scaffold name |
| 12 | Runtime Confirmed | No Launcher / live map capture this dual | **Agree leave open** — never claim Runtime Confirmed |
| 13 | Product English required for seal | No string/RTTI at this VA | **Agree** keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Exact-match semantics | **High** | Port bare lower_bound → false hits on greater keys |
| Nil `+0x20d` | **High** | Walk off tree / hang |
| Key int `+0x0C` | **High** | Wrong slot vs `+0x10` family |
| End = `*(map+4)` | **High** | Hit/miss inversion |
| `RET 8` thiscall ABI | **High** | Stack imbalance / wrong this |
| Map = DisciplineDef `@0x00b045b0` | **High** | Wrong this if reused |
| Payload `node+0x10` size `0x1FC` | **High** (caller dual) | Truncated copy in parent |
| Full node schema / product name | **Open** | Field ports / English wrong |
| Runtime | **Open** | Cold map / bit-exact |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-08-05).
disassemble_function ≡ decompile CF.
read_memory @ 0x00538ab0:
  push ecx
  mov edx,[ecx+4]            ; head
  mov eax,[edx+4]            ; root
  cmp byte [eax+0x20d],0     ; 80 B8 0D 02 00 00 00
  ... lower_bound loop ...
  cmp cand, head; jz miss
  cmp *key, [cand+0x0C]; jl miss
  *pOut = cand; ret 8        ; C2 08 00
  miss: *pOut = head; ret 8
body 0x68 B; pad CC @ 0x00538b18
xrefs: 9 UNCONDITIONAL_CALL; callees: []
callers all: mov ecx, 0xb045b0 before call
parent 0x0052b040: call → mov eax,[eax] → cmp eax,[0xb045b4]
```

### Lower_bound trap

Walk alone is lower-bound-shaped. **Do not port without** the `cand≠end && cand.key ≤ *key` gate.

### Layout trap

Never call SkillDefMap find / `0x0051c150` / `0x00538a40` on map `0x00b045b0`. Nil **`0x20d`** is DisciplineDef node scale (payload `0x1FC` from `+0x10` ⇒ nil sits just past payload).

### Parent trap

`DisciplineDefMap_TryCopyPayloadById`: `node == DAT_00b045b4` → **miss** (AL=0, no copy) — not “already cached”.

### ABI trap

Parent try-copy is **`__cdecl`** (bare RET, two stack args). **This** find is **`__thiscall` + RET 8**. Do not unify conventions.

---

## 4. Surviving contract for AutoCore

```
// DisciplineDef map exact find
Node* Find(DisciplineDefMap* map, int disciplineId) {
  Node* end = map->head;                 // *(map+4), often DAT_00b045b4
  Node* cand = end;
  Node* cur = end->parent;               // root
  if (!cur->isnil) {                     // isnil @ +0x20d
    do {
      if (cur->key < disciplineId)       // key @ +0x0C
        cur = cur->right;                // +8
      else { cand = cur; cur = cur->left; }
    } while (!cur->isnil);
  }
  if (cand != end && cand->key <= disciplineId) return cand; // equality under walk
  return end; // miss
}
// Callers: if (node == end) fail; else use (node+0x10) as 0x1FC-byte DisciplineDef
// ABI: thiscall(map, Node** out, int* key); ret 8; *out = result; EAX = out
```

---

## 5. Open questions

1. STL / product type name for map + node.  
2. Are all 9 callers guaranteed same map instance only (static yes; dynamic unknown)?  
3. Node fields beyond key / children / nil / `+0x10` template.  
4. Runtime capture / bit-exact.

**Verdict:** **accept-with-gaps** — adversarial attacks on merge/ABI/lower_bound/mutate/value-return **falsified**; product English + runtime remain open. **Never Runtime Confirmed.**
