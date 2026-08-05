# Review A (reconstruction fidelity): `aa_004a16d0` FxMaster_LoadEventVariant_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a16d0` |
| **VA** | `0x004a16d0` |
| **Canonical name (Ghidra)** | `FUN_004a16d0` |
| **Proposed name** | `FxMaster_LoadEventVariant_Inferred` (**High** role; format string `"%s_FOR_EVENT_%d"`) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_CVOGCharacter_LevelUp_004a16d0` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004a16d0_FxMaster_LoadEventVariant_Inferred.md` |
| **System** | `client-fx` / event-id FX instantiate |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Look up an event-id key in an FX master catalog map and instantiate a named event variant** of the template FX.

On catalog host `this` (the 8-byte host from `FUN_004a1620`, typically `obj+0x88`):

1. `map = *this`
2. `Map_LowerBoundFindByIntKey(map, …, &eventId)`
3. If iterator is end (`node == map+4` sentinel) → return
4. `template = node[+0x10]` (map value → NDSpecialFX template)
5. Build name: `_snprintf(buf, 0x104, "%s_FOR_EVENT_%d", template+0xD5, eventId)`
6. `fx = FUN_004a0b90(template, buf, mode, -1, 0)` — clone/instantiate `0x240` FX (`FUN_004ba310` inside)
7. If `fx != 0` and `slot ∈ [0, 4]` → `*(fx+0x230) = slot`

Primary thin dispatcher `FUN_004ec010` calls:

```
Ensure(+0x88);  // 004eb3b0
return 004a16d0(host+0x88, eventId, /*mode*/1, /*slot*/-1);
```

with event codes such as `4, 7, 8, 0xC, 0xE, 0x14, 0x15` from weapon/FX fire helpers — **event-id dispatch**, not free-form string play (`A_aa_004ec010`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x004a16d0` |
| Raw / annotated / clean | `aa_004a16d0` three-rep |
| Function record | `docs/reconstruction/functions/aa_004a16d0_FUN_004a16d0.md` |
| Consumer | `A_aa_004ec010_FUN_004ec010.md` |
| Clone helper | live `FUN_004a0b90` (alloc `0x240`, copies lists including `+0x1F8` audio pods) |
| LoadFromScriptName | post-parse also uses `004a0b90(fx, fx+0xd5, …)` — confirms `+0xD5` name field |

**This pass:** live decompile; 18 xrefs; string + map CF. **Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature

```c
// thiscall: ECX = catalog host (8-byte; *ECX = map*)
// Stack: eventId, mode/multiplier, slot
void __thiscall FxMaster_LoadEventVariant_Inferred(
    void *catalogHost,   // ECX
    uint32_t eventId,    // Stack[0x4]
    uint32_t mode,       // Stack[0x8]  — forwarded to 004a0b90 as param_3 (often 1)
    int slot);           // Stack[0xc]  — if 0..4 written to fx+0x230; -1 skips
```

Note: decompiler return type `void` but consumer `004ec010` treats EAX as result — **Probable** `004a0b90` result in EAX (common MSVC). Treat return as **FX\*** until ret-path sealed.

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `Map_LowerBoundFindByIntKey` | int-keyed map lower_bound |
| `_snprintf` | `"%s_FOR_EVENT_%d"` |
| `FUN_004a0b90` | Instantiate named FX variant from template |

Callers (14+): `FUN_004ec010`, `FUN_00512a20`, `FUN_00518370`, `FUN_00524710`, `FUN_00514d80`, `FUN_00582670`, `FUN_00582a20`, `FUN_005d9af0`, mission/level-up adjacent `00531330` / `00542e20`, etc.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Map lower_bound by eventId | Yes |
| End-iterator early out | Yes |
| Zero 0x104 name buffer | Yes |
| snprintf template name + event | Yes |
| `004a0b90(template, name, mode, -1, 0)` | Yes |
| Optional `fx+0x230 = slot` if `0 ≤ slot < 5` | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Event-id keyed map lookup | **High** | int key + FOR_EVENT format |
| Template name at `+0xD5` | **High** | LoadFromScriptName + snprintf base |
| `004a0b90` clones `0x240` FX | **High** | live decompile |
| `mode` is clone multiplier/scale arg | **Probable** | `004a0b90` uses `param_3` as count scale |
| `slot` stored at `+0x230` when 0..4 | **High** | explicit store + range |
| Return value is new FX\* | **Probable** | consumer uses EAX; decompiler void |
| Product name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Seal return (EAX) vs void — prefer ret-path read if porting.
2. Full map value node layout beyond `+0x10` template pointer.
3. Semantics of `+0x230` slot (hardpoint / channel index 0..4).
4. Ownership of returned FX (who tears down with `004b99c0`).
5. Runtime not run.

**Verdict:** **accept-with-gaps** — event variant CF High; return ABI Probable.
