# Skeptical / adversarial review: `CVOGMission_AddActiveObjective` @ `0x00531b00`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531b00` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Active-objective push interpretation and call edges |
| **Verdict** | **needs-more-evidence** |

---

## 1. Inspected artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_00531b00_CVOGMission_AddActiveObjective.md` | Authoritative decompile |
| `docs/reconstruction/raw/aa_00531b00_CVOGMission_AddActiveObjective.annotated.md` | Scaffold copy |
| `docs/reconstruction/reconstructed-exact/CVOGMission_AddActiveObjective.cpp` | Clean |
| `docs/reconstruction/functions/aa_00531b00_CVOGMission_AddActiveObjective.md` | Status |
| `docs/reconstruction/systems/missions-progression.md` | Role claim |
| `raw/aa_005327c0_CVOGReaction_GiveMission.md` | Call site `AddActiveObjective(*piVar1)` |

**Not performed:** Helper decompiles; assembly thiscall of caller; CE dirty-flag watch.

---

## 2. Evidence used

### A. Body mechanics

1. Unconditional `FUN_0053c460(key=*(param_2+0x10), param_2, 0)`.  
2. Conditional block only if objective’s pointer range `[0x158,0x15c)` has elements.  
3. Node alloc `0x14`, first field = `param_2`.  
4. `FUN_0053c760(key, node, 0)`; nonzero → `operator_delete` (noreturn warning).  
5. For each vector entry: virtual call slot `+0x28` with `(param_1, node)`.  
6. `*(uint*)(param_1+0x634) |= 0x10`.

### B. Plate claims under attack

- “Add active objective node to character mission hash (+0x548)”  
- “Called from GiveMission and CompleteObjective when advancing sequence”  
- “Sets dirty flag char+0x634 |= 0x10”

### C. Call-site tension

GiveMission decompile: `CVOGMission_AddActiveObjective(*piVar1);` — one explicit argument. This unit: two integer params thiscall.

---

## 3. Attack results

### Claim 1 — Inserts into character hash at `+0x548`

| Sub-claim | Attack result |
|-----------|----------------|
| Body stores to `param_1+0x548` | **Falsified** — no `0x548` in body |
| Hash insert happens via helpers using objective key `+0x10` | **Possible** — not proven without helper bodies |
| Plate offset is Confirmed | **Overclaim** relative to this unit alone |

### Claim 2 — Always activates / always sets dirty

| Sub-claim | Attack result |
|-----------|----------------|
| `FUN_0053c460` always runs | **Not broken** |
| Dirty flag always set | **Falsified** — only inside non-empty vector branch |
| Empty vector ⇒ no node / no virtuals / no dirty | **Not broken** |

### Claim 3 — `param_1` is character, `param_2` is objective

| Sub-claim | Attack result |
|-----------|----------------|
| `param_2+0x10` used as key; `+0x158/+0x15c` vector on same object | **Supports objective-like def** for `param_2` |
| `param_1+0x634` dirty | **Supports character-like owner** for `param_1` |
| Sealed C++ types | **No** — still `int` |
| GiveMission only passes `*piVar1` (objective) | **Undermines sealed two-arg thiscall story** — missing explicit character arg in that decompile |

### Claim 4 — Virtual loop is “notify listeners”

| Sub-claim | Attack result |
|-----------|----------------|
| Vtable `+0x28` called per element with `(param_1, node)` | **Not broken** as CF |
| Semantic “listeners / evaluators / UI” | **Unproven** |

### Claim 5 — `operator_delete` path is clean error handling

| Sub-claim | Attack result |
|-----------|----------------|
| Ghidra WARNING noreturn | Suggests abort/throw path or decompiler confusion |
| Safe recovery | **Not proven** — may terminate |

### Claim 6 — Name `CVOGMission_AddActiveObjective` / thiscall on mission

| Sub-claim | Attack result |
|-----------|----------------|
| Working name | Acceptable |
| `this` is CVOGMission instance | **Ambiguous** — params look like (character, objective) more than (mission, objective); name may be historical plate |

---

## 4. Alternate interpretations

### Minimal reading

```
void AddActiveObjective(Owner* owner, ObjectiveDef* obj) {
  register_or_insert(obj->id, obj, 0);          // FUN_0053c460
  if (obj has non-empty related list) {
    node = new Node{obj, 0,0,0,0};
    if (insert_node(obj->id, node, 0) fails) delete_and_maybe_abort(node);
    for (handler in obj.list) handler->vtbl[0x28/4](owner, node);
    owner->flags |= 0x10;
  }
}
```

### Competing stories

1. Primary insert is always `FUN_0053c460`; vector path is **extra** binding for multi-part objectives.  
2. Empty vector objectives are “registered” without dirtying character UI.  
3. GiveMission call decompiler dropped `this`/character — or this function is stdcall/cdecl mis-tagged.

---

## 5. Confirmed despite skepticism

1. Ordered helper → optional node → virtual fan-out → dirty bit.  
2. Dirty mask bit `0x10` at offset `0x634` on `param_1`.  
3. Objective-relative vector as `std::vector`-like begin/end pair (`>>2` element count).  
4. Node size `0x14` with objective pointer at start.  
5. Clean ≡ raw CF.  
6. Plate claim of direct `+0x548` write is **not** in this body.

---

## 6. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | Helper insert targets (`+0x548`?) | **Yes** |
| R2 | ABI / thiscall vs GiveMission call | **Yes** |
| R3 | param roles formal types | **Yes** |
| R4 | Vtable method identity | Medium–high |
| R5 | Dirty bit consumers | Medium |
| R6 | Noreturn delete semantics | Medium |
| R7 | Runtime | **Yes** |

---

## 7. Concrete checks performed

1. Searched body for `0x548` — absent.  
2. Conditioned dirty flag on vector non-empty — confirmed.  
3. Compared GiveMission call arity to this signature — mismatch.  
4. Verified clean did not invent hash stores.  
5. Checked zero-init then overwrite of node[0].  
6. Noted noreturn warning on delete path.

---

## 8. Verdict

### **`needs-more-evidence`**

**Why:** Core plate claim (hash `+0x548`) is not evidenced in-unit; primary behavior is opaque helpers + optional fan-out. Call-edge to GiveMission is inconsistent with the declared signature.

**Why not needs-revision:** No proof the raw CF sequence is wrong; clean matches it. Revision belongs to naming/plate and helper recovery, after more evidence.

**Why not accept-with-gaps (package):** Accepting “inserts at +0x548” from this unit’s plate would assert a store that is not here.

**Bar for stronger verdict:**

1. Decompile `FUN_0053c460` and `FUN_0053c760`.  
2. Resolve GiveMission → AddActiveObjective ABI (asm or multi-site).  
3. Identify vtable `+0x28` targets.  
4. Trace dirty `+0x634` bit `0x10` readers.  
5. Runtime: grant mission → observe objective hash and dirty bit.

**Final verdict: `needs-more-evidence`**
